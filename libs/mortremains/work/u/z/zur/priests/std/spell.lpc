// The master priest spell object inherited by all priest spells.

#include "../pr.h"
string *sphere;
int level;
int cost;
int casting_time;
int reversible;
object trg;
object tp;

void create(){
  load_object(REL_D);
  }

varargs int start_spell(int rev, string arg){
 /*
  No checks for sp cost or anything yet.
  Nor do I know how to deal with casting time yet.
*/
 tp = this_player(); // To prevent repeated calls when uneeded.
 if(REL_D->check_sphere(tp, sphere, level) == 0)
 {
     
    write("You do not have access to any of the spheres required to cast that spell.\n");
    return 1;
 }
 if((int)REL_D->check_spheres(tp, sphere, level) == -1)
 {
    write("You only have minor access to the needed sphere(s)\nrequired to cast that spell.\n");
    return 1;
 }
 if(!REL_D->level_check((wizardp(tp)) ? -1 : tp->query_level(), level) )
 {
   return (int) notify_fail("You aren't of sufficient level to cast that spell.\n");
 }
 if(rev)
 {
   if (reversible){
   return (int)this_object()->reverse(arg);
   }
   return (int) notify_fail("That spell is not reversible.\n");
 }
   return (int) this_object()->main(arg);

 }
 
 void room_msg(string str){
   say(str, ({ tp, trg }));
    }
 void tell_tp(string str)
 {
   tell_object(tp, str);
     
 }
 void tell_targ(string str)
 {
   if(trg == tp) return;
   tell_object(trg, str);
 }
 string hirself(object ob){
   return objective(ob->query("gender"))+"self";
 }
 int query_level() { return level; }
 int query_reversible() { return reversible; }
 string *query_spheres() { return sphere; }
 
 
 
