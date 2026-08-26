
#include <obj_parser.h>
#include <move_failures.h>

// These were determined empirically (with my hand :) -- Jeremy
#define DROP_H 40
#define PINCH_H 120

#define MAX_GET_NUMBER 20

inherit COMMAND_BASE;

mixed cmd( object *obs, string dir, string indir, mixed *args ) {
    object *dest;
    object ob;
    object dob;
    object *fail_dest;
    object *too_many;
    mixed *fail;
    mixed *ret;
    mixed *stuff;
    mixed amt;
    string sh;
    string hand_unit;
    string match_str;
    int i;
    int num;
    int cap;
    int perc;
    int handful;
    int total_num;
    mixed we;
    object env;
    object *bing;
    class obj_match result;

    if( indir && sizeof(obs) > 10 ) {
        add_failed_mess("Please be more specific as to what you want "
            "to get from.\n");
        return 0;
    }

    if( indir ) {
        match_str = args[0];
        dest = obs;
    } else {
        dest = ( ENV(TP)->query_mirror_room() ?
              ({ ENV(TP), ENV(TP)->query_mirror_room() }) : ({ ENV(TP) }) );
    }

    cap = (int)TP->query_max_weight();
    fail_dest = ({ });
    too_many = ({ });

    foreach( dob in dest ) {
        if( !is_in_me_or_environment( dob, TP ) )
            continue;

        if( dob->cannot_get_stuff() || dob->query_closed() || living(dob) ) {
            fail_dest += ({ dob });
            continue;
        }

        // Containers only.
        if( indir ) {
            result = match_objects_in_environments( match_str, dob );
            if( result->result != OBJ_PARSER_SUCCESS ) {
                add_failed_mess( match_objects_failed_mess( result ) );
                continue;
            }
            obs = result->objects;
        }

        // Containers only.
        if( living(dob) && !dob->allowed_to_loot(TP) ) {
            // Do basically the same check here as is done in the
            // match_objects_for_existence code.
            obs = filter( obs, (:
                  $(dob)->can_find_match_reference_inside_object( $1, TP ) :) );
            obs = filter( obs, (: member_array( $1,
                  $(dob)->query_holding() ) == -1 :) );
            if( !sizeof(obs) ) {
                fail_dest += ({ dob });
                continue;
            }
        }
        if( total_num + sizeof(obs) > MAX_GET_NUMBER ) {
            if( total_num > MAX_GET_NUMBER ) {
                too_many += obs;
                obs = ({ });
            } else {
                too_many += obs[MAX_GET_NUMBER - total_num..];
                obs = obs[0..MAX_GET_NUMBER - total_num - 1];
            }
        }

        total_num += sizeof(obs);

        ret = ({ ([ ]), ([ ]), ([ ]), ([ ]), ([ ]), });
        fail = ({ });

        foreach( ob in obs ) {
            if( ( living(dob) && !dob->allowed_to_loot( TP, ob ) ) ||
                ( ob->query_liquid() && ob->query_food_object() ) ||
                ( ENV(ob) && living( ENV(ob) ) ) ) {
                fail += ({ ob });
                num++;
                continue;
            }

            if( ob->query_continuous() ) {
                amt = ob->query_amount_types();

                if( amt["handful"] ) {
                    hand_unit = "handful";
                    handful = amt["handful"][0];
                } else if( amt["drop"] && ob->query_liquid() ) {
                    hand_unit = "drops";
                    handful = amt["drop"][0] * DROP_H;
                } else if( amt["pinch"] ) {
                    hand_unit = "pinches";
                    handful = amt["pinch"][0] * PINCH_H;
                } else { // Dunno what to do here - I guess give it to them.
                    handful = ob->query_amount();
                }

                if( ob->query_amount() > handful ) {
                    // Knock it down to a carryable amount.
                    // (I hope this is right...)
                    if( !match_str )
                        match_str = ob->query_name();
                    if( i = strsrch( match_str, "of" ) >= 0 )
                        i += 3;
                    if( hand_unit == "handful" )
                        handful = 1;

                    match_str = handful+" "+hand_unit+" of "+match_str[i..];

                    if( !ob = ob->query_parse_id(({ handful, match_str })) )
                        continue;
                }
            }

            env = ENV(ob);

            if( function_exists("do_get", ob ) ||
                function_exists("command_control", ob ) ) {
                if( function_exists("do_get", ob ) ) {
                    we = (int)call_other( ob, "do_get", dob, 0, match_str,
                         ({ 0, match_str }),
                         "<direct:object> from <indirect:object>");
                } else {
                    we = ob->command_control("get", dob, 0, match_str,
                         ({ 0, match_str }),
                         "<direct:object> from <indirect:object>");
                }

                if( !objectp(we) ) {
                    if( we ) {
                        we = (int)ob->query_weight();
                        perc = ( we * 100 ) / cap;
                        i = ( perc >= 95 ? 4 : perc / 25 );
                        if( !ret[i][env] )
                            ret[i][env] = ({ ob });
                        else
                            ret[i][env] += ({ ob });
                    } else {
                        if( member_array( ob,
                            TP->query_succ_mess_indir() ) == -1 &&
                            !query_notify_fail() && !living(ob) ) {
                            fail += ({ ob });
                        }
                        num++;
                    }
                    continue;
                } else {
                    ob = we;
                }
            }
            if( (int)ob->move(TP) == MOVE_OK ) {
                we = (int)ob->query_weight();
                perc = ( we * 100 ) / cap;
                i = ( perc >= 95 ? 4 : perc / 25 );

                if( !ret[i][env] )
                    ret[i][env] = ({ ob });
                else
                    ret[i][env] += ({ ob });

                if( interactive(TP) && ob->query_property("dropped") ) {
                    stuff = ob->query_property("dropped");

                    if( TP->query_name() != stuff[0] &&
                        query_ip_number(TP) == stuff[1] &&
                        sizeof( (HANDLER_DIR+"/multiplayer")->
                        check_allowed( TP, ({ stuff[0] }) ) ) ) {
                        sh = TP->query_cap_name()+" got "+
                        ob->query_short()+" from "+stuff[0]+" who "
                        "logged in from the same IP address.";
                        user_event("inform", sh, "multiplayer");
                        log_file("MULTIPLAYERS", ctime(time())+": "+
                             TP->convert_message(sh)+"\n");
                    } else if( TP->query_name() == stuff[0] &&
                        TP->query_refresh_time() > stuff[2] ) {
                        sh = TP->query_cap_name()+" picked up "+
                             TP->HIS+" equipment after a refresh.";
                        user_event("inform", sh, "multiplayer");
                        log_file("MULTIPLAYERS", ctime(time())+": "+
                             TP->convert_message(sh));
                    }
                }
            } else {
                fail += ({ ob });
                num++;
            }
        }

        /* Print out the different weight messages */
        for( i = 0; i < sizeof(ret); i++ ) {
            if( sizeof(ret[i]) ) {
                /* Print out the different environments for the weights. */
                foreach( env, bing in ret[i] ) {
                    if( TP->query_succ_mess_dir() )
                        bing -= TP->query_succ_mess_dir();

                    if( sizeof(bing) ) {
                        sh = query_multiple_short(bing);
                        write("You "+({"get", "get with a bit of difficulty",
                            "struggle somewhat to get", "find it very "
                            "difficult to get", "use all your strength and "
                            "just barely manage to get"})[i]+" "+sh+" from "+
                            inside_the_short(env)+".\n" );
                        say( (string)TP->one_short()+" "+({ "gets", "gets "
                            "with a bit of difficulty", "struggles somewhat "
                            "to get", "finds it very difficult to get",
                            "uses all "+TP->HIS+" strength and just barely "
                            "manages to get" })[i]+" "+sh+" from "+
                            inside_a_short(env)+".\n");
                    }
                }
            }
        }
        if( sizeof(fail) )
            add_failed_mess("You cannot get $I.\n", fail );
    }

    // This means everything failed.
    if( num == total_num ) {
        if( query_notify_fail() )
            return 0;

        if( indir ) {
            if( !num )
                add_failed_mess("There is no "+match_str+" in $I.\n", dest );
            if( sizeof(fail_dest) )
                add_failed_mess("You cannot get anything from $I.\n", fail_dest );
        }

        return -1;

    } else {
        // Success!
        if( sizeof(too_many) ) {
            add_succeeded_mess( ({ "You cannot pick up more than "+
                query_num(MAX_GET_NUMBER)+" objects at a time; "
                "discarding $I.\n", "" }), too_many );
        }
    }

    return 1;

} /* cmd() */

/** @ignore yes */
mixed query_patterns() {
    return ({
        "<indirect:object:here>", (: cmd( $1, 0, 0, 0 ) :),
        "<string> from <indirect:object>", (: cmd($1, $2, $3, $4) :),
    });
} /* query_patterns() */
