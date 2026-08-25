/*    /www/gateways/efuns.c
 *    from Nightmare IV
 *    a gateway listing of efun documentation
 *    created by Descartes of Borg 940615
 */

#include <std.h>
#include <dirs.h>

inherit DAEMON;

string __Links;

private void load();

void create() {
    daemon::create();
    load();
}

 private void load() {
    string *dirs, *files;
    int i, j, maxi, maxj;

    __Links = "<HTML><HEAD><TITLE>SimulEfun Documentation Gateway</TITLE>"
      "<H1>Nightmare Mudlib 3.3 SimulEfuns</H1>\n";
    if(!(maxi = sizeof(dirs = get_dir(DIR_WWW_SIMULEFUNS+"/")))) {
        __Links += "<BODY>No simul efuns known.</BODY></HTML>";
        return;
    }
    __Links += "<UL>";
    for(i=0; i<maxi; i++) {
        __Links += "<LI><A HREF=http:/doc/SimulEfun/"+dirs[i]+">"+
          dirs[i][0..strlen(dirs[i])-6] + "()</A>";
        __Links += "</UL>";
    }
    __Links += "</BODY></HTML>";
}

string gateway() { return __Links; }
