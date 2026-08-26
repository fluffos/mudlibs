/**
 * Handles the hiding and invisible state of players and objects.
 * @author Deutha
 */

#define SKILL "general.perception"

private nosave mapping _hide_invis;

void create() {
    _hide_invis = ([ ]);
} /* create() */

/**
 * This method returns the current hide/invisible states on the object.
 * The mapping is of the format:\n
 * <pre>
 * ([ <hide type name> :
 *     ({
 *        who,
 *        see,
 *        ({ obj, method }), // Remove method
 *      }),
 * ...
 * ])
 * </pre>
 * @return the hide invis mapping as above
 */
mapping query_hide_invis() { return copy(_hide_invis); }

/**
 * This method adds a hide/invis state to the object.
 * @param type the name of the type of hiding
 * @param who no idea
 * @param see no idea
 * @param gone the method and object to call when the hiding is removed
 * @return 1 on success, 0 on failure
 */
int add_hide_invis( string type, object who, mixed see, string *gone ) {
    if( _hide_invis[ type ] )
        return 0;
    _hide_invis[ type ] = ({ who, see, gone });
    return 1;
} /* add_hide_invis() */

/**
 * This method removed the hiding of the specified type off the object.
 * This method will call the function setup when the hiding was added
 * when the hiding is removed. If you pass 1 as the second argument, it
 * will send the 'quiet' flag to the callback function.
 * @param type the type of hiding to remove
 * @param quiet flag to pass along to the callback function
 * @return 1 on success, 0 on failure
 */
varargs int remove_hide_invis( string type, int quiet ) {
    mixed gone;

    if( !_hide_invis[ type ] )
        return 0;

    if( sizeof( gone = _hide_invis[ type ][ 2 ] ) == 2 && gone[0] )
        if( quiet )
            call_other( gone[ 0 ], gone[ 1 ], quiet );
        else
            call_other( gone[ 0 ], gone[ 1 ] );

    map_delete( _hide_invis, type );
    return 1;

} /* remove_hide_invis() */

/**
 * This does a perception check to see if the person can be seen.
 * This is variable on light level, amongst other things.
 * @param thing the person doing the looking
 */
int perception_check( object thing ) {
    int perception;

    if( !ENV(thing) || !( perception = thing->query_skill_bonus(SKILL) ) )
        return perception;

    switch( thing->check_dark( ENV(thing)->query_light() ) ) {
      case -2:
      case 2:
        perception /= 2;
      break;
      case -1:
      case 1:
        perception /= 4;
      break;
      default:
    }

    return perception;

} /* perception_check() */

/**
 * This is the method called to check to see if the person is visible or
 * not.
 * This is masked in /global/wiz_file_comm to handle
 * creator invisibility.
 * @param thing the object doing the looking
 * @return 1 if visible, 0 if not
 */
int query_visible( object thing ) {
    if( thing == TO || creatorp(thing) || thing->query_property("demon") )
        return 1;

    if( thing->query_blinded() )
        return 0;

    if( sizeof( _hide_invis ) ) {
        string key;
        mixed value, see;

        foreach( key, value in _hide_invis ) {
            if( value[ 0 ] == thing )
                continue;

            see = value[ 1 ];

            if( intp( see ) ) {
                if( perception_check(thing) > see )
                    continue;
                return 0;
            }

            if( stringp( see ) ) {
                if( call_other( thing, see ) )
                    continue;
                return 0;
            }

            return 0;
        }
    }

    return 1;

} /* query_visible() */

/**
 * This method returns an extra bit to stick on the end of the players
 * name to show when they are hiding and so on.
 * @return the extra bit to stick after a person's name based on the state
 */
string hide_invis_string() {
    string key, ret;

    ret = "";

    if( sizeof( _hide_invis ) )
        foreach( key in keys( _hide_invis ) )
            ret += " ("+key+")";

    return ret;

} /* hide_invis_string() */
