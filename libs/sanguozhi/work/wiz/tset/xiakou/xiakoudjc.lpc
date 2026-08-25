//  xiakoudjc.c
//  夏口点将场
//  created by tset 1/23/98
//  last updated by tset 2/1/98

#include <mudlib.h>
#include <ansi.h>

inherit OUTDOOR_ROOM;

void setup(){
        set_area("xiakou");
        set_light(20);
        set_brief("点将场");
        set_long("
点将场内空空旷旷，正中设了一个高高的点将台。点将台四周旗帜
鲜明，在风中竦竦作响。东边有一连串的箭垛，正南有好些草人，
北边有些将官在马上监督士兵训练。
\n\n");

  set_exits( ([
        "west" : __DIR__"bingying",
                ]) );

  add_item("qi", "sign", "旗帜", "旗",
                ([ "look" : "旗帜上大字写着「"+YEL+"苏"+NOR+"」。",
                   "get"  : "你拿得动吗？",
                ]) );

}

