// shang.c

#include <ansi.h>
inherit NPC;

void create()
{
        set_name("上官云", ({ "shangguan yun", "yun", "shangguan"}));
        set("long", "只见他长手长脚，双目精光灿烂，甚有威势。\n");
        set("title",HIY"日月神教  "GRN"青龙堂堂主"NOR);
        set("gender", "男性");
        set("age", 40);
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
        set("shen", -5000);

	set_temp("apply/attack", 40);
	set_temp("apply/defence", 40);

        set_skill("tianmo-jian",200);
	set_skill("sword", 210);
	set_skill("literate", 120);
        set_skill("dodge",200);
	set_skill("ding-dodge", 200);
	set_skill("force", 200);
	set_skill("tianmogong", 190);
	set_skill("parry", 200);
	set_skill("strike", 200);
	set_skill("tianmo-zhang", 200);

        map_skill("sword", "tianmo-jian");
        map_skill("dodge", "ding-dodge");
        map_skill("force", "tianmogong");	
	map_skill("parry", "tianmo-zhang");
	map_skill("strike", "tianmo-zhang");
	prepare_skill("strike", "tianmo-zhang");
	
        setup();
 	carry_object(BINGQI_D("changjian"))->wield();
	carry_object(MISC_D("cloth"))->wear();        
}
