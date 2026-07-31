
inherit NPC;
#include <ansi.h>;
int ask_me();

void create()
{
        set_name("岳不群", ({ "yue buqun", "yue" }) );
        set("title", "华山派掌门");
        set("nickname", "君子剑");
        set("gender", "男性");
        set("class", "swordsman");
        set("age", 55);
        set("long",
                "岳不群自幼执掌华山派，乃当今武林中一等一的高手。\n");
        set("attitude", "peaceful");
        set("str", 56);
        set("con", 50);
        set("dex", 50);
        set("int", 58);

    set("guard/flag", 1);
    set("guard/ok", 1);
    set("qi", 150000);
    set("max_qi", 150000);
    set("jing", 150000);
    set("max_jing", 150000);
    set("neili", 150000);
    set("max_neili", 150000);
    set("jiali", 200);

    set("combat_exp", 24500000);
    set("score", 0);

	set_skill("cuff", 500);
	set_skill("strike", 500);
	set_skill("force", 500);             // 基本内功
	set_skill("finger", 500);            // 基本指法
	set_skill("unarmed", 500);           // 基本拳脚
	set_skill("dodge", 500);             // 基本躲闪
	set_skill("parry", 500);             // 基本招架
	set_skill("sword", 500);             // 基本剑法
	set_skill("pixie-jian", 500);        // 辟邪剑法
	set_skill("changquan", 500);         // 太祖长拳
	set_skill("literate", 100);          // 读书识字
	set_skill("kuihua-xinfa", 500);      // 葵花心法
	set_skill("kuihua-dafa", 500);      // 葵花大法
	set_skill("kuihua-feiying", 500);      // 葵花身法
	set_skill("tmzhang", 500);
	set_skill("staff", 500);
	set_skill("tmjian", 500);
	set_skill("tmdao", 500);
	set_skill("pmshenfa", 500);
	set_skill("cuff",500);
	set_skill("blade", 500);
	set_skill("tmdafa", 500);
	set_skill("tmquan", 500);       
	map_skill("force", "kuihua-xinfa");
	map_skill("sword", "kuihua-dafa");
	map_skill("unarmed", "changquan");
	map_skill("dodge", "kuihua-feiying");
	map_skill("parry", "pixie-jian");

        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.tonggui" :),
                (: perform_action, "sword.pi" :),
                	(: perform_action, "sword.yinrou" :),
                (: perform_action, "sword.po" :),
                (: perform_action, "sword.gui" :),
                (: perform_action, "parry.cimu" :),
                (: perform_action, "parry.huanying" :),
                (: perform_action, "parry.sanlianci" :),
                (: perform_action, "dodge.kuihuashenzhang" :),
                (: perform_action, "dodge.feiying" :),
                (: perform_action, "dodge.jue" :),
                (: perform_action, "unarmed.yuhuan" :),
                (: exert_function, "powerup" :),
                (: exert_function, "kuihuawudi" :),
                (: exert_function, "powerup" :),                
        }) );
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 900);
        set_temp("apply/damage", 200);
        set_temp("apply/attack", 200);
        
        create_family("华山派", 13, "掌门");
        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}

void unconcious()
{
	die();
}
void die()
{
	int i;
        object who = this_object()->query_temp("last_damage_from");
  	if(((int)who->query("jinyong/book8")>=11))
	{
//::die();	
	}
        else if(who) {
        	message_vision("$N说道：不可能，这不可能，辟邪剑法天下无敌，怎么会被你打败！\n" NOR,this_object());
		i = random(5000);
		who->set("jinyong/book8",11);
		who->add("combat_exp",i+30000);
		who->add("potential",i*45);
		who->add("mpgx",10);
		who->add("expmax",2);
		//command("chat "+this_player()->query("name")+"胆色过人，义惩青城恶霸。");
		tell_object (who,"你赢得了"+chinese_number(i+30000)+"点经验"+
		           chinese_number(i*45)+"点潜能"+"十点门派贡献 二点成长上限！！\n");
		message("channel:chat", HIB"【海洋III】听说"+who->name() + "完成了笑傲江湖的所有任务!"NOR"\n", users());
		who->save();
        }
	::die();
}
