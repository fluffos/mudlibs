/****************************************************************************
	  help action for other actions -- by Ugh 1995 for Tubmud
****************************************************************************/

#pragma strong_types

#include <global_actions.h> 

inherit "basic/action";

void create() {
  action::create();
  set_command("help");
  set_specific("action");
  set_function("command_help");
}

mixed init_living(object ob) {
  return ({({ "help", 0, "command_help" })});
}

status command_help(string topic) {
  int i;
  string *handlers, *action, text, act;
  status result;

  handlers = 
    ACTION_DAEMON->find_instance(this_player())->query_action_handlers();
  for (i = sizeof(handlers); i--; ) {
    action = handlers[i]->query_actions();
    if (topic != (act = implode(action[0..1]," ")) && topic != action[0])
      continue;
    text = act + ":\n" + handlers[i]->query_info();
    if (!call_resolved(&result, this_player(), "tell_more", text))
      tell_object(this_player(), text);
    result = 1;
  }
  return result;
}

