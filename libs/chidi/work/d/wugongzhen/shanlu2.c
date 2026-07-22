// shanlu2.c 山路
// By csy 1999.03

inherit ROOM;

void create()
{
        set("short", "山路");
        set("long", @LONG
一条山路弯弯曲曲地通向山上。北面的山上好象有一片柏树林，树林
中隐隐露出亭子的一角，南面就是上山的路。
LONG
        );
        set("outdoors", "quanzhen");
        set("exits", ([
                "northeast" : __DIR__"shanlu3",
                "southeast" : __DIR__"shanlu4",
                "westdown" : __DIR__"shanlu1",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

