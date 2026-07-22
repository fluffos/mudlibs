// tandi.c 潭底
// Modify By River@SJ 99.06
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{ 
       set("short",HIB"潭底"NOR);
       set("long", @LONG
你身处碧水寒潭的潭底，忽然间一股寒气直扑而来，你不由得连打了一个
寒颤。往上看，寒冰盖顶，只透入丝丝阳光，偶有游鱼从你身连滑过。但深潭
中确实太冷，看来不能久留。
LONG);    
	set("exits", ([
            "up" : __DIR__"bishui",				
	]));             	
        setup();
}

void run(object ob)
{
        if (!ob) return;
        if (environment(ob) == this_object()){
	remove_call_out("run");
	call_out("run", 10, ob);
	ob->set_temp("last_damage_from", "掉进潭底淹");
	ob->receive_damage("jing", 20);
	ob->receive_damage("qi", 20);
	write(HIB"\n你只觉一股剌骨的寒气直逼心头。\n\n"NOR);
	}
	return 0;
	
}

void init()
{
        object ob = this_player();
        call_out("run", 10+random(10), ob);
}
