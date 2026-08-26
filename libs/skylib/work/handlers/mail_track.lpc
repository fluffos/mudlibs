/**
 * This handler keeps track of who has a mailer at the moment and sends the
 * mail to there instead.  This also keeps track of the current mailing
 * lists in the system.
 * @author Pinkfish
 * @started 1991 sometime
 * @index mailing_list
 * @changed
 */

#include <mail.h>
#include <mail_track.h>

#define MAILTOOL "/secure/cmds/creator/mailtool"

nosave mapping our_mailers;
mapping mailing_lists;

private void save_me() {
   unguarded( (: save_object, "/save/mail_track" :) );
} /* save_me() */

/** @ignore yes */
void create() {
    int i;
    string list, member;

    seteuid("Root");

    unguarded( (: restore_object, "/save/mail_track" :) );

    if( !mapp(mailing_lists) ) {
        mailing_lists = ([ ]);
    } else {
        foreach( list in keys(mailing_lists) ) {
            foreach( member in mailing_lists[list]->members ) {
                if( !PLAYER_H->test_user( member ) ) {
                    mailing_lists[list]->members -= ({ member });
                    i = 1;
                }
            }
            if( !sizeof( mailing_lists[list]->members ) )
                map_delete( mailing_lists, list );
        }
        if( i )
            save_me();
    }

    our_mailers = ([ ]);

} /* create() */

/**
 * This method adds in a mailer for a specific player into the current
 * list of mailers.
 * @param ob the mailer for the player
 * @param str the player the mailer is for
 * @return return 1 if successful
 */
int add_mailer( object ob, string str ) {
    if( !stringp(str) || !objectp(ob) )
        return 0;

    if( our_mailers[str] && our_mailers[str] != ob )
        our_mailers[str]->dest_me();

    our_mailers[str] = ob;
    return 1;

} /* add_mailer() */

/**
 * This method finds the mailer associated with a particular player.
 * @param str the player whose mailer to find.
 * @return the mailer object associated with the player
 * @see add_mailer()
 * @see delete_mailer()
 */
object find_mailer( string str ) { return our_mailers[str]; }

/**
 * This method removes a mailer from the current list of mailers.
 * It removes the mailer based on the object itself.
 * @param ob the mailer object to remove
 * @return 0 if unable to remove
 * @see add_mailer()
 * @see find_mailer()
 */
int delete_mailer( object ob ) {
    string key;
    object mailer;

    foreach( key, mailer in our_mailers )
        if( !mailer || mailer == ob )
            map_delete( our_mailers, key );

} /* delete_mailer() */

/** @ignore yes */
void we_are_done( object me ) {
    if( objectp(me) )
        me->dest_me();
} /* we_are_done() */

/**
 * This is the main mail function.  It tries to start up a mailer with
 * the default address and subject.  If there is no default address then
 * the mailer uses its menu mode, otherwise it sends one mail and then
 * leaves.
 * @param str 0 or "" for no default address
 * @param sub the default subject
 */
int mail( string str, string sub ) {
    object mailer;

    mailer = clone_object(MAILER);
    mailer->set_do_this_last( ({ TO, "we_are_done", mailer }) );
    mailer->read_mail( str, sub );

    return 2;

} /* mail() */

/**
 * This method returns the current mailing lists available on the
 * handler.
 * @return the array of available mailing lists
 */
string *query_mailing_lists() {
    return keys(mailing_lists) + ({"lords", "seniors"})+
           DOMAIN_H->query_domains();
} /* query_mailing_lists() */

/**
 * This method returns whether or not this is a controlled list.
 * It is possibly to add/remove members only from controlled lists,
 * ie. not domain or project lists.
 * @param list the list to check
 * @return 1 if this is a controlled list, 0 if not
 */
int query_controlled_list( string list ) {
    return classp( mailing_lists[list] );
} /* query_controlled_list() */

/**
 * This method checks to see if the specified list exists or not.
 * @return 1 if the list exists, 0 if not
 * @param list the list name to check
 * @see query_mailing_lists()
 * @see query_members()
 * @see query_member()
 */
int query_list( string list ) {
    return member_array( list, query_mailing_lists() ) != -1;
} /* query_list() */

/**
 * This returns the current members of the specified mailing list.
 * @return the members of the mailing list
 * @param list the mailing list to get the members of
 * @see query_mailing_lists()
 * @see query_list()
 * @see query_member()
 */
string *query_members( string list ) {
    switch( list ) {
      case "playtesters" :
        return (string *)PLAYTESTERS_H->query_playtesters()+
               (string *)DOMAIN_H->query_members("playtesters");
      case "seniors" :
        return (string *)DOMAIN_H->query_seniors();
      case "lords" :
        return (string *)DOMAIN_H->query_leaders();
      default :
    }

    if( DOMAIN_H->query_domain(list) )
        return (string *)DOMAIN_H->query_members(list);

//    if( PROJECT_H->query_project(list) )
//        return (string *)PROJECT_H->query_members(list);

    if( mailing_lists[list] )
        return copy(mailing_lists[list]->members);

    return ({ });

} /* query_members() */

/**
 * This method checks to see if the given player is in the selected
 * mailing list.
 * @param list_name the mailing list name
 * @param name the name of the player in the list
 * @return 1 if the player is a member, 0 if not
 * @see query_mailing_lists()
 * @see query_list()
 * @see query_members()
 */
int query_member( string list_name, string name ) {
    class mailing_list list;

    list = mailing_lists[list_name];

    if( classp(list) )
        return member_array( name, list->members ) != -1;

    if( list_name == "playtesters")
        return (int)playtesterp( name, 1 ) ||
               (int)DOMAIN_H->query_leader("playtesters", name );

    if( DOMAIN_H->query_domain(list) )
        return (int)DOMAIN_H->query_member( list_name, name );

//    if( PROJECT_H->query_project(list) )
//        return (int)PROJECT_H->query_member( list_name, name );

    if( list_name == "seniors")
        return (int)seniorp(name);

    if( list_name == "lords")
        return (int)lordp(name);

} /* query_member() */

/**
 * This method returns all the current controllers of the mailing list.
 * Controllers can add and remove members from a list.
 * @param list the mailing list to query the controllers for
 * @return the array of controllers
 */
string *query_controllers( string list ) {
    if( DOMAIN_H->query_domain(list) )
        return (string*)DOMAIN_H->query_leaders(list);

//    if( PROJECT_H->query_project(list) )
//        return (string*)PROJECT_H->query_leaders(list);

    if( mailing_lists[list] )
        return copy(mailing_lists[list]->controllers);

    return ({ });

} /* query_controllers() */

/**
 * This method checks to see if the given player is a controller.
 * @param list_name the name of the list
 * @param name the name to check to see if they are a controller
 * @see query_controllers()
 * @see query_member()
 */
int query_controller( string list_name, string name ) {
    class mailing_list list;

    if( classp( list = mailing_lists[list_name] ) )
        return member_array( name, list->controllers ) != -1;

    return 0;

} /* query_controller() */

/**
 * This method determines the creator of the list.
 * @return the creator of the list
 * @param list_name the list to get the creator of
 * @see create_list()
 */
string query_creator( string list_name ) {
    class mailing_list list;

    if( classp( list = mailing_lists[list_name] ) )
        return list->creator;

    return 0;

} /* query_creator() */

/**
 * This method attempts to create a mailing list.
 * @return 1 if successful, 0 if not
 * @param list the name of the list to create
 * @param creator the creator of the list
 * @see query_creator()
 * @see query_members()
 * @see query_controllers()
 */
int create_list( string list, string creator ) {
    if( !PO || file_name(PO) != MAILTOOL )
        return 0;

    if( query_list(list) || PLAYER_H->test_user(list) )
        return 0;

    mailing_lists[list] = new( class mailing_list,
                               members     : ({ creator }),
                               controllers : ({ creator }),
                               creator     : creator );

    save_me();
    return 1;

} /* create_list() */

/**
 * This method will delete a mailing list.
 * @param list the mailing list to delete
 * @see create_list()
 * @return 0 if failed and 1 on success
 */
int delete_list( string list ) {
    if( !PO || file_name(PO) != MAILTOOL )
        return 0;

    if( !mailing_lists[list] )
        return 0;

    map_delete( mailing_lists, list );
    save_me();
    return 1;

} /* delete_list() */

/**
 * This method adds a member to the specified mailing list.
 * @param list_name the mailing list to add a member to
 * @param mem the member to add
 * @return 1 if successful, 0 if not
 * @see remove_member()
 * @see delete_member()
 * @see query_member()
 */
int add_member( string list_name, string mem ) {
    class mailing_list list;

    if( !PO || file_name(PO) != MAILTOOL )
        return 0;

    if( !classp( list = mailing_lists[list_name] ) )
        return 0;

    if( member_array( mem, list->members ) != -1 )
        return 0;

    list->members += ({ mem });

    save_me();
    return 1;

} /* add_member() */

/**
 * This method removes a member from the specified mailing list.
 * If there are non members left in the mailing list, then the
 * list will be deleted.
 * @param list_name the mailing list to remove the member from
 * @param mem the members name to remove
 * @return 1 on success, 0 on failure
 * @see add_member()
 * @see query_member()
 * @see delete_member()
 */
int remove_member( string list_name, string mem ) {
    int i;
    class mailing_list list;

    if( !PO || file_name(PO) != MAILTOOL )
        return 0;

    if( !classp( list = mailing_lists[list_name] ) )
        return 0;

    if( ( i = member_array( mem, list->members ) ) == -1 )
        return 0;

    list->members = delete( list->members, i, 1 );

    if( ( i = member_array( mem, list->controllers)) != -1 )
        list->controllers = delete( list->controllers, i, 1 );

    if( !sizeof(list->members) )
        map_delete( mailing_lists, list_name );

    save_me();
    return 1;

} /* remove_member() */

/**
 * This method adds a controller to the specified mailing list.
 * @param list_name the controller to add
 * @param mem the controller to add
 * @see query_controllers()
 */
int add_controller( string list_name, string mem ) {
    class mailing_list list;

    if( !PO || file_name(PO) != MAILTOOL )
        return 0;

    if( !classp( list = mailing_lists[list_name] ) )
        return 0;

    if( member_array( mem, list->controllers ) != -1 )
        return 0;

    list->controllers += ({ mem });

    if( member_array( mem, list->members ) != -1 )
        list->members += ({ mem });

    save_me();
    return 1;

} /* add_controller() */

/**
 * This method removes a controller from the specified mailing list.
 * @param list_name the mailing list to remove the controller from
 * @param name the member to remove
 * @see add_controller()
 * @see query_controller()
 */
int remove_controller( string list_name, string name ) {
    int i;
    class mailing_list list;

    if( !PO || file_name(PO) != MAILTOOL )
        return 0;

    if( !classp( list = mailing_lists[list_name] ) )
        return 0;

    if( ( i = member_array( name, list->controllers ) ) == -1 )
        return 0;

    list->controllers = delete( list->controllers, i, 1 );

    save_me();
    return 1;

} /* remove_controller() */

/** @ignore yes */
mixed stats() {
    return ({
        ({"lists", sizeof( query_mailing_lists() ) }),
        ({"controlled lists", sizeof(mailing_lists) }),
    });
} /* stats() */
