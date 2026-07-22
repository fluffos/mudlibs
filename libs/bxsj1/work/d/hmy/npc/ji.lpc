// ji.c
#include <ansi.h>
inherit NPC;

void create()
{
        set_name("计无施", ({ "ji wushi", "ji", "wushi"}));
	set("nickname", "夜猫子");        
        set("long", 
"此人天赋异禀，目力特强，行事忽善忽恶，或正或邪，虽
然名计无施，其实却是诡计多端，是个极厉害的人物。\n");
        set("gender", "男性");
	set("age", 50);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 22);
	set("int", 25);
	set("con", 21);
	set("dex", 30);
        
        set("max_qi", 1800);
        set("max_jing", 1300);
	set("eff_jingli", 1200);
        set("jiali", 50);
        set("combat_exp", 300000);
        set("shen", -3000);

	set_temp("apply/attack", 40);
	set_temp("apply/defence", 40);

        set_skill("tianmo-dao",135);
	set_skill("blade", 135);
        set_skill("dodge",135);
	set_skill("ding-dodge", 135);
	set_skill("force", 135);
	set_skill("tianmogong", 135);
	set_skill("tianmo-zhang", 135);
	set_skill("strike", 135);
	set_skill("literate", 100);
	set_skill("parry", 135);

        map_skill("blade", "tianmo-dao");
        map_skill("dodge", "ding-dodge");
        map_skill("force", "tianmogong");
	map_skill("parry", "tianmo-dao");
	map_skill("strike", "tianmo-zhang");
	prepare_skill("strike", "tianmo-zhang");
        setup();
 
        carry_object("/clone/weapon/blade")->wield();
	carry_object("/clone/misc/cloth")->wear();        
	add_money("gold", 1+random(2));
}
