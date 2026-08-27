inherit "/std/guild";

string help()
{
    return "Los Paladines son los nobles artesanos de la lucha entre caballeros, "
           "su vida la dedican a proteger a los indefensos y ayudar a los desvalidos. "
           "En este gremio aprendes a formular conjuros protectores ya que los Lores "
           "tienen algunos poderes de Clerigo y saben luchar como el mas poderoso "
           "guerrero, pueden usar toda clase de armas y armaduras.\n";
    reset_get();
}

string query_main_skill() { return "wis"; }

int query_skill_cost(string skill)
{
    return 0;
}

void setup()
{
//    ::setup(); ??
    set_name("clerigo de gestur");
    set_short("Clerigo de Gestur");
    set_long("Los Paladines son los nobles artesanos de la lucha entre caballeros, "
             "su vida la dedican a proteger a los indefensos y ayudar a los desvalidos. "
             "En este gremio aprendes a formular conjuros protectores ya que los Lores "
             "tienen algunos poderes de Clerigo y saben luchar como el mas poderoso "
             "guerrero, pueden usar toda clase de armas y armaduras.\n");
    reset_get();

  add_guild_command("juzgar", 1);
  add_guild_command("fix", 1);
  add_guild_command("repeler", 1);
}

//int query_dice()         { return 12;   }
int query_hp_dice(object myp) { return 4;   }
int query_hp_min(object myp)  { return 6;   }
int query_gp_dice(object myp) { return 5;   }
int query_gp_min(object myp)  { return 8;   }
int query_thac0_step()   { return 3;    }
// int query_extr_str()    { return 1;    }
// int query_bing()    { return 1;    } pa ke esto?
// int query_extra_con_bonus() { return 1; }

int query_advance_cost() { return 1600; }

string query_spell_directory() { return "/d/gremios/hechizos/clerigos/gestur/"; }

int query_xp_cost() { return 1600; }

int query_legal_race(string race)
{
    switch(race)
    {
    case "Enano":
	case "enano":
	case "Humano":
	case "humano":
	case "duergar":
	case "Duergar":
	case "Medio-elfo":
	case "medio-elfo":
    case "Immortal":
    case "Inmortal":
	return 1;
    default:
	return 0;
    }
}


/*mixed query_legal_spheres()
{
    return ({ ({"paladin","mayor"}),
              ({"proteccion","mayor"}),
              ({"proteccion","menor"}),
              ({"resistencia","neutral"}),
              ({"tiempo","neutral"}),
             
           });
}*/

int query_legal_armour(string ignore) { return 1; }
int query_legal_weapon(string ignore) { return 1; }

int query_dual_wield_penalty(object me, object w1, object w2)
{
  int bon;

  bon = 50 - (int)me->query_level();
  bon = ( bon<0 ? 0 : bon );

  return bon;
}

void on_death(object player, object killer) {
}

string query_title(object ob) {
	if (ob->query_gender() == 1) {
		switch(ob->query_level()) {
			case 0..10:
				return "Novicio";
			case 11..15:
				return "Pequenyo Clerigo Iniciado";
			case 16..20:
				return "Joven Clerigo";
			case 21..25:
				return "Clerigo de la Batalla";
			case 26..30:
				return "Sacerdote de la Batalla";
			case 31..35:
				return "Sacerdote de la Guerra";
			case 36..40:
				return "Sacerdote del Fuego";
			case 41..45:
				return "Obispo del Fuego";
			case 46..50:
				return "Azote de los Infieles";
			case 51..55:
			case 56..60:
			case 61..1000:
				return "%^BOLD%^%^BLACK%^Torquemada %^RESET%^del %^BOLD%^F%^YELLOW%^u%^RED%^e%^RESET%^%^RED%^g%^BLUE%^o%^RESET%^";
			default:
				return "Gestur Erroneo";
		}
	}
	else {
		switch(ob->query_level()) {
			case 0..10:
				return "Novicia";
			case 11..15:
				return "Pequenya Cleriga Iniciada";
			case 16..20:
				return "Joven Cleriga";
			case 21..25:
				return "Cleriga de la Batalla";
			case 26..30:
				return "Sacerdotisa de la Batalla";
			case 31..35:
				return "Sacerdotisa de la Guerra";
			case 36..40:
				return "Sacerdotisa del Fuego";
			case 41..45:
				return "Alta Sacerdotisa del Fuego";
			case 46..50:
				return "Azote de los Infieles";
			case 51..55:
			case 56..60:
			case 61..1000:
				return "%^BOLD%^%^BLACK%^Torquemada %^RESET%^del %^BOLD%^F%^YELLOW%^u%^RED%^e%^RESET%^%^RED%^g%^BLUE%^o%^RESET%^";
			default:
				return "Gestur Erroneo";
		}
	}
}
