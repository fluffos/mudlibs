// Room: /d/beijing/zijin/shenwumen.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"神武门"NOR);
	set("long",
HIC"这是紫禁城的后宫门，此往北就出了紫禁城。\n"NOR
	);
	set("exits", ([ /* sizeof() == 3 */
  	"south" : __DIR__"shunzhenmen",
  	"west" : __DIR__"tongdao8",
  	"north" : "/d/beijing/jingshan",
  	"east" : __DIR__"tongdao7",
]));
  	set("objects", ([
		 "/d/beijing/npc/shiwei1" : 4,
	]));
	set("outdoors", "beijing");
	setup();
}
int valid_leave(object me, string dir)
{
    int i;
    object *ob;
    if (dir != "north" && me->query("id") == "xun bu")
        return 0;
    if (me->query("special_skill/sociability")) 
        return ::valid_leave(me, dir);  
    if ((dir=="north")
    && (me->query("id") == "yideng shiwei"
    || me->query("id") == "erdeng shiwei"
    || me->query("id") == "sandeng shiwei"
    || me->query("id") == "sideng shiwei"
    || me->query("id") == "wudeng shiwei"
    || me->query("id") == "liudeng shiwei"))
    return 0;
                
    if (dir == "north" || me->query("class") == "officer" || me->query("class") == "eunuch" ||present("hgtongxing ling",this_player()))
        return ::valid_leave(me, dir);
    ob = all_inventory( environment( me ));
    for(i=0; i<sizeof(ob); i++) 
    {
        if( living(ob[i]) && ob[i]->query("id") == "yideng shiwei" )
            return notify_fail("一等侍卫上前挡住你，朗声说道：皇宫禁地，禁止闲杂人等出入！\n");
    }            
    return ::valid_leave(me, dir);
}
