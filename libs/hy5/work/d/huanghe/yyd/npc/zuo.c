// xiaoyaozi.c 逍遥子
// zly 7/6/99

#include <ansi.h>
inherit NPC;
string ask_yaoshi();

void create()
{
	set_name("卓天雄", ({"zuo tianxiong", "zuo"}));
	set("title", HIR"铁棍震八方"NOR);
        set("shen_type", 1);
	set("gender", "男性");
	set("attitude", "aggressive");
        set("vendetta/authority",1);
	set("age", 38);
	set("long", 
"这是一个传说中的武林高手，双目
似争似闭，嘴里慢慢喷着烟雾。\n"
	);

	set("str", 50);
	set("int", 50);
	set("con", 50);
	set("dex", 50);

	  set("qi", 42000);
	set("max_qi", 42000);
	set("jing", 43800);
	set("max_jing", 43800);
	set("neili", 52000);
	set("max_neili", 52000);
	set("jiali", 200);
	
	set("combat_exp", 1500000);
	set("score", 200000);
	set("shen", 100000);
	 	set_skill("fengmo-zhang",180);
	set_skill("liuhe-zhang",180);
set_skill("dagou-bang",80);
	set_skill("strike",190);
	set_skill("force", 250);             // 
	set_skill("force", 180);             // 基本内功
	set_skill("huntian-qigong", 330);    // 混天气功
	set_skill("dodge", 150);      	     // 基本躲闪
	set_skill("xiaoyaoyou", 320);        // 逍遥游
	set_skill("parry", 150);             // 基本招架
	set_skill("hand", 200);              // 基本手法

	set_skill("blade", 180);             // 基本刀法
	set_skill("liuhe-dao", 280);       // 四象六合刀
	set_skill("begging", 200);           // 叫化绝活
	set_skill("checking", 200);          // 道听途说
	set_skill("training", 200);          // 驭兽术
	set_skill("strike",285);  // 基本掌法

	set_skill("xianglong-zhang",285);

	map_skill("strike","lianhua-zhang");
	prepare_skill("strike","lianhua-zhang");

	
	map_skill("force", "huntian-qigong");
	map_skill("hand",  "suohou-gong");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("blade", "liuhe-blade");
	map_skill("parry", "yuejia-qiang");

	set_skill("yuejia-qiang", 380);        // 打狗棒法
	set_skill("suohou-gong", 380);        // 打狗棒法
set_skill("chansi-shou", 380);        // 打狗棒法
set_skill("claw", 380);        // 打狗棒法
set_skill("hand", 380);        // 打狗棒法	
set_skill("club", 380);        // 打狗棒法		
map_skill("parry", "yuejia-qiang");
map_skill("club", "yuejia-qiang");
map_skill("claw", "suohou-gong");
map_skill("hand", "chansi-shou");

	prepare_skill("hand",  "chansi-shou");
prepare_skill("claw",  "suohou-gong");


       set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "club.gong" :),
                (: perform_action, "club.qldj" :),
                (: perform_action, "club.zhtx" :),
                (: command("unwield yuejia qiang") :),
                (: command("wield yuejia qiang") :),
                (: perform_action, "claw.suo" :),
                (: perform_action, "hand.qin" :),                
                (: perform_action, "hand.qinna" :),                
                (: perform_action, "dodge.gjtq" :),                                
                (: perform_action, "dodge.canghaiyixiao" :),                                
                (: perform_action, "dodge.maishou" :),                                
        }) );

        set("inquiry", ([
           "钥匙"  : (: ask_yaoshi :),
        ]));

        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/club")->wield();
      
       

} 

string ask_yaoshi()
{
        object me=this_player();
        me->set_temp("tao",1);
        command("hehe");
        command("whisper "+me->query("id")+" 打死我也不会告诉你的。");
        return "说完，偷偷向假山水池望了一眼。\n";
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

  	if((int)who->query("jinyong/book14")==3 )
{
		message_vision("$N说道：我的宝藏啊！\n" NOR,this_object());
		i = 580+random(2000);
		who->set("jinyong/book14",4);
		who->add("combat_exp",i+12000);
		who->add("potential",i*19);
		who->add("mpgx",10);
		who->add("expmax",2);
		//command("chat "+this_player()->query("name")+"胆色过人，义惩青城恶霸。");
		tell_object (who,"你赢得了"+chinese_number(i+12000)+"点经验"+
		           chinese_number(i*19)+"点潜能"+"十点门派贡献 二点成长上限！！\n");

		who->save();
}
        
	::die();
}