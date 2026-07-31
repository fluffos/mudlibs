// changcf.c 常长风
// zly 7/6/99

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("常长风", ({"chang changfeng", "chang", "changfeng"}));
	set("title", HIY"太岳四侠"NOR);
	set("nickname", "双掌开碑");
        set("shen_type", 1);
	set("gender", "男性");
	set("age", 35);
	set("long", 
"这人看起来又高又肥，便如是一座铁塔摆在地下，他身前放着一
块大石碑，碑上写的是“先考黄府君诚本之墓”。\n"
	);

	set("attitude", "aggressive");
        set("vendetta/authority",1);
	
	set("max_qi", 34000);
	set("max_jing", 33000);
	set("neili", 64000);
	set("max_neili", 64000);
	set("jiali", 200);
	set("combat_exp", 9800000);
	set("score", 400000);
	set_skill("unarmed",300);
	set_skill("hammer",280);
	set_skill("tiexue-hammer",320);
	set_skill("force", 260);
	set_skill("guiyuan-tunafa", 320);
	set_skill("dodge", 260);
	set_skill("shuishangpiao", 320);
	set_skill("strike", 280);
	set_skill("tiezhang-zhangfa", 350);
	set_skill("parry", 180);
	set_skill("literate", 100);
	set_skill("axe", 280);
	set_skill("duanyun-fu", 350);
	map_skill("hammer", "tiexue-hammer");
	set_skill("duanyun-fu", 350);
	set_skill("tongbi-zhang", 350);
	map_skill("force", "guiyuan-tunafa");
	map_skill("dodge", "shuishangpiao");
	map_skill("unarmed", "tiezhang-zhangfa");
	map_skill("strike", "tongbi-zhang");
	map_skill("parry", "tiezhang-zhangfa");
	prepare_skill("strike", "tiezhang-zhangfa");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "strike.chu" :),
                (: perform_action, "strike.juesha" :),
                (: perform_action, "strike.tui" :),
                (: perform_action, "strike.zhui" :),
                (: perform_action, "unarmed.dao" :),
                (: perform_action, "unarmed.ying" :),
                (: perform_action, "unarmed.yin" :),
                (: perform_action, "unarmed.tianlei" :),
                (: perform_action, "unarmed.tiezhangxianglong" :),
                  (: perform_action, "unarmed.zhangdao" :),
        }) );


        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"obj/mubei")->wield();
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

  	if((int)who->query("jinyong/book14")==1 && who->query_temp("book142") )
{
		//message_vision("$N说道：太岳四侠 绝不会放过你的！\n" NOR,this_object());
		i = 300+random(2000);
		who->set("jinyong/book14",2);
		who->add("combat_exp",i+8000);
		who->add("potential",i*18);
		who->add("mpgx",10);
		who->add("expmax",2);
		//command("chat "+this_player()->query("name")+"胆色过人，义惩青城恶霸。");
		tell_object (who,"你赢得了"+chinese_number(i+8000)+"点经验"+
		           chinese_number(i*18)+"点潜能"+"十点门派贡献 二点成长上限！！\n");

		who->save();
}
message_vision("$N说道：萧中慧的事我知道了，太岳四侠会全去帮她的！\n" NOR,this_object());	
	call_out("leavet",1);
        
	::die();
}




void leavet()
{
        object ob = this_object();
 message_vision("$N飞身向外跳去！\n" NOR,this_object());
        destruct(this_object());
}