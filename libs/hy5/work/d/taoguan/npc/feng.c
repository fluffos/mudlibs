 inherit NPC;
#include <ansi.h>
void smart_fight();
void smart_busy();
void smart_attack(); 
void create()
{
        set_name("风道人", ({ "taoist feng" }) );
        set("nickname",HIW "怒斧" NOR);
        set("gender", "男性");
        set("age", 60);
        set("long",
"风道人是丁氏兄妹新近从南疆请来的三清宫四供奉之一。\n"
);
        set("attitude", "friendly");
        set("combat_exp", 600000);
        set("score", 2000);
        set("reward_npc", 1);
        set("difficulty", 2);
        set("class", "knight"); 
        set("int", 30);
        set("cps", 30);
        set("spi", 30);
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
     	set("max_qi", 36000);
	set("max_jing", 36000);
	set("neili", 56000);
	set("max_neili", 56000);
	set("jiali", 200);
	set("combat_exp", 9500000);
	set("score", 500000);

	set_skill("force", 280);
	set_skill("guiyuan-tunafa", 380);
	set_skill("dodge", 300);
	set_skill("strike", 300);
	set_skill("hammer", 380);
	set_skill("axe", 380);
	set_skill("shuishangpiao", 380);
	set_skill("strike", 350);
	set_skill("tiezhang-zhangfa", 380);
	set_skill("parry", 200);
	set_skill("cuff", 300);
	set_skill("literate", 100);
	set_skill("tiexue-hammer",380);
	set_skill("duanyun-fu", 380);
	set_skill("tongbi-zhang", 380);
	set_skill("xuanyuan-axe", 380);
	set_skill("liumang-quan", 380);
		
	map_skill("force", "guiyuan-tunafa");
	map_skill("dodge", "shuishangpiao");
	map_skill("unarmed", "tiezhang-zhangfa");
	map_skill("strike", "tiezhang-zhangfa");
	map_skill("cuff", "liumang-quan");
	map_skill("parry", "xuanyuan-axe");
	map_skill("axe", "xuanyuan-axe");
	prepare_skill("strike", "tiezhang-zhangfa");
	prepare_skill("cuff", "liumang-quan");
        set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
                (: perform_action, "cuff.pofuchenzhou" :),
                (: perform_action, "cuff.guguoshenyou" :),
                (: perform_action, "cuff.luori" :),
                (: perform_action, "axe.kaitianpidi" :),
                (: perform_action, "axe.sanbanfu" :),
                (: perform_action, "axe.jiuqipoxiao" :),
                (: perform_action, "axe.jiuqipoxiao" :),                	
                (: perform_action, "axe.jiuqipoxiao" :),                	                	
                (: perform_action, "unarmed.dao" :),
                (: perform_action, "unarmed.ying" :),
                (: perform_action, "unarmed.yin" :),
                (: perform_action, "unarmed.tianlei" :),
                (: perform_action, "unarmed.tiezhangxianglong" :),
                  (: perform_action, "unarmed.zhangdao" :),
		(: command("unwield bigaxe") :),
		(: command("wield bigaxe") :),			
        }) );
        
        set_temp("apply/dodge", 30);
        set_temp("apply/armor", 30);
        setup();
        add_money("coin", 30);
        carry_object(__DIR__"obj/f_axe")->wield();
        carry_object(__DIR__"obj/f_cloth")->wear();
}  
void init()
{       
        ::init();
        add_action("do_killing", "kill");
} 
int do_killing(string arg)
{
    object player, victim;
    player = this_player();
    if(!arg || arg == "") return 0;
    victim = present(arg, environment(player));
    if(!objectp(victim))
                return notify_fail("这里没有这个人。\n");
    if(living(victim))
    {
        if(victim->query("name")=="看风景的道姑" 
          && victim->query("id")=="wandering taoist" )
        {
            message_vision(HIW"$N对著$n喝道：大胆，是何居心!\n"NOR, this_object(), player);
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            player->start_busy(2);
            return 0;
        } 
    }
    return 0;
} 
