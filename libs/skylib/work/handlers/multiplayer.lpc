/**
 * Keeps track of the marked multi players.
 * Called by the login handler, checking people against a list of
 * previous multiplayers, and if they are on the list, check if
 * they are already on.
 * <pre><code>
 * vars are:
 *  string *gits: an array of names of suspected multiplayers
 *  string *denied_parcels: an array of names of multiplayers prevented from
 *                          using the parcel system for sending parcels
 *  mapping allowed: the keys are the names of verified non-multiplayers,
 *                   the values are the names of people they are allowed to
 *                   play with.
 * </pre></code>
 */

#include <login_handler.h>
#include <playerinfo.h>

#define SAVE_FILE   "/save/multiplayer"

string *gits;
string *denied_parcels;
mapping allowed;

protected void create() {
  string git, denied_parcel, user;
  int changed = 0;

  gits = ({ });
  denied_parcels = ({ });
  allowed = ([ ]);
  seteuid(master()->creator_file(file_name()));
  if (file_size(SAVE_FILE + ".o") > 0) {
    unguarded((: restore_object, SAVE_FILE, 1 :));
  }
  foreach (git in gits) {
    if (!PLAYER_HANDLER->test_user(git)) {
      gits -= ({ git });
      changed = 1;
    }
  }
  foreach (denied_parcel in denied_parcels) {
    if (!PLAYER_HANDLER->test_user(denied_parcel)) {
      denied_parcels -= ({ denied_parcel });
      changed = 1;
    }
  }
  foreach (user in keys(allowed)) {
    if (!PLAYER_HANDLER->test_user(user)) {
      map_delete(allowed, user);
      changed = 1;
    }
  }
  if (changed) {
    unguarded((: save_object, SAVE_FILE :));
  }
} /* create() */

private void save_me() {
  unguarded((: save_object, SAVE_FILE :));
}

/**
 * Called by the login handler.  Checks to see if one of the
 * other multi players are on and sends out an inform if they
 * logged on from the same ip address as someone else.
 * @param p_name the name being checked
 * @param type the type of login call
 * @see /handlers/login_handler.c
 */
void entering(string p_name, string type) {
  string git, ip, *multis, mpmess;
  object tp;

  if ((type != LOGIN) || (member_array(p_name, gits) == -1)) {
    return;
  }
  multis = ({ });
  ip = query_ip_number(find_player(p_name));
  foreach (git in gits - ({ p_name })) {
    if (find_player(git) && (ip == query_ip_number(find_player(git)))) {
      multis += ({ capitalize(git) });
    }
  }
  if (sizeof(multis)) {
    tp = find_player(p_name);
    if (tp->query_property("read multiplay") == 1 ||
                                tp->query_property("Accepted Terms") == 1) {
      user_event("inform", capitalize(p_name) +" logged on from " +
                 query_ip_name(find_player(p_name)) +
                 " at the same time as " +
                 query_multiple_short(multis)+".  They have been "
                 "previously warned.", "multiplayer");
    } else {
      tp = find_player(p_name);
      user_event("inform", capitalize(p_name) +" logged on from " +
                 query_ip_name(find_player(p_name)) +
                 " at the same time as "+
                 query_multiple_short(multis), "multiplayer");
      tp->add_property("read multiplay", 1);
    }
    mpmess = p_name +" logged on from "+
      query_ip_name(find_player(p_name)) +
      " together with "+ query_multiple_short(multis) + "\n";
    log_file("MULTIPLAYERS", ctime(time()) + ": " + mpmess);

    mpmess = "Logged on from " + query_ip_name(find_player(p_name)) +
      " together with " + query_multiple_short(multis) + ".\n";
    PLAYERINFO_HANDLER->add_entry(this_object(), p_name, "multiplay", mpmess);
  }
} /* entering() */

/**
 * Called by the player object to see if a logon inform should be given
 * about duplicate players from the same IP address.
 * @param user the player being checked
 * @param others the others logged on from the same IP
 * @return array of not allowed dups
 */
string *check_allowed(object user, mixed *others) {
  string *names, *not_alts;
        mixed tmp;

        names = ({ });
        foreach(tmp in others)
                if(objectp(tmp))
                        names += ({ tmp->query_name() });
          else
                        names += ({ tmp });

  /* If nothing is known about them default to not allowed */
  if (!(not_alts = allowed[user->query_name()])) {
    return names;
  }
  not_alts = (names & not_alts);
  if (sizeof(names) != sizeof(not_alts)) {
    return (names - not_alts);
  } else {
    return ({ });
  }
} /* check_allowed() */

/**
 * Adds a player to the multiplayer list.
 * @param git the name of the suspected multiplayer
 * @return 0 if they are not a user, 1 if they are
 */
int add_git(string git) {
  if (member_array(git, gits) != -1) {
    gits -= ({ git });
  }
  if (!PLAYER_HANDLER->test_user(git)) {
    return 0;
  }
  gits += ({ git });
  call_out((: save_me :), 1);
  PLAYERINFO_HANDLER->add_entry(this_player(), git, "multiplay",
                                "Added to multiplayer handler.\n");
  return 1;
} /* add_git() */

/**
 * Remove a person from the multiplayer list.
 * @param git the name of the player to remove
 * @return 0 if they are not in the list, 1 if they are
 */
int delete_git(string git) {
  if (member_array(git, gits) == -1)
    return 0;
  gits -= ({ git });
  call_out((: save_me :), 1);
  PLAYERINFO_HANDLER->add_entry(this_player(), git, "multiplay",
                                "Deleted from multiplayer handler.\n");
  return 1;
} /* delete_git() */

/**
 * Returns the current list of suspected multi players
 * @return the list of multi players
 */
string *query_gits() {
  return copy(gits);
} /* query_gits() */

/**
 * Adds a player to the allowed multi IP list.
 * @param user the name of the player
 * @param other the name of another user which is not an alt
 * @return 0 if they are not a user, 1 if they are
 */
int add_allowed(string user, string other) {
  int oldsize, changed;

  if (!(PLAYER_HANDLER->test_user(user) && PLAYER_HANDLER->test_user(other))) {
    return 0;
  }
  if (undefinedp(allowed[user])) {
    allowed[user] = ({ other });
  } else {
    oldsize = sizeof(allowed[user]);
    allowed[user] |= ({ other });
  }
  if (!oldsize || (oldsize != sizeof(allowed[user]))) {
    changed = 1;
    PLAYERINFO_HANDLER->add_entry(this_player(), user, "multiplay",
                                  "Added to multiplayer handler as allowed "
                                  "together with " + other + ".\n");
  }

  if (undefinedp(allowed[other])) {
    allowed[other] = ({ user });
  } else {
    oldsize = sizeof(allowed[other]);
    allowed[other] |= ({ user });
  }
  if (!oldsize || (oldsize != sizeof(allowed[other]))) {
    changed = 1;
    PLAYERINFO_HANDLER->add_entry(this_player(), other, "multiplay",
                                  "Added to multiplayer handler as allowed "
                                  "together with " + user + ".\n");
  }
  if (changed) {
    call_out((: save_me :), 1);
  }
  return 1;
} /* add_allowed() */

/**
 * Remove a person from allowed multi IP list.
 * @param user the name of the player to remove
 * @return 0 if they are not in the list, 1 if they are
 */
int delete_allowed(string user) {
  if (undefinedp(allowed[user]))
    return 0;
  map_delete(allowed, user);
  call_out((: save_me :), 1);
  PLAYERINFO_HANDLER->add_entry(this_player(), user, "multiplay",
                                "Deleted from multiplayer handler "
                                "(allowed).\n");
  return 1;
} /* delete_allowed() */

/**
 * Returns the current allowed multi player IP list
 * @return the list of allowed multi players
 */
mapping query_allowed() {
  return copy(keys(allowed));
} /* query_allowed() */

/**
 * Adds a user to the list of users not allowed to use the parcel system
 * Only Lords are allowed to add a user to this array
 * @param user the name of the player
 */
int add_denied_parcel(string user) {
  if (!lordp(geteuid(previous_object()))) {
    write("You do not have permission to add a user to this list.\n");
    return 0;
  }
  if (member_array( user, denied_parcels) != -1) {
    denied_parcels -= ({ user });
  }
  if (!PLAYER_HANDLER->test_user(user)) {
    return 0;
  }
  denied_parcels += ({ lower_case(user) });
  call_out((: save_me :), 1);
  PLAYERINFO_HANDLER->add_entry(this_player(), user, "multiplay",
                            "Denied the use of the parcel system.\n");
  return 1;
} /* add_denied_parcel() */

/**
 * Removes a user from the list of users not allowed to use the parcel system
 * Only Lords are allowed to remove a user from this array
 * @param user the name of the player
 * @return 0 if they are not in the list, 1 if they are
 */
int remove_denied_parcel(string user) {
  if (!lordp(geteuid(previous_object()))) {
    write("You do not have permission to remove a user to this list.\n");
    return 0;
  }
  if (member_array(user, denied_parcels) == -1)
    return 0;
  denied_parcels -= ({ user });
  call_out((: save_me :), 1);
  PLAYERINFO_HANDLER->add_entry(this_player(), user, "multiplay",
                           "Allowed the use of the parcel system.\n");
  return 1;
} /* remove_denied_parcel() */

/**
 * Checks user against the parcels array
 * @param user the name of the player
 * @returns 0 if they are not in the list, 1 if they are
 */
int member_denied_parcel( string user ) {
  if (member_array(user, denied_parcels) == -1)
    return 0;
  return 1;
} /* member_denied_parcel() */

/**
 * Returns the current list of players denied use of the parcel system.
 * @return the list of denied parcel users
 */
string *query_denied_parcels() {
  return copy(denied_parcels);
} /* query_denied_parcels() */

/** @ignore yes */
varargs void mark_log(string user, string comment) {
  if (!comment) {
    log_file("MULTIPLAYERS", ctime(time())
             + " " + user
             + " Previous log entries handled.\n");
    PLAYERINFO_HANDLER->add_entry(this_player(), user, "multiplay",
                                  "Previous log entries handled.\n");
  } else {
    log_file("MULTIPLAYERS", ctime(time())
             + " " + user
             + ": " + comment + "\n" );
    PLAYERINFO_HANDLER->add_entry(this_player(), user, "multiplay", comment);
  }
} /* mark_log() */

/** @ignore yes */
string query_name() {
  return "Multiplayer handler";
}
