// tuolei.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("拖雷", ({ "tuo lei", "lei", "tuo" }));
	set("long", 
"拖雷是成吉思汗幼子，坚忍果决。此次带兵南来，势如破竹，兵锋毕露。\n");
	set("gender", "男性");
	set("title", HIR"蒙古征南大元帅"NOR);
	set("age", 18);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 24);
	set("str", 38);
	set("int", 40);
	set("con", 20);
	set("dex", 38);
	
set("max_qi", 39000);
	set("max_jing", 39000);
	set("neili", 33000);
	set("max_neili", 33000);
	set("jiali", 100);
	set("combat_exp", 8800000);
	set("score", 500000);

	set_skill("literate", 260);
	set_skill("force", 260);
	set_skill("dodge", 260);
	set_skill("unarmed", 260);
	set_skill("parry", 260);
	set_skill("whip", 300);
	set_skill("blade", 300);
	set_skill("sword", 300);
	set_skill("hand", 260);
	set_skill("claw", 300);
	set_skill("cuff", 300);
	set_skill("strike", 300);
	set_skill("houquan", 390);
	set_skill("yunlong-xinfa", 380);
	set_skill("yunlong-shengong", 380);
	set_skill("wuhu-duanmendao", 380);
	set_skill("yunlong-jian", 380);
	set_skill("yunlong-shenfa", 380);
	set_skill("yunlong-bian", 380);
	set_skill("yunlong-shou", 380);
	set_skill("yunlong-zhua", 380);
	set_skill("baihua-cuoquan", 380);
set_skill("bazhen-zhang", 380);

	map_skill("dodge", "yunlong-shenfa");
	map_skill("force", "yunlong-shengong");
	map_skill("unarmed", "baihua-cuoquan");
	map_skill("blade", "wuhu-duanmendao");
	map_skill("hand", "yunlong-shou");
	map_skill("parry", "baihua-cuoquan");
	map_skill("claw", "yunlong-zhua");
	map_skill("sword", "yunlong-jian");
	map_skill("whip", "yunlong-bian");

	map_skill("cuff", "baihua-cuoquan");
	map_skill("strike", "bazhen-zhang");
	
	prepare_skill("cuff", "baihua-cuoquan");
	prepare_skill("strike", "bazhen-zhang");

	set("book_count", 1);
   
	set("env/wimpy", 60);
	set("chat_chance_combat", 90);  
	set("chat_msg_combat", ({

		(: command("unwield changjian") :),
		(: command("wield changjian") :),
                (: perform_action, "sword.slj" :),
                (: perform_action, "sword.duoming" :),
                (: perform_action, "sword.guang" :),
                (: perform_action, "sword.shen" :),
                (: perform_action, "sword.xunlei" :),
                (: perform_action, "sword.xian" :),

                (: perform_action, "cuff.hong" :),
                (: perform_action, "cuff.luan" :),
                (: perform_action, "cuff.yi" :),                	                	
                                
                (: perform_action, "strike.bafang" :),
                (: perform_action, "strike.baxianzuijiu" :),
                (: perform_action, "strike.jueming" :),                	                	


                (: perform_action, "claw.ji" :),
                (: perform_action, "claw.ningxue" :),
	}) );

	set("env/wimpy", 60);
	set_temp("is_riding", HIC"青骢马"NOR);
	set("env/wimpy", 40);

 	setup();
	carry_object("/d/city/obj/tiejia")->wear();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/city2/obj/hlbian");
	carry_object("/d/city/obj/gangdao");
}
void die()
{
	int i;
        object who = this_object()->query_temp("last_damage_from");
  	if (!who) return;

who->set_temp("book590",1);
	call_out("leavet",1);
}


void leavet()
{
        object ob = this_object();
 message_vision("$N说道: 要想我们退军，来蒙古见大汗吧！\n" NOR,this_object());
        ::die();
}