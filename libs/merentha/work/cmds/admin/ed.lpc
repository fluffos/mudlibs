// Petrarch
// Merentha Lib 1.0
// <ed>

varargs int command(string file) {
    if(!file) return notify_fail("Syntax: ed <filename>\n");
    if(file_size(file)==-2) return notify_fail("You can not 'ed'it a directory.\n");
    if(file[0..0]!="/") file=this_player()->query_cwd()+file;
    ed(file);
    return 1;
}

string help() {
return "Syntax: ed <filename>\n\nBegins addition of the file given by filename.  Will create the file if it does not yet exist.";
}
