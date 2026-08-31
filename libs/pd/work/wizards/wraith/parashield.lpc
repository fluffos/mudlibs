# include <std.h>
inherit ARMOUR;
int extra_worn();
void create() {
::create();
  
    set_name("Obsidian Shield");
    
    set_short("Obsidian Shield");
    set_long("This is the shield of the Forsaken, and only members of this
elite guild will have the honor of wearing it in battle.  It's hot to the touch
and you 
wonder if it will hurt when worn...");
    set_id(({"shield", "guild_shield", "obsidian_shield"}));
    set_ac(20);            
    set_weight(20);
    set("value", 15);
    set_type("shield");  
    set_wear( (: extra_worn :) );
    set_limbs(({ "torso" , "right arm" , "right hand" }));
}
int extra_worn() {
    if((int)this_player()->query_level() < 50) {
        write("Get real!  You're not powerful enough for this boy!");
        say(this_player()->query_cap_name()+" feels stupid as a hand of fire reaches out of the front of the shield and SMACKS him across the face!");
        notify_fail("Get real!  You're not powerful enough for this boy!");
        return 0;
    }
    write("Extreme heat emenates from the shield and the air wavers as your vision blurs.  You scream in agony as the shield melds to your skin and becomes one with you!");
    say(this_player()->query_cap_name() + " suddenly doubles over in pain as the shield melds into his skin making him stronger!");
    return 1;
}
int weapon_hit() {
   int result;
   object atk;
   atk = (object)this_player()->query_current_attacker();

if(random(100) > 90) {
      write("The sword flashes brightly as the sword warps your foe's existence with chaos!");
      say((string)this_player()->query_cap_name()+"'s sword flashes brightly as it strikes.");
      result =
(random(55+random(50)-random(50)))*((this_player()->query_level()/20)+1);

      result=random(result)+1;
this_player()->add_sp(result);

atk->set_paralyzed(random(4));

      return result;
   }
   return 0;

}
 int query_auto_load() { if (this_player()->query_level() > 50) return 1; }
