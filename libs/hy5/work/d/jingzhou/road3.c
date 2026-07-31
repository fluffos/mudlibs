// Room: /d/jingzhou/road3.c

inherit ROOM;

void create()
{
        set("short", "大道");
        set("long", @LONG
这是一条青石大道。向东通往扬州。向西而去，只见一座高山
青松古柏，一片大好风景。
LONG
        );
        set("exits", ([
  "east" : __DIR__"road2",
  "northwest" : __DIR__"road4",
]));

        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

        setup();
        replace_program(ROOM);
}

