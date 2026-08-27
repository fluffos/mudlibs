inherit "/std/guild";

int query_skill_cost(string skill) {
    return 6;  /* Need a list of possible skills first.  Awaiting Dank */
}

void setup() {
    set_name("ladron");
    set_short("ladron");
    set_long(
      "Los Asesinos son los maestros de la sorpresa, atacan salvajemente "
      "con extrema precision a su victima pillandola desprevenida. No "
      "tienen ningun tipo de problemas de conciencia a la hora de efectuar "
      "su trabajo, por lo que son frios, calculadores y muy escurridizos. "
      "Dependen de su destreza mental y fisica para sobrevivir.\n");
    reset_get();
    add_guild_command("esconderse", 1);
    add_guild_command("robar", 1);
    add_guild_command("apunyalar", 1);
    add_guild_command("sigilar", 1);
    add_guild_command("desaparecer", 1);
    // add_guild_command("rastrear", 1); bugs de muchas shadows y mas
    // add_guild_command("decapitar", 1);
	// vamos a guardar para un poco mas adelante el comando
	// para "noquear" como diria un khazad...
	// el "aturdir" no debera ser instant, sera tipo miambush...
    add_guild_command("aturdir", 1);
    add_guild_command("fix", 1);
}

void create()
{
    ::create();
    set_main_skill("dex");
} /* setup() */

string query_main_skill() {return "dex";}
int query_advance_cost() { return 1000; }
int query_xp_cost()      { return 1000; }
//int query_dice()         { return 8;    }
int query_hp_dice(object myp)	{ return 4; }
int query_hp_min(object myp)	{ return 3; }
int query_gp_dice(object myp)	{ return 5; }
int query_gp_min(object myp)	{ return 7; }
int query_thac0_step() {return 2;}

int query_legal_race(string race) {
    return 1;
}

int query_legal_armour(string type)
{
    switch(type)
    {
    case "leather":
    case "padded leather":
    case "padded":
    case "elfin chain":
    case "basinet":
    case "shoes":
    case "slippers":
    case "boots":
    case "amulet":
    case "pendant":
    case "necklace":
    case "cape":
    case "cloak":
    case "ring":
    case "belt":
	return 1;
    default: return 0;
    }
}

int query_legal_weapon(string type)
{
    switch(type)
    {
    case "polearm":
    case "two-handed sword":
    case "bow":
    case "lance":
    case "mace":
    case "maza":
	case "daga":
    case "dagger":
	case "bastard sword":
	return 1;
    default : return 0;
    }
}

void check_stab(object ob) {
    if (ob && random(4))
	call_out("do_it", 0, ob);
} /* check_stab() */

void do_it(object ob) {
    if (ob)
	do_command("backstab", ob->query_name());
} /* do_it() */

/*
void set_gp(object ob) {
  ob->set_max_gp(level+(int)ob->query_dex());
}

void set_hp(object ob) {
  ob->set_max_hp(query_dice()  *(level +1));
}
*/

int query_dual_wield_penalty(object me, object w1, object w2)
{
    int bon;

    if ( w1->query_attack_type() != 3 || w2->query_attack_type() != 3 )
	return 50;

    bon = 50 - (int)me->query_level()*3/2;
    bon = ( bon<10 ? 10 : bon );

    return bon;
}

void on_death(object player, object killer) {
}

string query_title(object ob) {
	if (ob->query_gender() == 1) {
		switch(ob->query_level()) {
			case 0..10:
				return "Aprendiz de Ladron";
			case 11..15:
				return "Mangui";
			case 16..20:
				return "Chorizo";
			case 21..25:
				return "Asaltador de Caminos";
			case 26..30:
				return "Gato de los Tejados";
			case 31..35:
				return "Sombra de la Oscuridad";
			case 36..40:
				return "Sombra de la Noche";
			case 41..45:
				return "Ladron de Guante Blanco";
			case 46..50:
				return "Senyor de lo Ajeno";
			case 51..55:
			case 56..60:
			case 61..1000:
				return "%^BOLD%^Esp%^BLACK%^i%^WHITE%^a %^RESET%^de la %^BOLD%^%^CYAN%^Cofrad%^GREEN%^i%^CYAN%^a%^RESET%^";
			default:
				return "Ladron Erroneo";
		}
	}
	else {
		switch(ob->query_level()) {
			case 0..10:
				return "Aprendiz de Ladron";
			case 11..15:
				return "Mangui";
			case 16..20:
				return "Chorizo";
			case 21..25:
				return "Asaltadora de Caminos";
			case 26..30:
				return "Gata de los Tejados";
			case 31..35:
				return "Sombra de la Oscuridad";
			case 36..40:
				return "Sombra de la Noche";
			case 41..45:
				return "Ladrona de Guante Blanco";
			case 46..50:
				return "Senyora de lo Ajeno";
			case 51..55:
			case 56..60:
			case 61..1000:
				return "%^BOLD%^Esp%^BLACK%^i%^WHITE%^a %^RESET%^de la %^BOLD%^%^CYAN%^Cofrad%^GREEN%^i%^CYAN%^a%^RESET%^";
			default:
				return "Ladrona Erronea";
		}
	}
}
