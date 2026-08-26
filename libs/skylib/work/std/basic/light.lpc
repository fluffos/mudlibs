/**
 * This method handles the light changing and control.
 * @author Pinkfish
 */

private nosave int _light;
private nosave int _my_light;
private nosave int _need_recalculate;
private nosave object *_inform_of_change;

void new_recalc_light();
mixed query_property( string name );
void add_property( string name, mixed value );
void remove_property( string name );

void create() {
    _inform_of_change = ({ });
} /* create() */

/**
 * This returns the total light level of the object.   This includes the
 * light levels of anything that happens to be inside us.
 * @return current light level
 * @see query_my_light()
 * @see set_light()
 */
int query_light() {
    if( _need_recalculate ) {
        _need_recalculate = 0;
        new_recalc_light();
    }
    return _light;
} /* query_light() */

int query_light_needs_inform() {
    return _light || _need_recalculate;
} /* query__light_needs_inform() */

/**
 * This method returns the light associated with this object.   This does
 * not count the light levels of anything inside us.
 */
int query_my_light() { return _my_light; }

/**
 * This method forces a recalculation of the current light level in this
 * object.
 */
varargs void new_recalc_light() {
    object *obs;
    object ob;

    _need_recalculate = 0;

    obs = INV(TO);

    // Use the square root of the squares to make the differences
    // not so wild.
    _light = query_my_light() * query_my_light();

    if( !TO->query_opaque() ) {
        foreach( ob in obs ) {
          // If it is opaque, we do not count the light of the contents.
          _light += ( ob->query_opaque() ?
                    ( ob->query_my_light() * ob->query_my_light() ) :
                    ( ob->query_light() * ob->query_light() ) );
        }
    }
    _light = to_int( sqrt( to_float( _light ) ) );
    _inform_of_change->event_light_change( TO, 0, _light );
} /* new_recalc_light() */

/**
 * This method tells us that the light levels have changed and should
 * be recalculated when queried.
 * @see inform_of_light_level_change()
 */
void light_level_changed() {
    _need_recalculate = 1;
} /* light_level_changed() */

/**
 * This method tells all our environments that the light level has
 * changed.
 * @param ob the object whose environment we should tell about the change
 * @see light_level_changed()
 */
void inform_of_light_level_change( object ob ) {
    if( ob )
        ob->light_level_changed();
    while( ob && !ob->query_opaque() ) {
        ob->light_level_changed();
        ob = ENV(ob);
    }
} /* inform_of_light_level_change() */

/**
 * This method adds an object to be informed of light change events.
 * @param ob the object to be informed of light change events
 */
void add_inform_light_change(object ob) {
    _inform_of_change += ({ ob });
} /* add_inform_lifht_change() */

/**
 * This method removes an object from the current list of things to
 * be informed of a light change.
 * @param ob the object to remove from the inform list
 */
void remove_inform_light_change(object ob) {
    _inform_of_change -= ({ ob });
} /* remove_inform_light_change() */

/**
 * This method makes this object opaque.   This means that light does not
 * escpae from it.
 * @see not_obscured_object()
 * @see set_light()
 */
void set_opaque() {
    add_property( "opaque", 1 );
} /* set_opaque() */

/**
 * This method makes the object transparent (default).   This means that the
 * light from items inside does escape.
 * @see set_opaque()
 * @see set_light()
 */
void reset_opaque() {
    remove_property( "opaque" );
} /* reset_opaque() */

/**
 * This method checks to see if the object is opaque or not.
 * @return 1 if it is opaque, 0 if not
 */
int query_opaque() {
    return query_property("opaque");
} /* query_opaque() */

/**
 * This changes the current light level.
 * @param number the amount to chage it by
 * @see set_light()
 * @see query_my_light()
 * @see query_light()
 */
int adjust_light( int number ) {
    if( number ) {
        _my_light += number;
        inform_of_light_level_change(TO);
    }
    return _light;
} /* adjust_light() */

/**
 * This sets the current light level.   This method calls adjust_light()
 * with the correct value to set the light level.
 * <BR><BR>
 * Light Levels:
 * <BR>
 *    Magically Darkened Room   0-
 * <BR>
 *    Absolutely Dark Room      0
 * <BR>
 *    Standard Dark Room        5
 * <BR>
 *    Dimly Lit Room            20
 * <BR>
 *    Mine Shaft with Candles   30
 * <BR>
 *    Partially Lit Room        50
 * <BR>
 *    Well Lit Room             60
 * <BR>
 *    Shaded Forest             60
 * <BR>
 *    Brightly Lit Room         80
 * <BR>
 *    Direct Sunlight           100
 * <BR>
 *    Explosion or flash        200+
 * <BR>
 * @param number The new light level.
 * @see query_my_light()
 * @see query_light()
 */

int set_light(int number) {
    return adjust_light( number - _my_light );
} /* set_light() */

/** @ignore yes */
mixed *stats() {
    return ({
      ({ "light", _light, }),
      ({ "my light", _my_light, }),
    });
} /* stats() */
