// Chronos coded this off a template, basically.
#include <mudlib.h>
#include "../central.h"

inherit MONSTER;

void create() {
    ::create();
    seteuid(getuid());  
    set("race", "half-orc") ;
    set_size(6) ;
   set("short", "Fourz the Feared, Ugly Orc") ;
    set("long", @ENDLONG
Fourz is an ugly-as-hell Half-orc (aren't they all?) with huge bulging
muscles.  His face looks like someone tried to put out a forest
fire with a screwdriver.  He looks mean, carrying his huge
battle-axe.
ENDLONG
   );
    set_name("fourz") ;
    set("prevent_summon", 1);
   credit(200 + random(145) ) ;
   set("gender", "male");
   set("id", ({ "fourz", "half-orc" }) ) ;
    set("author", "Chronos") ;
    set ("damage", ({ 4,6 }) ) ;
    set ("weapon_name", "fists") ; 
    set_verbs( ({ "swing at", "attack", "punche at" }) );
    set_level(17);
    arm("/obj/weapon/battleaxe") ;
    wear("/obj/armor/chainmail") ;
   set("stat/strength", 19) ;
   set("stat/constitution", 18) ;
 }
