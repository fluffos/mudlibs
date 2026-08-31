#include <std.h>


inherit ARMOUR;
void init() {
    ::init();
add_action("add_player", "add");
}
void create()
{
 ::create();

 set_name("Earring");
 set_short("%^BOLD%^%^WHITE%^A%^BLACK%^n %^BLACK%^E%^WHITE%^a%^BLACK%^r%^WHITE%^r%^BLACK%^i%^WHITE%^n%^BLACK%^g%^RESET%^");
 set_long("%^BOLD%^%^BLACK%^This Earring Belongs to a leader of "
"the D%^WHITE%^a%^BLACK%^r%^WHITE%^k "
"%^BLACK%^S%^WHITE%^o%^BLACK%^u%^WHITE%^l%^BLACK%^s. It is a mystical shape "
"that has never been seen by the normal eye.");
   set_property("no steal", 1);
 set_id( ({ "earring","an earring" }) );
 set_type("Earring");
 set_ac(0);
 set_mass(1);
 set_value(00000);

}

int add_player(string what) {  
object ob;
ob = find_player(what);
if (!ob->is_player()) return notify_fail("Add who, dipshit?\n");
write("You add "+what+" to the darksouls. Don't you feel special?");
tell_object(ob, "%^BOLD%^%^BLACK%^You are now a D%^WHITE%^a%^BLACK%^r%^WHITE%^k %^BLACK%^S%^WHITE%^o%^BLACK%^u%^WHITE%^l.");
ob->set_guild("darksoul");
new("/wizards/detach/roston/guild/cloak")->move(this_player());   
  return 1;
 }
int query_auto_load()
{
 if (wizardp(this_player())) return 1;
 return 1;
}     
