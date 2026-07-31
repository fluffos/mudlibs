// Room: /d/fengtian/quest5.c

inherit ROOM;

void create()
{
	set("short", "土山洞");
	set("long", @LONG
这是一个黑漆漆的小土洞，洞壁上插着一只火把。迎面的土
墙上嵌着一块石板。地上放着一个长方形的石匣子。
LONG
	);

	setup();
}

void init()
{
	add_action("do_push","push");
	add_action("do_open","open");
}

int do_push(string arg)
{
	object me = this_player(),ob;

	if(arg != "石板")
		return notify_fail("你要推什么？\n");

	ob = find_object(__DIR__"quest4");
	if(!ob)
		ob = load_object(__DIR__"quest4");

	if(!ob || (me->query("force") < 200))
		return notify_fail("你用力推了一下，可是石板纹丝没动。\n");

	message_vision("$N推开石板，后面露出了一个出口。\n",me);

	tell_room(ob,"有人推开石板，露出了一个出口。\n");

	set("exits/south",__DIR__"quest4");
	ob->set("exits/north",__DIR__"quest5");

	call_out("do_close",8);
	return 1;
}

private void do_close()
{
	object ob;

	tell_room(__FILE__,"石板慢慢的移回了原位。\n");
	delete("exits/south");

	ob = find_object(__DIR__"quest4");
	if(!ob)
		ob = load_object(__DIR__"quest4");

	if(ob)
	{
		tell_room(ob,"石板慢慢的移回了原位。\n");
		ob->delete("exits/north");
	}
}

int do_open(string arg)
{
	object me = this_player(),ob,obs;

	if(arg != "石匣子" && arg != "石匣")
	{
		write("你要打开什么？\n");
		return 1;
	}

	obs = filter_array(children(__DIR__"obj/feiyusword"),(: clonep :));

	if(sizeof(obs))
	{
		write("你打开石匣子，发现里面什么也没有。\n");
		return 1;
	}

	ob = new(__DIR__"obj/feiyusword");
	ob->set("master",me->query("id"));
	ob->move(this_object());
	me->set_temp("feiyu_upgrade_quest/had",1);
	message_vision("$N猛地一下打开石匣子，一把短剑从里面掉了出来。\n",me);
	return 1;
}
