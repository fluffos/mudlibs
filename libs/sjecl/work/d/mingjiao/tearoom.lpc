// tearoom.c 茶室
// Modify By River@SJ 99.06
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{ 
       set("short",HIC"茶室"NOR);
       set("long", @LONG
这里是一间茶室，是专门招待宾客时沏茶的地方。
LONG);    
	set("exits", ([		
		"east" : __DIR__"tingtang",
	]));             
	set("objects",([
             FOOD_D("tang") : 2,
             __DIR__"npc/xtong1" : 1,
	]));
	set("no_fight", 1);
        setup();       
}

void init()
{
       	object me = this_player();
        if(me->query_temp("mj/xunluo") && !me->query_temp("tearoom"))
           me->set_temp("tearoom",1);
}

int valid_leave(object me, string dir)
{
	object *ob = deep_inventory(me);
	int i = sizeof(ob);
	if((dir == "east")) {
	    while (i--)
                if(ob[i]->id("suanmei tang"))
                   return notify_fail(CYN"侍茶小僮哼了一声：喝足了还要带走呀！\n"NOR);
	}
        return ::valid_leave(me, dir);
}
