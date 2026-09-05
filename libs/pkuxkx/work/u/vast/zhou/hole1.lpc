// Room: /d/taohuadao/hole1.c
// Date: llx 27/10/97

inherit ROOM;
void create()
{
	set("short", "山洞");
	set("long", @LONG
这是一个黑乎乎的山洞，借着洞外的光线，可以看到
地上有一个小坑(keng)。靠着内壁的地方有一枝柳枝
(branch)，看上去有一点古怪，想伸手去看看有什么
现象。内壁上好象有一个用枯草掩着的木门(door)。
LONG
	);
	set("item_desc",([
		"keng" : "这是一个小坑，不知道踩上去会发生什么事情。\n",
		"branch" : "这是一枝柳条，看上去有点古怪，你不禁想伸手摸一下。\n",
		"door" : "一扇半掩的小木门，应该可以走进去吧。\n",
	]));
	set("exits",([
		"out" : __DIR__"shanbi",
	]));
	setup();

}
void init()
{
	add_action("do_touch","touch");
	add_action("do_step","step");
	add_action("do_touch","mo");
	add_action("do_step","cai");
	add_action("do_enter","enter");
	add_action("do_enter","open");
}
int do_touch(string arg)
{
	object me;
	me = this_player();
	if(!arg || arg != "branch")
	return notify_fail("你想摸什么？\n");
	else
	{
		if(me->query_temp("zyhb/枝"))
		return notify_fail("你还没被尿浇够啊？\n");
        	message_vision("突然从顶壁浇下一股液体，淋了$N一身，\n散发着一股臊味，原来是被浇了一身的尿。\n", me);
		me->set_temp("zyhb/枝",1);
		if(me->query_temp("zyhb/便") && me->query_temp("zyhb/枝"))
		{
			tell_object(me, "你听到一个声音：“哈哈，你中计了！”\n");
			return 1;
		}
	return 1;
	}
}
int do_step(string arg)
{
	object me;
	me = this_player();
	if(!arg || arg != "keng")
	return notify_fail("你想踩什么？\n");
	else
	{
		if(me->query_temp("zyhb/便"))
		return notify_fail("你难道还想踩一脚粪便？\n");
        	message_vision("$N一下子陷了下去，抬脚一看，还散发着一股臭味，\n仔细一瞧，原来沾上了一脚的粪便。\n", me);
		me->set_temp("zyhb/便",1);
		if(me->query_temp("zyhb/便") && me->query_temp("zyhb/枝"))
		{
			tell_object(me, "你听到一个声音：“哈哈，你中计了！”\n");
			return 1;
		}
		return 1;
	}
}
int do_enter(string arg)
{
	object me, room;
	object* inv;
	int i;
	string name;
	room = find_object(__DIR__"hole2");
	if(!room) room = load_object(__DIR__"hole2");
	me = this_player();
	inv = deep_inventory(me);
	name = me->query("name");
	if(!arg || arg!="door")
	return notify_fail("你想进到哪去呢？\n");

	if( !me->query_temp("zyhb/便") || !me->query_temp("zyhb/枝"))
	{
		tell_object(me, "还是先查看一下这个山洞的情况再进去吧。\n");
	return 1;
	}
	if(me->query_temp("zyhb/便")
	&& me->query_temp("zyhb/枝")
	&& me->query_temp("zyhb/zbt")
	&& me->query_temp("zyhb/bhcs"))
	{
        	for(i = sizeof(inv)-1; i>=0; i--)
        	if(inv[i]->is_character()) return notify_fail("你不能背着别的玩家进去！\n");

		message_vision("$N开门走进了里面的山洞。\n",me);
		me->move(__DIR__"hole2");
		tell_room(room, name + "从外面的山洞走了进来。\n", me);
		me->delete_temp("zyhb/枝");
		me->delete_temp("zyhb/便");
		return 1;
	}
	if((!me->query_temp("zyhb/zbt")
	|| !me->query_temp("zyhb/bhcs"))
	&& me->query_temp("zyhb/便")
	&& me->query_temp("zyhb/枝"))
	{
		tell_object(me, "你听到上面传来一个人的声音：“你这小子怎么会知道这些\n" +
		"情况呢？是不是我那个傻弟弟郭靖告诉你的？\n");
	return 1;
	}
}
