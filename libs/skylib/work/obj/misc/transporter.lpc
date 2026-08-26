/*  -*- LPC -*-  */
#define CREATOR "Ceres"

/* A little transporter thingy. It creates a gateway from a room to where a
   creator is and a reverse gateway back again. It is so that creators can
   transport players to their workroom and then have them return whence
   they came.
 */

inherit "/std/object";

object who;
object from, to;

void setup() {
  set_name("disc");
  set_short("dull, grey disc");
  add_adjective(({"dull", "grey"}));
  add_alias("transporter");
  add_read_mess(this_object());

  set_long("This is a small grey disc.  The surface is completely smooth "
           "and dull except for some strange characters engraved in the "
           "surface which seem to wiggle as you stare at them.\n");

  set_read_mess("Ceres wonderful transporter.\n\nThis object will open a "
                "portal between you and player allowing them to travel "
                "to you and then return from where they came.\n"
                "You can 'transport <player>' to allow them to come to you "
                "or 'force <player>' to forcibly bring them to you.  "
                "'remove portal' will remove an open portal.\n");
  set_weight(5);
}

void init() {
  this_player()->add_command("transport", this_object(),
                             "<indirect:any-living>");
  this_player()->add_command("force", this_object(),
                             "<indirect:any-living>");
  this_player()->add_command("remove", this_object(), "portal");
}

int do_force(object *in_dir, string direct, string indirect, mixed args,
                 string format) {
  if(from || to || who) {
    this_player()->add_failed_mess(this_object(),
                                      "$N cannot create a magic portal for $I "
                                      "as one already exists.\n",
                                      ({in_dir[0]}));
    return 0;
  }
    
  from = environment(in_dir[0]);
  to = environment(this_player());
  who = in_dir[0];
  
  tell_room(from, "The air warps and buckles momentarily and a shimmering "
            "portal appears, floating in the air.\n");

  tell_room(to, "The air warps and buckles momentarily and a shimmering "
            "portal appears, floating in the air.\n");
  
  from->add_exit("portal", to, "path");
  from->modify_exit("portal", ({"function", ({ this_object(), "enter_fun"}),
                                "look", "Inside, the portal is hazy and "
                                  "indistinct.",
                                "message", "$N steps into a portal and "
                                  "disappears.\n",
                                "enter", "$N falls out of a magical portal.\n"
                                }));
  who->move_player("portal", to,
                   "$N steps into a portal and disappears.\n",
                   0, "$N falls out of a magical portal.\n");
  
  to->add_exit("portal", from, "path");
  to->modify_exit("portal", ({"function", ({this_object(), "exit_fun"}),
                              "look", "Inside, the portal is hazy and "
                                "indistinct.",
                              "message", "$N steps into a portal and "
                                "disappears.\n",
                              "enter", "$N falls out of a magical portal.\n"
                              }));
  
  this_player()->add_succeeded_mess(this_object(),
                                    "$N uses $D to create a magical portal "
                                    "for $I\n", ({in_dir[0]}));
  return 1;
}

int do_transport(object *in_dir, string direct, string indirect, mixed args,
                 string format) {
  if(from || to || who) {
    this_player()->add_failed_mess(this_object(),
                                      "$N cannot create a magic portal for $I "
                                      "as one already exists.\n",
                                      ({in_dir[0]}));
    return 0;
  }
    
  from = environment(in_dir[0]);
  to = environment(this_player());
  who = in_dir[0];
  
  tell_room(from, "The air warps and buckles momentarily and a shimmering "
            "portal appears, floating in the air.\n");

  tell_room(to, "The air warps and buckles momentarily and a shimmering "
            "portal appears, floating in the air.\n");
  
  from->add_exit("portal", to, "path");
  from->modify_exit("portal", ({"function", ({ this_object(), "enter_fun"}),
                                "look", "Inside, the portal is hazy and "
                                  "indistinct.",
                                "message", "$N steps into a portal and "
                                  "disappears.\n",
                                "enter", "$N falls out of a magical portal.\n"
                                }));
  to->add_exit("portal", from, "path");
  to->modify_exit("portal", ({"function", ({this_object(), "exit_fun"}),
                              "look", "Inside, the portal is hazy and "
                                "indistinct.",
                              "message", "$N steps into a portal and "
                                "disappears.\n",
                              "enter", "$N falls out of a magical portal.\n"
                              }));
  
  this_player()->add_succeeded_mess(this_object(),
                                    "$N uses $D to create a magical portal "
                                    "for $I\n", ({in_dir[0]}));
  return 1;
}

int enter_fun(string str, object ob, string special_mess) {
  if(ob != who)
    return notify_fail("You try to enter the portal but an unseen force "
                       "prevents you from doing so.\n");

  tell_object(ob, "As you step up to the portal you feel it suck you "
              "through.  "
              "It feels rather like being drunk - from the drink's point of "
              "view!\n");
  return 1;
}

int exit_fun(string str, object ob, string special_mess) {
  if(ob != who)
    return notify_fail("You try to enter the portal but an unseen force "
                       "prevents you from doing so.\n");

  tell_object(ob, "You step up to the portal you feel it suck you through.  "
              "It feels rather like being drunk - from the drinks point of "
              "view!\n");

  call_out("do_remove", 2);
  return 1;
}

int do_remove() {
  if(!from || !to)
    return notify_fail("There is no portal to remove.\n");
  
  tell_room(from, "The air warps and buckles momentarily and the portal "
            "disappears with a sucking, squelching pop.\n");

  tell_room(to, "The air warps and buckles momentarily and the portal "
            "disappears with a sucking, squelching pop.\n");
  
  from->remove_exit("portal");
  to->remove_exit("portal");

  who = from = to = 0;

  return 1;
}
