 // Room: /d/chuenyu/dustyroad.c
inherit ROOM; 
void create()
{
        set("short", "乡间小路");
        set("long", @LONG
这是一条从小镇通出来的黄土小路。南面小镇几乎看不到了。
往北是一望无际的平原。一座黑朦朦的山从云雾里忽隐忽现。
再走几步，就是一个三叉口。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"dustyroad0",
  "north" : __DIR__"dustyroad2",
]));
        set("outdoors", "chuenyu");
        set("objects", ([
                __DIR__"npc/flowerseller" : 1,
        ]) ); 
        set("coor/x",100);
        set("coor/y",110);
        set("coor/z",0);
        set("coor/x",100);
        set("coor/y",110);
        set("coor/z",0);
        setup();
}     
