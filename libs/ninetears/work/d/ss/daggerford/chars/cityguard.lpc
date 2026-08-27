inherit "/obj/monster";
 
#define ARMOUR "/baseobs/armours/"
#define WEAPON "/baseobs/weapons/"
 
void init()
   {::init();
    call_out("first_approach", 0, this_player());
   }
 
void setup()
  {set_name("The militiaman");
   add_property("NO_BUDGE",1);
   add_alias("militia");
   add_alias("guard");
   add_alias("militiaman");
   set_main_plural("militiamen");
   add_plural("guards");
   add_plural("militiamen");
   set_short("militiaman");
   set_long("Though young, the militiaman bears the scars of countless "+
            "battles, indicative of his fighting experience.  Silent "+
            "and nearly motionless, the guard could almost be a statue - "+ 
            "but then again, you have seen them in action, protecting the "+
            "innocent and punishing the guilty within the walls of this "+
            "fair city.\n\n");
   set_race("human");
   set_guild("fighter");
   set_level(20 + random(5));
   set_gender(1);
   set_wimpy(0);
   set_al(-60);
   set_random_stats(18, 18);
   set_str(18 + random(5));
   set_dex(15 + random(3));
   set_con(15 + random(3));
   set_max_hp(150 + random(75));
   set_thac0(12);
   load_chat(10, ({
        1, ":shifts his weight from one leg to the other.",
        1, ":smiles briefly at a passerby before regaining his composure."
        }));
   load_a_chat(30, ({
        1, "'You are a foolish one for fighting within these walls!",
        1, "'Help is on the way, you cannot win!"
        }));
   
   clone_object(WEAPON + "halberd")->move(this_object());
   clone_object(ARMOUR + "chainmail")->move(this_object());
   clone_object(ARMOUR + "helmet")->move(this_object());
   do_command("equip");
  }
 
void first_approach(object target)
{
  if((string)(target->query_race()) == "drow")
   {
      if((int)target->query_property("dead"))
      {
         do_command("unfollow "+target->query_name());
         do_command("say The only good Drow is a dead Drow they say.\n");
      }
      else
      {
         do_command("say Drow aren't welcome in this town");
         do_command("follow "+target->query_name());
         attack_ob(target);
     }
  }
}
 
void event_fight_in_progress(object ONE, object TWO) 
  {int alev, dlev, tolerance, i;
   object ATT, DEF, *atts;
   ATT = ONE;
   DEF = TWO;
   if((ATT->query_level()) < (DEF->query_level()))
      {ATT = TWO;
       DEF = ONE;
      }
   alev = ATT->query_level();
   dlev = DEF->query_level();
   if(dlev == 0)
       dlev = 1;
   tolerance = alev / dlev;
   if((dlev > 6) || (string)(DEF->query_race()) == "drow")
       tolerance = 1;
   if(dlev < 3)
       tolerance = 4;
   if((tolerance > 3) && interactive(DEF) && interactive(ATT))
      {atts = query_attacker_list();
       alev = 0;                 /* Just recycling variable names here */
       dlev = 0;
       if(sizeof(atts))
           for(i=0; i<sizeof(atts); i++)
              {if(atts[i] == DEF)
                  dlev = 1;
               if(atts[i] == ATT)
                  alev = 1;
              }
/*
       if(!alev || !dlev)
          {do_command("protect " + DEF->query_name());
           do_command("say Fighting those much weaker than yourself is NOT "+
                      "good policy,"+ ATT->query_cap_name() + "!");
          }
       do_command("follow " + ATT->query_name());
*/
       attack_ob(ATT);    
      }
  } 
