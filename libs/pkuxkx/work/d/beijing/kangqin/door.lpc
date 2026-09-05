// Room: /d/beijing/kangqin/door.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"王府大门"NOR);
	set("long",
MAG"你正站在一座豪华的府门前，门前有两只极大的石狮子，门
上高悬一块横匾，上书「康亲王府」四个金字。门口站着两排侍卫，
身着锦衣，手执钢刀，气宇轩昂。\n"NOR
	);
	set("exits", ([ /* sizeof() == 2 */
  	"south" : __DIR__"tingyuan",
  	"north" : "/d/beijing/lingjing",
]));
	set("objects",([
		"/d/beijing/npc/bj_bing" : 4,
		]));
	set("outdoors", "beijing");
	setup();

}
int valid_leave(object me, string dir)
{
    object *ob;
    int i;
    
    if (me->query("special_skill/sociability")) 
        return ::valid_leave(me, dir);   
    if( dir != "south" || me->query("class") == "officer" )
        return ::valid_leave(me, dir);
    ob = all_inventory( environment( me ));
    for(i=0; i<sizeof(ob); i++) 
    {
        if( living(ob[i]) && ob[i]->query("id") == "guan bing" )
            return notify_fail("官兵拦住了你的去路\n");
    }
    return ::valid_leave(me, dir);
}
