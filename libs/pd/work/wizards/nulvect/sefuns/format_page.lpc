varargs string format_page(string *items, int columns, int screen) {
    int width, i, j, x;
    string ret;

    if(!columns) columns = 2;
    if (!screen) screen = 75;
    ret = "";
    width = screen/columns;
    for(i=0, x = sizeof(items); i<x; i+=columns) {
        for(j=0; j<columns; j++) {
            if(i+j >= x) break;
            ret += arrange_string(items[i+j], width);
        }
        ret += "\n";
    }
    return ret;
}
