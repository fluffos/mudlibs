inherit "/std/spells/basic";
inherit "/std/basic/multiple_short";

#define SP_COST -40
#define DODGE_WEB "fighting.combat.dodging.range"
#define DODGE_CHANCE 5

void create()
{
  set_name("web");
  set_full_name("WEB of Entanglement");
  set_spell_type("attack");
  set_skill_used("magic.spells.attack.area");
  set_xp_cost(100);
  set_duration(1);
  set_info("A spray of silvery white fibres shoot out from your hand to " 
    "engulf a foe. Although it hurts not its prisoners, it keeps it still.\n");
}
/* return XP value! */
int heart_beat_web(object attacker, mixed *params) {
  object *targets, *hit, *dodged, caster;
  int i;
  string cname;
  
  caster = previous_object();
  cname = (string)caster->query_cap_name();
  
  if (params[2]) /* were we cast? (ie do we cost SP's) */
     caster->adjust_sp(SP_COST);

  targets = params[1];
  targets -= ({ caster });
  if (!sizeof(targets)) {
    write("Your spell failed... there is no one to attack.\n");
    say(cname + " frowns, and stops chanting " +
      (string)caster->query_possessive() + " spell.\n");
    return 0;
  }
  dodged = hit = ({ });
  for(i = 0; i < sizeof(targets); i++)
    if(environment(targets[i]) == environment(caster))
      if((int)targets[i]->query_skill(DODGE_WEB) > random(params[0]) /
            sizeof(targets))
        dodged += ({ targets[i] });
      else
        hit += ({ targets[i] });

  say(caster->query_cap_name()+" sprays " +
    query_multiple_short(hit) + " with silvery white gossamer fibres!\n",
    targets);
    
  for(i = 0; i < sizeof(hit); i++) {
    tell_object(hit[i], caster->query_cap_name() + " sprays you and " +
    query_multiple_short(hit - ({ hit[i] }) ) + " with webs!\n");
  }
  
  tell_object(caster, "You spray webs over " + query_multiple_short(hit) +
    " but miss " + query_multiple_short(dodged) + ".\n");
}
