//COPY 自 XYJ 雪山冰刀，
//LUCAS :)
//Modified by iszt@pkuxkx, 2007-02-17

#include <ansi.h> 
#include <weapon.h> 

inherit SWORD;

int do_make(string);

void create()
{
	set_name(HIW "冰柱" NOR, ({ "bing zhu", "bing", "zhu", "ice", }) );
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "条");
		set("long", "这是一条长长的冰柱，看起来晶莹剔透，锋锐无比。不知道能不能吃，或者做成刀剑等武器。\n");
		set("value", 8);
		set("wield_msg", "$N「唰」的一声抽出一条$n握在手中。\n");
		set("unwield_msg", "$N小心将手中的$n放回怀中。\n");
		set("material", "ice");
	}
	init_sword(25);
	setup();
	call_out("melt", 40+random(40));
}

void melt()
{
	object env;
	object ob = this_object();

	if(!ob)
		return;

	env = environment(ob);

	if (!env) 
		return;
	if( env->is_character() )
	{//a player or a NPC.
		if( (int)env->query_skill("force") < 100 )
		{
			message_vision("$N觉得身上凉凉的，湿湿的，原来是$n化了。\n", env, ob);
			destruct(ob);
			return;
		}
	}
	else if( (int)env->query_max_encumbrance() > 0 && !environment(env) )
	{//a room.
		if( (string)env->query("outdoors") != "凌霄城" )
		{
			tell_object(env, ob->name()+"终于化成了一滩水，流得到处都是。\n");
			destruct(ob);
			return;
		}
	}
	call_out("melt", 40+random(40));
}

void init()
{
	add_action("do_make", "make");
	add_action("do_make", "zuo");
	add_action("do_eat", "chi");
	add_action("do_eat", "eat");
}

int do_make(string arg)
{
	object ob, me;

	me = this_player();

	if( (int)me->query("neili") < 200 || (int)me->query_skill("force") < 100 )
	{
		message_vision("$N拿起冰柱捏来捏去，结果由于内功不够精纯，冰柱很快就化掉了。\n", me);
		destruct(this_object());
		return 1;
	}

	if(arg == "sword" || arg == "jian")
	{
		ob=new(__DIR__"icesword");
		ob->move(me);
		me->add("neili", -100);
		message_vision(HIW"$N拿起冰柱，内劲到处，只见冰柱透出一股清气，化成了一把冰剑！\n"NOR, me);
		destruct(this_object());
		return 1;
	}
	if(arg == "blade" || arg == "dao")
	{
		ob=new(__DIR__"iceblade");
		ob->move(me);
		me->add("neili", -100);
		message_vision(HIW"$N拿起冰柱，内劲到处，只见冰柱透出一股清气，化成了一把冰刀！\n"NOR, me);
		destruct(this_object());
		return 1;
	}

	return notify_fail("你要做什么？\n");
}

int do_eat(string arg)
{
	if( !this_object()->id(arg) )
		return 0;
	if( this_player()->is_busy() )
		return notify_fail("你上一个动作还没有完成。\n");

	message_vision( "$N拿起冰柱使劲一咬，只听嘎哒！一声，牙崩了。\n" , this_player());
	if( (int)this_player()->query("qi") > 20 )
                this_player()->receive_wound("qi", 20);
	else
		this_player()->unconcious();

	return 1;
}
