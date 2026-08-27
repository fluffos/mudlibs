/*** Mystic heal Shadow by Shaury    ***/ 
/*** -> based in a Wonderflug shadow ***/ 
 
#include "/d/gremios/hechizos/cleric/tweaks.h" 
 
object myplayer; 
int hps; 
 
void destruct_mystic_heal_shadow() { 
   destruct(this_object()); 
} 
 
void setup_shadow(object ob) { 
   shadow(ob,1); 
   myplayer = ob; 
   hps=(int)ob->query_max_hp()-(int)ob->query_hp();    ob->adjust_hp(hps,ob); 
} 
 
int check_duration() { 
   if(! (myplayer->query_timed_property("mystic_heal_on")) ) { 
      myplayer->adjust_hp(-hps-random(5)-1,myplayer); 
      tell_object(myplayer,"The mystic powers that were healing " 
        "you fades, and with it, some of your lifeforce fades.\n"); 
      if(hps>50) 
      tell_object(myplayer,"You get serious damage.\n"); 
      tell_room(environment(myplayer), 
         "The mystic powers that were healing "+ 
        (string)myplayer->query_cap_name()+" fades " 
         "from "+(string)myplayer->query_objective()+".\n",myplayer); 
      myplayer->remove_extra_look(this_object()); 
      return 1; 
  } 
  else return 0; 
} 
 
move(mixed dest,mixed messout,mixed messin) { 
   if(check_duration()) 
      call_out("destruct_mystic_heal_shadow",0,0); 
   return myplayer->move(dest, messout, messin ); 
} 
 
int adjust_hp(int amount, object hitter) 
{ 
  if ( amount > 0 ) 
        return myplayer->adjust_hp(amount, hitter); 
  if ( check_duration() )         call_out("destruct_mystic_heal_shadow",0,0); 
  return myplayer->adjust_hp( amount, hitter ); 
} 
   
string extra_look() { 
   if (check_duration()) 
      call_out("destruct_mystic_heal_shadow",0,0); 
   return (string)myplayer->query_pronoun() +" has a mystic cure.\n"; 
} 
 
int set_hp(int amount, object hitter) 
{ 
  if ( amount >= (int)myplayer->query_hp() ) 
        return myplayer->set_hp(amount, hitter); 
 
  if ( check_duration() ) 
        call_out("destruct_mystic_heal_shadow",0,0); 
  return myplayer->adjust_hp( 
                (int)myplayer->query_hp()-amount); 
} 
 
varargs mixed move_player(string dir, string dest, mixed message, 
  object followee, mixed enter) { 
  if ( check_duration() ) 
        call_out("destruct_mystic_heal_shadow",0,0); 
  return myplayer->move_player( dir, dest, message, followee, enter); 
} 
 
int query_mystic_heal_spell() { return 1; } 
 
void dispell_me() 
{ 
  myplayer->remove_extra_look(this_object()); 
  destruct(this_object()); 
} 
 
