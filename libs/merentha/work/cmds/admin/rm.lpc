// Petrarch
// Merentha Lib 1.0
// <rm>

varargs int command(string file) {

    if(!file) return notify_fail("Syntax: rm <file>\n");
    if(file[0..0]!="/") file=this_player()->query_cwd()+file;
    if(file_size(file)<0) return notify_fail("File does not exist or is a directory.\n");

    if(file[0..10]!="/tmp/trash/") rename(file, "/tmp/trash/"+explode(file, "/")[<1]);
    else rm(file);
    return 1;
}

string help() {
return "Syntax: rm <file>\n\nThis comman removes a file from the MUD.  Files removed as such actually get moved to the /tmp/trash/ directory.  Files removed from that directory are actually removed.";
}
