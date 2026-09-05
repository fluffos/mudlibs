string skip_spaces(string str) {
    int x, y;
    if (!stringp(str)) return str;
    x = 0;
    y = strlen(str)-1;
    while (x<y) {
        if ((str[x]==' ')||(str[x]=='\t')||(str[x]=='\n')) x++;
        else break;
    }
    while (x<y) {
        if ((str[y]==' ')||(str[y]=='\t')||(str[y]=='\n')) y--;
        else break;
    }
    return str[x..y];
}

string remove_spaces(string str) {
    str = implode(explode(str, " "), "");
    return str;
}