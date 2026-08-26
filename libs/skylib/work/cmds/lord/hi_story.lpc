/**
 * Command to allow Lords or higher to check someone's tell history.
 * Shiannar: 31/08/01.
 */

inherit COMMAND_BASE;

int tell_history(string arg, int brief, object player) {
  function bing;
  bing = player->get_htell_func();
  tell_object(player, capitalize(TP->query_name())+" checks your "
     "tell history.\n");
  TP->event_inform(filter(livings(), (:lordp($1):)), TP->query_cap_name()+
     " checks "+player->query_cap_name()+"'s tell history", "lord");
  return evaluate(bing, arg, brief);
}

mixed *query_patterns() {
  return ({
    "tell brief search <word'name'> of <indirect:player'player'>",
      (: tell_history(lower_case($4[0]), 1, $1[0]) :),
    "tell search <string'name'> of <indirect:player'player'>",
      (: tell_history(lower_case($4[0]), !TP->query_verbose("htell"), $1[0]) :),
    "tell brief of <indirect:player'player'>",
      (: tell_history("", 1, $1[0]) :),
    "tell verbose of <indirect:player'player'>",
      (: tell_history("", 0, $1[0]) :),
    "tell of <indirect:player'player'>",
      (: tell_history("", !TP->query_verbose("htell"), $1[0]) :),
  });
}
