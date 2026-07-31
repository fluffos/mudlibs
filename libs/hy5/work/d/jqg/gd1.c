// Room: /u/dubei/u/gumu/jqg/gd1
// by dubei
 
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "绝情谷底");
	set("long", @LONG
只见空谷无人，四周花草茂盛。不远处有一寒潭，潭水清澈，潭边
削壁环列，宛似身处一口大井之底 。
LONG
	);
 
        set("outdoors", "xiangyang");
	setup();
 
}
void init()
{
        add_action("do_pa", "pa");
        add_action("do_jump", "jump");
}
int do_pa(string arg)
{
       object me = this_player();

       if( !arg || arg == "" || arg !=  "up") return 0;
       if ((int)me->query_encumbrance() * 100 / (int)me->query_max_encumbrance() >= 20) 
       return notify_fail("你身上负重太多，爬不上去。\n");
 
       if((int)me->query_skill("dodge",1) < 100 )  
       return notify_fail("以你目前的轻功修为，很难爬上去。\n"); 
        message_vision("$N扒住岩石，小心的爬了上去。\n", me);
       me->move(__DIR__"qb");
       tell_room(environment(me), me->name() + "从谷底爬了上来。\n", ({ me }));
       return 1;
       
}
int do_jump(string arg)
{
       object me;
       me = this_player(); 
       if (arg != "tan di" ) return 0;
       if ( !arg ) return 0;
       if (!living(me)) return 0;
       message_vision("$N纵身向寒潭跳了进去。\n", me);
       me->move(__DIR__"ht1");
       tell_room(environment(me), me->name() + "从岸上跳了进来。\n", ({ me }));
       return 1;
}