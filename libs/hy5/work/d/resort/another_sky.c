 inherit ROOM;
void create()
{
        set("short", "世外桃源");
        set("long", @LONG
微风拂着你的面孔，送来阵阵花香。四面青山环抱，景色宜人。
如果不是穿过山洞，就是在恰克卜里山中寻上一年半载也不可能找
到这里。你陶醉在阵阵花香之中，恰似到了天上人间。
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"small_river",
  "east" : __DIR__"cave_tunnel",
]));
        set("outdoors", "resort"); 
        set("coor/x",-1220);
        set("coor/y",30);
        set("coor/z",-10);
        setup();
        replace_program(ROOM);
}    
