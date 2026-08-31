inherit "/std/weapon";
 
create() {
    ::create();
   set_id( ({ "mace", "skullcrusher"}) );
   set_name("skullcrusher");
   set_short("%^BLACK%^%^BOLD%^Sk%^RESET%^ul%^WHITE%^lC%^RESET%^ru%^BLACK%^%^BOLD%^sh%^RESET%^er");
   set("long", "%^BOLD%^%^BLACK%^The legendary skullcrusher, forged in the mountains of 
Thoradrim by the ancient dwarves.  Imbued with the spirit of the demon
Beelzebub, this dire mace is powerful and never ceases to cry out
for blood.");
   set_weight(25);
   set_curr_value("gold", 250);
   set_wc(8);
   set_ac(1);
   set_type("blunt");
     set_hit((: this_object(), "weapon_hit" :));
   set_wield("%^RED%^A wail of intense anguish and rage emits from the skullcrusher!!!");
   set_unwield("%^WHITE%^You drop to one knee exhausted, adrenaline seeping from your veins.");
}
int weapon_hit() {
   int result;
   object atk;
   atk = (object)this_player()->query_current_attacker();
if(random(100) < 10) {
      write("%^BLACK%^%^BOLD%^You swing violently at the s%^WHITE%^ku%^BLACK%^l%^WHITE%^l %^BLACK%^of your enemy, %^RESET%^%^GREEN%^SMASHING %^BOLD%^%^BLACK%^them in the face!");
      say((string)this_player()->query_cap_name()+"'s skullcrusher slams into the face of his enemy!");
      result =
(random(40) + this_player()->query_level());
      result = random(this_player()->query_level()*2) + 1;
this_player()->add_sp(result/4);
atk->set_paralyzed(random(4));
      return result;
   }
   return 0;
}
int query_auto_load() { if (this_player()->query_guild() == "AoD" ) return 1; }
