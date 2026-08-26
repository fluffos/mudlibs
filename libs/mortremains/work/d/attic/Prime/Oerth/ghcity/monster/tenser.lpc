
// A generic monster.
// Comments on monster properties are found in /obj/foobird.c

#include <mudlib.h>
inherit MONSTER ;

void create () {

	object ob1, ob2, ob3, ob4 ;

	::create() ;
	seteuid(getuid()) ;
       set("short", "Tenser the Archmage");
       set("long", "Here stands one of the greatest mages whoever lived.\n");
       set("id", ({ "tenser", "archmage"}) );
	set ("capacity", 10000) ;
	set ("max_cap", 10000) ;
	set ("max_vol", 10000) ;
	set ("volume", 200) ;
        set ("mass", 300) ;
        set ("bulk", 250) ;
       set_name ("tenser");
       set("gender", "male");
	enable_commands() ;
       set_living_name("tenser");
       set("stat/constitution", 10);
       set("stat/strength", 10);
       set("stat/charisma", 18);
       set("stat/intelligence", 18);
	set ("stat/dexterity", 18);
	set ("stat/wisdom", 12);
set_level(35);
	set("natt", 1);
	set ("thac0", 6);
	set ("damage", ({ 1,4 }) ) ;
	set ("weapon_name", "fists") ;
	set ("CLASS", "wizard");
       set("spell_points", 2500);
 set("mage_spells", ({ "stoneskin", "lightning", "missile", "haste", "prismsphere", "timestop", "swarm", "strength", "stun", "disjunction", "prism", "enlarge", "deadly_aim" }));
       set_skill("Long Blades", 5, "Strength") ;
       ob1= clone_object ("d/Prime/Oerth/ghcity/weap/tensersword");
    ob1 -> move (this_object()) ;
	ob2 = clone_object ("/d/class/wizard/general/obj/book") ;
    ob2 -> move (this_object()) ; 
    ob3 = clone_object ("/d/Outer/Sigil/items/archmagirobe") ;
    ob3 -> move (this_object()) ;   
   ob4 = clone_object ("d/Prime/Oerth/ghcity/items/ringreg");
   ob4-> move(this_object());
	set ("special", 1);
	set ("wealth", 10000);
       		}
void init () {
::init();
// command("cast prismsphere");
command("cast deadlyaim");
command("cast deadly_aim");
command("wield sword");
command("cast enlarge");
command("equip robes");
command("equip ring");
command("cast haste");
command("say You'll never defeat the Circle of Eight!");
}
void special_attack() {
	//this is the spell function for raw excessive damage
object ob;
int sv; 
string target;
if (this_object()->query("cast_delay") || this_object()->query("spell_points")<80) {
	return 1;
}else{	
 ob = (present("#STONESKIN#", this_object()));
if ( (ob) || (this_object()->query("wealth") < 1000)){

	ob = (present("#HASTE#", this_object()));
	if (ob){
switch (random(7)) {
       case 0 : command("cast stun at "+(this_object()->query_current_attacker())->query("name"));break;
	case 1 : command("cast missile at "+(this_object()->query_current_attacker())->query("name"));break;
	case 2 : command("cast lightning at "+(this_object()->query_current_attacker())->query("name"));break;
       case 3 : command("cast swarm at "+(this_object()->query_current_attacker())->query("name"));break;
       case 4 : command("cast disjunction at "+(this_object()->query_current_attacker())->query("name"));break;
       case 5 : command("cast prism at "+(this_object()->query_current_attacker())->query("name"));break;
       case 6 : command("cast timestop at "+(this_object()->query_current_attacker())->query("name"));break;
	}
	}else{
	command("cast haste");
}
	}else{
	command("cast stoneskin");
}
}
}
