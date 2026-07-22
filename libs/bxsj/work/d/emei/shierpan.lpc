// Room: /d/emei/shierpan.c

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",HIC "十二盘" NOR);
	set("long", @LONG
这里石阶陡折多弯，号称「十二盘」。由此西上可达华严顶，东下则到万
年庵。
LONG
	);
	set("outdoors", "峨眉山");
	set("exits", ([ 
  "eastdown" : __DIR__"wannianan",
  "southwest" : __DIR__"shierpan2",
]));

	setup();
}
int valid_leave(object me, string dir)
{
 if (dir == "southwest" && (int)me->query_skill("dodge", 1) < 101 ) {
      me->improve_skill("dodge", (int)me->query("dex")/10);
      me->receive_damage("jingli",  (int)me->query("dex"));
      return 1; }     return ::valid_leave(me, dir);

} 
	