// gaiyiming.c 盖一鸣
// zly 7/6/99

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("盖一鸣", ({"gai yiming", "gai", "yiming"}));
	set("title", HIY"太岳四侠"NOR);
	set("nickname", "八步赶蝉、赛专诸、踏雪无痕、独脚水上飞、双刺盖七省");
        set("shen_type", 1);
	set("gender", "男性");
	set("age", 36);
	set("long", 
"这人看起来短小精悍，下巴尖削，手中拿着一对峨眉钢刺。\n"
	);

	set("attitude", "aggressive");
        set("vendetta/authority",1);
	
	   set("qi", 23900);
        set("max_qi", 23900);
        set("jing", 23900);
        set("max_jing", 23900);
        set("neili", 41500);
        set("max_neili", 41500);
        set("jiali", 50);

        set("combat_exp", 8500000);
        set("score", 200000);
        set_skill("force", 370);
        set_skill("unarmed", 300);
        set_skill("dodge", 350);
        set_skill("parry", 350);
        set_skill("hand",370);
        set_skill("staff", 370);
        set_skill("taixuan-gong", 250);
set_skill("huanhe-dao", 350);
set_skill("sata-shenfa", 350);
set_skill("sumi-jian", 280);
set_skill("wuyu-quan", 350);
set_skill("xiuli-qiankun", 350);
set_skill("strike", 250);
set_skill("cuff", 250);
set_skill("unarmed", 250);
set_skill("blade", 350);
set_skill("sword", 350);
set_skill("club", 280);
set_skill("bawang-qiang", 280);
map_skill("sword", "sumi-jian");
//map_skill("blade", "huanhe-dao");
map_skill("strike", "xiuli-qiankun");
map_skill("cuff", "wuyu-quan");
      map_skill("force", "taixuan-gong");
        map_skill("dodge", "sata-shenfa");
        map_skill("parry", "taixuan-gong");
        map_skill("unarmed", "taixuan-gong");
set_skill("club", 280);
set_skill("bawang-qiang", 280);

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
		
	map_skill("force", "huntian-qigong");

        set("chat_chance", 3);
        set("chat_msg", ({
            "盖一鸣一摆峨嵋刺，细声细气地道：“你有什么宝贝，就给我们留下吧！”\n",
            "盖一鸣说道：“咱四兄弟义结金兰，行侠仗义，专门锄强扶弱，劫富
济贫，江湖上人称大名鼎鼎的‘太岳四侠’。”\n", 
     }) );

        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();

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

  	if((int)who->query("jinyong/book14")==2 && who->query_temp("book143") )
{
		//message_vision("$N说道：太岳四侠 绝不会放过你的！\n" NOR,this_object());
		i = 380+random(2000);
		who->set("jinyong/book14",3);
		who->add("combat_exp",i+8000);
		who->add("potential",i*19);
		who->add("mpgx",10);
		who->add("expmax",2);
		//command("chat "+this_player()->query("name")+"胆色过人，义惩青城恶霸。");
		tell_object (who,"你赢得了"+chinese_number(i+8000)+"点经验"+
		           chinese_number(i*19)+"点潜能"+"十点门派贡献 二点成长上限！！\n");

		who->save();
}
        
message_vision("$N说道：萧中慧的事我知道了，我们太岳四侠会去帮她的！\n" NOR,this_object());	
	call_out("leavet",1);
        
	::die();
}




void leavet()
{
        object ob = this_object();
 message_vision("$N飞身向外跳去！\n" NOR,this_object());
        destruct(this_object());
}