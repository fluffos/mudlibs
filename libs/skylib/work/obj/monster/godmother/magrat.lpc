inherit NPC_OBJ;
#include <panic.h>

#define START_STATE 0
#define FIRST_QUESTION 1
int state;
object player;
int start_time;

void setup() {
    start_time = time();
    set_name("garlik");
    set_short("fairy godmother");
    add_alias("godmother");
    add_adjective("fairy");
    set_long(
      "In the realm of Fairy Godmothers, this one must certainly "
      "take honours in a Division Yet To Be Announced.  Grimly determined "
      "to do things properly, Magrat Garlick has woven wild flowers in her "
      "windswept, golden locks, powdered her face to a fashionable pallor "
      "and has attired herself in numerous fluttering shawls, bangles, "
      "and a vivid green gown.  The overall effect is that of a maypole "
      "with a flower box emptied over its head that happens to jingle like "
      "a tinker's wagon with a broken wheel.  With one hand she clutches her "
      "regulation wand and with the other she dabs at her red and dripping "
      "nose with a damp scrap of lace.\n");

    set_race("human");
    set_guild("witch");
    set_level(200);
    state = START_STATE;
    set_gender(2);
    add_respond_to_with(({ "yes" }), "#yes_response");
    add_respond_to_with(({ "@nod" }), "#yes_response");
    add_respond_to_with(({ "no" }), "#no_response");
    add_respond_to_with(({ "@shake" }), "#no_response");
} /* setup() */

object make_pumpkin() {
    object pumpkin;

    pumpkin = clone_object("/obj/food");
    pumpkin->set_name("pumpkin");
    pumpkin->set_long("The large orange pumpkin has darker ribbed bits "
      "which run down from the top to the bottom.  There "
      "appears to be no hair at all protruding from this "
      "pumpkin in any way at all, really.\n");
    return pumpkin;
} /* make_pumpkin() */

void do_panic(object pl) {
    do_command("'Umm.  Hi.  You are lost?  Would you like me to get you "+
      "back to the city?");
    do_command("emote waves a wand around a bit.");
    tell_room(environment(),
      "A puff of smoke drifts away from where something used to be, "
      "now residing there is a pumpkin.\n");
    call_out((: make_pumpkin()->move(environment()) :), 1);
    do_command("'Whoops.");
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
        do_command("'Oh, ahhh.  Good.");
        do_command("peer wor");
        tell_object(player,
          the_short() + " waves the wand in your direction.\n");
        tell_room(environment(player),
          the_short() + " waves the wand in " +
          player->the_short() + "'s direction.\n");
        PANIC_HANDLER->finish_panic(player, PANIC_OK);
        /* A couple of pumpkins for good luck. */
        make_pumpkin()->move(player);
        make_pumpkin()->move(environment(player));
        player = 0;
        break;
    }
} /* yes_response() */

void no_response(object ob) {
    if(ob != player)
        return;

    switch (state) {
    case FIRST_QUESTION :
        do_command("'Oh, I must have got lost somewhere then.");
        do_command("wave");
        do_command("'Oh dear.");
        make_pumpkin()->move(player);
        make_pumpkin()->move(environment(player));
        PANIC_HANDLER->finish_panic(player, PANIC_NOT_OK);
        player = 0;
        break;
    }
} /* no_response() */

void event_exit(object ob) {
    if (!player)
        return ;

    if (ob == player) {
        object pl;

        pl = player;
        player = 0;
        do_command("'bye...");
        do_command("wave");
        do_command("'Whoops.");
        do_command("tell "+pl->query_name()+" Sorry to have bothered you.");
        PANIC_HANDLER->finish_panic(pl, PANIC_NOT_OK);
        make_pumpkin()->move(environment(pl));
    }
} /* event_exit() */

void hurry_up() {
    if (environment() && file_name(environment()) != "/room/void" && player)
        do_command("'Err.  Could you hurry up?  Other people are calling me.");
    else {
        PANIC_HANDLER->finish_panic(player, PANIC_NOT_OK);
        player = 0;
    }
} /* hurry_up() */

void event_fight_in_progress(object attacker, object attackee) {
    if (attackee == this_object()) {
        do_command("'Look, this is really not very nice.");
        do_command("frown");
        do_command("'I know the art of self defence you know!");
        set_hp(query_max_hp(), attacker);
        attackee->adjust_tmp_str(-2);
        attackee->adjust_tmp_dex(-2);
        attackee->adjust_tmp_wis(-2);
        attackee->adjust_tmp_int(-2);
        attackee->adjust_tmp_con(-2);
        attackee->add_property("attacked godmother", time());
        PANIC_HANDLER->finish_panic(player, PANIC_NOT_OK);
        player = 0;
    }
} /* event_fight_in_progress() */

void finish_up() {
    do_command("shuffle");
    do_command("'Umm.  I have to go.");
    do_command("smile appol");
    do_command("wave");
    PANIC_HANDLER->finish_panic(player, PANIC_NOT_OK);
    player = 0;
} /* finish_up() */

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
