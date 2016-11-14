//
// Created by user on 16/10/01.
//

#include "locationInfo.h"



void locationInfo::setIpAddr(string _ip){
    init();
    this->ip = _ip;
    fetchLocation();
}

string locationInfo::getCity(){
    return this->city;
}

string locationInfo::getCountry() {
    return this->country;
}

string locationInfo::getLatitude() {
    return this->latitude;
}

string locationInfo::getLongitude() {
    return this->longitude;
}

/**
 * 初期化処理
 */
void locationInfo::init(){
    this->city = "";
    this->country = "";
    this->ip = "";
}

/**
 * from https://github.com/maxmind/libmaxminddb/blob/master/doc/libmaxminddb.md
 * ipアドレスから国の情報を返す
 */
void locationInfo::fetchLocation(){
    string _ip = this->ip;
    //結果の国(iso表記)を保存
    string countryResult;
    //結果の地域を保存
    string cityResult;
    //緯度の地域を保存
    string latitudeResult;
    //経度の地域を保存
    string longitudeResult;
    //データベース不ファイルを指定
    const char *filename =  "/media/workspace/projectPi/ipDatabases/GeoLite2-City.mmdb";
    const char *filename2 =  "/home/user/workspace/projectPi/ipDatabases/GeoLite2-City.mmdb";
    const char *ip_address = _ip.c_str();
    MMDB_s mmdb;
    int status = MMDB_open(filename, MMDB_MODE_MMAP, &mmdb);

    if (MMDB_SUCCESS != status) {
        //for another Enviroment
        int status = MMDB_open(filename2, MMDB_MODE_MMAP, &mmdb);
        if(MMDB_SUCCESS !=status) {
            fprintf(stderr, "\n  Can't open %s - %s\n",
                    filename, MMDB_strerror(status));

            if (MMDB_IO_ERROR == status) {
                fprintf(stderr, "    IO error: %s\n", strerror(errno));
            }
            exit(1);
        }
    }

    int gai_error, mmdb_error;
    MMDB_lookup_result_s result =
            MMDB_lookup_string(&mmdb, ip_address, &gai_error, &mmdb_error);

    if (0 != gai_error) {
        fprintf(stderr,
                "\n  Error from getaddrinfo for %s - %s\n\n",
                ip_address, gai_strerror(gai_error));
        exit(2);
    }

    if (MMDB_SUCCESS != mmdb_error) {
        fprintf(stderr,
                "\n  Got an error from libmaxminddb: %s\n\n",
                MMDB_strerror(mmdb_error));
        exit(3);
    }

    MMDB_entry_data_list_s *entry_data_list = NULL;

    int exit_code = 0;
    if (result.found_entry) {
        int status = MMDB_get_entry_data_list(&result.entry,
                                              &entry_data_list);

        if (MMDB_SUCCESS != status) {
            fprintf(
                    stderr,
                    "Got an error looking up the entry data - %s\n",
                    MMDB_strerror(status));
            exit_code = 4;
            goto end;
        }

        if (NULL != entry_data_list) {
            //情報一覧を表示(デバッグ用)
            //MMDB_dump_entry_data_list(stdout, entry_data_list, 2);
            MMDB_entry_data_s entry_data_city, entry_data_country, entry_data_location_latitude,entry_data_location_longitude;;
            //得たい情報を指定する
            MMDB_get_value(&result.entry, &entry_data_country, "country", "iso_code", NULL);
            MMDB_get_value(&result.entry, &entry_data_city, "city", "names", "en", NULL);
            MMDB_get_value(&result.entry, &entry_data_location_latitude, "location", "latitude", NULL);
            MMDB_get_value(&result.entry, &entry_data_location_longitude, "location", "longitude", NULL);
            //受け取った構造体からデータをstringで取得
            countryResult = getMMDBresultString(entry_data_country);
            cityResult = getMMDBresultString(entry_data_city);
            latitudeResult = getMMDBresult(entry_data_location_latitude);
            longitudeResult = getMMDBresult(entry_data_location_longitude);
        }
    } else {
        fprintf(stderr,
                "\n  No entry for this IP address (%s) was found\n\n",
                ip_address);
        exit_code = 5;
    }

    end:
    MMDB_free_entry_data_list(entry_data_list);
    MMDB_close(&mmdb);
    this->country = countryResult;
    this->city = cityResult;
    this->latitude = latitudeResult;
    this->longitude = longitudeResult;
}


/**
 * MMDB形式の構造体の結果をstringで返す
 * @param entry_data
 * @return
 */
string getMMDBresultString(MMDB_entry_data_s entry_data){
    if(entry_data.has_data) {
        //tmpResultCharからdata_sizeが求めたいデーター
        char *tmpResultChar = (char *) entry_data.utf8_string;
        //char型で確保+1は最後にNULLを格納するため
        char resultChar[entry_data.data_size +1];
        for (int i = 0; i < entry_data.data_size; i++) {
            resultChar[i] = tmpResultChar[i];
        }
        //charの最後にnullを格納
        resultChar[entry_data.data_size] = NULL;
        string result = resultChar;
        return result;
    }else{
        return "";
    }
}

/**
 * MMDB形式の構造体の結果(double)をdoubleで返す
 * @param entry_data
 * @return
 */
string getMMDBresult(MMDB_entry_data_s entry_data){
    if(entry_data.has_data) {
        return to_string(entry_data.double_value);
    }
    return "";
}
