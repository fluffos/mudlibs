/**
 * @author Ringo
 * @started 1st August 1999
 */
#include <player_shop.h>

inherit ARMOUR_OBJ;

int do_badge( string );
int do_chat( string );

string _office, 
       _title,
       _channel,
       _owner;

void setup()
{
   set_name( "badge" );
   set_short( "employee badge" );
   add_adjective( "employee" );
   set_main_plural( "employee badges" );
   set_weight( 1 );
   set_value( 0 );
   set_type( "badge" );
   setup_armour( 640 );
   set_damage_chance( 5 );
   set_wear_remove_func( file_name( this_object() ),
     "wear_remove_badge" );
   add_property( "no recycling", 1 );
   add_extra_look( this_object() );
   if ( !query_property( "office" ) || !query_property( "owner" ) )
   {
      return;
   }
   _office = query_property( "office" );
   _owner = query_property( "owner" );
   _title = _office->shop_very_short();
   _channel = _office->query_channel();
   set_long( "This is a small tin badge which marks " +
     capitalize( _owner ) + " as an employee of "+
     _office->query_shop_name()+ ", "+ _office->query_place()+ ".\n" );
   add_adjective( _channel );
}
/* setup() */


/** @ignore yes */
private void get_properties()
{
   if ( !query_property( "office" ) || !query_property( "owner" ) )
   {
      return;
   }
   _office = query_property( "office" );
   _owner = query_property( "owner" );
   _title = _office->shop_very_short();
   _channel = _office->query_channel();
}
/* get_properties() */


/** @ignore yes */
void init()
{

   if ( !_office || !_owner )
   {
      get_properties();
      set_long( "This is a small tin badge which marks " +
        capitalize( _owner ) + " as an employee of "+
        _office->query_shop_name()+ ", "+ _office->query_place()+ ".\n" );
      add_adjective( _channel );
   }
   if ( !_office->query_employee( TP->query_name() ) &&
     !_office->query_retired( TP->query_name() ) &&
     !creatorp(TP) )
   {
      return;
   }
   add_command( "badge", ({ "help", "list ["+ _channel+ "]",
     "history ["+ _channel+ "]" }), (: do_badge($5) :) );
   add_command( _channel, "<string'text'>", (: do_chat($4[0]) :) );
}
/* init() */


/** @ignore yes */
void set_props( string path, string owner )
{
   if ( !path || path == "" )
   {
      return;
   }
   set_long( "This is a small tin badge which marks " +
     capitalize( owner ) + " as an employee of "+
     path->query_shop_name()+ ", "+ path->query_place()+ ".\n" );
   add_property( "office", path );
   add_property( "owner", owner );
   _office = path;
   _owner = owner;
   _title = _office->shop_very_short();
   _channel = _office->query_channel();
   add_adjective( _channel );
}
/* set_props() */


/** @ignore yes */
void wear_remove_badge( object thing )
{
   int level;
   string start;

   if ( !_office || !_owner )
   {
      get_properties();
   }
   if ( thing )
   {
      if ( !living( thing ) )
      {
         return;
      }
      level = ( _office->query_employee( thing->query_name() ) );

/* Once Tarnach's transferred over replace following line with
      if ( !level )
 */
      if ( !level || level == -1 )
      {
         if ( _office->query_retired( thing->query_name() ) )
         {
            start = "Retired manager of ";
         }
         else
         {
            thing->add_property( _channel+ "_on", 1 );
            return;
         }
      }
      else if ( level & MANAGER )
      {
         start = "Manager of ";
      }
      else if ( level & SUPERVISOR )
      {
         start = "Supervisor of ";
      }
      else
      {
         start = "Employee of ";
      }
      thing->add_property( _channel+ "_on", 1 );
      thing->set_title( _title, start + _office->query_shop_name() );
      return;
   }
   thing = previous_object()->query_worn_by();
   if ( thing )
   {
      thing->remove_property( _channel+ "_on" );
      thing->remove_title( _title );
   }
}
/* wear_remove_badge() */


/** @ignore yes */
string extra_look( object thing )
{

   if ( !_office || !_owner )
   {
      get_properties();
   }
   if ( !_office->query_employee( TP->query_name() ) &&
     !_office->query_retired( TP->query_name() ) && !creatorp(TP) )
   {
      return "";
   }
   return "You can get a list of commands by typing \"badge help\"\n";
}
/* extra_look() */


/** @ignore yes */
int do_badge( string args )
{
   string result;
   mixed *hist;

   if ( !_office || !_owner )
   {
      get_properties();
   }
   add_succeeded_mess( "" );
   if ( args == "list ["+ _channel+ "]" )
   {
      tell_object( this_player(),
        "The following employees from "+ _office->query_shop_name()+
        " are logged on: \n\n" + _office->badge_list() );
   }
   else if ( args == "history ["+ _channel+ "]" )
   {
      tell_object( this_player(),
        "You ask the badge for the last few chats on the "+ _channel+ 
        " channel\n");
      hist = HISTORY->query_chat_history( lower_case( _channel ) );
      if ( !arrayp( hist ) || !sizeof( hist ) )
      {
         tell_object( this_player(),
           "The badge mutters that nothing has been said on this channel, "
           "or it is not being remembered.\n" );
         return 1;
      }
      result = "$P$"+ _channel+ " channel$P$\n";
      result += implode( map( hist, (: "$I$5=$C$" + $1[0] + $1[1] + 
            "%^RESET%^" :) ), "\n" ); 
      tell_object( this_player(), result );
   }
   else
   {
      result = sprintf( "Commands for this badge:\n\n   %s\n   badge list "
        "[%s]\n   badge history [%s]\n\nYou can also set your preferred "
        "chat colour using the \"colour shopchat <colour>\" command.\n",
        _channel, _channel, _channel );
      tell_object( this_player(), result );
   }
   return 1;
}
/* do_badge() */


/** @ignore yes */
void receive( string channel, string sender, string text )
{
   object owner;
   string *ignoring;

   if ( !_office || !_owner )
   {
      get_properties();
   }
   owner = environment( this_object() );
   if ( !owner || ( !living( owner ) ) )
   {
      return;
   }
   if ( !_office->query_employee( owner->query_name() ) &&
     !_office->query_retired( owner->query_name() ) &&
     !creatorp(owner) )
   {
      return;
   }
   ignoring = owner->query_property( "ignoring" );
   if ( ignoring && member_array( lower_case( sender ), ignoring ) != -1 )
   {
      return;
   }
   if ( channel != _channel || 
     !owner->query_property( _channel+ "_on" ) )
   {
      return;
   }
   text = "["+ lower_case( _channel )+ "] "+ sender +": "+ text;
  
   tell_object( owner, owner->colour_event( "shopchat", "%^CYAN%^") +
     "$I$5=$C$"+ text + "%^RESET%^\n" );
   return;
}
/* receive() */


/** @ignore yes */
int do_chat( string wisp )
{
   string sender;
   object *things;

   add_succeeded_mess( "" );
   if ( !_office || !_owner )
   {
      get_properties();
   }
   if ( !this_player()->query_property( _channel+ "_on" ) )
   {
      return notify_fail( "You are not wearing the " + _channel+
        " badge!\n" );
   }
   if ( this_player()->query_property( "gagged" ) )
   {
      return notify_fail( "You have been gagged!  You cannot chat until "
        "your gag is removed.  Perhaps you should talk to a creator about "
        "this.\n");
   }
   if ( !creatorp(TP) )
   {
      wisp = replace_string( wisp, "%^", "");
   }
   if ( !wisp || ( wisp == "" ) )
   {
      return notify_fail( "Chat what?\n" );
   }
   if ( environment( this_object() ) != this_player() )
   {
      return notify_fail( "You're too far from the badge to whisper into "
        "it.\n" );
   }
   tell_object( this_player(),  "You whisper into the badge.\n" );
   sender = this_player()->query_cap_name();
   if ( this_player()->query_invis() )
   {
      sender = "Someone";
   }
   wisp = replace( wisp, sprintf( "%c", 7 ), "!" );
   things = children( BADGE );
   things -= ({ this_object(), find_object( BADGE ) });
   things->receive( _channel ,sender, wisp );
   HISTORY->add_chat_history( _channel, sender +": ", wisp );
   return 1;
}
/* do_chat() */
