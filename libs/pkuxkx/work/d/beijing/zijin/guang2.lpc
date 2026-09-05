// Room: /d/beijing/zijincheng/guang2.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"内金水桥"NOR);
	set("long",
HIC"桥白如云，水蓝如天，桥影在水中波动，宛若天上楼台宫阙。每
到早中晚三时，从熙和门，协和门涌出一队队的御林军和侍卫去换班。\n"NOR
	);
	set("exits", ([ /* sizeof() == 6 */
  	"northeast" : __DIR__"zhaodemen",
  	"west" : __DIR__"xihemen",
 	"south" : __DIR__"wumen",
  	"north" : __DIR__"taihemen",
  	"east" : __DIR__"xiehemen",
  	"northwest" : __DIR__"zhendumen",
]));
	set("outdoors", "beijing");
	setup();
}
int valid_leave(object me, string dir)
{
	object *ob;
	int i;
        if ((dir=="south")
        && (me->query("id") == "yideng shiwei"
        || me->query("id") == "erdeng shiwei"
        || me->query("id") == "sandeng shiwei"
        || me->query("id") == "sideng shiwei"
        || me->query("id") == "wudeng shiwei"
        || me->query("id") == "liudeng shiwei")
        )
        return 0;
        
        if( dir == "south" && me->query_condition("bjkiller"))
        	{
		    ob = all_inventory( environment( me ));
    
    for(i=0; i<sizeof(ob); i++) 
    {
        if( living(ob[i]) && (ob[i]->query("id") == "yideng shiwei"
        	        || ob[i]->query("id") == "erdeng shiwei"
        || ob[i]->query("id") == "sandeng shiwei"
        || ob[i]->query("id") == "sideng shiwei"
        || ob[i]->query("id") == "wudeng shiwei"
        || ob[i]->query("id") == "liudeng shiwei") )
            return notify_fail("侍卫上前挡住你，朗声说道：想跑，没那么容易！\n");
    }    
    me->start_busy(2);
  				}     	
        return ::valid_leave(me, dir);
}
