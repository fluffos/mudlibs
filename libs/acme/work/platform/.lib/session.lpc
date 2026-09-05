/**
 * Utility library for tracking sessions.
 *
 * @author devo@eotl
 * @alias SessionLib
 */
#pragma no_clone
#include <session.h>

struct ConnectedSessionInfo {
  string connection;
  int connect_time;
  int disconnect_time;
};

struct SessionInfo {
  string id;
  object avatar;
  string user;
  int state; // new, running, suspended, done
  int create_time;
  int transition_time;
  int invisible;
  mapping subsessions;
  mapping supersessions;
  struct ConnectedSessionInfo *connections;
};

protected int is_active(string session_id);
protected int is_subsession(string session_id, string subsession_id);

/**
 * Test whether a session is "active", e.g. the session state is "running" or
 * "suspended".
 * 
 * @param  session_id    the session being queried
 * @return 1 if the session is active, otherwise 0
 */
protected int is_active(string session_id) {
  return member(([ SESSION_STATE_RUNNING, SESSION_STATE_SUSPENDED ]), 
                SessionTracker->query_state(session_id)); 
}

/**
 * Test whether a session is a subsession of another.
 * 
 * @param  session_id    the parent session
 * @param  subsession_id the potential subsession
 * @return 1 if second arg is a subsession of the first, otherwise 0
 */
protected int is_subsession(string session_id, string subsession_id) {
  mapping subsessions = SessionTracker->get_subsessions(session_id);
  if (subsessions) {
    return member(subsessions, subsession_id);
  }
  return 0;
}
