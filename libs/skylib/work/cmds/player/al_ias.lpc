#include <alias.h>

inherit COMMAND_BASE;

private nosave string gfilter;
/**
 * Turn the compiled alias array into a string.
 * @param al the alias array
 * @return the string value of the alias array
 * @see compile_alias()
 */
string alias_string( mixed al ) {
   int i, num, *add_thing;
   string str;

    str = "";
    add_thing = ({ });

    for( i = 0; i < sizeof(al); i++ ) {
        if( stringp(al[i]) ) {
            str += replace( al[i], ({";", "\\;"}) );
        } else {
            num = al[i] & ALIAS_MASK;
            switch( al[i] - num ) {
            case NEW_LINE  :
               str += ";";
               break;
            case ALL_ARGS  :
               str += "$*$";
               break;
            case ONE_ARG   :
               str += "$"+num+"$";
               break;
            case TO_ARG    :
               str += "$*"+num+"$";
               break;
            case FROM_ARG  :
               str += "$"+num+"*$";
               break;
            case ALL_ARG   :
               str += "$arg:"+al[++i]+"$";
               break;
            case ARG_THING :
               str += "$arg"+num+":"+al[++i]+"$";
               break;
            case ELSE_THING :
              str += "$else$";
              break;
            case ALL_IFARG :
               str += "$ifarg:";
               break;
            case IFARG_THING :
               str += "$ifarg"+num+":";
               break;
            case CURR_LOC :
               str += "$!$";
               break;
            case END_IF      :
               str += "$endif$";
               break;
            }
        }
    }

    return str;

} /* alias_string() */

/**
 * Prints out all the aliases on the player object.  This is called by the
 * alias command when no arguments are specified.
 * @return 0 if no aliases are defined, 1 if they are
 * @see alias()
 */
int print_aliases( string filter, int sorted ) {
    int len, cols;
    string str, str1, str2, *tmp, bing, key;
    mapping aliases;
    string ret;

    aliases = TP->query_aliases();

    if( !sizeof(aliases) )
        return notify_fail("You have defined no aliases.\n");

    str1 = "";
    str2 = "";

    tmp = keys(aliases);
    if( filter && !regexp( filter, "[\\[\\]\\(\\)]+") ) {
        gfilter = "^" + filter;
        tmp = filter( tmp, (: regexp( $1, gfilter ) :) );
    }

    tmp = sort_array( tmp, 1 );
    ret = "";
    cols = (int)TP->query_cols();

    foreach( key in tmp ) {
        if( !key ) {
            map_delete( aliases, 0 );
            continue;
        }

        bing = alias_string( aliases[key] );
        if( !bing )
            bing = "Error in the alias!";

        str = key+": "+bing;
        if( strlen(str) > 39 || sorted ) {
            len = cols - strlen(key) - 2;
            if( len < 0 )
                len = 10;
            // If it is too long, print it right now.
            ret += sprintf( key+": %-=*s\n", len, bing );
        } else if( strlen(str) > 19 ) {
            str1 += str+"\n";
        } else {
            str2 += str+"\n";
        }
    }

    if( strlen(str1) )
        ret += sprintf("%-#*s\n", cols, str1 );

    if( strlen(str2) )
        ret += sprintf("%-#*s\n", cols, str2 );

    ret += sprintf("A total of %d aliases.\n", sizeof(tmp) );

    TP->more_string(ret);
    return 1;

} /* print_aliases() */

/**
 * Creates the compiled alias array.  See the alias.h file for the
 * definitions of thevalues in the alias array.
 * @param str the string to compile
 * @return the compiled alias array
 * @see /include/alias.h
 */
mixed compile_alias( string str ) {
    int i, space, tmp, gumby, nodollar;
    mixed ret, ifargs;
    string *frog, s1;

    str = replace( str, ({"\\;", "$escaped$", ";", "$new_line$", " ", " "}) );
    str = replace( str, "$escaped$", ";");
    str = "&"+str+"&";
    frog = explode( str, "$");

    if( frog[0] == "&")
       frog = frog[1..];
    else
       frog[ 0 ] = frog[ 0 ][ 1 .. ];

    s1 = frog[<1];
    if( s1 == "&" )
        frog = frog[0..<2];
    else
        frog[<1] = s1[0..<2];

    ret = ({ });
    ifargs = ({ });
    nodollar = 1;

    for( i = 0; i < sizeof(frog); i++ ) {
        switch( frog[i] ) {
        case "new_line" :
          ret += ({ NEW_LINE });
          nodollar = 1;
        break;
        case "*" :
          ret += ({ ALL_ARGS });
          gumby = 1;
          nodollar = 1;
        break;
        case "!" :
          if( creatorp(TO) ) {
              ret += ({ CURR_LOC });
              nodollar = 1;
          }
        break;
        case "else" :
          if( sizeof(ifargs) ) {
              ret[ifargs[sizeof(ifargs)-1]] = sizeof(ret)-
                  ifargs[sizeof(ifargs)-1]+1;
              ret += ({ ELSE_THING, 0, ""});
              ifargs[sizeof(ifargs)-1] = sizeof(ret)-2;
              nodollar = 1;
          }
        break;
        case "~" :
        case "endif" :
          if( sizeof(ifargs) ) {
              ret += ({ END_IF });
              ret[ifargs[sizeof(ifargs)-1]] = sizeof(ret)-
                  ifargs[sizeof(ifargs)-1];
              ifargs = delete( ifargs, sizeof(ifargs)-1, 1 );
              nodollar = 1;
              space = 1;
          }
        break;
        default :
          if( frog[i][0..4] == "ifarg") {
              if( sscanf( frog[i], "ifarg%d:%s", tmp, s1 ) == 2 ) {
                  if( tmp < 0 )
                      tmp = 0;
                  if( tmp > ALIAS_MASK )
                      tmp = ALIAS_MASK;
                  ret += ({ IFARG_THING+ tmp, 0, ""});
                  frog[i--] = s1;
                  nodollar = 1;
                  ifargs += ({ sizeof(ret)-2 });
                  space = 0;
                  gumby = 1;
              } else if( frog[i][5] == ':') {
                  ret += ({ ALL_IFARG, 0, ""});
                  frog[i] = frog[i][6..];
                  nodollar = 1;
                  ifargs += ({ sizeof(ret)-2 });
                  space = 0;
                  gumby = 1;
                  i--;
              } else {
                  if( sizeof(ret) && stringp(ret[sizeof(ret)-1]) && !space ) {
                      ret[sizeof(ret)-1] += "$"+frog[i];
                  } else if( nodollar ) {
                      ret += ({ frog[i] });
                      nodollar = 0;
                  } else {
                      ret += ({ "$"+frog[i] });
                  }
              }
          } else if( frog[i][0..2] == "arg") {
              if( sscanf(frog[i], "arg%d:%s", tmp, s1 ) == 2 ) {
                  if( tmp < 0 )
                      tmp = 0;
                  if( tmp > ALIAS_MASK)
                      tmp = ALIAS_MASK;
                  ret += ({ ARG_THING+ tmp, s1, ""});
                  nodollar = 1;
                  gumby = 1;
              } else if( frog[i][3] == ':') {
                  ret += ({ ALL_ARG, frog[i][4..100], ""});
                  nodollar = 1;
                  gumby = 1;
              } else {
                  if( sizeof(ret) && stringp(ret[sizeof(ret)-1]) && !space ) {
                      ret[sizeof(ret)-1] += "$"+frog[i];
                  } else if( nodollar ) {
                      ret += ({ frog[i] });
                      nodollar = 0;
                  } else {
                      ret += ({ "$"+frog[i] });
                  }
                  gumby = 1;
                  space = 0;
              }
          } else if( strlen(frog[i]) && frog[i][<1] == '*' &&
              sscanf( frog[i], "%d%s*", tmp, s1 ) == 2 && s1 == "") {
              if( tmp < 0 )
                  tmp = 0;
              if( tmp > ALIAS_MASK )
                  tmp = ALIAS_MASK;
              ret += ({ FROM_ARG + tmp });
              gumby = 1;
              nodollar = 1;
          } else if( strlen(frog[i]) && frog[i][0] == '*' &&
              sscanf( frog[i][1..1000], "%d%s", tmp, s1 ) == 2 && s1 == "") {
              if( tmp < 0 )
                  tmp = 0;
              if( tmp > ALIAS_MASK )
                  tmp = ALIAS_MASK;
              ret += ({ TO_ARG + tmp });
              gumby = 1;
              nodollar = 1;
          } else if( sscanf( frog[i], "%d%s", tmp, s1 ) == 2 && s1 == "") {
              if( tmp < 0 )
                  tmp = 0;
              if( tmp > ALIAS_MASK )
                  tmp = ALIAS_MASK;
              ret += ({ ONE_ARG + tmp });
              gumby = 1;
              nodollar = 1;
          } else {
              if( !nodollar )
                  frog[i] = "$"+frog[i];

              nodollar = 0;
              space = 0;

              if( strlen(frog[i]) && frog[i][<1] == '~') {
                  if( sizeof(ifargs) ) {
                      if( strlen(frog[i]) == 1 )
                          frog[i] = "";
                      else
                          frog[i] = frog[i][0..<2];
                      // Create an offset.
                      ret += ({ END_IF });
                      ret[ifargs[<1]] = sizeof(ret) - ifargs[<1];
                      ifargs = ifargs[0..<2];
                      nodollar = 1;
                      space = 1;
                  }
              }

              if( sizeof(ret) && stringp(ret[<1]) && space != 2 )
                  ret[<1] += frog[i];
              else
                  ret += ({ frog[i] });

              if( space )
                  space = 2;
          }
        }

    }

    while( sizeof(ifargs) ) {
        ret += ({ END_IF });
        ret[ifargs[sizeof(ifargs)-1]] = sizeof(ret)-
            ifargs[sizeof(ifargs)-1];
        ifargs = delete( ifargs, sizeof(ifargs)-1, 1 );
    }

    if( !gumby ) {
        if( sizeof(ret) && !stringp(ret[sizeof(ret)-1]) || space ) {
            ret += ({ " ", ALL_ARGS });
        } else if( sizeof(ret) ) {
           ret[sizeof(ret)-1] += " ";
           ret += ({ ALL_ARGS });
        }
    }

    return ret;

} /* compile_alias() */

/**
 * This method will print out one or more aliases.
 * @param str the aliases to print
 */
int print_some_aliases( string str ) {
    if( TP->is_alias(str) ) {
        printf("%s: %-=*s\n", str, (int)TP->query_cols() - strlen(str) -2,
            alias_string( TP->query_player_alias(str) ) );
        return 1;
    }

    return print_aliases( str, 0 );

} /* print_some_aliases() */

/**
 * The main alias control function.  Sets up new aliases and prints out
 * the values of single aliases or all the aliases.
 * @param str the command name
 * @return 0 if the alias command failed, 1 if it succeeded
 * @see edit_alias()
 * @see print_aliases()
 */
protected int alias( string name, string value ) {
#ifdef DISALLOW_COLOUR
    if( strsrch( name, "%^") > -1 || strsrch( value, "%^") > -1 )
        return notify_fail("You cannot add an alias with a colour escape "
                           "sequence (% ^).\n");
#endif

    if( name == ".plan" || name == ".project" || name == ".signature") {
        if( sizeof(value) > MAX_PLAN_LENGTH )
            return notify_fail("Sorry, the maximum length of .plan, .project "
                "and .signature aliases is "+MAX_PLAN_LENGTH+" characters.\n");
    }

    if( sizeof(value) > MAX_ALIAS_LENGTH )
        return notify_fail("Sorry, the maximum alias length is "+
            MAX_ALIAS_LENGTH+" characters.\n");

    name = implode( explode( name, " "), "");
    write( ( !TP->is_alias(name) ? "Added" : "Changed")+" alias '"+
        name+"'.\n");
    TP->add_player_alias( name, compile_alias(value) );
    return 1;

} /* alias() */

/** @ignore yes */
mixed query_patterns() {
    return ({
        "", (: print_aliases("", 0) :),
        "sorted", (: print_aliases("", 1) :),
        "<word'alias'>", (: print_some_aliases($4[0]) :),
        "<word'alias'> <string>", (: alias($4[0], $4[1]) :)
        });
} /* query_patterns() */
