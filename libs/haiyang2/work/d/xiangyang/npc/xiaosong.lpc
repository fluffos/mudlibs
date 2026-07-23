// guidao.c
// by cleansword
// 96-02-16 YZC disabled NPC killing, & "unknown" problem when revealed

#include <ansi.h>

inherit NPC;

string ask_me(object who);

void create()
{
	set_name("落魄公子", ({ "gong zi", "gong" }) );
	set("title", "嫖客");
	set("gender", "男性" );
	set("shen_type", -1);
	set("per", 30);
	set("age", 25);
	set("str", 25);
	set("cor", 25);
	set("cps", 25);
	set("int", 25);
	set("long",
	"这是个眉清目秀的青年公子，但精神颓废，一身酒气熏人，想必是在酒色场中淘空了身子。\n" );

	set("combat_exp", 20000);
	set("attitude", "heroism");
	set("chat_chance_combat", 15);
	set("chat_msg_combat", ({
		"公子说道: 你当真吃了豹子胆啦 ? 你知道我是谁 ! \n",
		"公子忽然发出一剑，招数精奇，但剑到中途却又急忙收招。\n",
		"公子说道: 快离开我 ! 我不能打架了 !....\n"
	}) );

	set("inquiry", ([
		"张三丰" : "是武林的泰山北斗，谁人不识？" ,
	        "张无忌" : "淫贼，我终有一天要抽他的筋剥他的皮。",	
                "宋远桥" : "武当七侠之首，名杨天下。",
                "宋青书" : "玉面孟尝之名播于江湖。",
                "周芷若"   : (: ask_me :),
	]) );

	set_skill("sword", 50);
	set_skill("dodge", 40);
	set_skill("unarmed", 50);
	set_skill("parry", 50);
	
	setup();
	carry_object("clone/weapon/changjian")->wield();
	carry_object("clone/misc/cloth")->wear();
}

string ask_me(object who)
{
	int i;
	object *ob;

	if( query("revealed") ) {
		if( is_killing(who) ) return "你既然知道了我的秘密，今日休想活命！\n";
		else {
			kill_ob(who);
			who->fight_ob(this_object());
			return "知道我秘密的人都得死，纳命来吧！\n";
		}
	}

	if( (random(10) < 5) || is_fighting() )
		return "这个......\n";

	set_temp("apply/attack",  50);
	set_temp("apply/defense", 50);
	set_temp("apply/damage",  120);


	message("vision",
		HIY "落魄公子眼中突然放出兽性的光芒，怒声说道，你竟敢提周姑娘的名字？！\n"
		"落魄公子大喝一声，叫道，天下除我宋青书之外，敢提周姑娘的人都得死！！\n" 
		"宋青书使开长剑，招数精奇，沉猛狠辣，太极神剑端的非同小可。\n" NOR,
		environment(), this_object() );
        set("title","玉面孟尝");
        set_name("宋青书",({ "song", "qingshu" }));
	set("pursuer", 1);
	set("vendetta/authority", 1);
	set("chat_chance", 15);
	set("chat_msg", ({
		(: random_move :)
	}) );
	set("bellicosity", 10000);
	set("combat_exp", 300000);
        set("max_qi",1000);
        set("max_neili",1200);
        set("eff_jingli",1000);  
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.zong" :),
                (: perform_action, "unarmed.zhenup" :),
                (: perform_action, "unarmed.zhan" :),
                (: perform_action, "unarmed.ji" :),
                (: perform_action, "unarmed.jielidali" :),
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.chan" :),
                (: perform_action, "sword.chanup" :),
                (: perform_action, "sword.sui" :),
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.lian" :),                
        }) );
	set_skill("force", 150);
	set_skill("taiji-shengong", 200);
	set_skill("dodge", 150);
	set_skill("tiyunzong", 200);
	set_skill("unarmed", 200);
	set_skill("taiji-quan", 200);
	set_skill("parry", 200);
	set_skill("sword", 200);
	set_skill("taiji-jian", 200);
	set_skill("liangyi-jian", 150);
	set_skill("wudang-array", 200);
	set_skill("array",100);
	set_skill("taoism", 200);
	set_skill("literate", 200);
	set_skill("yitian-tulong", 200);
	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");

        ob = all_inventory(environment());
	for(i=sizeof(ob)-1; i>=0; i--) {
		if( !userp(ob[i]) ) continue;
                if((int)ob[i]->query("combat_exp",1)<50000) continue;
		kill_ob(ob[i]);
		ob[i]->fight(this_object());
	}
	add_money("gold", 2);
	set("revealed", 1);
	return "天下除我宋青书之外，敢提周姑娘的人都得死！\n";
}
