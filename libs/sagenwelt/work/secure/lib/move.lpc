/// @file move.c
/// @brief this module is used for movable objects
///
/// Every object that wants to move something, either itself or something
/// else, needs to use efun::move_object to do the deed.  That efun doesn't
/// know anything about weight, encumbrance, light, ... as such there might be
/// many reasons why that desired move is disallowed.  For this reason direct
/// use of efun::move_object is restricted to this file!
/// @author Gwenhwyvar
/// @version 0.0.0
/// @date 2016-02-04


// --------------------------------------------------------------------------
/// @brief move
///
/// Moves this_object() from current environment (if any) into dest, making
/// some check prior if the move is allowed or not.  Also adjusts any necessary
/// values (weight, encumbrance, light, ...)
/// @Param dest
/// @Returns TRUE if the move is done, FALSE otherwise
// --------------------------------------------------------------------------
public nomask int move(object dest)
{
    object  to = TO();
    object *anc_to;
    object *anc_dest;
    string  fn;

    // move into oneself? not a god idea...
    if(dest == to)
        return FALSE;

    anc_to   = deep_inherit_list(to);

    // special handling for connection objects (login/player) as destination
    if(((fn = base_name(dest)) == LOGIN_OB) || (fn == PLAYER_OB))
    {
        // only input handling objects may be moved into players
        if(member_array(M_INPUT, anc_to) == -1)
            error("illegal to move non input handling objects into players");

        // and those move themselves only!!!
        if(origin() != ORIGIN_LOCAL)
            error("illegal to move input handling objects");

        efun::move_object(to, dest);
        return TRUE;
    }

    // a room can contain things but can't be contained itself
    if(member_array(ROOM, anc_to) != -1)
        error("illegal use of move with room as movable");

    // aside from above special case only standard objects may be moved
    if(member_array(STD_OBJECT, anc_to) == -1)
        error("illegal use of move with non object as movable");

    anc_dest = deep_inherit_list(dest);
    // only containers (rooms ARE containers) can contain other objects
    if(member_array(CONTAINER, anc_dest) == -1)
        error("illegal use of move with non container as destination");

    return FALSE;
}
