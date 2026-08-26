/* A simple trap object that can be used to trap any item that uses
 * /std/basic/trap
 */

#include <tasks.h>

inherit OBJECT_OBJ;

int difficulty;
string trigger;
string description;
mixed message;
mixed effect;

/** @ignore yes */
void create() {
  add_help_file("door_trap");
  do_setup++;
  ::create();
  do_setup--;
  if ( !do_setup ) {
    TO->setup();
    TO->reset();
  }
}

void make_trap(int diff, string trig, string desc, mixed mess, mixed eff) {
  difficulty = diff;
  trigger = trig;
  description = desc;
  message = mess;
  effect = eff;
}

/** @ignore yes */
void init() {
  this_player()->add_command("rig", this_object(),
           "<indirect:object:here> with <direct:object:me>");
}

int do_rig(mixed *in_dir, string direct, string indirect, mixed *args,
             string) {
  object ob;
  object other;

  if(sizeof(in_dir) > 1) {
    this_player()->add_failed_mess(this_object(), "A trap can only be rigged "
                                   "on a single item.\n");
    if(creatorp(TP))
      tell_creator(this_player(), "In_dir: %O\n", in_dir);
    return 0;
  }

  if(!difficulty) {
    this_player()->add_failed_mess(this_object(), "$D appears to be "
                                   "broken.\n");
    return 0;
  }
    
  ob = in_dir[0];
  
  if(ob->query_trap_difficulty() && ob->query_trap_armed()) {
    this_player()->add_failed_mess(this_object(),
                                   "$I already has an armed trap on it.\n",
                                   ({ in_dir[0] }));
    return 0;
  }

  if(!function_exists("setup_trap", ob, 0)) {
    this_player()->add_failed_mess(this_object(), "$I cannot be $Ved with "
                                   "$D.\n", ({ ob }));
    return 0;
  }
    
  if((trigger == "pick" || trigger == "unlock") && 
     (!ob->query_key() || ob->query_key() == "generic_key")) {
    this_player()->add_failed_mess(this_object(), "$I doesn't have a lock "
                                   "so $Vging it with $D which is triggered "
                                   "by " + trigger + "ing makes no sense.\n",
                                   ({ ob }));
    return 0;
  }

  switch(TASKER->perform_task(this_player(), "covert.items.traps", difficulty,
                              TM_FREE)) {
  case AWARD:
    write("%^YELLOW%^You feel you have learned something about rigging "
          "traps.%^RESET%^\n");
  case SUCCEED:
    difficulty +=
      random(this_player()->query_skill_bonus("covert.items.traps") / 10);
    break;
  default:

    // Either it goes off, or they succeed but botch it somewhat :)
    if(random(difficulty) >
       this_player()->query_skill_bonus("covert.items.traps") ||
       difficulty >
       this_player()->query_skill_bonus("covert.items.traps") * 2) {

      // display the message
      if(arrayp(message)) {
        write(message[0]);
        say(message[1], this_player());
      } else
        write(message);

      // numeric, just reduce their hps.
      if(intp(effect)) {
        if(effect > this_player()->query_hp())
          this_player()->do_death();
        else
          this_player()->adjust_hp(-(effect));
      } else if(arrayp(effect)) { // array, then add an effect with params
        switch(sizeof(effect)) {
        case 1:
          this_player()->add_effect(effect[0]);
          break;
        case 2:
          this_player()->add_effect(effect[0], effect[1]);
          break;
        default:
          this_player()->add_effect(effect[0], effect[1..]);
        }
      } else
        this_player()->add_effect(effect);

      this_object()->move("/room/rubbish");
      this_player()->add_succeeded_mess(this_object(), "As $N attempt$s to "
                                        "$V $D it goes off!\n");
      return 1;
    } else {
      difficulty -= random(difficulty -
                    this_player()->query_skill_bonus("covert.items.traps"));
    }
  }

  ob->setup_trap(difficulty, trigger, description, message, effect);

  if(function_exists("query_my_room", ob)) {
    other = ob->query_dest();
    other = other->query_door_control(ob->query_other_id());
    
    other->setup_trap(difficulty, trigger, description, message, effect);
    environment(this_player())->update_doors();
  }
    
  this_player()->add_succeeded_mess(this_object(), "$N carefully $V $I "
                                    "with $D.\n",
                                    ({ ob }));
  call_out("break_me", 1);
  return 1;
}

void break_me() {
  set_short("busted trap");
  set_long("A broken trap.\n");
  difficulty = 0;
  set_value(0);
}
