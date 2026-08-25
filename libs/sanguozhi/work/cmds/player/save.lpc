// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** save.c -- simple player save cmd
**
** 950711, Deathblade: Created.
*/

#include <mudlib.h>
inherit CMD;

private void main(string arg)
{
    write("不能存盘，系统会自动储存。 \n");
    return;
    this_body()->put_m_all_money();  // add by fire on Dec 13, 1997
    this_body()->save_me();
    out("存储完毕。\n");

    return;
}
