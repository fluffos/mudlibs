inherit MONSTER;
void create(){
  ::create();
  set("short", "A test monster.");
  set("long", "Nothin' special about it.\n");
  set("id", ({ "monster", "mn" }));
  set_verbs(({ "swing at", "punch at" }));
  set_name("monster");
  set_level(1);
  }
  
int force_me(string cmd) {
   int res;
   if(interactive(this_object()))
        cmd = (string)this_object()->process_input(cmd);
   res = command(cmd);
   return res;
}


