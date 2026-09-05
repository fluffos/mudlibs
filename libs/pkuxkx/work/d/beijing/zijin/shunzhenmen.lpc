// Room: /d/beijing/zijin/shunzhenmen.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"顺贞门"NOR);
	set("long",
HIC"这是御花园北面的正门，在清朝，平时是关着的，皇帝、皇后、
妃嫔出入时，随时启闭。\n"NOR
	);
	set("exits", ([ /* sizeof() == 2 */
  	"north" : __DIR__"shenwumen",
  	"south" : __DIR__"yuhuayuan",
]));
        set("outdoors", "beijing");

	setup();

}

int valid_leave(object me, string dir)
{
	object *ob;
	int i;
        if ((dir=="north")
        && (me->query("id") == "yideng shiwei"
        || me->query("id") == "erdeng shiwei"
        || me->query("id") == "sandeng shiwei"
        || me->query("id") == "sideng shiwei"
        || me->query("id") == "wudeng shiwei"
        || me->query("id") == "liudeng shiwei")
        )
        return 0;
        
        if( dir == "north" && me->query_condition("bjkiller"))
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