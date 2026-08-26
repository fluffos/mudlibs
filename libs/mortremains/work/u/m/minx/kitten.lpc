
//TIAMAT!!!


inherit "/std/monster" ;

void create () {
    ::create() ;
    seteuid(getuid()) ;
    set ("short", "Kitten") ;
    set("long", "A small harmless kitten.\n") ;
    set ("id", ({ "kitten", "cat", "pussy" }) ) ;
    set_size(1);
    set("armor_class", 9);
    set ("natt" , 1);
    set("race", "kitten");
    enable_commands();
set("damage_type", "slashing");
    set ("damage", ({2 , 5}));
    set ("weapon_name", "claws") ;
    set_verbs( ({ "slash", "scratch", "rip" }) ) ;
    set_verbs2( ({ "slashes", "scratches", "rips" }) ) ;
    set_name("kitten") ;
    set_living_name("kitten");
    enable_commands() ;
set_level(1);
}

void init() {
    ::init();
    command("growl");
}
