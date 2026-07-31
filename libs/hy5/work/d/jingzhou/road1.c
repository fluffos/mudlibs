// Room: /d/jingzhou/road1.c

inherit ROOM;

void create()
{
        set("short", "大道");
        set("long", @LONG
你走在一条青石大道上。北面通向扬州城。
LONG
        );
        set("exits", ([
  "northeast" : "/d/city/ximen",
  "west" : __DIR__"road2",
]));

        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

        setup();
        replace_program(ROOM);
}

