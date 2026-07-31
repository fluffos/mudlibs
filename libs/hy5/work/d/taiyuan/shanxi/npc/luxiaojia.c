 inherit NPC;
//inherit F_MASTER;
#include <ansi.h>
void smart_fight();
void smart_busy();
void smart_attack(); 
void create()
{
        set_name("路小佳", ({ "lu xiaojia", "lu" }) );
        set("gender", "男性" );
    	set("age", 25);
    	set("title", "独行客" );
    	set("nickname", HIR"快意江湖"NOR );
        set("int", 35);
        set("per", 30);
        set("npc_difficulty",10); 
        set("organization/性质","邪");
        set("quest_npc",1);
        set("class","assassin");
        set("resistance/kee",60);
        set("resistance/gin",60);
        set("resistance/sen",60);
        set("long",
                "他是个年轻人，一个奇怪的年轻人，有着双奇怪的眼睛，就连笑的时候，这双眼睛都
是冷冰的，就像是死人的眼睛，没有情感，也没有表情。
\n"
                );
        set("max_gin", 300000);
        set("max_kee", 300000);
        set("max_sen", 300000);
        set("eff_gin", 300000);
        set("eff_kee", 300000);
        set("eff_sen", 300000);
        set("gin", 300000);
        set("kee", 300000);
        set("sen", 300000);
        set("max_force", 4000);
        set("force", 4000);
        set("force_factor", 100);
        set("cor",80);
        set("str",50);
        set("combat_exp", 80000000);
        set("score", 3000);
        set("agi",25);
        set("int",30);
        set("chat_chance",10);
                set("chat_msg",({
"路小佳拈起一颗花生，剥开，抛起，然后看着这颗花生落到自己嘴里，闭上眼睛，
长长的叹了口气，开始慢慢咀嚼。\n",
"路小佳忽然笑笑 ，说道：“杀人是件干净痛快的事情。”他顿了一顿，又说道：
“所以在杀人之前，我一定要洗个澡。”\n",
        })      );
set("qi", 18000);
	set("max_qi", 18000);
	set("jing", 18000);
	set("max_jing", 18000);
	set("neili", 39000);
	set("max_neili", 39000);
	set("jiali", 100);

	set("combat_exp", 8500000);
	set("score", 200000);
	        set_skill("claw", 220);
        set_skill("throwing", 220);
        set_skill("goplaying", 100);
        set_skill("luteplaying", 100);
        
        set_skill("painting", 100);
        set_skill("medicine", 100);
        set_skill("construction", 100);
        set_skill("horticulture", 100);
        set_skill("dramaturgy", 100);

	set_skill("yangyanshu", 380);
	set_skill("force", 200);
	set_skill("unarmed", 250);
	set_skill("dodge", 250);
	set_skill("parry", 250);
	set_skill("hand",350);
	set_skill("strike", 250);
        set_skill("sword",250);
	set_skill("sword",200);
	set_skill("strike", 260);
	set_skill("sword", 260);
	set_skill("hand", 360);
	set_skill("qingyun-shou", 380);
	set_skill("panyang-zhang", 380);
	set_skill("liuyue-jian", 380);

	set_skill("wuzhan-mei",380);
	set_skill("zhemei-shou",380);
	set_skill("liuyang-zhang",380);
        set_skill("tianyu-qijian",380);
	set_skill("yueying-wubu",380);
	set_skill("bahuang-gong", 380);

	map_skill("force", "bahuang-gong");
	map_skill("strike","liuyang-zhang");
	map_skill("dodge", "yueying-wubu");
	map_skill("unarmed", "liuyang-zhang");
        map_skill("strike","liuyang-zhang");
	map_skill("hand", "zhemei-shou");
	map_skill("parry", "liuyang-zhang");
        map_skill("sword","tianyu-qijian");

        prepare_skill("hand","zhemei-shou");
	prepare_skill("strike","liuyang-zhang");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                	(: exert_function, "shield" :),
                	(: exert_function, "dunzun" :),	
                (: perform_action, "sword.kuangwu" :),
                	(: perform_action, "sword.qing" :),
                		(: perform_action, "sword.ju" :),
               
                (: perform_action, "sword.san" :),
                (: perform_action, "strike.zhong" :),
                (: perform_action, "strike.lianzhong" :),
                (: perform_action, "hand.tanmei" :),
                (: perform_action, "hand.zhemei" :),
                (: perform_action, "sword.san" :),
                (: perform_action, "sword.yushijufen" :),
                (: perform_action, "dodge.yueguangruying" :),                
        }));
        setup();
    carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"obj/lusword")->wield();
}   
smart_fight()
{
        int i;
        object *enemy;
        enemy = this_object()->query_enemy();
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        if (enemy[i]->query_skill("iron-cloth")>175) {
                                if (this_object()->query_temp("weapon")){
                                command( "say 好俊的硬功，看我的！");
                                command("unwield all");
                                }
                        } else  command("wield all");
                        
                        if (!enemy[i]->query_temp("till_death/lockup"))
                        {
                                this_object()->smart_busy();
                        } else this_object()->smart_attack();
                        
                }
        }
} 
smart_busy() {
        this_object()->perform_action("dodge.canglongzhaxian");
}
smart_attack() {
        this_object()->perform_action("sword.sharenruma");      
        }    
