inherit ROOM;
void create()
{
        set("short", "地窖");
        set("long", @LONG
地窖里寒冷而潮湿，泥土的墙壁上挂着一盏油灯。昏暗的灯光下，
这里更显得阴森可怖。
LONG
        );
        set("exits", ([
                "up" : __DIR__"dijiao",
        ]));
        set("no_magic",1);
        set("coor/x",-1120);
        set("coor/y",-120);
        set("coor/z",-30);
        setup();
        replace_program(ROOM); 
}      
