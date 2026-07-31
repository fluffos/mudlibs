// shanya.c
// bbb 1997/06/11
// Modify By River 98/12
#include <ansi.h>
int get_object(object ob);
inherit ROOM;

string look_down();
void create()
{
	set("short", "白龙峰");
	set("long", @LONG
走出十余里，你来到无量山主峰的后山，已来到无量剑派禁地，任何外人
不得擅入。这里丛林密布，山石怪异。旁边就是一深不见底的悬崖(cliff)。
LONG
	);
	set("exits", ([
		"northwest" : __DIR__"pubu",
	]));
        set("outdoors", "大理");
        set("objects", ([
            __DIR__"obj/yeguo" : 2,
        ]));

	set("item_desc",([
	   "cliff" : (: look_down :),
	   "down" : "下面白茫茫的什么也看不见。\n"
	]));
	setup();
}

void init()
{
	add_action("do_jump", "tiao");
        add_action("do_jump", "jump");
}

int get_object(object ob)
{
        if(userp(ob))
        return 1;
        return 0;
}

int do_jump(string arg,object *obj)
{
	object me= this_player();
        object *inv = deep_inventory(me);
        if (!arg || arg !="down") return 0;
        if(sizeof(obj)){
         message_vision(HIR "$N脚下踩一个空，「啊～～～」发出一声惨叫，向下直坠下去。\n"NOR, me);
         me->receive_wound("qi", 20);
         me->unconcious();
         me->move(__DIR__"xiaoxi");
         return 1;
         }
 if ( me->query("dali/meet_dy1") || (random((int)me->query("kar")) >10)){
	 message_vision(HIR "$N脚下踩一个空，「啊～～～」发出一声惨叫，向下直坠下去。\n" 
         "$N坠下百余丈，撞到崖边一棵古松上，弹了几弹，下坠的巨力却也消了。\n" NOR, me);
         me->move(__DIR__"bankong");
	 return 1;
         }
         message_vision(HIR "$N脚下踩一个空，「啊～～～」发出一声惨叫，向下直坠下去。\n"NOR, me);          
         me->receive_wound("qi", 20);
         me->unconcious();
         me->move(__DIR__"xiaoxi");
         return 1;
}

string look_down()
{
	return  "下面(down)深不可测，根本看不到底，如果你要自杀，这到是个好地方。\n";
}
