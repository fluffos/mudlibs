// 花轿里面

inherit ROOM;
string look_sign();

void create()
{
	set("short", "花轿里");
	set("long", @LONG
这是花轿里面，空间狭小，只有一个座位，两边的窗户(window)都用红布
蒙着，你不掀开的话，很难看见窗外的景物，只能感觉到轿子正在被抬着，摇
摇晃晃地走着，感到累了，你也可以离开(leave)。
LONG
	);

	set("item_desc",([
		"window" : (: look_sign :),
        ]));
	
	setup();
}

void init()
{
	add_action("do_leave", "leave");
}

string look_sign()
{
        object env, me = this_player();
        object who;
	string arg;

	if ( !arg = me->query("marry/id"))
		return "你怎么混进来的啊？\n";

	if ( ! who = find_player(arg))
		return "嗯？？你丈夫人呢？\n";

	if ( me->is_busy())
		return "你正忙着呢！\n";

        if(!( env = find_object(base_name(environment(who)))) )
        env = load_object(base_name(environment(who)));

        if(!random(5))
        	tell_room(env, "你发现有一双眼睛在轿内往外偷偷张望。\n");
        return "/cmds/std/look"->look_room(me, env);
}

int do_leave()
{
	string arg;
	object who, me = this_player();
	
	if ( arg = me->query("marry/id")){ 
		if (! who = find_player(arg)) {
			tell_object(me,"你觉得累了，于是站起身来，离开了花轿。\n");
			me->move("/d/city/yuelaoting");
			return 1;
		}
		return notify_fail("你丈夫还在外面呢，让他来决定吧。\n");
	}
	tell_object(me,"你觉得累了，于是站起身来，撩起轿帘，走了出去。\n");
	me->move("/d/city/yuelaoting");
	return 1;
}
