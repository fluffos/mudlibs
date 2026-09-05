inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIY"午门 "NOR);
	set("long",
HIC"午门是紫禁城的正门，门左右向前伸出呈凹形，俗称五凤楼。城\n"
"楼内设有宝座，东西侧有钟鼓明廊，每逢朝会或庆典等都要鸣钟击鼓，\n"
"出征将士凯旋归来，皇帝都亲自到午门正楼举行受俘礼。\n"NOR
	);

	set("exits", ([
        "north" : __DIR__"guang2",
        "south" : __DIR__"duanmen",
	]));

	set("objects", ([
		"/d/beijing/npc/shiwei1" : 4,
	]));

	set("outdoors","beijing");
	setup();
}

int valid_leave(object me, string dir)
{
    int i;
    object *ob;
    if (me->query("special_skill/sociability")) 
        return ::valid_leave(me, dir);        

    if ( dir == "north" && me->query("id") == "xun bu")
        return notify_fail("一等侍卫上前挡住你，朗声说道：皇宫禁地，禁止闲杂人等出入！\n");
    if (dir != "north" || me->query("class") == "officer" || me->query("class") == "eunuch" ||present("hgtongxing ling",this_player()))
        return ::valid_leave(me, dir);
    
    ob = all_inventory( environment( me ));
    for(i=0; i<sizeof(ob); i++) 
    {
        if( living(ob[i]) && ob[i]->query("id") == "yideng shiwei" )
            return notify_fail("一等侍卫上前挡住你，朗声说道：皇宫禁地，禁止闲杂人等出入！\n");
    }            
    return ::valid_leave(me, dir);
}
