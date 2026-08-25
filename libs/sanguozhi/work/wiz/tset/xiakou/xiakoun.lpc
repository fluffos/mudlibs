//  xiakoun.c
//  夏口城北
//  created by tset 1/16/98
//  last updated by tset 1/19/98

#include <mudlib.h>

inherit OUTDOOR_ROOM;

void setup(){
        object ob;

        set_area("xiakou");
        set_light(20);
        set_brief("城北");
        set_long("
这里是夏口城北，城门有官兵把守。出北门即是江岸。东边有个小
客栈，供往来行人歇息。
\n\n");

  set_exits( ([
        "north" : __DIR__"jiangan",
        "south" : __DIR__"xiakouc",
        "east"  : __DIR__"xiakoukz",
                ]) );

//if(present("bing")) return;
        ob=new(__DIR__"npc/bing");
	ob->move(this_object());
}
