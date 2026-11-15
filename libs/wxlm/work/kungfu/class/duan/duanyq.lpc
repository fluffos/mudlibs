// duanyanqing.c 段阎青



inherit NPC;

void create()
{
	set_name("段阎青", ({"duan yanqing", "duan", "yanqing", "qing"}));
	set("gender", "男性");
	set("nickname",HIR"恶贯满盈"NOR);
	set("age", 45);
	set("long", @LONG
他就是四大恶人之首，人称恶贯满盈的段阎青。只见他身高五尺有余，脸上常
年戴一张人皮面具，喜怒哀乐一丝不露。体格瘦长，双腿齐膝而断，只能用腋
下的两根镔铁拐杖代步，但行走如飞，反比常人更快！
LONG );
	set("attitude", "peaceful");
	
	set("str", 28);
	set("int", 35);
	set("con", 31);
	set("dex", 30);

	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: exert_function, "recover" :),
	}));

	set("qi", 4000);
	set("max_qi", 4000);
	set("jing", 1500);
	set("max_jing", 1500);
	set("neili", 4000);
	set("max_neili", 4000);
	set("jiali", 100);

	set("combat_exp", 1800000);

	set_skill("force", 220);
	set_skill("duanshi-xinfa", 220);
	set_skill("cuff", 170);
	set_skill("jinyu-quan", 170);
	set_skill("dodge", 210);
	set_skill("tiannan-step", 210);
	set_skill("parry", 220);
	set_skill("staff", 240);
	set_skill("duanjia-sword", 240);
	set_skill("finger", 240);
	set_skill("sun-finger", 240);

	map_skill("force", "duanshi-xinfa");
	map_skill("finger", "sun-finger");
	map_skill("cuff", "jinyu-quan");
	map_skill("dodge", "tiannan-step");
	map_skill("parry", "duanjia-sword");
	map_skill("staff", "duanjia-sword");

	prepare_skill("finger", "sun-finger");

	set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: perform_action, "finger.qiankun" :),
		(: perform_action, "finger.dian" :),
		(: perform_action, "sword.jing" :),
		(: perform_action, "sword.jue" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
	}));

	setup();

	carry_object("/clone/weapon/gangzhang")->wield();
	carry_object("/clone/misc/cloth")->wear();
}
