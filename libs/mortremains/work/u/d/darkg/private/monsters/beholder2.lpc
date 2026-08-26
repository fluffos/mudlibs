
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
    set ("CLASS", "wizard", "priest",);
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
    set ("spell_points", 1000);
    set("damage_type", "slashing");
    set ("damage", ({4 , 10}));
    set ("weapon_name", "teeth") ;
    set_verbs( ({ "bite", "gnaw", "chomp" }) ) ;
    set_verbs2( ({ "bites", "gnaws at", "chomps" }) ) ;
  wear("/d/class/wizard/general/obj/book", "book") ;
    set_name("death dealer") ;
    set_living_name("death dealer");
    enable_commands() ;
set_level(17);
}

void init() {
    ::init();
    command("say FOOD!");
}

void special_attack() {
    //this is the breathe or bite function for raw excessive damage
      object ob = this_object()->query_current_attacker();
   
  
switch (random(11)){
  	case 0 :    command("invoke hold");break;
    case 1 :    command ("cast fireball");break;
    case 2 :    command ("cast lightning");break;
  	case 3 :    command ("cast feeblemind");break;
	case 4 :    command ("cast disintegrate");break;
	case 5 :	command("invoke fear");break;
	case 6 :	command("invoke slow");break;
	case 7 :    command("invoke causeser");break;
	case 8 :	command ("cast finger");break;
	case 9 :    command ("cast dispel");break;
	case 10 :    command ("cast coldcone");break;
  }
}
