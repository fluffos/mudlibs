inherit "/std/guild";

#define SPELL_TABLE "/table/spell_table"

int query_skill_cost(string skill)
{
    return 6;
}

void setup()
{
    set_name("mago guerrero");
    set_short("Mago Guerrero");
    set_long(
      "Mages are the most powerful magic-users on "
      "Magisk Jord.  Their power lays in quickness of thought "
      "and powerful spells rather than hand to hand fighting "
      "ability.  They favor the power of  the Arcane and have "
      "no desire for the 'barbaric' forms of combat.\n"); 
    reset_get();
	add_guild_command("fix", 1);
	add_guild_command("reclamar", 1);
	add_guild_command("meditar", 1);
}
void create()
{
    ::create();
    set_main_skill("int");
}

int query_advance_cost() { return  500; }
int query_xp_cost()      { return 3500; }
//int query_dice()         { return 6;    }
int query_hp_dice(object myp) { return 3; }
int query_hp_min(object myp) { return 5; }
int query_gp_dice(object myp) { return 6; }
int query_gp_min(object myp) { return 15; }
int query_thac0_step()   { return 4;    }
string query_main_skill() {return "int";}

int query_legal_race(string race) {
    switch(race) {
    case "elfo":
    case "drow":
    case "humano":
	return 1;
    default       :return 0;
    }
}

string query_spell_directory() { return "/d/gremios/hechizos/mago/"; }

int query_legal_weapon(string type)
{
    /*switch(type)
    {
    case "dagger":
    case "dirk":
    case "dart":
    case "quarterstaff":
    case "staff":
    case "sling":
    case "knife":
	return 1;
    default: return 1;
    }*/
	return 1;
}

int query_legal_armour(string type)
{
    /*switch(type)
    {
    case "robe":
    case "boots":
    case "shoes":
    case "bracers":
    case "cloak":
    case "ring":
    case "amulet":
    case "pendant":
    case "necklace":
    case "cape":
    case "slippers":
    case "leather":
    case "belt":
	return 1;
    default:
	return 1;
    }*/
	return 1;
}

int query_dual_wield_penalty(object me, object w1, object w2)
{ // arreglar
    return 30;
}

/*
void set_gp(object ob)
{ ob->set_max_gp(level+(int)ob->query_int()); }

void set_hp(object ob)
{ ob->set_max_hp(query_dice()*level); }
int query_see_magic()
{
  return 1;
} 
*/
void on_death(object player, object killer) {
}

// int query_bing()    { return 1;    } PA KE KONIO ES ESTO? ORIGINALMENTE NO VENIA, ESTA COGIDO DE GREMIO GUERRERO

string query_title(object ob) {
	if (ob->query_gender() == 1) {
		switch(ob->query_level()) {
			case 0..10:
				return "Hidalgo de las Runas";
			case 11..15:
				return "Escudero de las Runas";
			case 16..20:
				return "Guerrero de las Runas";
			case 21..25:
				return "Guardian de las Runas";
			case 26..30:
				return "Lord Arcano de las Runas";
			case 31..35:
				return "Maestro del Circulo Interno";
			case 36..40:
				return "Senyor del Circulo Interno";
			case 41..45:
				return "Senyor Supremo del Circulo Interno";
			case 46..50:
				return "Regente del Circulo Interno";
			case 51..55:
				return "%^BOLD%^%^RED%^Alto Senyor de la %^BLACK%^Magia Runica%^RESET%^";
			case 56..60:
				return "%^BOLD%^Mago Guerrero Power%^RESET%^";
			case 61..1000:
				return "%^BOLD%^Mago Guerrero Power%^RESET%^";
			default:
				return "Mago Guerrero Erroneo";
		}
	}
	else {
		switch(ob->query_level()) {
			case 0..10:
				return "Plebeya de las Runas";
			case 11..15:
				return "Escudera de las Runas";
			case 16..20:
				return "Guerrera de las Runas";
			case 21..25:
				return "Guardiana de las Runas";
			case 26..30:
				return "Lady Arcana de las Runas";
			case 31..35:
				return "Maestra del Circulo Interno";
			case 36..40:
				return "Lady del Circulo Interno";
			case 41..45:
				return "Lady Suprema del Circulo Interno";
			case 46..50:
				return "Regente del Circulo Interno";
			case 51..55:
				return "%^BOLD%^%^RED%^Alta Lady de la %^BLACK%^Magia Runica%^RESET%^";
			case 56..60:
				return "%^BOLD%^Maga Guerrera Power%^RESET%^";
			case 61..1000:
				return "%^BOLD%^Maga Guerrera Power%^RESET%^";
			default:
				return "Maga Guerrera Erronea";
		}
	}
}
