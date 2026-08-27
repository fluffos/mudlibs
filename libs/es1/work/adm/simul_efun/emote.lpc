/*
 * a generic emote simul_efun
 */

varargs int emote (object sender, string msg_self, string msg_others, 
		    mixed target, string msg_target, string extra)
{
  string act_name, target_name;
  string act_objective, target_objective, act_poss, target_poss;
  int has_extra;

  if (!sender || !(act_name = (string)sender->query_cap_name()))
    return 0;
  act_objective = (string)sender->query_objective();
  act_poss = (string)sender->query_possessive();
  msg_others = replace_string(msg_others, "{N}", act_name);
  msg_others = replace_string(msg_others, "{O}", act_objective);
  msg_others = replace_string(msg_others, "{P}", act_poss);
  msg_others = replace_string(msg_others, "{M}", extra);
  if (!target || !msg_target)
    {
      message(msg_others,"emote",environment(sender),sender);
      message(msg_self,"emote",sender);
      return 1;
    }
  if (!present(target,environment(sender)))
    {
      return 0;
    }
  if (!objectp(target))
    {
      if (stringp(target))
	{
	  target = find_living(target);
	}
      else return 0;
    }
  if (!(target_name = (string)target->query_cap_name()))
    return 0;
  target_objective = (string)target->query_objective();
  target_poss = (string)target->query_possessive();
  msg_others = replace_string(msg_others,"{n}", target_name);
  msg_others = replace_string(msg_others, "{o}", target_objective);
  msg_others = replace_string(msg_others, "{p}", target_poss);
  msg_self = replace_string(msg_self,"{n}",target_name);
  msg_self = replace_string(msg_self,"{o}",target_objective);
  msg_self = replace_string(msg_self,"{p}",target_poss);
  msg_self = replace_string(msg_self,"{M}",extra);
  msg_target = replace_string(msg_target,"{N}",act_name);
  msg_target = replace_string(msg_target,"{O}",act_objective);
  msg_target = replace_string(msg_target,"{P}",act_poss);
  msg_target = replace_string(msg_target,"{M}",extra);
  message (msg_others,"emote",environment(sender),({sender,target}));
  message (msg_self,"emote",sender);
  message (msg_target,"emote",target);
  return 1;
}

