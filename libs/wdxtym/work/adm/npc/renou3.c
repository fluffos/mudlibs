
#include <ansi.h>
int qilin_xiao();
inherit NPC;
void create()
{
	set_name(BMAG "超级人偶"NOR, ({"ren3"}) );
	set("long",  "这是韩老魔做出来的人偶，提供玩家们测试技能及伤害。");
	set("gender", "无性");
	set("age", 999);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 255);
	set("int", 255);
	set("con", 255);
	set("dex", 255);
	set("qi", 1000000000);
	set("max_qi", 1000000000);
	set("max_jing", 1000000);
	set("neili", 1000000);
	set("max_neili", 1000000);
	set("combat_exp",100000000);
	
    set_skill("force", 2500+random(2500));
    set_skill("unarmed", 2500+random(2500));
    set_skill("dodge", 2500+random(2500));
    set_skill("parry", 2500+random(2500));
    set_skill("sword", 2500+random(2500));
    set_skill("hand", 2500+random(2500));
    set_skill("cuff", 2500+random(2500));
    set_skill("strike", 2500+random(2500));
    set_skill("finger", 2500+random(2500));
    set_skill("claw", 2500+random(2500));
    set_skill("blade", 2500+random(2500));
    set_skill("staff", 2500+random(2500));
    set_skill("hammer", 2500+random(2500));
    set_skill("club", 2500+random(2500));
    set_skill("whip", 2500+random(2500));
    
    set_skill("never-defeated", 2500+random(2500));
    set_skill("never-defeated", 2500+random(2500));
    set_skill("never-defeated", 2500+random(2500));
    set_skill("never-defeated", 2500+random(2500));
    set_skill("never-defeated", 2500+random(2500));
    set_skill("never-defeated", 2500+random(2500));
    set_skill("never-defeated", 2500+random(2500));
		
	map_skill("force", "never-defeated");
    map_skill("sword", "never-defeated");
    map_skill("parry", "never-defeated");
    map_skill("unarmed", "never-defeated");
    map_skill("dodge", "never-defeated");
	map_skill("hand", "never-defeated");
    map_skill("cuff", "never-defeated");
    map_skill("strike", "never-defeated");
    map_skill("finger", "never-defeated");
    map_skill("claw", "never-defeated");
	map_skill("blade", "never-defeated");
    map_skill("staff", "never-defeated");
    map_skill("hammer", "never-defeated");
    map_skill("club", "never-defeated");
    map_skill("whip", "never-defeated");
	
    set("chat_chance_combat", 90);
    set("chat_msg_combat", ({
		(: perform_action, "force.juemie" :),
		(: perform_action, "force.lei" :),
		(: perform_action, "force.po" :),
		(: perform_action, "force.tianhua" :),
		(: perform_action, "force.wanli" :),
		(: perform_action, "force.yuce" :),
		(: exert_function, "force.powerup" :),
		(: exert_function, "force.roar" :),		
		(: exert_function, "force.shield" :),
 }));
	setup();      
 carry_object("/clone/cloth/cloth")->wear();
 }               		
                		
int qilin_xiao()
{
        call_out("qilinyan", 1);
        return 1;
}

int qilinyan()
{
        int i;
        int dam;
        object *inv;
        inv = all_inventory(environment(this_object()));
        if (random(20) <= 5)
        {
        set("qi", 1000000);
        set("max_jing", 1000000);            
        message_vision( HIM"\n测试人偶恢复了血气。\n",this_object());   
        }
        
        return 1;
}

 void die()
{
       ::die();
}
 
 