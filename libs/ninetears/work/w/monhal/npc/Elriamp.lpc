
inherit "/obj/monster";

void setup() {
      set_name("Elriamp");
      set_short("Elriamp");
      set_al(60);
      set_main_plural("Elriamp");
      add_alias("Elriamp");
      set_race("elf");
	set_gender(1);
      set_level(40+random(10));
      set_wimpy(0);
	set_max_hp(query_level() * 10 + 1000);
	set_hp(query_max_hp());
	set_max_gp(1000);
	set_gp(1000);
      set_random_stats(20, 22);
      set_long("Elriamp es un elfo borrracho que mata su tiempo defendiendo.\n\n"
		"este camino, yo de ti no me meteria con el.\n\n");
      adjust_money(random(500), "silver");
//      set_aggressive(0);
	new("/baseobs/weapons/bastard_sword")->move(this_object());
	new("/baseobs/weapons/broad_sword")->move(this_object());
	new("/baseobs/armours/fullplate")->move(this_object());
	this_object()->init_equip();
      load_chat(20,
         ({
               1, "'No te han ensenyado a no molestar a los borrachos!",
               1, ":te mira mientras da algunos tumbos.",
//               1, "@grin evilly $lname$",
               1, ":da un trago de la botella!!!!.",
               1, "'El vinOooOo que tiene AsuncioOooOOn!",
               1, "'Hip Hip",
          }));
      load_a_chat(40,
         ({
               1, "'Nadie osa perturbar la paz de un borracho!",
               1, ":te mira con los ojos inyectados en alcohol.",
//               1, "@grin evilly $lname$",
               1, "'CUNYAOOOOOOOOO!!!",
          }));
	set_guild("warriors/slicerelfo");
	set_guild_ob("/d/gremios/guerreros/slicerelfo");
	add_attack_spell(70, "acelerarse", ({"/d/gremios/comandos/surge", "surge",0,0}));
	add_attack_spell(100, "cazar", ({"/d/gremios/comandos/hunt", "hunt",0,0}));
	add_property("NO_BUDGE", 1); // para q ningun hechizo lo haga marcharse de aki

}

int already_attacking(object me,object victim);

void event_enter(object enterer, string message)
{
		string msg;
	int lvl, luchando = 0;

	if (!enterer) 
		return;

	if (enterer->query_dead())
		return;

	if (already_attacking(this_object(), enterer)) {
		if (!this_object()->query_dead()) {
			if (!random(2))
				command("say Pagaras tu osadia con una paliza Hip!\n");
			else
				command("say Maldito necio , estas muerto Juas Juas!\n");
		}
		return;
	}

	

	/*
	if (query_fighting()) { no saludamos y advertimos al que entra
		tell_object(enterer, "Observas a Elriamp altamente excitado. %^BOLD%^%^RED%^Podria atacarte a ti inmerso en su furia!%^RESET%^\n");
		return;
	

int already_attacking(object me,object victim){
   if(member_array(me,victim->query_attacker_list()) != -1)
      return 1;
   if(member_array(me,victim->query_call_outed()) != -1) 
      return 1; }