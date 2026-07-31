inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
        set_name("西波儿古", ({"xiboer gu", "gu"}));
        set("long", "他是乱石山碧波潭的老龟精。\n");
        set("age", 30);
	set("title", "殿前左使");
        set("attitude", "heroism");
	set("class", "yaomo");
        set("gender", "男性");
        set("str", 20);
        set("int", 20);
        set("per", 10);
        set("con", 30);
        set("max_qi",500);
        set("max_jing", 500);
        set("combat_exp", 50000);
  set("combat_exp", 10000);

        set("eff_dx", -20000);
        set("nkgain", 250);

        set("neili", 200);
        set("max_neili", 200);
        set("neili", 200);
      
        setup();
initlvl((500+random(500)),53);        
        carry_object("/d/obj/armor/tenjia")->wear();
	carry_object("/d/obj/weapon/fork/gangcha")->wield();
}

