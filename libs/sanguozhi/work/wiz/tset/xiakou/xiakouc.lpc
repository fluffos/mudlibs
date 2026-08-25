//  xiakouc.c
//  夏口城中心 
//  created by tset 1/16/98
//  last updated by tset 1/19/98   

#include <mudlib.h>

inherit OUTDOOR_ROOM;

void setup(){
        object ob;
        set_area("xiakou");
        set_light(20);
        set_brief("城中心");
        set_long("
夏口虽是小城，却地势险峻，且颇有钱粮，乃江夏郡屯兵重地。城
中心士卒日夜巡逻，不见多少平民往来。
\n\n");

  set_exits( ([
        "north" : __DIR__"xiakoun",
        "south" : __DIR__"xiakous",
        "east"  : __DIR__"xiakoue",
        "west"  : __DIR__"xiakouw",
                ]) );
                
//        if(present("bing")) return;
        ob=new(__DIR__"npc/bing");
        ob->set_wander_area("xiakou");
        ob->set_movement_time(60);
	ob->move(this_object());
}
