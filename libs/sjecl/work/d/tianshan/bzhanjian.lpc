// Room: /d/tianshan/bzhanjian.c
// By Linux

inherit ROOM;
int do_drop(object me, object obj);
void create()
{
	set("short", "百丈涧");
	set("long", @LONG
眼前是一处山涧，深不可测。连接两侧峭壁的竟是几条铁链，铁链上的木
板早已不见。这边桥柱上钉这几枚暗器，四周积雪中插有数柄断刀断剑，更多
的是些奇门兵器，有几柄色泛悠蓝，定是涂有剧毒, 山涧下面是云雾弥漫的万
丈深崖，看来掉下去定无生路。
LONG);
	set("exits", ([
                "south" :__DIR__"shizhuyan",
        ]));       
	set("outdoors", "天山");
	setup();	
}

void init()
{
	add_action("do_zhan", ({"zhan", "ge", "qie"}));
	add_action("do_jump", ({"jump", "tiao", "yue"}));
	add_action("do_ren", ({"ren", "diu", "diuqi","drop"}));
}

int do_zhan(string arg)
{
	object me,weapon;
	me=this_player();
	if (me->is_busy() || me->is_fighting())	return notify_fail("你正忙着呢！\n");
	if( (!arg) || !((arg == "tielian") || (arg == "铁链") || (arg == "tieliang")))
		return notify_fail("你要砍什么？\n"); 
	if( !objectp(weapon = me->query_temp("weapon")) )
		return notify_fail("你得用件锋利的器具才能砍断铁链。\n");
	if (me->query_temp("天山砍铁链"))
		return notify_fail("铁链不是已经斩断了吗？\n");
	if( weapon->query("flag") != 4 )
		return notify_fail("你手上这件兵器无锋无刃，如何能砍断这根铁链？\n");
	message_vision("$N握紧手中"+weapon->name()+"，内力到处，已将扣在峭壁石洞中的半截铁链斩了下来，握在手中!\n", me);
	me->set_temp("天山砍铁链",1);
	me->add_busy(2);
	return 1;
}

int do_jump(string arg)
{
	object me=this_player();
	object *inv;
	int i;

	if (me->is_busy() || me->is_fighting())	return notify_fail("你正忙着呢！\n");
	if (!me->query_temp("天山砍铁链"))
		return notify_fail("什么？\n");
	if (arg == "down") { 
        	message_vision( "$N一个纵身，跳下了悬崖。\n",me);
		me->move(__DIR__"yadi");
		me->set_temp("last_damage_from", "跳下悬崖摔");
		me->unconcious();
		me->die();
		return 1;
	}
	if( (!arg) || !((arg == "duimian") || (arg == "对面")))
		return notify_fail("你要跳到哪里去，山下吗？\n");

	inv = filter_array(deep_inventory(me), (: userp :));
	if (sizeof(inv)) {
		message_vision("$N一纵身想跳到对面山崖上，不料一个失足......\n", me);
		me->unconcious();
		return 1;
	}

	if( (int)me->query_skill("dodge", 1) < 100 )
		return notify_fail("你觉得自己的轻功太差，跳过去岂不是送死！\n");
	
	message_vision("\n$N手握铁链，把心一横冲着对面悬崖跳了过去。人在半空，真气一浊，身形急速下坠,\n"+
			"突然$N手挥铁链向对面的半根垂下的铁链卷去，只见卷个正着。就由着这点借力，$N\n"+
			"在空中轻巧的一个盘旋，已经落在对面崖上。\n\n",me);

	inv = deep_inventory(me);
	i= random(sizeof(inv));
	if ((int)me->query_encumbrance() * 100 / (int)me->query_max_encumbrance() >= 80) {
		do_drop(me, inv[i]);
	}
	me->delete_temp("天山砍铁链");
	me->add_busy(2);
	me->move(__DIR__"xcmen");
	tell_room(environment(me), me->name() + "从对面的百丈涧荡了过来。\n",me);
	return 1;
}

int do_drop(object me, object obj)
{
	mixed no_drop;
	if( no_drop = obj->query("no_drop")) return 1;
	if( obj->is_character())
		return 1;
	else {
		message_vision( sprintf("但是$N由于用力过度，身上的一%s$n丢下了山涧，再也找不回来了。\n", obj->query("unit")),me, obj );
		destruct(obj);
	}
	return 1;
}

int do_ren(string arg)
{
	object me=this_player();

	if (!me->query_temp("天山砍铁链"))
		return notify_fail("什么？\n");

	if( (!arg) || !((arg == "tielian") || (arg == "铁链")))
		return notify_fail("你要扔什么，把你自己扔下去吗？\n");

	message_vision("$N把铁链扔在地上。\n",me);
	me->delete_temp("天山砍铁链");	
	return 1;
}

int valid_leave(object me,string dir)
{
	if ( me->query_temp("天山砍铁链") && dir == "south" )
	return notify_fail("你手上拿着铁链，怎么离开！\n");
	return ::valid_leave(me, dir);
}
