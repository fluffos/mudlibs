 inherit ROOM;
void create()
{
        set("short", "神水宫分舵");
        set("long", @LONG
这里是神水宫密秘分舵之一，但现在已经废弃不用了。
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"bottom2",
]));
        set("coor/x",200);
        set("coor/y",-30);
        set("coor/z",10);
        setup();
}       
