#include <server.h>

varargs void
add_action_rule(string rule, string action, string func)
{
  funcall(bind_lambda(#'call_other, previous_object()),
          SE_ACTIONS, "action_rule_add", rule, action, func);
}

varargs void
remove_action_rules(mixed rules)
{
  funcall(bind_lambda(#'call_other, previous_object()),
          SE_ACTIONS, "action_rule_remove", rules);
}

varargs void
add_action_class(string class, string func, mixed handler)
{
  funcall(bind_lambda(#'call_other, previous_object()),
          SE_ACTIONS, "action_class_add", class, func, handler);
}

void
duplicate_action_class(string old, string new)
{
  funcall(bind_lambda(#'call_other, previous_object()),
          SE_ACTIONS, "action_class_duplicate", old, new);
}

void
add_action_error_message(string verb, mixed mess)
{
  funcall(bind_lambda(#'call_other, previous_object()),
          SE_ACTIONS, "action_error_message_add", verb, mess);
}

