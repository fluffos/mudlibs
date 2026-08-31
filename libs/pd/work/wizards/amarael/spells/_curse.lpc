#include <std.h>
#include <daemons.h>

inherit DAEMON;

int spell();

mapping cursed;

int cmd_curse(string str) {
    object ob, tp;
    int effect, result;

    tp = this_player();
    if(!cursed)
       cursed = ([ ]);

    if(!spell())
      return notify_fail("What?\n");

    if(tp->query_ghost())
      return notify_fail("Ghosts cannot harm the living.\n");

    if(environment(tp)->query_property("no attack"))
      return notify_fail("Greater powers prevent your malice.\n");

    if(tp->query_rest_type())
      return notify_fail("Stand up first.\n");

    if(tp->query_disable())
      return notify_fail("You are too busy already!\n");

    if(tp->query_magic_round())
      return notify_fail("You are already casting a spell.\n");

    if(tp->query_mp() < 100)
      return notify_fail("You do not have the energy to do that.\n");

    if(!ob = present(str, environment(tp)))
      return notify_fail("You can't see "+str+" here.\n");

    if(!ob->is_living())
      return notify_fail("Curses are for the living.\n");

    if(ob == tp)
      return notify_fail("Curses!\n");

    if(!tp->kill_ob(ob))
      return notify_fail(ob->query_cap_name()+" is protected from your curses.\n");

    if(cursed[ob])
      return notify_fail(ob->query_cap_name()+" has already been cursed.\n");

    effect  = tp->query_skill("clairvoyance")/6;
    effect += tp->query_stats("charisma");
    effect -= ob->query_stats("charisma");

    result = effect/10;

    message("info", "%^BOLD%^BLACK%^You call upon the vengeful spirits of your ancestors.%^RESET%^", tp);
    message("info", tp->query_cap_name()+"'s eyes burn with anger.", environment(tp), tp);

    if(result < 1) {
      message("info", ob->query_cap_name()+" resists your curse!", tp);
      tp->add_mp(-100);
      return 1;
      }

    message("info", "%^BOLD%^RED%^"+ob->query_cap_name()+" is wreathed in the malice of your ancestors.%^RESET%^", tp);
    message("info", "%^BOLD%^RED%^You feel a heavy weight descend upon you.%^RESET%^", ob);

    ob->add_stat_bonus("strength", effect, (tp->query_stats("charisma")*5));
    ob->add_stat_bonus("dexterity", effect, (tp->query_stats("charisma")*5));
    ob->add_stat_bonus("constitution", effect, (tp->query_stats("charisma")*5));
    ob->add_stat_bonus("wisdom", effect, (tp->query_stats("charisma")*5));
    ob->add_stat_bonus("charisma", effect, (tp->query_stats("charisma")*5));
    ob->add_stat_bonus("intelligence", effect, (tp->query_stats("charisma")*5));
    ob->fix_vital_bonus();

    tp->add_mp(-100 - effect);

    cursed[ob] = tp->query_name();

    call_out("remove_curse", (tp->query_stats("charisma")*5), tp, ob);
    return 1;
}

void remove_curse(object tp, object ob) {
     message("info", "Your curse on "+ob->query_cap_name()+" has lifted.", tp);
     message("info", "You feel a terrible weight has been lifted from your shoulders.", ob);
     map_delete("cursed", ob);
}

int spell() {
    object tp;
    tp = this_player();
    if(tp->is_monster())			return 1;
    if(tp->query_subclass() != "gypsy") 	return 0;
    if(tp->query_level() < 25)			return 0;
    if(tp->query_skill("clairvoyance") < 120)	return 0;
    return 1;
}

void help() {
     write("
Syntax: <curse [living]>

The gypsies are able to call upon the vengeful spirits of 
their ancestors to curse a living being. While the spirits
are glad to curse many, the will never curse the same person
twice.
");
}
