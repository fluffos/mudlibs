 inherit ROOM;
void create()
{
        set("short", "走道");
        set("long", @LONG
屋后又是一条走道，走道两旁是雕刻精致的石壁，壁上嵌着发亮的铜灯，
有一扇很大的巨石屏风，遮住了走道的尽头。
LONG
        );
        set("exits", ([ 
                "west" : __DIR__"palace4",
                "north" : __DIR__"bathroom",
                                ]));
        set("objects", ([
//              __DIR__"npc/nun" : 2,
        ]) );
        set("indoors", "eren");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}
