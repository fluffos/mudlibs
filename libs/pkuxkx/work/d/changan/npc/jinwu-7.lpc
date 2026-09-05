// bing.c 官兵
#include <ansi.h>
inherit NPC;

int ask_ling();

void create()
{
	set_name("左金吾卫大将军", ({ "jin wu", "jiangjun" }));
	set("age", 22);
	set("gender", "男性");
	set("long", "这是金吾卫的最高长官，掌管着整个金吾卫和下辖几十个折冲府的大小事务。\n");
	set("attitude", "peaceful");
	set("changan_bing",1);

	set("str", 45);
	set("dex", 30);
	set("combat_exp", 50000000);
  set("shen_type",1);
 	set("max_qi", 500000);
 	set("max_jing", 500000);
 	set("neili", 50000);
 	set("max_neili", 50000);
 	set("jiali", 250);

	set_skill("unarmed", 800);
	set_skill("hand",800);
	set_skill("dodge", 800);
	set_skill("parry", 800);
	set_skill("blade", 800);
	set_skill("force", 800);
	set_skill("halberd",800);
	set_skill("bixue-xinfa", 800);
	set_skill("kuangfeng-dao", 800);
	set_skill("longfeng-xiang", 800);
	set_skill("huzhua-shou", 800);
	set_skill("lujia-ji", 800);
	map_skill("force", "bixue-xinfa");
	map_skill("dodge", "longfeng-xiang");
	map_skill("parry", "huzhua-shou");
	map_skill("hand", "huzhua-shou");
	map_skill("blade", "kuangfeng-dao");
	map_skill("halberd", "lujia-ji");
	
	prepare_skill("hand", "huzhua-shou");
	set_temp("apply/attack", 200);
	set_temp("apply/defense", 350);
	set_temp("apply/damage", 200);
	set_temp("apply/armor", 400);

  set("inquiry", ([
    "通行令" : (: ask_ling :)  
  ]) );

	setup();
	carry_object(__DIR__"obj/modao")->wield();
	carry_object(__DIR__"obj/mingguang-jia")->wear();
}

void init()
{
	object ob;
	::init();
	if (interactive(ob = this_player()) && 
		(int)ob->query_condition("cakiller")) {
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob);
	}
}

void kill_ob(object me)
{
	object *inv,ob=this_object(),qb;
	int lp,jw;
	
	command("say 大胆毛贼，这里也是你们敢闯得？剁了喂狗！\n");
	me->apply_condition("cakiller", 300);

	inv=all_inventory(environment(ob));
	jw=0;
	for(lp=0;lp<sizeof(inv);lp++)
	{
		if ( inv[lp]->query("id")=="jin wu" && inv[lp]!=ob && living(inv[lp]) )
		{
			message_vision("$N冲过来护卫住大将军，朝$n冲杀过来。\n", inv[lp], me);
			inv[lp]->kill_ob(me);
			jw++;
		}
	}
	
	if ( jw<16 )
	{
		qb=new(__DIR__"jinwu-6");
		qb->move(environment(ob));
		message_vision("$N冲过来护卫住大将军，朝$n冲杀过来。\n", qb, me);
		qb->kill_ob(me);
	}
	
	call_out("kill_target", 5, me);
	::kill_ob(me);
}

void kill_target(object me)
{
	object *inv, ob=this_object(),qb;
	int lp, jw;
	
	if ( !objectp(me) )
		return;
	
	if ( !is_fighting(me) )
		return;
	
	inv=all_inventory(environment(ob));
	jw=0;
	for(lp=0;lp<sizeof(inv);lp++)
	{
		if ( inv[lp]->query("id")=="jin wu" && inv[lp]!=ob && living(inv[lp]) )
		{
			if ( !inv[lp]->is_fighting(me) )
				inv[lp]->kill_ob(me);
			jw++;
		}
	}
	
	if ( jw<16 )
	{
		qb=new(__DIR__"jinwu-6");
		qb->move(environment(ob));
		message_vision("$N冲过来护卫住大将军，朝$n冲杀过来。\n", qb, me);
		qb->kill_ob(me);
	}
	
	switch(random(5))
	{
		case 0:
			message_vision(HIC"$N大喊道：弓弩手准备！只见“嗖”得一声几只利箭射中$n。\n"NOR, ob, me);
			me->receive_damage("qi", 1500+random(500), ob);
			me->receive_wound("qi", 1500+random(500), ob);
			me->start_busy(1+random(2));
			break;
		case 1:
			message_vision(HIM"$N大喊道：机关准备！只见亲兵抛出一张网网住了$n。\n"NOR, ob, me);
			me->start_busy(5+random(3));
			break;
		default:
			message_vision(HIY"$N吸了一口真气，伤势恢复了不少。\n"NOR,ob);
			if ( query("qi")<query("max_qi") )
				add("qi", query("max_qi")/25 );
			
			if ( query("eff_qi")<query("max_qi") )
				add("eff_qi", query("max_qi")/25 );
			
			add("neili", 1000 );
			break;
	}
	call_out("kill_target", 5+random(3), me);
}

int ask_ling()
{
	object me=this_player(),ob;
	
	if ( me->query("repute")<500000 &&
	     me->query("changan/points")+me->query("changan/level")*100<100 )
	{ 
		tell_object(me, "你的声望不够不能申请皇宫通行令。\n");
		return 1;
	}
	
	if ( me->query("balance")<20000 )
	{ 
		tell_object(me, "申请皇宫通行令至少要花费2两黄金。\n");
		return 1;
	}
	
	message_vision("$n缴纳了二两黄金后，$N递给$n一面"+HIM+"皇宫通行令"+NOR+"，凭令可以在一天内在太极宫内通行无阻。\n",this_object(), me);
	me->add("balance",-20000);
	ob=new(__DIR__"obj/ling-2");
	ob->move(me);
	return 1;
}

void unconcious()
{
	if ( query("qi")<0 ||
		   query("jing")<0 )
	  ::unconcious();
}