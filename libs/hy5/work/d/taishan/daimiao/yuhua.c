 //mac's yuhua.c
#include <room.h>
inherit ROOM;
void create()
{
  set("short","雨花道院");
  set("long",@LONG
这是为道士休息，饮食，打坐的处所，俭朴清净，有几个石砌的
桌子，摆放着一些简单的食品，饮料，小屋中一口老井，明为雨花，
据说乃当年泰山封禅时皇帝御用过的井水，清澈而甘甜。
LONG
  );
  set("exits",([
         "east":__DIR__"peitian.c",
               ]));
        set("objects", ([
                __DIR__"npc/daoshi" : 1,
       ]) );
    set("resource/water", 1);
    set("liquid/container", "雨花井"); 
  set("coor/x",300);
        set("coor/y",2300);
        set("coor/z",0);
        setup();
  replace_program(ROOM);
}       
