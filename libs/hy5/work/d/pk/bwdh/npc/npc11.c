#include <ansi.h>
inherit NPC;
void create()
{
        set_name("小渡厄", ({ "du e", "e" }) );
        set("title", "少林长老");
        set("gender", "男性");
        set("class", "bonze");
        set("age", 90);
        set("long", "这是一个面颊深陷，瘦骨零丁的老僧，他脸色枯黄，如同一段枯木。\n");
        set("attitude", "peaceful");

        set("str", 30);
        set("int", 25);
        set("dex", 28);
        set("con", 28);

	set("combat_exp", 1500000);
	set("score", 200000);

	set("str", 30);
	set("int", 30);
	set("cor", 30);
	set("cps", 30);
	set("con", 30);

	set("qi", 4000);
	set("max_qi", 2000);
	set("neili", 4000);
	set("max_neili", 2000);
	set("jiali", 90);

	create_family("少林派", 35, "弟子");
	assign_apprentice("弟子", 0);

	set_skill("force", 150);
	set_skill("whip", 300);
	set_skill("parry", 180);
	set_skill("dodge", 180);
	set_skill("yijinjing", 180);
	set_skill("hunyuan-yiqi", 150);
	set_skill("riyue-bian", 300);
	set_skill("shaolin-shenfa", 180);

	map_skill("force", "hunyuan-yiqi");
	map_skill("whip",  "riyue-bian");
	map_skill("parry", "riyue-bian");
	map_skill("dodge", "shaolin-shenfa");

	set_skill("blade", 150);
	set_skill("claw", 150);
	set_skill("club", 150);
	set_skill("cuff", 150);
	set_skill("finger", 150);
	set_skill("hand", 150);
	set_skill("staff", 150);
	set_skill("strike", 150);
	set_skill("sword", 150);

	set_skill("banruo-zhang", 190);
	set_skill("cibei-dao", 190);
	set_skill("damo-jian", 190);
	set_skill("fengyun-shou", 190);
	set_skill("fumo-jian", 190);
	set_skill("jingang-quan", 199);
	set_skill("longzhua-gong", 190);
	set_skill("luohan-quan", 190);
	set_skill("nianhua-zhi", 190);
	set_skill("pudu-zhang", 190);
	set_skill("qianye-shou", 190);
	set_skill("sanhua-zhang", 190);
	set_skill("weituo-gun", 190);
	set_skill("wuchang-zhang", 190);
	set_skill("xiuluo-dao", 190);
	set_skill("yingzhua-gong", 190);
	set_skill("yizhi-chan", 200);
	set_skill("zui-gun", 200);
	set_skill("buddhism", 200);
	map_skill("blade", "cibei-dao");
	map_skill("claw", "longzhua-gong");
	map_skill("club", "wuchang-zhang");
	map_skill("cuff", "luohan-quan");
	map_skill("finger", "nianhua-zhi");
	map_skill("hand", "fengyun-shou");
	map_skill("staff", "weituo-gun");
	map_skill("strike", "sanhua-zhang");
	map_skill("sword", "fumo-jian");

     set("chat_chance_combat", 90);
     set("chat_msg_combat", ({
                (: perform_action, "finger.fuxue" :),
                (: perform_action, "finger.fuxue" :),
                (: perform_action, "whip.chan" :),
                (: perform_action, "whip.chanrao" :),
                (: perform_action, "whip.fumoquan" :),
                            }) );

	set("count", random(10)-8);
        set_temp("apply/attack", 150);
        set_temp("apply/defense", 100);
        set_temp("apply/armor", 100);
        set_temp("apply/damage", 100);

        setup();
        carry_object(__DIR__"obj/hs")->wield();
        carry_object(__DIR__"obj/jgz")->wear();
        carry_object("/clone/cloth/cloth")->wear();
        carry_object(__DIR__"obj/jinchuang");
        carry_object(__DIR__"obj/jinchuang");
        carry_object(__DIR__"obj/jinchuang");        
}
