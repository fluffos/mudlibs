// Room: /d/emei/shierpan2.c

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
  "westup" : __DIR__"shierpan3",
  "northeast" : __DIR__"shierpan",
]));
	set("no_clean_up", 0);

	setup();
}
int valid_leave(object me, string dir)
{
 if (dir == "westup" && (int)me->query_skill("dodge", 1) < 101 ) {
      me->improve_skill("dodge",(int)me->query("dex")/10);
      me->receive_damage("jingli",  (int)me->query("dex"));
      return 1; }     return ::valid_leave(me, dir);

} 
