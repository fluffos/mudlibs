/**
 * This is the bank inheritable.  It handles all the bank transactions
 * and other such exciting stuff.
 * @author Pinkfish
 *
 * @changed Changed depositing to use indirect match and stopped
 * it runtiming parse_money with not-so-weird strings like "1 gold".
 * Also changed withdraw money, so it's now possible to withdraw
 * more then one type of coin at a time, without weird things happening.
 * - Sandoz, 05th July 2001.
 *
 * @changed Prevented dead people from being able to close accounts and
 * withdraw money - Sandoz, 10th July 2001.
 *
 * @changed Added cheques and a rewrote parts of it to stop a few rather
 * abusable bugs - Sandoz, 1st September 2001
 *
 * @changed Changed to work properly with multiple currency areas and
 * cleaned up considerably - Sandoz, 15th April 2003
 */

#include <money.h>

#define CHEQUE_OBJ "/obj/misc/cheque"

nosave inherit ROOM_OBJ;

int total_account, total_made;

nosave int account_cost,
           percentage,
           cheque_percentage,
           cheque_cost,
           min_cheque_value,
           use_cheques;

nosave string bank_name,
              place,
              cheque_long,
              cheque_short,
              save_file;

int do_withdraw( string money );
int do_deposit( object *things );
int do_cash( object *cheques );
int do_draw( mixed money, int account );
object make_cheque( int sum );

void create() {
    account_cost = 0;
    percentage = 10;
    cheque_percentage = 5;
    min_cheque_value = 2000;
    total_account = 0;
    total_made = 0;
    bank_name = "Bing's First";
    place = "default";
    add_help_file("bank");
    ::create();
} /* create() */

/** @ignore yes */
void init() {
    add_command("balance", "" );
    add_command("open", "account" );
    add_command("close", "account" );
    add_command("deposit", "<indirect:object:me'money'>",
              (: do_deposit( $1 ) :) );
    add_command("withdraw", "<string'money'>",
              (: do_withdraw( $4[0] ) :) );
    if( use_cheques ) {
        add_command("cash", "[in] <indirect:object:me'bond'>",
                  (: do_cash( $1 ) :) );
        add_command("draw", "bond from account [for] <string'money'>",
                  (: do_draw( $4[0], 1 ) :) );
        add_command("draw", "bond [for] <string'money'> from account",
                  (: do_draw( $4[0], 1 ) :) );
        add_command("draw", "bond [for] <indirect:object:me'money'>",
                  (: do_draw( $1, 0 ) :) );
        add_command("draw", "bond [for] <string'money'>",
                  (: do_draw( $4[0], 0 ) :) );
    }

    ::init();

} /* init() */

/**
 * This method returns the amount of money it costs to start an account
 * at this bank.
 * @return the account cost
 */
int query_account_cost() { return account_cost; }

/**
 * This method sets the amount of money that it costs to start an account
 * at this bank.
 * @param number the cost of starting an account
 */
void set_account_cost( int number ) { account_cost = number; }

/**
 * This method queries the percentage the bank charges on transactions.
 * @return the percentage the bank charges
 */
int query_percentage() { return percentage; }

/**
 * This method sets the percentage the bank charges on transactions.
 * @param number the percentage to charge
 */
void set_percentage( int number ) { percentage = number; }

/**
 * This method queries if the bank deals with cheques.
 * @return 1 if the bank is accepting/issuing cheques
 */
int query_use_cheques() { return use_cheques; }

/**
 * This method sets if the bank deals with cheques.
 * This has to be be set to 1 if the bank should accept
 * and issue cheques.
 * @param number 1 if the bank should accept/issue cheques, 0 if not
 */
void set_use_cheques( int number ) { use_cheques = number; }

/**
 * This method queries the cost of drawing cheques.
 * @return the cost of drawing cheques
 */
int query_cheque_cost() { return cheque_cost; }

/**
 * This method sets the cost of drawing cheques.
 * @param number the cost of drawing cheques
 */
void set_cheque_cost( int number ) { cheque_cost = number; }

/**
 * This method queries the percentage the bank charges on cheques.
 * @return the percentage the bank charges for drawing cheques
 */
int query_cheque_percentage() { return cheque_percentage; }

/**
 * This method sets the percentage the bank charges on cheques.
 * @param number the percentage to charge for drawing cheques
 */
void set_cheque_percentage( int number ) { cheque_percentage = number; }

/**
 * This method queries the minimum value of cheques given out.
 * @return the minimum value of cheques given out
 */
int query_min_cheque_value() { return min_cheque_value; }

/**
 * This method sets the minimum value of cheques issued by the bank.
 * @param number the minimum value of cheques issued in the bank
 */
void set_min_cheque_value( int number ) { min_cheque_value = number; }

/**
 * This method queries the short description to be given to cheques
 * issued by the bank.
 * @return the short description of cheques issued by the bank
 */
string query_cheque_short() { return cheque_short; }

/**
 * This method sets the short description to be given to
 * cheques issued by the bank.
 * @param str the short description to use
 */
void set_cheque_short( string str ) { cheque_short = str; }

/**
 * This method queries the long description to be given to cheques
 * issued by the bank.
 * @return the long description of cheques issued by the bank
 */
string query_cheque_long() { return cheque_long; }

/**
 * This method sets the long description to be given to
 * cheques issued by the bank.
 * @param str the long description to use
 */
void set_cheque_long( string str ) { cheque_long = str; }

/**
 * This method returns the total value of all the accounts.
 * @return the totaly value of all the accounts
 */
int query_total_account() { return total_account; }

/**
 * This method returns the amount of money the bank has made off the
 * players.
 * @return the amount of money made
 */
int query_total_made() { return total_made; }

/**
 * This method returns the name of the bank.
 * @return the name of the bank
 */
string query_bank_name() { return bank_name; }

/**
 * This method sets the name of the bank.
 * @param word the name of the bank
 */
void set_bank_name( string word ) { bank_name = word; }

/**
 * This method returns the place this bank operates in.
 * @return the place the bank operates in
 */
string query_place() { return place; }

/**
 * This method sets the place the bank operates in.
 * @param word the place the bank operates in
 */
void set_place( string word ) { place = word; }

/**
 * This method returns the save file of the bank.
 * @return the save file
 */
string query_save_file() { return save_file; }

/**
 * This method sets the save file for the bank.
 * @param word the save file to set to
 */
void set_save_file( string word ) {
    save_file = word;
    if( file_size( save_file +".o" ) > 0 )
        unguarded( (: restore_object, save_file :) );
} /* set_save_file() */

/** @ignore yes */
void do_save() {
    if( save_file )
        unguarded( (: save_object, save_file :) );
    TP->save();
} /* do_save() */

/** @ignore yes */
int get_account( object player ) {
    return BANK_H->query_account( TP->NAME, bank_name );
} /* get_account() */

/** @ignore yes */
int set_account( object player, int amount ) {
    BANK_H->set_account( TP->NAME, bank_name, amount );
} /* set_account() */

/** @ignore yes */
int adjust_account( object player, int amount ) {
    BANK_H->adjust_account( TP->NAME, bank_name, amount );
} /* set_account() */

/** @ignore yes */
int do_balance() {
    int amount;

    if( TP->query_property("dead") ) {
        add_failed_mess("Try as you might, you fail to draw the attention "
            "of the clerks.\n");
        return 0;
    }

    if( ( amount = get_account(TP) ) < 0 ) {
        add_failed_mess("You do not have an account here.\n");
        return 0;
    }

    if( !amount ) {
        add_succeeded_mess( ({"Your account is empty.\n",
            "$N checks the balance of $p account.\n"}) );
        return 1;
    }

    add_succeeded_mess( ({"You have "+
        MONEY_H->money_value_string( amount, place )+" in your account.\n",
        "$N check$s the balance of $p account.\n"}) );
    return 1;

} /* do_balance() */

/** @ignore yes */
int do_withdraw( string money ) {
    int amount, total, flag;
    object ob;
    mixed arr;

    if( TP->query_property("dead") ) {
        add_failed_mess("Try as you might, you fail to draw the attention "
            "of the clerks.\n");
        return 0;
    }

    if( ( total = get_account(TP) ) < 0 ) {
        add_failed_mess("You do not have an account here.\n");
        return 0;
    }

    if( !money ) {
        add_failed_mess("You must $V something.\n");
        return 0;
    }

    // Let's not accept a partial match.
    arr = MONEY_H->money_array_from_string( money, place, 1 );

    if( !sizeof( arr ) ) {
        add_failed_mess("Some or all of "+money+" is not legal tender here.  "
            "Please see \"help here\" for the correct input patterns.\n");
        return 0;
    }

    if( !amount = MONEY_H->query_total_value( arr, place ) ) {
        add_failed_mess("The amount of money you have chosen to withdraw has "
            "no value.\n");
        return 0;
    }


    if( amount > total || amount < 0 ) {
        add_failed_mess("You don't have enough money in your account.\n");
        return 0;
    }

    ob = clone_object(MONEY_OBJ);
    ob->set_money_array(arr);

    if( flag = ob->move(TP) )
        ob->move(TO);

    adjust_account( TP, -amount );
    total_account -= amount;
    do_save();

    add_succeeded_mess( ({"You $V "+query_multiple_short(
        ob->half_short(1) )+" from your account.\n"+( flag ?
        "Unfortunately you are too burdened to accept the money, "
        "so it is put on the counter for you.\n" : "")+
        "You have "+MONEY_H->money_value_string( get_account(TP),
        place )+" in your account after the withdrawal.\n",
        "$N $V some money from $p account.\n"}) );

    return 1;

} /* do_withdraw() */

/** @ignore yes */
int do_deposit( object *things ) {
    int amount, total, fee;
    object *tender, legal, illegal, cont;

    if( TP->query_property("dead") ) {
        add_failed_mess("Try as you might, you fail to draw the attention "
            "of the clerks.\n");
        return 0;
    }

    // Make sure it is all money we're depositing.
    if( sizeof( filter( things, (: !$1->query_property( "money" ) :) ) ) ) {
        add_failed_mess("You can only $V money.\n");
        return 0;
    }

    if( ( total = get_account(TP) ) < 0 ) {
        add_failed_mess("You don't have an account here.\n");
        return 0;
    }

    cont = clone_object("/std/container");
    things->move( cont );
    things = INV( cont );

    if( !sizeof( things ) ) {
        cont->dest_me();
        add_failed_mess("Something is broken, please contact a creator.\n");
        return 0;
    }

    // Figure out the legal tender.
    tender = MONEY_H->filter_legal_tender( things[ 0 ], place );
    legal = tender[ 0 ];
    illegal = tender[ 1 ];
    cont->dest_me();

    // Give them back their illegal money.
    if( illegal )
        illegal->move( TP );

    if( legal ) {
        amount = legal->query_value_in(place);

        if( place != "default")
            amount += legal->query_value_in("default");

        // min. amount to prevent depositing 1c 1000 times to avoid charges.
        if( amount < 200 ) {
            legal->move(TP);
            add_failed_mess("That is too small an amount to $V.\n");
            return 0;
        }

        fee = ( amount * percentage ) / 100;
        total_made += fee;
        amount = amount - fee;
        adjust_account( TP, amount );
        total_account += amount;

        do_save();

        add_succeeded_mess( ({ "$N $V "+MONEY_H->money_string(
            legal->query_money_array() )+".\nAfter expenses, this leaves "+
            MONEY_H->money_value_string( amount, place )+".\nThis "
            "gives a total of "+MONEY_H->money_value_string( total + amount,
            place )+" in your account.\n",
            "$N $V some money into $p account.\n" }) );
        legal->move("/room/rubbish");
    } else {
        add_failed_mess("Sorry, you cannot $V "+MONEY_H->money_string(
            illegal->query_money_array() )+", because it is not legal tender "
            "here.\n");
        return 0;
    }

    return 1;

} /* do_deposit() */

/** @ignore yes */
int do_open() {
    int amount;
    object money;

    if( TP->query_property("dead") ) {
        add_failed_mess("Try as you might, you fail to draw the attention "
            "of the clerks.\n");
        return 0;
    }

    if( get_account(TP) >= 0 ) {
        add_failed_mess("You already have an account here.\n");
        return 0;
    }

    if( account_cost ) {
        if( !( money = present( MONEY_ALIAS, TP ) ) ) {
            add_failed_mess("You do not have any money.\n");
            return 0;
        }
        amount = money->query_value_in( place );
        if( place != "default")
            amount += money->query_value_in("default");
        if( amount < account_cost ) {
            add_failed_mess("You do not have enough money to open an "
                "account here.\n");
            return 0;
        }

        write("It will cost you "+ (string)MONEY_H->money_value_string(
              account_cost, place ) +" to open the account.\n"
              "Do you still wish to open an account here?");

        input_to("check_open");
        return 1;
    }

    set_account( TP, 0 );
    add_succeeded_mess("$N $V an account.\n");
    return 1;

} /* do_open() */

/** @ignore yes */
int check_open( string word ) {
    object money, change;
    int amount;

    word = lower_case( word );

    if( word == "n" || word == "no") {
        write("Okay, not opening an account.\n");
        return 1;
    }

    if( word != "y" && word != "yes") {
        write("Do you want to open an account? Answer \"yes\" or \"no\".\n");
        input_to("check_open");
    }

    if( !( money = present( MONEY_ALIAS, TP ) ) ) {
        write("What did you do with your money?\n");
        return 0;
    }

    if( get_account(TP) >= 0 ) {
        add_failed_mess("You already have an account here.\n");
        return 0;
    }

    amount = money->query_value_in( place );

    if( place != "default")
        amount += money->query_value_in("default");

    if( amount < account_cost ) {
        write("You do not have enough money to open an account here.\n");
        return 0;
    }

    if( change = MONEY_H->pay_amount_from( account_cost, money, place ) )
        change->move(TP);

    set_account( TP, 0 );
    total_made += account_cost;

    do_save();

    tell_object( TP, "You now have an account here.\n");
    tell_room( TO, TP->the_short()+" opens an account.\n", TP );
    return 1;

} /* check_open() */

/** @ignore yes */
int do_close() {
    int total;
    object money;
    string ret;

    if( TP->query_property("dead") ) {
        add_failed_mess("Try as you might, you fail to draw the attention "
            "of the clerks.\n");
        return 0;
    }

    if( ( total = get_account(TP) ) < 0 ) {
        add_failed_mess("You don't even have an account here.\n");
        return 0;
    }

    ret = "";

    if( total ) {
        if( money = MONEY_H->make_new_amount( total, place ) ) {
            ret += "You receive "+MONEY_H->money_value_string(
                money->query_value_in(place), place )+" upon closing your "
                "account.\n";
            if( money->move(TP) ) {
                ret += "You are too heavily burdened to accept all that "
                    "money, so the clerk puts it on the counter for you.";
                money->move(TO);
            }
        } else {
            ret = "The amount of money in your account was not even "
                  "worth a coin of the lowest denomination in the local "
                  "currency.  Sorry.\nYour account is now closed.\n";
            total_made += total;
        }
        total_account -= total;
    } else
        ret += "You close your account.\n";

    add_succeeded_mess( ({ ret, "$N $V $p account.\n"}) );
    set_account( TP, -1 );

    do_save();

    return 1;

} /* do_close() */

/** @ignore yes */
int do_cash( object *cheques ) {
    object money;
    int amount;

    if( TP->query_property("dead") ) {
        add_failed_mess("Try as you might, you fail to draw the attention "
            "of the clerks.\n");
        return 0;
    }

    // Weed out the cheques that are not applicable here.
    cheques = filter( cheques, (: lower_case( $1->query_bank_name() ) == $2 :),
        lower_case(bank_name) );

    if( !sizeof(cheques) ) {
        add_failed_mess("You can only $V in money bonds drawn from "+
            bank_name+" here.\n" );
        return 0;
    }

    foreach( object cheque in cheques )
        amount += cheque->query_amount();

    if( amount < 1 ) {
        add_failed_mess("$I appear"+( sizeof(cheques) > 1 ? "" : "s" )+" to "
            "be worthless.\n", cheques );
        return 0;
    }

    cheques->move("/room/rubbish");

    if( !money = MONEY_H->make_new_amount( amount, place ) ) {
        // Give back their cheques.
        cheques->move(TP);
        add_failed_mess("Something has gone terribly wrong, please contact "
            "a creator immediately, or file a bug report.\n");
        return 0;
    }

    if( money->move(TP) ) {
        money->move(TO);
        add_succeeded_mess( ({"You $V in $I for "+
            MONEY_H->money_value_string( amount, place )+", however you "
            "are too burdened to accept all that money, so the clerk puts "
            "it in the counter for you.\n", "$N $V in $I.\n" }), cheques );
    }

    add_succeeded_mess( ({"You $V in $I for "+
        MONEY_H->money_value_string( amount, place )+".\n",
        "$N $V in $I.\n" }), cheques );
    return 1;

} /* do_cash() */

/** @ignore yes */
string zap_fee( object player, int fee ) {
    object change, money;
    int amount;
    string ret;

    ret = "You don't have enough money to pay the fees to $V "
          "a money bond.\n";

    if( !money = present( MONEY_ALIAS, player ) )
        return ret;

    amount = money->query_value_in( place );

    if( place != "default" )
        amount += (int)money->query_value_in( "default" );

    if( amount < fee )
        return ret;

    if( change = MONEY_H->pay_amount_from( fee, money, place ) )
        change->move(TP);

    return 0;

} /* zap_fee() */

/** @ignore yes */
int do_draw( mixed money, int account ) {
    object *tender, legal, illegal, cont, cheque;
    int amount, total, fee, flag;
    string fail;
    mixed arr;

    if( TP->query_property("dead") ) {
        add_failed_mess("Try as you might, you fail to draw the attention "
            "of the clerks.\n");
        return 0;
    }

    if( !money ) {
        add_failed_mess("You must $V something.\n");
        return 0;
    }

    if( stringp(money) && !account ) {
        add_failed_mess("You don't have "+money+".\n");
        return 0;
    }

    fee = cheque_cost;

    if( stringp(money) ) {
        if( ( total = get_account(TP) ) < 0 ) {
            add_failed_mess("You do not have an account here.\n");
            return 0;
        }

        // Let's not accept a partial match.
        arr = MONEY_H->money_array_from_string( money, place, 1 );

        if( !sizeof( arr ) ) {
            add_failed_mess("Some or all of "+money+" is not legal tender "
                "here.  Please see \"help here\" for the correct input "
                "patterns.\n");
            return 0;
        }

        if( !amount = MONEY_H->query_total_value( arr, place ) ) {
            add_failed_mess("The amount of money you have chosen to draw a "
                "money bond for has no value.\n");
            return 0;
        }


        if( amount > total || amount < 0 ) {
            add_failed_mess("You don't have enough money in your account.\n");
            return 0;
        }

        // Minimum cheque value.
        if( amount < min_cheque_value ) {
            add_failed_mess("The minimum amount of money you can $V "
                "a money bond for is "+MONEY_H->money_value_string(
                min_cheque_value, place )+".\n");
            return 0;
        }

        // Not enough coin on the account.
        if( amount > total || amount < 0 ) {
            add_failed_mess("You don't have enough money in your account.\n");
            return 0;
        }

        fee += ( amount * cheque_percentage ) / 100;
        if( ( amount + fee ) < total ) {
            adjust_account( TP, -( amount + fee ) );
            total_account -= amount + fee;
        } else {
            if( fail = zap_fee( TP, fee ) ) {
                add_failed_mess(fail);
                return 0;
            }
        }
    } else {
        if( pointerp(money) ) {
            // Make sure it's all money we're depositing.
            if( sizeof( filter( money,
                (: !$1->query_property("money") :) ) ) ) {
                add_failed_mess("You can only $V money bonds directly "
                    "from your account, or for money.\n");
                return 0;
            }

            cont = clone_object("/std/container");
            money->move(cont);
            money = INV(cont);

            if( !sizeof(money) ) {
                cont->dest_me();
                add_failed_mess("Something is broken, please contact a "
                    "creator.\n");
                return 0;
            }

            // Figure out the legal tender.
            tender = MONEY_H->filter_legal_tender( money[ 0 ], place );
            legal = tender[ 0 ];
            illegal = tender[ 1 ];
            cont->dest_me();

            // Give them back their illegal money.
            if( illegal )
                illegal->move(TP);

            if( legal ) {
                amount = legal->query_value_in(place);

                if( place != "default" )
                    amount += legal->query_value_in("default");

                // Minimum cheque value.
                if( amount < min_cheque_value ) {
                    legal->move(TP);
                    add_failed_mess("The minimum amount of money you can $V "
                        "a money bond for is "+MONEY_H->money_value_string(
                        min_cheque_value, place )+".\n");
                    return 0;
                }

                fee += ( amount * cheque_percentage ) / 100;
                if( fail = zap_fee( TP, fee ) ) {
                    legal->move(TP);
                    add_failed_mess(fail);
                    return 0;
                }
            } else {
                add_failed_mess("Unable to find any legal money to $V a "
                    "cheque for, sorry.\n");
                return 0;
            }

            legal->move("/room/rubbish");

        } else {
            add_failed_mess("Something has gone terribly wrong, please "
                "contact a creator immediately or file a bug report.\n");
            return 0;
        }
    }

    // Bugger! need to give back money now.
    if( !cheque = make_cheque( amount ) ) {
        if( account ) {
            adjust_account( TP, amount + fee );
            total_account += amount + fee;
        } else {
            MONEY_H->make_new_amount( amount + fee, place )->move(TP);
        }

        log_file("BAD_CHEQUES", "%s - %s failed to draw a money bond for %i "
            "in %s\n", ctime(time()), TP->query_cap_name(), amount,
            base_name(TO) );

        add_failed_mess("Something has gone wrong, please contact "
            "a creator immediately or file a bug report.\n");
        return 0;
    }

    total_made += fee;

    if( flag = cheque->move(TP) )
        cheque->move(TO);

    do_save();

    if( account ) {
        add_succeeded_mess( ({"You $V a money bond for "+
            MONEY_H->money_value_string( amount, place )+" from your "
            "account, paying "+MONEY_H->money_value_string( fee,
            place )+" of fees.\n"+( flag ?
            "Unfortunately you are too burdened to accept the money bond, "
            "so it is put on the counter for you.\n" : "")+
            "This leaves "+MONEY_H->money_value_string( get_account(TP),
            place )+" in your account.\n",
            "$N $V a money bond from his account.\n"}) );
    } else {
        add_succeeded_mess( ({
            "You hand "+MONEY_H->money_string(
            legal->query_money_array() )+" to a clerk and receive a "
            "money bond for "+MONEY_H->money_value_string( amount,
            place )+", paying "+MONEY_H->money_value_string( fee,
            place )+" of fees.\n"+( flag ?
            "Unfortunately you are too burdened to accept the money bond, "
            "so it is put on the counter for you.\n" : ""),
            "$N hand$s some money to a clerk and receive$s a money bond "
            "in return.\n"}) );
    }

    return 1;

} /* do_draw() */

/** @ignore yes */
object make_cheque( int sum ) {
    object cheque;

    if( !cheque = clone_object(CHEQUE_OBJ) )
        return 0;

    cheque->set_place( place );
    cheque->set_bank_name( bank_name );
    cheque->set_amount( sum );

    if( cheque_short )
        cheque->set_short( cheque_short );
    if( cheque_long )
        cheque->set_long( cheque_long );
    else
        cheque->set_long("This bond has been issued by $bank_name$ and "
                "appears to be for $amount_string$.  Please go to the "
                "nearest subbranch of the bank to cash it in.\n");

    return cheque;

} /* make_cheque() */

/** @ignore yes */
mixed stats() {
    return ::stats() + ({
      ({"account cost", account_cost }),
      ({"percentage", percentage }),
      ({"cheque cost", cheque_cost }),
      ({"cheque percentage", cheque_percentage }),
      ({"minimum cheque value", min_cheque_value }),
      ({"total accounts", total_account }),
      ({"total made", total_made }),
      ({"bank name", bank_name }),
      ({"place", place }),
      ({"save file", save_file }) });
} /* stats() */
