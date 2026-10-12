/**
 * Utility library for manipulating strings. A mostly straight port of
 * AcmeGetOpts. This is mostly around for nostalgiac reasons, you should be
 * using CommandController.
 * 
 * @author devo@eotl
 * @alias GetoptsLib
 */

protected mixed *getopts(string *args, string validopts);
protected mixed *getopts_long(string *args, string validopts, 
                              mapping longopts);

/**
 * Searches an argument list for valid command-line options, as described by
 * validopts. validopts is a list of valid options, or 0 to accept any 
 * option. An option character may be followed by a ":" to indicate the 
 * option requires an argument; and may be followed by a - to indicate it
 * requires an option and may be specified more than once. 
 * 
 * <p>Returns an array of the form: <code>({ string *other_args, mapping 
 * options, string badopts })</code>, where other_args is the new list of 
 * command line arguments with the options parsed out. options is a mapping 
 * wherein the keys are the ASCII value of the option character, and the 
 * value is the string argument passed to that option, or an array of all 
 * arguments passed to that option if specified with ":" and "-" 
 * respectively. Finally, badopts is a string of any options found but not 
 * specified in the validopts string, or specified to take an argument but
 * no argument was given.
 *
 * <p>An arg of "--" can be used to explicitly mark the end of options. The
 * "--" will be consumed and any args after this will be left alone.
 * 
 * @param  args      the argument list to search
 * @param  validopts a string designating valid options
 * @return           a 3 element array additional args, options, and bad 
 *                   options
 */
protected mixed *getopts(string *args, string validopts) {
  string badopts = "";
  mapping options = ([ ]);
  int anyopt;
 
  if (validopts) {
    // pad it to make checking for ':' easier
    validopts += " ";
  } else {
    // any option will be gathered
    anyopt = 1;
  }
  
  int i = 0;
  for (int size = sizeof(args); i < size; i++ ) {
    // Reached a non-option
    if (args[i][0] != '-') { break; }  
    
    if (args[i] == "--") {  
      // Explicit end of options
      // increment past this so we don't keep it
      i++;                   
      break;
    }
 
    // Stray '-'.  Skip it
    if (args[i] == "-") { continue; }
    
    for (int j = 1, int sz = strlen(args[i]) - 1; j < sz; j++) {
      int opt = args[i][j];
      int pos;
      if (anyopt 
        || ( ((pos = member(validopts, opt)) > -1)
          && (validopts[pos+1] != '-') 
          && (validopts[pos+1] != ':') )) {
        options[opt] = 0;
      } else {
        badopts += args[i][j..j];
      }
    }
 
    // Extract the option char  ('s' from "-s")
    int opt = args[i][<1];
    
    if (anyopt) {
      options[opt] = 0;
      continue;
    }
    
    int pos = member(validopts, opt);
    if (pos > -1) { 
      // Valid option
      if (validopts[pos+1] == ':') { 
        // This option takes an argument
        if (++i < size) {
          // If we're not at the end
          options[opt] = args[i];
          continue;
        }
      } else if (validopts[pos+1] == '-') { 
        // This option takes an argument and can be repeated. 
        if (++i < size) {
          // If we're not at the end
          if (!pointerp(options[opt])) {
            options[opt] = ({ });
          }
          options[opt] += ({ args[i] });
          continue;
        }
      } else {
        options[opt] = 0;
        continue;
      }
    }
 
    // If we made it this far, the option is either invalid or requires and 
    // arg and wasn't given one.
    badopts = sprintf("%s%c", badopts, opt);
  }
 
  return ({ args[i..], options, badopts });
}
 
/**
 * Searches an argument list for valid command-line options, as described by
 * validopts and longopts. validopts is a list of valid options, or 0 to 
 * accept any option. An option character may be followed by a ":" to 
 * indicate the option requires an argument; and may be followed by a - to 
 * indicate it requires an option and may be specified more than once. 
 * longopts is a mapping of valid long options, where the keys are the option
 * string, and the value is an integer designating the type of option: 0 for
 * standard long options, 1 for options which take an argument, and -1 for
 * options which take an argument and may be specified more than once.
 * 
 * <p>Returns an array of the form: <code>({ string *other_args, mapping 
 * options, string badopts })</code>, where other_args is the new list of 
 * command line arguments with the options parsed out. options is a mapping 
 * wherein the keys are the ASCII value of the option character, and the 
 * value is the string argument passed to that option, or an array of all 
 * arguments passed to that option if specified with ":" and "-" 
 * respectively. This mapping will also contain longopts, in which case the
 * mapping key is the entire string of the option name. Finally, badopts is 
 * an array of any options found but not specified as validopts or longopts,
 * or specified to take an argument but no argument was given.
 *
 * <p>An arg of "--" can be used to explicitly mark the end of options. The
 * "--" will be consumed and any args after this will be left alone.
 * 
 * @param  args      the argument list to search
 * @param  validopts a string designating valid options
 * @param  longopts  a mapping of long options to their option type
 * @return           a 3 element array additional args, options, and bad 
 *                   options
 */
protected mixed *getopts_long(string *args, string validopts, 
                              mapping longopts) {
  mixed *badopts = ({ });
  mapping options = ([ ]);
  int anyopt, anylongopt;
 
  if (validopts) {
    // pad it to make checking for ':' easier
    validopts += " ";
  } else {
    // any option will be gathered
    anyopt = 1;
  }
 
  if (!mappingp(longopts)) {
    anylongopt = 1;
  }
 
  int i = 0;
  for (int size = sizeof(args); i < size; i++) {
    // Reached a non-option
    if (args[i][0] != '-') { break; }
    
    if (args[i] == "--") {
      // Explicit end of options
      // increment past this so we don't keep it
      i++;
      break;
    }
  
    // Stray '-'.  Skip it
    if (args[i] == "-" ) { continue; }
    
    if (args[i][1] != '-') {
      for (int j = 1, int sz = strlen(args[i]) - 1; j < sz; j++) {
        int opt = args[i][j];
        if (anyopt 
          || (member(validopts, opt) > -1)) {
          options[ opt ] = 0;
        } else {
          badopts += ({ opt });
        }
      }
    }

    // Extract the option char  ('s' from "-s")
    int opt = args[i][<1];
 
    if (args[i][1] == '-') {
      // It's a long option
      // We already checked for "--"
      string longopt = args[i][2..];
      if (anylongopt) {
        options[longopt] = 0;
        continue;
      }
      
      if (!member(longopts, longopt)) {
        badopts += ({ longopt });
        continue;
      }
 
      if (longopts[longopt] > 0) {
        // This option takes an argument
        if (++i < size) {
          // If we're not at the end
          options[longopt] = args[i];
        } else {  
          // Ran out of args
          badopts += ({ longopt });
        }        
      } else { 
        if (longopts[longopt] < 0) { 
          // This option takes an argument that can be used more than once.
          if (++i < size) {
            // If we're not at the end
            if (!pointerp(options[longopt])) {
              options[longopt] = ({ });
            }
            options[longopt] += ({ args[i] });
          } else { 
            // Ran out of args
            badopts += ({ longopt });
          }        
        } else {
          // Doesn't take an argument
          options[longopt] = 0;
        }
      }
      continue;      
    } // End of longopts
    
    if (anyopt) {
      options[opt] = 0;
      continue;
    }
    
    int pos = member(validopts, opt);
    if (pos > -1) { 
      // Valid option
      if (validopts[pos + 1] == ':') {
        // This option takes an argument
        if (++i < size) {
          // If we're not at the end
          options[opt] = args[i];
          continue;
        }
      } else {
        if (validopts[pos+1] == '-') { 
          // This option takes an argument and can be repeated.
          if (++i < size) {
            // If we're not at the end
            if (!pointerp(options[opt])) {
              options[opt] = ({ });
            }
            options[opt] += ({ args[i] });
            continue;
          }
        } else {
          options[opt] = 0;
          continue;
        }
      }
    }
 
    // If we made it this far, the option is either invalid or requires and 
    // arg and wasn't given one.
    badopts += ({ opt });
  }
 
  return ({ args[i..], options, badopts });
}
 
