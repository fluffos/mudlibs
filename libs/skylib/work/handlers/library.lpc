/**
 * The library is a sort of information center.
 * Currently it supports only the recording on stories about players and
 * recording the quests that they have done.
 * @author Furball
 * @see /include/library.h
 */

#include <quest_handler.h>

#define SHARED 10
#define UNSHARED 90
#define RESTORE_PATH  "save/library/"

inherit "/std/object";

int *times;
string player_name, *quests, text_file;
mapping player_quest_info;

nosave mapping qps;

int new_top_quest();

/** @ignore yes */
private void init_data(string pl_name) {
    player_name = pl_name;
    quests = ({ });
    times = ({ });
    text_file = "";
    player_quest_info = ([ ]);
} /* init_data() */

/** @ignore yes */
private int get_data_file( string name ) {
    int success;

    if( player_name != name ) {
        success = unguarded( (: restore_object, RESTORE_PATH+name[0..0]+"/"+name :) );
        if( !success ) {
            init_data( name );
        }
        return success;
    }
    return 1;
} /* get_data_file() */

/** @ignore yes */
private void save_data_file( string name ) {
    unguarded( (: save_object, RESTORE_PATH+name[0..0]+"/"+name :) );
    return ;
} /* save_data_file() */

/**
 * This method returns the players current title.
 * @param name the name of the player
 * @return their current title, 0 if no title
 * @see /handlers/quest_handler.c
 */
string query_title( string name ) {
    get_data_file( name );
    if( !quests || !sizeof( quests ) )
        return 0;
    return (string)QUEST_HANDLER->query_quest_title( choice( quests ) );
} /* query_title() */

/**
 * This method returns the set of currently completed quests by the
 * player.
 * @param name the name of the player
 * @return the array of completed quests
 */
string *query_quests( string name ) {
    get_data_file(name);
    if( !quests )
        return ({ });
    return quests + ({ });
} /* query_quests() */

/**
 * This method returns the most recently completed quest by the player.
 * @param name the player name
 * @return the most recently completed quest
 */
string get_most_recent_quest( string name ) {
    int loop, highest;
    string quest_name;

    if( !get_data_file(name) )
        return "Sorry";

    if( !sizeof(quests) )
        return "None";

    for( highest = loop = 0; loop < sizeof(quests); loop++ ) {
        if( times[loop] > highest ) {
            highest = times[loop];
            quest_name = quests[loop];
        }
    }

    return quest_name;

} /* get_most_recent_quest() */

/**
 * This method gets the most recent time a quest was complete by the
 * player.
 * @param name the name of the player
 * @return the time of the most recently completed quest
 */
int get_most_recent_time( string name ) {
    int *t;

    if( !get_data_file(name) )
        return -1;

    if( !sizeof(quests) )
        return 0;

    if( !sizeof( t = sort_array( times, -1 ) ) )
        return 0;


    return t[0];

} /* get_most_recent_time() */

/**
 * This method sets the player as having done the quest and if we
 * should give them xp for it
 * This function should be called when a quest is finished.  It will then
 * call the quest_completed function on the quest handler and do all
 * assorted modifications to the player object etc.  The name should be the
 * players name and the quest should be the name of the quest that is
 * stored in the quest handler.
 * <p>
 * The include file <library.h> should be used for calls to this
 * handler.
 * @return 0 if the quest is already completed
 * @see /handlers/quest_handler->quest_completed()
 * @param pl_name name of the player
 * @param qu_name name of the quest
 * @param no_xp do not give out xp
 * @example
 * // Set the player as completing the womble friend quest, they get
 * // xp for it.
 * LIBRARAY->set_quest(this_player()->query_name(), "womble friend", 0);
 */
int set_quest(string pl_name, string qu_name, int no_xp) {
    int qu_level, qu_xp;
    object ob;

    // guests can't do quests.
    if( find_player(pl_name)->query_property("guest") )
        return 0;

    // Inactive quests automatically fail.
    if( !QUEST_HANDLER->query_quest_status(qu_name) )
        return 0;

    // clean out the qps cache so that we don't get invalid data.
    if( qps && qps[pl_name] )
        map_delete( qps, pl_name );

    get_data_file( pl_name );

    /* Already done the quest? */
    if( member_array( qu_name, quests ) != -1 )
        return 0;

    quests += ({ qu_name });
    times += ({ time() });

    /* Make sure the quest exists */
    qu_level = (int)QUEST_HANDLER->query_quest_level( qu_name );
    if( qu_level < 1 )
        return 0;

    qu_xp = (int)QUEST_HANDLER->query_quest_xp( qu_name );
    if( qu_xp < 1 )
        qu_xp = qu_level * 10000;

    QUEST_HANDLER->quest_completed( pl_name, qu_name, PO );
    save_data_file( pl_name );
    ob = find_player( pl_name );
    if( objectp( ob ) ) {
         if( !no_xp ) {
             ob->adjust_xp( (qu_xp*UNSHARED/100));
             /* The 1 indicates that this xp should be */
             /* shared with other team members. */
             ob->adjust_xp( qu_xp*SHARED/100, 1 );
       }
       call_out("save_them", 1, ob );
       ob->set_title( "quest",
               (string)QUEST_HANDLER->query_quest_title( qu_name ) );
    }

    return 1;

} /* set_quest() */

/**
 * This method removes a quest from the players list of completed quests.
 * @param pl_name the player name
 * @param qu_name the quest name
 * @return 0 if they have not done the quest, 1 if they habe
 * @see /handlers/quest_handler.c
 */
int unset_quest( string pl_name, string qu_name ) {
    int qu_level, i;

    get_data_file( pl_name );

    /* haven't done the quest? */
    if( ( i = member_array( qu_name, quests ) ) == -1 )
        return 0;

    /* make sure the quest exists */
    qu_level = (int)QUEST_HANDLER->query_quest_level( qu_name );
    if( qu_level < 1 )
        return 0;

    quests -= ({ qu_name });
    times -= ({ times[i] });

    save_data_file( pl_name );
    return 1;

} /* unset_quest() */

/**
 * This method causes the player to be saved.
 * @param thing the player to save
 */
void save_them( object thing ) {
    if( thing )
        thing->save();
} /* save_them() */

/**
 * This method  sets the information related to the players quest.
 * This information is used for quests which have several parts to them
 * and information needs to be stored about the player as they attempt
 * to complete it.
 * @param pl_name the name of the player
 * @param qu_info the quest name
 * @param details the information associated with the quest.
 */
void set_player_quest_info( string pl_name, string qu_info, mixed *details ) {
    get_data_file( pl_name );
    if( !player_quest_info )
        player_quest_info = ([ ]);
    player_quest_info[qu_info] = details;
    save_data_file(pl_name);
} /* set_player_quest_info() */

/**
 * This method returns all the quest information for a player.
 * This information is used for quests which have several parts to them
 * and information needs to be stored about the player as they attempt
 * to complete it.  The keys of the mapping are the quest names and the
 * values are the information associated with the quest.
 * @param pl_name the name of the player
 * @return the mapping containing all the quest info
 */
mapping query_all_player_quest_info( string pl_name ) {
    get_data_file( pl_name );
    if( !player_quest_info )
        return 0;
    return copy(player_quest_info);
} /* query_all_player_quest_info() */

/**
 * This method returns the quest info for a specific quest.
 * This information is used for quests which have several parts to them
 * and information needs to be stored about the player as they attempt
 * to complete it.
 * @param pl_name the player name
 * @param qu_info the quest name
 * @return the information associated with the quest
 */
mixed *query_player_quest_info( string pl_name, string qu_info ) {
    get_data_file( pl_name );
    if( !player_quest_info )
        return 0;
    player_quest_info = player_quest_info + ([ ]);
    return player_quest_info[qu_info];
} /* query_player_quest_info() */

/**
 * This method returns the time at which a quest is completed.
 * @param name the name of the player to get the time for
 * @param qu_name the name of the quest
 * @return the time at which it is completed
 */
int query_quest_time( string name, string qu_name ) {
    int time;

    if( !get_data_file(name) )
        return 0;

    time = member_array( qu_name, quests );
    if( time < 0 )
        return 0;

    return times[time];

} /* query_quest_time() */

/**
 * This method returns the story associated with the player.   This is
 * created from all the information about the quests they have done
 * joined together into a neato story.
 * @param name the player name
 * @return the story of the player
 * @see /handlers/quest_handler->query_quest_story()
 */
string query_story( string name ) {
    string story, quest;

    if( !get_data_file(name) )
        return "You can find nothing in the library on " + CAP(name) + "\n";

    if( text_file != "" )
        return unguarded( (: read_file, text_file :) );

    if( !sizeof(quests) )
        return CAP( player_name )+" has lead a most unadventureous life.\n";

    story = "";

    foreach( quest in quests )
        story += QUEST_HANDLER->query_quest_story( quest )+",\n";

    return story;

} /* query_story() */

/**
 * This method tells us if the player has completed the quest.
 * @param player the name of the player
 * @param quest the quest name
 * @return 1 if the quest has been done, 0 if it has not
 */
int query_quest_done( string player, string quest ) {
    get_data_file(player);
    return member_array( quest, quests ) != -1;
} /* query_quest_done() */

/**
 * This method returns the current number of quest points gathered
 * by the player.
 * @param name the player
 * @return the current number of quest pointds
 * @see /handlers/query_handler->query_quest_level()
 */
int query_quest_points( string name ) {
    int points;
    string word;

    // qps is used to cache the count of quest points since it's expensive and
    // queried a lot.
    // the reason for storing points+1 is so that someone with 0 points still
    // comes up true under the test if(qps[name])
    if( !qps )
        qps = ([ ]);

    if( qps[name] )
        return qps[name]-1;

    get_data_file( name );
    if( !quests || !sizeof( quests ) )
        points = 0;
    else {
        foreach( word in quests )
            points += (int)QUEST_HANDLER->query_quest_level( word );
    }

     qps[name] = points+1;

     return points;

} /* query_quest_points() */

/**
 * This method is called when a player refreshes totally or gets deleted.
 * @param name the player name
 * @return 0 if they do not exists, 1 if they do
 */
int restart( string name ) {
    if( TP != this_player(1) && PO != find_object("/handlers/refresh") )
        return 0;

    // clean out the qps cache so that we don't get invalid data.
    if( !qps )
        qps = ([ ]);

    if( !undefinedp( qps[name] ) )
        map_delete( qps, name );

    player_name = 0;
    unguarded( (: rm, RESTORE_PATH+name[0..0]+"/"+name+".o" :) );
    return 1;

} /* restart() */
