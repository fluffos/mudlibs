#include <ansi.h>
inherit SUPER_NPC;

void create()
{
        set_name("金甲卫士", ({ "wei shi", "shi", "guard" }) );
        set("gender", "男性");
        set("age", 25);
        set("long","这是位守护王宫的金甲武士，身披重甲，手执精兵。
他双目精光炯炯，警惕地巡视着四周的情形。\n");
	set_level(39);
        set("max_kee", 20000);
	set("max_sen", 20000);
        set("max_force", 8000);
        set("force_factor", 150);
  	create_family("将军府", 4, "");
  	delete("title");
  	set_skill("force",390);
  	set_skill("lengquan-force",390);
  	set_skill("parry",390);
  	set_skill("dodge",390);
  	set_skill("yanxing-steps",390);
  	set_skill("unarmed",390);
  	set_skill("changquan",390);
  	set_skill("spear",390);
  	set_skill("bawang-qiang", 390);
  	map_skill("force", "lengquan-force");
  	map_skill("unarmed", "changquan");
  	map_skill("spear", "bawang-qiang");
  	map_skill("parry", "bawang-qiang");
  	map_skill("dodge", "yanxing-steps");        
        
        set("env/test","HIY");
        setup();
	carry_object(0,"armor",random(5))->wear();
	carry_object(0,"cloth",random(5))->wear();
	carry_object(0,"pifeng",random(5))->wear();
	carry_object(0,"shield",random(5))->wear();
	carry_object(0,"shoes",random(5))->wear();
	carry_object(0,"kui",random(5))->wear();
	carry_object(0,"hand",random(5))->wear();
	carry_object(0,"ring",random(5))->wear();
	carry_object(0,"neck",random(5))->wear();
	carry_object(0,"waist",random(5))->wear();
	carry_object(0,"wrists",random(5))->wear();
	carry_object(0,"spear",random(5))->wield();
}
