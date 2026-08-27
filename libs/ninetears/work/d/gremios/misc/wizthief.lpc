inherit "/std/guild";

int query_skill_cost(string skill) {
    return 6;
}

void setup() {
    set_name("wizthief");
    set_short("Mago Ladron");
    set_long(
      "Los Magos Ladrones son una evolucion (o una degeneracion, segun a "
      "quien se pregunte) de los magos, que, por oscuros motivos, centraron "
      "parte de sus estudios en el perfeccionamiento de las artes del "
      "sigilo y la pilleria. Posee grandes habilidades magicas orientadas "
      "a estos aspectos, lo que los convierte en unos personajes escurridizos "
      "e incluso peligrosos.\n");
    reset_get();
    add_guild_command("esconderse", 1);
    add_guild_command("robar", 1);
    add_guild_command("apunyalar", 1);
    add_guild_command("sigilar", 1);
    add_guild_command("fix", 1);
}

void create()
{
    ::create();
} /* setup() */

string query_main_skill() {return "int";}
int query_advance_cost() { return 2000; }
int query_xp_cost()      { return 2500; }
//int query_dice()         { return 8;    }
int query_hp_dice(object myp)	{ return 4; }
int query_hp_min(object myp)	{ return 3; }
int query_gp_dice(object myp)	{ return 5; }
int query_gp_min(object myp)    { return 9; }
int query_thac0_step() {return 2;}

int query_legal_race(string race) {
    switch(race) {
    case "elfo":
    case "drow":
    case "humano":
    case "gnomo":
    case "inmortal":
  return 1;
    default: return 0;
    }

}

string query_spell_directory() { return "/d/gremios/hechizos/wizthief/"; }
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
   if (player->query_mirror_spell())
           player->destruct_mirror_shadow();
}

string query_title(object ob) {
	if (ob->query_gender() == 1) {
		switch(ob->query_level()) {
                        case 0..10:
                                return "Aprendiz del Ocultismo";
                        case 11..17:
                                return "Ocultista";
                        case 18..31:
                                return "Sombra Mistica";
                        case 32..50:
                                return "Resplandor Arcano de la Noche";
                        case 51..1000:
                                return "Gran Hechicero de la Ilusion y el Ocultismo";
			default:
                                return "Mago Ladron Erroneo";
		}
	}
	else {
		switch(ob->query_level()) {
                        case 0..10:
                                return "Aprendiz del Ocultismo";
                        case 11..17:
                                return "Ocultista";
                        case 18..31:
                                return "Sombra Mistica";
                        case 32..50:
                                return "Resplandor Arcano de la Noche";
                        case 51..1000:
                                return "Gran Hechicera de la Ilusion y el Ocultismo";
                        default:
                                return "Mago Ladron Erroneo";
		}
	}
}
