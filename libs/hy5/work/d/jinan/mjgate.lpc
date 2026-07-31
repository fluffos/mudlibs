 // mjgate.c
#include <room.h>
inherit ROOM;
void create()
{
  set("short","麻将馆大院");
  set("long",@LONG
每个地方都有赌场，有的赌场在地上，有的赌场在地下，有的赌场公开，有的赌
场不能公开，有的赌场赌得很大，有的赌场赌得很小。但是你只要去赌，就随时都有
可能把自己的老婆都输掉。朝延官方为了打击滥赌，关闭了所有的麻将馆，这是一间
由朝延官方开的麻将馆，只是为了让大家娱乐。
LONG
  );
  set("exits",([
         "east":__DIR__"street4",
         "west":__DIR__"mjroom",
               ]));
    set("objects", ([
    __DIR__"npc/girl" : 1,
                    ]) );
    set("outdoors", "jinan");
    set("no_magic",1);
    set("NONPC",1);
//    set("throw_exit", "east");
        set("coor/x",20);
        set("coor/y",1910);
        set("coor/z",0);
        setup();
    replace_program(ROOM); 
}        
