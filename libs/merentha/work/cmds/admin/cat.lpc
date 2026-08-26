// Petrarch
// Merentha Lib 1.0
// <cat>

varargs int command(string fname) {
    string str;

    if(!fname) return notify_fail("Syntax: cat <file>\n");
    if(fname[0..0]!="/") fname=this_player()->query_cwd()+fname;
    if (sizeof(fname) < 0) return notify_fail("File does not exist.\n");

    message("command", read_file(fname), this_player());

    return 1;
}

string help() {
    return "Syntax: cat <file>\n\nDisplays the content of file <file> on your screen.\n\nSee also: tail, head, more";
}
