// toumu.c
#include <ansi.h> 
inherit NPC;

void create()
{
	int n = random(2);
	set_name("强盗头目", ({ "tou mu" }) );

	set("title",HIB"黑风寨"NOR);
	set("gender", "男性");
	set("age", 33);
	set("long", "这家伙满脸横肉，一付凶神恶煞的模样，令人望而生畏。\n");
	set("combat_exp", 2000000);

	set("vendetta_mark", "heifeng_tufei");

     set("qi", 15200); 
        set("max_qi", 15200); 
        set("jing", 23500); 
        set("max_jing", 23500); 
        set("neili", 26500); 
        set("max_neili", 26500); 
        set("jiali", 180); 
        set("combat_exp", 7000000); 
        set("level", 50);
        set("score", 20000); 
        
        set_skill("force", 240); 
        set_skill("lengyue-shengong", 240); 
        set_skill("blade", 260); 
        set_skill("baisheng-daofa", 260); 
        set_skill("hujia-daofa", 260); 
        set_skill("dodge", 260); 
        set_skill("sixiang-bufa", 260); 
        set_skill("taxue-wuhen", 260);
        set_skill("parry", 240); 
        set_skill("throwing", 260); 

        set_skill("strike", 240); 
        set_skill("tianchang-strike", 240); 
        set_skill("cuff", 240); 
        set_skill("hujia-quan", 240); 
        set_skill("literate", 280); 
        set_skill("martial-cognize", 240); 

        map_skill("force", "lengyue-shengong"); 
        map_skill("blade", "hujia-daofa"); 
        map_skill("dodge", "sixiang-bufa"); 
        map_skill("parry", "hujia-daofa"); 
        map_skill("strike", "tianchang-strike"); 
        map_skill("cuff", "hujia-quan"); 
           
        prepare_skill("strike", "tianchang-strike"); 
        prepare_skill("cuff",   "hujia-quan"); 
        
        

        set("chat_chance_combat", 120); 
        set("chat_msg_combat", ({ 
                (: perform_action, "blade.huanying" :),
               	(: perform_action, "blade.lian" :),
                (: perform_action, "blade.xian" :), 
                (: perform_action, "blade.zhui" :), 
                (: perform_action, "blade.cang" :), 
                (: perform_action, "cuff.kuai" :), 
                (: perform_action, "strike.jian" :), 
                (: perform_action, "dodge.fei" :), 
                (: exert_function, "recover" :), 
                (: exert_function, "powerup" :), 
        })); 



	setup();

		carry_object(__DIR__"obj/blade")->wield();
	carry_object("/clone/misc/cloth")->wear();
}
