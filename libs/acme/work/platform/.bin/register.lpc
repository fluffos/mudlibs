/**
 * User registration controller. Also will log user into game upon success.
 *
 * @alias RegisterController
 */
#include <topic.h>
#include <user.h>
#include <command.h>

inherit CommandController;
inherit ValidationLib;

private inherit CommandLib;
private inherit MessageLib;
private inherit UserLib;

public mapping execute(mapping model, string verb);
public int validate_passwords_match(mapping model);

/**
 * Execute the register command. First creates the user, then starts a new
 * session and logs the user in.
 * 
 * @param  model         the command model
 * @param  verb          the command verb
 * @return an output model containing input username, new user id, and new 
 *         session id
 */
public mapping execute(mapping model, string verb) {
  mapping result = ([
    "username" : model["username"],
  ]);

  // create new user
  advance_step(result);
  string user_id = create_user(model["username"], model["password"]);
  if (!user_id) {
    string msg = sprintf("User creation failed: username: %O\n", 
                         model["username"]); 
    stdout_msg(msg, ([ ]), THISP);
    return fail_result(result);
  }
  result["user_id"] = user_id;

  // attach to session
  advance_step(result);
  string session_id = attach_session(THISP, user_id);
  if (!session_id) {
    string msg = sprintf("Attaching user session failed: username: %O\n", 
                         model["username"]); 
    stdout_msg(msg, ([ ]), THISP);
    return fail_result(result);
  }
  result["session_id"] = session_id;

  advance_step(result);
  string msg = sprintf("Registration complete! Welcome to the game, %s.\n",
                       model["username"]);
  stdout_msg(msg, ([ ]), THISP);
  return pass_result(result);
}

/**
 * Validate the password field matches the confirm password field.
 * 
 * @param  model         the command model
 * @return 1 if passwords match, otherwise 0
 */
public int validate_passwords_match(mapping model) {
  return model["password"] == model["confirmPassword"];
}
