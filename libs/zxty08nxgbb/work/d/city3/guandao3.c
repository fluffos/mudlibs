//by enter xiaoya

inherit ROOM;

void create()
{
        set("short", "官道");
        set("long", @LONG
道路两旁开满了金黄色的油菜花,微风吹过,飘来阵阵花香,再往
南走,眼看人人向往的天府之国---成都就要到了。
LONG
        );

        set("exits", ([
                "east" : __DIR__"guandao4",
                "west" : __DIR__"dadao7",
        ]));

        set("outdoors", "chengdu");
        setup();
        replace_program(ROOM);
}


