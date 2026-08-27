inherit "/std/guild";

int query_skill_cost(string skill) {
    return 6;  /* Need a list of possible skills first.  Awaiting Dank */
}

void setup() {
    set_name("asesino");
    set_short("Asesino");
    set_long(
      "Los Asesinos son los maestros de la sorpresa, atacan salvajemente "
      "con extrema precision a su victima pillandola desprevenida. No "
      "tienen ningun tipo de problemas de conciencia a la hora de efectuar "
      "su trabajo, por lo que son frios, calculadores y muy escurridizos. "
      "Dependen de su destreza mental y fisica para sobrevivir.\n");
    reset_get();
    add_guild_command("esconderse", 1);
    add_guild_command("emboscar", 1);
// el apunyalar necesita trabajo, el emboscar necesita revision o mas xD!
//    add_guild_command("apunyalar", 1);
    add_guild_command("sigilar", 1);
    // add_guild_command("rastrear", 1); bugs de muchas shadows y mas
    add_guild_command("decapitar", 1);
    add_guild_command("fix", 1);
// chu =)
}

void create()
{
    ::create();
    set_main_skill("dex");
} /* setup() */

string query_main_skill() {return "dex";}
int query_advance_cost() { return  1000; }
int query_xp_cost()      { return 1250; }
//int query_dice()         { return 8;    }
int query_hp_dice(object myp)	{ return 3; }
int query_hp_min(object myp)	{ return 3; }
int query_gp_dice(object myp)	{ return 5; }
int query_gp_min(object myp)	{ return 7; }
int query_thac0_step() {return 3;}

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
	return 0;
    default : return 1;
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
				return "Emboscador";
			case 11..15:
				return "Bandolero de los Bosques";
			case 16..20:
				return "Destripador";
			case 21..25:
				return "Estratega del Silencio";
			case 26..30:
				return "Senyor del Silencio";
			case 31..35:
				return "Maestro del Silencio";
			case 36..40:
				return "Sombra Letal";
			case 41..45:
				return "Aliento Cadaverico";
			case 46..50:
				return "Mensajero de la Muerte";
			case 51..55:
				return "%^BOLD%^Purificador %^RESET%^de %^BOLD%^%^CYAN%^Almas%^RESET%^";
			case 56..60:
				return "%^BOLD%^%^YELLOW%^Protegido %^RESET%^del %^BOLD%^%^RED%^Abismo%^RESET%^";
			case 61..1000:
				return "%^BOLD%^Senyor %^RESET%^del %^BOLD%^%^RED%^Abismo%^RESET%^";
			default:
				return "Asesino Erroneo";
		}
	}
	else {
		switch(ob->query_level()) {
			case 0..10:
				return "Emboscadora";
			case 11..15:
				return "Bandolera de los Bosques";
			case 16..20:
				return "Destripadora";
			case 21..25:
				return "Estratega del Silencio";
			case 26..30:
				return "Senyora del Silencio";
			case 31..35:
				return "Maestra del Silencio";
			case 36..40:
				return "Sombra Letal";
			case 41..45:
				return "Aliento Cadaverico";
			case 46..50:
				return "Mensajera de la Muerte";
			case 51..55:
				return "%^BOLD%^Purificadora %^RESET%^de %^BOLD%^%^CYAN%^Almas%^RESET%^";
			case 56..60:
				return "%^BOLD%^%^YELLOW%^Protegida %^RESET%^del %^BOLD%^%^RED%^Abismo%^RESET%^";
			case 61..1000:
				return "%^BOLD%^Senyora %^RESET%^del %^BOLD%^%^RED%^Abismo%^RESET%^";
			default:
				return "Asesina Erronea";
		}
	}
}
