/**
 * This class contains all the stuff needed to control families in a
 * player.
 * @author Pinkfish
 * @started Fri Oct 30 07:53:30 PST 1998
 */

#include <clubs.h>

/**
 * The class for family information in the family stuff for the player.
 * This is used internaly to the player object and should not be used
 * elsewhere.
 * @member name the family name
 * @member adjectives the adjectives
 * @member id the id
 * @member titles the allowed played titles
 * @member cur_title the current player title
 */
class family_information {
   string name;
   string *adjectives;
   string id;
   string *titles;
   string cur_title;
   string *clubs;
}

// The name of the variable is this because we need to
// preserve save file integrity.
private class family_information _family_name;

string query_name();

/**
 * This method creates the family information class and fills in all the
 * defaults.
 */
private class family_information create_family_info() {
   class family_information bing;

   bing = new(class family_information);
   bing->adjectives = ({ });
   bing->titles = ({ "mr", "miss", "mrs", "ms" });
   bing->clubs = ({ });

   return bing;

} /* create_family_info() */

/**
 * Update the adjectives.
 */
private void update_adjectives() {
   if( !_family_name )
       return;

   _family_name->adjectives = ({ });
   _family_name->id = 0;

   if( _family_name->name ) {
       _family_name->adjectives = explode( lower_case(_family_name->name), " ")[0..<2];
       _family_name->id = explode( lower_case(_family_name->name), " ")[<1];
   }

   if( _family_name->cur_title )
       _family_name->adjectives += explode( _family_name->cur_title, " ");

} /* update_adjectives() */

/**
 * This method adds the players title into the list of allowed titles.
 * @param title the title to add into the list
 * @see set_player_title()
 * @see remove_player_title()
 * @return 1 if the title was added successfuly, 0 if it exists
 * @example
 * player->add_player_title("lord");
 */
int add_player_title(string title) {
   title = lower_case(title);
   if( !_family_name )
       _family_name = create_family_info();
   if( member_array( title, _family_name->titles ) == -1 ) {
       _family_name->titles += ({ title });
       return 1;
   }

   return 0;

} /* add_player_title() */

/**
 * This method removes the players title from the list of allowed titles.
 * @param title the title to remove from the list
 * @see set_player_title()
 * @see add_player_title()
 */
void remove_player_title(string title) {
   title = lower_case(title);
   if( !_family_name )
       _family_name = create_family_info();
   if( member_array( title, _family_name->titles ) != -1 )
       _family_name->titles -= ({ title });
} /* remove_player_title() */

/**
 * This method sets the current family name of the player.
 * @param name the new family name
 * @see query_family_name()
 * @return 1 if successfully set
 */
int set_family_name( string name ) {
   // Not a family, or not a member.
   if( name && ( !CLUB_HANDLER->is_family(name) ||
       !CLUB_HANDLER->is_member_of( name, query_name() ) ) )
       return 0;

   if( !classp(_family_name) )
       _family_name = create_family_info();

   if( _family_name->name )
       CLUB_HANDLER->remove_member( _family_name->name, query_name() );

   if( name )
      _family_name->name = CLUB_HANDLER->query_club_name(name);
   else
      _family_name = 0;

   update_adjectives();
   return 1;

} /* set_family_name() */

/**
 * This method checks to make sure the players current family name
 * is still valid.  This will be called on startup and at various
 * other times.
 * @see set_family_name()
 */
void check_family_name() {
   class family_information frog;
   string bing;

   if( !classp(_family_name) && _family_name ) {
       bing = (string)_family_name;
       _family_name = create_family_info();
       set_family_name(bing);
   }

   if( classp(_family_name) && sizeof(_family_name) == 5 ) {
       frog = new(class family_information);
       frog->adjectives = _family_name->adjectives;
       frog->id = _family_name->id;
       frog->cur_title = _family_name->cur_title;
       frog->name = _family_name->name;
       frog->titles = _family_name->titles;
       frog->clubs = ({ });
       _family_name = frog;
   }

   if( _family_name && _family_name->name ) {
       if( !CLUB_HANDLER->is_family(_family_name->name) ||
           !CLUB_HANDLER->is_member_of(_family_name->name, query_name() ) ) {
           _family_name->name = 0;
       }
   }

   if( _family_name && strlen(_family_name->cur_title) > 20 ) {
       tell_object( TO, "%^YELLOW%^Your title is too long!  "
           "Resetting.\n%^RESET%^");
       _family_name->cur_title = 0;
   }

   update_adjectives();
   remove_player_title("mad");

} /* check_family_name() */

/**
 * This method queries the current family name of the player.
 * @return the name of the family, 0 if none set
 * @see set_family_name()
 */
string query_family_name() {
   if( stringp(_family_name) )
       return (string)_family_name;

   if( _family_name )
       return _family_name->name;

   return 0;

} /* query_family_name() */

/**
 * This method returns the current title of the player.
 * @return the current title of the player, 0 if none set
 * @see query_family_name()
 */
string query_player_title() {
   if( _family_name && _family_name->cur_title )
       return CAP(_family_name->cur_title);
   return 0;
} /* query_player_title() */

/**
 * This method returns all the player titles as a nice list.
 * @return all the player titles
 */
string *query_all_player_titles() {
   if( !_family_name )
       _family_name = create_family_info();
   return _family_name->titles;
} /* query_all_player_titles() */

/**
 * This method sets the current title of the player.
 * @param title the new title to set
 * @return 1 if successful, 0 on failure
 * @see query_player_title()
 */
int set_player_title( string title ) {
   string* bits;

   if( !_family_name )
       _family_name = create_family_info();

   if( strlen(title) > 20 )
       return 0;

   // Allow them to setup combination titles.
   bits = ( title ? explode( title, " ") : ({ }) );

   if( sizeof( filter( bits, (: member_array(
       $1, _family_name->titles ) != -1 :) ) ) == sizeof(bits) &&
       sizeof(bits) <= 1 ) {
       _family_name->cur_title = ( title ? implode( map( bits,
           (: CAP($1) :) ), " ") : 0 );
       update_adjectives();
       return 1;
   }

   return 0;

} /* set_player_title() */

/**
 * This method adds a club to current list of known clubs on the
 * family.
 * @param club the club to add
 */
int add_player_club(string club) {
   class family_information frog;

   if( !club )
       return 0;

   club = CLUB_HANDLER->normalise_name(club);
   if( !CLUB_HANDLER->is_club(club) )
       return 0;

   if( !_family_name )
       _family_name = create_family_info();

   if( classp(_family_name) && sizeof(_family_name) == 5 ) {
       frog = new(class family_information);
       frog->adjectives = _family_name->adjectives;
       frog->id = _family_name->id;
       frog->cur_title = _family_name->cur_title;
       frog->name = _family_name->name;
       frog->titles = _family_name->titles;
       frog->clubs = ({ });
       _family_name = frog;
   }

   if( member_array( club, _family_name->clubs ) == -1 ) {
       _family_name->clubs += ({ club });
       return 1;
   }

   return 0;

} /* add_player_club() */

/**
 * This method removes a club from the list of know clubs.
 * @param club the club to remove
 */
void remove_player_club(string club) {
   if( !club )
       return;

   if( !_family_name )
       return;

   club = CLUB_HANDLER->normalise_name(club);
   _family_name->clubs -= ({ club });

} /* remove_player_club() */

/**
 * This method returns the current know clubs the player is a meber of
 * @return the array of known clubs
 */
string *query_player_clubs() {
   if( !_family_name )
       return ({ });
   return _family_name->clubs;
} /* query_player_clubs() */

/**
 * @ignore yes
 * Adjectives which are added because of the family.
 */
string *parse_command_id_list() {
   if( _family_name && _family_name->id )
       return ({ _family_name->id });
   return ({ });
} /* parse_command_id_list() */

/**
 * @ignore yes
 * Adjectives which are added because of the family.
 */
string *parse_command_plural_id_list() {
   if( _family_name && _family_name->id )
       return ({ pluralize(_family_name->id) });
   return ({ });
} /* parse_command_id_list() */

/**
 * @ignore yes
 * Adjectives which are added because of the family.
 */
string *parse_command_adjectiv_id_list() {
   if( _family_name )
       return _family_name->adjectives;
   return ({ });
} /* parse_command_id_list() */
