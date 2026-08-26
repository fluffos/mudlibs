

inherit "/std/monster" ;

void create () {


    ::create() ;
    seteuid(getuid()) ;

    set_level(1);
    set ("short", "Rat") ;
    set("long", "Vermin, nuff said.\n") ;
    set ("id", ({ "rat", "vermin" }) ) ;
    set_size(1);
    set ("mass", 1);
    set_name("rat") ;
    enable_commands() ;
    set_living_name("rat") ;
    enable_commands() ;
    set("natt", 1);
    set ("damage", ({2, 5}));
    set ("armor_class", 10);
    set ("weapon_name", "teeth") ;
  set_verbs( ({ "trie to gnaw on", "bite at", "trie to bite", "attack" }) ) ;
    set("wealth", random(3) );
}


