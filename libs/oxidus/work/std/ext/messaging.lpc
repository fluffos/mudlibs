// /std/ext/messaging.c
// This module is heavily influenced by Lima's messaging system.
//
// Created:     2024/02/03: Gesslar
// Last Change: 2024/02/03: Gesslar
//
// 2024/02/03: Gesslar - Created

#include "include/messaging.h"

// Variables
private nosave int _contents_can_hear = 1, _environment_can_hear = 1;

void receive_message(string _type, string msg) {
  do_receive(msg, DIRECT_MSG);
}

// This function enables messages to be propogated to the contents of an object
int set_contents_can_hear(int i) {
  _contents_can_hear = !!i;
  return i;
}

// This function enables messages to be propogated to the environment of an object
int set_environment_can_hear(int i) {
  _environment_can_hear = !!i;
  return i;
}

// This function returns the value of the _can_hear_contents variable
int query_contents_can_hear() {
  return _contents_can_hear;
}

// This function returns the value of the _can_hear_environment variable
int query_environment_can_hear() {
  return _environment_can_hear;
}

// tell_up() is a function that sends a message to the environment of an object
// and all of the contents of that object, excluding the object passed as the
// second argument.
varargs void receive_up(string msg, object *exclude, int msg_type) {
  do_receive(msg, msg_type);

  if(!query_environment_can_hear())
    return;

  if(objectp(exclude))
    exclude = ({ exclude });

  if(!pointerp(exclude))
    exclude = ({});

  exclude += ({ this_object() });

  /** @type {EXT_MESSAGING} */ object env = environment();
  if(env) {
    /** @type {EXT_MESSAGING*} */ object *contents = all_inventory(env);
    contents -= exclude;
    contents->receive_up(msg, exclude, msg_type);

    if(member_array(env, exclude) == -1) {
      exclude += ({ env });
      env->receive_up(msg, exclude, msg_type);
    }
  }
}

// tell_down() is a function that sends a message to all of the contents of an
// object, excluding the object passed as the second argument.
varargs void receive_down(string msg, object *exclude, int msg_type) {
  do_receive(msg, msg_type);

  if(!query_contents_can_hear())
    return;

  if(objectp(exclude))
    exclude = ({ exclude });

  if(!pointerp(exclude))
    exclude = ({});

  /** @type {EXT_MESSAGING*} */ object *contents = all_inventory();
  contents -= exclude;
  contents->receive_down(msg, exclude, msg_type);
}

// tell_all() is a function that sends a message to the environment of an object
// and all of the contents of that object, excluding the object passed as the
// second argument.
varargs void receive_all(string msg, object *exclude, int msg_type) {
  if(objectp(exclude))
    exclude = ({ exclude });

  if(!pointerp(exclude))
    exclude = ({});

  // If we've already received this message, don't propagate further
  if(member_array(this_object(), exclude) != -1)
    return;

  do_receive(msg, msg_type);

  if(!query_environment_can_hear() && !query_contents_can_hear())
    return;

  exclude += ({ this_object() });

  /** @type {EXT_MESSAGING} */ object env = environment();
  if(env && member_array(env, exclude) == -1) {
    exclude += ({ env });
    env->receive_all(msg, exclude, msg_type);
  }

  /** @type {EXT_MESSAGING*} */ object *contents = all_inventory() - exclude;

  if(sizeof(contents)) {
    contents->receive_all(msg, exclude, msg_type);
  }
}

varargs receive_direct(string msg, int message_type) {
  do_receive(msg, message_type);
}

void do_receive(string message, int message_type) {
  string term;

  if(userp()) {
    term = this_object()->query_pref("colour");
    // If colour is not explicitly enabled, set NO_COLOUR to disable
    // coloured messages.
    switch(term) {
      case "on" :
        term = "on";
        break;
      case "off" :
        term = "off";
        message_type |= NO_COLOUR;
        break;
      default:
        term = "off";
        message_type |= NO_COLOUR;
        break;
    }

    if(!(message_type & NO_COLOUR))
      message = COLOUR_D->bod_colour_replace(this_object(), message, message_type);
  } else {
    // For non-user objects, also disable coloured messages.
    message_type |= NO_COLOUR;
  }

  // If NO_COLOUR flag is set, substitute colours with "off" (i.e., no
  // colour).
  if(message_type & NO_COLOUR)
    message = COLOUR_D->substitute_colour(message, "off");
  else
    message = COLOUR_D->substitute_colour(message, term);

  if(function_exists("query_environ")) {
    string encoding;

    if(query_environ("SCREEN_READER"))
      encoding = "screenreader";
    else if(query_environ("UTF-8"))
      encoding = "UTF-8";
    else
      encoding = "US-ASCII";

    message = LINES_D->substitute_lines(message, encoding);
  }

  receive(message);

  if(this_body() && this_body() != this_object())
    event(({this_object()}), "message", message, message_type, this_body());

  // Handle telnet go-ahead if it's a prompt.
  if(message_type & MSG_PROMPT)
    send_ga();
}

void send_ga() { if(interactive()) telnet_ga(); }
