inherit "/std/weapon";
 
void create() {
    ::create();
   set_id(({ "pickaxe", "pickax", "ax", "axe", "dwarven pickax" }));
   set_name("dwarven pickaxe");
   set_short("a dwarven pickaxe");
   set_long("A standard sturdy pickaxe used by the dwarven miners on Unalom. "
   "This axe is made of steel, which seems to have been dulled by the mysterious "
   "metal which the dwarves mine there.  The axe almost seems possessed in a way "
   "with the light reflecting off it almost seeming alive.");
   set_weight(12);
   set_curr_value("silver", 60);
   set_wc(6);
   set_type("axe");
   set_hit((: this_object(), "weapon_hit" :));
   }

int weapon_hit()
{
    int result;
    object atk;
    atk = (object)this_player()->query_current_attacker();
    if(random(100) < 5) {
    write("%^BOLD%^BLACK%^The whole room darkens as the axe digs into"+atk->query_cap_name()+".%^RESET%^");
    atk->do_damage("torso", atk->query_level()*3);
       
      result=10;
      return result;

    }
}
int query_auto_load() { if (this_player()->query_level() > 30) return 1; }
