

inherit "/std/monster" ;

void create () {


    ::create() ;
    seteuid(getuid()) ;

    set_level(1);
    set ("short", "Rat") ;
    set("long", "Vermin, nuff said.\n") ;
    set ("id", ({ "rat", "vermin" }) ) ;
    set_size(1);
    set ("mass", 2);
    set_name("rat, ferocious")
    enable_commands() ;
    set_living_name("rat") ;
    enable_commands() ;
    set("natt", 1);
    set ("damage", ({3, 6}))
    set ("armor_class", 12);
    set ("weapon_name", "teeth") ;
  set_verbs( ({ "trie to gnaw on", "bite at", "trie to bite", "attack" }) ) ;
  set("wealth", random(9) );
}


