// Room: /u/cuer/emei/gchang.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "广场");
set("outdoors","emei");
	set("long", @LONG
走完长长的石阶，到了一个很热闹的广场。这里是报
国寺大门前的广场，北面就是著名的报国寺，不时有上下
山的行人来来往往。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"bgsgate",
  "southdown" : __DIR__"shijie3",
  "east" : __DIR__"machehang",
]));
	set("no_clean_up", 0);

	setup();
	
}
int valid_leave(object me, string dir)
{

if(dir == "southdown" && (int)me->query("xiashan") == 1 && (string)me->query("family/family_name") == "峨嵋派")
            return notify_fail(GRN"没有经过掌门的同意，不能下山！\n"NOR); 
            return ::valid_leave(me, dir);
}