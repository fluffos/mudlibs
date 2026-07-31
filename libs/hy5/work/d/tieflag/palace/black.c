 inherit ROOM;
void create()
{
        set("short", "黑石道路");
        set("long", @LONG
这是一条以黑石铺成的道路，道路弯曲地穿入一片暗林！入林越深，光
线越是阴暗，但林梢却透下一道天光，照在地上的黑石上，衬得四下更宛
如地狱。
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"intersection",
  "south" : __DIR__"black2",
]));
        set("outdoors", "palace"); 
        set("coor/x",160);
        set("coor/y",0);
        set("coor/z",20);
        set("coor/x",160);
        set("coor/y",0);
        set("coor/z",20);
        set("coor/x",160);
        set("coor/y",0);
        set("coor/z",20);
        set("coor/x",160);
        set("coor/y",0);
        set("coor/z",20);
        setup();
        replace_program(ROOM);
}   
