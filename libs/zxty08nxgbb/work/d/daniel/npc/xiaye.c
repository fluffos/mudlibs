#include <ansi.h>

inherit BHNPC;
string query_save_file() { return DATA_DIR + "npc/下野德康"; }

void create()
{
        set_name("下野德康",({"xiaye dekang","xiaye","dekang"}));
this_object()->init_bhnpc();
set("area_name","神户钱庄");
set("area_file","/d/japan/qianzhuang.c");
        set("gender","男性");
         set("title","神户钱庄");
        set("combat_exp",300000);
        set_skill("unarmed",50);
        set_skill("parry",50);
        set_skill("dodge",50);
        set_skill("sword",50);
	set("attitude", "friendly");

        set("inquiry", ([
            "利息":   "我们庄的规矩是提取两成保管费。\n",
            "lixi":   "我们庄的规矩是提取两成保管费。\n",
                       ]) );

	setup();
	
       carry_object("/clone/weapon/changjian")->wield();
       carry_object("/clone/cloth/cloth")->wear();

	add_money("gold", 1);
}

int accept_fight(object me)
{
	kill_ob(me);
	return 1;
}

void init()
{
	object ob;
	::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
	add_action("do_check", "check");
	add_action("do_check", "wen");
	add_action("do_convert", "convert");
	add_action("do_convert", "duihuan");
        add_action("do_convert", "huan");
	add_action("do_deposit", "deposit");
	add_action("do_deposit", "cun");
	add_action("do_withdraw", "withdraw");
	add_action("do_withdraw", "qu");
}

void greeting(object ob)
{
	string banghui;
	int money;
	object lp;
	if(! (banghui=ob->query("banghui")))	{
		command("nod");
		return;
	}
	lp=new("/obj/lingpai");
	lp->create(banghui);
	if(lp->query("no_use"))	{
		destruct(lp);
		message_vision("$N冲着$n道：“这位"+
		RANK_D->query_respect(ob)+"的帮会文件有问题，快点与巫师联系吧。”\n",this_object(),ob);
		return;
	}
	if(lp->query("bangzhu_id")=="???")	{
		destruct(lp);
              message_vision("$N提醒$n道：“帮主已失踪多日，快去找狂人尼采商量商量吧。\n",this_object(),ob);
		return;
	}
	if( lp->query("bangzhu_id")!=ob->query("id"))	{
		destruct(lp);
		message_vision("$N笑咪咪的对着$n道：“帮主何时来此处转帐啊？”\n",this_object(),ob);
		return;
	}
	if(! (int)(money=lp->query("money")))	{
		destruct(lp);
		message_vision("$N对$n陪笑道：“目前无帐可转。”\n",
		this_object(),ob);
		return;
	}
	lp->set("money",0);
	lp->save();
	destruct(lp);
	ob->add("balance",money);
	ob->save();
	message_vision("$N将"+banghui+"最近的收帐"+MONEY_D->money_str(money)+"转到了$n的帐下。\n",this_object(),ob);

}

void enough_rest()
{
	delete_temp("busy");
}

int do_check()
{
	// here we use 3 units to display bank infos
	int total = (int)this_player()->query("balance");
        
	
	if (!total || total < 0) {
		this_player()->set("balance", 0);
		return notify_fail("您在敝商号没有存钱。\n");
	}
	write("你核对了帐本，在庄里共存有" + 
		MONEY_D->money_str(total) + "\n");
	return 1;
}

int do_convert(string arg)
{
	string from, to;
	int amount, bv1, bv2;
	object from_ob, to_ob;
	object me;
	
	if (query_temp("busy"))
		return notify_fail("这就去拿帐本，请稍候。\n");

	me = this_player();

	if (!arg || sscanf(arg, "%d %s to %s", amount, from, to) != 3)
	{
		return notify_fail("命令格式：huan <数量> <货币> to <新货币单位>\n");
	}

	from_ob = present(from + "_money", me);
	to_ob = present(to + "_money", me);

	if (!to_ob && file_size("/obj/money/" + to + ".c") < 0)
	{
		return notify_fail("你想换成什么？\n");
	}
	if (!from_ob)
	{
		return notify_fail("你身上没有带这种钱。\n");
	}
	if (amount < 1)
	{
		return notify_fail("你想白赚啊？\n");
	}
	if ((int)from_ob->query_amount() < amount)
	{
		return notify_fail("你带的" + from_ob->query("name") + "不够。\n");
	}
	
	bv1 = from_ob->query("base_value");
	if (!bv1)
	{
		return notify_fail("这样东西不值钱。\n");
	}

	bv2 = to_ob ? to_ob->query("base_value") : call_other("/obj/money/" + to, 
"query", "base_value" );
	
	if (bv1 < bv2)
		amount -= amount % (bv2 / bv1);	

	if (amount == 0)
	{
		return notify_fail("这些" + from_ob->query("name") + "不够换。\n");
	}

	// allowed to convert now
	set_temp("busy", 1);	
	remove_call_out("enough_rest");
	call_out("enough_rest", 5);

//	from_ob->add_amount(-amount);

	if (!to_ob) {
		to_ob = new("/obj/money/" + to);
		to_ob->set_amount(amount * bv1 / bv2);
		if( !to_ob->move(me))
			return notify_fail("你身上装不下这么多钱。\n");
	}
	else
		to_ob->add_amount(amount * bv1 / bv2);
	
	message_vision(sprintf("$N从身上取出%s%s%s，换成了%s%s%s。\n",
	chinese_number(amount), from_ob->query("base_unit"), from_ob->query("name"),
	chinese_number(amount * bv1 / bv2), to_ob->query("base_unit"), 
	to_ob->query("name")), me);

	from_ob->add_amount(-amount);


	return 1;
}

int do_deposit(string arg)
{
	string what;
	int amount;
	object what_ob, me;

	if (query_temp("busy"))
		return notify_fail("您请坐，这就去取帐本。\n");

	me = this_player();

	if (!arg || sscanf(arg, "%d %s", amount, what) != 2)
	{
		return notify_fail("命令格式: cun <数量> <货币>\n");
	}

	what_ob = present(what + "_money", me);
	if (!what_ob)
	{
		return notify_fail("你身上没有带这种钱。\n");
	}
	if (amount < 1)
	{
		return notify_fail("你想存多少" + what_ob->query("name") + "？\n");
	}
	if ((int)what_ob->query_amount() < amount)
	{
		return notify_fail("你带的" + what_ob->query("name") + "不够。\n");
	}

	// deposit it
	set_temp("busy", 1);	

	message_vision(sprintf("$N拿出%s%s%s，存进了钱庄。\n", 
	chinese_number(amount), what_ob->query("base_unit"), 
	what_ob->query("name")), me);
	me->add("balance", what_ob->query("base_value") * amount);
	what_ob->add_amount(-amount);

	remove_call_out("enough_rest");
	call_out("enough_rest", 5);
	return 1;
}

int do_withdraw(string arg)
{
	int amount, v,lixi;
	string what,banghui;
	object me;

	if (query_temp("busy"))
		return notify_fail("您请稍候.....。\n");

	me = this_player();
	
	if (!arg || sscanf(arg, "%d %s", amount, what) != 2)
	{
		return notify_fail("命令格式：qu <数量> <货币单位>\n");
	}
	if (amount < 1)
	{
		return notify_fail("你想取出多少钱？\n");
	}
	if (file_size("/obj/money/" + what + ".c") < 0)
	{
		return notify_fail("你想取出什么钱？\n");
	}
	if (amount==1 && what=="coin")	{
		return notify_fail(query("name")+"怒道：都象你这样，岂不要俺吃西北风去？！\n");
	}
	what = "/obj/money/" + what;

//	if ((v = amount * what->query("base_value")) > me->query("balance"))
//	{
//		return notify_fail("你存的钱不够。\n");
//	}



      if ( amount  > 
              ( me->query("balance") / (what->query("base_value")) ) )
      {
              return notify_fail("你存的钱不够。\n");
      }

     v = (amount) * what->query("base_value");


	if((int)me->query_encumbrance() + 
		amount* what->query("base_weight")
		> me->query_max_encumbrance() )
		return notify_fail("你取得钱太沉了，装不下。\n");

	set_temp("busy",1);
	me->add("balance",  -v);
        
	banghui=(string)me->query("banghui");
	if(! banghui || banghui!=(string)query("banghui"))	{
        v=what->query("base_value") * amount * 8 /10 ;
	 lixi=what->query("base_value") * amount/10;
	 if(lixi>0)	"/cmds/adm/ctom.c"->save_money(this_object(),lixi);
	}
	else
	 v=what->query("base_value") * amount;


	MONEY_D->pay_player(me, v );
	
	message_vision(sprintf("$N从钱庄里取出%s。\n", MONEY_D->money_str(v)),
		me);

	remove_call_out("enough_rest");
	call_out("enough_rest", 5);
	return 1;
}
