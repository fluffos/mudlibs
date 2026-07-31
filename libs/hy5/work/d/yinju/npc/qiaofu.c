inherit NPC;
#include <ansi.h>
void create()
{
	set_name("樵夫", ({ "qiao fu", "qiao" }));
	set("title",  "大理国大将军" );
	set("long", 
"他就是大理国的原大将军，一灯大师的四大弟子之一。
左手提着一捆松柴，右手握着一柄斧头，但见他容色豪
壮，神态虎虎，举手迈足间似是大将军有八面威风。若
非身穿粗布衣裳而在这山林间樵柴，必当他是个叱咤风
云的统兵将帅。\n");
              set("nickname", HIY "渔樵耕读" NOR );   
        set("gender", "男性");
        set("age", 45);

        set("class", "officer");
        set("attitude", "friendly");
        set("shen_type", 1);
        set("per", 25);
        set("str", 30);
        set("int", 20);
        set("con", 25);
        set("dex", 25);     
        set("max_qi", 21000);
        set("max_jing", 21500);
        set("neili", 22000);
        set("max_neili", 22000);
        set("jiali", 50);
        set("combat_exp", 3500000);
        set("score", 100000);


        set("inquiry", ([
                "一灯大师"   : "师父他老人家在上面。\n",
                "段智兴"     : "那是我师父俗世的名讳。\n",
                "刘瑛姑"     : "她是我师父俗世的妃子。\n",
        ]) );
   set_skill("unarmed", 200);
        set_skill("force", 200);
        set_skill("dodge", 200);
        set_skill("parry", 150);
        set_skill("cuff", 200);
        set_skill("strike", 150);
        set_skill("sword", 200);
        set_skill("staff", 150);
        set_skill("finger", 220);
        set_skill("finger", 280);
	set_skill("kurong-changong", 301);
        set_skill("tiannan-step", 280);
        set_skill("jinyu-quan", 280);
        set_skill("wuluo-zhang", 280);
        set_skill("duanjia-sword", 380);
        set_skill("yiyang-zhi", 280);
//        set_skill("sun-finger", 100);
	set_skill("literate", 200);
	set_skill("wuluo-zhang", 200);
	set_skill("feifeng-whip", 300);
	map_skill("unarmed", "yiyang-zhi");
	map_skill("force", "kurong-changong");
	map_skill("dodge", "tiannan-step");
	map_skill("finger", "yiyang-zhi");
	map_skill("cuff", "jinyu-quan");
	map_skill("strike", "wuluo-zhang");
	map_skill("parry", "yiyang-zhi");
	map_skill("sword", "duanjia-sword");
	map_skill("staff", "duanjia-sword");
	prepare_skill("cuff", "jinyu-quan");
	prepare_skill("strike", "wuluo-zhang");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "finger.sandie" :),
                (: perform_action, "finger.dian" :),
                (: perform_action, "finger.jian" :),
                (: perform_action, "finger.qian" :),
                (: perform_action, "finger.sandie" :),
                (: perform_action, "sword.fenglei" :),
                (: perform_action, "sword.jingtian" :),
                (: perform_action, "sword.feilong" :),   
                	(: perform_action, "sword.ailao" :),
                		(: perform_action, "sword.xswy" :) ,            
                (: perform_action, "dodge.huadie" :),
                
                (: exert_function, "powerup" :),
                (: exert_function, "ku" :),
                (: exert_function, "rong" :),
        }) );
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 1200);
        set_temp("apply/damage", 1100);

        setup();
        carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/misc/cloth")->wear();
}
        
void die()
{
	int i;
        object who = this_object()->query_temp("last_damage_from");
  	if (!who) return;
 		who->set_temp("book571",1);
		


	::die();
}