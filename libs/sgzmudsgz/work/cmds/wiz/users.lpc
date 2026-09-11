// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

/* List the user names of all people listed in the "users()" array
 *
 * Peregrin@ZorkMUD
 */

#include <mudlib.h>

inherit CMD;


private void main()
{
    object* ulist;
    string ustring;

    ulist = users();
    if (sizeof(ulist) <= 0) {
        out(sprintf("没有人在线上!!!   (甚至不包括你！)\n"));
        return;
    }
    if ((sizeof(ulist)==1) && (ulist[0]==this_user())) {
        out(sprintf("你是唯一的一位在线人士。\n"));
        return;
    }
    if(end_of_pipeline())
      out(implode(ulist->query_userid(),
                       (: $1 + " " + ($2 ? $2 : "(login)") :),
                       "")[1..] + "\n");
    else
      out((implode(ulist->query_userid(),
                       (: $1 + "\n" + ($2 ? $2 : "(login)") :),
                       "")[1..] + "\n"));

}
