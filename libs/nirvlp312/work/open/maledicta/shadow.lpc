#include "/players/maledicta/ansi.h"
#define VENOM present("venom_object", targ)

object targ;

shadow_symbon(object a) {
  if(!a) return 1;
  targ = a;
  shadow(targ,1);
  return 1;
}

shadow_symboff() {
  shadow(targ,0);
  destruct(this_object());
  return 1;
}

destruct_this_shadow(){
destruct(this_object());
return 1;
}

short(){
 if(targ){
 if(VENOM){
 if(VENOM->query_venomed()){
  return BOLD+capitalize(VENOM->query_symbiote())+"   ("+NORM+HIR+" Symbiote "+NORM+BOLD+")"+
  "            <"+targ->query_name()+">"+NORM;
    }
   }
 }
 else{
  return targ->short();
  }
  return targ->short();
 }

add_exp(arg) {
if(targ->query_exp() < VENOM->query_best_xp()){
targ->add_exp(arg);
return 1;
}
if(arg > 100){
targ->add_exp(arg - (arg / 3));
}
else{
targ->add_exp(arg);
}  
return 1; }

query_symb_shadow() { return 1; }
