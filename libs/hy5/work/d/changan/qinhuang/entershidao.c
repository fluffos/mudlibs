
#include <command.h>
inherit ROOM;

void create()
{
        set("short", "内宫通道");
        set("long", @LONG
通道两侧，自东向西依次排列着狮、獬、骆驼、象、麒麟和马六
种石雕巨兽，各有两对四座，共十二对二十四座，造型生动，栩栩如
生，使你像来到了传说的仙界。在淡淡的月照下，众石兽或蹲或立，
不畏风霜雨雪。
LONG );

        set("exits", ([
           "north":__DIR__"shidao2",
           "south":__DIR__"entershidao2",           	
]));
        set("objects", ([
                __DIR__"npc/bingshi": 2,  
                __DIR__"npc/bairenzhang": 1,  

        ]));
        setup();
}


