// mg-room1.c 迷宫房舍
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
        set("short", CYN "迷宫房舍" NOR);
        set("long", @LONG
这里是一间殿堂，四壁供的既有佛像，又有汉人。壁上写的又都是汉字，
只见大半宫室已然毁圯，堂中堆满了黄沙，连门户也有堵塞的，真奇怪之极。
你悄声悄气地走了进来。
LONG);
        set("no_sleep_room", 1);
        set("exits", ([
              "southeast" : __DIR__"mg-room4", 
              "southwest" : __DIR__"mg-room3",                      
        ]));     
        setup(); 
        set("tu_count", 2);
}

void init()
{
       object me, ob;
       me = this_player();    
       if(random(10) > 6  && query("tu_count") >= 1 ){
       	 ob=unew(__DIR__"obj/tu");
       	 if( !clonep(ob)) return;
         if( clonep(ob) && ob->violate_unique()){
           destruct(ob);
           return;
         } 
         message_vision("突然一阵微风吹过，卷出一张图卷飘落在地。\n", me);
         ob->move(environment(me));
         add("tu_count", -1);
      }
}

int count = 20;
void reset()
{
    if (--count == 0) {count = 20; set("tu_count", 2); ::reset();}
}

int clean_up()
{
       return 0;
} 
