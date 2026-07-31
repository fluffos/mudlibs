// Room: /d/emei/shierpan3.c

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",HIC "十二盘" NOR);
	set("long", @LONG
这里石阶陡折多弯，号称「十二盘」。你见路边有个八音池，有人正在向
池中击掌(clap)。由此西上可达华严顶，东下则到万年庵。
LONG
	);
	set("outdoors", "峨眉山");
	set("exits", ([ 
  "eastdown" : __DIR__"shierpan2",
  "southwest" : __DIR__"shierpan4",
]));
	setup();
}
int valid_leave(object me, string dir)
{
 if (dir == "southwest" && (int)me->query_skill("dodge", 1) < 101 ) {
      me->improve_skill("dodge",(int)me->query("dex"));
      me->receive_damage("jingli",  (int)me->query("dex"));
     return 1; }     return ::valid_leave(me, dir);

} 
void init()
{
	add_action("do_clap", "clap");
}

int do_clap()
{
	object me;
	me = this_player();

        if (me->is_busy() || me->is_fighting())
	return notify_fail("你正忙着哪！\n");

	if((int)me->query("jingli", 1) < 15 )
	return notify_fail("你太累了，还是好好休息吧。\n");

	if( (int)me->query_skill("strike", 1) > 40 ) {
	message_vision("$N正在象八音池击掌。\n", me);
	me->receive_damage("jingli", 15);
	return 1;
	}
	if( (int)me->query_skill("strike", 1 ) < 40 ) {
	message_vision("$N正在象八音池击掌。\n", me);
	me->receive_damage("jingli", 10+random(10));
	me->improve_skill("strike", (int)me->query("str"));
	return 1;
	}
}