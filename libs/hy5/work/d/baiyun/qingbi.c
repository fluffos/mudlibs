 //Created by justdoit at May 2001
//All Rights Reserved ^_^
inherit ROOM;
void create()
{
        set("short", "青壁");
        set("long", @LONG
越过瀑布，竟然别有洞天，看上去只是个很狭窄的山缝，额头一不小心便会和
石壁相撞，四周生满了不知名的低矮草木，而一面爬满藤萝的石壁上，密密麻麻尽
是青绿的藤萝。
LONG
           );
        set("exits", 
           ([ 
       "north" : __DIR__"tengluoxi2",
       "south" : __DIR__"longqiu",
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
