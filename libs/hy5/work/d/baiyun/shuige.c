 //Created by justdoit at May 2001
//All Rights Reserved ^_^
inherit ROOM;
void create()
{
        set("short", "水阁");
        set("long", @LONG
水阁实际并不宽敞，但看上去却很空旷，虽然一阁里有十许人，或站或坐，或
老或幼，有的穿着庄严华丽的上古衣冠，有的却只不过随随便便披着件宽袍，大家
的态度都很轻松，神情分外愉快，红尘中的所有烦恼，似乎都被隔在水阁之外。
LONG
           );
        set("exits", 
           ([ 
       "northwest" : __DIR__"9bridge",
       "south" : __DIR__"huajin1",
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
