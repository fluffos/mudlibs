#include <ansi.h>
inherit ROOM;
void create ()
{
set ("short",HIR + "太空船" + NOR);
set ("long", @LONG

这是一艘已经锈的不象样了的的太空船。
LONG);
set("item_desc" , ([ /* sizeof() == 1 */
"out": "飞船外云雾缭绕，什么也看不清楚。\n",
]));
  set("exits", ([ /* sizeof() == 1 */
"out":"/d/taikong/zongshu",
]));
//  set("objects", ([ /* sizeof() == 1 */
//"/u/ezine/npc/tong" : 1,
//]));
  set("no_magic", 1);
set("valid_startroom", 1);
setup();
}

int valid_leave(object me, string dir)
{
     if( dir=="out" && !wizardp(me) )
        return notify_fail("那里只有巫师才能进去。\n");
     return ::valid_leave(me, dir);
}

