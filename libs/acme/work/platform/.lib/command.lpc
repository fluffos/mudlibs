/**
 * A library of functions related to the supporting the command line.
 *
 * @alias CommandLib
 */
#pragma no_clone
#include <sys/regexp.h>
#include <command.h>

#define UNMATCHED_ARG  "__UNMATCHED_PARSE_COMMAND_ARG"

inherit StringLib;
inherit ArgumentLib;

mixed *apply_syntax(mixed *command, string arg, mapping opts, mapping badopts, 
                    string *args);
mixed *get_matching_syntax(mapping syntax_map, mapping opts, mapping badopts, 
                           mixed *args);
int valid_syntax(mixed *syntax, mapping opts, mapping badopts, mixed *args);
void parse_opts(string arg, int pos, mapping opts, mapping badopts, 
                mapping valid_opts, mapping valid_longopts);
void parse_longopt(string arg, int pos, string opt, string param, 
                   mapping badopts, mapping valid_longopts);
void parse_opt(string arg, int pos, mapping opts, mapping badopts, 
               mapping valid_opts);
string *parse_args(string arg, int pos, mapping syntax);
string *parse_args_explode(string arg, int pos, int numargs);
string *parse_args_sscanf(string arg, int pos, string pattern);
string *parse_args_regexp(string arg, int pos, string pattern);
string *parse_args_parse_command(string arg, int pos, string pattern);
void parse_param(string arg, int pos, string param);
mapping advance_step(mapping result);
mapping fail_result(mapping result);
mapping pass_result(mapping result);

private closure sscanf_args, parse_command_args;

/**
 * This function iterates over the syntax definitions of a specified command, 
 * applying the given argument string to populate the opts, badopts, and args
 * parameters, passed by reference. The first valid syntax found is returned. 
 * If no valid syntax was found, the closest match will be returned.
 * 
 * @param  command       the command definition
 * @param  arg           the command line argument string
 * @param  opts          a mapping of opts and longopts to their parameter
 *                       values, passed by reference
 * @param  badopts       a mapping of bad opts to their parameter values,
 *                       passed by reference
 * @param  args          the argument list, passed by reference
 * @return the syntax that was applied
 */
mixed *apply_syntax(mixed *command, string arg, mapping opts, mapping badopts, 
                    string *args) {
  // TODO subcommands
  mapping syntax_map = ([ ]);
  foreach (mixed *syntax : command[COMMAND_SYNTAX]) {
    int pos = 0;

    // XXX cache these?
    object logger = LoggerFactory->get_logger(THISO);
    //logger->info("%O", syntax);
    mapping valid_opts = mkmapping(map(syntax[SYNTAX_OPTS], 
                                       #'[, OPT_OPT),//'
                                   syntax[SYNTAX_OPTS]);
    mapping valid_longopts = mkmapping(map(syntax[SYNTAX_LONGOPTS], 
                                           #'[, OPT_OPT),//'
                                       syntax[SYNTAX_LONGOPTS]);

    opts = ([ ]);
    badopts = ([ ]);
    args = ({ });

    parse_opts(arg, &pos, &opts, &badopts, valid_opts, valid_longopts);
    pos = find_nonws(arg, pos);
    args = parse_args(arg, &pos, syntax);

    if (valid_syntax(syntax, opts, badopts, args)) {
      return syntax;
    } else {
      m_add(syntax_map, syntax, opts, badopts, args);
    }
  }

  mixed *syntax = get_matching_syntax(syntax_map, &opts, &badopts, &args);
  if (!syntax) {
    // no matching syntax, use first
    syntax = command[COMMAND_SYNTAX][0];
    opts = syntax_map[syntax, 0];
    badopts = syntax_map[syntax, 1];
    args = syntax_map[syntax, 2];
  }
  return syntax;
}

/**
 * Look through a bunch of syntaxes given the parsed opts, badopts, and args
 * and return the best match for that particular combination. This reassigns
 * opts, badopts, and args to the values that were parsed from the matching
 * syntax.
 * XXX this function is weird but needed for usage strings I guess
 * 
 * @param  opts          a mapping of opts and longopts to their parameter
 *                       values, passed by reference
 * @param  badopts       a mapping of bad opts to their parameter values,
 *                       passed by reference
 * @param  args          the argument list, passed by reference
 * @return the syntax that is the closest match to the 
 */
mixed *get_matching_syntax(mapping syntax_map, mapping opts, mapping badopts, 
                           mixed *args) {
  foreach (mixed *syntax, 
           mapping syn_opts, 
           mapping syn_badopts, 
           string *syn_args 
           : syntax_map) {
    if (valid_syntax(syntax, syn_opts, syn_badopts, syn_args)) {
      opts = syn_opts;
      badopts = syn_badopts;
      args = syn_args;
      return syntax;
    }
  }

  foreach (mixed *syntax, 
           mapping syn_opts, 
           mapping syn_badopts, 
           string *syn_args 
           : syntax_map) {
    if (valid_syntax(syntax, syn_opts, ([ ]), syn_args)) {
      opts = syn_opts;
      badopts = syn_badopts;
      args = syn_args;
      return syntax;
    }
  }

  return 0;
}

/**
 * Returns whether or not the parsed opts, badopts, and args are valid for a 
 * given syntax definition.
 * 
 * @param  syntax        the syntax being applied
 * @param  opts          a mapping of opts and longopts to their parameter
 *                       values, passed by reference
 * @param  badopts       a mapping of bad opts to their parameter values,
 *                       passed by reference
 * @param  args          the argument list, passed by reference
 * @return 1 if syntax is valid, 0 otherwise
 */
int valid_syntax(mixed *syntax, mapping opts, mapping badopts, mixed *args) {
  // TODO make sure multi opts are valid
  int numargs = sizeof(args);
  if (syntax[SYNTAX_EXPLODE_ARGS] >= 0) {
    if (numargs == syntax[SYNTAX_EXPLODE_ARGS]) {
      if (!sizeof(badopts)) {
        return 1;
      }
    }
  } else {
    if (syntax[SYNTAX_MIN_ARGS] >= 0) {
      if (syntax[SYNTAX_MIN_ARGS] <= numargs) {
        if (syntax[SYNTAX_MAX_ARGS] >= 0) {
          if (syntax[SYNTAX_MAX_ARGS] >= numargs) {
            return (!sizeof(badopts));
          }
        } else {
          return (!sizeof(badopts));
        }
      }
    } else if (syntax[SYNTAX_MAX_ARGS] >= 0) {
      if (syntax[SYNTAX_MAX_ARGS] >= numargs) {
        return (!sizeof(badopts));
      }
    } else {
      return (!sizeof(badopts));
    }
  }
  return 0;
}

/**
 * Parse opts and longopts out of an argument string.
 * 
 * @param  arg            the argument string
 * @param  pos            the position in the argument string to begin search,
 *                        passed by reference and assigned the position of the
 *                        end of the opts section of the argument string
 * @param  opts           a mapping of discovered opts and longopts to their 
 *                        parameter values, passed by reference
 * @param  badopts        a mapping of "bad" opts and their parameter values,
 *                        passed by reference
 * @param  valid_opts     all the valid opts
 * @param  valid_longopts all the valid longopts
 */
void parse_opts(string arg, int pos, mapping opts, mapping badopts, 
                mapping valid_opts, mapping valid_longopts) {
  int done = 0;
  int len = strlen(arg);
  while (!done && (pos < len)) {
    switch (arg[pos]) {
      case ' ':
      case '\t':
        pos++;
        break;
      case '-':
        pos++;
        if (pos >= len) {
          continue;
        }
        switch (arg[pos]) {
          case '-':
            pos++;
            string opt;
            string param;
            parse_longopt(arg, &pos, &opt, &param, &badopts, valid_longopts);
            if (opt) {
              if (!member(opts, opt)) {
                opts[opt] = ({ });
              }
              opts[opt] += ({ param });
            } else {
              // no more opts
              done = 1;
            } 
            break;
          case ' ':
            pos++;
            break;
          default:
            parse_opt(arg, &pos, &opts, &badopts, valid_opts);
            break;
        }
        break;
      default:
        // found an arg
        done = 1;
        break;
    }
  }
}

/**
 * Parse a longopt in an argument string.
 * 
 * @param  arg            the argument string
 * @param  pos            the position in the argument string to begin search,
 *                        passed by reference and assigned the position of the
 *                        end of the parsed longopt
 * @param  longopt        the parsed longopt, passed by reference
 * @param  param          the longopt parameter, passed by reference
 * @param  badopts        a mapping of "bad" opts and their parameter values,
 *                        passed by reference
 * @param  valid_longopts all the valid longopts
 */
void parse_longopt(string arg, int pos, string longopt, string param, 
                   mapping badopts, mapping valid_longopts) {
  longopt = "";
  int len = strlen(arg);
  while ((pos < len) && (arg[pos] != ' ')) {
    longopt = sprintf("%s%c", longopt, arg[pos]);
    pos++;
  }

  if (member(valid_longopts, longopt)) {
    if (valid_longopts[longopt][OPT_PARAM]) {
      pos = find_nonws(arg, pos);
      if (pos < len) {
        parse_param(arg, &pos, &param);
      } else {
        param = "";
      }
    }
  } else {
    badopts[longopt] = 1;
  }
}

/**
 * Parse an opt in an argument string.
 * 
 * @param  arg            the argument string
 * @param  pos            the position in the argument string to begin search,
 *                        passed by reference and assigned the position of the
 *                        end of the parsed opt
 * @param  opts           a mapping of discovered opts and longopts to their 
 *                        parameter values, passed by reference
 * @param  badopts        a mapping of "bad" opts and their parameter values,
 *                        passed by reference
 * @param  valid_opts     all the valid opts
 */
void parse_opt(string arg, int pos, mapping opts, mapping badopts, 
               mapping valid_opts) {
  int len = strlen(arg);
  while ((pos < len) && (arg[pos] != ' ')) {
    int opt = arg[pos];
    pos++;
    if (member(valid_opts, opt)) {
      string param;
      if (valid_opts[opt][OPT_PARAM]) {
        pos = find_nonws(arg, pos);
        if (pos < len) {
          parse_param(arg, &pos, &param);
        }
      }
      if (!member(opts, opt)) {
        opts[opt] = ({ });
      }
      opts[opt] += ({ param });
      return;
    } else {
      badopts[opt] = 1;
    }
  }
}

/**
 * Parse the argument list out of an argument string using the provided syntax
 * defintion. The syntax format will be used to determine the parsing method.
 * 
 * @param  arg           the argument string
 * @param  pos           the position in the argument string to begin search,
 *                       passed by reference and assigned the position of the
 *                       end of the parsed argument list
 * @param  syntax        the syntax being applied
 * @return the array of command line arguments found in argument string
 */
string *parse_args(string arg, int pos, mapping syntax) {
  switch (syntax[SYNTAX_FORMAT]) {
    case "sscanf":
      return parse_args_sscanf(arg, &pos, syntax[SYNTAX_PATTERN]);
    case "regexp":
      return parse_args_regexp(arg, &pos, syntax[SYNTAX_PATTERN]);
    case "parse_command":
      return parse_args_parse_command(arg, &pos, syntax[SYNTAX_PATTERN]);
    case "explode":
    default:
      return parse_args_explode(arg, &pos, syntax[SYNTAX_EXPLODE_ARGS]);
  }
  return 0;
}

/**
 * Parse the argument list out of an argument string using the explode method.
 * Using this method splits the entire string by whitespace and uses each
 * substring as an argument. Arguments that contain whitespace "may be quoted"
 * and the quoted string will be treated as a single argument. If an argument
 * limit is provided, the last argument in the returned argument list will 
 * gobble up all additional content in the argument string, even if it contains
 * whitespace.
 * 
 * @param  arg           the argument string
 * @param  pos           the position in the argument string to begin search,
 *                       passed by reference and assigned the position of the
 *                       end of the parsed argument list
 * @param  numargs       the expected number of arguments; the resulting
 *                       argument list may have fewer members, but never more
 * @return the array of command line arguments found in argument string
 */
string *parse_args_explode(string arg, int pos, int numargs) {
  string *args = ({ });
  if (numargs >= 0) {
    // hard arg limit
    while (sizeof(args) < numargs) {
      pos = find_nonws(arg, pos);
      if (sizeof(args) == (numargs - 1)) {
        // last arg consume entire string
        int end = match_quote(arg, pos);
        if (end == strlen(arg)) {
          // quoted string, unquote/unescape
          string param = arg[pos..end];
          param = unquote(param);
          param = unescape(param);
          args += ({ param });
          pos = end + 1;
        } else {
          // unquoted, add verbatim
          args += ({ args[pos..] });
          pos = strlen(arg);
        }
      } else {
        // normal arg, parse out
        string param;
        parse_param(arg, &pos, &param);
        if (param) {
          args += ({ param });
        }
      }
    }
  } else {
    // no arg limit
    args = explode_args(arg);
    pos = strlen(arg);
  }
  return args;
}

/**
 * Parse the argument list out of an argument string using the sscanf method.
 * Using this method takes an sscanf pattern and returns the matched 
 * substrings.
 * 
 * @param  arg           the argument string
 * @param  pos           the position in the argument string to begin search,
 *                       passed by reference and assigned the position of the
 *                       end of the parsed argument list
 * @param  pattern       the sscanf pattern; due to the nature of how the
 *                       internal call to sscanf() is made, there's a maximum
 *                       number of match operators that may be used, configured
 *                       in command.h
 * @return the array of command line arguments found in argument string
 */
string *parse_args_sscanf(string arg, int pos, string pattern) {
  if (!closurep(sscanf_args)) {
    mixed *sscanf_fragment = allocate(MAX_ARGS);
    mixed *eval_fragment = allocate(MAX_ARGS * 3);
    for (int i = 0; i < MAX_ARGS; i++) {
      sscanf_fragment[i] = quote("arg" + i);
      int j = i * 3;
      eval_fragment[j] = ({ i });
      eval_fragment[j + 1] = quote("arg" + 1);
      eval_fragment[j + 2] = #'break; //'
    }
    sscanf_args = lambda(({ 'arg, 'pattern }), 
      ({ #',, 
         ({ #'=, 
            'matches, 
            ({ #'sscanf, 'arg, 'pattern }) + sscanf_fragment 
         }), 
         ({ #'=, 'args, ({ #'allocate, 'matches }) }), 
         ({ #'=, 'i, 0 }), 
         ({ #'while, 
            ({ #'<, 'i, 'matches }), 
            'args, 
            ({ #'=, 
               ({ #'[, 'args, 'i }), 
               ({ #'switch, 'i }) + eval_fragment
            }), 
            ({ #'+=, 'i, 1 }) 
         }) 
      })
    ); //'
  }
  return funcall(sscanf_args, arg[pos..], pattern);
}

/**
 * Parse the argument list out of an argument string using a regular 
 * expression.
 * 
 * @param  arg           the argument string
 * @param  pos           the position in the argument string to begin search,
 *                       passed by reference and assigned the position of the
 *                       end of the parsed argument list
 * @param  pattern       the regular expression to apply
 * @return the array of command line arguments found in argument string
 */
string *parse_args_regexp(string arg, int pos, string pattern) {
  string *args = regmatch(arg, pattern, RE_MATCH_SUBS, pos);
  return args[1..];
}

/**
 * Parse the argument list out of an argument string using the the 
 * parse_command() method. This works similarly to the sscanf method, but uses
 * the parse_command() efun instead.
 * 
 * @param  arg           the argument string
 * @param  pos           the position in the argument string to begin search,
 *                       passed by reference and assigned the position of the
 *                       end of the parsed argument list
 * @param  pattern       the parse_command pattern; due to the nature of how 
 *                       the internal call to parse_command() is made, there's 
 *                       a maximum number of match operators that may be used, 
 *                       configured in command.h
 * @return the array of command line arguments found in argument string
 */
string *parse_args_parse_command(string arg, int pos, string pattern) {
  if (!closurep(parse_command_args)) {
    mixed *unmatched_fragment = allocate(MAX_ARGS);
    mixed *parse_command_fragment = allocate(MAX_ARGS);
    mixed *eval_fragment = allocate(MAX_ARGS * 3);
    for (int i = 0; i < MAX_ARGS; i++) {
      unmatched_fragment[i] = ({ #'=, quote("arg" + i), UNMATCHED_ARG }); //'
      parse_command_fragment[i] = quote("arg" + i);
      int j = i * 3;
      eval_fragment[j] = ({ i });
      eval_fragment[j + 1] = 
        ({ #'?, 
           ({ #'==, quote("arg" + i), UNMATCHED_ARG }), 
           ({ #'=, 'i, MAX_ARGS }), 
           ({ #'+=, 'args, quote("arg" + i) })
        });
      eval_fragment[j + 2] = #'break; //'
    }
    parse_command_args = lambda(({ 'arg, 'obs, 'pattern }), 
      ({ #',, 
         ({ #', }) + unmatched_fragment,
         ({ #'=, 
            'matched, 
            ({ #'parse_command, 'arg, 'obs, 'pattern }) + parse_command_fragment 
         }), 
         ({ #'?,
            'matched,
            ({ #',,
               ({ #'=, 'args, '({ }) }), 
               ({ #'=, 'i, 0 }), 
               ({ #'while, 
                  ({ #'<, 'i, MAX_ARGS }),
                  'args, 
                  ({ #'switch, 'i }) + eval_fragment, 
                  ({ #'+=, 'i, 1 }) 
               })
            }),
            '({ }),
         })
      })
    ); //'
  }
  return funcall(parse_command_args, arg[pos..], ({ }), pattern);
}

/**
 * Parse an opt or longopt parameter.
 * 
 * @param  arg           the argument string
 * @param  pos           the position in the argument string to begin search,
 *                       passed by reference and assigned the position of the
 *                       end of the parsed parameter
 * @param  param         the parsed parameter, passed by reference
 */
void parse_param(string arg, int pos, string param) {
  int end = match_quote(arg, pos);
  param = arg[pos..end];
  param = unquote(param);
  param = unescape(param);
  pos = end + 1;
}

/**
 * Advance the step field of a result model. It will be initialized if 
 * necessary.
 * 
 * @param  result        the result model
 * @return the result model, updated
 */
mapping advance_step(mapping result) {
  if (!member(result, STEP_FIELD)) {
    result[STEP_FIELD] = INITIAL_STEP;
  }
  result[STEP_FIELD]++;
  return result;
}

/**
 * Update the result model for a failure result.
 * 
 * @param  result        the result model
 * @return the result model, updated
 */
mapping fail_result(mapping result) {
  if (!member(result, STEP_FIELD)) {
    result[STEP_FIELD] = INITIAL_STEP;
  }
  result[STEP_FIELD] = -result[STEP_FIELD];
  return result;
}

/**
 * Update the result model for a success result.
 * 
 * @param  result        the result model
 * @return the result model, updated
 */
mapping pass_result(mapping result) {
  if (!member(result, STEP_FIELD)) {
    result[STEP_FIELD] = INITIAL_STEP;
  }
  return result;
}
