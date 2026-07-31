// wujiang.c 武将
#include <ansi.h>
inherit NPC;


void create()
{
	set_name("皇太极", ({ "huang taiji", "huang", "taiji" }));
	set("gender", "男性");
	set("age", random(10) + 30);
	set("str", 25);
	set("dex", 16);
	set("long", "金国皇帝，他站在那里，的确有说不出的威风。\n");
  set("title", HIY"金国皇帝"NOR);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set("combat_exp", 2810000);
	set("shen_type", 1);

   set("qi",84000);
        set("max_qi", 84000);
        set("jing", 82000);
        set("max_jing", 82000);
        set("neili", 82000);
        set("max_neili", 82000);
        set("jiali", 150);
        set("combat_exp", 9000000);
        set("score", 250000);

    
        set("str", 60);
        set("int", 69);
        set("con", 60);
        set("dex", 68);

        set("qi", 33900);
        set("max_qi", 33900);
        set("jing", 33900);
        set("max_jing", 33900);
        set("neili", 61500);
        set("max_neili", 61500);
        set("jiali", 50);

        set("combat_exp", 8500000);
        set("score", 200000);
        set_skill("force", 570);
        set_skill("unarmed", 500);
        set_skill("dodge", 550);
        set_skill("parry", 550);
        set_skill("hand",570);
        set_skill("staff", 570);
        set_skill("taixuan-gong", 550);
set_skill("huanhe-dao", 550);
set_skill("sata-shenfa", 550);
set_skill("sumi-jian", 580);
set_skill("wuyu-quan", 550);
set_skill("xiuli-qiankun", 550);
set_skill("strike", 550);
set_skill("cuff", 550);
set_skill("unarmed", 550);
set_skill("blade", 550);
set_skill("sword", 550);
set_skill("club", 580);
set_skill("bawang-qiang", 580);
map_skill("sword", "sumi-jian");
//map_skill("blade", "huanhe-dao");
map_skill("strike", "xiuli-qiankun");
map_skill("cuff", "wuyu-quan");
      map_skill("force", "taixuan-gong");
        map_skill("dodge", "sata-shenfa");
        map_skill("parry", "taixuan-gong");
        map_skill("unarmed", "taixuan-gong");
set_skill("club", 580);
set_skill("bawang-qiang", 580);

    	prepare_skill("strike", "xiuli-qiankun");
	prepare_skill("cuff", "wuyu-quan");

        
	set("chat_chance_combat", 90);
       set("chat_msg_combat", ({
                (: perform_action, "sword.dieying" :),
                (: perform_action, "sword.feiwu" :),
                (: perform_action, "sword.jiushi" :),
                (: perform_action, "sword.jiushi" :),                	
                (: perform_action, "sword.ruhe" :),
                (: perform_action, "sword.shenfeng" :),                	
                (: perform_action, "sword.wuyun" :),                	                	                	                	
                (: perform_action, "parry.po" :),
                (: perform_action, "parry.jing" :),
                (: perform_action, "parry.xuan" :),
                (: perform_action, "parry.po" :),
                (: perform_action, "parry.taixuan" :),
                
        }) );


	set_temp("apply/attack", 200);
	set_temp("apply/defense", 200);
	set_temp("apply/armor", 1000);
	set_temp("apply/damage", 2600);
        setup();

        carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/city/npc/obj/tiejia")->wear();
add_money("gold", 3);
}

void init()
{
	object ob;
	::init();
	if (interactive(ob = this_player()) && 
		(int)ob->query_condition("killer")) {
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob);
	}
}
void unconcious()
{
	die();
}
void die()
{
	int i;
        object who = this_object()->query_temp("last_damage_from");
  	if (!who) return;

                if ((int)who->query("jinyong/book13")==4)
{
                i = 800+random(5000);
		who->set("jinyong/book13",5);
		who->add("combat_exp",i+32000);
		who->add("potential",i*38);
		who->add("mpgx",20);
		who->add("expmax",2);
		//command("chat "+this_player()->query("name")+"胆色过人，义惩青城恶霸。");
		tell_object (who,"你赢得了"+chinese_number(i+32000)+"点经验"+
		           chinese_number(i*38)+"点潜能"+"二十点门派贡献 二点成长上限！！\n");
		message_vision("$N对天喊道： 我要入主中原.....\n",this_object(),who);
		message("channel:chat", HIB"【海洋III】听说"+who->name() + "完成了碧血剑的所有任务!"NOR"\n", users());
		who->save();
}		
		
	::die();

}                                                 