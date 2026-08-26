/*********************************
 * sphere_shadow.c 
 *
 * Tlaloc - 7.5.22
 *
 * This shadows several functions
 * on the player object to render
 * the prismatic sphere recipient
 * essentially unable to engage in
 * combat.
 *********************************/
 
object sphered;
 
int ok_to_kill(object targ)                           { return 0;      } //Can't attack anyone while sphere is up
int is_in_combat()                                    { return 0;      } //Never in combat
int clean_up_attackers()                              { return 0;      } //Never have attackers
object *query_attackers()                             { return ({  }); } //No attackers list while in sphere

object query_sphere_shadow()                          { return this_object(); } //Allows you to reference shadow by calling sphered player

//I found this necessary to stop things like AOE spells from firing.
void execute_attack()
{
    object attacker = sphered->query_current_attacker();
    
    if(objectp(attacker))
    {
        message("protection", "%^BOLD%^The prismatic sphere stops the fighting!%^RESET%^", environment(sphered));
        attacker->remove_attacker(sphered);
        sphered->remove_attacker(attacker);
    }
}

//Mask cause_typed_damage while sphere is up
int cause_typed_damage(object targ, string limb, int damage, string type)
{
    object attacker;

    if(!objectp(attacker = targ->query_property("beingDamagedBy")))
        attacker = previous_object();
    
    if(!objectp(attacker) || !objectp(targ))
        return 0;
    
    if(attacker == targ) //if it's me doing something to myself, let it pass through (healing myself)
        return targ->cause_typed_damage(targ, limb, damage, type);
    
    if(!objectp(sphered) || targ != sphered)
        return targ->cause_typed_damage(targ, limb, damage, type);
    
    message("protection", "%^CYAN%^BOLD%^The sphere shimmers as it nullifies the damage.%^RESET%^", environment(targ));
    attacker->remove_attacker(targ);
    targ->remove_attacker(attacker);
    
    return 0;      
}

int start_shadow(object ob)
{
  sphered = ob;
  return shadow(sphered,1);
}

int end_shadow()
{
  //unshadow();
  destruct(this_object());

}