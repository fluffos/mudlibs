wear(arg){
   if(arg=="aura"){
      if(this_player()->query_alignment() < 100) {
         write("You are not good enough to wear the aura.\n");
         return 1;
      }
      if(::wear(arg));
      write("The greatness of the aura surrounds you\n");
      say("The Aura hums as "+capitalize(this_player()->query_real_name())+" grasped the aura.\n");
      return 1;
   }
   if(arg != "aura"){
      return;
   }
}