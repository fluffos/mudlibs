#include <room.h>
inherit ROOM;
void create()
{
  set("short","方舟");
  set("long",@LONG
黑纱中光线灰黯，香烟氤氲，一位夫人盘膝坐在蒲团之上。蒲团边有一香炉。烟
云从香炉上冉冉升起，充满了整个房间。 
LONG
  );
        set("exits/out" ,__DIR__"outboat");
    set("objects",([
        __DIR__"npc/jiayi" : 1,
        __DIR__"obj/coffin": 1,
    ]) ); 
    set("coor/x",100);
        set("coor/y",40);
        set("coor/z",-30);
        setup();
        replace_program(ROOM);
 }     
