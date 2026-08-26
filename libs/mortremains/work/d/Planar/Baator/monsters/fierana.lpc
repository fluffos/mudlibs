// Coded by Ilzarion
// Cleaned up by Cyanide

#include <messages.h>

inherit MONSTER ;

void create () {
    object ob1;

    ::create() ;
    seteuid(getuid()) ;
    set ("short", "Fierana the Lady of Phlegethos") ;
    set ("long", @EndLong
Fierana, Lady of Phlegethos; the powerful Lord of the Fourth. She appears
as a beautiful young woman with flaming red hair and a lithe figure. The
berk who's fooled by her beauty deserves what he gets, being turned into
a charred husk. 
EndLong
    );
    set ("id", ({ "fierana", "lord", "baatezu"}) ) ;
    set_name ("fierana") ;
    set ("gender", "female") ;
    set ("race", "baatezu");
    enable_commands() ;
    set_living_name("fierana") ;
    set ("stat/constitution", 19);
    set ("stat/strength", 15);
    set ("stat/charisma", 21);
    set ("stat/intelligence", 23);
    set ("stat/dexterity", 20);
    set ("stat/wisdom", 20);
    set_size(7);
    set ("base_ac", 3);
    set ("armor_class", 3);
    set ("damage", ({ 1,4 }) ) ;
    set ("weapon_name", "fists") ;
    set ("CLASS", "wizard");
    set ("weap_resist", 4);
    set ("magic_resist", 90);
    set ("mage_spells", ({ "fireshield", "fireball", "swarm" }) );
    set ("max_sp", 1000);
    set ("spell_points", 1000);
    set("prevent_summon", 1);
    set ("resist_type", ([ "cold" : 0, "dehydration" : 0, "fire" : 0 ]) );
    set_verbs( ({ "slash at", "swing at", "swipe at" }) ) ;

    ob1 = clone_object ("/d/class/wizard/general/obj/book") ;
    ob1->set("invisible", 2);
    ob1 -> move (this_object()) ;

    set ("special", 10);
    set_level(40);
}
void init(){
    ::init();
    command ("cast fireshield");
}


void special_attack() {    
        //this is the spell function for raw excessive damage
        object ob;
        int sv; 
        string target;

    if (random(3)) return 0;

    if (query("power_delay")) {        
        ob = get_random_attacker();

        ob->receive_damage(((random(10)+61)), "fire", TO, 0);
        message(MSG_COMBAT, "Fierana call fire from the sky to burn you!\n", ob);
        message(MSG_COMBAT, "Fierana call fire from the sky to burn "+
            ob->query("cap_name")+"!\n", all_inventory(environment(TO)), ob);
        write("You call fire from the sky to hit "+ob->query("cap_name")+".\n");
        return 1;
    } else {	     
        switch (random(3)){    
            case 0 : command("cast fireball");break;
            case 1..2 : command("cast swarm");break;
        }
        return 0;
    }
}