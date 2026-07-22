// Room: /d/emei/wannianan.c

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",HIY "万年庵" NOR);
	set("long", @LONG
万年庵建在一座突起的山峰上，周围古木森森，清泉淙淙，闲步无坎，吟
游无坷，景色非常迷人。由此西上过十二盘可达华严顶，南下至白龙洞。
LONG
	);
	set("outdoors", "峨眉山");
	set("exits", ([ 
  "westup" : __DIR__"shierpan",
  "enter" : __DIR__"wanniananzd",
  "southdown" : __DIR__"bailongdong",
]));
	setup();
}

int valid_leave(object me, string dir)
{
 if (dir == "westup" && (int)me->query_skill("dodge", 1) < 101 ) {
      me->improve_skill("dodge", (int)me->query("dex"));
      me->receive_damage("jingli",  (int)me->query("dex"));
      return 1; }     return ::valid_leave(me, dir);

} 
