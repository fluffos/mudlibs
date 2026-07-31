inherit NPC;
#include <ansi.h>

void create()
{
	set_name("九头驸马", ({"jiutou fuma","fuma"}));
	set_level(135);
        set("long","九头驸马原在北冥大泽中修练，后被招为驸马。\n");
	set("gender", "男性");
       	set("age", 20);
 	set("title", "九头虫");
	set("attitude", "heroism");

        set("eff_dx", -500000);
        set("nkgain", 500);

	set("class","yaomo");
	set("force_factor", 100);
	set("mana_factor", 80);
	
	set_skill("huomoforce",1350);
	set_skill("pingtian-dafa",1350);
       	set_skill("unarmed",1350);
       	set_skill("dodge",1350);
       	set_skill("force",1350);
       	set_skill("parry", 200);
       	set_skill("spells",1350);
	set_skill("fork", 200);
 	set_skill("yueya-chan",1350);
	set_skill("moshenbu",1350);
	set_skill("moyun-shou",1350);
	map_skill("unarmed", "moyun-shou");
	map_skill("dodge", "moshenbu");
	map_skill("parry", "yueya-chan");
	map_skill("fork", "yueya-chan");
	create_family("碧波潭", 2, "蓝");

        setup();
	carry_object("/d/qujing/bibotan/obj/moonstaff")->wield();
        carry_object("/d/qujing/bibotan/obj/zhanpao")->wear();
}
