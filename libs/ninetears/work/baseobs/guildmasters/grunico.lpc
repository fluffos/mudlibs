// Arturin

inherit "/obj/monster";

#define MURO "/d/gremios/hechizos/mg/muro_ilusorio"

void attack_by(object ob)
{
	object *obs = find_match("patric", ETO);
	
	if (sizeof(obs))
		obs[0]->attack_ob(ob);
	
	::attack_by(ob);
}

void setup() {
      set_name("caballero");
      set_short("Caballero Runico");
      set_al(60);
      set_main_plural("Caballeros Runicos");
      add_alias("runico");
      set_race("human");
	set_language("common");
	set_gender(1);
      set_level(15+random(10));
      set_wimpy(0);
	set_max_hp(query_level() * 10 + 200);
	set_hp(query_max_hp());
	set_max_gp(1000);
	set_gp(1000);
      set_random_stats(20, 22);
      set_long("Caballero Runico.\n\n"
		"Un resplandor le cubre la cara. Se trata de un "
		"humano de talla media contratado por Patric para "
		"ayudar a defender su gremio.\n\n");
      adjust_money(random(10), "gold");
//      set_aggressive(0);
	new("/baseobs/weapons/daga_oxidada")->move(this_object());
	new("/baseobs/weapons/daga_oxidada")->move(this_object());
	new("/baseobs/armours/leather")->move(this_object());
	this_object()->init_equip();
      load_chat(20,
         ({
               1, ":esta atento a todo.",
               1, ":repasa algunos de sus hechizos.",
//               1, "@grin evilly $lname$",
//               1, ":se relame de gusto.",
//               1, "'Sexo, Drogas y Rockn'roll, y si eso no es posible, Muerte!",
//               1, "'Que vengan los drows, que vengan...",
          }));
      load_a_chat(40,
         ({
               1, "'Ahora sabreis para que me han contratado!",
//               1, ":te mira con los ojos inyectados en sangre.",
//               1, "@grin evilly $lname$",
//               1, "'JERONIMOOOOO!!!",
          }));
//	set_guild("mago guerrero");
	set_guild_ob("/d/gremios/misc/wizwar");
	add_attack_spell(70, "proyectil magico mayor", ({"/d/gremios/hechizos/mago/proyectil_magico_mayor", "cast_spell",0,0}));
	add_attack_spell(20, "desintegrar", ({"/d/gremios/hechizos/mg/desintegrar", "cast_spell",0,0}));
	add_attack_spell(40, "cono de frio", ({"/d/gremios/hechizos/mago/cono_frio", "cast_spell",0,0}));
	set_heart_beat(1);
}

int already_attacking(object me,object victim);

void event_enter(object enterer, string message)
{
	/* BUG, HAY Q LLAMAR A ::event_enter al finalizar cada return */
	string msg;
	int lvl, luchando = 0;

	if (!enterer) // la documentacion dice q hay q mirar esto
		return;

	if (enterer->query_dead())
		return;

	if (enterer->query_guild_name() == "caballero de jade") {
		call_out("murito", 0, 1);
	}

}

void murito()
{
		if (TO->query_property("murito_hecho"))
			return;
		MURO->cast_spell("sudeste", TO, 0);
		TO->ATP("murito_hecho", 1, 100);
}

// sacado de /d/gremios/comandos/base_command.c y modificado

int already_attacking(object me,object victim){
   if(member_array(me,victim->query_attacker_list()) != -1)
      return 1;
   if(member_array(me,victim->query_call_outed()) != -1) 
      return 1;
   return 0;
}

/*
void heart_beat()
{
	if (!TO->query_mirror_spell())
		if (!TO->query_spell_effect("spell"))
		ESPEJISMO->cast_spell(query_short(), this_object(), 0);
	::heart_beat();
}
*/
