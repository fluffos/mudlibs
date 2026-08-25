/* 
 * Externalize by Baldrick june '97.
 */

#include <standard.h>
#include <cmd.h>
inherit CMD_BASE;

void setup(){

position = 1;
}

protected int cmd(string bing, object me) {
    object ob;

    ob = clone_object("/secure/upgrade");
    if(!ob->new_player(me))
      write("Failed to upgrade.\n");
    return 1;
} /* upgrade_player() */

