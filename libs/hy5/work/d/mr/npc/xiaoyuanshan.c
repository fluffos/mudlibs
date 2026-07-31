// qiao-feng.c

#include <ansi.h>;
inherit NPC;
inherit F_MASTER;
int ask_duan2();
string ask_me();

void create()
{
	set_name("萧远山", ({"xiao yuanshan", "yuanshan", "xiao"}));
	set("nickname", "黑布蒙面人");
	set("gender", "男性");
	set("age", 29);
	set("long", 
"萧远山属契丹后族中人，自幼随汉人师父习武，武功属辽国第一，是辽周皇
后属珊大帐的亲军总教头，并且很得萧太后的赏识，受辽国太后信任，任属
珊军总教头\n");
	set("attitude", "peaceful");
	set("class", "beggar");
 	set("beggarlvl", 10);
	
	set("str", 330);
	set("int", 24);
	set("con", 330);
	set("dex", 324);

        set("qi", 132500);
	set("max_qi", 132500);
	set("jing", 133800);
	set("max_jing", 133800);
	set("neili", 333000);
	set("max_neili", 333000);
	set("jiali", 300);
	
	set("combat_exp", 9000000);
	set("score", 200000);
	set("shen", 100000);
	 
		set_skill("fengmo-zhang",380);
	set_skill("liuhe-zhang",380);
	set_skill("strike",390);
	set_skill("force", 250);             // 基本内功
	set_skill("huntian-qigong", 380);    // 混天气功
	set_skill("unarmed", 300);           // 基本拳脚
	set_skill("xianglong-zhang", 380);   // 降龙十八掌
	set_skill("dodge", 200);      	     // 基本躲闪
	set_skill("xiaoyaoyou", 380);        // 逍遥游
	set_skill("parry", 300);             // 基本招架
	set_skill("staff", 300);             // 基本棍杖
	set_skill("dagou-bang", 380);        // 打狗棒法
	set_skill("begging", 200);           // 叫化绝活
	set_skill("checking", 300);          // 道听途说
	set_skill("training", 300);         // 驭兽术
	
	set_skill("yuejia-qiang", 380);        // 打狗棒法
	set_skill("suohou-gong", 380);        // 打狗棒法
set_skill("chansi-shou", 380);        // 打狗棒法
set_skill("claw", 380);        // 打狗棒法
set_skill("hand", 380);        // 打狗棒法	
set_skill("club", 380);        // 打狗棒法		
	
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "dagou-bang");
	map_skill("staff", "dagou-bang");
	map_skill("strike", "xianglong-zhang");
map_skill("claw", "suohou-gong");
map_skill("hand", "chansi-shou");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.mielong" :),
                (: perform_action, "unarmed.mielong" :),
                (: perform_action, "unarmed.kanglongwuhui" :),                
                (: perform_action, "unarmed.hui" :),                
                (: perform_action, "unarmed.fei" :),                
                (: perform_action, "unarmed.qu" :),                
                (: perform_action, "unarmed.zhen" :),                
                (: perform_action, "unarmed.leiting" :),                
                (: perform_action, "unarmed.xianglong" :),                                
                (: perform_action, "dodge.gjtq" :),     
                (: perform_action, "dodge.canghaiyixiao" :),                                
                (: perform_action, "dodge.maishou" :),                                
        }) );
	set_temp("apply/attack",150);
	set_temp("apply/defense",150);
	set_temp("apply/armor",500);
	set_temp("apply/damage",400);
        set("inquiry", ([
          "带头大哥" : (: ask_duan2 :),
           ]));



	setup();
	
	//carry_object(__DIR__"obj/lvyv_bang");
	carry_object("/clone/misc/cloth")->wear();
//      carry_object(BOOK_DIR"stick_book")->wear();
}


void unconcious()
{
	die();
}
void die()
{
	int i;
        object who = this_object()->query_temp("last_damage_from");
  	if (!who) return;
who->set_temp("killtlbb83",1);
	 call_out("leavet",1);
}

void leavet()
{
        object ob = this_object();
message_vision(HIG"$N在一阵佛号声中，被一个扫地老僧救走..\n"NOR NOR,this_object());
        destruct(this_object());
}
