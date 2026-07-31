inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
        set_name("ĞÓÏÉ", ({"xing xian", "xian"}));
        set("long",
"ËıÇà×Ë×°ôä´ä£¬µ¤Á³ÈüëÙÖ¬£¬ĞÇÑÛ¹â»¹²Ê£¬¶êÃ¼ĞãÓÖÆë¡£\n");
        set("age", 20);
	set("attitude", "friendly");
        set("gender", "Å®ĞÔ");
	set("class", "yaomo");
	set("nickname", "ÌìÌ¨æ§¼§");
        set("str", 20);
        set("int", 20);
        set("per", 30);
        set("con", 20);
        set("max_qi",900);
        set("max_jing", 900);
        set("combat_exp", 400000);
  set("combat_exp", 42000000);


	set("eff_dx", -150000);
        set("nkgain", 400);

        set("neili", 500);
        set("max_neili", 500);
        set("neili",400);
        set("max_neili", 400);
        set("force_factor", 40);
        set("mana_factor", 30);
        set_skill("unarmed", 100);
        set_skill("force", 100);
        set_skill("dodge", 100);
	set_skill("sword", 100);

        setup();
initlvl((550+random(550)),46);       
	carry_object("/d/qujing/jingjiling/obj/xingzhi")->wield();
	carry_object("/d/qujing/jingjiling/obj/armor")->wear();
	carry_object("/d/obj/cloth/pinkskirt")->wear();
}
