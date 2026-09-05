/**
 * The SessionTracker monitors user login sessions.
 * 
 * @alias SessionTracker
 */
#pragma no_clone
#include <session.h>

private inherit SessionLib;

// program_id#session_count
// ([ string session_id : SessionInfo session ])
private mapping sessions;
private int session_counter;

public void setup();
public string new_session(string user_id, string supersession_id);
public string query_user(string session_id);
public int is_connected(string session_id);
public int connect_session(string session_id, string connection);
public int disconnect_session(string session_id);
public int resume_session(string session_id);
public int set_avatar(string session_id, object avatar);
public object query_avatar(string session_id);
protected string generate_id();

/**
 * Setup the SessionTracker.
 */
public void setup() {
  sessions = ([ ]);
}

/**
 * Invoked to create a new session.
 * 
 * @param  user_id         the user id who owns the session
 * @param  supersession_id the new session's parent session
 * @return the newly created session id
 */
public string new_session(string user_id, string supersession_id) {
  object logger = LoggerFactory->get_logger(THISO);
  if (supersession_id && !member(sessions, supersession_id)) {
    logger->warn("unable to create session: supersession %O doesn't exist",
                 supersession_id);
    return 0;
  }
  string id = generate_id();
  sessions[id] = (<SessionInfo>
    id: id,
    user: user_id,
    state: SESSION_STATE_NEW,
    create_time: time(),
    subsessions: ([ ]),
    supersessions: ([ ]),
    connections: ({ })
  );
  if (supersession_id) {
    sessions[id]->supersessions += ([ supersession_id ]);
    sessions[supersession_id]->subsessions += ([ id ]);
  }
  return id;
}

/**
 * Get the user who owns a given session.
 * 
 * @param  session_id    the session being queried
 * @return the user id who owns the session
 */
public string query_user(string session_id) {
  if (member(sessions, session_id)) {
    return sessions[session_id]->user;
  }
  return 0;
}

/**
 * Query whether a session is connected or not.
 * 
 * @param  session_id    the session id being queried
 * @return 1 if the session is connected, otherwise 0
 */
public int is_connected(string session_id) {
  if (!member(sessions, session_id)) {
    return 0;
  }
  struct SessionInfo session = sessions[session_id];
  return (sizeof(session->connections) 
          && (session->connections[<1]->disconnect_time));
}

/**
 * Associate a session with a connection, making it a "connected" session.
 * 
 * @param  session_id    the session being connected
 * @param  connection    the connection id of the connection using the session
 * @return 1 for success, 0 for failure
 */
public int connect_session(string session_id, string connection) {
  if (!member(sessions, session_id)) {
    return 0;
  }
  disconnect_session(session_id);
  struct SessionInfo session = sessions[session_id];
  session->connections += ({ (<ConnectedSessionInfo>
    connection: connection,
    connect_time: time()
  ) });
  return 1;
}

/**
 * Disconnect a session.
 * 
 * @param  session_id    the session to disconnect
 * @return 1 for success, 0 for failure
 */
public int disconnect_session(string session_id) {
  if (!member(sessions, session_id)) {
    return 0;
  }
  if (!is_connected(session_id)) {
    return 0;
  }
  struct SessionInfo session = sessions[session_id];
  session->connections[<1]->disconnect_time = time();
  return 1;
}

/**
 * Start or resume a session by changing its session state to "running". 
 * Sessions with a state of "done" may not be resumed.
 * 
 * @param  session_id    the session to resume
 * @return 1 for success, 0 for failure
 */
public int resume_session(string session_id) {
  if (!member(sessions, session_id)) {
    return 0;
  }
  struct SessionInfo session = sessions[session_id];
  int previous = session->state;
  if (previous == SESSION_STATE_DONE) {
    return 0;
  }
  session->state = SESSION_STATE_RUNNING;
  return previous;
}

/**
 * Associate an avatar object with a given session. Avatars can implement the
 * CommandGiverMixin and SensorMixin to share interactivity between sessions.
 * 
 * @param session_id the session owning the avatar
 * @param avatar     the avatar for the session
 * @return 1 for success, 0 for failure
 */
public int set_avatar(string session_id, object avatar) {
  if (!member(sessions, session_id)) {
    return 0;
  }
  sessions[session_id]->avatar = avatar;
  return 1;
}

/**
 * Get the avatar for a given session.
 * 
 * @param  session_id    the session id being queried
 * @return the session's avatar object
 */
public object query_avatar(string session_id) {
  if (!member(sessions, session_id)) {
    return 0;
  }
  return sessions[session_id]->avatar;
}

/**
 * Generate a new session id.
 * 
 * @return the new, unique session id
 */
protected string generate_id() {
  return sprintf("%s#%d", 
                 ObjectTracker->query_object_id(THISO), ++session_counter);
}

/**
 * Constructor.
 */
public void create() {
  setup();
}