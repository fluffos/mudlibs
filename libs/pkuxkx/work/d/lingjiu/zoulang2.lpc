// Room: /u/kiss/quanzhen/zhoulang2.c
// Made by: kiss

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", YEL"走廊"NOR);
	set("long", @LONG
你走在一条走廊上，走廊两边的柱上雕着精美的花纹,四周一片寂静，
东边就是玄宗台。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
"west" : __DIR__"xuzhuroom",
"east" : __DIR__"zoulang1",
"north":__DIR__"eatroom",
"south":__DIR__"xiuxishi"]));
set("no_clean_up", 0);
setup();
//replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
        if(!userp(me) && (dir == "north"))
                return notify_fail("NPC不要乱跑！\n");
        return ::valid_leave(me, dir);
}
