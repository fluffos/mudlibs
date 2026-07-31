inherit NPC;
#include <ansi.h>
#include "/d/migong/romnpc2.c"

void create()
{
       set_name("九头驸马", ({"jiutou fuma","fuma"}));

        set("long","九头驸马原在北冥大泽中修练，后被招为驸马。\n");
       set("gender", "男性");
       set("age", 20);
 	set("title", "九头虫");
        set("int", 25);
       set("attitude", "heroism");
        set("combat_exp", 1200000);
  set("combat_exp", 1500000);


        set("eff_dx", -500000);
        set("nkgain", 500);

       set("class","yaomo");
       set("per", 10);
	set("str", 30);
       set("max_qi", 1600);
       set("max_jing", 1600);
       set("neili", 2000);
       set("max_neili", 2000);
       set("force_factor", 100);
       set("max_neili", 1600);
       set("neili", 3000);

	create_family("火云洞", 2, "蓝");

        setup();
initlvl((500+random(500)),52);
	carry_object("/d/qujing/bibotan/obj/moonstaff")->wield();
        carry_object("/d/qujing/bibotan/obj/zhanpao")->wear();
}

