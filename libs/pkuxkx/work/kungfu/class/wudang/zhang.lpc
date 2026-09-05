#include <ansi.h>
// zhang.c 张三丰
#include <title.h>
inherit NPC;
inherit F_MASTER;

#include <no1master.h>

void consider();
void heal();

void create()
{
	set_name("张三丰", ({ "zhang sanfeng", "zhang" }));
	set("nickname", HIR "邋遢真人" NOR);
	set("long",
		"他就是武当派开山鼻祖、当今武林的泰山北斗张三丰真人。\n"
		"身穿一件污秽的灰色道袍，不修边幅。\n"
		"身材高大，年满百岁，满脸红光，须眉皆白。\n");
	set("title",RED "武当派" NOR + GRN "开山" NOR+ RED "祖师" NOR);
	set("gender", "男性");
	set("age", 100);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 50);
	set("int", 50);
	set("con", 50);
	set("dex", 40);

	set("per", 80);
	set("max_qi", 25000);
	set("max_jing", 13000);
	set("neili", 15000);
	set("max_neili", 15000);
	set("jiali", 300);
	set("combat_exp", 20000000);
	set("score", 500000);

	set("chat_chance", 100);
	set("chat_msg", ({
		(: heal :),
	}));
	set("chat_chance_combat", 70);
	set("chat_msg_combat", ({
		(: consider :),
	}) );

	set_skill("force", 450);
	set_skill("taiji-shengong", 400);
	set_skill("dodge", 400);
	set_skill("tiyunzong", 450);
	set_skill("cuff", 450);
	set_skill("taiji-quan", 400);
	set_skill("claw",450);
	set_skill("taiji-zhao",400);
	set_skill("parry", 450);
	set_skill("sword", 450);
	set_skill("taiji-jian", 400);
	set_skill("blade", 450);
	set_skill("xuanxu-dao", 400);
	set_skill("taoism", 400);
	set_skill("literate", 300);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("cuff", "taiji-quan");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");
	map_skill("claw","taiji-zhao");
	map_skill("blade","xuanxu-dao");
	prepare_skill("cuff", "taiji-quan");
	prepare_skill("claw","taiji-zhao");

  set("inquiry",([
     "沾衣十八跌": 
       "沾衣十八跌是真人钻研太极思想发展出来的一门防御技巧，非武当弟子无法使用，武当弟子\n"
       "对太极理解不深也无法领会这门高深武功，但凡武当弟子都可以向我请教(qingjiao)沾衣十\n"
       "八跌的高深技巧，对沾衣十八跌理解到一定程度可以在复真观自行研习。\n",
  ]));

    set_temp("apply/armor", 600);
    set_temp("apply/damage", 420);

	create_family("武当派", 1, "开山祖师");
	set("class", "taoist");

	setup();
	setup_no1master();
	carry_object("/clone/weapon/changjian");
}

void attempt_apprentice(object ob)
{
	if ((string)ob->query("family/family_name")!="武当派" || (string)ob->query("class")!="taoist")
	{
		command("say 我武当乃是道家门派。");
		command("say " + RANK_D->query_respect(ob) + "若想拜我派可先拜谷虚。"); 
		return;
	}
	if ((int)ob->query_skill("taiji-shengong", 1) < 50)
	{
		command("say 我武当派乃内家武功，最重视内功心法。");
		command("say " + RANK_D->query_respect(ob) +
			"是否还应该在太极神功上多下点功夫？");
		return;
	}
	if ((int)ob->query("shen") < 50000)
	{
		command("say 学武之人，德义为先，功夫的高低倒还在其次，未练武，先学做人。");
		command("say 在德行方面，" + RANK_D->query_respect(ob) +
			"是否还做得不够？");
		return;
	}
	if (ob->query_int() < 30)
	{
		command("say 我武当派武功全从道藏悟出。");
		command("say 要能达到炉火纯青之境，体质什么的倒是无关紧要，悟性却是半点也马虎不得。");
		command("say " + RANK_D->query_respect(ob) + "的悟性还大有潜力可挖，还是请回吧。");
		return;
	}
  if ( ob->query("newbiehongdou")&&ob->query("jobs/completed/newbie")<50 ) {
  	command("say "+RANK_D->query_respect(ob)+"仍旧眷恋红尘，罚你去冲虚道长哪里干苦力3个月以后再回来吧。");
   	return;
  }
  
	CHANNEL_D->do_channel(this_object(), "jh", "哈哈哈哈！！！！");
	CHANNEL_D->do_channel(this_object(), "jh", "想不到老道在垂暮之年，又觅得一个可塑之才，真是可喜可贺。");
	command("recruit " + ob->query("id"));
	if ((string)ob->query("gender")!="女性")
		ob->set("title" ,RED "武当派" NOR + GRN "真人" NOR);
	else
		ob->set("title" ,RED "武当派" NOR + GRN "女真人" NOR);
//title系统记录玩家title by seagate@pkuxkx
	ob->set_title(TITLE_RANK, ob->query("title"));
}
void consider()
{
	object *enemy,target;
	enemy = query_enemy() - ({ 0 });
	target = enemy[random(sizeof(enemy))];
	switch( random(2) )
	{
	case 0:
		command("wield changjian");
		command("wield sword");
		command("perform sword.chan " + target->query("id"));
		break;
	case 1:
		command("unwield changjian");
		command("perform cuff.zhen " +target->query("id"));
		command("wield changjian");
		break;
	}
}
void init()
{
	object ob;
	mapping fam;

	::init();

	ob = this_player();
	if ( (int)ob->query("shen") <5000 && (string)ob->query("family/master_id") == "zhang sanfeng")
	{
		command("say 你多次杀人越货，胡作非为，我岂能仍是你的师傅。\n");
		command("expell "+ ob->query("id"));
	}
  add_action("do_qingjiao","qingjiao");
}		

int do_qingjiao()
{  
  object me=this_player();
  mapping fam;
  int skill = me->query_skill("zhanyi-18die",1);
  int point,pflv;
  
  pflv = (int)me->query("purefamily/level");
  if (pflv>0 && me->query("purefamily/family_name") != "武当派") 
    pflv=0;

  if ( skill>me->query_skill_limit() )
    return notify_fail("你受到自身经验和悟性的影响，无法继续请教沾衣十八跌了。\n");
  
  if (!(fam=me->query("family")) || fam["family_name"]!="武当派")
    return notify_fail("你又不是牛鼻子老道，在这里凑什么热闹！\n");

  if( me->query_skill("taiji-shengong",1)<500 ||
      me->query_skill("taiji-quan",1)<500 )
    return notify_fail("你对太极的理解不足，尚不足以学习沾衣十八跌！\n");

  if( (pflv<4 && skill>=500) || (skill>=600) )
    return notify_fail("对于沾衣十八跌，已经教不了你什么了！\n");

  if((int)me->query("jing")<(int)me->query("max_jing"))
    return notify_fail("你心神无法专一，怎能参悟道学至理？\n");
  
  if((int)me->query("qi")<(int)me->query("max_qi"))
    return notify_fail("你气血亏缺，无法静下心来参悟道学至理！\n");

  if (me->is_busy())
    return notify_fail("你现在无法静下心来钻研太极！\n");

  if ( me->query("score") < 1000 )
    return notify_fail("你对师门贡献不足，无法继续学习沾衣十八跌。\n");

  if( (int)me->query("learned_points") >= (int)me->query("potential") )
    return notify_fail("你的潜能已经发挥到极限了，没有办法再成长了。\n");

  point = skill+skill*me->query("int")/300+me->query("int")*3;
  if (pflv)
	  point += point*pflv/20;
  me->improve_skill("zhanyi-18die", point);
  me->add("score", random(4)*(-1)/3);
  me->add("learned_points", 1);
  me->start_busy(1);
  tell_object(me,"张三丰向你教授了一些太极思想，你对沾衣十八跌有所领悟。\n");

  return 1;
}

void heal()
{
	object ob=this_object();
	
	if (ob->query("eff_qi") < ob->query("max_qi"))
	{
		command("exert heal");
		command("enforce 100");
		return;
	}

	if (ob->query("qi") < ob->query("eff_qi"))
	{
		command("exert recover");
		return;
	}

	if (ob->query("jing") < ob->query("eff_jing"))
		command("exert regenerate");

	return;
}

                                
#include "/kungfu/class/masterdie.h"