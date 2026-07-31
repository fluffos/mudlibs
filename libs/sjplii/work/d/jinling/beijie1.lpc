//jinling  beijie1.c
inherit ROOM;

void create()
{
        set("short", "北街");
        set("long", @LONG
这里是金陵镇北边的主要街道，往南通往镇上最热闹的广场，往北
则通往长江边，你的左边是衙门，右边是一家钱庄，街道上人来人往，
一派繁华的景象。
LONG
        );
        set("exits", ([/* sizeof() == 4 */
           "north" : __DIR__"yuhuatai",
           "south" : __DIR__"beijie2",
           "west" : __DIR__"yamen",
           "east" : __DIR__"qianzhuang",
]));
        set("objects", ([
              __DIR__"npc/wulinren" : 1,
              __DIR__"npc/shangren" : 1,
			]) );

 set("outdoors", "jinling");

        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}