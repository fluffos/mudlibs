//lu.c
#include <ansi.h>

inherit NPC;
inherit F_UNIQUE;
inherit F_MASTER;
int do_join(string arg);

void create()
{
	set_name("陆高轩", ({ "lu gaoxuan", "lu" ,"gaoxuan"}));
	set("title", "神龙教军师");
	set("nickname",HIC "神机妙算" NOR);
	set("long", "他天庭饱满,地阔方圆,容貌颇为英俊.\n然而满面愁容,恰似顷刻间便有杀身之祸一般.\n" );
	set("gender", "男性");
	set("age", 37);
	set("str", 35);
	set("dex", 20);
	set("max_qi",1500);
        set("qi",1500);
	set("max_jing",500);
        set("jing",500);
	set("combat_exp", 300000);
	set("score", 40000);
	set("shen_type", -1);
	set("attitude", "peaceful");

	set_skill("literate", 100);
	set_skill("force", 70);
	set_skill("unarmed", 70);
	set_skill("hand", 70);
	set_skill("staff", 70);
	set_skill("parry", 70);
	set_skill("dodge", 70);
	set_skill("hamagong", 70);
	set_skill("yixingbu", 70);
	set_skill("shenlong-quanfa", 70);
	set_skill("shenlong-xinfa", 70);
	set_skill("shedao-qigong", 70);
	set_skill("shexing-diaoshou", 70);
	set_skill("tianshan-zhang", 70);

	map_skill("dodge", "yixingbu");
	map_skill("force", "hamagong");
	map_skill("unarmed", "shexing-diaoshou");
	map_skill("parry", "shexing-diaoshou");
	map_skill("staff", "tianshan-zhang");

	set_temp("apply/attack", 60);
	set_temp("apply/defense", 60);
	set_temp("apply/armor", 30);
	set_temp("apply/damage", 60);
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
add_action("do_join","join");
}

int do_join(string arg)
{
   object ob ;
   ob = this_player () ;
   if( !arg || arg!="shenlongjiao" )
	return notify_fail("你要加入什么组织？\n"); 
   if(ob->query("shenlongjiao")) 
	{
	message_vision(HIC "陆高轩说道：你已经是神龙教弟子了。\n" NOR,this_player());
	return 1;
	}
   if ((int)ob->query("shen")>-1000)
        {
	message_vision(HIC "陆高轩对$N大怒道：还想入教?一看你就不是好人!\n" NOR,this_player());
	set_leader(this_player());
	remove_call_out("kill_ob");
	call_out("kill_ob", 1, this_player()); 
  	return 1;
	}
   if (ob->query("combat_exp")<20000)
        {
	message_vision(HIC "陆高轩对$N摇头道：你的实战经验太低。\n" NOR,this_player());
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
   message_vision(HIC "陆高轩对$N大怒道：还想入教?一看你就不是好人!\n" NOR,this_player());
	set_leader(this_player());
	remove_call_out("kill_ob");
	call_out("kill_ob", 1, this_player()); 
  	return 1;
	}
}

void attempt_apprentice(object ob)
{
    if ((int)ob->query_skill("literate",1) < 40 ) {
        command("say 你的学问太低了,还是努努力先提高一下吧!");
		return;
    }
    if ((int)ob->query("shen") > -0  ) {
        command("say 我神龙教与世隔绝，向来不与您这种白道人物打交道，您请回吧！");
		return;
	}
    command("say 很好，很好。");
    command("recruit " + ob->query("id"));
}
 
