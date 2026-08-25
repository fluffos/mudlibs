#include <std.h>
#include <dirs.h>

inherit DAEMON;

nosave private string __Homes;

void create() {
    string *tmp;
    int i, maxi;

    daemon::create();
    set_no_clean(1);
    __Homes = "<HTML><HEAD><TITLE>Creator Home Pages</TITLE></HEAD><BODY>"
      "<H1>The Home Pages of Some Nightmare Creators</H1><DL>\n";
    maxi = sizeof(tmp = get_dir(REALMS_DIRS+"/"));
    for(i=0; i<maxi; i++)
      if(file_exists(REALMS_DIRS+"/"+tmp[i]+"/public_html/index.html"))
        __Homes+="<DT><A HREF=/~"+tmp[i]+"/index.html>"+
	  "<IMG SRC=/images/Folder.gif>\n"+
          possessive_noun(capitalize(tmp[i]))+" Home Page</A>";
    __Homes += "</DL>";
}

string gateway() { return __Homes; }

