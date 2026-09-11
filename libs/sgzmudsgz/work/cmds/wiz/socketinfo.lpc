// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>

inherit CMD;

private void main(string str) {
    mixed* lines = socket_status();
    string array linea;
    string line;
    
    foreach (linea in lines) {
        line = implode (linea, " ");
        if (line[0..1] != "-1")
            out(line + "\n");
    }
}
