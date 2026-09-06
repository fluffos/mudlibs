
/************************************************
 NAME:    duel_corpse.c

 PURPOSE: Protect dead players when dueling.

 AUTHOR:  Tron 
 ************************************************/
string name;
status entered;

status
query_virtual_room() { return 1; } //won't get destructed when
                                   //world is reseted.

string
query_name() { return name; }

status
id(string s) {
 
    if(s == "body") return 1;
    if(name && s == "body of "+name) return 1;
    return 0;
}

string
short() {
  if(this_object() == environment(this_player())) {
       return "Inside your corpse";
   }
  if(name) return "Dead body of "+capitalize(name);
  else return "Corpse";
}

status
get() { write("You wouldn't touch that.\n");  return 0; }
       
void
long(string s) {

  if(this_object() == environment(this_player())) {
     this_player()->tell_me("You feel safe here...safe enough to heal "+
           "before you return to the real world again. It's dark here "+
           "but somehow you know you are the soul in your own body. "+
           "Yes, you could 'leave' this dead body any time now.");
     return;
    }
  if(name) { 
     write(short()+".\n");
   }
   else write("Corpse.\n");
}

void
init() {

   if(entered && environment(this_player()) == this_object()) {
     move_object(this_player(), environment(this_object()));
     return;
    }
   else if(environment(this_player()) == this_object())
    entered = 1;

  if(this_object() == environment(this_player())) {
      this_player()->tell_me("What??? You are not dead? Somehow you "+
          "feel you are still alive.");
      set_light(1);
      name = (string)this_player()->query_real_name();
      this_player()->set_attacker(0);
      this_player()->set_alt_attacker(0);
       this_player()->set_hunted(0);
     this_player()->set_conditions(0);
      add_action("leave", "leave");
    }
}

status
leave() {

object *obs;
int i;

   write("ZZZZZZZzzzzzppp...\n");
   this_player()->move_player("X#/room/church");
   tell_room(environment(this_object()), short()+" vanishes.\n");

   obs = all_inventory(this_object());
   i = sizeof(obs);
   while(i--) {
      move_object(obs[i], "/room/church");
   }
   destruct(this_object());

   return 1;
}

int
object_died(object a, object b) {

   if(a)
	if ((int)a->query_hp() < 0) a -> add_hp(-((int)a->query_hp()));
  return 1;
}
