// da.c
#include <ansi.h>

inherit NPC;

void create()
{
	set_name("司马大", ({ "sima da", "sima", "da"}));
        set("long", 
"这大汉身材魁梧之极，巨人般的身体在走动
时，脚步声极之沉重，整个地板都为之震动。\n");
        set("title",HIY"日月神教  "GRN"青龙堂舵主"NOR);
        set("gender", "男性");
        set("age", 40);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 23);
        set("int", 23);
        set("con", 24);
        set("dex", 28);
       
        set("max_qi", 2000);
        set("max_jing", 1000);
	set("eff_jingli", 1000);
        set("jiali", 50);
        set("combat_exp", 800000);

        set_skill("dodge",140);
        set_skill("literate", 120);
        set_skill("ding-dodge",140);
        set_skill("tianmogong",140);
        set_skill("strike", 140);
        set_skill("tianmo-zhang", 140);        
        set_skill("force",140);
        set_skill("parry",140);
	set_skill("sword", 140);
	set_skill("tianmo-jian", 140);

        map_skill("dodge", "ding-dodge");
        map_skill("force", "tianmogong");
	map_skill("parry", "tianmo-jian");
	map_skill("sword", "tianmo-jian");
	map_skill("strike", "tianmo-zhang");
	prepare_skill("strike", "tianmo-zhang");        
        setup();

	carry_object(BINGQI_D("changjian"))->wield();
	carry_object(MISC_D("cloth"))->wear();
}

