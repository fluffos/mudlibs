
#include <money.h>

inherit COMMAND_BASE;

private mapping money_types;
private string pattern;

/** @ignore  yes */
mapping query_money_types() { return copy(money_types); }

void create()  {
    string zone, *zones;

    zones = keys( MONEY_H->query_all_values() );
    money_types = allocate_mapping( sizeof(zones) );

    foreach( zone in zones )
        money_types[ lower_case( zone ) ] = zone;

    if( sizeof(zones) > 1 )
        pattern = "{"+implode( zones, "|")+"}";

    ::create();

}  /* create() */

/** @ignore yes */
int find_the_dough( object env )  {
    if( member_array( MONEY_ALIAS, env->query_alias() ) != -1 )  {
        while( ( env = ENV(env) ) != TP )
           if( env->query_closed() && !env->query_transparent() )
               return 0;
        return 1;
    }

    return 0;

} /* find_the_dough() */

/** @ignore yes */
int cmd( string str, int brief ) {
    object *monies, *divided_money;
    object money, new_money, tmp_money, env;
    mixed tmp_arr, total;
    int i, j, success;
    string tmp;

    switch( TP->check_dark( ENV(TP)->query_light() ) ) {
      case -2 :
      case -1 :
        add_failed_mess("It is too dark here to count your money.\n");
        return 0;
      case 1 :
      case 2 :
        add_failed_mess("It is too bright here to count your money.\n");
        return 0;
      default:
    }

    monies = filter( deep_inventory(TP), (: find_the_dough($1) :) );

    if( sizeof(monies) )  {
        total = ({ });
        success = 0;
        divided_money = ({ 0, 0 });

        foreach( money in monies )  {
            tmp_money = money;

            if( str )  {
                new_money = clone_object(MONEY_OBJECT);
                new_money->set_money_array( money->query_money_array() );

                divided_money = MONEY_H->filter_legal_tender( new_money,
                                money_types[ lower_case(str) ] );

                tmp_money = divided_money[0];

                if( divided_money[1] )
                    divided_money[1]->dest_me();
            }

            if( tmp_money )  {
                if( !brief ) {
                    if( ENV(money) == TP ) {
                        write("Your purse contains "+
                            query_multiple_short( tmp_money->half_short(1) )+
                            ".\n");
                    } else {
                        env = ENV(money);
                        tmp = env->poss_short();
                        env = ENV(env);

                        while( env != TP )  {
                            tmp += " in "+env->poss_short();
                            env = ENV(env);
                        }

                        write( tmp + " contains "+
                            query_multiple_short( tmp_money->half_short(1) ) +
                            ".\n");
                    }
                }

                success++;
                tmp_arr = tmp_money->query_money_array();

                for( i = 0; i < sizeof(tmp_arr); i += 2 ) {
                    j = member_array( tmp_arr[i], total );
                    if( j != -1 ) {
                        total[j+1] += tmp_arr[i+1];
                    } else {
                        total += tmp_arr[i..i+1];
                    }
                }

                if( divided_money[0] )
                    divided_money[0]->dest_me();
            }
        }

        if( !success )  {
            write("You have no money from "+CAP(str)+".\n");
        } else if( brief || ( success >= 1 && sizeof(monies) > 1 ) ) {
            write("You have a total of "+
                MONEY_H->money_string(total)+".\n");
        }

        return 1;
    }

    add_failed_mess("You are flat broke.\n");
    return 0;

} /* cmd() */

/** @ignore yes */
mixed query_patterns()  {
    if( sizeof(money_types) > 1 ) {
        return ({
            "", (: cmd( 0, 0 ) :),
            "brief", (: cmd( 0, 1 ) :),
            "brief "+pattern, (: cmd( $4[0], 1 ) :),
            pattern, (: cmd( $4[0], 0 ) :),
        });
    }

    return ({
        "", (: cmd( 0, 0 ) :),
        "brief", (: cmd( 0, 1 ) :),
    });

} /* query_patterns() */
