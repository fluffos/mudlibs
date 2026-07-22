#include <skill.h> 
#include <ansi.h>

inherit NPC;
int do_learn(string arg);

void create()
{
        set_name("鹿杖客", ({ "lu zhangke", "lu", "zhangke" }) );
        set("title", HBBLU"玄冥二老"NOR);
        set("long", "他就是玄冥二老中的鹿杖客。\n");
        set("gender", "男性" );
        set("age", 55);
        set("apprentice", 1);
        set("attitude", "peaceful");
        set("str",25);
        set("int",25);
        set("con",25);
        set("dex",25);
        set("unique", 1);
        set("per", 20);
        set("no_get", 1);

        set("max_qi", 10000);
        set("max_jing", 6500);
        set("neili", 16000);
        set("max_neili", 16000);
        set("jiali", 100);
        set("combat_exp", 4200000);
        set("eff_jingli", 7000);

        set_skill("force", 350);
        set_skill("xiantian-gong", 350);
        set_skill("dodge", 350);
        set_skill("tiyunzong", 350);
        set_skill("strike", 350);
        set_skill("xuanming-shenzhang", 350);
        set_skill("parry", 350);
        set_skill("literate", 250);

        map_skill("force", "xiantian-gong");
        map_skill("dodge", "tiyunzong");
        map_skill("strike", "xuanming-shenzhang");
        map_skill("parry", "xuanming-shenzhang");
        prepare_skill("strike", "xuanming-shenzhang");

        setup();
        carry_object("/d/wudang/obj/white-robe")->wear();
}

int prevent_learn(object ob, string skill)
{
	if (skill == "xuanming-shenzhang")
		return 0;
	return 1;
}

int is_apprentice_of(object ob)
{
	return 1;
}

int recognize_apprentice(object ob)
{
	return 1;
}
