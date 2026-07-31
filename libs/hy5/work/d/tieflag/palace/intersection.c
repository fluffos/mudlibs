 inherit ROOM;
void create()
{
        set("short", "岔路口");
        set("long", @LONG
路到这里再向前就分成两条。左面一条，满布著白色的晶石，甚是
平坦阅目，路旁种植两行花草，修剪整齐，香气袭人。往右的一条黑石
道路，却曲折地通向一坐阴森黝暗的丛林，道路崎岖坎坷，林中随风吹
出阵阵阴湿的臭气。
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"white",
  "south" : __DIR__"black",
  "west" : __DIR__"bridge",
]));
        set("outdoors", "palace"); 
        set("coor/x",160);
        set("coor/y",10);
        set("coor/z",20);
        set("coor/x",160);
        set("coor/y",10);
        set("coor/z",20);
        set("coor/x",160);
        set("coor/y",10);
        set("coor/z",20);
        set("coor/x",160);
        set("coor/y",10);
        set("coor/z",20);
        setup();
        replace_program(ROOM);
}  
