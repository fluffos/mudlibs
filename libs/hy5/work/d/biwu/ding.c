// ding.c ¶¡´ºÇï

inherit NPC;
inherit F_MASTER;
string ask_me();
string ask_du1();
string ask_du2();

void create()
{
	set_name("¶¡´ºÇï", ({ "ding chunqiu", "ding" }));
	set("nickname", "ÐÇËÞÀÏ¹Ö");
	set("long", 
		"Ëû¾ÍÊÇÐÇËÞÅÉ¿ªÉ½×æÊ¦¡¢ÁîÕýÅÉÈËÊ¿Éî¶ñÍ´¾øµÄÐÇËÞÀÏ¹Ö¶¡´ºÇï¡£\n"
		"¿ÉÊÇËû¿´ÆðÀ´ÐÎÃ²ÇåÆæ£¬ÏÉ·çµÀ¹Ç¡£\n");
	set("gender", "ÄÐÐÔ");
	set("age", 60);
	set("attitude", "friendly");
	set("class", "scholar");
	set("shen_type", -1);
	set("shen", -150000);
	set("str", 125);
	set("int", 130);
	set("con", 128);
	set("dex", 128);
	
	set("max_qi", 334000);
	set("max_jing", 333000);
	set("neili", 354000);
	set("max_neili", 354000);
	set("jiali", 100);
	set("combat_exp", 19500000);
	set("score", 400000);

	set_skill("unarmed", 1150);
	set_skill("force", 1150);
	set_skill("huagong-dafa", 980);
	set_skill("throwing", 1150);
	set_skill("feixing-shu", 980);
	set_skill("dodge", 1150);
	set_skill("zhaixinggong", 980);
	set_skill("strike", 150);
	set_skill("chousui-zhang", 980);
	set_skill("claw", 1150);
	set_skill("sanyin-wugongzhao", 980);
	set_skill("parry", 1150);
	set_skill("staff", 1150);
	set_skill("poison", 1150);
	set_skill("tianshan-zhang", 980);
	set_skill("literate", 1000);

	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("strike", "chousui-zhang");
	map_skill("claw", "sanyin-wugongzhao");
	map_skill("parry", "chousui-zhang");
	map_skill("unarmed", "chousui-zhang");
	map_skill("staff", "tianshan-zhang");
	prepare_skill("strike", "chousui-zhang");
	prepare_skill("claw", "sanyin-wugongzhao");
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 2500);
        set_temp("apply/damage", 2550);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "strike.zhaohuo" :),
                (: perform_action, "strike.zhaohuo" :),                
                (: perform_action, "strike.biyan" :),
                (: perform_action, "strike.sandu" :),
                (: perform_action, "strike.huoqiang" :),
                (: perform_action, "strike.throw" :),
                (: perform_action, "strike.yinhuo" :),
                (: perform_action, "strike.zhaohuo" :),
                (: perform_action, "strike.huoqiu" :),
                (: perform_action, "strike.zhaohuo" :),
        }) );
	set("book_count", 1);
	set("zhen_count", 1);
	set("san_count", 1);

	set("inquiry", ([
		"¶¾¾­" : (: ask_me :),
		"ÐÇËÞ¶¾¾­" : (: ask_me :),
		"±ÌÁ×Õë" : (: ask_du1 :),
		"ÈýÐ¦åÐÒ£É¢" : (: ask_du2 :),
		"åÐÒ£ÈýÐ¦É¢" : (: ask_du2 :),
	]));

	create_family("ÐÇËÞÅÉ", 1, "¿ªÉ½×æÊ¦");
	set("class", "taoist");

	setup();
	carry_object("/p/item/ritemtz3/ahands34")->wear();
//      carry_object("/clone/weapon/changjian")->wield();
}

