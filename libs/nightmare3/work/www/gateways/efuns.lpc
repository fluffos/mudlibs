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

    __Links = "<HTML><HEAD><TITLE>Efun Documentation Gateway</TITLE>"
      "<H1>MudOS Driver Efuns</H1>\n";
    if(!(maxi = sizeof(dirs = get_dir(DIR_WWW_EFUNS+"/")))) {
        __Links += "<BODY>No efuns known.</BODY></HTML>";
        return;
    }
    for(i=0; i<maxi; i++) {
        __Links += "<H2>"+dirs[i]+":</H2>\n<UL>";
        if(!(maxj = sizeof(files = get_dir(DIR_WWW_EFUNS+"/"+dirs[i]+"/"))))
          continue;
        for(j=0; j<maxj; j++)
          __Links += "<LI><A HREF=http:/doc/efun/"+dirs[i]+"/"+files[j]+">"+
            files[j]+"()</A>";
        __Links += "</UL>";
    }
    __Links += "</BODY></HTML>";
}

string gateway() { return __Links; }
