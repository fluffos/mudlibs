inherit NPC_OBJ;
#include <panic.h>

#define START_STATE 0
#define FIRST_QUESTION 1
#define CLOSE_EYES 2
#define THINK_DRUM 3

int state, start_time;
object player;

void setup() {
    start_time = time();
    set_name("godmother");
    set_short("fairy godmother");
    add_adjective("fairy");
    set_long(

      "This fairy godmother isn't quite what you expected.  She is tall "
      "and forbidding; not in the slightest bit cuddly or smiley.  She looks "
      "slightly uncomfortable and is currently glaring at her wand, which "
      "appears to be malfunctioning.  If you cross her, you might find yourself "
      "turned into a wombat or worse.\n" );


    set_race("human");
    set_guild("witch");
    set_level(300);
    set_gender(2);

    add_respond_to_with(({ "yes" }), "#yes_response");
    add_respond_to_with(({ "@nod" }), "#yes_response");
    add_respond_to_with(({ "no" }), "#no_response");
    add_respond_to_with(({ "@shake" }), "#no_response");
    add_respond_to_with(({ "@think", "mended", "drum" }), "#think_mended_drum");
    add_respond_to_with(({ "@think", "mended" }), "#think_mended_drum");
    add_respond_to_with(({ "@think", "drum" }), "#think_mended_drum");
    add_respond_to_with(({ "@womble" }), "#think_mended_drum");
    state = START_STATE;
} /* setup() */

void do_panic(object pl) {
    do_command("'I hope you're not foreign.  You know, where you gabble at me in "
      "heathen lingo and eat foreign muck and worship "
      "objects.");
    init_command("'Hello.  You want some help to get back to the city?", 1);
    init_command("glare "+pl->query_name(), 2);
    state = FIRST_QUESTION;
    player = pl;
    start_time = time();
} /* do_panic() */

int query_waiting() { return time()-start_time; }

void yes_response(object ob) {
    if (ob != player)
        return ;
    switch (state) {
    case FIRST_QUESTION :
        do_command("'Right then.  Close your eyes and concentrate.");
        do_command("'Think of the mended drum");
        state = THINK_DRUM;
        call_out("check_closed", 20);
        break;
    }
} /* yes_response() */

void no_response(object ob) {
    if (ob != player)
        return ;
    switch (state) {
    case FIRST_QUESTION :
        do_command("'So why did you call me up then?");
        do_command("kick "+player->query_name());
        do_command("eye "+player->query_name()+" evil");
        /* Curse them... */
        player->set_tmp_str(-4);
        PANIC_HANDLER->finish_panic(player, PANIC_NOT_OK);
        player = 0;
        break;
    }
} /* no_response() */

void close_eyes(object ob) {
    if (ob != player)
        return ;
    switch (state) {
    case CLOSE_EYES :
        do_command("'Now, think of the mended drum");
        do_command("poke "+player->query_name());
        state = THINK_DRUM;
        remove_call_out("check_closed");
        call_out("check_think", 20);
        break;
    }
} /* close_eyes() */

void think_mended_drum(object ob) {
    if (ob != player)
        return ;
    switch (state) {
    case CLOSE_EYES :
        do_command("'You need to close your eyes first");
        do_command("glare "+player->query_name());
        break;
    case THINK_DRUM :
        do_command("'Now the world will just rearrange itself to suit you.");
        PANIC_HANDLER->finish_panic(player, PANIC_OK);
        player = 0;
        break;
    }
} /* think_mended_drum() */

void check_close() {
    do_command("'Come on, close your eyes.  I don't have all day.");
    do_command("top foot");
    call_out("check_close", 60);
} /* check_close() */

void check_think() {
    do_command("'Good.  You have closed your eyes.  Now, think of the "
      "mended drum");
    call_out("check_think", 60);
} /* check_think() */

void event_exit(object ob) {
    if (ob == player) {
        do_command("'Thats right!  Just walk out on me.");
        do_command("tell "+player->query_name()+" Thats right!  Just walk out on me.");
        do_command("glare "+player->query_name());
        PANIC_HANDLER->finish_panic(player, PANIC_NOT_OK);
        player = 0;
    }
} /* event_exit() */

void event_fight_in_progress(object attacker, object attackee) {
    if (attackee == this_object()) {
        /* Someone is attacking us! */
        attacker->adjust_tmp_str(-4);
        attacker->adjust_tmp_con(-4);
        attacker->adjust_tmp_dex(-4);
        attacker->adjust_tmp_int(-4);
        attacker->adjust_tmp_wis(-4);
        do_command("'What is this travesty!  Attacking your fairy "
          "godmother, Well I never.");
        do_command("'"+attacker->one_short()+" I here by curse you!");
        do_command("'Don't expect me to help you again.");
        do_command("glare "+attacker->query_name());
        attacker->add_property("attacked godmother", time());
        PANIC_HANDLER->finish_panic(player, PANIC_NOT_OK);
        player = 0;
    }
} /* event_fight_in_progress() */

void hurry_up() {
    if (!player) {
        /* If the player has buggered off, we give up */
        PANIC_HANDLER->finish_panic(player, PANIC_NOT_OK);
        player = 0;
    } else {
        do_command("tap foot");
        do_command("glare "+player->query_name());
    }
} /* hurry_up() */

void finish_up() {
    do_command("'Well.  You took too long.  What a complete waste of time.");
    if (player) {
        do_command("glare "+player->query_name());
        PANIC_HANDLER->finish_panic(player, PANIC_NOT_OK);
    }
    player = 0;
} /* finish_up() */

void event_dest(object ob) {
    if (ob == player) {
        PANIC_HANDLER->finish_panic(player, PANIC_NOT_OK);
        player = 0;
    }
} /* event_dest() */

void dest_me() {
    if (player) {
        PANIC_HANDLER->finish_panic(player, PANIC_NOT_OK);
        player = 0;
    }
    ::dest_me();
} /* dest_me() */

int unambushable() {
    return 1;
}
