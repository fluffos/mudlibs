// shisuo.c

inherit ITEM;

void create()
{
	set_name("石锁", ({ "shi suo", "suo" }) );

	set_weight(100);

	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "个");
		set("no_get",1);
		set("long", "这是一个强身健体用的石锁，\n你也可以举(ju)一下试试。\n");
	}
	setup();
}

void init()
{
	add_action("do_ju","ju");
}

int do_ju(string arg)
{
	object me = this_player();
	string who;
	int damage,skill;

	if(!arg || !id(arg))
		return notify_fail("你要举什么？\n");

	if(who = query_temp("do_ju"))
		return notify_fail(who+"正在举这个石锁，你等一下吧。\n");

	damage = (int)me->query("age")/2 + 3;
	if(me->query("qi") < damage)
		return notify_fail("你现在体力不支，还是先休息一下再说吧。\n");

	if(me->is_busy())
		return notify_fail("你现在正在忙。\n");



	me->start_busy(4);
	set_temp("do_ju",me->name());
	if( (skill = (int)me->query_skill("unarmed",1)) >80)
		message_vision("$N单膀一较力，轻松地将石锁举过头顶。\n",me);
	else
		message_vision("$N一咬牙将石锁慢慢举过头顶。\n",me);

	call_out("do_drop",3,me,damage,skill);
	return 1;
}

void do_drop(object me,int damage,int skill)
{
	int str = me->query("str");
	int improve;

	if(str > 30)
		str = 30;

	improve = str/2 + random(str/2);
	message_vision("$N将石锁放在了地上。\n",me);
	delete_temp("do_ju");
	me->receive_damage("qi",damage);

	if(skill < 40)
		me->improve_skill("unarmed",improve);
	if(me->query("combat_exp") < 120000)
		me->add("combat_exp",10+random(15));
	me->stop_busy();
}
