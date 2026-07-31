// zhang.c 张三丰
#include <ansi.h>
inherit NPC;
void create()
{
    object ob;
        set_name("小张三丰", ({ "zhang sanfeng", "zhang", "sanfeng" }));
        set("nickname", "邋遢真人");
        set("title",HIW"武当派开山祖师"NOR);
        set("long", 
                "他就是武当派开山鼻祖、当今武林的泰山北斗张三丰真人。\n"
                "身穿一件污秽的白色道袍，不修边幅。\n"
                "身材高大，年满百岁，满脸红光，须眉皆白。\n");
        set("gender", "男性");
        set("age", 100);
        set("attitude", "friendly");
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        
        set("max_qi", 1500);
        set("max_jing", 1000);
        set("neili", 1500);
        set("eff_jingli", 1000);
        set("max_neili", 1500);
        set("jiali", 30);
        set("combat_exp", 400000); 
        set("unique", 1);

	set("max_qi", 15000);
	set("max_jing", 13000);
	set("neili", 15000);
	set("max_neili", 15000);
	set("jiali", 100);
	set("combat_exp", 7000000);
	set("score", 500000);
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
	set_skill("force", 250);
	set_skill("taiji-shengong", 300);
	set_skill("dodge", 150);
	set_skill("tiyunzong", 300);
	set_skill("unarmed", 200);
	set_skill("taiji-quan", 300);
	set_skill("parry", 200);
	set_skill("sword", 200);
	set_skill("taiji-jian", 300);
	set_skill("liangyi-jian", 150);
	set_skill("wudang-array", 300);
	set_skill("array",100);
	set_skill("taoism", 250);
	set_skill("literate", 100);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");
        set("class", "taoist");

        setup();

        carry_object("/clone/cloth/cloth")->wear();
        carry_object(__DIR__"obj/zwj")->wield();
        carry_object(__DIR__"obj/rsg");
        carry_object(__DIR__"obj/rsg");
        carry_object(__DIR__"obj/rsg");
}
