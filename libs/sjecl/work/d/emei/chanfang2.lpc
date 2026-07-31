// Room: /d/emei/chanfang2.c

inherit ROOM;
#include <room.h>
#include <ansi.h>
//#include "jingzuo.h";
void create()
{
	set("short", "禅房");
	set("long", @LONG
这里是一间安静宽敞的禅房，乃是千佛庵中弟子打坐修行之所。地下整整
齐齐放着许多蒲团。几位年轻师太和俗家女弟子正肃容入定。
LONG
	);
	set("exits", ([ 
  "west" : __DIR__"qianfoandd",
]));
    set("jingzuo", 1);
    set("no_fight", 1);
create_door("west", "小门", "east", DOOR_CLOSED);
	setup();
}
