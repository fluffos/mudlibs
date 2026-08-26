#include <drinks.h>
#include <living.h>

#undef PUBLIC_SURRENDER
#undef POINTS_LOG
#undef DEBUG

int hp, max_hp, gp, max_gp, xp, wimpy, *drink_info;
#ifdef SURRENDER_ON
int surrender;
#endif
nosave int max;
nosave string which;
nosave mapping counts;
nosave int ltime;
nosave string lverb;

void create() {
    max_hp = 1;
    max_gp = 1;
#ifdef SURRENDER_ON
    surrender = -1;
#endif
    drink_info = allocate( D_SIZEOF );
    counts = ([ ]);
} /* create() */

int query_hp() { return hp; }

varargs int set_hp( int number, object attacker ) {
    if ( number > max_hp )
        number = max_hp;
    hp = number;
    if ( ( hp < 0 ) && ( find_call_out( "do_death" ) == -1 ) )
        call_out( "do_death", 0, attacker );
    return hp;
} /* set_hp() */

protected int check_wimpy() {
    int hp;
    hp = this_object()->query_hp();
    if ( hp < 1 )
        return 0;
    if (100 * hp < this_object()->query_wimpy()
      * this_object()->query_max_hp()) {
        this_object()->run_away();
        return 1;
    }
    return 0;
}

#ifdef SURRENDER_ON
protected int check_surrender(object attacker) {
    int hp;
    hp = this_object()->query_hp();
    if (hp < 1)
        return 0;
    if (hp * 100 < this_object()->query_surrender()
      * this_object()->query_max_hp()) {
        ({ attacker, this_object() })->event_surrender(
          this_object(), attacker);
        return 1;
    }
    return 0;
}
#endif

varargs int adjust_hp( int number, object attacker, object weapon, string attack ) {
    hp += number;
    if ( hp > max_hp )
        hp = max_hp;

    if ( ( hp < 0 ) && ( find_call_out( "do_death" ) == -1 ) )
        call_out( "do_death", 0, attacker, weapon, attack );
    if (hp > 0 && number < 0 && attacker && attacker != this_object()) {
#if SURRENDER_ON
        if (this_object()->query_surrender() >= this_object()->query_wimpy())  {
            if (!check_surrender(attacker))
                check_wimpy();
        }
        else  {
            if (!check_wimpy())
                check_surrender(attacker);
        }
#else
        check_wimpy();
#endif
    }
    return hp;
} /* adjust_hp() */

varargs string health_string(object person, int full) {
    return HEALTH_H->health_string(person, full);
} /* health_string() */

int query_max_hp() { return max_hp; }

int set_max_hp( int number ) {
    int old_hp;
    old_hp = hp;
    if ( max_hp == hp )
        hp = number;
    else
    if ( max_hp ) {
        hp = ( hp * number ) / max_hp;
    }
    else
        hp = number;
    max_hp = number;
    if ( hp > max_hp )
        hp = max_hp;
    if ( ( hp < 0 ) && ( old_hp > 0 ) )
        hp = max_hp;
    return max_hp;
} /* set_max_hp() */

int query_gp() { return gp; }

int query_specific_gp( string gp_type ) {
    return gp;
} /* query_specific_gp() */

void clear_gp_info() { which = 0; }

int set_gp( int number ) {
    gp = number;
    if ( gp > max_gp )
        gp = max_gp;
    return gp;
} /* set_gp() */

int adjust_gp( int number ) {

    if ( gp + number < 0 )
        return -1;

    gp += number;

    if ( gp > max_gp )
        gp = max_gp;

    return gp;
}

int query_max_gp() { return max_gp; }

int set_max_gp( int number ) {
    if ( max_gp ) gp = ( gp * number ) / max_gp;
    else gp = number;
    max_gp = number;
    if ( gp > max_gp ) gp = max_gp;
    return max_gp;
} /* set_max_gp() */

int query_xp() { return xp; }

varargs int adjust_xp( int number, int shared ) {
    if(number > 10000) {
      TCRE("shiannar", sprintf("%s %O recieved %d xp from %s %O", TO->query_name(), TO, number, PO->query_short(), PO));
    }
    if(number > 10000 && previous_object() &&
      explode(file_name(previous_object()), "/")[0] == "w")
        log_file("CHEAT", ctime(time()) + " " + file_name(previous_object()) +
          " gave " + number + " Xp for " + this_object()->query_name() +
          "\n");

    xp += number;
    return xp;
} /* adjust_xp() */

int query_wimpy() { return wimpy; }

int set_wimpy( int number ) {
    if ( ( number < 0 ) || ( number > 100 ) ) return -1;
    return wimpy = number;
} /* set_wimpy() */

#ifdef SURRENDER_ON
int query_surrender() {
    if (surrender == -1) {
        if (wimpy > 94)
            return 100;
        else
            return wimpy + 5;
    } else
        return surrender;
}

int set_surrender( int number ) {
    if ( ( number < 0 ) || ( number > 100 ) ) return -1;
    return surrender = number;
} /* set_surrender() */
#endif

int *query_drink_info() { return drink_info; }

int query_volume( int type ) {
    if ( type >= D_SIZEOF ) return 0;
    return drink_info[ type ];
} /* query_volume() */

int adjust_volume( int type, int amount ) {
    if ( type >= D_SIZEOF ) return 0;

    return drink_info[ type ] += amount;
} /* adjust_volume() */

void update_volumes() {
    int i, delta;
    delta = (int)this_object()->query_con();
    for ( i = 0; i < sizeof( drink_info ); i++ ) {
        if ( drink_info[ i ] > delta ) {
            drink_info[ i ] -= delta;
            // drinking cools you down if you're hot, eating warms you up
            // if you're cold.
            if(this_object()->query_personal_temp() >  0 && i == D_DRINK)
                this_object()->adjust_personal_temp(-(delta/3));
            else if(this_object()->query_personal_temp() <  0 && i == D_FOOD)
                this_object()->adjust_personal_temp(delta/3);
        } else
        if ( drink_info[ i ] < -delta )
            drink_info[ i ] += delta;
        else
            drink_info[ i ] = 0;
    }
} /* update_volumes() */

mapping query_counts() { return counts; }
