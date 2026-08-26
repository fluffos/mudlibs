
#include <broadcaster.h>
#include <command.h>
#include <group_handler.h>

// Magic numbers for messages.
#define BROADCASTER_NAME     0
#define MESSAGE              1
#define DATA                 0
#define TIME                 1
#define TO_BROADCASTER       0
#define TO_OTHERS            1

inherit "/std/effect_shadow";

int _time_joined;
string _group, _parsed_prefix;
object _player, *_assisting, *_assisters, *_preparing_to_attack;

int add_assister( object member );
int remove_assister( object member );
void rebuild_parsed_prefix();

/** @ignore yes */
object attach_to_player( object p, int i ) {

   _player = p;
   _time_joined = time();

   _assisting = ({ });
   _assisters = ({ });
   _preparing_to_attack = ({ });

   return ::attach_to_player( p, i );

} /* attach_to_player() */

/** @ignore yes */
void event_quit( object me ) {
    object tmp;

    tmp = _player; // Store it locally.
    GROUP->remove_member( _group, _player );
    tmp->event_quit( me );

} /* event_quit() */

/** @ignore yes */
string query_group() { return _group; }

// This function is called always when a player receives
// membership to a group.  Whether it's a completely new
// group, or the new name of a renamed group.
void group_membership_added( string group ) {
    _group = group;
    rebuild_parsed_prefix();
} /* group_membership_added() */

/** @ignore yes */
void group_membership_removed() { remove_this_effect(); }

/** @ignore yes */
void rebuild_parsed_prefix() {

   string channel_name;

   tell_creator( _player, "[DEBUG]: Rebuilding channel prefix.\n");

   if( sizeof( _group ) <= GROUP_CHANNEL_MAX_CHARS ||
       GROUP_CHANNEL_MAX_CHARS <= 3 ) {
       channel_name = _group;
   } else {
       channel_name = _group[ 0..( GROUP_CHANNEL_MAX_CHARS - 4 ) ];
       channel_name += "...";
   }

   _parsed_prefix = GROUP_NOTIFY_PREFIX;
   _parsed_prefix = replace( _parsed_prefix,
      ({
         "$channel$", channel_name,
         "$colour$", _player->colour_event( GROUP_COLOUR_EVENT, "" )
      }) );

} /* rebuild_parsed_prefix() */

/** @ignore yes */
string query_parsed_prefix() { return _parsed_prefix; }

// Group members are visible to the group's leader.
int query_visible( object looker ) {
   string looker_group;

   // Safe guard for creators.
   if( _player->query_invis() && !looker->query_property("test character") )
       return _player->query_visible( looker );

   looker_group = looker->query_group();

   // If I'm a member of the looker's group, and he's using a group
   // command, then I'm visible to him.
   if( looker != _player && query_verb() == "group" &&
       GROUP->is_member( looker_group, _player ) )
       return 1;

   // Else return default.
   return _player->query_visible( looker );

} /* query_visible() */

void set_my_colours( string event, string colour ) {
   _player->set_my_colours( event, colour );
   if( event == GROUP_COLOUR_EVENT )
       rebuild_parsed_prefix();
} /* set_my_colours() */

int attack_by( object attacker ) {
   object assists_me;
   int delay;
   int retval;

   retval = player->attack_by( attacker );

   if( !retval )
       return retval;

   _assisters -= ({ 0 });

   foreach( assists_me in _assisters ) {
      // He's already fighting the attacker.
      if( member_array( attacker, assists_me->query_attacker_list() ) != -1 )
          continue;

      // He's not in my group.
      if( !GROUP->is_member( _group, assists_me ) ) {
          remove_assister( assists_me );
          continue;
      }

      // He's not in the same room.
      if( ENV( assists_me ) != ENV( _player ) )
          continue;

      if( pk_check( assists_me, attacker ) )
          continue;

      delay = 16 - sqrt( assists_me->query_skill_bonus("general.perception") );
      delay -= random( 3 );

      if( delay < 1 )
          delay = 1;

      delay = delay * sizeof( assists_me->query_assisting() );

      tell_creator( assists_me, "(DEBUG) Moving in to assist %s "
         "fighting %s in %i seconds.\n", _player->query_cap_name(),
         file_name( attacker ), delay );

      assists_me->commence_assist( _player, attacker, delay );

   }

   return retval;

} /* attack_by() */

void commence_assist( object person_to_help, object target_to_attack,
                      int delay ) {

   if( member_array( target_to_attack, _preparing_to_attack ) != -1 )
       return;

   _preparing_to_attack += ({ target_to_attack });

   call_out("assist_member", delay, target_to_attack, person_to_help );

} /* commence_assist() */

void assist_member( object attacker, object assisting ) {
   object *my_attacker_list, *his_attacker_list;

   _preparing_to_attack -= ({ attacker, 0 });

   if( !assisting || !attacker )
       return;

   my_attacker_list = _player->query_attacker_list();
   his_attacker_list = assisting->query_attacker_list();

   // I'm already fighting this guy, or at least
   // preparing to fight.
   if( member_array( attacker, my_attacker_list ) != -1 )
       return;

   // He's no longer fighting this guy.
   if( member_array( attacker, his_attacker_list ) == -1 )
       return;

   if( attacker == _player || assisting == _player ||
       ENV( attacker ) != ENV( _player ) )
       return;

    // We're not assisting them any more.
    if( member_array( assisting, _assisting ) == -1 )
        return;

   if( _player->attack_ob( attacker ) ) {
       if( !sizeof( my_attacker_list | _preparing_to_attack ) ) {
           _player->add_message("Noting the intentions of "+
               attacker->the_short()+", you move in to assist "+
               assisting->the_short()+".\n", ({ }) );
           return;
       }

       _player->add_message("You note the intentions of "+
           attacker->the_short()+" and prepare to attack "+
           attacker->HIM+" as well.\n", ({ }) );
   }

} /* assist_member() */

int add_assister( object member ) {
   _assisters -= ({ 0 });
   if( member_array( member, _assisters ) != -1 )
       return 0;
   _assisters += ({ member });
   member->add_assisting( _player );
   return 1;
} /* add_assister() */

void add_assisting( object member ) {
   _assisting -= ({ 0 });
   if( member_array( member, _assisting ) != -1 )
       return;
   _assisting += ({ member });
} /* add_assisting() */

int remove_assister( object member ) {
   _assisters -= ({ 0 });
   if( member_array( member, _assisters ) == -1 )
       return 0;
   _assisters -= ({ member });
   member->remove_assisting( _player );
   return 1;
} /* remove_assister() */

void remove_assisting( object member ) {
   _assisting -= ({ 0 });
   _assisting -= ({ member });
} /* remove_assisting() */

object *query_assisting() {
   _assisting -= ({ 0 });
   return _assisting;
} /* query_assisting() */

object *query_assisters() {
   _assisters -= ({ 0 });
   return _assisters;
} /* query_assisters() */

void event_channel_message( object broadcaster, string channel, mixed data ) {
   mixed message;
   string msg, colour;

   message = data[ 0 ];

   if( channel != "group_"+_group ) {
       call_out( (: remove_this_effect() :), 1 );
       return;
   }

   if( !GROUP->is_member( _group, _player ) ) {
       call_out( (: remove_this_effect() :), 1 );
       return;
   }

   colour = _player->colour_event( GROUP_COLOUR_EVENT, "" );

   msg = "";

   if( stringp( message ) ) {
       msg += message;
   } else if( arrayp( message ) ) {
       if( broadcaster == _player ) {
           if( message[ TO_BROADCASTER ] ) {
               msg += message[ TO_BROADCASTER ];
           } else {
               return;
           }
       } else if( message[ TO_OTHERS ] ) {
           msg += message[ TO_OTHERS ];
       } else {
           return;
       }
   }

   msg += "\n";
   msg = replace( msg, ({ "%^RESET%^", ( "%^RESET%^" + colour ),
                          "\n", "%^RESET%^\n"}) );

   msg = _parsed_prefix + colour + msg;

   tell_object( _player, msg );

} /* event_channel_message() */

void display_group_history() {
   int indent_a, indent_b;
   mixed *bit, *history;
   string whole, message, prefix, suffix;

   /* This is a convoluted function because of the hack-job I
    * did with the message structure.  Basically, this is
    * what one message consists of:
    *    bit =
    *    ({
    *       [0] broadcaster's name (capitalized),
    *       [1] ({
    *             [0] either array: ({ msg_to_broadcaster, msg_to_rest }) or
    *               msg_to_all,
    *             [1] time() when the broadcast was made
    *           })
    *    })
    */

   if( !GROUP->is_member( _group, _player ) ) {
       call_out( (: remove_this_effect() :), 0 );
       return;
   }

   history = BROADCASTER->query_channel_history( "group_" + _group );

   if( !sizeof( history ) ) {
       tell_object( this_player(), "Nothing has been said on your "
           "group's channel.\n" );
       return;
   }

   if( TP != _player ) {
       tell_object( TP, "Shame on you.\n");
       return;
   }

   prefix = _parsed_prefix;

   // This is a bit of a hack, but I don't feel like rewriting
   // the messaging system.  And it's not that ugly.
   sscanf( GROUP_NOTIFY_PREFIX, "$I$+%d,+%d=", indent_a, indent_b );
   suffix = "$I$-" + indent_a + ",-" + indent_b + "=\n";

   whole = "";

   foreach( bit in history ) {
      if( bit[ MESSAGE ][ TIME ] < _time_joined ) {
          // The message was broadcasted before this member
          // joined the group.  We skip it.
          continue;
      }

      // message = "** " + ctime( bit[ MESSAGE ][ TIME ] ) + " **:\n";
      message = ctime(bit[MESSAGE][TIME])[11..18];
      message += prefix;

      if( bit[ MESSAGE ][ DATA ] && stringp( bit[ MESSAGE ][ DATA ] ) ) {
          // The message is general to everyone.
          message += bit[ MESSAGE ][ DATA ];
          message += "$I$-5,-0=\n";
          whole += message;
          continue;
      }

      if( !arrayp( bit[ MESSAGE ][ DATA ] ) ) {
          // Something's gone wrong.
          continue;
      }

      // The message is an array divided to two parts: the first
      // element is the message the broadcaster received ("You..."),
      // the second is what everyone else received.
      if( bit[ BROADCASTER_NAME ] &&
          lower_case( bit[ BROADCASTER_NAME ] ) == _player->query_name() ) {
          // The broadcaster is the person listening.
          if( bit[ MESSAGE ][ DATA ][ TO_BROADCASTER ] ) {
              // We give him msg_to_broadcaster, the first.
              message += bit[ MESSAGE ][ DATA ][ TO_BROADCASTER ];
          }
      } else if( bit[ MESSAGE ][ DATA ][ TO_OTHERS ] ) {
          // The broadcaster is someone else.  We give him msg_to_rest.
          message += bit[ MESSAGE ][ DATA ][ TO_OTHERS ];
      }

      whole += message + suffix;

   }

   tell_object( TP, whole );

} /* display_channel_history() */

varargs int adjust_xp( int original_xp, int shared ) {
   int plvl, olvl, xp, share;
   object other, *others;

   if( original_xp < 0 || !shared )
       return ( int )player->adjust_xp( original_xp );

   others = GROUP->members_of( _group );

   if( !sizeof( others ) ) {
       call_out( (: remove_this_effect() :), 1 );
       return ( int )player->adjust_xp( original_xp );
   }

   if( sizeof( others ) == 1 )
       return ( int )player->adjust_xp( original_xp );

   // the more people in the team the smaller the shared Xp.
   xp = ( original_xp * 2 ) / sizeof(others);

   plvl = (int)player->query_level() / 2;

   foreach( other in others - ({ _player }) ) {
       if( !objectp( other ) )
           continue;

       if( ENV( other ) != ENV( _player ) )
           continue;

       olvl = (int)other->query_level();

       if( olvl <= plvl && plvl ) {
           share = ( xp * ( 1 + ( 99 * olvl ) / plvl ) ) / 100;
       } else {
           share = xp;
       }

       tell_creator( _player, "%s's share: %i\n", other->query_name(),
           share );

       other->adjust_xp( share, 0 );

   }

   tell_creator( _player, "%s's share: %i\n", _player->query_name(),
      original_xp );

   return ( int )player->adjust_xp( original_xp );

} /* adjust_xp() */

/**
 * This bit coded completely by Ceres.  Or was it Deutha?  In
 * any case, thanks to them.
 */
varargs int add_skill_level( string skill, int lvl, mixed exp ) {
   int diff_0, diff_1, diff, width_0, width, ret;
   object other, *others;

   ret = _player->add_skill_level( skill, lvl, exp );

   if( !ret ) {
        // If they didn't actually get an advance due to hitting a limit or
        // whatever then don't give their team an advance either.
       return ret;
   }

   // Not sharing already shared TMs, TMs from contemplate, skill
   // level advancements from 'advance', perception and points TMs.
   if( objectp( exp ) && base_name( exp ) == base_name( TO ) ||
       ( PO && file_name( PO ) == CONTEMPLATE ) || lvl != 1 ||
       intp( exp ) || skill == "general.perception" ||
       ( skill[ <7.. ] == ".points" ) )
       return ret;

   if( !_group ) {
       // Something's messed up.
       call_out( (: remove_this_effect() :), 1 );
       return ret;
   }

   others = (object *)GROUP->members_of( _group );
   others -= ({ 0 });

   if( !sizeof( others ) ) {
       // Something's REALLY messed up.
       call_out( (: remove_this_effect() :), 1 );
       return ret;
   }

   others -= ({ _player });

   if( !sizeof( others ) ) {
       // He's soloing.
       return ret;
   }

   diff_0 = (int)_player->query_skill_bonus( skill );
   diff_1 = (int)_player->query_skill( skill );
   width_0 = (int)_player->stat_modify( 25 * 25, skill );

   foreach ( other in others ) {
      if( !objectp( other ) )
          continue;

      if( ENV( other ) != ENV( _player ) )
          continue;

      if( diff_0 - (int)other->query_skill_bonus( skill ) >
          diff_1 - (int)other->query_skill( skill ) ) {
          diff = diff_0 - (int)other->query_skill_bonus( skill );
      } else {
          diff = diff_1 - (int)other->query_skill( skill );
      }

      width = (int)other->stat_modify( width_0, skill );

      if( random( width + diff * diff +
          sqrt( other->query_skill( skill ) ) ) < ( width / 2 ) &&
          other->add_skill_level( skill, lvl, TO ) ) {
          tell_object( other, "%^YELLOW%^By watching "+
              (string)_player->the_short()+", you feel you have learnt "
              "something.%^RESET%^\n");
      }
   }

   return 1;

} /* add_skill_level() */
