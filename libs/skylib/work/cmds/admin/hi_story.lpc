/**
 * Command to allow admin to check say history. Admin only as
 * say history is usually considered much more private.
 * NB: This must always generate an inform. Never remove that segment,
 * for reasons of privacy.
 */

inherit COMMAND_BASE;

int say_history(string arg, int brief, object player) {
  function bing;
  bing = player->get_hsay_func();
  tell_object(player, capitalize(TP->query_name())+" checks your "
     "say history.\n");
  TP->event_inform(filter(livings(), (:adminp($1):)), TP->query_cap_name()+
     " checks "+player->query_cap_name()+"'s say history", "admin");
  return evaluate(bing, arg, brief);
}

mixed *query_patterns() {
  return ({
    "say brief search <word'name'> of <indirect:player'player'>",
      (: say_history(lower_case($4[0]), 1, $1[0]) :),
    "say search <string'name'> of <indirect:player'player'>",
      (: say_history(lower_case($4[0]), !TP->query_verbose("hsay"), $1[0]) :),
    "say brief of <indirect:player'player'>",
      (: say_history("", 1, $1[0]) :),
    "say verbose of <indirect:player'player'>",
      (: say_history("", 0, $1[0]) :),
    "say of <indirect:player'player'>",
      (: say_history("", !TP->query_verbose("hsay"), $1[0]) :),
  });
}
