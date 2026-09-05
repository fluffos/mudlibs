//洛阳，扩展地图
//by kiden
//2006-9-8
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIG"小舍"NOR);
        set("long", @LONG
小舍中，桌椅几榻，无一而非竹制，墙上悬着一幅墨竹，笔势纵横，
墨迹淋漓，颇有森森之意。桌上放着一具瑶琴，一管洞箫。
LONG
        );

        set("exits", ([
               "south" : __DIR__"xiaoshe4",  //厨房
               "west" : __DIR__"zhuwu",     
               "north" : __DIR__"xiaoshe5",  //休息之所      
        ]));
        set("objects", ([
             "/d/riyuejiao/npc/lvzhuweng" : 1,
        ]));
        setup();
        replace_program(ROOM);
}

