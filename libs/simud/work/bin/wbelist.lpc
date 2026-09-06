void main(string args)
{
    object blueprint;
    object *exits;
    /* find all broken exits */
    /* an exit is broken if its destination doesn't exist */

    exits = clones(args);

    foreach (object exit : exits) {
        object target;
        target = exit->get_destination();
        if ( target == 0 ) {
            msg( object_name(exit) + " located at " + get_location(exit) );
        }
    }
}