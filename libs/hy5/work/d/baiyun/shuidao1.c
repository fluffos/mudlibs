 //Created by justdoit at May 2001
//All Rights Reserved ^_^
inherit ROOM;
void create()
{
        set("short", "水道");
        set("long", @LONG
进得洞中，但见是一条长长的地下水道，四面都是水，无论往哪里游，都会立
刻就撞上石壁，连换气的地方都没有，你只感觉到气息不继，浑身似乎要炸开来般
痛苦异常。
LONG
           );
        set("exits", 
           ([ 
       "up" : __DIR__"anliu1",
       "down" : __DIR__"shuidao2",
        ]));
    set("objects", 
       ([ 
//           __DIR__"obj/sand" : 1, 
        ]));
        set("indoors", "baiyun");
        set("coor/x",10);
    set("coor/y",-1680);
    set("coor/z",0);
    setup();
    replace_program(ROOM);
}    
