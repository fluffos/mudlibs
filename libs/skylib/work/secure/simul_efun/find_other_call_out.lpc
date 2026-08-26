/**
 * Contains some simul_efuns.
 * @author Pinkfish
 */

/**
 * This method allows you to find a call_out on another object.
 * @param ob the object to find the call out on
 * @param co the name of the call out to find
 * @return the same as from find_call_out()
 * @see efun::find_call_out()
 */
mixed find_other_call_out( object ob, string co ) {
    return evaluate( bind( (: find_call_out($(co)) :), ob ) );
} /* find_other_call_out() */
