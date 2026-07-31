// zhang.c
#include <ansi.h>

inherit NPC;
inherit F_UNIQUE;
inherit F_MASTER;
int do_join(string arg);

void create()
{
	set_name("张淡月", ({ "zhang danyue", "zhang"}));
	set("title", "神龙教黑龙使");
	set("long", "这是一个黑衣大汉,脸色大变,身子发颤,似乎恐惧已极.\n" );
	set("gender", "男性");
	set("age", 44);
	set("str", 35);
	set("dex", 20);
	set("max_qi",3000);
        set("qi",3000);
	set("max_jing",1000);
        set("jing",1000);
	set("combat_exp", 500000);
	set("score", 40000);
	set("shen_type", -1);
	set("attitude", "peaceful");

	set_skill("force", 90);
	set_skill("huntian-qigong", 85);
	set_skill("dodge", 90);
	set_skill("xiaoyaoyou", 85);
	set_skill("unarmed", 85);
	set_skill("xianglong-zhang", 85);
	set_skill("shedao-qigong", 90);
	set_skill("shenlong-xinfa", 90);
	set_skill("parry", 70);
	set_skill("staff", 90);
	set_skill("literate", 70);

	map_skill("force", "shenlong-xinfa");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("parry", "xianglong-zhang");

	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	set_temp("apply/armor", 20);
	set_temp("apply/damage", 30);
	set("neili", 1000); 
	set("max_neili", 1000);
	set("jiali", 100);
        set("inquiry", ([
		"神龙教" :  "一般人是入不了我神龙教的(join shenlongjiao).\n",
		"入教" :  "一般人是入不了我神龙教的(join shenlongjiao).\n",
		"洪安通" :  "教主脾气不好,要讨他欢心才好。\n",
		"教主" :  "教主脾气不好,要讨他欢心才好。\n",
		"口号" : "万年不老!永享仙福!寿与天齐!文武仁圣!\n",
       ]) );
	setup();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 10);
}

void init()
{
	object ob;

	::init();
add_action("do_join","join");
	if( interactive(ob = this_player()) && !is_fighting() ) {

		remove_call_out("greeting");
		call_out("greeting", 50, ob);
	}
}

int do_join(string arg)
{
   object ob ;
   ob = this_player () ;
   if( !arg || arg!="shenlongjiao" )
	return notify_fail("你要加入什么组织？\n"); 
   if(ob->query("shenlongjiao")) 
	{
	message_vision(HIC "张淡月说道：你已经是神龙教弟子了。\n" NOR,this_player());
	return 1;
	}
   if ((int)ob->query("shen")>-1000)
        {
	message_vision(HIC "张淡月对$N大怒道：还想入教?一看你就不是好人!\n" NOR,this_player());
	set_leader(this_player());
	remove_call_out("kill_ob");
	call_out("kill_ob", 1, this_player()); 
  	return 1;
	}
   if (ob->query("combat_exp")<20000)
        {
	message_vision(HIC "张淡月对$N摇头道：你的实战经验太低。\n" NOR,this_player());
  	return 1;
  	}
  if ( ob->query_skill("bibo-shengong",1)
	|| ob->query_skill("hamagong",1)
	|| ob->query_skill("huagong-dafa",1))
   {
    ob->set("shenlongjiao",1);
    command("tell "+this_player()->query("id")+" 你现在就是神龙教弟子了.\n");
    return 1;	
   }
   else 
   {
   message_vision(HIC "张淡月对$N大怒道：还想入教?一看你就不是好人!\n" NOR,this_player());
	set_leader(this_player());
	remove_call_out("kill_ob");
	call_out("kill_ob", 1, this_player()); 
  	return 1;
	}
}


void greeting(object ob)
{
	object obj;
        if (interactive(ob))
        {
	if (obj = present("usedgao", ob))          
	   set("combat_exp",100000);
	   set("qi",100);
	   set("jing",100);
	}
	return;
}

void attempt_apprentice(object ob)
{
    if ((int)ob->query_skill("shenlong-xinfa",1) < 40 ) {
        command("say 你的本门内功心法太低了,还是努努力先提高一下吧!");
		return;
    }
    if ((int)ob->query_skill("shedao-qigong",1) < 40 ) {
        command("say 你的本门杖法太低了,还是努努力先提高一下吧!");
		return;
    }
    if ((int)ob->query("shen") > -5000  ) {
        command("say 我神龙教与世隔绝，向来不与您这种白道人物打交道，您请回吧！");
		return;
	}
    command("say 很好，很好。");
    command("recruit " + ob->query("id"));
}
 
