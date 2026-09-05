#include <bodypart.h>
#include <event.h>
#include <message.h>

inherit BODY_HUMANOID;

void
configure()
{
  BODY_HUMANOID::configure();
  set_race("human");
}

status can_perceive_look(mapping e) {
  return e[E_AGENT]->short();  // do not perceive invisible examiners
}

string describe_look_event(mapping e) {
  object agent;
  mixed target;
  if ((agent=e[E_AGENT]) == get_user())  // do not perceive own looks ;-)
    return 0;
  switch (e[E_TYPE]) {
  case "examine":
    if (!pointerp(target=e[E_TARGET]))
      target = ({ target });
    target = filter_objects(target,"short");
    if (!sizeof(target))
      return 0;
    target = make_list(map(target,#'describe_object,e[E_ID],
                                 ARTICLE_THE,0,({e[E_AGENT]}),0,get_user()));
    return capitalize(message2string(({ M_THE,e[E_AGENT],
                                        M_VERB,"examine",e[E_AGENT],
                                        " "+target+".\n" }),
                                     get_user()));
  }
}

string describe_event(mapping e,string t) {
  switch (t) {
  case "look":
    if (can_perceive_look(e))
      return describe_look_event(e);
    break;
  default:
    break;
  }
  return 0;
}
