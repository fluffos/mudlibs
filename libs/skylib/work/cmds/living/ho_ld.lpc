/* Command to hold weapons. This _should_ be fairly simple, however it is */
/* complicated by dealing with 1. a variable number of limbs and 2. printing */
/* out all the appropriate holding/unholding/failing/suceeding messages. */

inherit COMMAND_BASE;

int no_limbs( object *obs ){
    int ret = 0;
    foreach( object ob in obs )
    ret += ob->query_no_limbs();
    return ret;
} /* no_limbs() */

int cmd(object *obs, string str) {
    int num_limbs;   // this players limb count
    int avail;       // limbs available
    int old_avail;   // old limbs available, used for sanity checking
    int reqd;        // limbs required
    int i;           // general counter
    int pos;         // which limb position
    int success;     // did we succeed
    int *used;       // limbs used by set_hold or set_unhold

    object ob;
    object weapon;
    object *using;    // limbs currently in use
    object *fails;    // weapons we failed to hold
    object *unfails;  // weapons we failed to unhold
    object *holds;    // weapons we sucessfully held
    object *unholds;  // weapons we successfully unheld
    object *holding; // the things we're already holding.
    object *tmp; // the things we won't try to hold.

    string *limbs;    // limb names;
    string *hhands;   // hands we successfully held weapons in
    string *uhands;   // hands we successfully unheld weapons from

    tmp = ({ });
    foreach( object wep in obs ){
        if( !wep->query_no_limbs() ){
            obs -= ({ wep });
            tmp += ({ wep });
        }
    }
    if( sizeof( tmp ) && !sizeof( obs ) ){
        add_failed_mess(query_multiple_short( tmp ) +" can't be held.\n");
        return 0;
    }
    else if( sizeof(tmp) )
        write( query_multiple_short( tmp )+" can't be held, ignoring...\n");
    if( !sizeof( obs ) ){
        add_failed_mess("Hold what?\n");
        return 0;
    }
    using = TP->query_holding();
    holding = obs & ( using - ({ 0 }) );
    obs -= holding;

    if( !sizeof(obs) ) {
        add_failed_mess("You are already holding $I.\n", holding );
        return 0;
    }

    fails = filter( obs, (: ENV($1) != TP :) );
    obs -= fails;

    if( !sizeof(obs) ) {
        add_failed_mess("$I "+({"is","are"})[query_group(fails)]+" not in "
          "your inventory, so you cannot hold "+({"it","them"})
          [query_group(fails)]+".\n", fails );
        return 0;
    }

    // calc how many hands will be needed
    limbs = TP->query_limbs();
    num_limbs = sizeof(limbs);
    avail = TP->query_free_limbs();

    fails = holds = unholds = hhands = uhands = unfails = ({ });

    // deal with specific hands first
    if( str && obs[0] ) {
        if( obs[0]->query_no_limbs() > 1 ) {
            add_failed_mess("That weapon requires more than one hand!\n");
            return 0;
        }

        if( ( pos = member_array(str, limbs) ) == -1 ) {
            if( !sizeof(limbs) ) {
                add_failed_mess("You seem to have a singular lack of limbs.\n");
                return 0;
            }
            add_failed_mess("Incorrect limb type, must be one of "+
              query_multiple_short(limbs)+".\n");
            return 0;
        }

        // clear the appropriate hand
        if (using[pos]) {
            used = TP->set_unhold(using[pos]);
            if (!sizeof(used)) {
                /* This means we cannot hold the object for sure. */
                unfails += ({ using[pos] });
                uhands += ({ limbs[pos] });
            } else {
                for (i=0;i<sizeof(used) && i<sizeof(limbs);i++) {
                    uhands += ({ limbs[used[i]] });
                }
                unholds += ({ using[pos] });
            }
        }

        if (!sizeof(unfails)) {
            // hold in the appropriate hand
            used = TP->set_hold(obs[0], pos);
            if (!sizeof(used)) {
                fails += ({ obs[0] });
            } else {
                for (i=0;i<sizeof(used) && i<sizeof(limbs);i++) {
                    hhands += ({ limbs[used[i]] });
                }
                holds += ({ obs[0] });
                success = 1;
            }
        }

    } else {  // now deal with normal holding

        foreach(ob in obs) {
            reqd += ob->query_no_limbs();
        }

        if (reqd > num_limbs) {
            tmp = ({ });
            while( no_limbs( obs ) > num_limbs ){
                tmp += ({ obs[sizeof( obs )-1] });
                obs -= ({ obs[sizeof( obs )-1] });
            }
            write( "Can't hold everything, ignoring "+
              query_multiple_short( tmp )+".\n");
        }

        old_avail = -1;
        // if necessary put down items until the required hands are available
        // No need for a while, if it cannot be done.  It cannot be done.
        // If nothign was able to be put down after one sweep through, we are
        // out of luck.
        while ((avail < reqd) &&
          (avail < num_limbs)) {
            if ((reqd > num_limbs - sizeof(unfails)) ||
              (old_avail == avail)) {
                if (sizeof(unfails)) {
                    add_failed_mess("You do not have enough limbs to hold $I, since " +
                      query_multiple_short(unfails) + " failed "
                      "to unhold.\n", obs);
                } else {
                    add_failed_mess("Not able to free up enough limbs to hold $I.\n",
                      obs);
                }
                return 0;
            }
            old_avail = avail;
            using = TP->query_holding();
            for (i = 0; i < sizeof(using); i++) {
                weapon = using[i];
                if(weapon) {
                    used = TP->set_unhold(weapon);
                    if (sizeof(used)) {
                        for (i=0; i < sizeof(used) && used[i] < sizeof(limbs); i++) {
                            uhands += ({ limbs[used[i]] });
                        }
                        unholds += ({ weapon });
                        avail = TP->query_free_limbs();
                        break;
                    } else {
                        if (member_array(weapon, unfails) == -1) {
                            unfails += ({ weapon });
                        }
                        uhands += ({ limbs[i] });
                    }
                }
            }
        }

        if (!sizeof(unfails)) {
            // now try holding the new items
            foreach(ob in obs) {
                using = TP->query_holding();
                pos = 0;

                if(!ob->query_no_limbs() || avail < ob->query_no_limbs()) {
                    fails += ({ ob });
                    break;
                }

                // hold the new items
                while((using[pos]) && (pos < num_limbs)) {
                    pos++;
                }

                used = TP->set_hold(ob, pos);
                if(used == ({ })) {
                    fails += ({ ob });
                } else {
                    for (i=0;i<sizeof(used) && i<sizeof(limbs);i++) {
                        hhands += ({ limbs[used[i]] });
                    }
                    holds += ({ ob });
                    success = 1;
                    avail = TP->query_free_limbs();
                }
            }
        }
    }

    if( sizeof(holding) && !sizeof(holds) )
        write( "You are already holding "+query_multiple_short(holding)+".\n" );

    if( sizeof(unfails) ) {
        write( TP, "You fail to put down "+query_multiple_short(unfails)+
          " from your "+query_multiple_short(uhands)+".\n");
        say( TP->one_short()+" fails to put down "+
          query_multiple_short(unholds)+" from "+
          TP->query_possessive()+" "+query_multiple_short(uhands)+".\n");
    }

    if( sizeof(unholds) ) {
        write( "You put down "+query_multiple_short(unholds)+" from your "+
          query_multiple_short(uhands)+".\n");
        say( TP->one_short()+" puts down "+query_multiple_short(unholds)+
          " from "+TP->query_possessive()+" "+
          query_multiple_short(uhands)+".\n");
    }

    if( sizeof(holds) ) {
        write( "You hold "+query_multiple_short(holds)+" in your "+
          query_multiple_short(hhands)+".\n");
        say( TP->one_short()+" holds "+query_multiple_short(holds)+
          " in "+TP->query_possessive()+" "+
          query_multiple_short(hhands)+".\n");
    }

    // don't print the failed to hold messages if we managed to hold stuff.
    if( !success && sizeof(fails) ) {
        write( "You fail to hold "+query_multiple_short(fails)+".\n");
        say( TP->one_short()+" fails to hold "+
          query_multiple_short(fails)+".\n");
    }

    // We don't add a succeeded mess at all, this will break things when
    // certain objects call cmd() directly.
    return 1;

} /* cmd() */

mixed *query_patterns() {
    return ({
      "<indirect:object:me>",(: cmd($1,0 ) :),
      "<indirect:object:me> in [my] {" +
      implode( TP->query_limbs(), "|") + "}",
      (: cmd( $1,implode( $4[1..], " ")) :) });
} /* query_patterns() */
