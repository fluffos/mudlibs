// Room: /d/jingzhou/road2.c

inherit ROOM;

void create()
{
        set("short", "大道");
        set("long", @LONG
这是一条青石大道。东面隐约可以看到扬州城的城墙。向西
看去，只见群山起伏，青翠碧绿，不知通向哪里。
LONG
        );
        set("exits", ([
  "east" : __DIR__"road1",
  "west" : __DIR__"road3",
]));

        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

        setup();
        replace_program(ROOM);
}

