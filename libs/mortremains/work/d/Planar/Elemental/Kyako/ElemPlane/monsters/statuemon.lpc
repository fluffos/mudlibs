#include <mudlib.h>

inherit MONSTER ;

void create () {

        ::create() ;
        seteuid(getuid()) ;
        set ("short", "Living statue") ;
        set("long", @Statue
One of the mayor's statues.
It appears to be very strong and resistant to most things.
You're gonna have a tough time killing it.
Unless there's a way to avoid it...
Statue
 ); 
        seteuid(getuid()) ;
        set ("id", ({ "statue", "statuemon" }) ) ;
        set ("capacity", 1000) ;
        set ("volume", 1000) ;
        set ("mass", 30000) ;
        set ("bulk", 2500) ;
        enable_commands() ;
        resistance("fire", 0);
        resistance("cold", 0);
        resistance("crushing", 0);
        resistance("dehydration", 0);
        resistance("suffocation", 0);
        resistance("bleeding", 0);
        resistance("acid", 0);
        resistance("poison", 0);
        resistance("necromancy", 0);
        resistance("force", 0);
        resistance("electricity", 0);
        resistance("slashing", 0);
        resistance("piercing", 0);
        resistance("bludgeoning", 0);
        resistance("magic", 0);
        resistance("wizard", 0);
        set("stat/charisma", 15 );
        set("stat/strength", 30 );
        set("stat/constitution", 30 );
        set("stat/dexterity", 10 );
        set("stat/wisdom", 1 );
        set("stat/intelligence", 1 );
        set_name("statuemon") ;
        set_living_name("statuemon") ;
        set ("weapon_name", "stone fists") ;
        set_verbs( ({ "bash", "pound", "clobber", "hit" }) ) ;
        set_skill("Unarmed", 5, "Strength") ;
        set_level(10);
set("damage", ({ 10, 30 }) );
}

void init() {
}

int resetcmd() {
   ::remove();
   return 0;
}
