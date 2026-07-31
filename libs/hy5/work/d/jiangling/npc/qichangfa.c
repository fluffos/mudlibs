//Edited by fandog, 02/13/2000
#include <ansi.h>;
inherit NPC;

void create ()
{
	set_name("戚长发", ({"qi changfa","qi"}));
	set("nickname", HIB"铁锁横江"NOR);
	set("long", "一个老头儿，嘴里咬着一根短短的旱烟管。他满头白发、满脸皱
纹，但眼中神光炯然，凛凛有威。\n");
	set("gender", "男性");
	set("age", 48);
	set("combat_exp", 10000000);
	set("str", 125);
	set("int", 125);
	set("con", 125);
	set("dex", 125);
	set("per", 125);
	set_skill("force", 220);
	set_skill("dodge", 220);
	set_skill("sword", 220);
	set_skill("parry", 220);
	set_skill("feixian-steps", 220);
	set("max_qi",35000);
	set("max_jing",35000);
	set("max_neili",35000);
	set("qi",35000);
	set("jing",35000);
	set("neili",35000);
    set("max_qi",35000);
        set("max_jing",35000);
        set("max_sen",35000);
        set("neili", 50000);
        set("max_neili", 50000);
        set("atman", 10000);
        set("max_atman", 50000);
        set("mana", 50000);
        set("max_mana", 50000);
        set("force_factor", 350);





        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 600);
        set_temp("apply/damage", 650);
        set_skill("literate",380);
        set_skill("unarmed",380);
        set_skill("dodge",290);
        set_skill("parry",280);
	set_skill("force",380);
	set_skill("strike",380);
	set_skill("literate",380);	
	set_skill("cuff",380);	
	set_skill("changquan",380);
        set_skill("luohua-jian",380);
        set_skill("sword",380);
set_skill("ill-quan",380);
set_skill("luoriquan",380);
set_skill("qinnashou",380);
	set_skill("array",500);
	set_skill("taoism", 500);
set_skill("shizi-zhan",380);
set_skill("dahong-quan",380);
set_skill("qishang-cuff",380);
set_skill("kongling-jian",380);
set_skill("luofeng",380);
set_skill("taiyi",500);
set_skill("sanqing-jian",380);
set_skill("kongdong-xinfa",380);

        //set_skill("doomsword",380);
        //set_skill("chilian-shenzhang",380);
        //set_skill("softsword",280);
        //set_skill("nine-moon-sword",380);

        map_skill("unarmed","qishang-cuff");
        map_skill("sword","sanqing-jian");
        map_skill("force","kongdong-xinfa");
        map_skill("dodge","luofeng");
        map_skill("parry","qishang-cuff");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: exert_function, "roar" :),
                (: exert_function, "shield" :),
                (: exert_function, "powerup" :),
                (: perform_action, "sword.huan" :),
                (: perform_action, "sword.jianmang" :),
                (: perform_action, "sword.sanlianji" :),	
                (: perform_action, "sword.wanxiang" :),	
    (: perform_action, "dodge.bagua" :),	                	
                (: perform_action, "parry.hunpofeiyang" :),
                (: perform_action, "parry.qishang" :),
            (: exert_function, "zhenhuo" :),
            (: exert_function, "dingshen" :),
            (: exert_function, "sanqing" :),
            (: exert_function, "wuxing" :),			

		(: command("unwield changjian") :),
		(: command("wield changjian") :),

        }) );
	
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 600);
        set_temp("apply/damage", 650);
  


	setup();
		carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/cloth/male-cloth")->wear();
}


void unconcious()
{
    die();
}
void die()
{
        object ob, me, corpse;
        
        ob = this_object();
        me = query_temp("last_damage_from");
if (!me) return;
              //me->add("score",1);        
        message_vision(RED"$N一声怒吼，浑身鲜血直流，倒了下去!\n"NOR,ob,me);
        


        me->set_temp("killlc3",1);


              ::die();
        return;
}