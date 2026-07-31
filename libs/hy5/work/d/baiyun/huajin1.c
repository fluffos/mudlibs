 //Created by justdoit at May 2001
//All Rights Reserved ^_^
inherit ROOM;
void create()
{
        set("short", "鲜花小径");
        set("long", @LONG
绿草如茵的山坡下，有条鲜花小径，种满着不知名的奇花异草，似乎不常有人
行走，时常有几只可爱的小白兔好奇地看着你，走出花径还是花径，穿过花丛还是
花丛，四面山峰滴翠，晴空一碧如洗，前面半顷荷塘上的九曲桥头，有个朱栏绿瓦
的水阁。
LONG
           );
        set("exits", 
           ([ 
       "north" : __DIR__"shuige",
       "southwest" : __DIR__"tengluoxi",
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
