/**
 * This is the main dance floor inherit,
 * here we can dance with each other.
 * @author Sandoz 12th October 2001.
 */

#define POS_CMDS ({ "sit", "stand", "kneel", "lie", \
                    "meditate", "crouch", "position" })
#define CMDS ({ "hide", "sneak", "steal", "kill", "attack", "cast" })

object *dancers;
string ball_room;

void check_room();
object query_ball_room();

/** @ignore yes */
void create() {
    dancers = ({ });
    if( !query_ball_room() )
        tell_room( TO, "No ball room set!  Please contact a creator "
            "immediately.\n" );
} /* create() */

/**
 * This method returns the current dancers array -
 * all the people who are dancing, and who with.
 * @return the dancing people
 */
object *query_dancers() { return dancers; }

/**
 * This method returns whether or not the given
 * player is currently dancing.
 * @return 1 if dancing, 0 if not
 */
int query_dancer( object who ) { return sizeof( dancers & ({ who }) ); }

/**
 * This method returns the dancing partner of the player.
 * @param player the player to get the partner for
 * @return the dancing partner of the player
 */
object query_partner( object who ) {
    int i;
    if( ( i = member_array( who, dancers ) ) == -1 )
        return 0;
    return dancers[ i + ( i % 2 ? -1 : 1 ) ];
} /* query_partner() */

/**
 * This method adds a pair of dancers into the dancers array.
 * @param who the player to add
 * @param with the partner to add to the player
 * @return 1 if successfully added, 0 if the player was already dancing
 */
int add_couple( object who, object with ) {
    if( !who || !with || query_dancer(who) || query_dancer(with) )
        return 0;
    dancers += ({ who, with });
    return 1;
} /* add_couple() */

/**
 * This method removes a dancer and his/her partner from
 * the dancers array.
 * @param who the player to remove, could be an array index
 * @return 1 if successfully removed, 0 if the player wasn't dancing
 */
int remove_dancer( mixed who ) {
    if( objectp(who) )
        who = member_array( who, dancers );
    if( !intp(who) || who < 0 || who > ( sizeof(dancers) - 1 ) )
        return 0;
    dancers = delete( dancers, who - who % 2, 2 );
    call_out( (: check_room :), 4 );
    return 1;
} /* remove_dancer() */

/**
 * This method returns the ball room associated with this room.
 * @return the ball room
 */
object query_ball_room() {
    if( !ball_room || ball_room == "" )
        return 0;
    return find_object( ball_room ) || load_object( ball_room );
} /* query_dance_floor() */

/** @ignore yes */
void check_room() {
    object *liv, *obs, ball;

    if( !ball = query_ball_room() ) {
        tell_room( TO, "Oh my god!  There's no ball room!\n");
        return;
    }

    obs = filter( INV(TO), (: !living($1) :) );
    liv = filter( INV(TO) - obs, (: !query_dancer($1) :) );

    filter( liv, (: tell_object( $1, "Your dancing partner has left, "
            "and you leave the dance floor.\n" ) :) );

    liv->move_with_look( ball, "$N step$s off the dance floor.",
                               "$N leave$s the dance floor.");
    obs->move( ball,
         "A janitor comes about and moves $N off the dance floor.",
         "A janitor comes about and moves $N off the dance floor.");

} /* check_room() */

/**
 * This method sets the room to use as the main ball room.
 * @param str the file name of the ball room
 */
void set_ball_room( string str ) {
    ball_room = str;
    TO->add_exit( "retire", ball_room, "path" );
    TO->modify_exit( "retire", ({
        "move mess", "You leave the dance floor.\n",
        "exit mess", "$N leave$s the dance floor.",
        "enter mess", "$N step$s off the dance floor.",
        "function", "check_partner" }) );
} /* set_ball_room() */

/** @ignore yes */
int check_partner( string verb, object who, string special_mess ) {
    object partner;

    if( !who || !objectp(who) )
        return 1;

    if( !( partner = query_partner(who) ) || !objectp(partner) ||
        ENV(partner) != TO )
        return 1;

    who->add_follower(partner);
    call_out( (: $1->remove_follower($2) :), 1, who, partner );
    return 1;

} /* check_partner() */

/** @ignore yes */
int do_squish( string input ) {

    if( !input )
        return 1;

    if( !input = explode( input, " ")[0] )
        return 1;

    if( sizeof( POS_CMDS & ({ input }) ) ) {
        tell_object( TP, "You're dancing, what would you want to change "
            "your position for?\n");
        return 1;
    }

    if( sizeof( CMDS & ({ input }) ) ) {
        tell_object( TP, "You had better concentrate on dancing.\n");
        return 1;
    }

} /* do_squish() */

/** @ignore yes */
void init() {
    TP->command_override( (: do_squish :) );
    if( find_call_out("check_room") == -1 )
        call_out( (: check_room() :), 4 );
} /* init() */

/** @ignore yes */
void reset() {
    if( find_call_out("check_room") == -1 )
        call_out( (: check_room() :), 4 );
} /* reset() */

/** @ignore yes */
void event_exit( object ob, string mess, object to ) {
    if( !ball_room )
        return;

    if( find_object(ball_room) )
        remove_dancer( ob );
} /* event_exit() */

mixed *query_default_position( object ob ) {
    return ({ "dancing here", "", "" });
} /* query_default_position() */

int is_allowed_position( string pos ) { return ( pos == "dancing here" ); }
