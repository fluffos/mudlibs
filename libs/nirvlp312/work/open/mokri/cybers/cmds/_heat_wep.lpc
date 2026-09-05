#include "/players/mokri/define.h"

main(string str)
{
   object who, wep, gobj;
   
   if(!TP->query_pl_k())
      {
      write("You must be PK to use this.\n");
      return 1;
   }
   
   if(TP->query_ghost())
      {
      write("You're dead. Please lie still.\n");
      return 1;
   }
   
   gobj = present("guild_implants",TP);
   if(!gobj)
      {
      write("Error. No CyberNinja Implants present.\n");
      return 1;
   }
   
   if(TP->query_spell_dam()) return 1;
   if(gobj->guild_lev() < 8)
      {
      write("Your neural implants are not sufficient to allow this action.\n");
      return 1;
   }
   
   if(TP->query_sp() < 60)
      {
      write("You are too drained to attempt this.\n");
      return 1;
   }
   
   if(!str && TP->query_attack())
      {
      who = TP->query_attack();
      if(present(who,ENV(TP)))
         str = who->query_real_name();
   }
   
   if(!str)
      {
      write("Heat who's weapon?\n");
      return 1;
   }
   
   str = LOWER(str);
   who = find_player(str);
   if(who == TP)
      {
      write("Just 'unwield'. It's cheaper!\n");
      return 1;
   }
   
   if(!who || !present(who,ENV(TP)))
      {
      write(CAP(str)+" is not here.\n");
      return 1;
   }
   
   if(who->query_level() > 19)
      {
      write("Uh, no.\n");
      return 1;
   }
   
   if(!who->query_pl_k())
      {
      write(CAP(str)+" is not PK.\n");
      return 1;
   }
   
   wep = who->query_weapon();
   if(!wep)
      {
      write(CAP(str)+" does not have a weapon wielded that you can heat!\n");
      return 1;
   }
   
   write("You concentrate, collecting electricity in your implants.\n");
   TP->add_sp(-60);
   if(!random(8))
      {
      write("The energy dissipates unexpectedly.\n");
      return 1;
   }
   
   write(HIR+"You release the energy, heating "+CAP(str)+"'s weapon to the point " + who->query_pronoun() + " can no longer hold on to it.\n"+NORM);
   tell_object(who,HIR+CAP(TPN)+" HEATS YOUR WEAPON, FORCING YOU TO UNWIELD IT.\n"+NORM);
   say(TPN+" focuses an energy burst onto " + CAP(str) + "'s weapon, forcing " + who->query_objective() + " to unwield it.\n");
   who->stop_wielding();
   wep->set_wielded(0);
   wep->set_wielded_by(0);
   if(wep->query_guild_bonus()) wep->remove_guild_bonus();
   TP->spell_object(who, "disarmament", 0,0,"","","");
   return 1;
}
