/**
 * A cheque inherit for use with banks.
 * @author Sandoz, 31st August 2001
 */

inherit OBJECT_OBJ;

private int amount, amount_set;
private string bank_name, place;

void create() {
    ::create();
    place = "default";
    set_name("bond");
    set_short("money bond");
    set_long("This is a blank money bond.\n");
    set_value(0);
    set_weight(0);
} /* create() */

/** @ignore yes */
string long( string words, int number ) {
    return replace( ::long( words, number ), ({ "$amount_string$",
                    MONEY_H->money_value_string( amount, place ),
                    "$bank_name$", bank_name }) );
} /* long() */

/**
 * This method queries the place associated with the cheque.
 * @return the place associated with the cheque
 */
string query_place() { return place; }

/**
 * This method sets the place associated with the cheque.
 * @param loc the place to associate the cheque with
 */
void set_place( string loc ) { place = loc; }

/**
 * This method queries the amount of money associated with the cheque.
 * @return the amount of money associated with the cheque
 */
int query_amount() { return amount; }

/**
 * This method sets the amount of money associated with the cheque.
 * @param number the amount of money to associate the cheque with
 * @return the newly set amount or 0 if the amount has already been set
 */
int set_amount( int number ) {
    if( amount_set )
        return 0;
    amount = ABS(number);
    return amount;
} /* set_amount() */

/**
 * This method queries the bank name associated with the cheque.
 * @return the bank name associated with the cheque
 */
string query_bank_name() { return bank_name; }

/**
 * This method sets the bank name associated with the cheque.
 * @param name the bank name
 */
void set_bank_name( string name ) { bank_name = name; }

/** @ignore yes */
mapping query_dynamic_auto_load() {
    if( !query_name() || query_name() == "object" )
        return 0;

    return ([ "::"         : ::query_dynamic_auto_load(),
              "amount set" : amount_set,
              "amount"     : amount,
              "bank name"  : bank_name,
              "place"      : place
              ]);

} /* query_dynamic_auto_load() */

/** @ignore yes */
void init_dynamic_arg( mapping map ) {
    if( map["::"] )
        ::init_dynamic_arg( map["::"] );
    if( map["amount set"] )
        amount_set = map["amount set"];
    if( map["amount"] )
        amount = map["amount"];
    if( map["bank name"] )
        bank_name = map["bank name"];
    if( map["place"] )
        place = map["place"];
} /* init_dynamic_arg() */

/** @ignore yes */
mapping int_query_static_auto_load() {
    return ([ "::" : ::int_query_static_auto_load() ]);
} /* int_query_static_auto_load() */

/** @ignore yes */
mapping query_static_auto_load() {
    if( !query_name() || query_name() == "object" )
        return 0;
    if( file_name( TO )[ 0 .. 15 ] == "/obj/misc/cheque" )
        return int_query_static_auto_load();
    return 0;
} /* query_static_auto_load() */

/** @ignore yes */
void init_static_arg( mapping map ) {
    if( !mappingp( map ) )
        return;
    if( map["::"] )
        ::init_static_arg( map["::"] );
} /* init_static_arg() */

/** @ignore yes */
mixed *stats() {
    return ::stats() + ({
      ({ "amount set", amount_set }),
      ({ "amount", amount }),
      ({ "bank name", bank_name }),
      ({ "place", place }) });
} /* stats() */