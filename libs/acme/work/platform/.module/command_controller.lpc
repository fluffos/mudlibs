/**
 * A generic CommandController module for commands added through the 
 * CommandGiverMixin. Each command must define a controller, and those
 * controllers may inherit this program to gain simplicity and uniformity
 * in handling command execution. This is an abstract class, it implements the
 * do_command() function invoked directly by CommandGiver but expects the
 * inheriting programs to implement the execute() function.
 *
 * @alias CommandController
 */
#pragma no_clone
#include <sys/strings.h>
#include <command.h>
#include <command_controller.h>
#include <prompt.h>

private inherit CommandLib;
private inherit MessageLib;
private inherit ArgumentLib;
private inherit StringLib;
private inherit StructLib;
private inherit ObjectExpansionLib;
private inherit FileLib;
private inherit FormatStringLib;
private inherit PromptLib;

struct CommandState {
  string verb;
  mixed *command;
  mixed *syntax;
  mapping opts;
  string *args;
  mapping extra;
  mapping model;
  int field_retry;
  int form_retry;
  int force_prompt;
};

closure prompt_formatter, fail_formatter;

public void setup();
public void teardown();
public mapping do_command(mixed *command, string verb, string arg);
mapping process_command(struct CommandState state, closure callback);
int process_args(struct CommandState state, closure callback);
int process_opts(struct CommandState state, mapping opts, closure callback);
int process_extra(struct CommandState state, closure callback);
int process_field(struct CommandState state, mixed *field, string field_type, 
                  mixed index, closure callback);
void field_prompt(struct CommandState state, mixed *field, string field_type, 
                  mixed index, closure callback);
public int field_input(string arg, struct CommandState state, mixed *field, 
                       string field_type, mixed index, closure callback);
string parse_value(struct CommandState state, mixed *field, string field_type, 
                   mixed index, mixed val);
string parse_boolean(string arg, mixed val);
string parse_int(string arg, mixed val);
string parse_float(string arg, mixed val);
string parse_enum(string arg, mixed val, mixed *enum);
string parse_file(string arg, mixed val);
string parse_files(string arg, mixed val);
string parse_object(string arg, mixed val);
string parse_objects(string arg, mixed val);
varargs int do_validate(struct CommandState state, closure callback, 
                        int flags);
int validate(mixed *validations, struct CommandState state, mixed val, 
             mixed *field, closure retry_test);
mapping do_execute(mapping model, string verb);
public mapping execute(mapping model, string verb);

/**
 * Setup this command controller.
 */
public void setup() {
  prompt_formatter = parse_format(DEFAULT_CMD_PROMPT, ([
      'm' : ({ 0, "%s", ({ ''message }) }),
      't' : ({ 0, "%s", ({ ''type }) }),
      'd' : ({ 0, "%s", ({ 
               ({ #'?, 
                  ({ #'stringp, ''default }), 
                  ({ #'sprintf, 'arg, ''default }),
                  ""
               })
            }) })
    ]),
    ({ 'message, 'type, 'default })
  ); //'

  fail_formatter = parse_format(DEFAULT_CMD_FAIL, ([
      'm' : ({ 0, "%s", ({ ({ #'||, ''message, "" }) }) }),
      'v' : ({ 0, "%s", ({ ''verb }) })
    ]),
    ({ 'message, 'verb })
  ); //'
}

/**
 * Tear down this CommandController.
 */
public void teardown() {

}

/**
 * Run a command. Takes a command definition loaded from a command spec file,
 * and collects all specified fields and runs validation against the values
 * input by the user, either from arg list, getopts-style parameters, or a
 * series of one or more interactive user prompts (with retries). Once all 
 * fields values have been provided and validated, they are passed to the 
 * execute() function as the "model" mapping along with the verb being used.
 * The execute function may return a new model mapping that can be piped to
 * a new command on the command line. This behavior is only guaranteed when
 * not running in 'interactive' mode; if it is necessary to prompt the user for
 * a missing or invalid value, this function will return 0. However it may be
 * possible to preserve the command pipeline and resolve the rest of the
 * command in the future after execute() finishes, if it is desirable to do so
 * by the user.
 *
 * TODO implement command piping
 * 
 * @param  command       the command info as loaded from the command spec
 * @param  verb          the verb being used
 * @param  arg           the argument string
 * @return an "output" model mapping, or 0 if either the command failed or an
 *         interactive prompt was issued
 */
public mapping do_command(mixed *command, string verb, string arg) {
  mapping opts, badopts;
  string *args;
  arg = trim(arg, TRIM_RIGHT, ' ');
  mixed *syntax = apply_syntax(command, arg, &opts, &badopts, &args);

  if (valid_syntax(syntax, opts, badopts, args)) {
    struct CommandState state = 
      (<CommandState> 
        verb: verb, 
        command: command, 
        syntax: syntax, 
        opts: opts, 
        args: args, 
        extra: ([ ]), 
        model: ([ ]), 
        field_retry: 0, 
        form_retry: 0, 
        force_prompt: 0);
    return process_command(state, symbol_function("do_execute", THISO)); //'
  } 

  // fail syntax
  return 0;
}

/**
 * Entry-point into command processor. Anytime the command state changes, this
 * function may be called which attempts to run the command. If there is still
 * missing or invalid input, it will descend into sub-processing functions to
 * correct the problem, and re-run process_command() with the new command 
 * state. If the command state is good, the callback will be executed.
 * 
 * @param  state         the command state, a struct containing all the 
 *                       information about the command-to-be-executed we have
 *                       so far
 * @param  callback      the callback to execute the validated command
 * @return the result of the callback, or 0 if command could not be run as 
 *         input
 */
mapping process_command(struct CommandState state, closure callback) {
  if (!process_args(state, callback)) {
    return 0;
  }
  if (!process_opts(state, state->syntax[SYNTAX_OPTS], callback)) {
    return 0;
  }
  if (!process_opts(state, state->syntax[SYNTAX_LONGOPTS], callback)) {
    return 0;
  }
  if (!process_extra(state, callback)) {
    return 0;
  }
  if (!do_validate(state, callback, VALIDATE_SKIP_FIELDS)) {
    return 0;
  }

  return funcall(callback, state->model, state->verb);
}

/**
 * Process the field values passed via the command arg list. This simply 
 * runs process_field() for each command arg, and runs field_prompt() if you
 * didn't specify enough args for the number of fields required. If all the
 * arg values are good, return 1 to continue processing. To halt or terminate
 * processing, return 0.
 * 
 * @param  state         the command state, a struct containing all the 
 *                       information about the command-to-be-executed we have
 *                       so far
 * @param  callback      the callback to execute the validated command
 * @return 1 to continue processing, otherwise 0
 */
int process_args(struct CommandState state, closure callback) {
  int i = 0;
  int numargs = sizeof(state->args);
  foreach (mixed *field : state->syntax[SYNTAX_ARGS]) {
    if (!member(state->model, field[FIELD_ID])) {
      if ((i < numargs) && !state->force_prompt) {
        // we have the arg, process it
        if (!process_field(state, field, "args", i, callback)) {
          return 0;
        }
      } else {
        state->force_prompt = 0;
        // not enough args provided
        if ((field[FIELD_PROMPT_SETTING] == PROMPT_SYNTAX)
            || (field[FIELD_PROMPT_SETTING] == PROMPT_ALWAYS)) {
          // prompt user for value
          state->args += ({ field[FIELD_DEFAULT] });
          field_prompt(state, field, "args", i, callback);
          return 0;
        } else {
          if (field[FIELD_REQUIRED]) {
            // TODO required field, fail usage
            return 0;            
          } else {
            // not required, continue with default
            state->args[i] = field[FIELD_DEFAULT];
            if (!process_field(state, field, "args", i, callback)) {
              return 0;
            }
          }
        }
      }
    }
    i++;
  }
  return 1;
}

/**
 * Process the field values passed via the command opts and longopts. This 
 * simply runs process_field() for each specified opt or longopt, and runs 
 * field_prompt() for any required-but-missing fields. If all the values are 
 * good, return 1 to continue processing. To halt or terminate processing, 
 * return 0.
 * 
 * @param  state         the command state, a struct containing all the 
 *                       information about the command-to-be-executed we have
 *                       so far
 * @param  opts          a map of opt or longopt string to the field definition
 * @param  callback      the callback to execute the validated command
 * @return 1 to continue processing, otherwise 0
 */
int process_opts(struct CommandState state, mapping opts, closure callback) {
  foreach (mixed opt, mixed *field : opts) {
    if (!member(state->model, field[FIELD_ID])) {
      if (member(opts, opt) && !state->force_prompt) {
        // we have the opt, process it
        if (!process_field(state, field, "opts", opt, callback)) {
          return 0;
        }
      } else {
        state->force_prompt = 0;
        // opt not provided
        if ((field[FIELD_PROMPT_SETTING] == PROMPT_SYNTAX)
            || (field[FIELD_PROMPT_SETTING] == PROMPT_ALWAYS)) {
          // prompt user for value
          m_add(state->opts, opt, field[FIELD_DEFAULT]);
          field_prompt(state, field, "opts", opt, callback);
          return 0;
        } else {
          if (field[FIELD_REQUIRED]) {
            // required field, fail usage
            return 0;            
          } else {
            // not required, continue with default
            m_add(state->opts, opt, field[FIELD_DEFAULT]);
            if (!process_field(state, field, "opts", opt, callback)) {
              return 0;
            }
          }
        }
      }
    }
  }
  return 1;
}

/**
 * Process the extra field values that were defined but not specified as 
 * passed via args or opts. This simply runs process_field() for each extra 
 * field, and runs field_prompt() for any required-but-missing fields. If all 
 * the values are good, return 1 to continue processing. To halt or terminate 
 * processing, return 0.
 * 
 * @param  state         the command state, a struct containing all the 
 *                       information about the command-to-be-executed we have
 *                       so far
 * @param  callback      the callback to execute the validated command
 * @return 1 to continue processing, otherwise 0
 */
int process_extra(struct CommandState state, closure callback) {
  foreach (mixed *field : state->command[COMMAND_FIELDS]) {
    string id = field[FIELD_ID];
    if (!member(state->model, id)) {
      if (member(state->extra, id) && !state->force_prompt) {
        // we have the field, process it
        if (!process_field(state, field, "extra", id, callback)) {
          return 0;
        }
      } else {
        state->force_prompt = 0;
        // field not provided
        if ((field[FIELD_PROMPT_SETTING] == PROMPT_SYNTAX)
            || (field[FIELD_PROMPT_SETTING] == PROMPT_ALWAYS)) {
          // prompt user for value
          m_add(state->extra, id, field[FIELD_DEFAULT]);
          field_prompt(state, field, "extra", id, callback);
          return 0;
        } else {
          if (field[FIELD_REQUIRED]) {
            // required field, fail usage
            return 0;            
          } else {
            // not required, continue with default
            m_add(state->extra, id, field[FIELD_DEFAULT]);
            if (!process_field(state, field, "extra", id, callback)) {
              return 0;
            }
          }
        }
      }
    }
  }
  return 1;
}

/**
 * Process a field. This function has 3 duties, parse the field value from the
 * input string, run field validations on the value, and add the value to the 
 * model. If anything goes wrong along the way, it should attempt to retry 
 * field processing via a field_prompt() call. Returns 1 if everything was 
 * good, otherwise 0 to halt/terminate processing.
 * 
 * @param  state         the command state, a struct containing all the 
 *                       information about the command-to-be-executed we have
 *                       so far
 * @param  field         the field info from the parsed command spec: id, type
 *                       info, required/prompt settings, max retry, default 
 *                       value, prompt string, validations
 * @param  field_type    field type: "args", "opts", or "extra"
 * @param  index         field index, int for arg position, string for opts or
 *                       extra field ids
 * @param  callback      the callback to execute the validated command
 * @return 1 to continue processing, otherwise 0
 */
int process_field(struct CommandState state, mixed *field, string field_type, 
                  mixed index, closure callback) {
  mixed val;
  string fail = parse_value(state, field, field_type, index, &val);
  if (fail) {
    if (state->field_retry >= field[FIELD_MAX_RETRY]) {
      // TODO set fail message
    } else {
      // TODO print fail message
      state->field_retry += 1;
      field_prompt(state, field, field_type, index, callback);
    }
    return 0;
  } else {
    closure retry_test = (: 
      return ( (($2[FIELD_PROMPT_SETTING] == PROMPT_VALIDATE)
                || ($2[FIELD_PROMPT_SETTING] == PROMPT_ALWAYS))
                && ($1->field_retry < $2[FIELD_MAX_RETRY]) );
    :);

    int valid = validate(field[FIELD_VALIDATION], state, val, field, 
                         retry_test);
    if (valid == VALIDATION_RETRY) {
      // prompt user for value
      state->field_retry += 1;
      field_prompt(state, field, field_type, index, callback);
      return 0;
    } else if (valid == VALIDATION_FAIL) {
      return 0;
    }

    // validation passed, add to model
    state->model[field[FIELD_ID]] = val;
    // reset retries to 0 fo next field
    state->field_retry = 0;
    // if form retry, force prompt for next field
    if (state->form_retry > 0) {
      state->force_prompt = 1;
    }
    return 1;
  }
}

/**
 * Prompt the user for a field value.
 * 
 * @param  state         the command state, a struct containing all the 
 *                       information about the command-to-be-executed we have
 *                       so far
 * @param  field         the field info from the parsed command spec: id, type
 *                       info, required/prompt settings, max retry, default 
 *                       value, prompt string, validations
 * @param  field_type    field type: "args", "opts", or "extra"
 * @param  index         field index, int for arg position, string for opts or
 *                       extra field ids
 * @param  callback      the callback to execute the validated command
 */
void field_prompt(struct CommandState state, mixed *field, string field_type, 
                  mixed index, closure callback) {
  mapping context = ([ ]);
  if (field[FIELD_PROMPT][PROMPT_NOECHO]) {
    context[PROMPT_NO_ECHO] = 1;
  }

  string val = get_struct_member(state, field_type)[index];
  string prompt = funcall(
    prompt_formatter, 
    field[FIELD_PROMPT][PROMPT_MSG],
    (field[FIELD_TYPE] == "enum" 
      ? (field[FIELD_ENUM][ENUM_ID] 
        ? field[FIELD_ENUM][ENUM_ID]
        : "enum")
      : field[FIELD_TYPE]),
    val
  );
//  LoggerFactory->get_logger(THISO)->info("%O %O %O %O %O %O %O %O", THISP, prompt, context, state, field, field_type, index, callback);
  prompt(THISP, prompt, context, 
         #'field_input, state, field, field_type, index, callback);
}

/**
 * Handle field prompt input. This should update the command state with the
 * new value and re-run process_command().
 * 
 * @param  input         the input string
 * @param  state         the command state, a struct containing all the 
 *                       information about the command-to-be-executed we have
 *                       so far
 * @param  field         the field info from the parsed command spec: id, type
 *                       info, required/prompt settings, max retry, default 
 *                       value, prompt string, validations
 * @param  field_type    field type: "args", "opts", or "extra"
 * @param  index         field index, int for arg position, string for opts or
 *                       extra field ids
 * @param  callback      the callback to execute the validated command
 * @return 0 to indicate success
 */
public int field_input(string input, struct CommandState state, mixed *field, 
                       string field_type, mixed index, closure callback) {
  if (input && strlen(input)) {
    get_struct_member(state, field_type)[index] = input;
  }
  process_command(state, callback);
  return 0;
}

/**
 * Parse a field value from an input arg/opt/extra string. This should apply
 * the correct type parser, and update the field value by reference.
 * 
 * @param  state         the command state, a struct containing all the 
 *                       information about the command-to-be-executed we have
 *                       so far
 * @param  field         the field info from the parsed command spec: id, type
 *                       info, required/prompt settings, max retry, default 
 *                       value, prompt string, validations
 * @param  field_type    field type: "args", "opts", or "extra"
 * @param  index         field index, int for arg position, string for opts or
 *                       extra field ids
 * @param  val           the field value, passed by reference
 * @return a fail message, or 0 if value was parsed successfully
 */
string parse_value(struct CommandState state, mixed *field, string field_type, 
                   mixed index, mixed val) {
  string id = field[FIELD_ID];
  string arg = get_struct_member(state, field_type)[index];
  arg = trim(arg || "", TRIM_BOTH);
  switch (field[FIELD_TYPE]) {
    case "bool":
      return parse_boolean(arg, &val);
    case "int":
      return parse_int(arg, &val);
    case "float":
      return parse_float(arg, &val);
    case "enum":
      return parse_enum(arg, &val, field[FIELD_ENUM]);
    case "file":
      return parse_file(arg, &val);
    case "files":
      return parse_files(arg, &val);
    case "object":
      return parse_object(arg, &val);
    case "objects":
      return parse_objects(arg, &val);
    case "string":
    default:
      val = arg;
      return 0;
  }
  // XXX should this fail?
  return 0;
}

/**
 * Parse a boolean value.
 * 
 * @param  arg           the value string
 * @param  val           the value to set to 1 or 0, passed by reference
 * @return a fail message, or 0 if value was parsed successfully
 */
string parse_boolean(string arg, mixed val) {
  switch (lower_case(arg)) {
    case "y":
    case "yes":
    case "true":
      val = 1;
      return 0;
    case "n":
    case "no":
    case "false":
      val = 0;
      return 0;
    default:
      return "Allowed values are: yes, no"; 
  }
  return 0;
}

/**
 * Parse an integer value.
 * 
 * @param  arg           the value string
 * @param  val           the value to set to an int, passed by reference
 * @return a fail message, or 0 if value was parsed successfully
 */
string parse_int(string arg, mixed val) {
  if (sscanf("%d", arg, val)) {
    return 0;
  } else {
    return "Please enter a number.";
  }
  return 0;
}

/**
 * Parse a floating point value.
 * 
 * @param  arg           the value string
 * @param  val           the value to set to a float, passed by reference
 * @return a fail message, or 0 if value was parsed successfully
 */
string parse_float(string arg, mixed val) {
  int i, f;
  if (sscanf("%d.%d", arg, i, f)) {
    if (f == 0) {
      val = to_float(i);
    } else if (f == 1) {
      val = to_float(i) + 0.1;
    } else {
      val = to_float(i) + (to_float(f) / pow(10, ceil(log(f) / log(10))));
    }
    return 0;
  } else {
    return "Please enter a number.";
  }
  return 0;
}

/**
 * Parse value from an enumeration.
 * 
 * @param  arg           the value string
 * @param  val           the value to set, passed by reference. assigned string
 *                       for single or array for multi
 * @param  enum          the enumeration info: legal values, multi flag, 
 *                       delimeter for multi value strings
 * @return a fail message, or 0 if value was parsed successfully
 */
string parse_enum(string arg, mixed val, mixed *enum) {
  mapping enum_map = mkmapping(enum);
  if (enum[ENUM_MULTI]) {
    val = ({ });
    string *args = explode_unescaped(arg, enum[ENUM_DELIM]);
    foreach (string a : args) {
      a = unescape(a);
      if (!member(enum_map, a)) {
        return "Allowed values are: " 
          + implode(enum[ENUM_VALUES], enum[ENUM_DELIM] + " ");
      }
      val += ({ a });
    }
  } else {
    if (!member(enum_map, arg)) {
      return "Allowed values are: " 
        + implode(enum[ENUM_VALUES], enum[ENUM_DELIM] + " ");
    }
    val = arg;
  }
  return 0;
}

/**
 * Parse a string as if it specifies a single filename.
 * 
 * @param  arg           the value string
 * @param  val           the value to set to filename, passed by reference
 * @return a fail message, or 0 if value was parsed successfully
 */
string parse_file(string arg, mixed val) {
  mixed result;
  string err = parse_files(arg, &result);
  if (err) {
    return err;
  }
  if (!sizeof(result)) {
    val = 0;
  } else {
    // TODO prompt user for file selection when size > 1
    val = result[0];
  }
  return 0;
}

/**
 * Parse a value representing a list of filenames. Patterns will be expanded.
 * 
 * @param  arg           the value string
 * @param  val           the value to set to an array of filenames, passed by 
 *                       reference
 * @return a fail message, or 0 if value was parsed successfully
 */
string parse_files(string arg, mixed val) {
  string *args = explode_args(arg);
  mixed *result = ({ });
  foreach (string pattern : args) {
    result += expand_pattern(pattern, THISP);
  }
  val = result;
  return 0;
}

/**
 * Parse a value as a single object. Object expansion will be performed.
 * 
 * @param  arg           the value string
 * @param  val           the value to set to an object, passed by reference
 * @return a fail message, or 0 if value was parsed successfully
 */
string parse_object(string arg, mixed val) {
  mixed result;
  string err = parse_objects(arg, &result);
  if (err) {
    return err;
  }
  if (!sizeof(result)) {
    val = 0;
  } else {
    // TODO prompt user for object selection when size > 1
    val = result[0];
  }
  return 0;
}

/**
 * Parse a value as a list of objects. Object expansion will be performed.
 * 
 * @param  arg           the value string
 * @param  val           the value to set to object array, passed by reference
 * @return a fail message, or 0 if value was parsed successfully
 */
string parse_objects(string arg, mixed val) {
  val = expand_objects(arg, THISP, 0);
  return 0;
}

/**
 * Perform command validation. May prompt for new values if validation fails
 * when run in interactive mode. Return 1 if validation passed, otherwise 0.
 * 
 * @param  state         the command state, a struct containing all the 
 *                       information about the command-to-be-executed we have
 *                       so far
 * @param  callback      the callback to execute the validated command
 * @param  flags         validation flags: skip field-level validations
 * @return 1 if validations passed, otherwise 0
 */
varargs int do_validate(struct CommandState state, closure callback, 
                        int flags) {
  closure retry_test = (: 
    return ($1->form_retry < $1->command[COMMAND_MAX_RETRY]);
  :);

  if (!(flags & VALIDATE_SKIP_FIELDS)) {
    foreach (mixed *field : state->command[COMMAND_FIELDS]) {
      int valid = validate(field[FIELD_VALIDATION], state, 
                           state->model[field[FIELD_ID]], field, retry_test);
      if (valid == VALIDATION_RETRY) {
        state->form_retry += 1;
        state->model = ([ ]);
        state->force_prompt = 1;
        process_command(state, callback);
        return 0;
      } else if (valid == VALIDATION_FAIL) {
        return 0;
      }
    }
  }

  // do form validation
  mixed *validations = state->syntax[SYNTAX_VALIDATION] 
                       + state->command[COMMAND_VALIDATION];
  int valid = validate(validations, state, state->model, 0, retry_test);
  if (valid == VALIDATION_RETRY) {
    state->form_retry += 1;
    state->model = ([ ]);
    state->force_prompt = 1;
    process_command(state, callback);
    return 0;
  } else if (valid == VALIDATION_FAIL) {
    return 0;
  }

  return 1;
}

/**
 * Validate command by running one or more validation functions with a 
 * specified value to validate. Will not perform a retry, but will perform a
 * specified retry test and indicate via the return value whether a retry
 * should be performed. This allows the validate() function to be used to 
 * perform field-level or form-level validations depending on the function
 * arguments.
 * 
 * @param  validations   the validations to run
 * @param  state         the command state, a struct containing all the 
 *                       information about the command-to-be-executed we have
 *                       so far
 * @param  val           the value to validate; field value for fields or model
 *                       mapping for form-level validation
 * @param  field         the field info if performing a field level validation
 * @param  retry_test    a closure that takes state and field info (if given),
 *                       and returns 1 if retry attempt should be made, or 0 to
 *                       terminate command execution
 * @return an integer indicating if validations passed, failed w/ retry, or
 *         failed w/o retry
 */
int validate(mixed *validations, struct CommandState state, mixed val, 
             mixed *field, closure retry_test) {
  foreach (mixed *validation : validations) {
    // invoke validation function
    string func = VALIDATION_PREFIX + validation[VALIDATE_VALIDATOR];
    closure validator = symbol_function(func, THISO);
    if (!validator) {
      stderr_msg(funcall(fail_formatter, sprintf(
        "Validator not found: %s.\n", 
        validation[VALIDATE_VALIDATOR]
      ), state->verb));
    }

    // process result
    int result = apply(validator, val, validation[VALIDATE_PARAMS]);
    result = (validation[VALIDATE_NEGATE] ? !result : result);
    if (!result) {
      // validation failed
      stderr_msg(funcall(fail_formatter, validation[VALIDATE_FAIL], 
                         state->verb));
      if (funcall(retry_test, state, field)) {
        return VALIDATION_RETRY;
      } else {
        return VALIDATION_FAIL;
      }
    }
  }
  return VALIDATION_PASS;
}

/**
 * Run the execution function. 
 * 
 * @param  model         a mapping of field ids to the collected field value
 * @param  verb          the verb being used to execute command
 * @return a mapping that will be used for the model of the next command in 
 *         the pipeline
 */
mapping do_execute(mapping model, string verb) {
  return execute(model, verb);
}

/**
 * The execution function. Should be overridden by implementing command 
 * controllers to execute the actual business logic of the command.
 * 
 * @param  model         a mapping of field ids to the collected field value
 * @param  verb          the verb being used to execute command
 * @return a mapping that will be used for the model of the next command in 
 *         the pipeline
 */
public mapping execute(mapping model, string verb) {
  return 0;
}

/**
 * Constructor.
 */
public void create() {
  setup();
}
