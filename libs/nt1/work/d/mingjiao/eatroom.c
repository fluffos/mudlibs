// eatroom.c 厨房 
// Modify By River@SJ 99.06
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{ 
       set("short",HIW"厨房"NOR);
       set("long", @LONG
满屋的果香和肉香，你一走进这里，闻得阵阵的香气，就立即产生饱
餐一顿的念头。有几个厨子正在忙忙碌着，有几个小僮在旁侍侯着。
LONG );
	set("exits", ([		
		"east" : __DIR__"xting",
	]));             
	set("objects",([
             __DIR__"npc/xtong2" : 1,
	]));
        set("no_fight", 1);

        set("coor/x",-300);
        set("coor/y",210);
        set("coor/z",120);
        setup();
}

void init()
{
        object me = this_player();
        if(me->query_temp("mj/xunluo") && !me->query_temp("eatroom"))
           me->set_temp("eatroom",1);
}

int valid_leave(object me, string dir)
{
	object *ob = deep_inventory(me);
	int i = sizeof(ob);
        if((dir == "east")){
          while (i--)
          if(ob[i]->id("suanmei tang") || ob[i]->id("zongzi"))
	     return notify_fail("小僮哼了一声：吃饱喝足了还要带走呀！\n");                
        }
        return ::valid_leave(me, dir);
}
