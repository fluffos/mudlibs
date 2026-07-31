 inherit NPC;
#include <ansi.h>
void  smart_fight(object who); 
void create()
{
        set_name("火道人", ({ "taoist huo" }) );
        set("nickname",HIR "毒指" NOR);
        set("gender", "男性");
        set("age", 50);
        set("long",
"火道人是丁氏兄妹新近从南疆请来的三清宫四供奉之一。\n"
);
        set("attitude", "friendly");
        set("combat_exp", 700000);
        set("score", 2000);
        set("reward_npc", 1);
        set("difficulty", 2);
        set("class", "assassin"); 
        set("int", 30);
        set("cps", 30);
        set("spi", 30);
        set("fle",50);
//      set("pursuer", 1); 
        set("force", 500);
        set("max_neili", 500);
        set("force_factor", 30); 
        set("atman", 150);
        set("max_atman", 150); 
        set("mana", 300);
        set("max_mana", 300);
        set("mana_factor", 5); 
        set("inquiry", ([
                "谷衣心法": 
"谷衣心法是我茅山派为对抗邪魔外道所创的内功心法。\n",
        ]) ); 
  	set_skill("hammer",380);
	set_skill("tiexue-hammer",320);
	set_skill("force", 260);
	set_skill("guiyuan-tunafa", 320);
	set_skill("dodge", 260);
	set_skill("shuishangpiao", 320);
	set_skill("strike", 280);
	set_skill("tiezhang-zhangfa", 350);
	set_skill("parry", 180);
	set_skill("literate", 100);
	set_skill("axe", 380);
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
                (: perform_action, "hammer.fanzhuan" :),
                (: perform_action, "unarmed.dao" :),
                (: perform_action, "unarmed.ying" :),
                (: perform_action, "unarmed.yin" :),
                (: perform_action, "unarmed.tianlei" :),
                (: perform_action, "unarmed.tiezhangxianglong" :),
                  (: perform_action, "unarmed.zhangdao" :),
		(: command("unwield bighammer") :),
		(: command("wield bighammer") :),
        }) );
        
        set_temp("apply/dodge", 30);
        set_temp("apply/armor", 30);
        setup(); 
 
        add_money("silver", 30);
        carry_object(__DIR__"obj/h_cloth")->wear();
} 

