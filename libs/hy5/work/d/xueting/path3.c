// Room: /d/path2/shanlu1.c

inherit ROOM;

void create()
{
        set("short", "破旧官道");
        set("long", @LONG
这是一条年久失修的官道，路的两旁长满了灌木丛，路上一道
道车辙深深浅浅写着这里从前的繁华。自从黑风山有土匪盘聚，雪
镇就日渐萧条。官道东边是一个山坳。
LONG
        );
        
        set("objects",([
        	__DIR__"npc/traveller" :2,        
        ]));
        
        set("exits", ([ /* sizeof() == 1 */
//        "eastup" : "/d/heifeng/lu1",
        "west" : __DIR__"path2",
        "east": __DIR__"shanao.c",
]));
        set("no_clean_up", 0);
        set("outdoors", "xueting");
        setup();
        replace_program(ROOM);
}
