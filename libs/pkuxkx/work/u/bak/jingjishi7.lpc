//竞技室
//by male

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIR"竞技室"NOR);
	set("long", @LONG
     一进到竞技室里，你就感到一股浓浓的杀气。这种气氛让你不寒而栗！
你的对手是一个身材和你差不多的男子，他正淡淡的看着你，你不仅要问
这就是将要与我做生死相搏的人么？
LONG
	);
        set("outdoors", "city");

	set("exits", ([
                "out" : "/d/city/restroom",

	]));


	setup();
}
int do_dig(string arg)
{
   write(HIR"生死相搏，岂能儿戏？\n"NOR);
  return 1;
}
void init()
{
   add_action("do_dig","dig");
/*
object zhe;
 if(! objectp( zhe = present("boji zhe", this_object()) ))
{
 zhe=load_object("/d/city/npc/boji");
if(zhe) zhe->move(this_object());
}
*/
return;
}
int valid_leave(object me, string dir)
{
if(me->is_fighting())
{
return notify_fail(HIR"生死相搏，不能中途退出！\n"NOR);
}
else
{
return::valid_leave(me,dir);
}
}

