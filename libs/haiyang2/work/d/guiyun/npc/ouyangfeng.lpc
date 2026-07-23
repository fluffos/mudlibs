// /d/guiyun/ouyangfeng.c
// Last Modified by Sir 03/05/2003

#include <ansi.h>

inherit NPC;
//inherit F_SKILL;
void create()
{
	set_name("欧阳锋", ({ "ouyang feng", "ouyang", "feng" }));
	set("long", "他是白驼山庄主，号称“西毒”的欧阳锋。\n"
		+"由于习练「九阴真经」走火入魔，已变得精\n"
		+"神错乱，整日披头散发。\n");
	set("title", "白驼山庄主");
	set("gender", "男性");
	set("age", 53);
	set("nickname", HIY "西毒" NOR);
	set("shen_type",-1);
	set("shen", -150000);
	set("attitude", "peaceful");
	set("no_get",1);

	set("str", 30);
	set("int", 29);
	set("con", 30);
	set("dex", 28);

	set("qi", 12500);
	set("max_qi", 12500);
	set("jing", 11900);
	set("max_jing", 11900);
	set("neili", 23000);
	set("max_neili", 23000);
	set("jiali", 50);

	set("combat_exp", 13000000);
	set("score", 200000);

	set("str", 60);
	set("int", 69);
	set("con", 60);
	set("dex", 68);

	set("qi", 19500);
	set("max_qi", 19500);
	set("jing", 16900);
	set("max_jing", 16900);
	set("neili", 28000);
	set("max_neili", 28000);
	set("jiali", 150);

	set("combat_exp", 6500000);
	set("score", 200000);
set_skill("qixian-wuxingjian", 300);
set_skill("cuff", 300);
set_skill("cuff", 300);
set_skill("lingshe-quan", 300);
set_skill("zhaosheshu", 300);
set_skill("yangsheshu", 300);
	set_skill("sword", 280);
	set_skill("force", 250);
	set_skill("unarmed", 150);
	set_skill("dodge", 150);
	set_skill("parry", 150);
	set_skill("strike",170);
	set_skill("hand",170);
	set_skill("training",300);
	set_skill("staff", 250);
	set_skill("hamagong", 300);
	set_skill("chanchu-bufa", 300);
	set_skill("shexing-diaoshou", 300);
	set_skill("lingshe-zhangfa", 300);
	set_skill("hamashengong", 300);
	
	map_skill("strike", "hamashengong");
	map_skill("force", "hamagong");
	map_skill("dodge", "chanchu-bufa");
	map_skill("unarmed", "shexing-diaoshou");
	map_skill("hand", "shexing-diaoshou");
	map_skill("parry", "lingshe-zhangfa");
	map_skill("staff", "lingshe-zhangfa");

        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                (: exert_function, "reserve" :),
                (: perform_action, "staff.saoluoye" :),
                (: perform_action, "staff.shoot" :),
                (: perform_action, "staff.saoluoye" :),
                (: command("unwield shengzhang") :),
                (: command("unwield shengzhang") :),
                (: command("wield shengzhang") :),
                (: command("wield shengzhang") :),
                (: perform_action, "strike.hama" :),                
                (: perform_action, "strike.hama" :),                
                (: perform_action, "hand.diaoshou" :),                
                (: perform_action, "hand.diaoshou" :),                
        }) );

	create_family("白驼山派",1, "开山祖师");
	set("chat_chance",2);
	set("chat_msg",({
		"欧阳锋自言自语道：何日白驼山派才能重霸江湖呢…\n",
		"欧阳锋道：我儿欧阳克必能够重振白驼山派雄风！\n",
		"欧阳锋道：江湖险恶，困难重重哪！\n",
	}));
	
	set("inquiry", ([
		"name":   "名字，我...我没有名字，我...我是谁?",
		"名字":   "名字，我...我没有名字，我...我是谁?",
	]));
	setup();
//	carry_object(WEAPON_DIR"treasure/lingshezhang")->wield();
	carry_object("/d/baituo/obj/shezhang")->wield();
	carry_object(__DIR__"obj/baipao")->wear();
	add_money("silver",50);
}


