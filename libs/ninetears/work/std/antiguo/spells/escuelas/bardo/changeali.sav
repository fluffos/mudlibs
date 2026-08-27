/***  Change Alignment  ***/
/*** Blame this spell on Taniwha ***/
 
inherit "/std/spells/base.c";
 

void setup()
{
  set_spell_name("Change Alignment");
  set_spell_level(4);
  set_school("bard");

  set_target_type("one");
  set_range(1);

  set_help_desc("This spell changes the alignment of the target.  "
    "The effects can be devastating to some guilds, negligable to others.\n"
    "Saving throw on magical resistance.");
 
  set_gp_cost(50);
  set_casting_time(1);
  set_rounds( ({ "round1" }) );
}
 
int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{

  if (!target)
  {
    tell_object(caster,
      "Your spell failed ... there is no one of that name here.\n");
    return -1;
  }

  if ( !quiet )
  {
    tell_room(environment(caster), (string)caster->query_cap_name()+
      " sings:\n\n"   
      "   I've talked to the Gods, I've walked on the stars,\n"  
      "   Our fathers were Druids, masters of earth.\n"
      "   Call me a liar, call me a thief,\n"
      "   But from this chant you'll find little relief.\n" 
      , ({target,caster}));
 
    tell_object(caster, "You sing:\n\n" 
      "   I've talked to the Gods, I've walked on the stars,\n"  
      "   Our fathers were Druids, masters of earth.\n"
      "   Call me a liar, call me a thief,\n"
      "   But from this chant you'll find little relief.\n" 
      "\n\n");
  }
  if(random( (int)target->query_property("magical")) < 10)
  {	
     if( target == caster)
     {
        tell_object(target, "You cast Change Alignment upon yourself.\n");
    	tell_room(environment(caster), (string)caster->query_cap_name()+
      	" casts a spell upon "+target->query_objective()+"self.\n",target);
     } 	
     else
     {
        tell_object(target, "You feel different , as though your soul has been turned inside out!\n");
 
        tell_object(caster, "You cast Change Alignment on "+
           (string)target->query_cap_name() + ".\n");
 
        tell_room(environment(caster), target->query_cap_name()+
           " suddenly takes on a different demenour.\n", ({target,caster}) );
     }	
     target->reverse_align();
     target->set_ethics(-(int)target->query_ethics());
  }
  else
  {
     tell_object(target,"You feel a wind rush through your soul, you shudder, but are otherwise unchanged.\n");
     tell_object(caster,"Your spell failed.\n");
  }   
  if ( !interactive(target) )
  {
    tell_room(environment(caster), target->query_cap_name()+
      " doesn't appear too pleased with "+caster->query_cap_name()+
      "'s antics.\n", caster);
    tell_object(caster, target->query_cap_name()+
      " doesn't appear too pleased with your antics.\n");
    target->attack_by(caster);
  }

  return 0;
}
