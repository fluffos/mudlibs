
#define COST  50
#define SKILL "general.perception"

inherit COMMAND_BASE;

int cmd() {
    if( TP->query_blinded() ) {
        add_failed_mess("How can you watch anything?  You're blind.\n");
        return 0;
    }

    if( sizeof( (int *)TP->effects_matching( "mind.alertness" ) ) ) {
        add_failed_mess("You are already alert and watching your "
            "surroundings.\n");
        return 0;
    }

    if( !TASKMASTER_H->point_tasker( TP, "general", COST ) ) {
        add_failed_mess("You can't concentrate enough to watch "
          "your surroundings.\n");
        return 0;
    }

    XP_H->handle_xp( TP, COST, 1 );
    TP->add_effect( EFFECTS_DIR "/other/alertness", 60 +
        (int)TP->query_skill_bonus(SKILL) / 3 );

    add_succeeded_mess("");
    return 1;

} /* cmd() */

int stop_watching() {
    int *enums, id;

    if( sizeof( enums = TP->effects_matching("mind.alertness") ) )
        foreach( id in enums )
            TP->delete_effect( id );
    else
        add_succeeded_mess( ({ "You are not currently watching!\n", "" }) );

    return 1;

} /* stop_watching() */

mixed *query_patterns() {
    return ({ "stop", (: stop_watching() :),
      "", (: cmd() :) });
} /* query_patterns() */
