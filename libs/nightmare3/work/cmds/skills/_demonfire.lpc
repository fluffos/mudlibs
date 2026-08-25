//Demonfire for the kataans. 
//Coded by Zaknaifen@Nightmare 1-31-94.
 
 
#include <std.h>
 
  void do_good(object ob);
  void do_evil(object ob);
  void do_kataan(object ob);
  object env, *list, caster, *goodlist, *evillist, *kataanlist;
  int x ,y, z, a, b, c, d, e, group;
 
 
int cmd_demonfire(string str)
 {
 
  x=(int)this_player()->query_skill("faith");  
  y=(int)this_player()->query_stats("intelligence");
  z=(int)this_player()->query_stats("wisdom");
  a=(int)this_player()->query_max_mp();
  b=(int)this_player()->query_mp();
  c=(int)this_player()->query_stats("charisma");
  env=environment(this_player());
  list=all_inventory(environment(this_player()));
  caster=this_player();
  group=0;
   group += b/4 + x + y/3 + z/3 + 50;
 
  if(str)
   {
   notify_fail("Demonfire will affect all present, no argument is needed.\n");
   return 0;
   }
 
  if((string)this_player()->query_class()!="kataan")
     {
      notify_fail("You would never dare to summon demons.\n");
      return 0;
     }
     
    
   if(this_player()->query_ghost())
     {
      notify_fail("You can't do that in your current state.\n");
      return 0;
     }
 
   if((int)this_player()->query_alignment()>-500)
     {
      notify_fail("You have second thoughts at the last moment while "
                  "debating whether summoning demons is a good deed.\n");
      return 0;     
      }
    
       if(x<65)
     {
               notify_fail(
                 "%^RED%^The demons sneer at your lack of faith.%^RESET%^\n");
      return 0;
     }
   
    if(b<40) 
    {
      notify_fail("You lack the mystical strength required to summon "
                  "Demonfire.\n");
      return 0;
    }
 
   if(env->query_property("no attack") || env->query_property("no magic")) 
    {
     notify_fail("Something is blocking your ability to commune with "
                  "your demonic masters.\n");
     return 0;
    }
 
  if(c<20)
    {
     message("my_action",
            "The demons hear your call, but ignore it and aid a more "
            "intriguing worshiper. ", this_player());
     message("other_action",
             "The air grows chill and the light lessens momentarily. ",
             environment(this_player()), this_player());
     this_player()->add_mp(-40);
     return 1;
    } 
     
   
   message("my_action",
         "%^BLACK%^%^BOLD%^"
         "The demons heed your request for aid and arrive in a cackling "
         "mass of horned flesh.%^RESET%^ ", this_player());
   message("other_action",
           "%^RED%^"
           "The earth opens and a host of demonic beings flow from the "
           "depths below. ", environment(this_player()), this_player());
   this_player()->add_mp(-b);
   this_player()->set_paralyzed(8, "You are too weak to do anything. "); 
   kataanlist = ({ });
   goodlist = ({ });
   evillist = ({ });
   list=all_inventory(environment(this_player()));
     for( d=0 ; d<sizeof(list) ; d++ ) {
      if(list[d]==this_player()) continue;
      if((string)list[d]->query_race()=="demigod") continue;
      if(!living(list[d])) continue;
      if(creatorp(list[d])) continue;
      if( (string)list[d]->query_class()=="kataan")
         kataanlist += ({ list[d] });
      else if ((int)list[d]->query_alignment()<0)
         evillist += ({ list[d] });
      else 
         goodlist += ({ list[d] }); }
   for(d=0;d<sizeof(kataanlist);d++) do_kataan(kataanlist[d]);
   for(d=0;d<sizeof(evillist);d++) do_evil(evillist[d]);
   for(d=0;d<sizeof(goodlist);d++) do_good(goodlist[d]);
   this_player()->add_skill_points("faith", group/5);
   return 1;
   }
 
//This spell will ignore perfectly neutral players and monsters.
 
void do_good(object ob)
  {
   message("other_action",
               "%^RED%^"
               "Cackling demons appear all around you! " 
               "Before you can run, they dive into your body burning " 
               "you to your soul!%^RESET%^", ob);
   message("other_action", 
           "%^CYAN%^%^BOLD%^"+
           (string)ob->query_cap_name()+" screams "
           "in agony as flaming spirits leap into "+
           ob->query_possessive()+" body. ", 
           environment(ob), ob);
         ob->add_mp(-((int)ob->query_max_mp())*2);
   for(e=0;e<random((int)caster->query_level()/2)+2;e++)
     {
         ob->add_alignment(-(random(30)+10));
     }
         ob->do_damage("torso", group);
         ob->set_paralyzed((int)ob->query_level()/2,
            "You are too busy fighting for control of your body! ");
         ob->kill_ob(caster, 0);             
     }
 
 
void do_evil(object ob)
  {
    group+=random(b)/2+20;
        ob->add_mp(-(b));
        message("other_action",
          "%^RED%^"
          "You cringe in terror as your future demonic masters draw "
          "strength from your body! To amuse themselves, they force "
          "you to attack their summoner.%^RESET%^ ", ob);
        message("other_action",
          "%^BLUE%^%^BOLD%^"+
          (string)ob->query_cap_name()+
          " screams in terror as shadowy forms rip bits of "
          "essence from "+ob->query_possessive()+" body.%^RESET%^ ", 
          environment(ob), ob);
        ob->kill_ob(caster, 0);             
   }
 
void do_kataan(object ob)
  {
   ob->add_mp(-b);
   group+=random(b)+50;
   message(
           "other_action",
           "%^RED%^%^BOLD%^"+
           (string)caster->query_cap_name()+
           " has summoned Demonfire! You feel the demons drawing "
           "strength from you as they prepare to destroy the good "
           "around you! %^RESET%^", ob
          );
   message(
           "other_action",
           "%^BLUE%^"+
           (string)ob->query_cap_name()+
           " writhes in pleasure as shadowy forms draw energy "
           "from "+ob->query_possessive()+" body.%^RESET%^ ", 
           environment(ob), ob
          );
       
       if(random(100)>50)
          {
           message("other_action",
            "%^RED%^%^BOLD%^Fangthane tells you:%^RESET%^ "
            "%^RED%^ Amuse me until I am freed. Attack my " 
            "summoner!%^RESET%^", ob);
           ob->kill_ob(caster, 0);
       }
  }
 
 
void help() 
 
  { 
   message("info",
       "Syntax: <demonfire>\n\n"
       "Those of high faith and attractive to their demonic masters "
       "may use this spell to purge the area around them of good "
       "creatures. It is rumored that the presence of more than "
       "one kataan increases the power of the summoned demons. ",
       this_player());
 }

