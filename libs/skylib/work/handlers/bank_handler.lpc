/**
 * Keep track of each banks data.
 * @change 12-11-97 Pinkfish
 * Removed the player_name variable.  Made a couple of the functions
 * private
 *
 * @change 21-11-97 Terano
 * Changed the get_data_file function so that if there is no data file
 * for a player, it calls init_data().
 */


#define RESTORE_PATH "/save/bank_accounts/"

private mapping accounts;

private void create() {
    seteuid( master()->creator_file( file_name(TO) ) );
} /* create() */

private void init_data( string word ) {
    accounts = ([ ]);
} /* init_data() */

/**
 * Start up the system by restoring the players data.
 * @param word the name of the player being restored
 */
int get_data_file( string name ) {
    if( !unguarded( (: restore_object,
        RESTORE_PATH+name[0..0]+"/"+name :) ) ) {
        init_data(name);
        return 0;
    }

    return 1;

} /* get_data_file() */

/**
 * Save the current data file to disk.
 * @param word the name of the player being saved
 */
private void save_data_file( string name ) {
    unguarded( (: save_object, RESTORE_PATH+name[0..0]+"/"+name :) );
} /* save_data_file() */

/**
 * Find out how much a player has at a given bank.
 * @param name the name of the player
 * @param bank_name the name of the bank
 * @return the current balance, -1 on failure
 */
int query_account( string name, string bank_name ) {
    get_data_file( name );

    if( !accounts )
        return -1;

    if( undefinedp( accounts[ bank_name ] ) == 1 )
        return -1;

    return accounts[ bank_name ];

} /* query_account() */

/**
 * Change the amount of money a player has at a given bank.
 * @param word the name of the player
 * @param bank_name the name of the bank
 * @param amount the amount to change the balance by
 */
void adjust_account( string word, string bank_name, int amount ) {
    get_data_file( word );

    accounts[ bank_name ] += amount;

    if( accounts[ bank_name ] < 0 )
        map_delete( accounts, bank_name );

    save_data_file( word );

} /* adjust_account() */

/**
 * Sets the balance at a certain bank to the specificed amount.
 * @param word the name of the player
 * @param bank_name the name of the bank
 * @param amount the amount to set the bank to.
 */
void set_account( string word, string bank_name, int amount ) {
    get_data_file( word );

    if( amount < 0 )
        map_delete( accounts, bank_name );
    else
        accounts[ bank_name ] = amount;

    save_data_file( word );

} /* set_account() */

/** @ignore yes */
mapping query_accounts() { return copy(accounts); }
