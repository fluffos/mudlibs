/**
 * User registration controller. Also will log user into game upon success.
 *
 * @alias RegistrationController
 */
#include <topic.h>
#include <user.h>

inherit CommandController;

inherit MessageLib;
inherit ValidationLib;
inherit UserLib;

int execute(mapping model, string verb) {
  // get id for username
  string user_id = UserTracker->query_primary_user(model["username"]);
  if (!user_id) {
    string msg = sprintf("Login failed: no user_id found for username: %O", 
                         model["username"]); 
    system_msg(THISP, msg, ([ ]), TOPIC_LOGIN);
    return 1;
  }

  string session_id = attach_session(THISP, user_id);
  if (!session_id) {
    string msg = sprintf("Attaching user session failed: username: %O", 
                         model["username"]); 
    system_msg(THISP, msg, ([ ]), TOPIC_LOGIN);
    return 1;
  }
  return 1;
}

int validate_password_matches(mapping model) {
  object logger = LoggerFactory->get_logger(THISO);
  mapping passwd = read_value(passwd_file(model["username"]));
  if (!mappingp(passwd)) {
    // password file missing or corrupt
    return 0;
  }
  string user_id = UserTracker->query_primary_user(model["username"]);
  if (!mappingp(passwd[user_id])) {
    logger->warn("Primary user id %O for user %O not found in password file",
                 user_id, model["username"]);
    return 0;
  }  
  string hash = hash_passwd(model["password"]);
  return passwd[user_id][PASSWD_PASSWORD] == hash;
}

