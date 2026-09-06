// Standard group npc; ie. npc that is one of npcs forming a group that
// fights together.
//
// Version 3.0, 04-jan-96 by Doomdark
// Earlier version by Val; some modifications by Chaotic.
//
// Last modifications 04-jan-96 by Doomdark
//
// NEW:
//
// - Now uses SSF. Remember to set _both_ messages; one the attacker gets,
//   and the one others in the room get. Both can and should be SSF strings.
// - Now adds attacker to the enemy list, even if can't attack him/her/it
//   right away; will attack when we get the chance!
// - Only calls for help, if there's at least one member of the group in
//   the same room. This only applies to the printing messages, though, so
//   if you want to code more intelligent tactics, you can mask "group_attacked",
//   which _will_ get called anyway.

#include <npc_defs.h>
#include <daemons.h>

#ifndef	EQUIPPED_GROUP_NPC
#include <npc.h>
#endif

// In case of equipped group npc, npc.h will be inheritted by equipped
// npc already.

string group;		// Name of the group we belong to.
mapping group_messages; // Customized messages printed when we are attacked.
object groupd;		// Group daemon; should enhance performance.

// Messages:
//	"ask_help_msg":	Message victim first says: something like
//			"XXX yells: Help me!" etc.
//	"can_help_msg":	Message other npcs say if they can give help,
//			something like "XXX says: Ok, let's kick some ass!".
//	"cant_help_msg": Message other npcs say if they can't give help,
//			(even though they're in the same room), because
//			they're fighting already. Something like
//			"XXX says: Sorry, I'm busy fighting myself!"
// Messages can and do use SSF, Stickmud String Format; check out
// SSF.doc for more info!
// Note that usually you do use 2 strings for each of these messages;
// one the (original) attacker gets, and one the others get. So, something
// like (this one also uses SSF):
//
// set_group_message("ask_help_msg",
//  "%<me.name>% points at you and yells: Help me against this creature!",
//  "%<me.name>% points at %<him.name>% and yells: Help me against this creature!"
// );
//
// Note:
//	More messages can and will be used later. If you can think of a
//	useful new message type, tell/mail me. -+ Doomdark +-

#define ASK_HELP    1
#define CAN_HELP    3
#define CANT_HELP   5

int
attacked_by(object attacker, int to_top, int flags)
{
    int res;
    // If to_top < 0, we're simply checking if we _can_ be attacked, not really
    // initiating an attack! -+ Doomdark +-
    if (is_fighting(attacker))
	return ::attacked_by(attacker, to_top, flags);
    res = ::attacked_by(attacker, to_top, flags);
    if (res && to_top >= 0 && group && attacker != this_object()) {
	if (groupd || (groupd = find_object(GROUP_D)))
	    groupd -> group_attacked(this_object(), attacker, group);
    }
    return res;
}

status
group_attacked(object victim, object attacker, object *members)
{
    mixed x;
    string s;
    int i;
    // Is this npc originally being attacked?
    if (victim == this_object()) {
	// Let's see if we're the only member of the group in this room. If so,
	// let's not waste our time calling for help!
	// (coders with time to spend on making perfect monsters; feel free to
	// mask this function, and call help from neighbouring rooms!)
	i = sizeof(members) - 1;
	while (i >= 0) {
	    if ((x = members[i]) && x != this_object() && present(members[i],
		environment()))
		break;
	    i--;
	}
	if (i < 0) return 0;
	// When we return 0, no further calls are done for other members of the
	// group. This is used, for example, to make things more efficient;
	// consider group of 100 NPCs scattered around an area... Usually it's
	// enough to call help only if there are other members in the same room,
	// and even then, only for those NPCs that are in the same room.

	if (!group_messages || !(x = group_messages["ask_help_msg", 0]))
	    s = sprintf("%s yells: Help, I'm being attacked!",
	      query_name());

	s = x;

	attacker->tell_me(s, 0, 0, this_object(), attacker, 0);

	if (!group_messages || !(x = group_messages["ask_help_msg", 1]))
	    ; // We'll use the one used above!

	x = s;

	if (s)
	    environment()->tell_here(s,
	      0, 0,
	      ({ attacker, this_object() }),
	      this_object(), attacker, 0);
	return 1;
	// When we return 1, help will be called!

	// If this wasn't the attacked npc, we'll check if we can help it!

    } else {

	// Doesn't really matter what we return if this was not npc first attacked...
	// But let's return 1 if help was given, and 0 otherwise. This may be useful
	// later on.
	// We can depend on both victim and attacker to be on the same room.
	// But, we might be elsewhere ourselves!
	if (environment() != environment(victim))
	    ;
	// Let's simply not respond to the call. This may change in future.

	else if (is_fighting() && !is_fighting(attacker)) {
	    if (!group_messages || !(s = group_messages["cant_help_msg", 0]))
		s = sprintf("%s yells: Sorry, but I'm fighting myself!",
		  query_name());

	    s = x;

	    if (s) attacker->tell_me(s, 0, 0, this_object(), attacker, 0);

	    if (!group_messages || !(x = group_messages["cant_help_msg", 1]))
		; // We'll use the one used above!

	    s = x;

	    if (s) environment()->tell_here(s, 0, 0,
		  ({ attacker, this_object() }),
		  this_object(), attacker, 0);

	    attack_object(attacker, 1); // So we'll attack him/her/it later!
	} else {
	    if (!group_messages || !(s = group_messages["can_help_msg", 0]))
		s = sprintf("%s yells: Sure, let's bash this shithead!",
		  query_name());

	    s = x;

	    if (s) attacker->tell_me(s, 0, 0, this_object(),
		  attacker, 0);

	    if (!group_messages || !(x = group_messages["can_help_msg", 1]))
		; // We'll use the one used above!

	    s = x;

	    if (s) environment()->tell_here(s, 0, 0,
		  ({ attacker, this_object() }),
		  this_object(), attacker, 0);

	    attack_object(attacker, 0);     // Will attack right away!
	    return 1;
	}
	return 0;
    }
}

// With this we "register" this npc to the global group daemon!
void
set_group(string str)
{
    if (groupd || (groupd = find_object(GROUP_D)) ||
      (GROUP_D->load() && (groupd = find_object(GROUP_D)))) {
	groupd -> add_to_group(group = str, this_object());
    } else throw("Error: Can't find /bin/daemons/groupd.c!\n");
}

// msg = name of the message we'll be adding; currently either
//  "ask_help_msg", "can_help_msg" or "cant_help_msg".
// text1 = message printed to the (original) attacker,
// text2 = message printed to others in the same room
varargs void
set_group_message(string msg, string text1, string text2)
{
    if (!group_messages) group_messages = m_allocate(1, 2);
    group_messages[msg, 0] = make_format_string(text1);
    if (text2) group_messages[msg, 1] = make_format_string(text2);
    else group_messages[msg, 1] = 0;
}
