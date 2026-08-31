#define TP this_player() 
#define TPC TP->query_con()
#define TPI TP->query_int()
#define E environment 

object monksoul;

start_meditate(soul) {
  if(!soul) return;
  call_out("heal_me",2);
  soul->set_meditate(1);
  monksoul=soul;
}

drop() { return 1; }

init() {
  add_action("nil","",1);
}


nil(arg) { 
  switch(query_verb()) {
   case "mt":
   case "monk":
   case "ring":
    case "ering":
   case "help":
   case "quit":
   case "vitals":
   case "alias":
   case "hp":
   case "who":
   case "cure":
   case "score":
   case "look":
   case "say":
  case "'":
   case "whisper":
   case "i":
   case "l":
   case "me":
   return;
   case "wakeup":
{  write("You stop meditating.\n");
       dest_me(); 
   return 1;
    }   
   default:
   write("You can't do that while meditating <just type wakeup to stop>.\n");
  }
  return 1;
}

heal_me() {
   int max;

  if (TPI>TPC) {
     max = 1 + TPI/13;
    }
   else {
     max = 1 + TPC/13;
   }
  E()->heal_self(max);
  call_out("heal_me",3);
}

dest_me() {
  tell_room(E(E()),E()->query_name()+
           " stops meditating.\n");     
  monksoul->set_meditate(0);
  destruct(this_object());
  return 1;
}
