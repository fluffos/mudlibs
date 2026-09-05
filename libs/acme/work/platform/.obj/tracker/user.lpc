/**
 * The UserTracker keeps track of the game's users.
 *
 * @author devo@eotl
 * @alias UserTracker
 */
#pragma no_clone

inherit UserLib;

// ([ str user_id : UserInfo ])
mapping users;
// ([ str username : user_id ])
mapping usernames;
int user_counter;

void setup();
string new_user(string username);
string query_username(string user_id);
int set_last_session(string user_id, string session_id);
string query_last_session(string user_id);
mapping query_users(string username);
string generate_id();

/**
 * Setup the UserTracker.
 */
void setup() {
  users = ([ ]);
  usernames = ([ ]);
}

/**
 * Invoked to track a new user.
 * 
 * @param  username      the username of the new user
 * @return the newly created user id
 */
string new_user(string username) {
  string user_id = generate_id();
  users[user_id] = (<UserInfo> 
    id: user_id,
    username: username
  );
  if (!member(usernames, username)) {
    usernames[username] = ([ ]);
  }
  usernames[username] += ([ user_id ]);
  return user_id;
}

/**
 * Get the username for a given user id.
 * 
 * @param  user_id       the user being queried
 * @return the username of the specified user
 */
string query_username(string user_id) {
  if (!member(users, user_id)) {
    return 0;
  }
  return users[user_id]->username;
}

/**
 * Set a user's last (or current) session.
 * 
 * @param user_id    the user id of the user owning the session
 * @param session_id the session id of the user's new last session
 * @return 1 for success, 0 for failure
 */
int set_last_session(string user_id, string session_id) {
  if (!member(users, user_id)) {
    return 0;
  }
  // XXX validate session is owned by user?
  users[user_id]->last_session = session_id;
  return 1;
}

/**
 * Get a user's last (or current) session.
 * 
 * @param  user_id       the user id being queried
 * @return the session id of the user's last session, or 0 if never logged in
 */
string query_last_session(string user_id) {
  if (!member(users, user_id)) {
    return 0;
  }
  return users[user_id]->last_session;
}

/**
 * Get the users associated with a given username.
 * 
 * @param  username      the username to query
 * @return a zero-width mapping of the user ids sharing the username
 */
mapping query_users(string username) {
  if (!member(usernames, username)) {
    return 0;
  }
  return copy(usernames[username]);
}

/**
 * Generate a new, unique user id.
 * 
 * @return the new user id
 */
string generate_id() {
  return sprintf("%s#%d", program_name(THISO), ++user_counter);
}

/**
 * Constructor.
 */
void create() {
  setup();
}
