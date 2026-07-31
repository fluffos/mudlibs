//whitlady.c 
inherit NPC;

void create()
{
	set_name("°×ÒÂ½£¼§", ({ "white lady","lady","white" }) );
	set("gender", "Å®ĞÔ" );
	set("age", 18);
	set("long", "Ò»¸ö´ÏÃ÷ÁæÀşµÄ°×ÒÂ½£¼§¡£\n");
	set("shen_type", -1);
	set("combat_exp", 1000);
	set("str", 20);
	set("dex", 18);
	set("con", 19);
	set("int", 20);
	set("attitude", "friendly");
	
	set("qi", 8000);
	set("max_qi", 8000);
	set("jing", 7800);
	set("max_jing", 7800);
	set("neili", 10000);
	set("max_neili", 10000);
	set("jiali", 10);

	set("combat_exp", 800000);
    set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                (: exert_function, "reserve" :),
                (: command("zhaoshe") :),
                (: command("zhaoshe") :),
                (: perform_action, "strike.hama" :),                
                (: perform_action, "hand.diaoshou" :),                
                (: perform_action, "sword.shan" :),                
                (: perform_action, "sword.yin" :),                
                (: perform_action, "sword.zhu" :),                
        }) );
	set_skill("unarmed", 100);
	set_skill("hand", 80);
	set_skill("strike", 80);
	set_skill("dodge", 120);
	set_skill("parry", 90);
	set_skill("force", 90);
	set_skill("staff", 80);
	set_skill("training", 50);
	set_skill("hamagong",190);
	set_skill("chanchu-bufa", 200);
	set_skill("shexing-diaoshou", 200);
	set_skill("lingshe-zhangfa", 200);
set_skill("qixian-wuxingjian", 200);
set_skill("xiyu-tiezheng", 200);
set_skill("shentuo-zhang", 200);
set_skill("cuff", 100);
set_skill("cuff", 100);
set_skill("lingshe-quan", 200);
set_skill("zhaosheshu", 180);
set_skill("yangsheshu", 180);
	map_skill("force", "hamagong");
	map_skill("dodge", "chanchu-bufa");
	map_skill("unarmed", "shexing-diaoshou");
	map_skill("hand", "shexing-diaoshou");
	map_skill("parry", "qixian-wuxingjian");
	map_skill("sword", "qixian-wuxingjian");
	set_temp("apply/attack", 8);
	set_temp("apply/defense", 12);
	set_temp("apply/damage", 111);
	set_temp("apply/armor", 117);
	//create_family("°×ÍÕÉ½ÅÉ", 10, "µÜ×Ó");
	setup();
	carry_object("/clone/weapon/changjian")->wear();
	carry_object("/d/baituo/obj/baipao")->wear();
}

