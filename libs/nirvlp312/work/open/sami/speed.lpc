#define USER user
#define USERN user->query_name()
#define USERRN user->query_real_name()
#define POS query_possessive()
#define OBJ query_objective()
#define PRO query_pronoun()
#define USERPO user->POS
#define USERPR user->PRO
#define USEROB user->OBJ
#define ATT user->query_attack()
#define ATTPO ATT->POS
#define ATTPR ATT->PRO
#define ATTOB ATT->OBJ
#define ATTN ATT->query_name()
#define ATTRN ATT->query_real_name()->> 
#include "/sys/ansi.h"

main(object user, object wep, string name, string short){
  int dam;
  string message;
if(random(100) > 40) {
    return 0; 
  }
  if(!present(ATT, environment(USER))) { 
    return 0; 
  }
dam = random(40) +15;
  message = wep->query_message_hit(dam);
  tell_room(environment(user),
  HIK+USERN+"'s form "+HBCYN+" B L U R S "+HIK+"!!!!"+NORM+"\n");
  wep->set_gen_bonus(dam);
  tell_object(USER,"You "+message[1]+" "+ATT->query_name()+""+message[0]+".\n");

  tell_object(ATT, USER->query_name()+" "+message[1]+" you"+message[0]+".\n");
  tell_room(environment(USER), USER->query_name()+" "+message[1]+" "+ATT->query_name()+message[0]+".\n", ({USER, ATT}));
  return 0;
}