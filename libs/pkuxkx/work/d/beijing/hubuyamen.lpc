// Room: /d/beijing/hubu
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", RED"户部府衙大门"NOR);
        set("long",
CYN"这户部衙门掌管的是朝廷钱粮赋税收入，所以朝廷派有重兵看守，三
步一岗五部一哨，进出的人都要盘查搜身，防卫极之严密，门口挨挨压压
排了一长溜儿官轿，俱都是各省藩司衙门来京回事的、提取库银的。\n"NOR
        );

        set("exits", ([
                "north" : __DIR__"guloudajie_w2",
                "south"  : __DIR__"hubuyamen2"

        ]));
	set("objects", ([
	    "/d/beijing/npc/shiwei":4,
	]));
        setup();

}
int valid_leave(object me, string dir)
{
    int i;
    object *ob;
    if( dir !="south" || me->query("class") == "officer")
        return ::valid_leave(me, dir);
    ob = all_inventory( environment( me ));
    for(i=0; i<sizeof(ob); i++) 
    {
        if( living(ob[i]) && ob[i]->query("id") == "shi wei" )
            return notify_fail("侍卫伸手拦住你朗声说道：里面没什么好看的，马上离开这里....！\n");
    }            
    return ::valid_leave(me, dir);
}

