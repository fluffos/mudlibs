 inherit ROOM;
void create()
{
        set("short", "交河故城");
        set("long", @LONG
此城位于雅尔乃孜沟中，系古西域三十六国“车师前国”的
故城，该城建在自北向南高十多丈的黄土台地上，四周无城墙，
岸崖笔立如削 ，壁垒天然。
LONG
        );
        set("exits", ([ 
  "northwest" : __DIR__"sichou2",
  "eastdown" : __DIR__"tulufan",
]));
        set("objects", ([
        __DIR__"npc/bird" : 2,
                        ]) );
        //set("no_pk",1);
        
        
        set("outdoors", "xinjiang");
        set("coor/x",-1070);
        set("coor/y",2030);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}      
