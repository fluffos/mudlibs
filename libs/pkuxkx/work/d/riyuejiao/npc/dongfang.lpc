//dongfang.c	假东方不败
//by bing
inherit NPC;
#include <ansi.h>

void create()
{
        set_name("东方不败", ({ "dongfang bubai", "dongfang" }));
        set("long","他是日月神教的现任教主，号称武功天下第一的东方不败。他端坐
在宝座上，面色阴沉，一句话也不说。\n");
	set("gender", "男性");
	set("title",HIR "日月神教教主" NOR);
        set("age", 43);
        set("shen_type", -1);
        set("str", 20);
        set("int", 23);
        set("con", 24);
        set("dex", 20);
        set("max_qi", 200);
        set("max_jing", 200);
        set("neili", 200);
        set("max_neili", 200);
        set("combat_exp", 5000);

        set_skill("force", 40);
        set_skill("riyue-shengong", 40);
        set_skill("dodge", 20);
        set_skill("parry", 30);
	set_skill("strike",30);
	set_skill("kaishan-zhang",30);
        set_skill("feitian-shenfa", 20);
        set_skill("literate",40);
        map_skill("force", "riyue-shengong");
        map_skill("parry", "kaishan-zhang");
        map_skill("dodge", "feitian-shenfa");
        map_skill("strike","kaishan-zhang");
	create_family("日月神教", 22, "弟子");
        setup();
        carry_object(__DIR__"obj/heiyi")->wear();
}

void attempt_apprentice(object ob)
{
	command("say 老夫不收徒弟。");
}