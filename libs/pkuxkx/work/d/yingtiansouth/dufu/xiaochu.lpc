inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "小厨房");
        set("long", 
"这里是孟家的小厨房，专做一些细致的点心。
你可以坐(sit)下来用餐。\n"

        );
        set("exits", ([
                
                "south" : __DIR__"huilang2",
               // "east" : __DIR__"dongmen",
               // "west" : __DIR__"dating",
               // "south" : __DIR__"shiwei2",
                
        ]));
        set("objects", ([
		__DIR__"npc/chuniang" : 1,
        //"/d/city/npc/bing" : 1,
        
        ]));
        //set("outdoors", "yingtianfu");
        setup();
   
}

void init()
{
	add_action("do_sit","sit");
}
int food_exist(object me)
{
	object *foods;
	foods=all_inventory(this_object());
	for (int i=0;i<sizeof(foods);i++)
	if (foods[i]->query("meng_food"))
	return 1;//地上有吃的
	foods=all_inventory(me);
	for (int i=0;i<sizeof(foods);i++)
	if (foods[i]->query("meng_food"))
	return 2;//身上有吃的
	return 0;
}
int do_sit()
{
	object me=this_player(),ob;
	message_vision("$N找了一张空桌，坐了下来。\n",me);
	if (!ob=present("chu niang",this_object()))
	{
		tell_object(me,"可惜厨娘这会儿并不在，你只好等等再用餐了。\n");
		return 1;
	}
	if (food_exist(me)==2)
	{
		tell_object(me,"你身上不是有吃的吗？\n");
		return 1;
	}
	if (food_exist(me)==1)
	{
		tell_object(me,"这里不是有吃的吗？\n");
		return 1;
	}
	if (!ob->query("is_chuniang"))
	{
		tell_object(me,"可惜厨娘这会儿并不在，你只好等等再用餐了。\n");
		return 1;
	}
	ob->OfferFood(me);
	return 1;
}