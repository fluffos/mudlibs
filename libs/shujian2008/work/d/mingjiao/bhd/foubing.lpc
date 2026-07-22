// foubing.c 冰山
// Modify By River@SJ 99.06
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short",HIW"冰山"NOR);
	set("long", @LONG
这是一块很大浮动冰山，是由万年玄冰组成。由于前面的冰山受到火山之
热，不断的熔化，而产生吸力，把许多浮冰不断的吸进，所以冰山是不断的靠
近火山。
LONG);
        set("no_fight", 1);
        set("no_get_from", 1); 
        set("no_sleep_room", 1);
	set("ppl", 0);
        set("outdoors","极北");
	setup();
}

void run(object ob)
{
	set("ppl", 0);
	if (!ob || environment(ob)!= this_object()) return;
	tell_object(ob, HIW"\n冰山缓缓的向北飘去。\n\n"NOR);
	ob->move(__DIR__"foubing1");
}

void init()
{
	set("ppl", 1);
	call_out("run", 20+random(10), this_player());
}
