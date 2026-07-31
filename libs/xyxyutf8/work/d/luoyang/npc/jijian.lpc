#include <ansi.h>
inherit NPC;

void create()
{
	set_name("蔡师师", ({ "cai shishi" ,"shishi","cai" }) );
	set("gender", "男性" );
	set_level(36);
	set("age", 52);
	set("long",
"蔡师师，黑面蔡家第四代弟子中最出类拔萃的人物，现在洛阳专为各位英雄祭剑。\n");
	set("attitude", "friendly");
	set_skill("fonxansword",360);
	set_skill("sword",360);	
	set_skill("parry",360);
	set_skill("unarmed",300);
	set_skill("dodge",360);
	set_skill("force",360);
	map_skill("sword","fonxansword");
	map_skill("parry","fonxansword");
	create_family2("将军府","黑面蔡家",4,HIR"剑师传人" NOR);
	setup();
        carry_object(0,"cloth",random(2))->wear();
        carry_object(0,"sword",random(2))->wield();
        powerup(1,1);
}
