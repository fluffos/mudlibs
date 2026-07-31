inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
        set_name("赤身鬼使", ({"guard"}));
        set("long", "一个青面獠牙的红须赤身鬼使。\n");
        set("age", 30);
	set("attitude", "heroism");
        set("gender", "男性");
        set("str", 25);
        set("int", 20);
        set("per", 10);
        set("con", 30);
        set("max_qi",800);
        set("max_jing", 800);
        set("combat_exp", 100000);
  set("combat_exp", 100000);

        set("neili", 500);
        set("max_neili", 500);

        setup();
initlvl((550+random(550)),45);       
	carry_object("/d/obj/weapon/fork/gangcha")->wield();
}
