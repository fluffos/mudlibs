/**
 * Modified for new guildless system
 * Shaydz 28/7/01
 */

nosave string *skills;

protected void create() {
    skills = ({"covert", "crafts", "faith", "fighting", "general", "magic"});
} /* create() */

/**
 * This methof returns the skill to be used to calculate
 * max gp and gp increase rates for the creature.
 * @param thing the creatore to get the gp skill for
 * @return the gp skill to be used for gp calculations
 */
varargs string query_gp_skill( object thing ) {
        return "general.points";

} /* query_gp_skill() */

/** @ignore yes */
void set_gp( object thing ) {
    int arr;

    if( !thing )
        return;

    arr = thing->query_skill_bonus("general.points");
    thing->set_max_gp( 50 + arr );

} /* set_gp() */

/** @ignore yes */
string *query_skills() { return skills; }

/**
 * This method returns the cost of a skill
 * for the specified player.
 * @param skill the skill to get the cost for
 * @param player the player to get the skill cost for
 * @return the skill cost
 */
float query_skill_cost( string skill, object player ) {
    string stat;
    int i;

    if( !player || !objectp(player) ||
        !( stat = SKILL_H->query_skill_stat( skill ) ) )
        return 10;

    foreach( stat in explode( stat, "" ) )
      i += call_other( player, "query_real_"+replace( stat, ({
           "C", "con", "S", "str", "D", "dex", "I", "int", "W", "wis" }) ) );

    return ( explode( skill, "." )[0] == "general" ? 600.0 : 400.0 ) / i;

} /* query_skill_cost() */

/**
 * This method returns the maximum level a player can learn
 * the specified skill to in a training hall.
 * @param skill the skill to get the maximum learnable level for
 * @param the player to get the maximum level for
 * @return the maximum learnable level
 */
int query_skill_max_level( string skill, object player ) {
    string stat;
    int i;

    if( !player || !objectp(player) ||
        sizeof( SKILL_H->query_immediate_children( skill ) ) )
        return sizeof( explode( skill, "." ) ) * 5;

    if( explode( skill, "." )[0] == "general" )
        return ( player->query_real_con() + player->query_real_str() +
                 player->query_real_dex() + player->query_real_int() +
                 player->query_real_wis() ) * 5;

    stat = SKILL_H->query_skill_stat( skill );
    foreach( stat in explode( stat, "" ) )
        i += call_other( player, "query_real_"+replace( stat, ({
             "C", "con", "S", "str", "D", "dex", "I", "int", "W", "wis" })));

    // This will be :
    // 400 levels with a stat of 21 in a purely one stat skill.
    // 40 levels with a stat of 3 in a purely one stat skill.
    return i * 4 - 20;

} /* query_skill_max_level() */

string query_title(object player) {
    return TITLE_H->query_title(player);
} /* query_title() */

/**
 * @ignore yes
 * Used to calculate new guild level based on skill mods.
 */
int query_new_level( object thing ) {
    int i, lvl;

    if( !thing || !sizeof( skills ) )
        return 0;

    for( i = 0; i < sizeof( skills ); i++ )
        lvl += "/cmds/creator/newskills"->new_skill_value(
               thing->query_skill( skills[ i ] ));

    lvl /= sizeof( skills );
    return lvl;

} /* query_new_level() */

/**
 * This returns the level of the specified creature.
 * @param thing the creature to get the level for
 * @return the level of the creature
 */
int query_level( object thing ) {
    int i, lvl, *t;

    if( !thing || !objectp(thing) )
        return 0;

    t = values( filter( thing->query_skills(),
        (: !sizeof( SKILL_H->query_immediate_children( $1 ) ) &&
        strsrch( $1, "language" ) == -1 :) ) );
//    TCRE("shaydz",sprintf("t: %O\n",t));

    if( sizeof(t) > 30 )
        t = sort_array( t, -1 )[0..29];
//    TCRE("shaydz",sprintf("t: %O\n",t));

    foreach( i in t )
      lvl += i;
//    TCRE("shaydz",sprintf("lvl: %O\n",lvl));

    return lvl / 29;

} /* query_level() */
