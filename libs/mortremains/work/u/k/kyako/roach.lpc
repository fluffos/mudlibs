

inherit "/std/monster" ;

void create () {


    ::create() ;
    seteuid(getuid()) ;
    set("author", "kyako");
    set_level(1);
    set("short", "a large roach");
    set("long", "Vermin, nuff said.\n") ;
    set ("id", ({ "roach" }) );
    set_size(1);
    set ("mass", 1);
    set_name("roach");
    enable_commands() ;
    set_living_name("roach");
    enable_commands() ;
    set("natt", 1);
    set ("damage", ({2, 5}));
    set ("armor_class", 10);
    set ("weapon_name", "teeth") ;
    set_verbs( ({ "bite at", "trie to bite", "attack" }) ) ;
    set("wealth", random(3) );
}


