#include <ansi.h>
inherit F_MASTER;
inherit NPC;
void imbue_event(object me);
void create()
{
        set_name("天枫十四郎", ({ "master tianfeng", "tianfeng", "master"}) );
        set("gender", "男性" );
        set("age", 55);
        set("nickname", CYN "伊贺忍侠" NOR);
        set("long", 
"一个面色蜡黄，浓眉高颧的乌衣老者，浑身尽是杀气。他盘膝坐在山巅之上，
衣抉下露出赤足，却将一双高齿乌木的木屐端放于前，木屐上竟又放着柄乌
鞘长刀。\n");
    create_family("飞天御剑流", 5, "家督");
    set("rank_nogen",1);
    set("ranks",({"下忍","中忍","上忍",RED"罗刹"NOR,HIR"修罗"NOR}));
    set("rank_levels",({32000,512000,1536000,3456000 }));
      set("str", 50);
        set("dex", 50);
        set("con", 50);
        set("int", 50);
        set("per", 50);
        set("per",23);
        set("tianyu_1",1);
        set("jing", 20000);
        set("eff_jing", 20000);
        set("max_jing", 20000);        
        set("qi", 22000);
        set("eff_qi", 22000);
        set("max_qi", 22000);
        set("max_jingli", 22000);
        set("neili", 40000);
        set("max_neili", 40000);
        set("max_jingqi",1000);
        set("combat_exp", 9000000);
        set_skill("dodge",300);
        set_skill("cuff",320);
        set_skill("unarmed",300);
        set_skill("parry",300);
        set_skill("blade",380);

         set_skill("wuxing-dun",280);
        set_skill("shayi",280);
         set_skill("aikido",280);
         set_skill("shayi-xinfa",320);
        set_skill("shiren-jianfa",280);
        set_skill("shiren-quanfa",280);
        set_skill("force",300);
set_skill("huoxinliu-jianfa",180);

set_skill("xuanhualiu-quanfa",280);
set_skill("ninjitsu",380);
set_skill("ittouryu",380);
set_skill("enmeiryu",380);
set_skill("hand",320);
        set_skill("literate",250);
        map_skill("blade", "ittouryu");
        map_skill("force", "shayi-xinfa");
        
        map_skill("dodge", "wuxing-dun");
        map_skill("parry", "shiren-jianfa");
        
        map_skill("hand", "enmeiryu");
        map_skill("cuff", "xuanhualiu-quanfa");
	prepare_skill("cuff", "xuanhualiu-quanfa");
	prepare_skill("hand", "enmeiryu");
        
        create_family("飞天御剑流", 5, "家督");
         set("chat_chance_combat", 98);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.break" :),
                (: perform_action, "hand.mukuha" :),
                (: perform_action,"hand.shiden" :),
                (: perform_action, "hand.shimon" :),  
                (: perform_action, "hand.chuyao" :), 
                (: perform_action, "hand.linfengguilong" :), 		
                (: perform_action, "blade.gobankiri" :), 
                (: perform_action, "blade.hyakki" :), 
                (: perform_action, "blade.daoshen" :), 
                (: perform_action, "blade.shiwanshenmo" :), 
                (: exert_function, "berserk" :),
                (: exert_function, "durup" :),
                (: exert_function, "shayi" :),
                (: exert_function, "shenzu" :),	
                (: exert_function, "powerup" :),		
        }));
       set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 200);
        set_temp("apply/attack", 200);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                        "天枫十四郎那亘古不变的死灰色的脸突然颤抖起来，哇的一声咳出口鲜血。\n",
                                })  );
        set("inquiry",  ([
                "李菊" : "菊子。。菊子。。你在哪里。。。\n",
                ])              ); 
        setup();
    carry_object(__DIR__"wucloth")->wear();
    carry_object(__DIR__"muji")->wear();
        carry_object(__DIR__"blackblade")->wield();
} 
void attempt_apprentice(object ob)
{
        if(ob->query("family/family_name")!="飞天御剑流")
        {
                command("say 你是哪时来的??\n");
          return 0;
        }
        if(ob->query("combat_exp")<1000000)
        {
                 command("say 你的实战经练不够，我不能传授你功夫。\n");
            return 0;
        }
       	if ((int)ob->query_skill("huoxinliu-jianfa", 1) < 200) {
		command("say 你的活心流剑法太低了，还未能领悟活心二字如何学习我的武功呢。"); 
		command("say " + RANK_D->query_respect(ob) + 
			"你还是把活心流剑法先提高了在来吧？");
		return;
        }
	if ((int)ob->query_skill("shayi-xinfa", 1) < 200) {
		command("say 你的杀意心法太低,恐怕控制不了杀意。"); 
		command("say " + RANK_D->query_respect(ob) + 
			"你还是把杀意心法先提高了在来吧？");
		return;
	}
	if ((int)ob->query_skill("aikido", 1) < 200) {
		command("say 你的空手道太低。"); 
		command("say " + RANK_D->query_respect(ob) + 
			"你还是把空手道先提高了在来吧？");
		return;
	}
	if ((int)ob->query_skill("wuxing-dun", 1) < 200) {
		command("say 你的五行遁太低。"); 
		command("say " + RANK_D->query_respect(ob) + 
			"你还是把五行遁先提高了在来吧？");
		return;
	}
    if ((int)ob->query_skill("shayi", 1) < 200)
    {
        command("say 剑法之道在于杀意。");
        command("say " + RANK_D->query_respect(ob) +
            "你的杀意太低了？");
        return;
    }
	command("recruit " + ob->query("id"));
	ob->set("title",HIR"【一刀流】"HIR"传人"NOR);
       ob->set("class", "yujianliu");
}