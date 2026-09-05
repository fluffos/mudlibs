// Room: /d/beijing/xingbu.c
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", RED"刑部府衙大门 "NOR);
        set("long",
CYN"走到门前，只见大门紧紧的闭着，周围的青砖围墙足有八、九尺之高，
墙内不时有衙役巡查时发出的声响，夹杂着一阵阵的狗吠声，门外战着的那
两个凶恶的衙役正恶狠狠的瞪着你，看样子像想把你整个儿吞进肚子里似的。\n"NOR
        );

        set("exits", ([
                 "north": __DIR__"xingbuyamen2",
                 "south": __DIR__"guloudajie_e",
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
    if( dir !="north" || me->query("class") == "officer")
        return ::valid_leave(me, dir);
    ob = all_inventory( environment( me ));
    for(i=0; i<sizeof(ob); i++) 
    {
        if( living(ob[i]) && ob[i]->query("id") == "shi wei" )
            return notify_fail("侍卫伸手拦住你朗声说道：里面没什么好看的，马上离开这里....！\n");
    }            
    return ::valid_leave(me, dir);
}
