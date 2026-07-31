//weiqi...97/12/11
#include <ansi.h>
inherit NPC;
void create()
{
	set_name("公孙三娘", ({"gongsun sanniang", "gongsun", "sanniang"}));
	set("age", 32);
	set_level(50);
	set("gender", "女性");
	set("per", 30);
	set("long", "公孙大娘的结拜姐妹，剑法和舞曲同样精妙。\n");
	set("title", HIM"舞仙"NOR);
	set("attitude", "friendly");
	set("force_factor", 200);
        set("mana_factor", 100);
	set_skill("unarmed",300);        
	set_skill("dodge", 500);
	set_skill("moondance", 300);
	set_skill("parry", 300);
	set_skill("literate", 400);
	set_skill("sword", 500);
	set_skill("daya-jian",500);
	set_skill("force",300);
	set_skill("spells",300);
	map_skill("dodge", "moondance");
	map_skill("sword", "daya-jian");
	map_skill("parry", "daya-jian");
	set("env/test",({"HIB","HIY","HIC"})[random(3)]);
	setup();
        carry_object(0,"sword",random(100))->wield();
	carry_object(0,"cloth",random(100))->wear();
	carry_object(0,"shoes",random(100))->wear();
	carry_object(0,"pifeng",random(100))->wear();
	carry_object(0,"ring",random(100))->wear();
	carry_object(0,"neck",random(100))->wear();
}

