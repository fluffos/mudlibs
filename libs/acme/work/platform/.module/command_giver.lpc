/**
 * A module for objects to execute user commands.
 *
 * @author devo@eotl
 * @alias CommandGiverMixin
 */
#pragma no_clone
#include <sys/functionlist.h>
#include <capability.h>
#include <command_giver.h>
#include <command.h>

private inherit ObjectLib;
private inherit FileLib;
private inherit ArrayLib;
private inherit CommandSpecLib;

private mapping CAPABILITIES_VAR = ([ CAP_COMMAND_GIVER ]);
private string CMD_IMPORTS_VAR = 
  PlatformBinDir "/command_giver/command_giver.cmds";

private int enabled;
private nosave mixed *commands;

public void setup();
public void teardown();
int is_command_giver();
mixed *load_cmd_imports();
public int do_command(string arg);
public int run_script(string script_file);
protected object load_controller(string controller);

/**
 * Setup the CommandGiverMixin.
 */
public void setup() {
  object logger = LoggerFactory->get_logger(THISO);
  commands = load_cmd_imports();
  //logger->info("commands: %O\n", commands);
  enabled = 1;
}

/**
 * Tear down the CommandGiverMixin.
 */
public void teardown() {
  enabled = 0;
}

/**
 * Return true to indicate this object is a command giver.
 * 
 * @return 1 to indicate object is a command giver
 */
int is_command_giver() {
  return enabled;
}

/**
 * Introspect the inherit tree for the command imports variable assignments and 
 * load the configured command specs from disk.
 * 
 * @return a 2-dimensional array of command spec and the parsed command data
 */
mixed *load_cmd_imports() {
  mixed *result = ({ });
  mixed *vars = variable_list(THISO, RETURN_FUNCTION_NAME
                                     | RETURN_VARIABLE_VALUE);
  int i = 0;
  while ((i = member(vars,  CMD_IMPORTS_VAR_STR, i)) != -1) {
    mixed val = vars[++i];
    if (stringp(val)) {
      result += ({ ({ val, load_command_spec(val) }) });
    }
    i++;
  }
  return result;
}

/**
 * Main command router invoked by HookService. Any added commands will pass 
 * through this action function to parse out the verb and argument portion of
 * the command. Then control will be routed to the associated command 
 * controller for validation and execution.
 * 
 * @param  arg the command-line argument
 * @return     the result of the command execution; 1 for success, 0 for
 *             failure.
 */
public int do_command(string arg) {
  mapping fragments = ([ ]); // len to fragment 
  mapping matched = ([ ]);  // verb to arg
  int arglen = strlen(arg);
  int result = 0;
  foreach (mixed *cmd : commands) {
    string specfile = cmd[0];
    foreach (mixed *command : cmd[1]) {
      foreach (string verb : command[COMMAND_VERBS]) {
        if (member(matched, verb)) {
          if (matched[verb]) {
            object controller = load_controller(expand_path(
                                  command[COMMAND_CONTROLLER], specfile));
            if (controller) {
              result = controller->do_command(command, verb, matched[verb]);
            }
            // TODO notify broken controller via result
            if (result) {
              break;
            }
          } else {
            continue;
          }
        }
        int len = strlen(verb);
        if (len > arglen) {
          continue;
        }
        if (!member(fragments, len)) {
          fragments[len] = arg[0..(len - 1)];
        }
        if (fragments[len] == verb) {
          if (len == arglen) {
            matched[verb] = "";
          } else if (arg[len] == ' ') {
            // trim leading spaces
            int i = len;
            while (arg[i] == ' ') { 
              i++;
            }
            // set the match
            if (i < arglen) {
              matched[verb] = arg[i..];
            } else {
              matched[verb] = "";
            }
          } else {
            matched[verb] = 0;
          }
        } else {
          matched[verb] = 0;
        }

        if (matched[verb]) {
          object controller = load_controller(expand_path(
                                command[COMMAND_CONTROLLER], specfile));
          if (controller) {
            result = controller->do_command(command, verb, matched[verb]);
          }
          if (result) {
            break;
          }
        }
      }
      if (result) {
        break;
      }
    }
    if (result) {
      break;
    }    
  }
  
  return result;
}

/**
 * Simple script handling supporting basic source files.
 * 
 * @param  script_file   the script file
 * @return 1 for success, 0 for failure
 */
public int run_script(string script_file) {
  string script = read_file(script_file);
  if (!script) {
    return 0;
  }
  string *lines = explode(script, "\n");
  foreach (string line : lines) {
    command(line);
  }
  return 1;
}

/**
 * Attempt to load a command controller object.
 * 
 * @param  controller    the path to the controller
 * @return the loaded controller object
 */
protected object load_controller(string controller) {
  object result;
  object logger = LoggerFactory->get_logger(THISO);
  string err = catch(result = load_object(controller); publish);
  if (err) {
    logger->info("error loading controller %s: %s", controller, err);
  }
  return result;
}

