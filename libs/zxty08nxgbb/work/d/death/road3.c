// Room: /d/death/road3.c
inherit ROOM;
void create()
{
        set("short", "路的尽头");
        set("long", @LONG
你走在一条温暖、气氛祥和而又宁静的路上，只觉得心里既没有快乐，
也没有悲伤。你记不起昨天做了些啥，也想不起将来要做什么。你的感
觉不是在走，而是在飘呀、飘呀...
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "north" : "/d/death/road3",
  "south" : "/d/death/road2",
]));
        setup();
        replace_program(ROOM);
}

