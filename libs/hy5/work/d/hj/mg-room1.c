// mg-room1.c 迷宫房舍
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
        set("short", CYN "迷宫房舍" NOR);
        set("long", @LONG
这里是连绵不断的是一列房舍。每一间房中大都供有佛像。偶然在
壁上见到几个汉文，写的是「高昌国国王」，「文泰」，「大唐贞观十
三年」等等字样。你悄声悄气地走了进来。
LONG);
        set("no_sleep_room", 1);
        set("exits", ([
              "south" : __DIR__"tianjin",
              "north" : __DIR__"mg-room2", 
              "northwest" : __DIR__"mg-room3",    
              "northeast" : __DIR__"mg-room4",               
        ]));
        setup(); 
        set("tu_count", 2);
}

void init()
{
   object me;
   me = this_player();    
   if(random(10) > 7  && query("tu_count") >= 1){
      message_vision("突然一阵微风吹过，卷出一张图卷飘落在地。\n", me);
      new(__DIR__"obj/tu")->move(environment(me));
      add("tu_count", -1);
      }
}
int count = 1;
void reset()
{
    if (--count == 0) {count = 20; set("tu_count", 2); ::reset();}
}
int clean_up()
{
       return 0;

} 
