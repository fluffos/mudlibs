inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
        set_name("¹Å²¨¶ùÎ÷", ({"guboer xi", "xi"}));
        set("long", "ËûÊÇÂÒÊ¯É½±Ì²¨Ì¶µÄÀÏ±î¾«¡£\n");
        set("age", 30);
	set("title", "µîÇ°ÓÒÊ¹");
        set("attitude", "peaceful");
        set("gender", "ÄÐÐÔ");
	set("class", "yaomo");
        set("str", 20);
        set("int", 20);
        set("per", 10);
        set("con", 30);
        set("max_qi",500);
        set("max_jing", 500);
        set("combat_exp", 45000);
  set("combat_exp", 60000);

        set("eff_dx", 20000);
        set("nkgain", 250);


        setup();
        initlvl((500+random(500)),53);
        carry_object("/d/obj/armor/tenjia")->wear();
	carry_object("/d/obj/weapon/fork/gangcha")->wield();
}

ÿ