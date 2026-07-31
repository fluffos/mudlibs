//cool 98.4.18
inherit ROOM;

void create()
{
        set("short", "武馆大门");
        set("long", @LONG
这里是一个大宅子，门口高悬一个大匾“襄阳武馆”，立了两个石狮，
你从大门口瞧进去，好象里面人来人往，都很繁忙的样子，门口站着两个
门卫，神情威严。
LONG);
        set("exits", ([
                "north" : __DIR__"dayuan",
                "south" : __DIR__"xiaojs",
        ]));
        set("no_fight",1);
        set("objects", ([
__DIR__"npc/menwei" : 1,
        ]));
        setup();
}

int valid_leave(object me, string dir)
{
	object *inv,kicker;
	int sizeinv,n,tt;
        if (me->query("combat_exp") >=  50000
           && dir =="north")
	     return notify_fail("大门里面传出来一个声音：我们这里只接纳初入江湖的新手。\n");
        if (me->query("potential") >=  50000
           && dir =="north")
	     return notify_fail("大门里面传出来一个声音：我们这里只接纳初入江湖的新手。\n");

		inv=all_inventory(me);
		sizeinv=sizeof(inv);
	
		while (sizeinv--)
		{
       			if (inv[sizeinv]->is_character())  
     				return notify_fail("你想进去拐卖人口？\n");
       		
		}

	return ::valid_leave(me, dir);
        
}
