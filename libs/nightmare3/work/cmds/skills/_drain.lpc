/*
             Drain -
  Coded by Zaknaifen@Nightmare on 3-2-94 for
  the Darkside.
*/
 
 
#include <std.h>    
 
inherit DAEMON;
 
void do_dumb(object ob);
void do_other(object ob);
 
int cmd_drain(string str)
  {
  
  int x, y, z, magic, factor1, factor2, final;
  string *traits;
  object ob;
  
  
  x=(int)this_player()->query_skill("faith"); 
  y=(int)this_player()->query_stats("intelligence");
  z=(int)this_player()->query_stats("wisdom");  
  magic=(int)this_player()->query_mp();  
  
  if((string)this_player()->query_class()!="kataan")
   {
    do_other(this_player());
    return 1;
   }
   
  if(x<30)
   {
    message("my_action", 
            "%^RED%^%^BOLD%^Fangthane tells you:%^RESET%^ "
            "Perhaps when you have more faith I will allow "
            "you to do what you desire.\n", this_player());
    return 1;
   }
  
   if(y<20)
     {
      do_dumb(this_player());
      return 1;
     }
   
   if(!str)
     {
      notify_fail("You recall from your teachings that you must drain "
                  "a specific item.\n");
      return 0;
     }
 
   if(!(ob=present(str, this_player())) )
     {
      notify_fail("You do not possess that object.\n");
      return 0;
     }
 
   traits=(string *)ob->query_property("magic item");
   
   if(!traits) 
    {
     notify_fail("You may only drain the magic from an item that has " 
                 "magic to begin with.\n");
     return 0;
    }
   
   if(magic<10)
     {
      notify_fail("You lack the magical energy required to do that.\n");
      return 0;
     }
   
   message("my_action",
         "%^CYAN%^%^BOLD%^"
         "You call upon your demonic masters to transfer the magical " 
         "strength from your "+str+" to your body.%^RESET%^ ",
         this_player());
   message("other_action",
           "%^RED%^The area around you takes on a reddish-hue as "+
           (string)this_player()->query_cap_name()+" raises an object "
           "above "+this_player()->query_possessive()+" head. The air "   
           "around "+(string)this_player()->query_cap_name()+" crackles "
           "with power as the object disappears!%^RESET%^ ",
           environment(this_player()), this_player());
   factor1=sizeof(traits);
   factor2=x/2+y/2+z/2;
   final=factor2*factor1*random(3)+1;
   if(final<=5)
     {
       final=random(25)+10;
     }
   this_player()->add_skill_points("faith", final);
   present(lower_case(str), this_player())->remove();
   this_player()->add_hp(final);
   this_player()->add_sp(final);
   this_player()->add_alignment(-final);
   this_player()->add_mp(-10);
   return 1;
 }  
 
 
void do_other(object ob)
  {
   
//Done to reflect the fact that summoning demons is not
//something someone other than Kataans would do.
//Zaknaifen
   
   message("my_action", 
      "%^BLACK%^%^BOLD%^"
      "Chaotic visions fill your mind and threaten to drive you mad! "
      "The demons you have summoned run rampant in your mind and "
      "take a piece of it with them before leaving you! ", ob);
   message("other_action",
       "%^CYAN%^"+
       (string)ob->query_cap_name()+" falls to "+
       (string)this_player()->query_possessive()+" knees, screaming "
       "in agony.%^RESET%^ ", environment(ob), ob);
   ob->do_damage("head", random(80)+20);
   ob->add_stat_bonus("intelligence", -10);
   ob->add_stat_bonus("wisdom", -10);
   return;
  }
 
 
 
void do_dumb(object ob)
  {
   
//Done to reflect the fact that dealing with demons is inherently
//dangerous and not to be attempted by the weak of will.
//Zaknaifen
   
   
   message("my_action",
      "%^RED%^"
      "You are engulfed in flame as you lose control of the summoning "
      "process!%^RESET%^ ", ob);
   message("other_action", 
       "%^RED%^"+
       (string)ob->query_cap_name()+" screams as "+
       (string)ob->query_subjective()+" is engulfed in flames! "
       "You hear the sound of cackling as the flames wink out of " 
       "existance. ", environment(ob), ob);
   ob->do_damage("torso", random(30)+50);
   return;
  }
 
 
void help()
  {
   message("info",
     "\n"
     "%^RED%^                            -=Drain=-%^RESET%^\n\n"
     "Calls upon the demons of the nether realms to act as "
     "a conduit for magic power, enabling the caster to transfer "
     "the magic contained in items into his/her own body. "
     "The process is not for the dull-witted, or those without "
     "faith.\n"
     "\n%^RED%^"
     "Syntax:  drain <item_name>%^RESET%^\n", this_player());
  }
 
 
 
 
 
 
