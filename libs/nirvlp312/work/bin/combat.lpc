#include <grammar.h>

inherit "basic/create";
inherit "basic/parser";
inherit "basic/daemon";

#define COMBAT "global/commands/combat"

void
create()
{
  add_error_message("put", 
        ({"Put on something / something on what / something down"
          " / what into where?\n",-1}));

  add_rule("wear "G_ALL, "wear", COMBAT);
  add_error_message("wear", ({"Wear what?\n",-1}));

  add_rule("put "G_ALL" on", "wear", COMBAT);
  add_rule("put on "G_ALL, "wear", COMBAT);

  add_rule("remove "G_ALL, "unwear", COMBAT);
  add_error_message("remove", ({"Remove what?\n",-1}));

  add_rule("take "G_ALL" off", "unwear", COMBAT);
  add_rule("take off "G_ALL, "unwear", COMBAT);
  add_error_message("take", ({"Take what? Take off what?\n",-1}));

#ifndef G_HAND
#define G_HAND "<hand>"
#endif
#ifndef G_HAND2
#define G_HAND2 "<hand2>"
#endif

  duplicate_class(G_OBJECT,G_HAND);
  duplicate_class(G_OBJECT,G_HAND2);
  add_rule("wield "G_OBJECT" "G_WORD, "wield", COMBAT);
  add_rule("wield "G_OBJECT" in "G_HAND, "wield", COMBAT);
  add_rule("wield "G_OBJECT" in "G_HAND" and "G_HAND2, "wield", COMBAT);
  add_rule("wield "G_OBJECT, "wield", COMBAT);
  add_rule("wield "G_ALL, "wield", COMBAT);
  add_error_message("wield", ({"Wield what?\n",-1}));

  add_rule("let go of "G_ALL, "unwield", COMBAT);
  add_error_message("let", "Let go of which weapon?\n");
  add_rule("remove "G_ALL, "unwield", COMBAT);
  add_rule("unwield "G_ALL, "unwield", COMBAT);

#if 0
  add_rule("kill "G_ALL_LIVINGS, "attack", COMBAT);
  add_error_message("kill", ({"Kill whom?\n",-1}));
#endif

  add_rule("attack "G_ALL_LIVINGS, "attack", COMBAT);
  add_error_message("attack", ({"Attack whom?\n",-1}));

  add_rule("join "G_ALL_LIVINGS, "join", COMBAT);
  add_error_message("join", ({"Join whom?\n",-1}));

  add_rule("stop", "stop_hunting", COMBAT);
  add_rule("stop hunting", "stop_hunting", COMBAT);

  add_rule("flee","flee",COMBAT);
  add_rule("run away","flee",COMBAT);
  add_rule("retreat","retreat",COMBAT);
  add_rule("stop fighting","stop_fight",COMBAT);
  add_rule("stop fighting "G_ALL_LIVINGS,"stop_fight",COMBAT);
  add_error_message("stop", ({"Stop fight?\n",-1}));
  
  add_rule("block "G_EXIT,"block",COMBAT);
  add_rule("stop blocking "G_EXIT,"stop_block",COMBAT);
  add_rule("stop blocking","stop_block",COMBAT);
  add_rule("don't block "G_EXIT,"stop_block",COMBAT);
  add_rule("don't block","stop_block",COMBAT);
  add_rule("dont block "G_EXIT,"stop_block",COMBAT);
  add_rule("dont block","stop_block",COMBAT);

  add_rule("follow "G_LIVING,"follow",COMBAT);
  add_rule("stop following","stop_follow",COMBAT);
  add_rule("stop following "G_LIVING,"stop_follow",COMBAT);
  add_rule("stop following "G_ANY_LIVING,"stop_follow",COMBAT);
  add_rule("following","list_followed",COMBAT);

  add_rule("protect "G_LIVING,"protect",COMBAT);
  add_rule("stop protecting","stop_protect",COMBAT);
  add_rule("stop protecting "G_LIVING,"stop_protect",COMBAT);
  add_rule("stop protecting "G_ANY_LIVING,"stop_protect",COMBAT);

  add_rule("guard "G_LIVING,"guard",COMBAT);
  add_rule("stop guarding","stop_guard",COMBAT);
  add_rule("stop guarding "G_LIVING,"stop_guard",COMBAT);
  add_rule("stop guarding "G_ANY_LIVING,"stop_guard",COMBAT);
  add_error_message("stop",({"Stop fighting, hunting, blocking, protecting, guarding or following [whom or what]?\n",-1}));

  filter(query_rule_verbs(),
    lambda(({ 'v }), ({ #'add_command, "parse_cmd", 'v })));
}

int parse_cmd(string arg,string verb)
{
  return parse_sentence(arg ? verb + " " + arg : verb);
}
