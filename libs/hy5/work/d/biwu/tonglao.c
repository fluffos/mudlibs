// /NPC tonglao.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("天山童姥", ({ "tong lao", "tong", "lao" }));
	set("long",
	    "她就是「灵鹫宫」的开山祖师.\n"+
	    "乍一看似乎是个十七八岁的女子,可神情却是老气横秋.\n"+
	    "双目如电,炯炯有神,向你瞧来时,自有一股凌人的威严.\n");
	set("title", "灵鹫宫主人");
	set("gender", "女性");
	set("age", 96);
	set("nickname", HIR "唯我独尊" NOR);
	set("shen_type",0);
	set("attitude", "peaceful");

	set("str", 125);
	set("int", 135);
	set("con", 140);
	set("dex", 140);

	set("qi", 468000);
	set("max_qi", 468000);
	set("jing", 464000);
	set("max_jing", 464000);
	set("neili", 464000);
	set("max_neili", 464000);
	set("jiali", 100);

	set("combat_exp", 165500000);
	set("score", 200000);
	set_skill("yangyanshu", 1300);
	set_skill("force", 1000);
	set_skill("unarmed", 1250);
	set_skill("dodge", 1250);
	set_skill("parry", 1250);
	set_skill("hand",250);
	set_skill("strike", 1250);
        set_skill("sword",1150);

	set_skill("wuzhan-mei",1380);
	set_skill("zhemei-shou",1380);
	set_skill("liuyang-zhang",1380);
        set_skill("tianyu-qijian",1380);
	set_skill("yueying-wubu",1380);
	set_skill("bahuang-gong", 1980);

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
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 2500);
        set_temp("apply/damage", 2550);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                (: exert_function, "powerup" :),
                (: perform_action, "sword.kuangwu" :),
                (: perform_action, "sword.kuangwu" :),
                (: perform_action, "sword.san" :),
                (: perform_action, "sword.san" :),
                (: perform_action, "sword.yushijufen" :),
                (: perform_action, "sword.yushijufen" :),                
                (: perform_action, "dodge.yueguangruying" :),                
                (: perform_action, "dodge.yueguangruying" :),                
        }));
	create_family("灵鹫宫",1, "开山祖师");
	setup();
    carry_object("/p/item/ritemtz3/wsword8")->wield();
    
    carry_object("/p/item/ritemtz3/ahands9")->wear();
	carry_object("/d/lingjiu/obj/qingyi")->wear();
        carry_object("/d/lingjiu/obj/doupeng")->wear();
}
