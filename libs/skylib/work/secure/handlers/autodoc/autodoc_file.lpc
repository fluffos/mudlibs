/**
 * The automatic document generator.  It takes source files from various
 * directories and creates help files from the comments embedded in the
 * code.
 *
 * @see /secure/handlers/autodoc/autodoc_handler
 * @author Pinkfish
 * @started Fri Oct 24 16:03:57 EDT 1997
 */

#include <autodoc.h>

#define EOF -1

nosave mapping private_functions;

mapping public_functions,
        protected_functions,
        inherits,
        main_docs,
        define_docs,
        includes,
        class_docs;

string file_name;

int last_changed, num_failed_tries;

// Temporary.
nosave string current_comment, current_file;
nosave int current_position, changed;

// We will only handle simple defines.  Function ones we will ignore.
nosave mapping defines;

private mapping parse_comment( string stuff );
private void do_parse_file( function func );
private int query_file_position();
private void handle_inherit( mixed bits );

/** @ignore yes */
private void setup() {
    changed = 0;
    main_docs = 0;
    file_name = "";
    private_functions = ([ ]);
    public_functions = ([ ]);
    protected_functions = ([ ]);
    inherits = ([ ]);
    defines = ([ ]);
    define_docs = ([ ]);
    includes = ([ ]);
    class_docs = ([ ]);
    current_comment = 0;
    current_file = "";
    current_position = 0;
    last_changed = 0;
} /* setup() */

/** @ignore yes */
void create() {
    seteuid(getuid());
    setup();
} /* create() */

/** @ignore yes */
private int query_file_position() { return current_position; }

/** @ignore yes */
private int lookahead_character( int num ) {
    if( current_position + num - 1 < strlen(current_file) )
        return current_file[ current_position + num - 1 ];
    return EOF;
} /* lookahead_character() */

/** @ignore yes */
private int next_character() {
    if( current_position < strlen(current_file) )
        return current_file[current_position++];
    return EOF;
} /* next_character() */

/** @ignore yes */
private int pop_character( int num ) { current_position += num; }

/**
 * @ignore yes
 * Throw away everything to the end of the line.
 */
private void skip_to_end_of_line() {
    int ch;

    do {
        ch = next_character();
    } while( ch != '\r' && ch != '\n' && ch != EOF );

} /* skip_to_end_of_line() */

/**
 * @ignore yes
 * Throw away all the characters until the end of the comment.
 */
private string skip_to_end_of_comment() {
    string data;
    int ch, ok;

    // This will pull all the stuff out of a comment and stick them into
    // a nice string.  Wheeee!
    data = "";
    do {
        ok = 1;
        ch = next_character();
        if( ch == '*' && lookahead_character(1) == '/' ) {
            // End of comment.
            ok = 0;
            pop_character(1);
        } else if( ch == '\r' || ch == '\n' ) {
            data += "\n";
            if( lookahead_character(1) == ' ' )
                pop_character(1);
            if( lookahead_character(1) == '*' && lookahead_character(2) != '/' ) {
                pop_character(1);
                if( lookahead_character(1) == ' ' )
                    pop_character(1);
            }
        } else if( ch == EOF ) {
            ok = 0;
        } else if( ch == '\\' && (
            lookahead_character(1) == '/' ||
            lookahead_character(1) == '*' ||
            lookahead_character(1) == '\\' ) ) {
            // Build up our comment stuff.
        } else {
            data += sprintf("%c", ch );
        }
    } while( ok );

    return data;

} /* skip_to_end_of_comment() */

/**
 * @ignore yes
 * Skips all the spaces and comments that are in our way.
 */
private void skip_spaces_and_comments() {
    int ok;

    do {
        switch( lookahead_character(1) ) {
            case ' ' :
            case '\t' :
            case '\n' :
            case '\r' :
              ok = 1;
              // Move our index up one.
              pop_character(1);
            break;
            case '/' :
              // Could be a comment.
              if( lookahead_character(2) == '/' ) {
                  ok = 1;
                  skip_to_end_of_line();
              } else if( lookahead_character(2) == '*' ) {
                  ok = 1;
                  if( lookahead_character(3) != '*' ||
                      lookahead_character(4) == '*' ) {
                      // Make sure it is not a code comment.
                      pop_character(2);
                      skip_to_end_of_comment();
                      current_comment = 0;
                  } else {
                      pop_character(3);
                      if( lookahead_character(1) == ' ' )
                          pop_character(1);
                      if( !main_docs )
                          main_docs = parse_comment( skip_to_end_of_comment() );
                      else
                          current_comment = skip_to_end_of_comment();
                  }
              } else {
                  ok = 0;
              }
            break;
            default :
              ok = 0;
              break;
        }
    } while (ok);

} /* skip_spaces_and_comments() */

/**
 * @ignore yes
 * Expands the defines...
 */
private string expand_token( string token ) { return defines[token]; }

/**
 * @ignore yes
 * Gets the next token...
 */
private string get_word() {
   string data;
   int ok;
   int ch;

   skip_spaces_and_comments();
   ok = 1;
   data = "";
   ch = lookahead_character(1);
   if( ( ch >= 'a' && ch <= 'z') ||
       ( ch >= 'A' && ch <= 'Z') ||
       ( ch == '_') ) {
       do {
          ch = lookahead_character(1);
          if ((ch >= 'a' && ch <= 'z') ||
              (ch >= 'A' && ch <= 'Z') ||
              (ch >= '0' && ch <= '9') ||
              (ch == '_')) {
             ch = next_character();
             data += sprintf("%c", ch);
          } else {
             ok = 0;
          }
       } while (ok);

       if( expand_token(data) ) {
           current_file = expand_token(data) + current_file[current_position..];
           current_position = 0;
           return get_word();
       }
   } else if( ( ch >= '0' && ch <= '9') || ch == '-') {
      if( ch == '-')
          data += sprintf("%c", next_character() );

      // Number, only search for number bits.
      do {
         ch = lookahead_character(1);
         if( ( ch >= '0' && ch <= '9') ||
             ( ch >= '.') ) {
             ch = next_character();
             data += sprintf("%c", ch);
         } else {
             ok = 0;
         }
      } while (ok);
   } else if( ch == '\"' || ch == '\'') {
      int end_ch;

      end_ch = ch;
      ch = next_character();
      data += sprintf("%c", ch);
      do {
         ch = next_character();
         if (ch == end_ch) {
            ok = 0;
            data += sprintf("%c", ch);
         } else if (ch == '\\') {
            // Skip the next character.
            ch = next_character();
            data += sprintf("\\%c", ch);
         } else if (ch == EOF) {
            ok = 0;
         } else {
            data += sprintf("%c", ch);
         }
      } while (ok);
   } else if (ch == '(') {
      if (lookahead_character(2) == '{' ||
          lookahead_character(2) == '[') {
         return sprintf("%c%c", next_character(), next_character());
      }
      return sprintf("%c", next_character());
   } else if (ch == '}' || ch == ']') {
      if (lookahead_character(2) == ')') {
         return sprintf("%c%c", next_character(), next_character());
      }
      return sprintf("%c", next_character());
   } else if (ch == ';' ||
              ch == ')' ||
              ch == '=' ||
              ch == '{' ||
              ch == '}') {
      // open brace, semi colon, close brace... is a special thingy.
      return sprintf("%c", next_character());
   } else if (ch == EOF) {
      return "";
   } else {
      // All non-space, non alphanumeric...  Dump together...
      do {
         ch = lookahead_character(1);
         if ((ch >= 'a' && ch <= 'z') ||
             (ch >= 'A' && ch <= 'Z') ||
             (ch >= '0' && ch <= '9') ||
             (ch == '_') ||
             (ch == ' ') ||
             (ch == '\t') ||
             (ch == '\n') ||
             (ch == '(') ||
             (ch == ')') ||
             (ch == EOF) ||
             (ch == ';') ||
             (ch == '=') ||
             (ch == '{') ||
             (ch == '}') ||
             (ch == '\'') ||
             (ch == '\"') ||
             (ch == '\r')) {
            ok = 0;
         } else {
            ch = next_character();
            data += sprintf("%c", ch);
         }
      } while (ok);
   }

   return data;

} /* get_word() */

/*
 * Attempts to get a complete statement...
 */
private mixed get_statement(string start) {
   mixed bits;
   string curr;
   int depth;
   string temp_comment;
   int last_pos;
   int in_class;

   // If it starts with the class keyword, then is must be a class.
   // We rip until a semi colon or an open brace.
   // If we find a semi colon...  Then it is a predef or an inherit
   // statement.
   bits = ({ start });
   do {
      last_pos = query_file_position();
      curr = get_word();
      bits += ({ curr });
      if( last_pos != query_file_position() ) {
          // Make sure it is doing something.
          reset_eval_cost();
      }
   } while (curr != ";" && curr != "{" && curr != "");

   if( curr == "{") {
      if( member_array("class", bits ) != -1 &&
          member_array("(", bits ) == -1 ) {
          // We have a class, now we need to parse this in a useful way.
          // Sadly this cannot fit into the normal way of parsing.  It is an
          // exception to one of those rules :)
          in_class = 1;
      }

      // Grab the rest...  but ignore it.
      // Keep the current comment though.
      temp_comment = current_comment;
      depth = 1;
      do {
        last_pos = query_file_position();
        curr = get_word();
        if (curr == "{") {
           depth++;
        } else if (curr == "}") {
           depth--;
        } else if (curr == "") {
           // End of file.
           depth = 0;
        }

        if( last_pos != query_file_position() ) {
            // Make sure it is doing something.
            reset_eval_cost();
        }
        if (in_class) {
           bits += ({ curr });
        }
      } while (depth > 0);
      current_comment = temp_comment;
   }

   return bits;
} /* get_statement() */

/*
 * This parses the comment into the appropriate bits...
 */
private mapping parse_comment(string stuff) {
   string *bits;
   int i;
   mapping frog;
   string name;
   int j;
   int rabbit;

   if( !stuff )
       return ([ ]);

   if( stuff[0] == '@') {
       stuff = "\n" + stuff;
   } else {
       stuff = "\n@main " + stuff;
   }

   bits = explode(stuff, "\n@");
   frog = ([ ]);

   for( i = 0; i < sizeof(bits); i++ ) {
      j = strsrch( bits[i], " ");
      rabbit = strsrch( bits[i], "\n");
      if( j == -1 || ( rabbit != -1 && rabbit < j ) ) {
          j = rabbit;
      }

      if( j > 0 ) {
         name = bits[i][0..j - 1];
         stuff = bits[i][j+1..];

         if( !frog[name] ) {
             frog[name] = ({ stuff });
         } else {
             frog[name] += ({ stuff });
         }
      }
   }

   return frog;

} /* parse_comment() */

/*
 * Handles a class...
 */
private void handle_class( mixed bits ) {
   string name;
   int i;
   string *types;
   mapping comm;

   name = bits[1];
   types = ({ });

   i = member_array("{", bits );

   if( i != -1 ) {
       // Ok, figure out all the elements and types.
       bits = bits[i + 1..];
       while( sizeof(bits) ) {
          i = member_array(";", bits);
          if( i != -1 ) {
              types += ({ ({ bits[i - 1], bits[0..i - 2] }) });
              bits = bits[i + 1..];
          } else {
              bits = ({ });
          }
       }

       comm = parse_comment(current_comment);
       if( !comm["ignore"] )
           class_docs[name] = ({ 0, types, parse_comment(current_comment) });
   }

} /* handle_class() */

/*
 * Handles an inherit...  Sticks all the needed stuff in like the
 * thing being inherited and the state of it and stuff.
 */
private void handle_inherit( mixed bits ) {
   int pos;
   string name;

   pos = member_array("inherit", bits );
   if( pos >= 0 ) {
       // Need to strip off the last thingy which should be a semi colon.
       name = implode( map( bits[pos+1.. sizeof(bits)-2],
           function( string str ) {
               if( str[0] == '\"') {
                   sscanf( str, "\"%s\"", str );
                   return str;
               }
               if( str = string_to_define(str) )
                   return str;
               return "";
           } ), "");
       inherits[name] = bits[0..pos-1];
   }
} /* handle_inherit() */

/*
 * We have found a function definition...  Create the information
 * we need from it.
 */
private void handle_function_definition(mixed bits) {
   int pos, end_pos, new_pos;
   string name, *type;
   mapping comm;
   mixed args;

   pos = member_array("(", bits );

   if( pos > 0 ) {
       name = bits[pos-1];
       if( !AUTODOC_H->exclude_method(name) ) {
           type = bits[0..pos-2];
           if( !sizeof(type) )
               type = ({"int"});
           end_pos = member_array(")", bits, pos );
           args = ({ });
           if( end_pos > pos + 1 ) {
               // Whoo, there are some arguments.
               pos++;
               while( member_array(",", bits, pos ) != -1 ) {
                   new_pos = member_array(",", bits, pos );
                   args += ({ bits[pos..new_pos-2], bits[new_pos-1] });
                   pos = new_pos + 1;
               }
               args += ({ bits[pos..end_pos -2], bits[end_pos-1] });
           }
           comm = parse_comment(current_comment);
           if( !comm["ignore"] ) {
               if( member_array("private", type ) != -1 ) {
                   type -= ({"private"});
                   private_functions[name] = ({ type, args, comm });
               } else if( member_array("protected", type ) != -1 ) {
                   type -= ({"protected"});
                   protected_functions[name] = ({ type, args, comm });
               } else {
                   type -= ({"public"});
                   public_functions[name] = ({ type, args, comm });
               }
           }
       }
       current_comment = 0;
   }
} /* handle_function_definition() */

/*
 * Gets the rest of the line.  Mostly used by the hash stuff...
 */
private string get_rest_of_line() {
   string value;
   int ch;
   int last_pos;

   value = "";
   // Skip the spaces at the start.
   ch = lookahead_character(1);
   while (ch == ' ' || ch == '\t') {
      pop_character(1);
      ch = lookahead_character(1);
   }

   // Get the whole definition.
   do {
      last_pos = query_file_position();
      ch = next_character();
      if (ch == '\\') {
         // Skip one!  This is escaped...
         ch = next_character();
         if (ch == '\r' && lookahead_character(1) == '\n') {
            // Handle MSDOS sillyness.
            ch = next_character();
         }
         ch = ' ';
      }
      if (last_pos != query_file_position()) {
         reset_eval_cost();
      }
      value += sprintf("%c", ch);
   } while (ch != '\n' && ch != '\r' && ch != EOF);

   return value;

} /* get_rest_of_line() */

/*
 * Handles the hairy #define's and #includes.
 */
private void handle_hash() {
   int i;
   string token;
   string name;
   string value;
   string *bits;
   string stuff;
   string inc_name;
   string curr_comm;
   mapping comm;

   token = get_word();

   // Not really sure what to do about these right now.
   switch (token) {
      case "define" :
      case "defin" :
         // Ok, with a define...  we... get a name and a substitution value.
         curr_comm = current_comment;
         value = get_rest_of_line();
         if (sscanf(value, "%s %s", name, value) == 2) {
            defines[name] = value;
            if (token == "define") {
               comm = parse_comment(curr_comm);
               if (!comm["ignore"]) {
                  define_docs[name] = comm;
               }
               current_comment = 0;
            }
         }
         break;
      case "include" :
         // Eeeek!  This will be evil... At the moment assume they don't
         // do arithmetic in the #include line...
         value = get_rest_of_line();
         if (value[0] == '\"') {
            // This means a local inherit...
            bits = explode(file_name, "/");
            sscanf(value, "\"%s\"", name);
            stuff = read_file(implode(bits[0..<2], "/") +
                              "/" + name);
            if (stuff) {
               inc_name = "/" + implode(bits[0..<2], "/") +
                              "/" + name;
            }
         } else if (value[0] == '<') {
            // This means it could be a global inherit...
            sscanf(value, "<%s>", name);
         }

         if( name[0] == '/') {
             stuff = read_file(name);
             if( stuff )
                 inc_name = name;
         }

         bits = master()->define_include_dirs();

         while( !stuff && i < sizeof(bits) ) {
            stuff = read_file( sprintf(bits[i], name ) );
            if( stuff ) {
               // Remove all the autodoc comments from the include file...
               stuff = replace_string( stuff, "/**", "/* ");
               // Ignore included classes.
               stuff = replace_string( stuff, "class ", "clas ");
               stuff = replace_string( stuff, "#define ", "#defin ");
               inc_name = sprintf( bits[i], name );
            }
            i++;
         }

         if( inc_name ) {
            // Zap double '//'s
            inc_name = replace( inc_name, "//", "/");
            if( inc_name[0] != '/')
                inc_name = "/" + inc_name;
         }

         if( stuff ) {
             // We found it!  Stick the include bit in where it is needed.
             if( !includes[inc_name] ) {
                 current_file = stuff + current_file[current_position..];
                 current_position = 0;
             }
             // Update the time as well.
             includes[inc_name] = unguarded( (: stat($(inc_name)) :) )[1];
         }
         break;
      default :
         // Pragma's and other silly hash things.
         skip_to_end_of_line();
         break;
   }
} /* handle_hash() */

/*
 * Gets the next token...  This is state dependant, we need to know
 * what state we are in to figure out what sort of token we are probably
 * looking for...
 */
private void next_statement() {
   string token;
   string *bits;

   token = get_word();
   // A hash directive.
   if( token[0] == '#') {
       return handle_hash();
   } else if (token == ";") {
       return ;
   } else if (token != "") {
       bits = get_statement(token);
       if( member_array("inherit", bits) != -1 ) {
           // An inherit statement.
           return handle_inherit(bits);
       } else if( bits[0] == "class" && member_array("(", bits) == -1 ) {
           return handle_class(bits);
       } else if( bits[sizeof(bits) - 1] == "{" &&
           member_array("=", bits) == -1 ) {
           return handle_function_definition(bits);
       } else {
           // It was a predef or a variable declaration.
           return;
       }
   }
} /* next_statement() */

/**
 * Loads up the currently set file name from the archives.
 */
void load_file() {
   unguarded( (: restore_object( AUTODOC_SAVE_DIR +
                 replace_string(file_name, "/", ".") ) :) );

   if( !includes )
       includes = ([ ]);
   if( !class_docs )
       class_docs = ([ ]);

} /* load_file() */

/**
 * Saves the current file name to the archives.
 */
void save_file() {
   unguarded( (: save_object( AUTODOC_SAVE_DIR +
                 replace_string(file_name, "/", ".") ) :) );
} /* save_file() */

/**
 * Parses the input file figuring out all the documentation bits of it.
 * @param name the name of the file to parse
 * @param func the function to call when the parsing is finished
 * @param only_load a flag telling us to only load the information
 */
void parse_file( string name, function func, int only_load ) {
   int curr_change, reload;
   string my_name, new_file;

   setup();
   file_name = name;
   load_file();

   if( !only_load ) {
       if( sizeof( unguarded( (: stat($(name)) :) ) ) ) {
           if( file_size(name) != -2 ) {
               curr_change = unguarded( (: stat($(name)) :) )[1];
           } else {
               AUTODOC_H->remove_file(name);
               if( name[<1] != '/')
                   name += "/";
               foreach( new_file in unguarded( (: stat($(name)) :) ) ) {
                   if( file_size(name+new_file) != -2 &&
                       new_file[sizeof(new_file)-2..sizeof(new_file)] )
                       AUTODOC_H->add_file(name+new_file);
               }
               if( func )
                   call_out( (: evaluate($1) :), 2, func );
               return;
           }

           reload = curr_change > last_changed || file_name(PO) == AUTODOC_H;

           if( !reload ) {
               // Check to see if the include files have changed.
               foreach( my_name in keys(includes) ) {
                   if( unguarded( (: file_exists($(my_name)) :) ) ) {
                       new_file = AUTODOC_SAVE_DIR +
                                  replace_string(my_name, "/", ".")+".o";

                       // Add all missing includes to the handler.
                       if( !unguarded( (: file_exists($(new_file)) :) ) ) {
                           event( users(), "inform", "Autodoc: Adding \""+
                               my_name+"\"", "autodoc");
                           AUTODOC_H->add_file(my_name);
                           reload = 1;
                           continue;
                       }

                       if( unguarded( (: stat($(my_name)) :) )[1] >
                           unguarded( (: stat($(new_file)) :) )[1] ) {
                           event( users(), "inform", "Autodoc: Updating \""+
                               my_name+"\" - \""+new_file+"\" outdated",
                               "autodoc");
                           reload = 1;
                           break;
                       }
                   }
               }
           }

           if( reload ) {
               setup();
               num_failed_tries = 0;
               file_name = name;
               changed = 1;
               last_changed = curr_change;
               current_file = read_file(name);
               current_position = 0;
               event( users(), "inform", "Autodoc: Parsing \""+file_name+"\"",
                   "autodoc");
               if( catch( do_parse_file(func) ) )
                   evaluate(func);
           } else {
               if( num_failed_tries ) {
                   num_failed_tries = 0;
                   save_file();
               }
               event( users(), "inform", "Autodoc: Skipping \""+file_name+"\"",
                   "autodoc");
               if( func )
                   call_out( (: evaluate($1) :), 2, func );
           }
       } else {
           event( users(), "inform", "Autodoc: No file \""+file_name+"\"",
               "autodoc");
           num_failed_tries++;
           save_file();
           if( func )
               call_out( (: evaluate($1) :), 2, func );
       }
   } else {
       if( func )
           call_out( (: evaluate($1) :), 2, func );
   }

} /* parse_file() */

/** @ignore yes */
private void do_parse_file( function func ) {
   int num;

   // Darn, changed while we were reading it.
   if( file_size(file_name) != -2 &&
       unguarded( (: stat(file_name) :) )[1] > last_changed )
       return parse_file( file_name, func, 0 );

   num = 0;

   while( lookahead_character(1) != EOF && num < 2 ) {
       next_statement();
       num++;
   }

   if( lookahead_character(1) == EOF ) {
       save_file();
       if( func )
           call_out( (: evaluate($1) :), 2, func );
   } else {
       call_out( (: do_parse_file :), 1, func );
   }

} /* do_parse_file() */

/**
 * Returns the inherits mapping of the system.  This returns a mapping of the
 * form ([ inherit_name : ({ flags }) ]).  Where the name of the inherit is
 * something like "/std/object" and the flags are things you can apply to
 * an inherit, like "protected" or "private".  If there are no flags then
 * the flags will be an empty array.
 * @return a mapping of things inherited by this file
 */
mapping query_inherits() { return inherits; }

/**
 * The mapping of private functions.
 * The mapping is of the form ([ func_name : ({ type, args, docs }) ]).
 * The type bit is an array of the type name, ie: ({ "int" }) or
 * ({ "mixed", "*" }).  The args bit looks like ({ "name", type }),
 * where the type is the same as in the previous array.  The docs is
 * a mapping of the form ([ "tag" : ({ data }) ]), where each reference
 * to a tag creates a new element in the data array.
 * @return a mapping containing the private functions
 */
mapping query_private_functions() { return private_functions; }

/**
 * The mapping of public functions.
 * The mapping is of the form ([ func_name : ({ type, args, docs }) ]).
 * The type bit is an array of the type name, ie: ({ "int" }) or
 * ({ "mixed", "*" }).  The args bit looks like ({ "name", type }),
 * where the type is the same as in the previous array.  The docs is
 * a mapping of the form ([ "tag" : ({ data }) ]), where each reference
 * to a tag creates a new element in the data array.
 * @return a mapping containing the public functions
 */
mapping query_public_functions() { return public_functions; }

/**
 * The mapping of protected functions.
 * The mapping is of the form ([ func_name : ({ type, args, docs }) ]).
 * The type bit is an array of the type name, ie: ({ "int" }) or
 * ({ "mixed", "*" }).  The args bit looks like ({ "name", type }),
 * where the type is the same as in the previous array.  The docs is
 * a mapping of the form ([ "tag" : ({ data }) ]), where each reference
 * to a tag creates a new element in the data array.
 * @return a mapping containing the protected functions
 */
mapping query_protected_functions() { return protected_functions; }

/**
 * Returns the main docs for the class.  The mapping is of
 * the form ([ "tag" : ({ data }) ]), where each reference
 * to a tag creates a new element in the data array.
 * @return a mapping containing the main docs for the file
 */
mapping query_main_docs() { return main_docs || ([ ]); }

/**
 * The file name being processed.
 * @return the name of the file being processed
 */
string query_file_name() { return file_name; }

/**
 * The defines which were setup in the class.  This is the mapping of the
 * defines which were processed.  The format of the mapping is
 * ([ "name" : "value" ]), where the name is the name of the define and
 * the value is what to replace it with.
 * @return the mapping of defines
 */
mapping query_defines() { return defines; }

/**
 * Did the file change?  Checks to see if the file changed since it
 * was last read.
 * @return 1 if it changed, 0 if it has not changed
 */
int query_changed() { return changed; }

/**
 * This method returns the number of times the file was attempted to
 * be read and it was discovered not to exist at all.
 * @return the number of times it was unable to be read
 */
int query_num_failed_tries() { return num_failed_tries; }

/**
 * The files included by this one.
 * @return an array of included files
 */
string *query_includes() { return keys(includes); }

/** @ignore yes */
mapping query_all_includes() { return includes; }

/**
 * The documentation for the defines.  This is mostly used by the include
 * file documentation system.
 * @return the mapping of define names to documentation
 */
mapping query_define_docs() { return define_docs; }

/**
 * The documentation for the classes.
 * @return the mapping of the class names to documentation
 */
mapping query_class_docs() { return class_docs; }

/** @ignore yes */
void dest_me() { destruct(TO); }
