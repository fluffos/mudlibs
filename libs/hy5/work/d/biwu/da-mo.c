// Npc: /kungfu/class/shaolin/da-mo.c
// Date: YZC 96/01/19

inherit NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
	set_name("达摩老祖", ({
		"da mo",
		"da",
		"mo",
	}));
	set("long",
		"他是一位卷发络腮须的天竺老僧，身穿一袭邋遢金丝绣红袈裟。\n"
		"但却满面红光，目蕴慈笑，眼现智珠，一派得道高僧气势。\n"
                "他就是少林派开山鼻祖、当今武林的隐世高僧达摩祖师。\n"
	);

	set("title", HIR"少林开山祖师"NOR);
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 80);
	set("shen_type", 1);
	set("str", 130);
	set("int", 130);
	set("con", 130);
	set("dex", 130);
	set("max_qi", 454000);
	set("max_jing", 453000);
	set("neili", 458000);
	set("max_neili", 458000);
	set("jiali", 150);
	set("combat_exp", 116000000);
	set("score", 500000);

	set_skill("buddhism", 180);
	set_skill("literate", 130);

	set_skill("blade", 1300);
	set_skill("claw", 1300);
	set_skill("club", 1300);
	set_skill("cuff", 1300);
	set_skill("dodge", 1300);
	set_skill("finger", 1300);
	set_skill("force", 1300);
	set_skill("hand", 1300);
	set_skill("parry", 1300);
	set_skill("staff", 1300);
	set_skill("strike", 1300);
	set_skill("sword", 1300);
	set_skill("whip", 1300);

	set_skill("banruo-zhang", 1300);
	set_skill("cibei-dao", 1300);
	set_skill("damo-jian", 1300);
	set_skill("fengyun-shou", 1300);
	set_skill("fumo-jian", 1300);
	set_skill("hunyuan-yiqi", 1300);
	set_skill("jingang-quan", 1300);
	set_skill("longzhua-gong", 1300);
	set_skill("luohan-quan", 1300);
	set_skill("nianhua-zhi", 1300);
	set_skill("pudu-zhang", 1300);
	set_skill("qianye-shou", 1300);
	set_skill("sanhua-zhang", 1300);
	set_skill("riyue-bian", 1300);
	set_skill("shaolin-shenfa", 1300);
	set_skill("weituo-gun", 1300);
	set_skill("wuchang-zhang", 1300);
	set_skill("xiuluo-dao", 1300);
	set_skill("yingzhua-gong", 1300);
	set_skill("yijinjing", 980);
	set_skill("yizhi-chan", 1300);
	set_skill("zui-gun", 1300);
	set_skill("wuying-jian", 1300);
	map_skill("blade", "cibei-dao");
	map_skill("claw", "longzhua-gong");
	map_skill("club", "wuchang-zhang");
	map_skill("cuff", "luohan-quan");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("finger", "nianhua-zhi");
	map_skill("force", "yijinjing");
	map_skill("hand", "fengyun-shou");
	map_skill("parry", "nianhua-zhi");
	map_skill("staff", "weituo-gun");
	map_skill("strike", "sanhua-zhang");
	map_skill("sword", "wuying-jian");
	map_skill("whip", "riyue-bian");
        set("double_attack",1);
        set("breakup", 1);
        set("szj/over200", 1);
        set("jiuyin/full", 1);
        set("jiuyin/shang", 1);
        set("jiuyin/xia", 1);
        	set("guard/flag",1);
	set("guard/ok",1);
	set("hyvip",4);        
	prepare_skill("finger", "nianhua-zhi");
	prepare_skill("strike", "sanhua-zhang");
         set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 2500);
        set_temp("apply/damage", 2550);
       set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
                (: perform_action, "finger.fuxue" :),
                (: perform_action, "sword.wuying" :),
                (: perform_action, "sword.wuying" :),
                (: perform_action, "sword.wuying" :),                                
                (: perform_action, "sword.ruying" :),
                (: perform_action, "sword.foxin" :),
                (: perform_action, "sword.lidichenfo" :),
        }) );
	create_family("少林派", 34, "弟子");
	setup();
    carry_object("/p/item/ritemtz3/wsword40")->wield();
    carry_object("/p/item/ritemtz3/ahands40")->wear();
        carry_object("/d/shaolin/obj/xuan-cloth")->wear();
}

