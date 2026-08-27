/* Baldrick: Added stat modifier for extreme strength */

inherit "/std/guild";

int query_skill_cost(string skill)
{
 return 0;  /* Need a list of possible skills first.  Awaiting Dank */
}

void setup() 
  {
  set_name("defensores de gaia");
  set_short("Defensores de gaia");
  set_long("Los defensores de gaia odian cualquier tipo de utensilio cortante, y destruiran a todo aquel que los porte, "+
	"por ser una amenaza en potencia para su raza.");
  reset_get();
  add_guild_command("juzgar", 1);
  add_guild_command("centrar", 1);
  add_guild_command("fix", 1);
  add_guild_command("slice",1); //-> por quest!
  //add_guild_command("twirl",1); -> por quest! de momento rula bugeado
  // y... es una dopada, no creo que se ponga jamas.
//  add_guild_command("esconderse",1);
//  add_guild_command("sigilar", 1);
//  add_guild_command("globooscuro", 1);
//  add_guild_command("fuegofatuo", 1);
	// jiasjias, el surge se supone ke es de wdrow xDDD
	add_guild_command("acelerarse", 1);
}

void create()
  {
  ::create();
  set_main_skill("str");
}

string query_main_skill() {return "str";}
int query_advance_cost() { return  500; }
int query_xp_cost()      { return 2000; }
//int query_dice()         { return 10;   }
int query_hp_dice(object myp) { return 7;   }
int query_hp_min(object myp)  { return 10;   }
int query_gp_dice(object myp) { return 5;   }
int query_gp_min(object myp)  { return 6;   }

int query_legal_race(string race) {
	switch(race) {
		case "ent":
		case "Inmortal":
			return 1;
		default:
			return 0;
	}
}

int query_thac0_step()   { return 2;    }
int query_extr_str()    { return 1;    }
int query_bing()    { return 1;    }
int query_extra_con_bonus() { return 1; }

/*
void set_gp(object ob)
{ 
  ob->set_max_gp(level+(((int)ob->query_str()+(int)ob->query_con())/2));
}

void set_hp(object ob)
{ 
 int lvl;
 lvl = (int)ob->query_level();
 ob->set_max_hp(query_dice()*lvl);
 }
*/

int query_legal_armour(string ignore) { return 1; }
int query_legal_weapon(string ignore) { return 1; }

int query_dual_wield_penalty(object me, object w1, object w2)
{
  int bon;

  bon = 50 - (int)me->query_level()*1.8;
  bon = ( bon<0 ? 0 : bon );

  return bon;
}

void on_death(object player, object killer) {
}

string query_title(object ob) {
	if (ob->query_gender() == 1) {
		switch(ob->query_level()) {
			case 0..10:
				return "Semilla de la vida";
			case 11..15:
				return "titulo 11-15";
			case 16..20:
				return "titulo 16-20";
			case 21..25:
				return "titulo 21-25";
			case 26..30:
				return "titulo 26-30";
			case 31..35:
				return "titulo 31-35";
			case 36..40:
				return "titulo 36-40";
			case 41..45:
				return "titulo 41-45";
			case 46..50:
				return "titulo 46-50";
			case 51..1000:
				return "%^BOLD%^%^RED%^titulo 51 en adelante%^RESET%^";
			default:
				return "Defensor de Gaia Erroneo";
		}
	}
	else {
		switch(ob->query_level()) {
			case 0..10:
				return "Estudiosa de las Artes del Combate";
			case 11..15:
				return "Guerrera de la Patrulla de la Suboscuridad";
			case 16..20:
				return "Lider de la Patrulla de la Suboscuridad";
			case 21..25:
				return "Guerrera Drow";
			case 26..30:
				return "Guerrera de la Dama Oscura";
			case 31..35:
				return "Lady de la Guerra de la Dama Oscura";
			case 36..40:
				return "Protectora de la Dama Oscura";
			case 41..45:
				return "Lider de los Guerreros Drow";
			case 46..50:
				return "Brazo Ejecutor de la Dama Oscura";
			case 51..55:
				return "%^BOLD%^%^BLACK%^Slicer %^RESET%^de la %^BOLD%^%^RED%^Muerte%^RESET%^";
			case 56..60:
				return "%^BOLD%^Lider %^RESET%^de los %^BOLD%^%^BLACK%^Slicers %^RESET%^de la %^BOLD%^%^RED%^Muerte%^RESET%^";
			case 61..1000:
				return "%^BOLD%^%^RED%^Despiadada %^WHITE%^Maestra de Armas de la %^BLACK%^Suboscuridad%^RESET%^";
			default:
				return "Guerrera Drow Erronea";
		}
	}
}
