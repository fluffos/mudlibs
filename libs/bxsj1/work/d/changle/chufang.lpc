// eatroom.c 厨房 
// Modify By River@SJ 99.06
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{ 
       set("short",HIW"厨房"NOR);
       set("long", @long
这里是长乐帮的厨房。位于西廊之外的一间很大的房间。房角里有一只小
炭炉。也不知道在炖著什么东西，波波波的直响。桌子上放著一些煮好的食物，
香味扑鼻。
long);
	set("exits", ([		
		"north" : __DIR__"zoulang2",
	]));             
	set("objects",([
             FOOD_D("rice") : 1,
             FOOD_D("cha") : 2,
             __DIR__"npc/tong" : 1,
	]));
	set("no_fight", 1);
	setup();
}

int valid_leave(object me, string dir)
{
	object *ob = deep_inventory(me);
	int i = sizeof(ob);
	if( dir == "north" ){
		while (i--)
		if(ob[i]->id("xiang cha") || ob[i]->id("rice"))
			return notify_fail(CYN"小僮哼了一声：吃饱喝足了还要带走呀！\n"NOR);
	}
	return ::valid_leave(me, dir);
}
