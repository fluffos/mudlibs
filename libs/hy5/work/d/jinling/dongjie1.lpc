//jinling  dongjie1.c
inherit ROOM;

void create()
{
        set("short", "东街");
        set("long", @LONG
这里是金陵镇东边的主要街道，往西通往镇上最热闹的广场，往东
则通往东门，街道上人来人往，一派繁华的景象。南面好象有一家酒楼。
LONG
        );
        set("exits", ([/* sizeof() == 4 */
           "east" : __DIR__"huaihe",
           "west" : __DIR__"zhongxin",
           "south" : __DIR__"jiulou",
            "north" : __DIR__"wuyigang",
]));
set("objects", ([
              __DIR__"npc/rascal" : 1,
			]) );

         set("outdoors", "jinling");

        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}