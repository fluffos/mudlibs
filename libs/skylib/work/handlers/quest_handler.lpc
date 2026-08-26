/**
 * This class keeps track of the current set of quests availabe in the
 * game.
 * @author Furball
 */

#include <library.h>

#define QUEST_LOG "QUESTS"
#define SAVE_FILE "/save/quests"
#define BACKUP_FILE "/save/quests/quests"

inherit OBJECT_OBJ;

private int *quest_level;
private int *quest_xp;
private int *num_times_done;
private int *quest_status;
private string *quest_name;
private string *quest_title;
private string *quest_story;
private string *last_done_by;
private nosave int total_qp;

/**
 * This method reloads the quests from the save file.
 * @see save_quests()
 */
void load_quests() { unguarded( (: restore_object, SAVE_FILE :) ); }

/**
 * This method saves the current set of quests to the save file.
 * @see load_quests()
 */
void save_quests() { unguarded( (: save_object, SAVE_FILE :) ); }

void create() {
   int i;
   ::create();
   load_quests();
   if ( !quest_name ) {
      quest_name = ({ });
   }
   if ( !quest_level ) {
      quest_level = ({ });
   }
   if ( !quest_title ) {
      quest_title = ({ });
   }
   if ( !quest_story ) {
      quest_story = ({ });
   }
   if ( !quest_xp ) {
      quest_xp = ({ });
   }
   if ( !last_done_by ) {
      last_done_by = ({ });
   }
   if ( !num_times_done ) {
      num_times_done = ({ });
   }
   if ( !quest_status ) {
     if(sizeof(quest_name)) {
       quest_status = allocate(sizeof(quest_name));
       for(i=0; i<sizeof(quest_name); i++) {
         quest_status[i] = 1;
       }
     } else {
       quest_status = ({ });
     }
   }

   for(i = 0; i<sizeof(quest_level); i++) {
     if(quest_status[i]) {
       total_qp += quest_level[i];
     }
   }

} /* create() */

/**
 * This returns the current total gp for all of the current quests.
 * @return the total gp
 */
int query_total_qp() { return total_qp; }

/**
 * This method adds a new quest into the system.  You only need to call
 * this ONCE.  The name of the quest must be unique.  The story is
 * what can be seen in the players books about the player.
 * @param name the name of the quest
 * @param level the level of the quest 0-100
 * @param title the title for finishing the quest, 0 for none
 * @param story the story about the quest
 * @return 1 if successful, 0 if not
 * @see delete_quest()
 * @see query_quest_level()
 * @see query_quest_title()
 * @see query_quest_story()
 */
int add_quest( string name, int level, int xp, string title, string story ) {

  if(file_name(PO) != "/secure/cmds/lord/questtool"){
        printf("Illegal access.");
        return 0;
  }

   if ( member_array( name, quest_name ) != -1 )
      return 0;
   quest_name += ({ name });
   quest_level += ({ level });
   quest_xp += ({ xp });
   quest_title += ({ title });
   quest_story += ({ story });
   last_done_by += ({ "nobody" });
   num_times_done += ({ 0 });
   quest_status += ({ 1 }); //Make it active!
   log_file( QUEST_LOG, (string)this_player()->query_name() +
         " added: "+ name +", "+ level +", "+ title +", "+ story +"\n" );
   save_quests();
   unguarded( (: cp, SAVE_FILE +".o", BACKUP_FILE +"."+ time() :) );
   total_qp += level;
   return 1;
} /* add_quest() */

/**
 * Change the status of a quest from active to inactive
 * and vice versa.
 * @param the name of a quest.
 */
int change_quest_status(string name) {
  int temp;

  if(file_name(PO) != "/secure/cmds/lord/questtool"){
        printf("Illegal access.");
        return 0;
  }

  temp = member_array(name, quest_name);
  if(temp == -1) {
    return -1;
  }
  quest_status[temp] = !quest_status[temp];
  return quest_status[temp];
}

/**
 * This method returns the status of a quest.
 * @param the name of a quest
 * @return 1 for active, 0 for inactive.
 */
int query_quest_status(string name) {
  int temp;

  temp = member_array(name, quest_name);
  if(temp == -1) {
    return -1;
  }
  return quest_status[temp];
}


/**
 * This method returns the level of the quest.
 * @param name the name of the quest
 * @return the level of the quest, -1 on failure
 * @see add_quest()
 * @see set_quest_level()
 */
int query_quest_level(string name) {
  int temp;

  temp = member_array(name, quest_name);
  if(temp == -1) {
    return -1;
  }
  return quest_level[temp];
} /* query_quest_level() */

/**
 * This method sets the level of the quest.
 * @param name the name of the quest
 * @param level the level of the quest
 * @return 0 on failure, 1 on success
 * @see add_quest()
 * @see query_quest_level()
 */
int set_quest_level(string name, int level) {
   int temp;

  if(file_name(PO) != "/secure/cmds/lord/questtool"){
        printf("Illegal access.");
        return 0;
  }
   temp = member_array(name, quest_name);
   if(temp == -1) {
      return 0;
   }
   log_file(QUEST_LOG, "%s : level set for %s to %d\n\n",
            this_player()->query_name(), name, level);
   quest_level[ temp ] = level;
   save_quests();
   return 1;
} /* set_quest_level() */

/**
 * This method returns the xp reward of the quest.
 * @param name the name of the quest
 * @return the xp reward of the quest, -1 on failure
 * @see add_quest()
 * @see set_quest_xp()
 */
int query_quest_xp(string name) {
  int temp;

  temp = member_array(name, quest_name);
  if(temp == -1) {
    return -1;
  }
  return quest_xp[temp];
} /* query_quest_xp() */

/**
 * This method sets the xp reward of the quest.
 * @param name the name of the quest
 * @param amount the amount of xp reward of the quest
 * @return 0 on failure, 1 on success
 * @see add_quest()
 * @see query_quest_xp()
 */
int set_quest_xp(string name, int amount) {
   int temp;

  if(file_name(PO) != "/secure/cmds/lord/questtool"){
        printf("Illegal access.");
        return 0;
  }

   temp = member_array(name, quest_name);
   if(temp == -1) {
      return 0;
   }
   log_file(QUEST_LOG, "%s : xp amount set for %s to %d\n\n",
            this_player()->query_name(), name, amount);
   quest_xp[ temp ] = amount;
   save_quests();
   return 1;
} /* set_quest_level() */

/**
 * This method returns the story associated with the quest.
 * @param name of the quest
 * @return the story of the quest
 * @see add_quest()
 * @see set_quest_story()
 */
string query_quest_story(string name) {
  int temp;

  temp = member_array(name, quest_name);
  if(temp == -1) {
    return "did nothing";
  }
  return quest_story[temp];
} /* query_quest_story() */

/**
 * This method sets the story associated with the quest.
 * @param name of the quest
 * @param story the new story of the quest
 * @see add_quest()
 * @see query_quest_story()
 */
int set_quest_story(string name, string story) {
   int temp;

  if(file_name(PO) != "/secure/cmds/lord/questtool"){
        printf("Illegal access.");
        return 0;
  }

   temp = member_array(name, quest_name);
   if(temp == -1) {
      return 0;
   }
   log_file(QUEST_LOG, "%s : story set for %s to %s\n\n",
            this_player()->query_name(), name, story);
   quest_story[ temp ] = story;
   save_quests();
   return 1;
} /* set_quest_story() */

/**
 * This method returns the title associated with the quest.
 * @param name of the quest
 * @return the title of the quest
 * @see add_quest()
 * @see set_quest_title()
 */
string query_quest_title(string name) {
  int temp;

  temp = member_array(name, quest_name);
  if(temp == -1 || quest_title[temp] == "") {
    return "Unknown Quester";
  }
  return quest_title[temp];
} /* query_quest_title() */

/**
 * This method sets the title associated with the quest.
 * @param name of the quest
 * @param title the new title of the quest
 * @see add_quest()
 * @see query_quest_title()
 */
int set_quest_title(string name, string title) {
   int temp;

  if(file_name(PO) != "/secure/cmds/lord/questtool"){
        printf("Illegal access.");
        return 0;
  }

   temp = member_array(name, quest_name);
   if(temp == -1) {
      return 0;
   }
   log_file(QUEST_LOG, "%s : title set for %s to %s\n\n",
            this_player()->query_name(), name, title);
   quest_title[ temp ] = title;
   save_quests();
   return 1;
} /* set_quest_title() */

/**
 * This method returns the number of times the quest has been
 * completed.
 * @param name thre name of the quest
 * @return the number of times completed
 * @see quest_completed()
 * @see add_quest()
 * @see query_quest_done()
 */
int query_quest_times( string name ) {
   int i;

   i = member_array( name, quest_name );
   if ( i == -1 )
      return -1;
   return num_times_done[ i ];
} /* query_quest_times() */

/**
 * This method returns the name of the last person to complete the
 * quest.
 * @param name thre name of the quest
 * @return the last person to complete the quest
 * @see quest_completed()
 * @see add_quest()
 * @see query_quest_times()
 */
mixed query_quest_done( string name ) {
   int i;

   i = member_array( name, quest_name );
   if ( i == -1 )
      return -1;
   return last_done_by[ i ];
} /* query_quest_done() */

/**
 * This method removes the given quest from the system.
 * @see name the name of the quest to remove
 * @return 0 on failure, 1 on success
 * @see add_quest()
 */
int delete_quest(string name) {
   int temp;

   if(file_name(PO) != "/secure/cmds/lord/questtool"){
        printf("Illegal access.");
        return 0;
   }
   log_file(QUEST_LOG, this_player()->query_name() + " removed : " +
            name + "\n\n");
   temp = member_array(name, quest_name);
   if(temp == -1) {
      return 0;
   }
   total_qp -= quest_level[temp];
   quest_xp = delete(quest_xp, temp, 1);
   quest_name = delete(quest_name, temp, 1);
   quest_level = delete(quest_level, temp, 1);
   quest_title = delete(quest_title, temp, 1);
   quest_story = delete(quest_story, temp, 1);
   last_done_by = delete( last_done_by, temp, 1 );
   num_times_done = delete( num_times_done, temp, 1 );
   save_quests();
   return 1;
} /* delete_quest() */

/**
 * This method returns the names of all the quests.
 * @return the names of all the quests
 * @see add_quest()
 * @see delete_quest()
 */
string *query_quest_names() {
  return quest_name + ({ });
} /* query_quest_names() */

/**
 * This method returns the levels of all the quests.
 * @return the levels of all the quests
 * @see add_quest()
 * @see delete_quest()
 */
int *query_quest_levels() {
  return quest_level + ({ });
} /* query_quest_levels() */

/**
 * This method returns the xp rewards of all the quests.
 * @return the levels of all the quests
 * @see add_quest()
 * @see delete_quest()
 */
int *query_quest_xps() {
  return quest_xp + ({ });
} /* query_quest_levels() */

/**
 * This method returns the titles of all the quests.
 * @return the titles of all the quests
 * @see add_quest()
 * @see delete_quest()
 */
string *query_quest_titles() {
  return quest_title + ({ });
} /* query_quest_titles() */

/**
 * This method returns the stories of all the quests.
 * @return the stories of all the quests
 * @see add_quest()
 * @see delete_quest()
 */
string *query_quest_stories() {
  return quest_story + ({ });
} /* query_quest_stories() */

/**
 * This method should be called in the code when a quest is complete.
 * @param name name of the player
 * @param quest the quest completed
 * @param prev_ob the object which completed the quest
 * @see add_quest()
 * @see delete_quest()
 */
void quest_completed( string name, string quest, object prev_ob ) {
   int i;
   string word;

   log_file( QUEST_LOG, ctime( time() ) +" "+ name +" completed "+
         quest +"\n" );
   user_event( "inform", name +" completes "+ quest, "quest" );
   if ( file_name( previous_object() ) != LIBRARY ) {
      prev_ob = previous_object();
   }
   word = (string)prev_ob->query_name();
   if ( !word ) {
      word = file_name( prev_ob );
   } else {
      word += " ("+ file_name( prev_ob ) +")";
   }
   log_file( QUEST_LOG, "given by "+ word +"\n" );
   i = member_array( quest, quest_name );
   if ( i == -1 ) {
      log_file( QUEST_LOG, "non existent quest\n" );
      return;
   }
   last_done_by[ i ] = name;
   num_times_done[ i ]++;
   save_quests();
} /* query_completed() */

/* Fame functions - for use in halls of fame / libraries etc. */
/* Piecemaker 25/3/93                                         */

/**
 * This method returns the fame of the player.
 * Gets the fame percentage of the player. Quest points / total quest points
 * @param name the name of the player
 * @return the fame as a percentage (0-100)
 * @see query_player_story()
 * @see query_fame_string()
 * @see query_total_qp()
 */
int query_player_fame(string name){
   int playerqp, rank;

   /* do checking on the names */
   if (!name){
      return 0;
   }
   /* expand the nicknames if there are any */
   if (this_player()){
      name = (string)this_player()->expand_nickname(name);
   }
   /* are they a valid player ? */
   if( !rank(name) ) {
      return 0;
   }

   /* do the calculations */
   playerqp = (int)LIBRARY->query_quest_points(name);

   rank = ( playerqp * 125 ) / query_total_qp();
   return rank;
} /* query_player_fame() */

/**
 * This method returns a string associated with the fame level of the
 * player.
 * @param name the name of the player
 * @return the fame string
 * @see query_player_fame()
 * @see query_player_story()
 */
string query_fame_str( string name ) {
   switch ( query_player_fame( name ) ) {
      case 0 .. 4 :
         return "completely unknown";
      case 5 .. 14 :
         return "unknown";
      case 15 .. 24 :
         return "unknown";
      case 25 .. 34 :
         return "moderately well known";
      case 35 .. 44 :
         return "well known";
      case 45 .. 54 :
         return "very well known";
      case 55 .. 64 :
         return "known throughout the region";
      case 65 .. 74 :
         return "famous";
      case 75 .. 84 :
         return "renowned";
      case 85 .. 94 :
         return "very renowned";
      default :
         return "so renowned that no introduction is needed";
   }
} /* query_fame_str() */

/**
 * This method lists the stories for the quests the player has done.
 * @param name the name of the player
 * @return the story of the player
 * @see query_fame_string()
 * @see query_player_fame()
 */
string *query_player_story(string name){
   string *quests;
   string *story;
   int i;

   story = ({ });
   /* do checking on the names */
   if (!name){
      return ({ });
   }
   /* expand the nicknames if there are any */
   if (this_player()){
      name = (string)this_player()->expand_nickname(name);
   }
   /* are they a valid player ? */
   if( !rank(name) ) {
      return 0;
   }

   /* right, we checked everything now. Lets do some real work. */
   quests = query_quest_names();
   if (sizeof(quests) == 1){
      story = ({"Is an under achiever."});
   }
   else{
      for(i=0;i<sizeof(quests);i++){
         if (LIBRARY->query_quest_done(name, quests[i])){
            story = ({ query_quest_story( quests[ i ] ) }) + story;
         }
      }
   }
   return story;
} /* query_player_story() */
