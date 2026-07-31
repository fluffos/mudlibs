
#include <ansi.h>
#include <medical.h>
inherit NPC;
inherit F_DEALER;

string ask_huan();
int do_peiyao(string arg);
int working(object me);
int halt_working(object me);

void create()
{
	set_name("平一指", ({"ping yizhi"}));
	set("title", "药铺老板");
	set("gender", "男性");
	set("long", "他就是医术高超的「杀人神医」平一指。\n");
	set("age", 65);
	set("int", 38);
	set("qi", 1000);
	set("max_qi", 1000);
	set("jing", 1000);
	set("max_jing", 1000);
	set("shen_type", 1);
	set("combat_exp", 500000);
	set("attitude", "heroism");
	set("inquiry", (["冲脉丹互换":(
									  : ask_huan:),

	]));
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	add_action("do_duihuan", "duihuan");
}

string ask_huan()
{
	object me;
	string msg;

	me = this_player();

	msg = HIW "目前提供以下冲脉丹兑换方式：" ZJBR
			  "一一一一一一一一一一一一一一一一一一一一一一一" NOR "\n";
	msg += ZJOBACTS2 + ZJMENUF(3, 4, 9, 30);
	msg += sprintf(HIW "下品  " NOR "兑换" + ZJBR + HIG "中品" NOR "  2：1 :%s" ZJSEP, "duihuan 1");
	msg += sprintf(HIW "下品  " NOR "兑换" + ZJBR + HIR "上品" NOR "  3：1 :%s" ZJSEP, "duihuan 2");
	msg += sprintf(HIW "下品  " NOR "兑换" + ZJBR + HIY "极品" NOR "  6：1 :%s" ZJSEP, "duihuan 3");

	msg += sprintf(HIG "中品  " NOR "兑换" + ZJBR + HIW "下品" NOR "  1：2 :%s" ZJSEP, "duihuan 4");
	msg += sprintf(HIR "上品  " NOR "兑换" + ZJBR + HIW "下品" NOR "  1：3 :%s" ZJSEP, "duihuan 5");
	msg += sprintf(HIY "极品  " NOR "兑换" + ZJBR + HIW "下品" NOR "  1：6 :%s" ZJSEP, "duihuan 6");
	
	//msg += sprintf(HIY "极品  " NOR "兑换" + ZJBR + HIW "200灵石" NOR "  7：1 :%s" ZJSEP, "duihuan 7");
	//msg += sprintf(HIY "极品  " NOR "兑换" + ZJBR + HIW "200玉石" NOR "  5：1 :%s" ZJSEP, "duihuan 8");

	write(msg + "\n");
	return "好！你看看你想怎么兑换？";
}

int do_duihuan(string arg)
{
	object me, ob1, ob2;
	string da, db, dname;
	int amount, i;
	me = this_player();

	amount = 1;
	i = 1;
	switch (arg)
	{
	case "1":
		da = "chongmai dan";
		db = "/clone/shizhe/dan_chongmai2";
		amount = 2;
		/* code */
		break;
	case "2":
		da = "chongmai dan";
		db = "/clone/shizhe/dan_chongmai3";
		amount = 3;
		/* code */
		break;
	case "3":
		da = "chongmai dan";
		db = "/clone/shizhe/dan_chongmai4";
		amount = 6;
		/* code */
		break;
	case "4":
		da = "chongmai dan2";
		db = "/clone/shizhe/dan_chongmai1";
		i = 2;
		/* code */
		break;
	case "5":
		da = "chongmai dan3";
		db = "/clone/shizhe/dan_chongmai1";
		i = 3;
		/* code */
		break;
	case "6":
		da = "chongmai dan4";
		db = "/clone/shizhe/dan_chongmai1";
		i = 6;
		break;
	case "7":
		da = "chongmai dan4";
		db = "/clone/yuanbaopiao2";
		amount = 7;
		break;
     case "8":
		da = "chongmai dan4";
		db = "/clone/yushipiao2";
		amount = 5;
		break;		
		
		
	
		
	default:
		break;
	}

	if (!objectp(ob1 = present(da, me)))
		return notify_fail("你身上没有这种冲脉丹。\n");
	if (amount > ob1->query_amount())
		return notify_fail("你没有那么多的" + ob1->name() + "。\n");
	dname = ob1->name();

	ob1->set_amount((int)ob1->query_amount() - amount);

	ob2 = new (db);

	if (ob2->query_amount())
		ob2->set_amount(i);

	ob2->move(me);

	tell_object(me, "你用" + chinese_number(amount) + "颗" + dname + "兑换了" + chinese_number(i) + "颗" + ob2->name() + "\n");

	call_out("ask_huan", 0.5, me);

	return 1;
}
