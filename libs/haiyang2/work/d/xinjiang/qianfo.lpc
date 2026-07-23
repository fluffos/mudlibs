 inherit ROOM;
void create()
{
        set("short", "柏孜克里克千佛洞");
        set("long", @LONG
始建于公元六世纪曲氏高昌国时期，一直是高昌地区的佛教重地。
壁画大部分残毁，残存部分内容以大立佛为主，有“西方净士变”、
“举哀图”、“地狱变”、“小忽雷”等。
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"huoyan",
]));
        set("objects", ([
        __DIR__"npc/youke" : 1,
        __DIR__"npc/ghost1" : 2,
                        ]) );
        //set("no_pk",1);
        
        
        set("outdoors", "xinjiang");
        set("coor/x",-1020);
        set("coor/y",2030);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}    
