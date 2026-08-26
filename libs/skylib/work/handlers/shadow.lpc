/**
 * This handler deals with recycling shadow objects.
 * Since shadow objects are so easily recyclable,
 * we are going to call reload_object() on them,
 * and keep them here until they're reused.
 * <p>
 * ob = clone_object("/std/shadows/object/identity_hold");<br>
 * should become...<br>
 * ob = SHADOW_H->get_shadow("/std/shadows/object/identity_hold");
 * @author Sandoz, 02 Sept. 2002.
 * @see shadow()
 * @see query_shadowing()
 * @see recycle_shadow()
 * @see get_shadow()
 * @see delete_shadows()
 * @changed Changed recycle_shadow() to return 1 on success and
 * optimized a few other things - Sandoz 26 Sept. 2002.
 */

class shadow_data {
    object *obs;
    int hits;
    int misses;
}

private mapping shadows = ([ ]);

/**
 * This method recycles the shadow object that calls this.
 * It puts it in the recycled list, where it can be taken
 * from again when needed.
 * @param ob the shadow object to recycle
 * @return 1 upon success, 0 upon failure
 * @see shadow()
 * @see query_shadowing()
 * @see get_shadow()
 * @see delete_shadows()
 * @see query_hits()
 */
int recycle_shadow( object ob ) {
    class shadow_data data;

    if( query_shadowing(ob) && !ENV(ob) &&
        classp( data = shadows[base_name(ob)] ) &&
        sizeof( data->obs ) < data->misses ) {
        reload_object(ob);
        data->obs += ({ ob });
        return 1;
    }

    return 0;

} /* recycle_shadow() */

/**
 * This method clones a shadow, or gets a recycled shadow
 * from the handler if there are any available.
 * @param str the filename of the shadow to get
 * @return the shadow object
 * @see shadow()
 * @see query_shadowing()
 * @see delete_shadows()
 * @see recycle_shadow()
 * @see query_hits()
 */
object get_shadow( string str ) {
    class shadow_data data;
    object ob, *obs;
    int i;

    if( classp( data = shadows[str] ) && ( i = sizeof( obs = data->obs ) ) ) {
        while( i-- ) {
            if( ( ob = obs[i] ) && !query_shadowing(ob) ) {
                data->obs = obs[0..i-1];
                data->hits++;
                return ob;
            }
        }
        // We found nothing of use.
        data->obs = ({ });
    }

    if( ob = clone_object(str) ) {
        if( undefinedp( shadows[str] ) )
            shadows[str] = new( class shadow_data, obs : ({ }) );
        shadows[str]->misses++;
    }

    return ob;

} /* get_shadow() */

/**
 * This method destructs all shadows with the specified filename and
 * deletes them from the handler.  This is useful when you have
 * updated a shadow, and don't want to use the recycled (outdated) ones.
 * @param file the filename of the shadows to delete
 * @see shadow()
 * @see query_shadowing()
 * @see recycle_shadow()
 * @see get_shadow()
 * @see query_hits()
 */
void delete_shadows( string file ) {
    if( classp(shadows[file]) ) {
        shadows[file]->obs = filter( shadows[file]->obs,
            (: $1 && !query_shadowing($1) :) );
        map( shadows[file]->obs, (: destruct($1) :) );
        shadows[file]->obs = ({ });
    }
} /* delete_shadows() */

/**
 * This method returns the whole recycled shadows mapping.
 * @return the whole recycled shadows mapping
 * @see shadow()
 * @see query_shadowing()
 * @see recycle_shadow()
 * @see get_shadow()
 * @see delete_shadows()
 * @see query_hits()
 */
mapping query_shadows() { return copy(shadows); }

/**
 * This method returns the number of missed calls to the
 * get_shadow() function for the specified file.
 * @param the filename to get the miss count for
 * @return the number of misses
 * @see shadow()
 * @see query_shadowing()
 * @see recycle_shadow()
 * @see get_shadow()
 * @see delete_shadows()
 * @see query_hits()
 */
int query_misses( string file ) {
    if( classp( shadows[file] ) )
        return shadows[file]->misses;
    return 0;
} /* query_misses() */

/**
 * This method returns the number of hits for a specific recycled shadow.
 * @param file the filename of the shadow to get the hits rate for
 * @return the hits rate for the specified shadow
 * @see shadow()
 * @see query_shadowing()
 * @see recycle_shadow()
 * @see get_shadow()
 * @see delete_shadows()
 */
int query_hits( string file ) {
    if( classp( shadows[file] ) )
        return shadows[file]->hits;
    return 0;
} /* query_hits() */

/**
 * This method returns the recycled shadows for a specific file.
 * @param file the filename of the shadow to get the recycled shadows for
 * @return the recycled shadows
 * @see shadow()
 * @see query_shadowing()
 * @see recycle_shadow()
 * @see get_shadow()
 * @see delete_shadows()
 */
object *query_recycled( string file ) {
    if( classp( shadows[file] ) )
        return shadows[file]->obs;
    return 0;
} /* query_recycled() */

/** @ignore yes */
void dest_me() {
    map( shadows, (: map( $2->obs - ({ 0 }), (: destruct($1) :) ) :) );
    destruct(TO);
} /* dest_me() */

/** @ignore yes */
mixed stats() {
    string file;
    class shadow_data data;
    int hits, misses, total;

    foreach( file, data in shadows ) {
        hits += data->hits;
        misses += data->misses;
        total += sizeof( data->obs );
    }

    return ({
        ({"total hits", hits }),
        ({"total misses", misses }),
        ({"total recycled", total }),
    });

} /* stats() */
