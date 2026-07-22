// leizudian.c 雷祖殿

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "雷祖殿");
        set("long", @LONG
雷祖殿中供真武大帝，真武原称玄武，为避宋圣祖赵玄郎的讳，改称
真武。他是由星宿信仰而来的，是二十八宿中北方七宿的合称。殿中放了
红木大香案，香案上供品齐备，香火十分旺盛。 
LONG
        );
       
        set("exits", ([
                "southeast" : __DIR__"donglang4",
                "north" : __DIR__"donglang5",
        ]));
        set("objects", ([
                __DIR__"npc/zhangyao" : 1, 
   ]));
 
        setup();
        replace_program(ROOM);
}



