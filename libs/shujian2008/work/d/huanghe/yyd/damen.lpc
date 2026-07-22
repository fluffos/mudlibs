// 萧府大门 damen.c
// zly 99.6.21

#include <room.h>
#include <ansi.h>
#include <wanted.h>

inherit ROOM;

void create()
{ 
       set("short",MAG"萧府大门"NOR);
       set("long", @LONG
这里是晋阳大侠萧半和所住的萧府的大门，红漆包门的正上方有一块金字
黑底的长匾，上书“萧府”两个大字，门口两侧分立两个大石狮，甚是威武。
北面是萧府的大厅，南面是黄河区域了。
LONG);    
        set("exits", ([
		"north" : __DIR__"dating",
		"southeast" : "/d/huanghe/huanghe7",
        ]));    
        set("no_fight", 1);

        set("objects",([
		__DIR__"npc/zhang" : 1,
        ]));         
	setup();        
}

int valid_leave(object me, string dir)
{
	if (dir == "north" && is_wanted(me))
		return 0;
        if ( !me->query_temp("yyd_jinchai") && dir == "north" )
        return notify_fail("张妈一手把你抓住，说道：“一点规矩也不懂！”\n");
        return ::valid_leave(me, dir);
}
