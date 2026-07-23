//jinling  beijie2.c
inherit ROOM;

void create()
{
        set("short", "北街");
        set("long", @LONG
这里是金陵镇北边的主要街道，往南通往镇上最热闹的广场，往北
则通往长江边，你的左边是当铺，右边是一家武器店，街道上人来人往，
一派繁华的景象。
LONG
        );
        set("exits", ([/* sizeof() == 4 */
           "north" : __DIR__"beijie1",
           "south" : __DIR__"zhongxin",
           "west" : __DIR__"dangpu",
           "east" : __DIR__"wuqidian",
]));
        set("objects", ([
              __DIR__"npc/stealer" : 1,
              __DIR__"npc/boy" : 1,
			]) );

 set("outdoors", "jinling");

        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}