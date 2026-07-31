// Room: /d/xiangyang/huapu2.c  花圃
// Date: Jan. 28 2002 by Pound

inherit ROOM;

int do_jiao(string);

void create()
{
	set("short", "花圃");
	set("long", @LONG
顺着花圃间的小路向南走几步，只见在东南角有个粪池（fenchi），
隐隐飘来些粪便的味道。粪池里面的粪便用水稀释过，看来可以直接用于
浇花施肥。
LONG
	);
	set("exits", ([
	    "north" : __DIR__"huapu",
	]));
	set("item_desc", ([
	    "fenchi" : "粪池旁有个粪勺，可以用来装粪浇(jiao)花。\n",
	]));

	set("outdoors", "xiangyang");
	setup();
}

void init()
{
	add_action("do_jiao", "jiao");
}

int do_jiao(string arg)
{
	object me;
	me = this_player();

	if (me->is_busy() )
	{
	    return notify_fail("你现在正忙着呢。\n");
	}

// 稍微增加一点随机难度，容貌高者往往不适应这种劳动，昏倒的几率稍大。
	if (me->query_temp("yaowang/jiao") > 26 && me->query("per") > random(50))
	{
	    message_vision("$N在粪池里舀了几下，突然一阵极浓的臭气扑面而来，当即熏得$N昏了过去。\n", me);
	    me->set_temp("yaowang/jiao", 0);
	    me->unconcious();
	    return 1; 
	}

//      set_temp("die_reason", "舀粪浇花操劳过度，累倒在粪池里死了");
	me->receive_damage("qi", 30);
	me->add_temp("yaowang/jiao", 1);
	message_vision("$N从粪池里舀了一勺粪遍浇到了花上，一阵臭气熏得$N几欲作呕。\n", me);
	me->start_busy(2); 

	if (me->query("qi") < 100)
	    tell_object(me, "你已经累得腰酸腿疼，直不起腰了。\n");
	return 1;
}

