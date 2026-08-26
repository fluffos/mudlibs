/**
 * Standard vault inheritable object. There are two inheritables
 * (this one and /std/shops/vault_entry.c) which are provided to
 * make it easy to set up vaults.
 *
 * This one handles the actual vault room itself.
 * When using this room you must use set_vault_name() and
 * set_vault_entrance().  You should also define a setup_container()
 * function to customise your vault drawers.  Please note that
 * "$size$" in the container long description will be expanded
 * to the vault size, and the vault size will be added as an
 * adjective to the vault automatically, so try not to describe
 * their size too much.
 *
 * @author Ceres
 * @see /std/shops/vault_entrance.c
 * @see /handlers/vault_handler.c
 * @change Mostly rewritten by Sandoz, 2002.
 */

inherit ROOM_OBJ;

object container;
string vault_name, entry;

private void do_clean();

/** @ignore yes */
void create() {
    ::create();

    add_property("no_teleport", 1 );
    add_help_file("vault");

    if( clonep(TO) )
        call_out( function() { if( !vault_name ) do_clean(); }, 1 );

} /* create() */

/**
 * Used to set the exit from this vault room (usually out to the vault
 * entry room).  The parameters are just like those of add_exit,
 * except that you cannot use a 'door' or 'gate' type exits here.
 * @param direction the direction of the exit
 * @param dest the destination room
 * @param type the exit type as in add_exit
 * @see add_exit
 */
void set_vault_exit( string direc, mixed dest, string type ) {
    entry = dest;
    add_exit( direc, dest, type );
    modify_exit( direc, ({"function", "check_done"}) );
} /* set_vault_exit() */

/** @ignore yes */
string query_vault_name() { return vault_name; }

/** @ignore yes */
object query_vault_container() { return container; }

/** @ignore yes */
string query_owner() {
    if( container )
        return container->query_ownership();
    return 0;
} /* query_owner() */

/** @ignore yes */
void setup_vault( string vault, object thing ) {
    string name, size;
    object ob;

    if( !userp( thing ) || !vault )
        return;

    vault_name = vault;
    name = thing->query_name();

    if( container ) {
        if( (string)container->query_ownership() == name )
            return;
        else if( creatorp( thing ) && ( ob =
            find_player( container->query_ownership() ) ) && ENV(ob) == TO )
            return;
                  else {
            remove_hidden_object( container );
            container->dest_me();
            container = 0;
        }
    }

    size = VAULT_H->query_player_vault_size( vault_name, name );

    container = VAULT_H->make_container( name, size );

    container->set_save_file( VAULT_H->query_vault_save_dir(vault_name) +
        name, thing );

    container->set_ownership( name );
    container->set_size(size);

    add_hidden_object(container);

    TO->setup_container( container );

} /* set_player() */

/** @ignore yes */
int check_done( string verb, object thing, string special ) {
    if( thing->query_auto_loading() ) {
        tell_room( TO, "The door swings shut.\n");
        tell_object( thing, "Your inventory is still being generated.\n"
            "Please wait until it is completed.\n");
        return notify_fail("");
     }
     return 1;
} /* check_done() */

/** @ignore yes */
protected void do_clean() {
    if( container ) {
        remove_hidden_object( container );
        container->forced_save();
        container->dest_me();
    }

    entry->do_clean(TO);

} /* do_clean() */

/** @ignore yes */
void event_exit( object thing, string message, object to ) {
    if( userp(thing) && container &&
        container->query_ownership() == thing->query_name() ) {
        call_out( (: do_clean :), 1 );
    }

    ::event_exit( thing, message, to );

} /* event_exit() */

/** @ignore yes */
string query_quit_handler() { return entry; }

/**
 * Define this function in your vault room to perform setup on the vault
 * container. Use it to customise the name, short, long, size etc. of your
 * drawers (or whatever your vault uses).
 * @param container the object to perform your customisation on
 */
void setup_container( object container ) {
    container->set_name("safe");
    container->set_short("safe");
    container->set_long("This $size$ safe has been embedded into the wall "
        "with other similar safes.  There is no way anyone could move it "
        "from its current location.  The interior of the safe is totally "
        "black.\n");
} /* setup_container() */

/** @ignore yes */
mixed stats() {
    return ::stats() + ({
        ({"vault name", vault_name }),
        ({"entry", entry }),
        ({"container", container }),
        ({"owner", query_owner() }),
    });
} /* stats() */
