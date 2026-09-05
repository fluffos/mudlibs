inherit "obj/weapon";
int i;
reset(arg) {
   ::reset(arg);
   if(arg) return;
      set_alias("stick");
	set_short("An Example stick");
	set_long("A suprisingly strong stick!\n");
	set_class(18);
	set_weight(3);
	set_value(1000);
	set_name("example stick");

      set_hit_func(this_object());
}
weapon_hit(attacker) {
  i=random(10);
  if (i>5) {

	say(this_player()->query_name()+"'s stick hits suprisingly hard!\n");
	write("You hit hard with your stick.\n");
  return 1;
    }
   return 0;
}
