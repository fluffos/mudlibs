/* Hamlet -- friendly little noncombat room */
inherit "/std/room";

int noheal = 0;
int noquit = 0;
int nonpc = 1;

void create() {
  ::create();
  add_property("nocast",1);
  add_property("noguild",1);
  add_property("no_undead",1);
  add_property("STAY_OUT",1);
   add_property("noncombat",1);  //Khelben, for knowing if we are in a noncombat room.
}

void init() {
  ::init();
  add_action("dweeb","kill");
  add_action("dweeb","skull");
  add_action("dweeb","attack");
  add_action("dweeb","berserk");
  add_action("person_quits","quit");
}

void no_heal() { noheal = 1; }
void no_quit() { noquit = 1; }
void allow_npcs() { nonpc = 0; }

int dweeb(string whatever) {
  tell_object(this_player(),"Fighting is not allowed here.\n");
  return 1;
}

int person_quits() {
  if(noquit) {
    tell_object(this_player(),"You may not quit in this room.\n");
    return 1;
  }
  
  return 0;
}

int test_add(object ob, int flag) {
  int FIGHTING = 0;
  int CASTING = 0;
  int i;
  object *atlst = ob->query_attacker_list() + ob->query_call_outed();
  mixed casts = ob->query_spell_effects_type("offensive");
  
  if(!interactive(ob) && living(ob) && nonpc) {
    return 0;
  }

  if(ob->query_property("flipped")) {
    tell_object(ob,"You are currently berserked.  You may not "
                "enter that room until you have\nstopped.\n");
    return 0;
  }

  for(i=0;i<sizeof(atlst);i++)
    if(interactive(atlst[i])) {
      FIGHTING = 1;
      break;
    }

  if(FIGHTING) {
    tell_object(ob,"You may not enter that room until you "
                "stop your fights.  Type 'stop' now.\n");
    return 0;
  }

  if(sizeof(casts))
    for(i=1;i<sizeof(casts);i+=2)
      if(sizeof(casts[i])) {
        CASTING = 1;
        break;
      }
  
  if(CASTING) {
    tell_object(ob,"You may not enter that room until you "
                "finish your spell.\n");
    return 0;
  }
  
  return ::test_add(ob,flag);
}

void event_enter(object ob, string mess, object from) {
  if(interactive(ob) && noheal)
    ob->set_no_heal();
}

void event_exit(object ob, string mess, object to) {
  if(interactive(ob) && noheal)
    ob->set_heal();
}
