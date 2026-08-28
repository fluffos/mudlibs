inherit "/std/weapon";
 
create() {
    ::create();
   set_id( ({ "dagger", "a dagger", "a jagged-edged dagger",
	      "jagged-edged dagger"}) );
   set_name("dagger");
   set_short("a jagged-edged dagger");
   set("long", "This wicked-looking dagger seems to glow with an inner "
       "power. It certainly has not been designed for a clean "
       "kill, its blade is sharp and serrated to inflict a truely "
       "grievous wound.");
   set_weight(275);
   set("value", 100);
   set_type("knife");
   set_hit_func(this_object());
}
 
int weapon_hit(object ob) {
  int i;
  i=random(5);
  if( (string)this_player()->query_class() == "rogue")
    return i;
  return 0;
}
