/**
 * Utility library for dealing with users.
 * 
 * @author devo@eotl
 * @alias UserLib
 */
#pragma no_clone
#include <user.h>

private inherit FileLib;
private inherit ConnectionLib;
private inherit SessionLib;
private inherit FormatStringLib;

struct UserInfo {
  string id;
  string username;
  string last_session;
};

protected string user_dir(string username);
protected int user_exists(string username);
protected string passwd_file(string username);
protected string hash_passwd(string password);
protected string create_user(string username, string password);
protected int install_skeleton(string user_dir, string username);
protected int apply_template(string template_path, string username);
protected int save_password(string user_id, string password);
protected string attach_session(object interactive, string user_id);

/**
 * Get the user directory for a given username.
 * 
 * @param  username the username of directory owner
 * @return          the user dir
 */
protected string user_dir(string username) {
  return UserDir "/" + username;
}

/**
 * Test whether a user with a given name exists.
 * 
 * @param  username the username to test
 * @return          1 if the user exists, otherwise 0
 */
protected int user_exists(string username) {
  return file_exists(user_dir(username));
}

/**
 * Get the password file for a given username.
 * 
 * @param  username      the username
 * @return the user's password file
 */
protected string passwd_file(string username) {
  return user_dir(username) + PASSWD_FILE;
}

/**
 * Create a password hash.
 * 
 * @param  password      the plain text password
 * @return the hashed password
 */
protected string hash_passwd(string password) {
  return hash(PASSWD_HASH_METHOD, password, PASSWD_HASH_ITERATIONS);
}

/**
 * Create a new user with the provided username and password. This installs
 * the skeleton dir, registers the username with the user tracker, and saves
 * the password to the user's password file.
 * 
 * @param  username      the username
 * @param  password      the plain-text password
 * @return the new user id
 */
protected string create_user(string username, string password) {
  object logger = LoggerFactory->get_logger(THISO);

  string user_dir = user_dir(username);
  if (!install_skeleton(user_dir, username)) {
    logger->warn("unable to install skeleton user dir: %O", user_dir);
  }

  string user_id = UserTracker->new_user(username);

  if (!save_password(user_id, password)) {
    logger->warn("unable to save password for user: %O %O", user_id, username);
  }
  
  return user_id;
}

/**
 * Install the skeleton user directory to the specified user dir. This involves
 * copying the files and applying the templates.
 * 
 * @param  user_dir      the user dir to isntall to
 * @param  username      the username of the dir's owner
 * @return 1 for success, 0 for failure
 */
protected int install_skeleton(string user_dir, string username) {
  object logger = LoggerFactory->get_logger(THISO);
  if (file_exists(user_dir)) {
    return 0;
  }
  copy_tree(SkelDir, user_dir);
  if (!apply_template(user_dir + DOMAIN_TEMPLATE, username)) {
    logger->warn("unable to apply domain template: %O", user_dir);
  }
  if (!apply_template(user_dir + ZONE_TEMPLATE, username)) {
    logger->warn("unable to apply zone template: %O", user_dir);
  }
  return 1;
}

/**
 * Apply a skeleton template for a specified username.
 * 
 * @param  template_path the path of the template file
 * @param  username      the username
 * @return 1 for success, 0 for failure
 */
protected int apply_template(string template_path, string username) {
  if ((strlen(template_path) < 10) 
      || (template_path[<9..<1] != TEMPLATE_SUFFIX)) {
    return 0;
  }
  mapping infomap = ([ 
    'f' : ({ 0,
             "%s",
             ({ "acme-basic" }) // TODO support user flavors
          }),
    'u' : ({ 0,
             "%s",
             ({ username }) 
          })
  ]);
  string template = read_file(template_path);
  if (!template) {
    return 0;
  }
  string body = funcall(parse_format(template, infomap, 0));
  if (!write_file(template_path[0..<10], body)) {
    return 0;
  }
  if (!rm(template_path)) {
    return 0;
  }
  return 1;
}

/**
 * Save a user's hashed password to their password file.
 * 
 * @param  user_id       the user id
 * @param  password      the hashed password
 * @return 1 for success, 0 for failure
 */
protected int save_password(string user_id, string password) {
  object logger = LoggerFactory->get_logger(THISO);
  string username = UserTracker->query_username(user_id);
  string passwd_file = passwd_file(username);
  mapping passwd = read_value(passwd_file);
  if (!mappingp(passwd)) {
    passwd = ([ ]);
    if (file_exists(passwd_file)) {
      logger->warn("Overwriting corrupt password file %O", passwd_file);
    }
  }
  string hash = hash_passwd(password);
  passwd[user_id] = ([ PASSWD_PASSWORD: hash ]);
  write_value(passwd_file, passwd);
  return 1;
}

/**
 * Attach a user to their user session. If it can be safely resumed, their
 * last session will be used. Otherwise, a new session will be created with a
 * new avatar. Then the "descension" process takes place, which involves 
 * resuming their session and switching their connection from the provided 
 * interactive (which will generally be the login object).
 * 
 * @param  interactive   the user's current interactive 
 * @param  user_id       the user id to attach to session
 * @return the attached session id
 */
protected string attach_session(object interactive, string user_id) {
  object logger = LoggerFactory->get_logger(THISO);

  // get last connected session, or create new one
  string session_id = UserTracker->query_last_session(user_id);
  if (!session_id || !is_active(session_id)) {
    session_id = SessionTracker->new_session(user_id);
    if (!session_id) {
      logger->warn("failed to start session: %O", user_id);
      return 0;
    }
  }

  // get the session avatar, or create a new one
  // TODO add a way to use another session's avatar?
  object avatar = SessionTracker->query_avatar(session_id);
  if (!avatar) {
    avatar = clone_object(PlatformAvatar);
    if (!avatar) {
      logger->warn("failed to clone platform avatar: %O", user_id);
      return 0;
    }
  }
  if (!avatar->is_avatar()) {
    logger->warn("session avatar doesn't identify as avatar: %O %O", 
                 session_id, avatar);
    return 0;
  }
  SessionTracker->set_avatar(session_id, avatar);

  mixed *args, ex;
  if (ex = catch(args = avatar->try_descend(session_id); publish)) {
    logger->warn("caught exception in try_descend: %O", ex);
    return 0;
  } else {
    // (re)start session
    if (!SessionTracker->resume_session(session_id)) {
      logger->warn("failed to resume user session: %O %O", 
                   user_id, session_id);
      return 0; 
    }
    // switch connection to session
    if (!connect_session(interactive, session_id)) {
      logger->warn("failed to connect user session: %O %O", 
                   interactive, session_id);
      return 0;
    }
    apply(#'call_other, avatar, "on_descend", session_id, args);
    return session_id;
  } 
  return 0;
}
