// format_page()
// Tweaked by Radix for who command : MArch 4, 1997
string format_page(string *items, int columns) {
    int width, i, j, x;
    string ret;

    if(!columns) columns = 2;
    ret = "";
    if(!this_player())
        width = 75/columns;
    else
        width = this_player()->query_cols() / columns;
    for(i=0, x = sizeof(items); i<x; i+=columns) {
        for(j=0; j<columns; j++) {
            if(i+j >= x) break;
            ret += arrange_string(items[i+j], width);
        }
        ret += "\n";
    }
    return ret;
}
