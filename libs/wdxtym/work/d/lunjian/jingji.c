#include <room.h>
inherit ROOM;

void create()
{
	set("short", "竞技场");
	set("long", "这里是华山论剑的比武竞技场。");
	set("exits", ([
		"out" : __DIR__"enter",
	]));
	set("objects",([
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	me->force_me("quit");
	return 0;
}
void init()
{
   add_action("do_eat", "eat");
   add_action("do_eat", "use");


}
int do_eat(string arg){

   object me = this_player();

 tell_object(me,"论剑不能使用任何药物！！\n");
 return 1;

}