// Petrarch
// Merentha Lib 1.0
// <cd>

varargs int command(string dir) {
    if(!dir) dir="/realms/"+this_player()->query_name();
    if(dir==".") return 1;
    if(dir=="..") dir="/"+implode(explode(this_player()->query_cwd(), "/")[0..<2], "/");
    if(dir[0..0]=="~") {
        if(dir=="~") dir="/realms/"+this_player()->query_name();
        else dir="/realms/"+dir[1..<1];
    }
    return this_player()->set_cwd(dir);
}


string help() {
return "Syntax: cd <directory>\n\nChange directory into <directory>.  The input can be either an absolute or realitive pathname.  If no input is given it will take you to your home directory.";
}
