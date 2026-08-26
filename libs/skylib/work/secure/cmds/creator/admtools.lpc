/**
 * Admin tools.
 * Shaydz - 02 Apr '00
 * @changed Added deity control and changed to v1.6 - Sandoz, 22/09/2002.
 */

#include <colors.h>
inherit COMMAND_BASE;

private string main_menu_template = @END
-------------------------------------------------------------------------
%s
-------------------------------------------------------------------------
  %sCommand                                      Status%s

  [1]  Access Control                          %s
  [2]  Domain Control                          %s
  [3]  Project Control                         %s
  [4]  Security Control                        %s
  [5]  Quest Control                           %s
  [6]  Board Control                           %s
  [7]  Mail Control                            %s
  [8]  Login Control                           %s
  [9]  Deity Control                           %s

  [10] Reboot/Shutdown                         %s
  [11] Abort Shutdown                          %s

END;

int cmd(string arg);
private void make_selection(string str);
private void handle_shutdown();
private void handle_shutdown2(string str);
private void handle_shutdown3(string str);
private void handle_shutdown4(string str, int delay);
private void abort_shutdown();

private void display_menu() {
    string title, s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11;

    title = sprintf("%s%|72s%s", YELLOW, mud_name()+" Administration Tool "
        "v1.6", RESET );

    s1 = s2 = s3 = s4 = s5 = s6 = s7 = s8 = s9 = s10 = s11 = RED+"Unavailable"+RESET;

    if( PROJECT_H->query_leader( TP->query_name() ) )
        s3 = MAGENTA+"Limited"+RESET;

    if( creatorp(TP) ) {
        s1 = s7 = s8 = s9 = s10 = MAGENTA+"Limited"+RESET;
        s11 = GREEN+"Available"+RESET;
    }

    if( lordp(TP) ) {
        s1 = s2 = s4 = s8 = MAGENTA+"Limited"+RESET;
        s5 = s7 = s9 = s10 = s11 = GREEN+"Available"+RESET;
    }

    if( adminp(TP) )
        s1 = s2 =  s4 = s6 = s8 = GREEN+"Available"+RESET;


    tell_object( TP, sprintf( main_menu_template, title, BOLD, RESET,
        s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11 ) );

    tell_object( TP, "Enter your command [1-11], or [Q] to quit: ");
    input_to( (: make_selection :) );

} /* display_menu() */

private void handle_shutdown() {
    if( !creatorp(TP) ) {
        tell_object( TP, BOLD+RED+FLASH+"You do not have the ability to do "
            "that!\n\n"+RESET);
        tell_object( TP, "Enter your command [1-11], or [Q] to quit: ");
        input_to( (: make_selection :) );
        return;
    }

    tell_object( TP, "Are you sure you want to shutdown the mud? [Y/N]: ");
    input_to( (: handle_shutdown2 :) );

} /* handle_shutdown() */

private void handle_shutdown2( string str ) {
    str = lower_case(str);

    if( !str || ( str = lower_case(str) ) == "" || ( str != "y" &&
        str != "yes") ) {
        tell_object( TP, BOLD+GREEN+"Shutdown Cancelled!\n\n"+RESET );
        cmd("");
        return;
    }

    tell_object( TP, "Enter time until shutdown: ");
    input_to( (: handle_shutdown3 :) );

} /* handle_shutdown2() */

private void handle_shutdown3( string str ) {
    int delay;

    if( !str || str == "") {
        tell_object( TP, BOLD+GREEN+"Shutdown Cancelled!\n\n"+RESET );
        cmd("");
        return;
    }

    if( sscanf( str, "%d", delay ) != 1 ) {
        tell_object( TP, BOLD+GREEN+"Shutdown Cancelled!\n\n"+RESET );
        cmd("");
        return;
    }

    if( delay < 5 && !adminp(TP) ) {
        tell_object( TP, BOLD+GREEN+"Only admin can shut the mud down that "
            "soon!\nPlease try again with a longer delay.\n\n"+RESET );
        cmd("");
        return;
    }

    tell_object( TP, "Enter reason for the shutdown: ");
    input_to( (: handle_shutdown4( $1, $(delay) ) :) );

} /* handle_shutdown3() */

private void handle_shutdown4( string str, int delay ) {

    if( !str || str == "") {
        tell_object( TP, BOLD+GREEN+"Shutdown Cancelled!\n\n"+RESET );
        cmd("");
        return;
    }

    log_file("SHUTDOWN", "Mud shutdown by %s at %s because: %s.\n",
        TP->query_cap_name(), ctime(time()), str );
    tell_object( TP, YELLOW+"OK, Shutting down!.\n\n"+RESET );

    if( !delay ) {
        SHUTDOWN_H->init_shutdown(0);
    } else {
        SHUTDOWN_H->init_shutdown( delay, 1 );
    }

    cmd("");
    return;

} /* handle_shutdown4() */

private void abort_shutdown() {
    SHUTDOWN_H->abort_shutdown();

    log_file("SHUTDOWN", "Mud shutdown aborted by %s at %s.\n",
        TP->query_cap_name(), ctime(time()) );

    cmd("");
    return;

} /* abort_shutdown */

private void no_privs() {
    tell_object( TP, "You don't have the privileges to use this option.\n");
    cmd("");
} /* no_privs() */

private void make_selection( string str ) {
    if( !str )
        return display_menu();

    switch( str ) {
      case "1":
        "/secure/cmds/creator/accesstool"->cmd("");
      break;
      case "2":
        if( lordp(TP) ) {
            "/secure/cmds/lord/domaintool"->cmd("");
            break;
        }
        no_privs();
      break;
      case "3":
//        "/secure/cmds/creator/projecttool"->cmd("");
        no_privs();
      break;
      case "4":
        if( lordp(TP) ) {
            "/secure/cmds/lord/securitytool"->cmd("");
            break;
        }
        no_privs();
      break;
      case "5":
        if( lordp(TP) ) {
            "/secure/cmds/lord/questtool"->cmd("");
            break;
        }
        no_privs();
      break;
      case "6":
        if( adminp(TP) ) {
            "/secure/cmds/admin/boardtool"->cmd("");
            break;
        }
        no_privs();
      break;
      case "7":
        "/secure/cmds/creator/mailtool"->cmd("");
      break;
      case "8":
        "/secure/cmds/lord/logintool"->cmd("");
      break;
      case "9":
        "/secure/cmds/creator/deitytool"->cmd("");
      break;
      case "10":
        handle_shutdown();
      break;
      case "11":
        abort_shutdown();
      break;
      case "Q":
      case "q":
        return;
      break;
      default:
        return display_menu();
    }

} /* get_command() */

/** @ignore yes */
int cmd( string str ) {
    display_menu();
    return 1;
} /* cmd() */
