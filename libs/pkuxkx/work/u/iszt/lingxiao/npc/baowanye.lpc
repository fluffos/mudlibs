// baowanye.c

#include "setdizi.h"

void create()
{
	setcreate(2);
	set_name("包万叶", ({ "bao wanye", "bao", "wanye" }) );
	set("gender", "男性" );
	set("age", 36);
	set("long", "这是一个黑黑瘦瘦的雪山弟子，一身白袍，在这里负责发放防具。\n");

	add("inquiry", ([
		"rumors" : "这凌霄城可以说几十年没发生过什么大事了，哪有什么消息呢？",
		"here" : "这里是凌霄城的防具库，雪山派弟子可以找我领(ling)一些必要的防具。",
		"防具" : "这里是凌霄城的防具库，雪山派弟子可以找我领(ling)一些必要的防具。",
		"万叶" : "你叫的这么亲切，干嘛呀？",
		"包拯" : "不错，包青天正是在下先祖。",
		"包青天" : "不错，包青天正是在下先祖。",
		"皮靴" : "哈哈，可别小看我们凌霄城的皮靴，跟普通的皮靴大有不同呢。",
	]) );
	setfamily(6);

	set("claw_count", 10);
	set("shoes_count", 10);
	set("gloves_count", 10);
	set("armor_count", 10);

	setup();
	setequip();
}

void init()
{
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting()
		&& ob->query("family/family_name") == "雪山派" )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_ling", "ling");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() )
		return;
	message_vision(CYN"包万叶看到$N进来，对$N点了点头。\n"NOR, ob);
}

int do_ling(string arg)
{
	object ob = this_object();
	object me = this_player();
	string msg;

	if(me->is_busy())
		return notify_fail("你正忙着呢。\n");

	if(me->query("family/family_name") != "雪山派")
		return notify_fail("不是雪山派弟子来捣什么乱！\n");

	if(arg!="claw" && arg!="shoes" && arg!="gloves" && arg!="armor")
	{
		msg = CYN"$n对$N笑道：「要领什么防具，直说无妨。」\n"NOR;
		msg += WHT"防具种类：\n";
		msg += "冰爪(claw)\t皮靴(shoes)\t皮手套(gloves)\t皮甲(armor)\n"NOR;
		message_vision(msg, me, ob);
		return 1;
	}

	if(me->query_temp("lingxiao/get"+arg))
		return notify_fail(CYN"包万叶道：「你不是领过这种防具了么？」\n"NOR);
	if(query(arg+"_count") <= 0)
		return notify_fail(CYN"包万叶道：「不巧，这种防具我这里已经没有了。」\n"NOR);
	me->set_temp("lingxiao/get"+arg, 1);
	add(arg+"_count", -1);

	ob = new(__DIR__"obj/" + arg);
	ob->move(me);
	me->start_busy(1);
	msg = YEL"$n交给$N一"+ob->query("unit")+ob->name()+YEL"。\n"NOR;
	msg += CYN"$n道：「拿去罢。还要领什么防具，直说无妨。」\n"NOR;

	message_vision(msg, me, this_object());

	return 1;
}