#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIM"东厂大门"NOR);
	set("long",
HIC"这里便是明成祖朱棣为了镇压政治上的反对力量而设立一个
称为“东缉事厂”的特务机构，简称“东厂”的官署，东厂由皇帝所
宠信宦官担任首领。官署门口站立了几名锦衣卫。\n"NOR
	);

	set("exits", ([
		"south" : "/d/beijing/zijin/donghuamen",
		"north" : __DIR__"guangchang",
	]));

	set("outdoors","beijing");
  set("objects", ([
               __DIR__"npc/jinyiwei" : 5,
        ]));
	
	setup();
}

int valid_leave(object me, string dir)
{
    int i;
    object *ob;

    if (dir != "north" )
        return ::valid_leave(me, dir);
        	
    if (me->query("special_skill/sociability")) 
        return ::valid_leave(me, dir);        
        
    if (me->query("class") == "eunuch" && present("guanfang yin",me))
        return ::valid_leave(me, dir);
    
    ob = all_inventory( environment( me ));
    
    for(i=0; i<sizeof(ob); i++) 
    {
        if( living(ob[i]) && ob[i]->query("id") == "jin yiwei" )
            return notify_fail("锦衣卫上前挡住你，朗声说道：闲杂人等禁止入内！\n");
    }            
//    return ::valid_leave(me, dir);
}