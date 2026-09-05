#include <event.h>
#include <grammar.h>
#include <describe.h>
#include <prop/item.h>

inherit "basic/create";

// Ugh Jul-5-1995
void create() {
  set_global_listening_event("change_body_state?",1);
  listen_event("change_body_state?");
}

status do_action(string verb, mixed args) {
  object ob;
  mapping e;
  e = ([ E_AGENT: this_player (),
         E_PREPOSITION: args[G_TEXT],
         E_SUCCESS: 1 ]);
  switch (verb) {
  case "sit": 
    e += ([ E_TARGET: args[G_INDIRECT], 
            E_ID: args[G_INDIRECT,1],
            E_FROM: "standing",
            E_TO: "sitting" ]);
    break;
  case "sit_down":
    e += ([ E_FROM: "standing",
            E_TO: "sitting" ]);
    break;
  case "lie":
    e += ([ E_TARGET: args[G_INDIRECT],
            E_ID: args[G_INDIRECT,1],
            E_TO: "lying" ]);
    break;
  case "lie_down":
    e += ([ E_TO: "lying" ]);
    break;
  case "sit_up_ob":
    e += ([ E_TARGET: args[G_INDIRECT],
            E_ID: args[G_INDIRECT,1],
            E_FROM: "lying",
            E_TO: "sitting" ]);
    break;
  case "sit_up":
    e += ([ E_FROM: "lying",
            E_TO: "sitting" ]);
    break;
  case "leave":
    e += ([ E_TARGET: args[G_INDIRECT],
            E_ID: args[G_INDIRECT,1],
            E_TO: "standing" ]);
    break;
  case "stand_up":
    e += ([ E_TO: "standing" ]);
    break;
  default:
    return 0;
  }
  send_event("change_body_state?", e, ({ environment(this_player()) }));
  return e[E_SUCCESS];
}

status sit_down(object who,object where,string where_id,string preposition) {
  return with_player(who,#'do_action,
                     ({ "sit",([ G_INDIRECT:where;where_id,
                                 G_TEXT:preposition;" " ]) }));
}

object *get_targets(string prop) {
  object *targets;
  targets = ({ environment(this_player()) });
  targets += (all_inventory(environment(this_player())) + 
              all_inventory(this_player()));
  targets = filter_objects(targets,"query_property",prop);
  return targets;
}

#define FAIL(who,mess) with_player((who),#'notify_fail,({ mess,0 }))

void receive_event(mapping e, string type, int prio) {
  int i;
  object seat, who;
  string prep;
  mixed target;
  if (e[E_HANDLED])  // Alfe 95-Jun-20
    return;
  e[E_HANDLED] = 1;  // we will handle it now  Alfe 95-Jun-20
  if (type != "change_body_state?")
    return;
  e[E_SUCCESS] = 0;
  if (target=e[E_TARGET])
    e[E_SUCCESS] = target->apply_action("change bodystate",100,e);
  else {
    e[E_SUCCESS] = 0;
    target = with_player(e[E_AGENT],#'get_targets,P_SITTABLE);
    for (i=sizeof(target); i && !e[E_SUCCESS]; )
      e[E_SUCCESS] = target[<i--]->apply_action("change bodystate",100,e);
  }
  if (e[E_SUCCESS])
    return;
  seat = e[E_TARGET];
  who = e[E_AGENT];
  prep = e[E_PREPOSITION];
  switch (e[E_TO]) {
  case "sitting":
    switch (e[E_FROM]) {
    case "standing":
      if (!seat)
        FAIL(who, "What do you want to sit on?\n");
      else 
        FAIL(who, ("You can't sit down "+prep+" "+
                   describe((seat == environment(who) ? 
                             (e[E_ID]||"it") : seat), 
                            ARTICLE_THE)+"!\n"));
      break;
    case "lying":
      if (!seat)
        FAIL(who, "Where do you want to sit up in?\n");
      else
        FAIL(who, ("You can't sit up "+prep+" "+
                   describe((seat == environment(who) ? 
                             (e[E_ID]||"it") : seat), 
                            ARTICLE_THE)+"!\n"));
      break;
    }
    return;
  case "lying":
    if (!seat)
      FAIL(who, "Where do you want to lie?\n");
    else
      FAIL(who, ("You can't lie down "+prep+" "+
                 describe((seat == environment(who) ? 
                           (e[E_ID]||"it") : seat),
                          ARTICLE_THE)+"!\n"));
    return;
  case "standing":
    if (!seat) 
      FAIL(who, "You are not sitting or lying on anything "
                "to stand up from.\n");
    else
      FAIL(who, ("You can't stand up from "+
                 describe((seat == environment(who) ? 
                           (e[E_ID]||"it") : seat),
                          ARTICLE_THE)+"!\n"));
    return;
  }
}
