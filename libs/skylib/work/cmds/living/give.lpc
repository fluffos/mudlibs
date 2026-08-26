/* command, trial out by Turrican for a commands daemon. */

#include <move_failures.h>

inherit COMMAND_BASE;

mixed cmd(mixed *indir, string *indir_match) {
  string sh, s1;
  int tot, max;
  object *per, *ret, *fail, pobj, ob, *obs, *succ;

  per = indir[1];
  succ = ({ });
  foreach(pobj in per) {
    obs = indir[0];
    obs -= per;

    if (pobj->query_property("player") && !interactive(pobj)) {
      tell_object(TP, pobj->the_short()+" seems too chalky to accept your "
                  "gift.\n");
      continue;
    }

    if (pobj == TP)
      continue;

    // Check for multiplayers giving items to each other.
    if(pobj->query_property("player") &&
       query_ip_number(TP) == query_ip_number(pobj) &&
       sizeof("/handlers/multiplayer"->check_allowed(TP, ({ pobj })))) {
      sh = capitalize(TP->query_name())+ " gave " +
        query_multiple_short(obs) +
        " to " + pobj->query_name() + " while logged in from the same IP "
        "address.";
      user_event("inform", sh, "multiplayer");
      log_file("MULTIPLAYERS", ctime(time()) + ": " + sh + "\n");
    }
    
    if (!sizeof(obs)) {
      tell_object(TP, "Nothing to give to "+ pobj->short() +".\n" );
      continue;
    }
    ret = ({ });
    fail = ({ });
    foreach(ob in obs) {
      if ( member_array( ob, succ ) > -1 )  continue;
      if (function_exists("do_give", ob) ||
          function_exists("command_control", ob)) {
        if (function_exists("do_give", ob))
          max = call_other(ob, "do_give", pobj, indir_match[0],
                                indir_match[1],
                                ({ indir_match[0], indir_match[1] }),
                                "<direct:object:me> to <indirect:living>");
        else
          max = ob->command_control("give", pobj, indir_match[0],
                                    indir_match[1],
                                    ({ indir_match[0], indir_match[1] }),
                                    "<direct:object:me> to <indirect:living>");
        if (max == 0)  {
          fail += ({ ob });
          continue;
        }
      }
      if (pobj->query_closed()  ||  ob->move(pobj) != MOVE_OK) {
        fail += ({ ob });
      }
      else  {
        ret += ({ ob });
        tot += ob->query_weight();
      }
    }
    if (sizeof(ret)) {
      succ += ret;
      if (pobj->query_clothing())
        s1 = pobj->query_pocket_mess();
      else
        s1 = "$ob_short$";
      sh = query_multiple_short(ret);
      tell_object(TP, "You give "+ sh +" to "+
                  replace_string(s1, "$ob_short$", pobj->one_short())+
                  ".\n");
      tell_room(environment(TP), TP->one_short() + " gives " + sh +
                " to " + replace_string(s1, "$ob_short$",
                                        pobj->one_short()) +
                ".\n", ({ TP, pobj }));
      tell_object(pobj, capitalize(TP->one_short() ) + " gives "+
                  sh + " to you.\n" );
      if (living(pobj) && (max = pobj->query_max_weight()))
        if ((max = tot*100/max) > 25)
          if (max >= 95) {
            tell_room(environment(TP),
                      pobj->the_short()+" staggers under a weight "+
                      pobj->query_pronoun()+" can only just carry.\n",
                      ({ pobj }) );
            pobj->event_say(TP, "You stagger under a weight you can only "
                            "just carry.\n");
          } else {
            tell_room(environment(TP), pobj->the_short()+ ({
              " is only mildly discomforted by the additional weight.\n",
              " braces "+pobj->query_objective()+"self to take the load.\n",
              " stumbles as "+pobj->query_pronoun()+" takes the load.\n"
              })[(max/25)-1], ({ pobj }) );
            pobj->event_say(TP, "You"+ ({
              " are only mildly discomforted by the additional weight.\n",
              " brace yourself under the load.\n",
              " stumble as you take the load.\n"
              })[(max/25)-1]);
          }
    }
    if (sizeof(fail))
      tell_object(TP, "You cannot give "+query_multiple_short(fail)+ " to "+
                  pobj->one_short() +".\n" );
  }
  return 1;
}

mixed *query_patterns() {
  return ({ "<indirect:object:me> to <indirect:living>",
            (: cmd($1, $3) :) });
}
