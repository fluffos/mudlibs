/**
 * This is a inheritable that provides an efficient way of storing
 * lots of items. Only one copy of the item is effectively in storage
 * and everytime one is removed, an exact copy is duplicated and
 * put back in the store. Objects are added to the store via
 * add_object(). The actual storage container object
 * can be returned by query_cont() and this container should be
 * searched when you want to find what objects the store contains.
 * Any object can inherit this, and methods
 * should be put in place in the inheriting file that end up calling
 * create_real_object() which will sort out duplicating the item
 * and returning an object pointer to the one you can deal with.
 * @example
 * inherit "clone_on_demand";
 * int do_buy( objects *obs );
 *
 * void setup(){
 *   set_name("shop");
 *   set_short("widget shop");
 *   add_object( "sprocket" );
 * }
 *
 * object create_object( string arg ){
 *   if( arg == "sprocket" )
 *     return clone_object("/path/of/sprocket");
 * }
 *
 * void init(){
 *   add_command("buy", "<indirect:object:"+file_name( query_cont() )+">");
 * }
 *
 * int do_buy( object *obs ){
 *   object ob;
 *   foreach(ob in obs){
 *     widget = create_real_object(ob);
 *     widget->move( TP );
 *   }
 *   add_succeeded_mess("$N buy$s $I.\n", obs );
 *   return 1;
 * }
 *
 * @author Pinkfish Aquilo
 * @see add_object
 * @changed Changed to use a permanent temporary container so that we
 * wouldn't have to clone/dest a temporary container each time a real
 * object is created.  We also don't have to move each object twice in
 * create_real_object() anymore.
 * - Sandoz, 2002.
 * @changed Changed to keep the stock in the original container at all
 * times, because that is where add_commands are pointing to.
 * - Sandoz, Dec. 2003.
 */

#include <armoury.h>

#define INFINITE_LEFT 10000
#define MAX_PROP "max per reset"
#define NUM_REMOVED "number removed this reset"
#define REFERENCE "name we are reference by"
#define DISPLAY "display in shop"

nosave object _cont, _tmp_cont;

/**
 * This method returns the container which is used to keep one copy of
 * each items in storage.
 * @return the object container
 */
object query_cont() { return _cont; }

private object make_shop_container() {
    object ob;

    ob = clone_object("/std/container");
    ob->set_name("clone_on_demand-store");
    ob->add_property("parent", file_name(TO) );

    return ob;

} /* make_shop_container() */

/** @ignore yes */
void reset() {
    object ob;

    if( !_cont )
        _cont = make_shop_container();

    foreach( ob in INV(_cont) )
        ob->remove_property( NUM_REMOVED );

} /* reset() */

/**
 * This method is used to add an item to the storage.
 * When this method is called, create_object() is called
 * (with the object name as an arg) in the inheriting file.
 * If no object is returned by that function,
 * the name is cloned with clone_object(), and failing that
 * request_item() is called in the armoury against the name.
 *
 * This method makes add_weapon() and add_armour() obsolete.
 *
 * @example
 * add_object( "frog", 1 + random( 3 ) );
 * // This will try and create an object called frog, in the order mentioned
 * // above
 * @example
 * add_object( "/obj/food/apple.food", 0 );
 * // Add unlimited numbers of apples.
 * @param name the name of the object to add.
 * @param max_per_reset the maximum number of items to be available at any one time
 * @param display_as the name that this item is displayed as in shops
 * @return 1 if the item was added successfully to the store, 0 if it was not.
 */
varargs int add_object( string name, int max_per_reset, string display_as ) {
    object ob;

    if( !_cont )
         _cont = make_shop_container();

    if( !( ob = TO->create_object(name) ) &&
        !( ob = ARMOURY_H->request_item( name, 100 ) ) )
        ob = clone_object(name);

    if( ob ) {
        if( ob->query_decays() ) {
            // Stop decaying objects decaying in inventories.
            ob->set_decay_speed(0);
        }

        ob->move(_cont);

        if( display_as )
            ob->add_property( DISPLAY, display_as );

        ob->add_property( REFERENCE, name );
        ob->add_property( MAX_PROP, max_per_reset );
        return 1;
    }

    return 0;

} /* add_object() */

/**
 * Returns how more times object ob can be duplicated
 * @param ob the object to test
 * @return how many more times
 */
int query_num_items_left( object ob ) {
    int max, num;

    max = ob->query_property( MAX_PROP );
    num = ob->query_property( NUM_REMOVED );

    if( max )
        return max - num;

    if( max == -1 )
        return INFINITE_LEFT;

    return 0;

} /* query_num_items_left() */

/**
 * This function returns the quantity of particular object available
 * to be cloned on demand. In matching which object is the one in
 * question it uses the short name of the object, which is passed as
 * an argument to the function.
 * @param name is the short name of the object you wish to query.
 * @return the number left, returns INFINITE_LEFT if the shop has an infinite
 * number, returns -1 if the item isn't stocked.
 */
int query_number_left( string name ) {
    object  thing;

    thing = filter( INV(_cont), (: $1->query_short() == $(name) :) )[0];

    if( !thing )
        return -1; // We don't have that item.

    return query_num_items_left( thing );

} /* query_number_left() */

/**
 * This function can be used to check the quantity left of an array
 * of items.  It returns a parallel array of integers.  In other words
 * the array it returns contains the numbers of stock in array positions
 * corresponding to the array positions of the objects it was passed.
 * @example
 * query_items_left( ({ "banana" , "melon" }) )
 * would return ({ 12 , 6 }) if there were 12 bananas and 6 melons left.
 * @param names an array of the short names of the items you wish to query
 * @return an array of integers, each one returning like query_number_left
 * would for the object in that position of the object array.
 * @see query_number_left
 */
int *query_items_left( string *names ) {
    int sz, *numbers;

    // Empty arrays not allowed.
    if( ( sz = sizeof( names ) ) < 1 )
        return  ({ });

    numbers = allocate( sz );

    while( sz-- )
        numbers[sz] = query_number_left( names[sz] );

    return numbers;

} /* query_items_left() */

/**
 * This function transfers certain tracking properties from the
 * original item to the new item which replaces it in storage. To
 * transfer any additional properties, have switch_extra_properties()
 * defined in your inheriting object and return an array of extra
 * properties to transfer
 */
private void switch_properties( object newone, object original ) {
    mixed extra, *props, prop;

    props = ({ MAX_PROP, NUM_REMOVED, REFERENCE });

    if( sizeof( extra = TO->switch_extra_properties() ) )
        props += extra;

    foreach( prop in props ){
        newone->add_property( prop, original->query_property( prop ) );
        original->remove_property( prop );
    }

    if( newone->query_decay_speed() ) {
        original->set_decay_speed( newone->query_decay_speed() );
        // Stop decaying objects decaying in inventories.
        newone->set_decay_speed(0);
    }

} /* switch_properties() */

/**
 * The main point of entry. 'thing' should be an object already placed
 * in the clone_on_demand store container via 'add_object'. This
 * method then duplicates that object, replaces the original copy in
 * the container with this new one, and returns the original which can
 * be delt with as normal.
 * @param thing an object in the store
 * @return the original object
 * @see add_object
 */
protected object create_real_object( object thing ) {
    string name;
    object new_thing;

    name = thing->query_property( REFERENCE );

    if( !( new_thing = TO->create_object( name ) ) &&
        !( new_thing = ARMOURY_H->request_item( name, 80 + random( 20 ) ) ) )
        new_thing = clone_object(name);

    if( new_thing ) {
        int i, max, num;
        object *inv;

        switch_properties( new_thing, thing );

        // Restore contents' order.
        inv = INV(_cont);
        i = member_array( thing, inv );
        inv[i] = new_thing;
        i = sizeof(inv);

        thing->move("/room/void");

        if( !_tmp_cont )
            _tmp_cont = make_shop_container();

        while( i-- )
            inv[i]->move(_tmp_cont);

        inv = INV(_tmp_cont);
        i = sizeof(inv);

        // Now move them back to the original container.
        // The things need to be in the original container,
        // because that is where all the add commands are looking in.
        // - Sandoz.
        while( i-- )
            inv[i]->move(_cont);

        // Decrement store if applicable.
        num = new_thing->query_property( NUM_REMOVED );
        if( max = new_thing->query_property( MAX_PROP ) )
            new_thing->add_property( NUM_REMOVED, num + 1 );
    }

    return thing;

} /* create_real_object() */

/** @ignore yes */
void dest_me() {
    // Let's recycle too - Sandoz.
    if( _cont ) {
        INV(_cont)->move("/room/rubbish");
        _cont->dest_me();
    }

    // _tmp_cont should always be empty.
    if( _tmp_cont )
        _tmp_cont->dest_me();

} /* dest_me() */

/** @ignore yes */
mixed stats() {
    return ({
        ({"container", _cont }),
        ({"temporary container", _tmp_cont }),
    });
} /* stats() */
