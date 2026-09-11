//  eastgate.c
//  夏口东门
//  created by tset 1/23/98
//  last updated by tset 1/23/98

#include <mudlib.h>
#include <ansi.h>

inherit OUTDOOR_ROOM;

void setup(){
        set_area("xiakou");
        set_light(20);
	set_brief("东门");
        set_long("
城门上警卫深严，不时地有士兵在城墙上来回巡逻。一个牌子悬挂
在门墙上。好些士兵正在盘查进出百姓。出去就是江夏大路了。
\n\n");

  set_exits( ([
        "west" : __DIR__"xiakoue",
	"east" : __DIR__"jxroad/0/3",
                ]) );

  add_item("sign", "牌子", "牌",
                ([ "look" : "牌子上写着「"+YEL+"夏口"+NOR+"」。",
                ]) );

}
