/*
 *
 * Unique Handler - For handling Unique Items and Weapons.
 * @author Shaydz
 * Started: 31/07/2004
 *
 */

#define SAVE_FILE SAVE_DIR HANDLER_DIR "unique"

mapping uniques;

void create() {
   seteuid( (string)"/secure/master"->
         creator_file( file_name( this_object() ) ) );
   uniques = ([ ]);
   if ( file_size( SAVE_FILE +".o" ) > 0 )
      unguarded( (: restore_object, SAVE_FILE :) );
} /* create() */

/**
 * This method returns the uniques mapping.
 * @return the uniques mapping
 */
mapping query_uniques() { return uniques; }

/**
 * This method returns the data on the specified unique mapping.
 * @return the data on the spcified unique item
 */
string *query_unique(string item){

    if(!item || item == "")
        return 0;

    if(member_array(item,keys(uniques)) == -1)
        return 0;

    return uniques[item];
} /* query_uniques() */

/** Saves the current state to disk. */
void save_me() { unguarded( (: save_object, SAVE_FILE :) ); }

/** @ignore yes */
void dest_me() {
    save_me();
    destruct(TO);
} /* dest_me() */
