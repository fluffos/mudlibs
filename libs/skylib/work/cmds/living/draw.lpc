/**
 * This is the draw command for drawing weapons from scabbard.
 * Original - DW, partly rewritten by Sandoz, 2002.
 */

inherit COMMAND_BASE;

int cmd( string weapon_str, object *scabbards ) {
    object scabbard, *weapons, weapon, *tmp;
    int targetted, limbs;
    string failed;

    if( !scabbards ) {
        scabbards = filter( INV( TP ), (: $1->query_scabbard() :) );

        if( !sizeof(scabbards) ) {
            add_failed_mess("You don't appear to have any scabbards.\n");
            return 0;
        }

        weapons = match_objects_for_existence( weapon_str, scabbards );

        if( !sizeof(weapons) ) {
            add_failed_mess("There is no "+weapon_str+" in "+
                ( sizeof(scabbards) == 1 ? (string)scabbards[0]->poss_short() :
                "any of your scabbards")+".\n");
            return 0;
        }

        scabbard = ENV( weapons[0] );

    } else {
        if( sizeof(scabbards) > 1 ) {
            add_failed_mess("You can only draw weapons from one scabbard at "
                "a time.\n");
            return -1;
        }

        scabbard = scabbards[0];

        if( !scabbard->query_scabbard() ) {
            add_failed_mess("$I doesn't appear to be a scabbard.\n",
                ({ scabbard }) );
            return 0;
        }

        if( ENV(scabbard) != TP ) {
            add_failed_mess("You have to take $I out of "+
                ENV(scabbard)->the_short()+" before you can draw any "
                "weapons from it.\n", ({ scabbard }) );
            return 0;
        }

        weapons = match_objects_for_existence( weapon_str, scabbard );

        if( !sizeof(weapons) ) {
            add_failed_mess("There is no "+weapon_str+" in $I.\n", scabbards );
            return -1;
        }

        targetted = 1;

    }

    weapon = weapons[0];
    // these are the weapons inside the same scabbard as the first one.
    weapons = filter( weapons, (: ENV($1) == ENV($2) :), weapon );

    if( targetted && sizeof(weapons) > 1 &&
        ( ( limbs = weapon->query_no_limbs() ) > 1 ||
        weapons[1]->query_no_limbs() > 1 ) ) {
        add_failed_mess("You cannot draw more than one "+
            query_num( limbs >= weapons[1]->query_no_limbs() ? limbs :
            weapons[1]->query_no_limbs() )+"-handed weapon at a "
            "time.\n");
        return 0;
    }

    if( targetted && sizeof(weapons) > 2 ) {
        add_failed_mess("You cannot draw more than two weapons at a time "
            "from $I.\n", ({ scabbard }) );
        return 0;
    }

    weapons = ( weapon->query_no_limbs() > 1 ? weapons[0..0] : weapons[0..1] );
    failed = "";

    tmp = filter( weapons, (: $1->move( TP ) :) );
    if( sizeof(tmp) ) {
        failed += "You cannot $V "+query_multiple_short(tmp, "the")+" from "+
                  scabbard->the_short()+" because you are too burdened.\n";
        if( !sizeof( weapons -= tmp ) ) {
            add_failed_mess( failed );
            return 0;
        }
    }

    tmp = filter( weapons, (: !sizeof( $1->hold_item( TP ) ) :) );
    if( sizeof(tmp) ) {
        failed += "You cannot $V "+query_multiple_short(tmp, "the")+" from "+
                  scabbard->the_short()+" because you cannot hold "+
                  ( query_group(weapons) ? "them" : "it")+".\n";
        if( !sizeof( weapons -= tmp ) ) {
            add_failed_mess( failed );
            return 0;
        }
    }

    add_succeeded_mess( ({
        "$N $V "+query_multiple_short(weapons)+" from $I.\n",
        "$N $V "+query_multiple_short(weapons)+" from "+
        scabbard->poss_short()+".\n"}), ({ scabbard }) );
    return 1;

} /* cmd() */

mixed query_patterns() {
   return ({"<string'weapon'>", (: cmd( $4[0], 0 ) :),
            "<string'weapon'> from <indirect:object:me'scabbard'>",
            (: cmd( $4[0], $1 ) :)
            });
} /* query_patterns() */
