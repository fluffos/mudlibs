// mg-room3.c 迷宫房舍
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
        set("short", CYN "迷宫房舍" NOR);
        set("long", @LONG
这里是一间殿堂，四壁供的既有佛像，又有汉人。壁上写的又都
是汉字，通道上还有几具白骨骷髅，真是奇怪之极。你悄声悄气地走
了进来。
LONG);
        set("no_sleep_room", 1);
        set("exits", ([
              "southeast" : __DIR__"mg-room1",
              "northeast" : __DIR__"mg-room5",                     
        ]));
        setup(); 
        set("stone_count", 2);
}
void init()
{
   object me;
   me = this_player();    
   if(random(10) > 6  && query("stone_count") >= 1){
      message_vision("突然你脚下一拌，好象踩到了什么硬东西。\n", me);
      new(__DIR__"obj/shiqi")->move(environment(me));
      add("stone_count", -1);
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