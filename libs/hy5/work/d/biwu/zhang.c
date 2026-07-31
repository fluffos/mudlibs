// zhang.c 张三丰

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("张三丰", ({ "zhang sanfeng", "zhang" }));
	set("nickname", "邋遢真人");
	set("long", 
		"他就是武当派开山鼻祖、当今武林的泰山北斗张三丰真人。\n"
		"身穿一件污秽的灰色道袍，不修边幅。\n"
		"身材高大，年满百岁，满脸红光，须眉皆白。\n");
	set("gender", "男性");
	set("age", 100);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 130);
	set("int", 130);
	set("con", 130);
	set("dex", 130);
	
	set("max_qi", 555000);
	set("max_jing", 553000);
	set("neili", 555000);
	set("max_neili", 555000);
	set("jiali", 100);
	set("combat_exp", 117000000);
	set("score", 500000);
         set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.zong" :),
                (: perform_action, "unarmed.zhenup" :),
                (: perform_action, "unarmed.yingyang" :),
                (: perform_action, "unarmed.tu" :),
                (: perform_action, "unarmed.zhan" :),
                (: perform_action, "unarmed.ji" :),
                (: perform_action, "unarmed.jielidali" :),
                (: perform_action, "hand.leiting" :),
                (: perform_action, "hand.mian" :),
                (: perform_action, "strike.zheng" :),	
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.chan" :),
                (: perform_action, "sword.chanup" :),
                (: perform_action, "sword.sui" :),
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.zhenwu" :),
                (: perform_action, "sword.lian" :),                
        }) );
set_skill("claw", 1150);
set_skill("strike", 1180);
	set_skill("force", 1150);
	set_skill("taiji-shengong", 1180);
	set_skill("dodge", 1150);
	set_skill("tiyunzong", 1180);
	set_skill("unarmed", 1100);
	set_skill("taiji-quan", 1180);
	set_skill("parry", 1100);
	set_skill("sword", 1100);
	set_skill("taiji-jian", 1180);
	set_skill("liangyi-jian", 1150);
	set_skill("wudang-array", 1180);
	set_skill("array",1100);
	set_skill("taoism", 1100);
	set_skill("literate", 1200);
	set_skill("yitian-tulong", 1380);
	set_skill("juehu-shou", 1380);
	set_skill("raozhi-roujian", 1180);
	set_skill("wudang-mianzhang", 1180);
	set_skill("hand", 1180);
	set_skill("paiyun-shou", 1180);
	set_skill("shenmen-jian", 1380);
	set_skill("yitian-zhang", 1280);
	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-quan");
	map_skill("sword", "taiji-jian");
		map_skill("hand", "paiyun-shou");
			map_skill("strike", "yitian-zhang");
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 2500);
        set_temp("apply/damage", 3500);
        set("double_attack",1);
        set("breakup", 1);
        set("szj/over200", 1);
        set("jiuyin/full", 1);
        set("jiuyin/shang", 1);
        set("jiuyin/xia", 1);
        	set("guard/flag",1);
	set("guard/ok",1);
	set("hyvip",4);    
	create_family("武当派", 1, "开山祖师");
	set("class", "taoist");

	setup();
    carry_object("/p/item/ritemtz3/wsword43")->wield();
    carry_object("/p/item/ritemtz3/ahands43")->wear();
}

