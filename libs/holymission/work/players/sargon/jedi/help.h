int help(string str) {

    string path;

    if(!str) return 0;

    if(str=="levels") {
        GM->list_levels(4,TP->query_gender());
        return 1;
    }
    path="/players/mangla/guild/helpdir/"+str;
    if(file_size(path) > 0)
        cat(path);
    else
        return 0;
    return 1;
}
