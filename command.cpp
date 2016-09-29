//
// Created by user on 16/09/23.
//

#include <fstream>
#include "command.h"

/**
 * コマンドの実行結果をtmpファイルに書き込む
 * @param str
 */
void command::doCommand(string str){
    // コマンドの出力をｔｍｐファイルに書き込む
    //LANG=Cをつけて英語で返すように
    string command = "LANG=C " + str + " >tmp";
    //systemの引数に合わせるためchar型に変換して渡す
    int result = system(command.c_str());
    if (result != 0)
    {
        cerr << "Command failed "+str << endl;
    }
}

/*
 * tmpファイルの内容を返す
 */
string command::getResult(){
    ifstream ifs("tmp");
    if (ifs.fail())
    {
        std::cerr << "Tmp FIle open failled" << std::endl;
    }
    std::istreambuf_iterator<char> it(ifs);
    std::istreambuf_iterator<char> last;
    std::string str(it, last);
    return str;
}

/**
 *実行したいコマンドを第一引数
 * 取り出したい結果を第二引数(正規表現で)
 *
 * 正規表現で記述した文字列
 * @return
 */
string command::analyzeCommand(string commandStr,string reg) {
    smatch match;
    this->doCommand(commandStr);
    regex re(reg);
    string cmdResult = this->getResult();
    int result = regex_search(cmdResult, match,re);
    cout << match.str() << endl;
    if(result){
        cout << match[match.size() - 1] << endl;
        //配列の最後の要素（正規表現の結果）を返す
        return match[match.size() - 1];
    }else{
        return "";
    }
}
