//    /cmds/skills/_deus.c
//    Nightmare Mudlib
//    A command for Monks to tell if Assassins are on the mud
//    by Kalinash@Nighmtare June 23, 1994.

#include <std.h>

inherit DAEMON;

int cmd_deus() {
    object ppl, me;
    int mp_amt, sp_amt;

    me = this_player();
    if(environment(me)->query_property("no magic"))
        return notify_fail("Your concentration is being blocked.\n");
    if((string)me->query_class() != "monk")
        return notify_fail("Your prayers go unanswered.\n");
    if((int)me->query_skill("faith") < 30)
        return notify_fail("You have not the faith needed for this spell.\n");
    mp_amt = random(90) + 10;
    sp_amt = random(20) + 10;
    if((int)me->query_sp() < sp_amt)
        return notify_fail("Your body cannot handle the stress right now.\n");
    if((int)me->query_mp() < mp_amt)
        return notify_fail("Your mind is too fatigued.\n");
    if(random(100) < 10)
        return notify_fail("Your prayers go unanswered.\n");
    message("their_action", sprintf("%s mutters a prayer of divination.", 
      me->query_cap_name()), environment(me), me);
    me->add_mp(-mp_amt);
    me->add_sp(-sp_amt);
    ppl = filter_array(users(), "is_assassin", this_object());
    if(sizeof(ppl)) {
        message("my_action", "You feel the presence of great evil in "
          "the world.", me);
        return 1;
    }
        else {
                message("my_action", "You feel the world is safe at this time.", me);
                        return 1;
                            }
}

int is_assassin(object ob) {
    if((string)ob->query_guild() == "assassin" && !creatorp(ob))
        return 1;
    else
        return 0;
}

void help() {
    message("help", "Command : deus\n\nAllows monks with a high faith to "
      "detect the presence of beings who are filled with the greatest evil.",
      this_player());
    return;
}
