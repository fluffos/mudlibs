/**
 * This is a study command that gives one a brief overview of the
 * statistics of an object.
 * @author Sandoz, June 2002.
 */

#include <weapon.h>

#define CONVERT(x) CAP(TP->convert_message(x))

inherit COMMAND_BASE;

/** @ignore yes */
private mixed do_study( object ob ) {
    // WEAPONS.
    if( ob->query_weapon() ) {
        int i;
        mixed attacks;
        string *types, *names;

        names = ob->query_attack_names();
        attacks = ob->query_attack_data();
        types = ({ });

        for( i = 0; i < sizeof(attacks); i += W_ARRAY_SIZE )
            if( member_array( attacks[i+W_TYPE], types ) == -1 )
                types += ({ attacks[i+W_TYPE] });

        return CONVERT( ob->one_short() )+" is a "+
            query_num(ob->query_no_limbs())+"-handed weapon that can be "
            "used to "+query_multiple_short(names)+" and does "+
            query_multiple_short(types)+" damage.";

    }

    // ARMOUR AND CLOTHES.
    if( ob->query_armour() || ob->query_clothing() ) {
        mixed tmp;
        string ret;
        int arm;

        if( stringp( tmp = ob->query_type() ) )
            tmp = ({ tmp });

        tmp = implode( map( tmp,
             (: CLOTHING_H->query_zone_names($1) :) ), (: $1 + $2 :) );

        arm = ob->query_armour();

        ret = CONVERT( ob->one_short() )+" is a piece of "+( arm ? "armour" :
            "clothing")+" that is "+( arm ? "protecting" : "covering")+" "+
            ( !sizeof(tmp) ? "no areas" : "the "+query_multiple_short(
            sort_array( uniq_array( tmp ), 1 ) ) );

        if( ob->query_scabbard() ) {
            ret += ", and can be used to sheath "+ob->query_scabbard_mess(1);
        } else if( sizeof( tmp = ob->query_pockets() ) ) {
            mixed types;
            int i;

            types = ([ ]);

            for( i = 0; i < sizeof( tmp ); i += 2 )
                types[ tmp[ i ] ]++;

            types = map( keys(types), (: query_num($2[$1]) + " " + $1 + " pocket"+
                ( $2[$1] > 1 ? "s" : "" ) :), types );

            ret += ", and has "+query_multiple_short(types);
        }

        return ret+".";

    }

    // SCABBARDS.
    if( ob->query_scabbard() )
        return CONVERT( ob->one_short() )+" is a scabbard that can be used "
            "to sheath "+ob->query_scabbard_mess(1)+".";

    // UNKNOWN.
    return ob;

} /* do_study() */

/** @ignore yes */
int cmd( object *obs ) {
    string *failed;
    mixed info;
    int i;

    info = map( obs, (: do_study($1) :) );
    failed = filter( info, (: objectp($1) :) );
    info -= failed;

    if( i = sizeof(failed) )
        info += ({ CONVERT( query_multiple_short(failed) )+" "+( i == 1 ?
             "is" : "are")+" of undeterminable type and cannot be studied."});

    TP->more_string( implode( info, "\n")+"\n", "Study");
    tell_room( ENV(TP), TP->the_short()+" studies "+
        query_multiple_short(obs)+".\n", TP );

    return 1;

} /* cmd() */

/** @ignore yes */
mixed query_patterns() { return ({"<indirect:object:me>", (: cmd($1) :) }); }
