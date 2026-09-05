inherit "obj/weapon";
int i,x;
reset(arg) {
   ::reset(arg);
if(arg) return;
       set_alias("scalpel");
       set_name("Scalpel of Hawkeye");
       set_short("Hawkeye's Scalpel");
       set_long("A very powerful and sharp Scalpel of Hawkeye.\n");
         set_class(18);
         set_weight(1);
         set_value(10000);
       set_hit_func(this_object());
}
weapon_hit(attacker) {
if(this_player()->query_alignment() > 500) {
say(this_player()->query_name() + " slices his opponent to pieces with his scalpel!\n");
  write("You slice your opponent to pieces with your scalpel!\n");
  i = random(9);
  x= 0;
  x= i + 9;
}
   return x;
}
