/*
 * complex/window.c,
 * originally written by Ugh for Tubmud, Nov-1995
 * ported and adapted by Chameloid for Tubmud, Mar-1999
 *
 */

#include <global_commands.h>  // added global_, Coogan, 02-May-2001
#include <grammar.h>
#include <describe.h>
#include <message.h>
#include <event.h>
#include <prop/player.h>
#include <exits.h>              // Coogan, 03-Mar-2006

#define STANDARD_DIRS ({ "north","northeast","east","southeast","south",\
                         "southwest","west","northwest" })

#define CANCEL_PRIO 300         // must be the same as in complex/door!

inherit "complex/door";

private        status outside = 0;
private nosave string window_view;     // a filename
private nosave status enterable = 1;

status query_outside() {
  return outside;
}

void set_inside() {
  outside = 0;
}

void set_outside() {
  outside = 1;
}

string query_window_view() {  // Coogan, 19-May-2003
  return window_view;
}

void set_window_view(string s) {  // Coogan, 19-May-2003
  window_view = s;
}

status query_enterable() {  // Coogan, 19-May-2003
  return enterable;
}

void set_enterable(status s) {  // Coogan, 19-May-2003
  enterable = s;
}

string window_extra_long() {
  return "There is "+ describe(this_object(),ARTICLE_A) +".\n";
}

void configure() {
  door::configure();
  set_id(({ "window" }));
  set_name("window into nothingness");
  set_short(0);
  set_extra_long(#'window_extra_long);
  set_door_type(EXIT_TYPE_WINDOW);  // Coogan, 03-Mar-2006
  listen_event("move",EPRIO_MODIFY);
}

void init() {
  door::init();
  add_action_rule("look through "G_OBJECT,"look_through_window");
  if (query_enterable()) {
    add_action_rule("climb through "G_OBJECT,"climb_window");
    if (outside) {
      add_action_rule("climb into "G_OBJECT,"climb_window");
      add_action_rule("climb in "G_OBJECT,"climb_window");
      add_action_rule("look in "G_OBJECT,"look_through_window");
      add_action_rule("look into "G_OBJECT,"look_through_window");
    } else {
      add_action_rule("climb out of "G_OBJECT,"climb_window");
      add_action_rule("climb out "G_OBJECT,"climb_window");
      add_action_rule("look out "G_OBJECT,"look_through_window");
      add_action_rule("look out of "G_OBJECT,"look_through_window");
    }
  }
}

status door_move_hook(string str, status silently) {
  return door::door_move_hook(str, silently);
}

varargs void set_door_exit(mixed where, string dir, mixed hook, mixed flags,
                           mixed dir_str) {
  if (member(STANDARD_DIRS,dir) >= 0) {
    set_name("window in the "+ dir +"ern wall");
    set_id(({ "window",dir +" window",dir +"ern window","window "+ dir }));
  } else {
    set_name("window "+ dir);
    set_id(({ "window",dir +" window","window "+ dir }));
  }
  door::set_door_exit(where,dir,hook,flags,dir_str);
}

varargs void set_window_exit(mixed where, string dir, mixed hook, mixed flags,
                            mixed dir_str) {
  set_door_exit(where,dir,hook,flags,dir_str);
}

void set_window_short(mixed s) {
  set_door_short(s);
}

void set_window_long(mixed s) {
  set_door_long(s);
}

private string window_view() {
  object dest;
  string view;

  dest = (window_view && load_object(window_view)) || get_destination();
  if (dest)
    view = COMMANDS_LOOK->look_at_room(dest, 0,
                                      this_player()->query_property(P_COMBINED),
                                      this_player());
  return view || "Nothing.\n";
}

// spaces clipped off the string-ends -- Ugh Apr-12-1999
private string get_preposition_string() {
  if (outside)  
    return "into";
  else
    return "out of";
}

// mixed to int, Coogan, 27-Mar-2011
int do_action(string action,mapping args) {
  string tmp;
  if (args[G_OBJECT] != this_object())
    return 0;
  switch (action) {
  case "climb_window":
    return query_enterable() && pass_door(0);
  case "look_through_window":
    message(({({ M_PL_THE, M_PL_VERB, "look", " "+get_preposition_string()+" ",
                 M_ME_THE, "." }),
              ({ M_RAW, M_WRITE, #'window_view })}));
    return 1;
  case "leave":  // Coogan, 19-May-2003
    if (!query_enterable()) {
      message("The window is too high above the ground to leave through it.\n");
      return 1;
    }
    // fall through
  default: 
    return door::do_action(action,args);
  }
  NO_WARN_MISSING_RETURN;  // Coogan, 27-Mar-2011
}

void receive_event(mapping e,string type,int prio) {
  switch (type) {
  case "look":  // added this case, Coogan, 08-Apr-2003
    if (prio == CANCEL_PRIO) {
      if (e[E_TYPE] == "look_into")
        return;
    }
    break;
  case "move":
    if ((e[E_DIR] != "X")               &&
        (e[E_FROM] == environment())    && 
        (e[E_TO] == get_destination())  &&
        query_open()                    &&  // Coogan, 04-Mar-2006
        e[E_DIR] != query_verb()) {         // and this check too
      e[E_OUT] = ({ M_THE,M_ARG,E_AGENT,M_VERB,"climb",M_ARG,E_AGENT, 
                    " "+get_preposition_string()+" ",
                    M_THE,this_object(),"." });
      e[E_IN] = ({ M_THE,M_ARG,E_AGENT,M_VERB,"climb",M_ARG,E_AGENT, 
                   // check for outside -- Ugh Apr-12-1999
                   (query_outside() ? " in through " : " out of "),
                   M_THE,(get_other_door() || M_ME),"." });
    }
  }
  door::receive_event(e,type,prio);
}

