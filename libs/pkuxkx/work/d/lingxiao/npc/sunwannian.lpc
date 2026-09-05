// sunwannian.c

#include "setdizi.h"

void create()
{
	setcreate(2);
	set_name("孙万年", ({ "sun wannian", "sun", "wannian" }) );
	set("gender", "男性" );
	set("age", 36);
	set("long", "这是一个黑黑瘦瘦的雪山弟子，一身白袍，在这里负责发放武器。\n");

	add("inquiry", ([
		"rumors" : "这凌霄城除了几十年前遇上过雪崩以外没发生过什么大事了，哪有什么消息呢？",
		"雪崩" : "雪山上难免会有雪崩，遇上雪崩那也是无可奈何。",
		"here" : "这里是凌霄城的武器库，雪山派弟子可以找我领(ling)一些必要的武器。",
		"武器" : "这里是凌霄城的武器库，雪山派弟子可以找我领(ling)一些必要的武器。",
		"长剑" : "师父嘱我多备一批长剑，雪山派弟子可以找我来领(ling)。",
		"暗器" : "师父显露过一手出神入化的暗器功夫，看的一众弟子羡煞。",
		"师父" : "我不收徒，你别叫我师父。",
		"乌龟" : "你才是乌龟！",
		"王八" : "千年的王八，万年的你！哼哼！",
		"鳖" : "你再敢这么叫我，看我不废了你的！",
		"冰镐" : "雪山之上离不了冰镐，呵呵，说起来在下投师白老爷子也是为了雪山的梦想。",
		"雪山" : "雪山在那里，山鹰便要去登。",
		"山鹰" : "呵呵，你怎么问起山鹰来了？山鹰是和车协齐名的北大品牌社团。",
		"车协" : "北京大学自行车协会(CAPU)成立于1995年，每年均组织暑期远征活动，创造我的巫师就是06暑期队员。",
		"CAPU" : "哈，这是我唯一会说的外语了：Cycling Association of Peking University",
		"暑期" : "2006年车协暑期从大连到乌苏里江，欢迎访问http://www.chexie.net/",
		"dingruogu" : "崇拜中……你连他都知道……",
	]) );
	setfamily(6);

	set("sword_count", 40);
	set("stone_count", 100);
	set("staff_count", 10);
	set("whip_count", 10);

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

void attempt_apprentice(object ob)
{
	setapp(ob);
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() )
		return;
	message_vision(CYN"孙万年看到$N进来，对$N上下打量了一番。\n"NOR, ob);
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

	if(arg!="sword" && arg!="stone" && arg!="staff" && arg!="whip")
	{
		msg = CYN"$n对$N怒道：「想领什么赶紧说，别磨蹭。」\n"NOR;
		msg += WHT"武器种类：\n";
		msg += "长剑(sword)\t飞蝗石(stone)\t冰镐(staff)\t皮鞭(whip)\n"NOR;
		message_vision(msg, me, ob);
		return 1;
	}

	if(me->query_temp("lingxiao/get"+arg) > 4 && arg != "stone")
		return notify_fail(CYN"孙万年道：「你领过的那么多都去哪了？」\n"NOR);
	if(query(arg+"_count") <= 0)
		return notify_fail(CYN"孙万年道：「不巧，这种武器我这里已经没有了。」\n"NOR);
	me->add_temp("lingxiao/get"+arg, 1);
	add(arg+"_count", -1);

	ob = new(__DIR__"obj/" + arg);
	ob->move(me);
	me->start_busy(1);
	msg = YEL"$n交给$N一"+ob->query("unit")+ob->name()+YEL"。\n"NOR;
	msg += CYN"$n道：「拿去罢。还想领什么赶紧说。」\n"NOR;

	message_vision(msg, me, this_object());

	return 1;
}