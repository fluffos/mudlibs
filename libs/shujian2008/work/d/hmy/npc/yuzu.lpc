// shang.c
// Modified by Numa 19991022

#include <ansi.h>
inherit NPC;

void create()
{
        set_name("狱卒", ({ "yu zu", "yuzu",}));
        set("long", "身穿一身黑袍，冷冷的笑着。\n");
        set("title",HIY"日月神教  "HIR"监狱"NOR);
        set("gender", "男性");
        set("age", 40);
        set("attitude", "peaceful");
        set("no_quest",1);
        set("shen_type", -1);
        set("str", 22);
        set("int", 25);
        set("con", 21);
        set("dex", 30);

        set("max_qi", 1500);
	set("qi", 1500);
	set("jing", 1000);
        set("max_jing", 1000);
        set("neili", 1700);
        set("max_neili", 1700);
	set("eff_jingli", 700);
	set("jingli", 700);
        set("jiali", 50);
        set("combat_exp", 300000);
        set("shen", -5000);

	set_temp("apply/attack", 40);
	set_temp("apply/defence", 40);

        set_skill("tianmo-jian",140);
	set_skill("sword", 140);
        set_skill("dodge",140);
	set_skill("ding-dodge", 140);
	set_skill("force", 140);
	set_skill("tianmogong", 140);
	set_skill("parry", 140);
	set_skill("literate", 100);
	set_skill("tianmo-zhang", 140);
	set_skill("strike", 140);

        map_skill("sword", "tianmo-jian");
        map_skill("dodge", "ding-dodge");
        map_skill("force", "tianmogong");
	map_skill("parry", "tianmo-jian");
	map_skill("strike", "tianmo-zhang");
	prepare_skill("strike","tianmo-zhang");
        setup();

	carry_object(BINGQI_D("changjian"))->wield();
	carry_object("/clone/misc/cloth")->wear();
}
