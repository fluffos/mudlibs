// Modify By River 98/12
#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "荆棘林");
	set("long", @LONG
你信步而行，举步踏到的尽是矮树长草，这里没有路,每走一步，荆棘都
钩刺到小腿,划破你的身体。
LONG
	);
        set("outdoors", "大理");

	set("exits", ([
           "south" : __DIR__"xiaoxi",
           "north" : __DIR__"shanlu9",
           "east" : __DIR__"anbian1",
           "west" : __FILE__,
	]));

	setup();
}

void init()
{    
       object me = this_player();
       if (random(me->query("kar")) <15
        && me->query_con() < 30){
         me->add("qi", -50);
         me->add("jingli", -10);
         me->receive_wound("jing", 20);
         }
       else{    
         me->add("qi", -10);
         }                   
}
