//jinling  xijie1.c
inherit ROOM;

void create()
{
        set("short", "西街");
        set("long", @LONG
这里是金陵镇西边的主要街道，往东通往镇上最热闹的广场，往西
则通往西门，街道上人来人往，一派繁华的景象。
LONG
        );
        set("exits", ([/* sizeof() == 4 */
           "west" : __DIR__"xijie2",
           "east" : __DIR__"zhongxin",
]));
        set("objects", ([
              __DIR__"npc/yiren" : 1,
			]) );

 set("outdoors", "jinling");

        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}