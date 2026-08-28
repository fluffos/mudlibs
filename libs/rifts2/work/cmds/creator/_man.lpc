/*    /cmds/system/_man.c
 *    from Nightmare Mudlib 3.2
 *    a command to access the man documents for efuns and such
 *    created by Descartes of Borg 940122
 */

#include <std.h>
#include <dirs.h>

inherit DAEMON;

#define MAN_PAGES ({ "SimulEfun", "efun", "applies", "lfun" })

int cmd_man(string str) {
    string d, tmp;
    string *pages, *dirs;
    int i;

    if(!str)
        return notify_fail("Usage: <man [function]>\n");
    d = str[0..0];
    i = sizeof(MAN_PAGES);
    pages = ({});
    dirs = ({});
    while(i--){
        dirs += map_array(filter_array(get_dir(DIR_DOCS+"/"+
            MAN_PAGES[i]+"/*"), (: (file_size($2 + $1) == $3) :),
			(DIR_DOCS+"/"+MAN_PAGES[i]+"/"), -2), (: ($2 + $1) :),
			MAN_PAGES[i]+"/");
    }
    dirs += MAN_PAGES;
    i = sizeof(dirs);
    while(i--) 
      if(file_exists(tmp = sprintf("%s/%s/%s", DIR_DOCS, dirs[i],
        str))) pages += ({ tmp });
    if(!(i = sizeof(pages))) return notify_fail("No such man page.\n");
    else if(i > 1) 
      message("system", "Showing only the first of "+i+" man pages.",
        this_player());
    this_player()->more(pages[0]);
    return 1;
  }