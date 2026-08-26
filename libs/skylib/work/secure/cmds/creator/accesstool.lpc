/**
 * accesstool.c
 * The Access Control Tool
 * for the admtool
 * Shaydz 2 Apr '00
 */

#include <colors.h>
#include <access.h>

inherit COMMAND_BASE;

private mapping return_mapping = ([ ]);
private string main_menu_template = @END
-------------------------------------------------------------------------
%s
-------------------------------------------------------------------------
  %sCommand                                      Status%s

  [1]  Grant access to creator                 %s
  [2]  Revoke access from creator              %s
  [3]  List access                             %s

END;

private string main_prompt = "Enter your command [1-3], or [Q] to quit: ";
private string main_prompt2 = "Enter your command [1-3], [B] to go back, or [Q] to quit: ";

int cmd(string str);
private void get_command(string str);
private void add_creator(string str);
private void add_creator2(string str, string str2);
private void add_creator3(string path, string name, int mask);
private void revoke_creator(string str);
private void revoke_creator2(string str, string str2);
private void revoke_creator3(string path, string name, int mask);
string access_string(int access_flags);
private void do_summary(string str);
private string user_access(string);
private string list_access(string);

private void display_menu() {
    string title, s1, s2, s3;

    title = sprintf("%s%|72s%s", YELLOW, mud_name()+" Access Control Tool "
        "v1.5", RESET );

    s1 = s2 = s3 = RED+"Unavailable"+RESET;

    if( creatorp(TP) ) {
        s3 = GREEN+"Available"+RESET;
        s2 = s1 = MAGENTA+"Limited"+RESET;
    }

    if( adminp(TP) )
        s1 = s2 = s3 = GREEN+"Available"+RESET;

    tell_object( TP, sprintf( main_menu_template, title, BOLD, RESET,
        s1, s2, s3 ) );

} /* display_menu() */

private void do_prompt() {
    tell_object( TP, undefinedp(return_mapping[TP]) ? main_prompt :
                                                      main_prompt2 );
    input_to( (: get_command :) );
} /* do_prompt() */

private void add_creator( string str ) {
    if( !str || str == "")
        return do_prompt();

    if( !creatorp( str = lower_case(str) ) ) {
        tell_object( TP, RED+"\n"+CAP(str)+" is not a creator.\n"+RESET );
        return do_prompt();
    }

    tell_object( TP, "Enter the type of access to grant, "
        "(r)ead, (w)rite, (g)rant, [rwg]: ");

    input_to( (: add_creator2( $1, $(str) ) :) );

} /* add_creator() */

private void add_creator2( string str, string str2 ) {
    int mask;

    if( !str || str == "")
        return do_prompt();

    foreach( int flag in str ) {
        switch( flag ) {
          case 'r':
            mask |= READ_MASK;
          break;
          case 'w':
            mask |= WRITE_MASK;
          break;
          case 'g':
            if( !adminp(TP) ) {
                tell_object( TP, RED+"\nYou don't have permission to give "
                    "grant access."+RESET+"\n");
                return do_prompt();
            }
            mask |= GRANT_MASK;
          break;
          default:
            tell_object( TP, RED+"\n"+sprintf("Invalid access type - '%c'.\n",
                flag )+RESET );
            return do_prompt();
        }
    }

    if( mask < 1 ) {
        tell_object( TP, RED+"\nGrant cancelled.\n"+RESET );
        return do_prompt();
    }

    tell_object( TP, "Enter full directory path to give "+CAP(str2)+" access "
        "to (without the trailing /): ");
    input_to( (: add_creator3( $1, $(str2), $(mask) ) :) );

} /* add_creator2() */

private void add_creator3( string path, string name, int mask ) {
    string old;

    if( !path || path == "")
        return do_prompt();

    if( path != "/" && path[<1] == '/')
        path = path[0..<2];

    if( !dir_exists(path) ) {
        tell_object( TP, RED+"\nNo such directory: "+path+"\n"+RESET );
        return do_prompt();
    }

    old = geteuid(TO);
    seteuid(geteuid(TP));

    if( !master()->valid_grant( TP, path ) ||
        !master()->add_permission( name, path, mask ) ) {
        seteuid(old);
        tell_object( TP, RED+"\nYou do not have the privileges to grant access "
            "to "+path+".\n"+RESET );
        return do_prompt();
    }

    tell_object( TP, GREEN+"\n"+CAP(name)+" has been granted "+
        access_string(mask)+" access to "+path+"\n"+RESET );

    log_file("/secure/log/ACCESS", "%s granted <%s> access to %s for %s.\n",
        TP->query_cap_name(), access_string(mask), path, CAP(name) );

    return do_prompt();

} /* add_creator3() */

private void revoke_creator( string str ) {
    if( !str || str == "")
        return do_prompt();

    str = lower_case(str);

    tell_object( TP, "Enter the type of access to revoke, "
        "(r)ead, (w)rite, (g)rant, [rwg]: ");
    input_to( (: revoke_creator2( $1, $(str) ) :) );

} /* revoke_creator() */

private void revoke_creator2( string str, string str2 ) {
    int mask;

    if( !str || str == "")
        return do_prompt();

    foreach( int flag in str )
        switch( flag ) {
          case 'r':
            mask |= READ_MASK;
          break;
          case 'w':
            mask |= WRITE_MASK;
          break;
          case 'g':
            mask |= GRANT_MASK;
          break;
          default:
            tell_object( TP, RED+"\n"+sprintf("Invalid access type - '%c'.\n",
                flag )+RESET );
            return do_prompt();
        }

    if( mask < 1 ) {
        tell_object( TP, RED+"\nRevoke cancelled.\n"+RESET );
        return do_prompt();
    }

    tell_object( TP, "Enter full directory path to revoke access from "
        "(without the trailing /): ");
    input_to( (: revoke_creator3( $1, $(str2), $(mask) ) :) );

} /* revoke_creator2() */

private void revoke_creator3( string path, string name, int mask ) {
    string old;

    if( !path || path == "")
        return do_prompt();

    if( path != "/" && path[<1] == '/')
        path = path[0..<2];

    old = geteuid(TO);
    seteuid(geteuid(TP));

    if( !master()->valid_grant( TP, path ) ||
        !master()->remove_permission( name, path, mask ) ) {
        seteuid(old);
        tell_object( TP, RED+"\nYou do not have the privileges to revoke "
            "access to "+path+" from "+CAP(name)+".\n"+RESET );
        return do_prompt();
    }

    tell_object( TP, GREEN+ "\n"+access_string(mask)+" access to "+
        path+" has been revoked from "+CAP(name)+".\n"+RESET );
    log_file("/secure/log/ACCESS", "%s revoked <%s> access from %s to %s.\n",
        TP->query_cap_name(), access_string(mask), CAP(name), path );

    return do_prompt();

} /* revoke_creator3() */

/** @ignore yes */
string access_string( int access_flags ) {
    string plus = "";

    if( access_flags & READ_MASK )
        plus += "r";

    if( access_flags & WRITE_MASK )
        plus += "w";

    if( access_flags & GRANT_MASK )
        plus += "g";

    return plus;

} /* access_string() */

private void do_summary( string str ) {
    string ret;

    if( !str || str == "")
        ret = list_access(0);
    else if( dir_exists(str) )
        ret = list_access(str);
    else
        ret = user_access(str);

    if( ret )
        tell_object( TP, ret );

    return do_prompt();

} /* do_summary() */

private string user_access( string args ) {
    string ret = "", path, name, *paths, *names;
    mapping m = master()->query_permissions(), d = ([ ]);

    if( args ) {
        foreach( path in keys(m) )
            foreach( name in keys(m[path]) )
                if( name == args )
                    d[path] = "  "+sprintf("%-3s",
                        access_string(m[path][name]) )+" "+path+"\n";

        paths = sort_array( keys(d), 1 );

        foreach( path in paths )
            ret += d[path];

        if( ret == "") {
            if( !PLAYER_H->test_user(args) )
                return "No such player.\n";
            return CAP(args)+" has no access at this time.\n";
        } else {
            return ret;
        }
    }

    foreach( path in keys(m) )
        foreach( name in keys(m[path]) ) {
            if( undefinedp(d[name]) )
                d[name] = ({ });
            d[name] += ({ path });
        }

    names = sort_array( keys(d), 1 );

    foreach( name in names ) {
        ret += CAP(name)+":\n";
        paths = sort_array( d[name], 1 );

        foreach( path in paths )
            ret += "  "+sprintf("%-3s",
                access_string(m[path][name]))+" "+path+"\n";

        ret += "\n";
    }

    return ret;

} /* user_access() */

private string list_access( string args ) {
    mapping m = master()->query_permissions();
    string ret = "", *paths, *names;

    if( args ) {
        if( args[0] != '/')
            return args+": not a valid path.\n";

        if( args != "/" && args[<1] == '/')
            args = args[0..<2];

        if( undefinedp(m[args]) )
            return "No access has been granted for that path.\n";

        names = sort_array( keys(m[args]), 1 );
        ret = args +":\n";

        foreach( string name in names )
            ret += "  "+sprintf("%-3s",
                access_string(m[args][name]))+" "+CAP(name)+"\n";

        return ret;
    }

    // By sorting the paths into alphabetical order, that should imply
    // that access for /cmds is listed before access for /cmds/creator.
    paths = sort_array( keys(m), 1 );

    foreach( string path in paths ) {
        ret += path+":\n";

        names = sort_array( keys(m[path]), 1 );

        foreach( string name in names )
            ret += "  "+sprintf("%-3s",
                access_string(m[path][name]))+" "+CAP(name)+"\n";

        ret += "\n";
    }

    if( ret == "")
        return "No access has been granted to anyone at this time.\n";
    else
        return ret;

} /* list_access() */

private void get_command( string str ) {
    if( !str ) {
        display_menu();
        return do_prompt();
    }

    switch( str ) {
      case "1":
        tell_object( TP, "Enter the name of the creator to grant access to : ");
        input_to( (: add_creator :) );
      break;
      case "2":
        tell_object( TP, "Enter the name of the creator to revoke access from : ");
        input_to( (: revoke_creator :) );
      break;
      case "3":
        tell_object( TP, "Enter the name of the creator or a full path, "
            "(enter for the whole mud): ");
        input_to( (: do_summary :) );
      break;
      case "B":
      case "b":
        if( !return_mapping[TP] ) {
            display_menu();
            return do_prompt();
        }
        return_mapping[TP]->cmd("");
        map_delete( return_mapping, TP );
      break;
      case "Q":
      case "q":
        map_delete( return_mapping, TP );
        return;
      default:
        display_menu();
        return do_prompt();
    }
} /* get_command() */

/** @ignore yes */
int cmd( string arg ) {
    if( file_name(PO) == "/secure/cmds/creator/admtools")
        return_mapping[TP] = PO;

    display_menu();
    do_prompt();

    return 1;

} /* cmd() */
