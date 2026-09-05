inherit "obj/weapon";
int amt;

long() {
   write("A relic from a forgotten age in the long past. You notice an aura of\n");
   write("power surrounding it!\n");
   if(amt<1) {
      write("A relic from a forgotten age in the past. It appears old, but is\n");
      write("still capable of doing damage.\n");
      return 1; }
   return 1; }

decay() {
   write("The POWER Sword suddenly flashes brilliantly!!\n");
   say(capitalize(this_player()->query_real_name())+"'s POWER Sword suddenly flashes brightly!!\n");
set_name("dull sword");
set_short("A dull sword");
}

reset(arg) {
   if(!arg) {
      ::reset(arg);
      set_name("power sword");
      set_alt_name("sword");
      set_short("The POWER Sword");
      set_alias("blade");
      set_class(17);
      set_hit_func(this_object());
      set_weight(5);
      amt=this_player()->query_level()+random(20);
   }
}

weapon_hit(attacker) {
   while(amt>1){
      if (random(30) > 20) {
         write("Ka-Boom!\n\n");
say(capitalize(this_player()->query_real_name())+"'s Sword vibrates with awesome POWER!!\n");
         return 10;
         amt--;
         }
      write("BOOM!\n\n");
say(capitalize(this_player()->query_real_name())+"'s Sword slices through the air faster than the eye can follow!!\n");
      amt--;
      write("=========== "+amt+".\n");
      return 15;
   }
   if(amt < 0) return 0;
   if(amt == 1) {
      write("The Sword spins faster than the eye can follow as it discharges\n");
      write("Its last bit of power. The magical energy pouring forth is beyond\n");
      write("Belief!!!\n\n");
      say(capitalize(this_player()->query_real_name())+"'s "+
         "Sword spins faster than the eye can follow as it discharges\n");
      say("Its last bit of power. The magical energy pouring forth is beyond\n");
      say("Belief!!!\n\n");
      amt--;
      return 2000; }
   if(amt == 0) {
      decay();
      amt--;
      return 2000; }
}

query_value() {
  return 10000+(amt*500); }

query_save_flag() { return 1; }
