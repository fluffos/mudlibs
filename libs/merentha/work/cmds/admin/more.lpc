// Petrarch
// Merentha Lib 1.0
// <more>

varargs int command(string file) {
    if(!file) return notify_fail("Syntax: more <file>\n");
    if(file[0..0]!="/") file=this_player()->query_cwd()+file;
    if(file_size(file)<0) return notify_fail("File was directory or did not exist.\n");
    this_player()->more(read_file(file));
    return 1;
}

string help() {
return "Syntax: more <file>\n\nDisplay the file given on your screen with the 'more' function enabled.\n\nSee Also: cat, head, tail.";
}
