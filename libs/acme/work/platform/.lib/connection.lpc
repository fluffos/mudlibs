/**
 * Utility library for tracking connections.
 *
 * @author devo@eotl
 * @alias ConnectionLib
 */
#pragma no_clone
#include <capability.h>
#include <command_giver.h>
#include <connection.h>

private inherit CapabilityLib;

struct ConnectionInfo {
  string id;
  string terminal;
  int terminal_width, terminal_height;
  int *ttyloc;
  int connect_time;
  int disconnect_time;
};

struct ConnectionState {
  object interactive;
  int exec_time;
  mapping negotiation_pending;
  int naws_last;
  struct ConnectionInfo info;
  string session;
};

protected int connect_session(object who, string session);
protected int query_screen_width(object ob);
protected int query_screen_length(object ob);
protected varargs string query_terminal_type(object ob);
protected varargs void restore_prompt(object ob);

/**
 * Connect an existing interactive object to a new session. This will exec them
 * into the session avatar and update their connection info accordingly. The
 * specified session will then become a "connected" session.
 * 
 * @param  who           an interactive object
 * @param  session       a session to connect them to
 * @return 1 for success, 0 for failure
 */
protected int connect_session(object who, string session) {
  object logger = LoggerFactory->get_logger(THISO);
  object avatar = SessionTracker->query_avatar(session);
  if (!avatar) {
    logger->debug("no avatar attached to session: %O %O", session, who);
    return 0;
  }
  if (!avatar->is_avatar()) {
    logger->debug("attempting to connect a non-avatar: %O %O", avatar, who);
    return 0;
  }
  if (!exec(avatar, who)) {
    logger->debug("exec failed: %O %O", avatar, who);
    return 0;
  }
  string connection = ConnectionTracker->query_connection(who);
  if (!ConnectionTracker->set_interactive(connection, avatar)) {
    logger->debug("failed to switch connection: %O %O", connection, avatar);
    return 0;
  }
  if (!SessionTracker->connect_session(session, connection)) {
    logger->debug("failed to connect session: %O %O", session, connection);
    return 0;
  }
  return 1;
}

/**
 * Get the screen width of a connected object.
 * 
 * @param  ob            the connected object, defaults to THISO
 * @return the screen width
 */
protected int query_screen_width(object ob) {
  if (!ob) {
    ob = THISO;
  }
  struct ConnectionInfo info = 
    ConnectionTracker->query_connection_info(
      ConnectionTracker->query_connection_id(ob)
    );
  int result = info->terminal_width;
  if (result <= 0) {
    result = DEFAULT_SCREEN_WIDTH;
  }
  return result;
}

/**
 * Get the screen length of a connected object.
 * 
 * @param  ob            the connected object, defaults to THISO
 * @return the screen length
 */
protected int query_screen_length(object ob) {
  if (!ob) {
    ob = THISO;
  }
  struct ConnectionInfo info = 
    ConnectionTracker->query_connection_info(
      ConnectionTracker->query_connection_id(ob)
    );
  int result = info->terminal_width;
  if (result <= 0) {
    result = DEFAULT_SCREEN_LENGTH;
  }
  return result;
}

/**
 * Get the terminal type of a connected object.
 * 
 * @param  ob            the connected object, defaults to THISO
 * @return the terminal type
 */
protected varargs string query_terminal_type(object ob) {
  if (!ob) {
    ob = THISO;
  }
  struct ConnectionInfo info = 
    ConnectionTracker->query_connection_info(
      ConnectionTracker->query_connection_id(ob)
    );
  if (info) {
    return info->terminal;
  }
  return 0;
}
