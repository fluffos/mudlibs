inherit NPC;
string *first_name = ({ "Çà÷­", "³àÀð", "»Æöð", "°×öè", "×Ïöë", "½ð÷¡",
"ÒøòÃ", "ÎÚöú"});
string *name_words = ({ "Á¦Ê¿"});

void create()
{
	string name;
	name = first_name[random(sizeof(first_name))];
	name += name_words[random(sizeof(name_words))];

       set_name(name, ({"li shi", "shi"}));
       set("gender", "ÄÐÐÔ");
	set("title", "¹¬Ç°»¤ÎÀ");
       set("age", 20+random(5));
	set("per", 10);
	set("str", 25);
       set("attitude", "heroism");
       set("shen_type", 1);
        set("combat_exp", 100000);
  set("daoxing", 20000);

        set_skill("parry", 70);
        set_skill("dodge", 70);

	set("force", 200);
	set("max_force", 200);
        set("force_factor",15);
	set("mana", 100);
	set("max_mana", 100);
	set("mana_factor", 10);
	set("max_kee", 800);
	set("max_sen", 400);
        setup();
        carry_object("/d/obj/armor/tiejia")->wear();
	carry_object("/d/obj/weapon/fork/fork")->wield();
}
