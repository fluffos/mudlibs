// sang.c
#include <ansi.h>

inherit NPC;

void create()
{
	set_name("桑三娘", ({ "sang sanniang", "sang", "sanniang"}));
	set("long", 
"一名相貌慈祥的中年妇人，但杀起人来心狠手辣，绝不手软。\n");
	set("title",HIY"日月神教  "HIW"白虎堂堂主"NOR);
        set("gender", "女性");
	set("age", 34);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 22);
	set("int", 25);
	set("con", 21);
	set("dex", 30);
                
        set("max_qi", 3000);
        set("max_jing", 2200);
	set("eff_jingli", 2200);
        set("jiali", 50);
        set("combat_exp", 1700000);
        set("shen", -5500);

	set_temp("apply/attack", 40);
	set_temp("apply/defence", 40);

        set_skill("tianmo-zhang",200);
	set_skill("strike", 200);
	set_skill("literate", 100);
        set_skill("dodge",200);
	set_skill("ding-dodge", 200);
	set_skill("force", 200);
	set_skill("tianmogong", 200);
	set_skill("parry", 200);
	set_skill("whip", 200);
	set_skill("cihang-bian", 200);

        map_skill("strike", "tianmo-zhang");
        map_skill("dodge", "ding-dodge");
        map_skill("force", "tianmogong");
	map_skill("parry", "tianmo-zhang");
	map_skill("whip", "cihang-bian");
	prepare_skill("strike", "tianmo-zhang");
        setup();
        carry_object(BINGQI_D("changbian"))->wield();
	carry_object("/clone/misc/cloth")->wear();        
}
