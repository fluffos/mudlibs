
//Beholder

inherit "/std/monster" ;

void create () {

    object ob1, ob2, ob3 ;

    ::create() ;
    seteuid(getuid()) ;
    set ("stat/constitution", 20);
    set ("special", 20);
    set ("short", "Beholder") ;
    set("long", "A old and powerful Beholder.\n") ;
    set ("id", ({ "beholder", "death dealer" }) ) ;
    set("gender", "female");
    set_size(7);  
set ("CLASS", "monster",);
    set("armor_class", 5);
    set("magic_resist",0);
    set ("capacity", 0);
    set ("hit_points", 1730) ;
    set ("natt" , 1);
    set ("aggressive", 1) ;
    set("race", "beholder");
    enable_commands();
    set("max_tp", 1000);
    set("theurgy_points", 1000);
    set("priest_spells", ({ "hold", "fear", "slow", "causeser" }) );
    set ("mage_spells", ({ "fireball", "lightning", "feeblemind", "disintegrate", "finger", "dispel", "coldcone" }) );
    set ("max_sp", 1000);
set("deity", "Greater Unknown");
    set ("spell_points", 1000);
    wear("/d/class/wizard/general/obj/book", "book") ;
    set("damage_type", "slashing");
    set ("damage", ({4 , 10}));
    set ("weapon_name", "teeth") ;
    set_verbs( ({ "bite", "gnaw", "chomp" }) ) ;
    set_verbs2( ({ "bites", "gnaws at", "chomps" }) ) ;
    set_name("death dealer") ;
    set_living_name("death dealer");
    enable_commands() ;
set_level(15);
}

void init() {
    ::init();
    command("say FOOD!");
}

void special_attack() {
    //this is the breathe or bite function for raw excessive damage
    object ob = this_object()->query_current_attacker();

    if (random(3) == 0) {
	say( "Death Dealers first eye looks at "+ ob->query("cap_name")+"!\n", ob);
	tell_object(ob, "Death Dealer's first eye cast Hold on you!\n");
	command("invoke hold");
    }        
    if (random(3) == 0) {
	say( "Death Dealers second eye shoots a fireball on "+ ob->query("cap_name")+"!\n", ob); 
	tell_object(ob, "Death Dealer's second eye sets you on fire!\n");
	command ("cast fireball");
    }
    if (random(3) == 0) {
	say( "Death Dealer's third eye glares at "+ ob->query("cap_name")+" !\n", ob);
	tell_object(ob, "Death Dealers third eye lights your LIFE!\n");
	command ("cast lightning");
    }	
    if (random(3) == 0) {
	say( "Death Dealers fourth eye glances at "+ ob->query("cap_name")+" !\n", ob);
	tell_object(ob, "Death Dealer's fourth eye makes you feel not so Smart!\n");
	command ("cast feeblemind");
    }
    if (random(3) == 0) {
	say( "Death Dealers fifth eye DISINTERATES "+ ob->query("cap_name") +" !\n");
	tell_object(ob, "Death Dealer's fifth eye makes you feel less than you were!\n");
	command ("cast disintegrate");
    }
    if (random(3) == 0) {
	say( "Death Dealers sixth eye makes "+ ob->query("cap_name") +" run like hell!\n");
	tell_object(ob, "Death Dealer's sixth eye makes you scared as shit!\n");
	command("invoke fear");
    }
    if (random(3) == 0) {
	say( "Death Dealers seventh eyes seems to make "+ ob->query("cap_name") +" slow as shit!\n");
	tell_object(ob, "Death Dealer's seventh eye makes everything seem to slow down!\n");
	command("invoke slow");
    }
    if (random(3) == 0) {
	say( "Death Dealers eighth eye makes blood pour from "+ ob->query("cap_name") +" !\n");
	tell_object(ob, "Death Dealer's eighth eye makes you Hurt badly!\n");
	command("invoke causeser");
    }
    if (random(3) == 0) {
	say( "Death Dealers ninth eye stares at "+ ob->query("cap_name") +" making his heart stop!\n");
	tell_object(ob, "Death Dealer's ninth eye makes you have a Heart Attack!\n");
	command ("cast finger");
    }
    if (random(3) == 0) {
	say( "Death Dealers Main eye glares at "+ ob->query("cap_name") +" !\n");
	tell_object(ob, "Death Dealer's main eye looks at you!\n");
	command ("cast dispel"); 
    }
    if (random(3) == 0) {
	say( "Death Dealers tenth eye glares, shooting a white beam at "+ ob->query("cap_name") +"!\n");
	tell_object(ob, "Death Dealer's tenth eye glares at you making you cold!\n");
	command ("cast coldcone");
    }
}
