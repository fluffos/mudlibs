/**
 * The vault handler keeps track of inventories and other
 * properties of players' vaults.  It also deals with the
 * monthly fees.
 * @author Sandoz, 2002.
 */

#include <login.h>
#include <origin.h>

#define VAULT_SAVE_DIR     SAVE_DIR "/vaults/"
#define SAVE_FILE          VAULT_SAVE_DIR "main.o"

#define VAULT_CONTAINER    STD_OBJECT_DIR "/vault_container"

#define VAULT_SIZE         0
#define VAULT_COST         1

#define DAY                (60*60*24)
#define MONTH              (30*DAY)
#define MS(x,y)            (string)MONEY_H->money_value_string(x,y)

/**
 * This class is used to store the data for a specific vault.
 * @member sizes the vault sizes available in the specified vault
 * @member vaults the players' vaults
 */
class vault_data {
    string *sizes;
    mapping vaults;
}

/**
 * This class is used to store the properties and contents
 * of a player's vault.
 * @member size the size of the vault
 * @member expiry_time the expiry time of the player's vault account
 * @member new_vault whether the player has visited their vault yet
 */
class player_vault_data {
    string size;
    int expiry_time;
    int new_vault;
}

private mapping vaults, warned;

private nosave mapping vault_sizes, returnables;

private void clean_vault( string *vault_names );
private void expire_vaults();
private void do_player_logon( object player );

private void save_me() {
    unguarded( (: save_object, SAVE_FILE :) );
} /* save_me() */

/** @ignore yes */
void create() {
    if( !unguarded( (: dir_exists, VAULT_SAVE_DIR :) ) )
        unguarded( (: mkdir, VAULT_SAVE_DIR :) );

    if( unguarded( (: file_exists, SAVE_FILE :) ) )
        unguarded( (: restore_object, SAVE_FILE :) );

    vault_sizes = ([ "small"        : ({  500, -1     }),
                     "medium-sized" : ({ 1000, 6000  }),
                     "large"        : ({ 1800, 12000 }),
                     "very large"   : ({ 3000, 30000 }),
                     ]);

    if( !mapp(vaults) )
        vaults = ([ ]);

    if( !mapp(warned) )
        warned = ([ ]);

    expire_vaults();

} /* create() */

/** @ignore yes */
string normalize_name( string name ) {
    int i;

    name = lower_case(name);

    for( i = 0; i < strlen(name); i++ ) {
        if( name[i] == ''' ) {
            name = name[0..i-1] + name[i+1..];
            i--;
            continue;
        }

        if( name[i] < 'a' || name[i] > 'z')
            name[i] = '_';
    }

    return implode( explode( name, "_") - ({ 0, "" }), "_");

} /* normalize_name() */

/** @ignore yes */
string query_vault_save_dir( string name ) {
    name = normalize_name( name );
    return VAULT_SAVE_DIR+name+"/";
} /* query_vault_save_dir() */

/**
 * This method queries if the specified vault exists.
 * @param name the name of the vault to test
 * @return 1 if it exists, 0 if not
 */
int query_vault( string name ) { return !undefinedp( vaults[name] ); }

/**
 * This method is called by the refresh handler.
 * @param name the name of the player being refreshed
 */
void player_refreshed( string name ) {
    string vault, file;

    if( !sizeof(vaults) )
        return;

    if( origin() != ORIGIN_LOCAL && base_name(PO) != REFRESH_H )
        error("Bad origin for player_refreshed.\n");

    foreach( vault in keys(vaults) ) {
        if( !undefinedp( vaults[vault]->vaults[name] ) ) {
            file = query_vault_save_dir(vault)+name+".o";
            if( unguarded( (: file_exists, file :) ) )
                unguarded( (: rm, file :) );
        }
        map_delete( vaults[vault]->vaults, name );
    }

    map_delete( vaults[vault]->vaults, name );

    if( pointerp( warned[vault] ) )
        warned[vault] -= ({ name });

    save_me();

    file = query_vault_save_dir("quest_rewards")+name+".o";
    if( unguarded( (: file_exists, file :) ) )
        unguarded( (: rm, file :) );

    log_file("VAULTS", "%s refreshed - %s\n", CAP(name), ctime(time()) );

} /* player_refreshed() */

/** @ignore yes */
int query_vault_max_weight( string size ) {
    if( vault_sizes[size] )
        return vault_sizes[size][VAULT_SIZE];
    return 0;
} /* query_vault_max_weight() */

/**
 * This method creates a container for the actual vault room.
 * @param player the player we are creating the container for
 * @param size the size of the container to create
 * @return the container object
 */
object make_container( string player, string size ) {
    object cont;

    cont = clone_object(VAULT_CONTAINER);

    if( size )
        cont->set_max_weight( query_vault_max_weight(size) );

    cont->set_open();
    cont->set_stuck( 1 );
    cont->reset_get();

    if( player )
        cont->set_ownership( player );

    return cont;

} /* make_container() */

/**
 * This method restores the returnables mapping for
 * the specified player.
 * @param name the name of the player to restore the
 * returnables mapping for
 */
private void restore_returnables( string name ) {
    string stuff;

    stuff = unguarded( (: read_file,
        query_vault_save_dir("quest_rewards")+name+".o" :) );

    if( stringp(stuff) )
        returnables = restore_variable( stuff );

} /* restore_returnables() */

/**
 * This method removes the returnables file for the specified player.
 * @param name the name of the player whose returnables to delete
 */
private void remove_returnables( string name ) {
    unguarded( (: rm, query_vault_save_dir("quest_rewards")+name+".o" :) );
} /* remove_returnables() */

/**
 * This method saves the returnables mapping for the specified player.
 * @param name the name of the player whose returnables to save
 */
private void save_returnables( string name ) {
    string d;

    d = query_vault_save_dir("quest_rewards");

    if( !unguarded( (: dir_exists, d :) ) )
        unguarded( (: mkdir, d :) );

    unguarded( (: write_file, d+name+".o", save_variable(returnables), 1 :) );

    returnables = 0;

} /* remove_returnables() */

/**
 * This method does the actual returning of quest items.
 * @param player the player to return the items to
 * @param vault the name of the vault the items are from
 * @param things the things to return to the player
 */
private void do_return( object player, string vault, object *things ) {
    tell_object( player, "An errand runner from "+
        vault+" approaches you and returns "+
        query_multiple_short(things)+" to you, for your vault "
        "account has been closed down for overdue rent.\n");

    things = filter( things, (: $1->move($2) :), player );

    if( sizeof( things ) ) {
        tell_object( player, "He places "+query_multiple_short( things,
            "the")+" "+( ENV(player)->query_property("here") ||
            "on the ground")+" for you are too burdened to accept "+
            ({"it", "them"})[query_group(things)]+".\n");
        things->move( ENV(player) );
    }

} /* do_return() */

/**
 * This method recycles the things in an expired vault,
 * and deletes the account from the vaults mapping.
 * Items with the "quest_reward" property will be given
 * back to players, while the rest should end up in
 * general stores.
 */
private void do_recycle( string vault, string name ) {
    string dir;

    dir = query_vault_save_dir( vault );

    if( unguarded( (: file_exists, dir+name+".o" :) ) ) {
        object *qrs, cont, tmp;

        cont = make_container( 0, 0 );
        cont->set_save_file( dir + name );
        cont->set_no_save( 1 );

        unguarded( (: rm, dir+name+".o" :) );

        qrs = filter( deep_inventory(cont),
            (: $1->query_property("quest_reward") :) );

        if( sizeof(qrs) ) {
            if( ( tmp = find_player(name) ) && ENV(tmp) ) {
                do_return( tmp, vault, qrs );
            } else {
                tmp = make_container( name, 0 );

                restore_returnables( name );

                if( mapp(returnables) ) {
                    if( returnables[vault] )
                        tmp->init_dynamic_arg( returnables[vault] );
                } else {
                    returnables = ([ ]);
                }

                qrs->move(tmp);
                returnables[vault] = tmp->query_dynamic_auto_load();
                save_returnables( name );

                LOGIN_H->add_static_login_call( name, "do_login_call",
                    base_name(TO) );

                tmp->dest_me();
                if( tmp )
                    destruct(tmp);
            }
        }

        deep_inventory(cont)->move("/room/rubbish");
        cont->dest_me();
        if( cont )
            destruct(cont);
    }

    map_delete( vaults[vault]->vaults, name );

    if( pointerp( warned[vault] ) )
        warned[vault] -= ({ name });

    log_file("VAULTS", "%s - account recycled in %s - %s\n",
        CAP(name), vault, ctime(time()) );

} /* do_recycle() */

/**
 * This method queries whether or not the specified player
 * has an account in the specified vault.
 * @param vault the name of the vault to test
 * @param name the name of the player to test
 * @return 1 if the player has an account in the vault, 0 if not
 */
int query_account_in( string vault, string name ) {
    if( !undefinedp( vaults[vault] ) &&
        !undefinedp( vaults[vault]->vaults[name] ) ) {
        if( vaults[vault]->vaults[name]->expiry_time &&
            vaults[vault]->vaults[name]->expiry_time < time() ) {
            do_recycle( vault, name );
            save_me();
            return 0;
        } else {
            return 1;
        }
    }

    return 0;

} /* query_account_in() */

/**
 * This method returns the expiry time of the specified vault
 * for the specified player.
 * @param vault the name of the vault to get the expiry time for
 * @param name the name of the player to get the expiry time for
 * @return the expiry time of the player's vault, or 0 if none
 */
int query_expiry_time( string vault, string name ) {
    if( query_account_in( vault, name ) )
        return vaults[vault]->vaults[name]->expiry_time;
    return 0;
} /* query_expiry_time() */

/**
 * This method returns the vault upkeep cost for one month
 * for the specified player.
 * @param vault the vault name to get the cost for
 * @param name the name of the player to get the cost for
 * @return the renting cost of one month
 */
int query_vault_rent( string vault, string name ) {
    if( query_account_in( vault, name ) )
        return vault_sizes[ vaults[vault]->vaults[name]->size ][VAULT_COST];
    return 0;
} /* query_vault_rent() */

/**
 * This method returns all available vault sizes.
 */
string *query_vault_sizes() { return keys(vault_sizes); }

/**
 * This method returns the player's vault size in the specified vault.
 * This will be a string representation of the vault size,
 * ie. "small", "large".
 * @param vault the vault to get the vault size for
 * @param player the player to get the vault size for
 * @return the player's vault size in the specified vault
 */
string query_player_vault_size( string vault, string player ) {
    if( query_account_in( vault, player ) )
        return vaults[vault]->vaults[player]->size;
    return 0;
} /* query_player_vault_size() */

/**
 * This method is called by the login handler and it initiates
 * the process of returning quest rewards to players whose vaults
 * have expired.
 * @param player the player logging in
 * @param type the type of login
 */
void do_login_call( mixed player, string type ) {
    if( type == LOGIN && ( player = find_player(player) ) )
        call_out( (: do_player_logon :), 10, player );
} /* do_login_calls() */

/**
 * This method returns quest rewards from expired vaults to
 * their owners upon logon.
 * @param player the player logging on
 */
private void do_player_logon( object player ) {
    string vault, name;

    if( !player )
        return;

    name = player->query_name();

    if( !unguarded( (: file_exists,
        query_vault_save_dir("quest_rewards")+name+".o" :) ) )
        return;

    if( !ENV(player) ) {
        tell_object( player, "An errand runner approaches you to return "
            "some items to you, but decides not to, for you seem to "
            "have no environment.\n");
        return;
    }

    log_file("VAULTS", "%s reclaimed returnables - %s\n",
        CAP(name), ctime(time()) );

    restore_returnables(name);
    remove_returnables(name);

    if( mapp(returnables) ) {
        object cont;

        cont = make_container( name, 0 );

        foreach( vault in keys(returnables) ) {
            INV(cont)->dest_me();
            cont->init_dynamic_arg( returnables[vault] );
            do_return( player, vault, INV(cont) );
        }

        cont->dest_me();
        if( cont )
            destruct(cont);

    }

    returnables = 0;
    LOGIN_H->remove_static_login_call( name, "do_login_call",  base_name(TO) );

} /* do_player_logon() */

/** @ignore yes */
private void clean_vault( string *vault_names ) {
    string vault, name;
    int time, expiry;

    vault = vault_names[0];
    vault_names = vault_names[1..];
    time = time();

    foreach( name in keys( vaults[vault]->vaults ) ) {
        if( !PLAYER_H->test_user( name ) ) {
            if( unguarded( (: file_exists,
                query_vault_save_dir(vault)+name+".o" :) ) )
                unguarded( (: rm, query_vault_save_dir(vault)+name+".o" :) );
            map_delete( vaults[vault]->vaults, name );
            log_file("VAULTS", "%s lost account in %s (no user) - %s\n",
                CAP(name), vault, ctime(time()) );
            continue;
        }

        expiry = vaults[vault]->vaults[name]->expiry_time;

        if( expiry ) {
            if( expiry < time ) {
                do_recycle( vault, name );
                continue;
            }

            if( expiry - MONTH / 2 < time && ( !pointerp(warned[vault]) ||
                member_array( name, warned[vault] ) == -1 ) ) {
                string who;

                if( !pointerp(warned[vault]) )
                    warned[vault] = ({ name });
                else
                    warned[vault] += ({ name });

                switch( PLAYER_H->test_gender(name) ) {
                  case 1 :
                    who = "Sir";
                  break;
                  case 2 :
                    who = "Madam";
                  break;
                  default :
                    who = CAP(name);
                }

                MAIL_H->do_mail_message( name, "the vault manager",
                    "Your vault space.", "", "Dear "+who+",\n\nYour vault "
                    "account in "+vault+" is going to expire on "+
                    ctime(expiry)+".  We urge you to pay a visit to us and "
                    "remedy the situation in a timely manner.  If you have "
                    "not extended your lease by "+ctime(expiry)+", we will "
                    "be forced to dispose of all items within your vault.\n\n"
                    "Management,\n"+vault, 0, 0 );
                continue;
            }
        }
    }

    save_me();

    if( sizeof( vault_names ) )
        call_out( (: clean_vault :), 60, vault_names );
    else
        call_out( (: expire_vaults :), DAY );

} /* clean_vault() */

/** @ignore yes */
private void expire_vaults() {
    string *vault_names;

    if( sizeof( vault_names = keys(vaults) ) )
        clean_vault(vault_names);

} /* expire_vaults() */

/**
 * This method adds a new vault into the handler.
 * @param name the name of the vault to add
 * @param sizes the available vault sizes
 */
void add_vault( string name, string *sizes ) {
    int i;
    string *bad;

    if( !name || name == "") {
        printf("No vault name specified.\n");
        return;
    }

    if( i = sizeof( bad = filter( sizes, (: !$2[$1] :), vault_sizes ) ) ) {
        printf("Bad vault size%s : %s.\n", i == 1 ? "" : "s",
            query_multiple_short(bad) );
        return;
    }

    if( query_vault( name ) ) {
        vaults[name]->sizes = sizes;
    } else {
        vaults[name] = new( class vault_data,
            sizes      : sizes,
            vaults     : ([ ]) );
    }

    save_me();

    name = query_vault_save_dir(name);
    if( !dir_exists( name ) )
        unguarded( (: mkdir, name :) );

} /* add_vault() */

/**
 * This method removes a vault and all associated data,
 * along with all vault content.  Use with care.
 * @param name the name of the vault to remove
 * @return 1 if successfully removed, 0 if not
 */
int remove_vault( string name ) {
    string dir;

    if( !adminp( previous_object(-1) ) ) {
        printf("Sorry, only admin can remove vaults.\n");
        return 0;
    }

    if( !query_vault(name) ) {
        printf("No such vault.\n");
        return 0;
    }

    map_delete( vaults, name );
    map_delete( warned, name );

    save_me();

    dir = query_vault_save_dir(name);

    map( unguarded( (: get_dir, dir :) ),
      (: unguarded( (: rm, $2 + $1 :) ) :), dir );

    unguarded( (: rmdir, dir :) );

    log_file("VAULTS", "%s REMOVED %s - %s\n",
        CAP( TP->query_name() ), name, ctime(time()) );

    return 1;

} /* remove_printer() */

/**
 * This method returns the cost of a single visit for the
 * specified vault size.
 * @param vault the vault to get the vault size for
 * @param name the name of the player to get the visiting cost for
 * @param visit_cost the set visit cost from the vault room
 * @return the visit cost
 */
int query_visit_cost( string vault, string name, int visit_cost ) {
    if( vault_sizes[vaults[vault]->vaults[name]->size][VAULT_COST] == -1 &&
        !vaults[vault]->vaults[name]->new_vault )
        return visit_cost;
    return 0;
} /* query_player_vault_size() */

/** @ignore yes */
void event_visit( string vault, string name ) {
    if( vaults[vault]->vaults[name]->new_vault ) {
        vaults[vault]->vaults[name]->new_vault = 0;
        save_me();
    }
} /* event_visit() */

/** @ignore yes */
private string price_line( string size, string place, int open_cost,
                           int visit_cost, int flag ) {
    int cost;

    cost = vault_sizes[size][VAULT_COST];
    size = CAP( add_a(size) )+" vault";

    if( cost == -1 )
        cost = open_cost;
    else
        visit_cost = 0;

    if( flag ) {
        if( visit_cost )
            return sprintf("%-=*s%s\n", 26, size+":",
                indent("Opening: "+MS( cost, place )+"\n"
                       "Visiting: "+MS( visit_cost, place ), 26, 79 )[26..] );
        return sprintf("%-=*s%s\n", 26, size+":",
            indent("Opening: "+MS( 3*cost, place )+"\n"
                   "Monthly fee: "+MS( cost, place ), 26, 79 )[26..] );
    }

    if( visit_cost )
        return size+" with no upkeep fees, but an opening cost of "+
            MS( cost, place )+" and a visiting cost of "+
            MS( visit_cost, place )+".";

    return size+" with no visiting costs, but an opening cost of "+
        MS( 3 * cost, place )+" and a monthly upkeep fee of "+
        MS( cost, place )+".";

} /* price_line() */

/**
 * This method returns the price list for a specific vault.
 * @param vault the name of the vault to get the price list for
 * @param place the place for price calculations
 * @param open_cost the opening cost of an account with no upkeep costs
 * @param visit_cost the visiting cost of a vault with no upkeep costs
 * @param flag if the flag is true, the price list will be
 * formatted so that it would look better on signs etc.
 */
string query_pricing( string vault, string place, int open_cost,
                      int visit_cost, int flag ) {
    if( query_vault( vault ) )
        return implode( map( vaults[vault]->sizes,
            (: price_line( $1, $2, $3, $4, $5 ) :), place, open_cost,
            visit_cost, flag ), ( !flag ? " " : "\n") );

    return 0;

} /* query_pricing() */

/**
 * This method deposits a certain amount of money onto a player's
 * vault account.
 * @param vault the name of the vault we are depositing into
 * @param months the number of months we want to pay the rent for
 * @param prop the proprietor NPC
 * @param place the place for money calculations
 * @return 1 upon success, 0 upon failure
 */
int do_pay( string vault, int months, object prop, string place ) {
    int amount, cost;
    string name;

    name = TP->query_name();

    if( !query_account_in( vault, name ) ) {
        prop->do_command("'You have not rented any vault space here.");
        return 1;
    }

    if( !amount = query_vault_rent( vault, name ) ) {
        prop->do_command("'Something has gone wrong with calculating your "
            "monthly upkeep costs.  Please talk to a creator, or file a bug "
            "report.");
        return 1;
    }

    if( amount == -1 ) {
        prop->do_command("'Your vault doesn't have upkeep costs.");
        return 1;
    }

    if( !months ) {
        prop->do_command("'You have to specify the number of months you wish "
            "to pay the rent for.");
        return 1;
    }

    if( months < 0 ) {
        prop->do_command("'I'm afraid we don't refund rent for vaults.");
        return 1;
    }

    cost = amount * months;

    if( (int)TP->query_value_in( place ) < cost ) {
        prop->do_command("'You do not have the "+MS( cost, place )+" that "
            "it would cost to pay your vault rent for "+
            query_num(months)+" month"+( months == 1 ? "" : "s")+".");
        return 1;
    }

    prop->do_command("'Very well, that'll be "+MS( cost, place )+" for "+
        query_num(months)+" month"+( months > 1 ? "s" : "")+", please.");

    TP->pay_money( MONEY_H->create_money_array( cost, place ), place );

    vaults[vault]->vaults[name]->expiry_time += MONTH * months;

    if( pointerp( warned[vault] ) )
        warned[vault] -= ({ name });

    save_me();

    tell_room( ENV(TP), TP->the_short()+" $V$0=hands,hand$V$ some coins to "+
        prop->the_short()+".\n", TP );
    tell_object( TP, "You hand the coins to "+prop->the_short()+".\n"
        "The rent for your vault has been paid until "+
        ctime( vaults[vault]->vaults[name]->expiry_time )+".\n");

    prop->do_command("'Thank you.");
    return 1;

} /* do_pay() */

/**
 * This method opens an account for a player.
 * @param vault the name of the vault
 * @param size the size of the vault we wish to apply for
 * @param prop the proprietor NPC
 * @param place the place for money calculations
 * @param open_cost the opening cost of an account with no upkeep costs
 * @param visit_cost the visiting cost of a vault with no upkeep costs
 */
int do_rent( string vault, string size, object prop, string place,
             int open_cost, int visit_cost ) {
    int cost, no_fee;
    class player_vault_data data;
    string name;

    name = TP->query_name();

    if( query_account_in( vault, name ) ) {
        prop->do_command("'You are already renting vault space here!");
        return 1;
    }

    if( !cost = vault_sizes[size][VAULT_COST] ) {
        prop->do_command("'Something has gone wrong with calculating the "
            "cost of the vault space you requested.  Please talk to a "
            "creator, or file a bug report.");
        return 1;
    }

    if( cost == -1 ) {
        no_fee = 1;
        cost = open_cost;
    } else {
        cost = 3 * cost;
    }

    if( (int)TP->query_value_in( place ) < cost ) {
        prop->do_command("'You do not have the "+MS( cost, place )+" that "
            "it would cost to rent "+add_a(size)+" vault"+( no_fee ? "" :
            " for three months")+".");
        return 1;
    }

    if( no_fee ) {
        prop->do_command("'The vault you requested doesn't have any upkeep "
            "costs, however an initial payment of "+MS( cost, place )+" is "
            "necessary, plus an entry fee of "+MS( visit_cost, place )+" each "
            "time you wish to visit the vault.");
    } else {
        prop->do_command("'Very well, that'll be "+MS( cost, place )+".  "
            "This will be considered as down payment for three months.");
    }

    TP->pay_money( MONEY_H->create_money_array( cost, place ), place );

    data = new( class player_vault_data,
                size        : size,
                expiry_time : ( no_fee ? 0 : time() + 3 * MONTH ),
                new_vault   : 1 );

    vaults[vault]->vaults[name] = data;

    if( pointerp( warned[vault] ) )
        warned[vault] -= ({ name });

    save_me();

    tell_object( TP, "You hand the coins to "+prop->the_short()+".\n");
    tell_room( ENV(TP), TP->the_short()+" $V$0=hands,hand$V$ some coins to "+
        prop->the_short()+".\n", TP );

    if( !no_fee ) {
        tell_object( TP, "The rent for your vault has been paid until "+
            ctime( vaults[vault]->vaults[name]->expiry_time )+".\n");
        prop->do_command("'Please keep in mind that once your rent runs out, "
            "any items in the vault will be discarded, and you will lose the "
            "vault space.  For your convenience try to ensure adequate funds "
            "on your vault account at all times.");
    }

    if( sizeof( vaults[vault]->sizes ) > 1 )
        prop->do_command("'Should you wish to switch to a different vault "
            "size at a later date, then you are most welcome to do so.");

    log_file("VAULTS", "%s rented %s vault in %s - %s\n",
        CAP(name), add_a(size), vault, ctime(time()) );

    prop->do_command("'Thank you.");
    return 1;

} /* do_rent() */

/** @ignore yes */
int sort_by_weight( object ob1, object ob2 ) {
    int i, j;

    i = ob1->query_weight();
    j = ob2->query_weight();

    if( i < j )
        return -1;

    if( i > j )
        return 1;

    return 0;

} /* sort_by_weight() */

/**
 * This method switches a player's vault size.
 * @param vault the name of the vault
 * @param size the new size of the vault
 * @param prop the proprietor NPC
 * @param place the place for money calculations
 * @param open_cost the opening cost of an account with no upkeep costs
 * @param visit_cost the visiting cost of a vault with no upkeep costs
 */
int do_switch( string vault, string size, object prop, string place,
               int open_cost, int visit_cost ) {
    int tmp, cost, no_fee, i;
    string name, ret, cur_size;

    name = TP->query_name();

    if( !query_account_in( vault, name ) ) {
        prop->do_command("'You have not rented any vault space here.");
        return 1;
    }

    cur_size = vaults[vault]->vaults[name]->size;

    if( cur_size == size ) {
        prop->do_command("'You are already renting "+add_a(size)+" vault.");
        return 1;
    }

    if( tmp = vaults[vault]->vaults[name]->expiry_time )
        tmp = to_int( to_float( tmp - time() ) / MONTH *
              vault_sizes[cur_size][VAULT_COST] );

    if( !cost = vault_sizes[size][VAULT_COST] ) {
        prop->do_command("'Something has gone wrong with calculating the "
            "cost of the vault space you requested.  Please talk to a "
            "creator, or file a bug report.");
        return 1;
    }

    if( cost == -1 ) {
        no_fee = 1;
        cost = open_cost;
    } else {
        cost = 3 * cost;
    }

    cost -= tmp;

    if( cost > 0 ) {
        if( (int)TP->query_value_in( place ) < cost ) {
            prop->do_command("'You do not have the additional "+
                MS( cost, place )+" that it would cost to change your vault "
                "from "+cur_size+" to "+add_a(size)+" one.");
            return 1;
        }

        prop->do_command("'You have to pay an additional "+
            MS( cost, place )+" to switch your vault from "+cur_size+" to "+
            add_a(size)+" one.");

        TP->pay_money( MONEY_H->create_money_array( cost, place ), place );
        vaults[vault]->vaults[name]->expiry_time = time() + 3 * MONTH;

        tell_object( TP, "You hand the coins to "+prop->the_short()+".\n");
        tell_room( ENV(TP), TP->the_short()+" $V$0=hands,hand$V$ some coins "
            "to "+prop->the_short()+".\n", TP );

    } else {
        prop->do_command("'You have paid enough rent for your current vault "
            "to switch your vault from "+cur_size+" to "+
            add_a(size)+" one without any additional costs.");
        tmp = -tmp;
        tmp = to_int( to_float(tmp) / vault_sizes[size][VAULT_COST] * MONTH );
        vaults[vault]->vaults[name]->expiry_time = time() + 3 * MONTH + tmp;
    }

    i = vault_sizes[size][VAULT_SIZE];

    if( i < vault_sizes[cur_size][VAULT_SIZE] ) {
        object cont, *inv, *failed;
        string dir;

        dir = query_vault_save_dir( vault );

        cont = make_container( name, cur_size );
        cont->set_save_file( dir + name, TP );

        if( cont->query_loc_weight() > i ) {
            object tmp_cont;

            tmp_cont = clone_object("/std/container");

            inv = sort_array( INV(cont), (: sort_by_weight :) );

            while( cont->query_loc_weight() > i && sizeof(inv) ) {
                inv[0]->move(tmp_cont);
                inv = inv[1..];
            }

            cont->set_max_weight( i );

            inv = filter( INV(tmp_cont), (: !$1->move($2) :), cont );

            cont->do_save();
            cont->dest_me();

            if( cont )
                destruct(cont);

            if( sizeof( inv = INV(tmp_cont) ) ) {
                if( sizeof( failed = filter( inv, (: $1->move(TP) :) ) ) ) {
                    failed->move( ENV(TP) );
                    inv -= failed;
                }
                if( sizeof(inv) )
                    ret = query_multiple_short(inv)+" did not fit into your "
                        "new vault and "+
                        ({"has", "have"})[query_group(inv)]+" been returned "
                        "to you";
                if( sizeof(failed) ) {
                    if( !ret )
                        ret = query_multiple_short(failed)+" did not fit "
                            "into your new vault and "+
                            ({"has", "have"})[query_group(failed)]+" been "
                            "placed on the floor because you are too "
                            "burdened to accept "+
                            ({"it", "them"})[query_group(failed)];
                    else
                        ret += ", while "+query_multiple_short(failed)+" "+
                            ({"has", "have"})[query_group(failed)]+" been "
                            "placed on the floor because you are too "
                            "burdened to accept "+
                            ({"it", "them"})[query_group(failed)];
                }
                tell_object( TP, ret+".\n");
            }

            tmp_cont->dest_me();
            if( tmp_cont )
                destruct(tmp_cont);
        }
    }

    tell_object( TP, ( !ret ? "Your" : "The rest of your")+" things have all "
        "been moved over to the new vault.\n");

    if( no_fee ) {
        vaults[vault]->vaults[name]->expiry_time = 0;
        prop->do_command("'Although the vault you are switching to doesn't "
            "have any upkeep costs, you must pay an entry fee of "+
            MS( visit_cost, place )+" each time you wish to visit the "
            "vault.");
    } else {
        tell_object( TP, "The rent for your vault has been paid until "+
            ctime( vaults[vault]->vaults[name]->expiry_time )+".\n");
        prop->do_command("'Please keep in mind that once your rent runs out, "
            "any items in the vault will be discarded, and you will lose the "
            "vault space.  For your convenience try to ensure adequate funds "
            "on your vault account at all times.");
    }

    vaults[vault]->vaults[name]->size = size;

    if( pointerp( warned[vault] ) )
        warned[vault] -= ({ name });

    save_me();

    log_file("VAULTS", "%s switched account in %s from %s to %s - %s\n",
        CAP(name), vault, cur_size, size, ctime(time()) );

    prop->do_command("'Thank you.");
    return 1;

} /* do_switch() */

/**
 * This method tells the player for how long they have payed their rent.
 * @param vault the vault name to get their rent for
 * @param prop the proprietor NPC to do the speaking
 * @return always returns 1
 */
int do_check_rent( string vault, object prop ) {
    string name;

    name = (string)TP->query_name();

    if( !query_account_in( vault, name ) ) {
        prop->do_command("'You have not rented any vault space here.");
        return 1;
    }

    if( !vaults[vault]->vaults[name]->expiry_time )
        prop->do_command("'Your vault space doesn't have any upkeep costs, "
            "however you have to pay separately for each visit.");
    else
        prop->do_command("'The rent for your vault has been paid until "+
            ctime( vaults[vault]->vaults[name]->expiry_time )+".");

    return 1;

} /* do_check_rent() */

/**
 * This method returns all vaults and their data.
 * @return all data for vaults
 */
mapping query_vaults() { return vaults; }

/**
 * This method returns the mapping of warned players.
 * @return all data for warned players
 */
mapping query_warned() { return warned; }

/** @ignore yes */
string query_name() { return "The Vault Handler"; }

/** @ignore yes */
mixed stats() {
    return ({
        ({"vaults", sizeof(vaults) }), }) + map( keys(vaults),
        (: ({ $1, sizeof( $2[$1]->vaults ) || "none" }) :), vaults );
} /* stats() */
