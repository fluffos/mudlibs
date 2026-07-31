inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
       	set_name("ÁèÐé×Ó", ({"lingxu zi", "zi"}));
       	set("gender", "ÄÐÐÔ");
       	set("age", 30);
        set("long", "Ò»¸öÉí¸ß±Û³¤µÄµÀÊ¿£¬ÈÝÃ²»¹¿´µÄ¹ýÈ¥¡£
¿É×ÐÏ¸Ò»ÇÆ£¬¾±ÖÐ¾¹³¤×ÅÃÜÃÜÂéÂéµÄ³¤Ã«¡£\n");
       	set("attitude", "heroism");
	set("class", "yaomo");
	set("bellicosity", 800);
       	set("per", 18);
	set("looking", "ÏàÃ²Ð×¶ñ£¬ÂúÁ³ºáÈâ¡£");
	set("str", 25);
       	set("combat_exp", 120000);
  set("combat_exp", 41200000);

        set_skill("unarmed", 75);
        set_skill("dodge", 75);
        set_skill("blade", 75);
        set_skill("parry", 75);

        set("neili", 700);
        set("max_neili", 700);
        set("force_factor", 30);
        set("max_qi", 800);
        set("max_jing", 800);
        set("max_neili", 300);
        set("neili", 300);
	set("mana_factor", 20);
	set("eff_dx", -50000);
	set("nkgain", 300);
	set_temp("apply/armor", 25);
	setup();
	initlvl((500+random(500)),41);
	carry_object("/d/obj/cloth/changpao")->wear();
	carry_object("/d/qujing/jisaiguo/obj/panzi");
}


ÿ