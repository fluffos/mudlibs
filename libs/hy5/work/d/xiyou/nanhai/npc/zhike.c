//Cracked by Roath
// zhike.c Öª¿ÍÉ®º
// By Dream Dec. 20, 1996

inherit NPC;

void create()
{
	set_name("Öª¿ÍÉ®", ({ "zhike seng", "seng" }));
	set("long", "Ò»Î»ÄêÇáµÄÉ®ÈË£¬Á³ÉÏ×ÜÊÇ´ø×ÅÈÈÇéµÄĞ¦Èİ¡£\nËû¸ºÔğÔÚ´ËÓ­½ÓÇ°À´²Îìø½øÏãµÄ¿ÍÈË¡£\n");
	set("gender", "ÄĞĞÔ");
	set("age", 25);
	set("attitude", "peaceful");
	set("class", "bonze");
	set("max_kee", 200);
	set("max_gin", 200);
	set("max_sen", 200);
	set("force", 100);
	set("max_force", 100);
	set("force_factor", 10);
	set("max_mana", 100);
	set("mana", 100);
	set("mana_factor", 10);
	set("combat_exp", 5000);
	set("daoxing", 10000);



        create_family("ÄÏº£ÆÕÍÓÉ½", 4, "µÜ×Ó");
	
	setup();
              add_money("silver", 8); 
	carry_object("/d/xiyou/nanhai/obj/sengpao")->wear();
}

