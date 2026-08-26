
// A generic monster.
// Comments on monster properties are found in /obj/foobird.c

#include <mudlib.h>
inherit MONSTER ;

void create () {

	object ob1, ob2, ob3, ob4 ;

	::create() ;
	seteuid(getuid()) ;
       set("short", "Ren o' The Star");
       set("long", "Here stands the Master of the Merchants' and Traders' Union.\n");
      set("id", ({ "ren", "ren o' the star", "star"}) );
	set ("capacity", 10000) ;
	set ("max_cap", 10000) ;
	set ("max_vol", 10000) ;
	set ("volume", 200) ;
        set ("mass", 300) ;
        set ("bulk", 250) ;
set_name("ren o' the star");
       set("gender", "male");
	enable_commands() ;
set_living_name("ren o' the star");
set("stat/constitution", 18);
set("stat/strength", 17);
set("stat/charsima", 16);
set("stat/intelligence", 17);
set("stat/dexterity", 17);
set("stat/wisdom", 10);
set_level(23);
set("natt", 2);
	set ("damage", ({ 1,4 }) ) ;
	set ("weapon_name", "fists") ;
	set ("CLASS", "wizard");
set("spell_points", 500);
set("mage_spells", ({"stoneskin", "lightning", "missile", "enlarge", "haste"}));
set_skill("Clubbing Weapons", 4, "Strength") ;
ob1= clone_object ("/d/Prime/Oerth/ghcity/weap/morningstar1");
    ob1 -> move (this_object()) ;
	ob2 = clone_object ("/d/class/wizard/general/obj/book") ;
    ob2 -> move (this_object()) ; 
ob3= clone_object ("/d/Prime/Oerth/ghcity/armour/bronzeplate");
    ob3 -> move (this_object()) ;   
   ob4 = clone_object ("d/Prime/Oerth/ghcity/items/ringreg");
   ob4-> move(this_object());
	set ("special", 1);
	set ("wealth", 10000);
       		}
void init () {
::init();
command("wield morning star");
command("equip");
command("cast stoneskin");
command("cast enlarge");
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
switch (random(2)) {
case 0 : command("cast missile at "+(this_object()->query_current_attacker())->query("name"));break;
case 1 : command("cast lightning at "+(this_object()->query_current_attacker())->query("name"));break;
	}
	}else{
	command("cast haste");
}
	}else{
	command("cast stoneskin");
}
}
}
