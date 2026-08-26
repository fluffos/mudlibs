/**
 * This is the tattooist NPC inherit for tattoo parlours,
 * which should be inherited into tattooist NPCs.
 * You should also use set_home_location() on them, and set it to
 * their tattoo parlour room; this will make sure they refuse to
 * tattoo anything when not actually in their parlour, and they will
 * try to return to their home location when driven out of there.
 * @author Shiannar, 15/10/01, inheritized by Sandoz, 2002.
 * @see /std/shops/tattoo_shop
 * @see /std/effects/other/tattoo
 */

#define TATTOO     EFFECTS_DIR "/other/tattoo"

inherit NPC_OBJ;

int busy;

/** @ignore yes */
int query_busy() { return busy; }

/** @ignore yes */
void set_busy( int i ) {
    set_chats_off( i );
    busy = i;
} /* set_busy() */

/**
 * This method does some expansion on the bodypart string.
 * @param bodypart the bodypart to expand
 * @param expand the string to expand with, ie. a player's poss_short()
 */
string expand_tattooable( string bodypart, string expand ) {
    return TATTOO->expand_tattooable( bodypart, expand );
} /* expand_tattooable() */

/**
 * This method checks for the presence of the player, etc.
 * Feel free to overwrite this, but do try to keep all the
 * checks intact.
 * @param who the person getting a tattoo
 * @return 1 if the person is here an all is fine, 0 if not
 */
int check_person( object who ) {
    if( !who || ENV(who) != ENV(TO) ) {
        do_command("'Odd, where'd they go?");
        set_busy( 0 );
        return 0;
    }

    if( TO->is_fighting(who) ) {
        do_command("'I certainly won't serve someone like you!");
        set_busy( 0 );
        return 0;
    }

    if( base_name(ENV(TO)) != query_home_location() ) {
        do_command("'This isn't my tattooing shop!  I can't work here!");
        set_busy( 0 );
        return 0;
    }

    return 1;

} /* check_person() */

void create() {
    ::create();
    add_adjective("tattooist artist");
    add_alias("tattooist");
} /* create() */

/**
 * This method starts the actual tattooing process.
 * Feel free to overwrite it in your NPC for custom messages, etc.,
 * and also use check_person() in each stage.
 * @param who the person getting a tattoo
 * @param tattoo the thing to tattoo onto them
 * @param the bodypart to tattoo onto
 * @return 1 upon success, 0 upon failure
 */
int do_tattoo( object who, string tattoo, string bodypart ) {
    if( !check_person(who) )
        return 0;

    do_command("'Well now, "+who->query_cap_name()+", "+tattoo+"?");

    tell_room( ENV(who), the_short()+" takes "+who->poss_short()+" money "
        "and hides it somewhere.\n");

    init_command(":prepares a couple of needles and some ink.", 4 );

    set_busy( 1 );

    call_out("tattoo_2", 10, who, tattoo, bodypart );
    return 1;

} /* do_tattoo() */

/** This method is used by the default do_tattoo(). */
void tattoo_2( object who, string tattoo, string bodypart ) {
    if( !check_person(who) )
        return;

    do_command(":mixes a couple of ink colours together.");

    init_command("'Now, this may hurt a bit.  Kind of like a thousand "
                 "tiny fish-hooks lancing through your skin.", 4 );

    init_command("grin wryly", 5 );

    call_out("tattoo_3", 10, who, tattoo, bodypart );

} /* tattoo_2() */

/** This method is used by the default do_tattoo(). */
void tattoo_3( object who, string tattoo, string bodypart ) {
    if( !check_person(who) )
        return;

    tell_object( who, the_short()+" painfully lances your skin multiple "
        "times with "+HIS+" needles.\n");
    tell_room( ENV(who), the_short()+" tattoos a picture into "+
        who->poss_short()+" skin.\n", who );

    call_out("finish_tattoo", 10, who, tattoo, bodypart );

} /* tattoo_3() */

/**
 * This method finishes the tattooing process.
 * Feel free to overwrite this function for custom messages,
 * but do try to keep all the checks intact.
 * @param who the person getting a tattoo
 * @param tattoo the thing to be tattooed
 * @param bodypart the bodypart to tattoo onto
 */
void finish_tattoo( object who, string tattoo, string bodypart ) {
    if( !check_person(who) )
        return;

    tell_object( who, the_short()+" carefully draws "+tattoo+" "+
        expand_tattooable( bodypart, "your")+", paying extra attention to "
        "detail.\n");
    tell_room( ENV(who), the_short()+" draws a tattoo on "+
        who->poss_short()+" skin.\n", who );

    who->add_effect( TATTOO, ({ bodypart, tattoo }) );

    do_command("'There, all done.  That wasn't too painful, was it?");

    set_busy(0);

} /* finish_tattoo() */

/**
 * This method starts the actual tattoo removal process.
 * Feel free to overwrite it in your NPC for custom messages, etc.,
 * and also use check_person() in each stage.
 * @param who the person removing a tattoo
 * @param the bodypart to remove a tattoo from
 * @return 1 upon success, 0 upon failure
 */
int do_remove( object who, string bodypart ) {
    if( !check_person(who) )
        return 0;

    do_command("'Well now, "+who->query_cap_name()+", you want the tattoos "+
        expand_tattooable( bodypart, "your")+" removed?");

    tell_room( ENV(who), the_short()+" takes "+who->poss_short()+" money "
        "and hides it somewhere.\n");

    init_command("'I'll see what I can do.", 2 );

    set_busy( 1 );

    call_out("remove_2", 10, who, bodypart );
    return 1;

} /* do_remove() */

/** This method is used by the default do_remove(). */
void remove_2( object who, string bodypart ) {
    if( !check_person(who) )
        return;

    do_command(":busies "+HIM+"self with "+HIS+" tattooing supplies.");

    init_command("'Now, this may hurt.  A lot.", 4 );
    call_out("finish_remove", 10, who, bodypart );

} /* remove_2() */

/**
 * This method finishes the removal of a tattoo.
 * Feel free to overwrite this function for custom messages,
 * but do try to keep all the checks intact.
 * @param who the person removing a tattoo
 * @param bodypart the bodypart to remove tattoos from
 */
void finish_remove( object who, string bodypart ) {
    int *effs;
    mapping args;

    if( !check_person(who) )
        return;

    if( !sizeof( effs = who->effects_matching("body.tattoo") ) ) {
        do_command("'Hrmm.  It would appear you're not tattooed.");
        return;
    }

    args = who->arg_of( effs[0] );
    map_delete( args, bodypart );

    if( !sizeof( args ) )
        who->delete_effect( effs[0] );
    else
        who->set_arg_of( effs[0], args );

    tell_object( who, the_short()+" punctures your skin multiple times "
        "with "+HIS+" needles, then softly chants soft magic words to remove "
        "the ink.\n"+the_short()+" then runs "+HIS+" hands over your skin, "
        "leaving behind them an un-blemished surface.\n");

    tell_room( ENV(who), the_short()+" somehow removes the tattoos "+
        expand_tattooable( bodypart, who->poss_short() )+".\n", who );

    set_busy(0);

} /* finish_remove() */

/** @ignore yes */
mixed stats() { return ::stats() + ({ ({"busy", query_busy() }) }); }
