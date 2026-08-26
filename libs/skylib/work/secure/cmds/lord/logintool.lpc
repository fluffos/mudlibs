/**
 * The Login Control Tool for the Admtools.
 * @author Sandoz, 31/05/2003
 */

#include <colors.h>

inherit COMMAND_BASE;

private mapping return_mapping = ([ ]);
private string main_menu_template = @END
-------------------------------------------------------------------------
%s
-------------------------------------------------------------------------
  %sCommand                                      Status%s

  [1]  Switch to unrestricted login mode       %s
  [2]  Switch to playtester only login mode    %s
  [3]  Switch to creator only login mode       %s

  [4]  Display current login mode              %s

END;

private string main_prompt = "Enter your command [1-4], or [Q] to quit: ";
private string main_prompt2 = "Enter your command [1-4], [B] to go back, or [Q] to quit: ";

// Function prototypes.
int cmd( string args );
private void get_command( string str );
private void switch_login_mode( int i );
private void display_login_mode();

private void display_menu() {
    string title, s1, s2, s3, s4;

    title = sprintf("%s%|72s%s", YELLOW,
        mud_name()+" Login Control Tool v1.0", RESET );

    s1 = s2 = s3 = s4 = RED+"Unavailable"+RESET;

    if( lordp(TP) )
        s4 = GREEN+"Available"+RESET;

    if( adminp(TP) )
        s1 = s2 = s3 = GREEN+"Available"+RESET;

    tell_object( TP, sprintf( main_menu_template, title, BOLD, RESET,
                 s1, s2, s3, s4 ) );

} /* display_menu() */

private void do_prompt() {
    tell_object( TP, undefinedp(return_mapping[TP]) ? main_prompt :
                                                      main_prompt2 );
    input_to( (: get_command :) );
} /* do_prompt() */

private void switch_login_mode( int i ) {
    LOGIN_H->set_login_mode( i );
    return do_prompt();
} /* switch_login_mode() */

private void display_login_mode() {
    tell_object( TP, mud_name()+" is currently running in "+
        LOGIN_H->get_login_mode( LOGIN_H->query_login_mode() )+".\n");
    return do_prompt();
} /* display_login_mode() */

private void get_command( string str ) {
    if( !str ) {
        display_menu();
        return do_prompt();
    }

    switch( str ) {
      case "1":
        switch_login_mode( 0 );
      break;
      case "2":
        switch_login_mode( 1 );
      break;
      case "3":
        switch_login_mode( 2 );
      break;
      case "4":
        display_login_mode();
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
      break;
      default:
        display_menu();
        return do_prompt();
    }

} /* get_command() */

/** @ignore yes */
int cmd( string arg ) {
    if( PO && file_name(PO) == "/secure/cmds/creator/admtools")
        return_mapping[TP] = PO;

    if( !lordp(TP) ) {
        log_file("SECURITY_VIOLATION", TP->query_name()+" attempted to "
            "illegally use the LoginTool on "+ctime(time())+"\n");
        return notify_fail("%^RED%^Security Violation!\n%^RESET%^");;
    }

    display_menu();
    do_prompt();

    return 1;

} /* cmd() */
