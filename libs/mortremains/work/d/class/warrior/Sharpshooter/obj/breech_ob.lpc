// This object makes the weapon revert to normal when unwielded. ;)
#include <mudlib.h>

inherit OBJECT ;

int level, bonus, flag ;
object weapon, guy ;
string long ;

void create() {
    seteuid(getuid()) ;
    set("prevent_drop", 1) ;
    set("prevent_sell", 1) ;
    set("prevent_insert", 1) ;
    set("prevent_clean", 1) ;
}

void init() {
    add_action("check_wield", "",1) ;
}

int activate(object wep, int lvl, int bns) {
    if (!wep) return 0 ;
    weapon = wep ;
    guy = environment(wep) ;
    level = lvl ;
    bonus = bns ;
    long = weapon->query("long") ;
    weapon->set("long", long+
      "It is surrounded by an unearthly glow, and is providing light.\n" ) ;
}

int check_wield() {
    if (flag) return 0;
    if (!weapon) call_out("remove", 5) ;
    if (!living(environment())) {
	flag++;
	call_out("undo", 5) ;
	return 0;
    }
    if (weapon && !weapon->query("wielded")) {
	flag++;
	call_out("undo", 5) ;
	return 0;
    }
    if (environment(weapon) != guy) {
	flag++;
	call_out("undo", 5) ;
	return 0;
    }
    return 0 ;
}

int undo() {
    if (living(environment())) {
	message("combat", capitalize(weapon->query("short"))+
	  " slowly stops glowing.\n", environment(environment())) ;
    } else {
	tell_object(environment(),
	  capitalize(weapon->query("short")) + 
	  " slowly stops glowing.\n" ) ;
    }
    weapon->set_bonus(0,0,0) ;
    weapon->add("light", -1 ) ;
    weapon->set("long", long+
      "This weapon was once infused with a powerful lifeforce.\n") ;
    call_out("remove", 5) ;
    return 0 ;
}           
