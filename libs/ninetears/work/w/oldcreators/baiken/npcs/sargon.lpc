//Rutseg 5-XII-2001

#include "../path.h"
inherit "obj/monster";

void setup()
{
	set_name("sargon");
	set_short("Sargon, maestro edhil de la espada");
	add_alias("sargon");
	add_alias("maestro");
	add_alias("elfo");
	add_plural("elfos");
	set_main_plural("Maestros de la espada");
	set_long("De complexion delgada, y mente agil, este noble elfo es conocido entre los de sur raza por "
		"por haber defendido el poblado de Hitrim en multiples ocasiones, incluso en la Guerra de la Desolancion "
		"contra los drows, y por haber alcanzado la mayor maestria jamas lograda con la espada. Hace mucho tiempo "
		"de la leyenda que en tal guerra se enfrento con la comandante del ejercito de Lloth, hasta entonces la "
		"mas arrogante sacerdotisa, que jamas habia perdido combate alguno, y pese a ello el filo de su reconocida "
		"Espada %^YELLOW%^Solar%^RESET%^ hirio de gravedad a esta, que tubo que huir humillada, dejando el combate en "
		"tablas. El es en verdad anciano ya, aunque ese hecho solo se nota en sus ojos, y en las lecciones que da "
		"a los Edhils que llegan a lograr un manejo en la espada singular.\n");
	set_race("Elfo");
	set_race_ob("/std/races/elf");
	set_guild("Edhil_faroth");
	set_guild_ob("/std/guilds/warriors/Edhil_faroth");
	set_str(18);
	set_dex(40);
	set_con(17);
	set_int(8);
	set_wis(40);
	set_cha(15);
	set_level(44);
	set_max_hp(1500);
	adjust_money(roll(2,8),"gold");
	load_chat(50,
		({
			1,"'Lamentablemente mi Espada %^YELLOW%^Solar%^RESET%^ se rompio durante la guerra.\n",
			1,"'Hace mucho tiempo un mago elfo llamado Calegyn encontro un poderoso conjuro para encantar el laen.\n",
			1,"'Con el conjuro, Calegyn encanto mi espada de %^BOLD%^Laen%^RESET%^, forjando asi mi Espada %^YELLOW%^Solar%^RESET%^.\n",
			1,"'Creo recordar que el mago vivia en una torre de cristal, oculta entre los bosques, fuimos companyeros de batalla durante mucho tiempo.\n",
			1,"'El conjuro que encontro Calegyn era dificil de realizar, y requirio una gran gema de %^RED%^BOLD%^fuego %^YELLOW%^solar%^RESET%^.\n",
			1,"'Cuando se acabo la guerra Calegyn dijo que regresaria a su torre, al parecer la entrada esta oculta, y solo un ojo atento seria capaz de descubrir su paradero.\n"
		}));
	set_aggressive(5);//Supuestamente es como 0 pero pega a los hated
	add_hated("raza","Drow");

	add_clone(ARMAS+"elf_sword",2);
	add_clone(ARMADURA+"cuero_elfico",1);
	add_clone(ARMADURA+"cinta_elfica",1);
	init_equip();
}
void init()
{
	::init();
	add_attack_spell(40,"fuerza_natura",({"/std/commands/edhil/fuerza_natura","fuerza_natura",3,0}));
	add_attack_spell(60,"cazar",({"/std/commands/cazar","hunt",0,0}));
}
void event_enter(object ob, string mensaje, object donde)
{
	if(ob->query_property("bando")>1 || ob->query_timed_property("odiado_ARBRE") && ob->query_guild_name()!="Edhil Faroth")
		TO->attack_ob(ob);
	::event_enter(ob, mensaje, donde);
}
void attack_by(object ob)
{
	if(ob->query_property("bando")==1 && !ob->query_property("odiado_ARBRE"))
		ob->add_timed_property("odiado_ARBRE",1,2000);
	return ::attack_by(ob);
}