/**
 * This file contains all the data needed for handling money.  This
 * includes the money handler and the money object itself.
 * @author Pinkfish
 */
#ifndef __SYS__MONEY
/** @ignore yes */
#define __SYS__MONEY

#ifdef __MONEY_CLASS__
/**
 * This class stores the attributes of a coin.
 * @member head_short the short description of the front side of the coin
 * @member tail_short the short description of the back side of the coin
 * @member head_long the long description of the front side of the coin
 * @member tail_long the long description of the back side of the coin
 * @member material the material the coins has been made from
 * @member plural the plural of the coin, this should be one word only
 * @member adj words used to describe the coin(s), ie. "thin and scratched"
 * @member weight the weight of 100 coins of the type
 */
class money_data {
    string head_short;
    string tail_short;
    string head_long;
    string tail_long;
    string material;
    string plural;
    string adj;
    int weight;
}
#endif

/**
 * The object to use for money.
 */
#define MONEY_OBJECT "/obj/money"
/**
 * The money handler object, used for routines and opetations on money.
 */
#define MONEY_HAND "/handlers/money_handler"
/**
 * The money alias, this is used by the money object to identify
 * itself.  The reason it has spaces in it is so that it is not
 * matched by find_match(), only by present().
 * @example
 * // Find the players money object.
 * money = present(MONEY_ALIAS, player);
 */
#define MONEY_ALIAS "Some Money For Me"

#define NO_MATCH -1
#define NO_MONEY -2
#define NO_LEGAL -3

/**
 * The index into the array returned by the make_payment functions for
 * the change.
 */
#define MONEY_PAY_CHANGE 1
/**
 * The index into the array returned by the make_payment functions for
 * the return array.  This is the actual value to fiddle with.
 */
#define MONEY_PAY_RETURN 0
/**
 * The index into the array returned by make_payment functions for the
 * the depleted money array.
 */
#define MONEY_PAY_DEPLETED 2

#endif /* __SYS__MONEY */
