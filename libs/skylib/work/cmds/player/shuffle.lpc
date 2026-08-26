/**
 * This is the shuffle command which will let us shuffle
 * things about in our containers.
 * @author Sandoz, Feb. 2003.
 */

/** @ignore yes */
int do_shuffle( object *obs, string things )  {
    object ob, *inv, *failed;
    string str;

    if( !ENV(TP) ) {
        add_failed_mess("Oops, you seem to be in limbo.\n");
        return 0;
    }

    if( sizeof(obs) > 1 ) {
        add_failed_mess("Sorry, you can only shuffle things inside one "
            "container at a time.\n");
        return 0;
    }

    ob = obs[0];

    if( ENV(ob) != TP ) {
        add_failed_mess("$I "+( query_group(ob) ?
            "don't" : "doesn't")+" appear to be in your inventory.\n", obs );
        return 0;
    }

    if( ob->query_closed() ) {
        add_failed_mess("You ought to open $I before shuffling the things in "+
            ( query_group(ob) ? "them" : "it")+".\n", obs );
        return 0;
    }

    if( ob->query_liquid() ) {
        add_failed_mess("Sorry, you cannot shuffle anything inside $I.\n",
            obs );
        return 0;
    }

    switch( sizeof( inv = match_objects_for_existence( things, ob ) ) ) {
      case 0 :
        add_failed_mess("There appears to be no '"+things+"' inside $I.\n",
            obs );
        return 0;
      case 1 :
        add_failed_mess("If you figure out a way to shuffle one thing only, "
            "please enlighten me as well.\n", obs );
        return 0;
      default :
        inv -= filter( inv,
            (: $1->query_liquid() && $1->query_continuous() :) );
        inv->move(TP);
        inv = filter( inv, (: ENV($1) != $2 :), ob );

        if( !sizeof(inv) ) {
            add_failed_mess("Try as you might, you can't get anything out of "
                "$I.\n", obs );
            return 0;
        }

        failed = ({ });

        foreach( object thing in shuffle(inv) )
            if( thing->move(ob) )
                failed += ({ thing });

        if( sizeof(failed) )
            str = "  Unfortunately you don't manage to fit "+
                  query_multiple_short( failed, "the")+" in $I anymore.";
        else
            str = "";

        add_succeeded_mess( ({
            "You take out "+query_multiple_short(inv)+" from $I and put them "
            "back randomly one by one."+str+"\n",
            "$N take$s out "+query_multiple_short(inv)+" from $I and put$s "
            "them back randomly one by one.\n"}), obs );
        return 1;

    }

} /* do_shuffle() */

/** @ignore yes */
mixed query_patterns() {
    return ({"<string'things'> {in|inside} <indirect:object:me'container'>",
             (: do_shuffle( $1, $4[0] ) :),
    });
} /* query_patterns() */
