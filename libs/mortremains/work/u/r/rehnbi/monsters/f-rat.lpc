#include <mudlib.h>
inherit MONSTER ;

void create () {


    ::create() ;
    seteuid(getuid()) ;

set_level(2);
    set ("short", "Rat") ;
set("long", "Very pissed off rat, kinda pushy.\n");
    set ("id", ({ "rat", "vermin" }) ) ;
    set_size(1);
    set ("mass", 2);
set_name("ferocious rat");
    enable_commands() ;
set_living_name("Ferocious Rat");
    set("natt", 1);
set ("damage" , ({3, 5}));
    set ("armor_class", 12);
    set ("weapon_name", "teeth") ;
  set_verbs( ({ "trie to gnaw on", "bite at", "trie to bite", "attack" }) ) ;
set("wealth", (4)+random(3));
}


