// Petrarch
// Merentha Lib 1.0
// <head>

varargs int command(string fname) {
    string str;
    int i;

    if(!fname) return notify_fail("Syntax: head <file>\n");
    if(fname[0..0]!="/") fname=this_player()->query_cwd()+fname;
    if (sizeof(fname) < 0) return notify_fail("File does not exist.\n");

    if(!i=this_player()->getenv("LINES")) i=20;
    message("command", implode(explode(read_file(fname), "\n")[0..i],"\n"), this_player());

    return 1;
}
string help() {
return "Syntax: head <file>\n\nDisplays the first 18 or so lines of the given file you specify.\n\nSee also: tail, cat, more";
}
