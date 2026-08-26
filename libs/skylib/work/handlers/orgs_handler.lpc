/**
 * This is the organizations handler.
 * Keeps track of organizations, their members and other properties.
 * @author Sandoz
 */

#define SAVE_FILE  HANDLER_SAVE_DIR "/orgs"
#define TIME       ctime(time())
#define CHECK_TIME 86400
#define DATA       ( ( class org_data ) orgs[name] )

class org_data {
  string info;        // general info about the organization
  string title;       // the official title of the organization
  string *req_orgs;   // any orgs one has to be a memeber of to join
  string *anti_orgs;  // any orgs one can't be a member of to join
  string *req_quests; // any quests one needs to do before joining
  string channel;
}

private mapping orgs, members;

private void check_members( string name );
private void check_all_members();

/** @ignore yes */
private void create() {
    if( file_size( SAVE_FILE+".o" ) > 0 )
        unguarded( (: restore_object, SAVE_FILE :) );
    if( !mapp(orgs) )
        orgs = ([ ]);
    if( !mapp(members) )
        members = ([ ]);
    if( sizeof( keys(orgs) ) )
        call_out( (: check_all_members :), 300 + random( 300 ) );
} /* create() */

/** @ignore yes */
private void save_data_file() {
    unguarded( (: save_object, SAVE_FILE :) );
} /* save_data_file() */

/** @ignore yes */
void dest_me() {
    destruct(TO);
} /* dest_me() */

/**
 * This method returns all the current orgs.
 * @return all current orgs
 * @see query_members()
 * @see query_member()
 */
string *query_orgs() { return keys(orgs); }

/**
 * This method adds a new organization into the orgs mapping.
 * @param name the name of the organization to add
 * @param title the title of the new organization
 * @param info the general description of the organization
 * @return 1 if successful, 0 if an org with the name already exists
 * @see remove_org()
 * @see query_org()
 */
varargs int add_org( string name, string title, string info, string channel ) {
    class org_data org;

    if( !name || name == "" || orgs[name] || !adminp( previous_object(-1) ) )
        return 0;

    org = new( class org_data );
    org->info = info || "Why bother?";
    org->title = title || "The Organization of No Title";
    org->channel = channel;
    orgs[name] = org;
    members[name] = ({ });

    save_data_file();

    return 1;

} /* add_org() */

/**
 * This method removes an organization from the handler.
 * @param name the name of the organization to remove.
 * @return 1 if successfully removed, 0 if not
 * @see add_org()
 * @see query_org()
 */
int remove_org( string name ) {
    if( undefinedp( orgs[name] ) || !adminp( previous_object(-1) ) )
        return 0;

    map_delete( orgs, name );
    map_delete( members, name );

    save_data_file();

    return 1;

} /* remove_org() */

/**
 * This method queries if the specified organization exists or not.
 * @param name the name of the organization to check
 * @return 1 if the organization exists, 0 if not
 * @see add_org()
 * @see remove_org()
 */
int query_org( string name ) { return !undefinedp( orgs[name] ); }

/**
 * This method sets a new title for the specified org.
 * @param name the name of the org to set a new title for
 * @param title the new title to set
 * @return 1 if title successfully set, 0 if not
 * @see query_title()
 */
int set_title( string name, string title ) {
    if( !orgs[name] || !title || title == "" )
        return 0;

    DATA->title = title;
    save_data_file();
    return 1;

} /* set_title() */

/**
 * This method returns the title of the organization.
 * @param name the name of the organization to get the title for
 * @return the title of the organization
 * @see set_title()
 */
string query_title( string name ) {
    if( !orgs[name] )
        return 0;
    return DATA->title;
} /* query_title() */

/**
 * This method sets a new channel for the specified org.
 * @param name the name of the org to set a new channel for
 * @param channel the new channel to set
 * @return 1 if channel successfully set, 0 if not
 * @see query_channel()
 */
int set_channel( string name, string channel ) {
    if( !orgs[name] || !channel || channel == "" )
        return 0;

    DATA->channel = channel;
    save_data_file();
    return 1;

} /* set_title() */

/**
 * This method returns the channel used by the organization.
 * @param name the name of the organization to get the channel for
 * @return the channel used by the organization
 * @see set_channel()
 */
string query_channel( string name ) {
    if( !orgs[name] )
        return 0;
    return DATA->channel;
} /* query_channel() */

/**
 * This method sets a new info for the specified org.
 * @param name the name of the org to set a new info for
 * @param info the new info to set
 * @return 1 if title successfully set, 0 if not
 * @see set_info()
 */
int set_info( string name, string info ) {
    if( !orgs[name] || !info || info == "" )
        return 0;

    DATA->info = info;
    save_data_file();
    return 1;

} /* set_info() */

/**
 * This method returns the general info of the organization.
 * @param name the name of the organization to get the info for
 * @return the general info of the organization
 * @see query_info()
 */
string query_info( string name ) {
    if( !orgs[name] )
        return 0;
    return DATA->info;
} /* query_info() */

/**
 * This method adds an org to the specified organization's
 * required orgs array.
 * @param name the name of the org to add the req for
 * @param req a string or an array of strings to add to
 * the required orgs list
 * @see remove_req_org()
 * @see query_req_orgs()
 */
void add_req_org( string name, mixed req ) {
    string *reqs;

    if( !orgs[name] )
        return;

    if( !pointerp( reqs = DATA->req_orgs ) )
        reqs = ({ });

    if( stringp(req) && query_org(req) && member_array( req, reqs ) == -1 )
        reqs += ({ req });
    else if( pointerp(req) )
        foreach( req in req )
          if( stringp(req) && query_org(req) &&
              member_array( req, reqs ) == -1 )
              reqs += ({ req });

    DATA->req_orgs = reqs;
    save_data_file();

} /* add_req_org() */

/**
 * This method removes an org from the specified organization's
 * required orgs array.
 * @param name the name of the org to remove the req from
 * @param req a string or an array of strings to remove
 * @see add_req_org()
 * @see query_req_orgs()
 */
void remove_req_org( string name, mixed req ) {
    string *reqs;

    if( !orgs[name] )
        return;

    if( !pointerp( reqs = DATA->req_orgs ) )
        return;

    if( stringp(req) )
        reqs -= ({ req });
    else if( pointerp(req) )
        foreach( req in req )
          if( stringp(req) )
              reqs -= ({ req });

    DATA->req_orgs = reqs;
    save_data_file();

} /* remove_req_org() */

/**
 * This method will return the orgs one has to be a member of
 * before they can join the specified org.
 * @param name the name of the org to get the required orgs for
 * @return the required orgs array
 * @see add_req_org()
 * @see remove_req_org()
 */
string *query_req_orgs( string name ) { return DATA->req_orgs || ({ }); }

/**
 * This method adds a quest to the specified organization's
 * required quests array.
 * @param name the name of the org to add the req quest for
 * @param req a string or an array of strings to add to
 * the required quests list
 * @see remove_req_quest()
 * @see query_req_quests()
 */
void add_req_quest( string name, mixed req ) {
    string *reqs;

    if( !orgs[name] )
        return;

    if( !pointerp( reqs = DATA->req_quests ) )
        reqs = ({ });

    if( stringp(req) && member_array( req, reqs ) == -1 )
        reqs += ({ req });
    else if( pointerp(req) )
        foreach( req in req )
          if( stringp(req) && member_array( req, reqs ) == -1 )
              reqs += ({ req });

    DATA->req_quests = reqs;
    save_data_file();

} /* add_req_quest() */

/**
 * This method removes a quest from the specified organization's
 * required quests array.
 * @param name the name of the org to remove the req quest from
 * @param req a string or an array of strings to remove
 * @see add_req_quest()
 * @see query_req_quests()
 */
void remove_req_quest( string name, mixed req ) {
    string *reqs;

    if( !orgs[name] )
        return;

    if( !pointerp( reqs = DATA->req_quests ) )
        return;

    if( stringp(req) )
        reqs -= ({ req });
    else if( pointerp(req) )
        foreach( req in req )
          if( stringp(req) )
              reqs -= ({ req });

    DATA->req_quests = reqs;
    save_data_file();

} /* remove_req_quest() */

/**
 * This method will return the quests has to do before they can
 * join the specified org.
 * @param name the name of the org to get the required quest for
 * @return the required quests array
 * @see add_req_quest()
 * @see remove_req_quest()
 */
string *query_req_quests( string name ) { return DATA->req_quests || ({ }) ; }

/**
 * This method adds an org that one can't be a member of to the
 * specified organization's required anti-orgs array.
 * @param name the name of the org to add the req for
 * @param anti a string or an array of strings to add to
 * the anti-org list
 * @see remove_anti_org()
 * @see query_anti_orgs()
 */
void add_anti_org( string name, mixed anti ) {
    string *antis;

    if( !orgs[name] )
        return;

    if( !pointerp( antis = DATA->anti_orgs ) )
        antis = ({ });

    if( stringp(anti) && query_org(anti) && member_array( anti, antis ) == -1 )
        antis += ({ anti });
    else if( pointerp(anti) )
        foreach( anti in anti )
          if( stringp(anti) && query_org(anti) &&
              member_array( anti, antis ) == -1 )
              antis += ({ anti });

    DATA->anti_orgs = antis;
    save_data_file();

} /* add_anti_org() */

/**
 * This method removes an anti-org from the specified organization's
 * anti-orgs array.
 * @param name the name of the org to remove the anti-org from
 * @param anti a string or an array of strings to remove
 * @see add_anti_org()
 * @see query_anti_orgs()
 */
void remove_anti_org( string name, mixed anti ) {
    string *antis;

    if( !orgs[name] )
        return;

    if( !pointerp( antis = DATA->anti_orgs ) )
        return;

    if( stringp(anti) )
        antis -= ({ anti });
    else if( pointerp(anti) )
        foreach( anti in anti )
          if( stringp(anti) )
              antis -= ({ anti });

    DATA->anti_orgs = antis;
    save_data_file();

} /* remove_anti_org() */

/**
 * This method will return the orgs one cannot be a member of
 * if they want to join the specified org.
 * @param name the name of the org to get the anti-orgs for
 * @return the anti-orgs array
 * @see add_anti_org()
 * @see remove_anti_org()
 */
string *query_anti_orgs( string name ) { return DATA->anti_orgs || ({ }) ; }

/**
 * This method returns all the members of the specified org.
 * @param name the name of the org to get the members of
 * @return the members array
 * @see query_member()
 */
string *query_members( string name ) { return members[name] || ({ }); }

/**
 * This method queries whether or not the player is a
 * member of the organization or not.
 * @param name the name of the org to check
 * @param player the name of the player to check
 * @return 1 if the player is a member, 0 if not
 * @see add_member()
 * @see remove_member()
 * @see query_can_join()
 */
int query_member( string name, string player ) {
    string *tmp;

    if( !pointerp( tmp = members[name] ) )
        return 0;

    return ( member_array( player, tmp ) != -1 );

} /* query_member() */

/**
 * This method checks whether or not the player can join an org.
 * This checks all the reqs and anti-orgs etc.
 * @param name the name of the org to check
 * @param player the name of the player to check
 * @return 1 if the player could join the org, 0 if not
 * @see add_member()
 * @see remove_member()
 * @see query_member()
 */
int query_can_join( string name, string player ) {
    if( !orgs[name] || !PLAYER_H->test_user(player) )
        return 0;

    if( sizeof( filter( query_req_orgs(name),
        (: !query_member( $1, $2 ) :), player ) ) )
        return 0;

    if( sizeof( filter( query_anti_orgs(name),
        (: query_member( $1, $2 ) :), player ) ) )
        return 0;

    if( sizeof( filter( query_req_quests(name),
        (: !LIBRARY_H->query_quest_done( $2, $1 ) :), player ) ) )
        return 0;

    return 1;

} /* query_can_join() */

/**
 * This method adds a member to an org.
 * @param name the name of the org to add a member to
 * @param player the name of the player to add
 * @return 1 if successfully added, 0 if not
 * @see remove_member()
 * @see query_member()
 * @see query_can_join()
 */
int add_member( string name, string player ) {
    
    if( !members[name] || query_member( name, player ) ||
        !query_can_join( name, player ) )
        return 0;

    members[name] += ({ player });
    save_data_file();
         
    return 1;

} /* add_member() */

/**
 * This method removes a member from an org.
 * @param name the name of the org to remove a member from
 * @param player the name of the player to remove
 * @return 1 if successfully removed, 0 if not
 * @see add_member()
 * @see query_member()
 * @see query_can_join()
 */
int remove_member( string name, string player ) {
    if( !members[name] )
        return 0;

    members[name] -= ({ player });
    save_data_file();
    return 1;

} /* add_member() */

/**
 * This method returns the orgs the specified player is a member of.
 * @param player the name of the player
 * @return the orgs the player is a member of
 * @see query_orgs()
 * @see query_member()
 */
string *query_my_orgs( string player ) {
    return filter( keys(orgs), (: query_member( $1, $2 ) :), player );
} /* query_my_orgs() */

/** @ignore yes */
private void check_members( string *left ) {
    if( sizeof(left) ) {
        string name;
         
        name = left[0];
        left = left[1..];

        foreach( string player in query_members( name ) ) {
            if( !player || !PLAYER_H->test_user(player) ) {
                members[name] -= ({ player });
                log_file("ORGS", "%O removed from %O - %s - %s\n",
                    player, name, "doesn't exist anymore", TIME );
            }
        }

        if( sizeof(left) ) {
            call_out( (: check_members :), 10, left );
            return;
        }

        // Save only when the cycle has ended,
        // otherwise we save once every ten seconds per org.
        save_data_file();
    }

} /* check_members() */

/** @ignore yes */
private void check_all_members() {
    string *all;

    call_out( (: check_all_members :), CHECK_TIME );

    if( sizeof( all = keys(orgs) ) )
        check_members( all );

} /* check_all_members() */

/**
 * This method deletes the given player by name from all orgs.
 * This should be called by the refresh handler when the player
 * refreshes or is deleted.
 * @param player the player to delete
 */
void refresh_player( string player ) {
    int flag;

    foreach( string name in keys(members) ) {
        if( member_array( player, members[name] ) != -1 ) {
            flag = 1;
            members[name] -= ({ player });
        }
    }

    if( flag )
        save_data_file();

} /* refresh_player() */

/** @ignore yes */
mixed stats() {
    mixed org_info;

    org_info = ({ });

    foreach( string name in keys(orgs) )
        org_info += ({ ({ name, DATA->title }) });

    return ({ ({ "total orgs" , sizeof( keys( orgs ) ) }) }) + org_info;

} /* stats() */
