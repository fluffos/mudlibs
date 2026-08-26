/* Sand Monster*/

inherit MONSTER;

#define attackName 	

void create() 
{
    ::create();
    set("prevent_summon", 1);  // Until this can be cleaned up - Cyanide
    set("author" , "gasman");
    set_name("Sand Monster");
    set("id", ({ "monster", "sand monster" }) );
    set("short", "Sand Monster");
    set("long", "A goolish sand monster!\n");
    set("gender", "male");
    set("race" , "sand");
    set("weapon_name", "claws");
    set_verbs( ({ "swing at" }) );
    set("damage", ({ 4, 9 }) );
    credit(random(50));
    set_level(20);
}
