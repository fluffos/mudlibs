 //Created by justdoit at May 2001
//All Rights Reserved ^_^
inherit ROOM;
void create()
{
        set("short", "青山谷");
        set("long", @LONG
岛中有山，山中有谷，四面的山却也不高，游目四顾，只见繁花青草，便如同
一个极大的花园，花影摇曳，幽谷无人，树木似乎四季常春，青翠欲滴，鲜花竞相
绽放，有如仙境，但前前后后望去似乎竟是青翠，一时间，出谷的路竟消失在雾中。
山谷中除了偶尔鸟虫的啁啾低鸣外，便只有若有若无的流水之声传来。
LONG
           );
        set("exits", 
           ([ 
       "northeast" : __DIR__"longqiu",
       "south" : __DIR__"xiaowu",
        ]));
    set("objects", 
       ([ 
//           __DIR__"obj/sand" : 1, 
        ]));
        set("outdoors", "baiyun");
        set("coor/x",10);
    set("coor/y",-1680);
    set("coor/z",0);
    setup();
    replace_program(ROOM);
}   
