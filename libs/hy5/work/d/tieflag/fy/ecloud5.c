 inherit ROOM;
void create()
{
        set("short", "东门西");
        set("long", @LONG
再往东就是东城门了，东门外是通向山里的一条路。东门和其他的城门没有什
么不同，上面贴满了告示和通缉令。听说当年大盗祈潼就是在东门被人发现，报告
了官府后被抓住的。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"egate",
  "west" : __DIR__"ecloud4",
  "north" : __DIR__"hall",
])); 
        set("outdoors", "fengyun");
        set("coor/x",50);
        set("coor/y",0);
        set("coor/z",0);
        set("coor/x",50);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}      
