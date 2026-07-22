#include <ansi.h>
inherit NPC;

void create()
{
	set_name("霖枫", ({"lin feng", "feng"}));
  	set("gender", "男性");
  	set("age", 46);
  	set_level(30);
  	
	set_skill("spear",300);
	set_skill("force",300);
	set_skill("dodge",300);
	set_skill("parry",300);
	set_skill("yanxing-steps",300);
	set_skill("bawang-qiang",300);
	set_skill("lengquan-force",300);
	set_skill("unarmed",300);
	set_skill("changquan",300);
  	map_skill("force", "lengquan-force");
  	map_skill("unarmed", "changquan");
  	map_skill("spear", "bawang-qiang");
  	map_skill("parry", "bawang-qiang");
  	map_skill("dodge", "yanxing-steps");
	set("force_factor", 20);
	create_family2("将军府","少帅军", 3,"管家");
	setup();
 	carry_object(0,"cloth",random(2))->wear();
 	carry_object(0,"shoes",random(2))->wear();
 	carry_object(0,"kui",random(2))->wear();
  	carry_object(0,"spear",random(2))->wield();
}