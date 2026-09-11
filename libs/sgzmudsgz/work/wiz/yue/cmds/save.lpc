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
this_body()->set_start_location(file_name(environment(this_body())));
    this_body()->save_me();
    out("存储完毕。\nfinished saving place.");

    return;
}
