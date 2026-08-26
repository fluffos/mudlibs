/**
 * boardtool.c
 * The Board Control Tool
 * for the admtool
 * Shaydz 2 Apr '00
 */

#include <board.h>
#include <colors.h>

inherit COMMAND_BASE;

private mapping return_mapping = ([ ]);
private string main_menu_template = @END
-------------------------------------------------------------------------
%s
-------------------------------------------------------------------------
  %sCommand                                      Status%s

  [1]  Create NEW Board                        %s
  [2]  Delete Board                            %s
  [3]  List Boards                             %s

END;

private string main_prompt = "Enter your command [1-3], or [Q] to quit: ";
private string main_prompt2 = "Enter your command [1-3], [B] to go back, or [Q] to quit: ";

// Function prototypes.
int cmd(string args);
private void get_command( string str );
private void create_board();
private void create_board2( string str );
private void create_board3( string str, string board );
private void create_board4( string str, string board, int priv, string acc );
private void delete_board();
private void delete_board2( string str );
private void delete_board3( string str, string board );
private void list_boards();

private void display_menu() {
    string title, s1, s2, s3;

    title = sprintf("%s%|72s%s", YELLOW, mud_name()+" Board Control "
        "Tool v1.5", RESET );

    s1 = s2 = s3 = RED+"Unavailable"+RESET;

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

private void create_board() {
    tell_object( TP, "Enter the name of the NEW board: ");
    input_to( (: create_board2 :) );
} /* create_board() */

private void create_board2( string str ) {
    if( !str || str == "")
        return do_prompt();

    str = lower_case(str);

    if( BOARD_H->is_board(str) ) {
        tell_object( TP, "A board called "+CAP(str)+" already exists.\n");
        return do_prompt();
    }

    tell_object( TP, "Is "+str+" to be an [a]dmin only, [l]ord only "
        "or [n]ormal access board [a|l|n] : ");

    input_to( (: create_board3( $1, $(str) ) :) );

} /* create_board2() */

private void create_board3( string str, string board ) {
    string acc;
    int priv;

    if( !str || str == "")
        return do_prompt();

    switch( lower_case(str) ) {
      case "n" :
        acc = "a normal access";
        priv = B_PRIV_NORMAL;
      break;
      case "a" :
        acc = "an admin only";
        priv = B_PRIV_ACCESS_ADMIN;
      break;
      case "l" :
        acc = "a lord only";
        priv = B_PRIV_ACCESS_RESTRICTED;
      break;
      default:
        tell_object( TP, "Is "+board+" to be an [a]dmin only, [l]ord only "
            "or [n]ormal access board [a|l|n] : ");
        input_to( (: create_board3($1, $(board)) :) );
        return;
    }

    tell_object( TP, "Are you sure you wish to create "+acc+" board "
        "called "+CAP(board)+"? [Y|N] : ");

    input_to( (: create_board4( $1, $(board), $(priv), $(acc) ) :) );

} /* create_board3() */

private void create_board4( string str, string board, int priv, string acc ) {
    string old;

    if( !str || lower_case(str) != "y")
        return do_prompt();

    old = geteuid();
    seteuid(geteuid(TP));

    if( BOARD_H->create_board( board, priv ) )
        tell_object( TP, GREEN+"\nThe board "+CAP(board)+" has been created "
            "as "+acc+" board.\n\n"+RESET );
    else
        tell_object( TP, RED+"\nFailed to create the board '"+
            CAP(board)+"'.\n\n"+RESET );

    seteuid(old);

    return do_prompt();

} /* create_board4() */

private void delete_board() {
    tell_object( TP, "Enter the name of the board to DELETE: ");
    input_to( (: delete_board2 :) );
} /* delete_board() */

private void delete_board2( string str ) {
    if( !str || str == "")
        return do_prompt();

    if( !BOARD_H->is_board(str) ) {
        tell_object( TP, "A board called "+CAP(str)+" does not exist.\n");
        return do_prompt();
    }

    tell_object( TP, "Are you sure you wish to delete the "+
        CAP(str)+" board? : ");

    input_to( (: delete_board3( $1, $(str) ) :) );

} /* delete_board2() */

private void delete_board3( string str, string board ) {
    string old;

    if( !str || str == "")
        return do_prompt();

    str = lower_case(str);

    if( str == "y" || str == "yes") {
        old = geteuid();
        seteuid(geteuid(TP));
        if( BOARD_H->delete_board(board) )
            tell_object( TP, GREEN+"\nThe board "+CAP(board)+" has been "
                "deleted.\n\n"+RESET );
        else
            tell_object( TP, RED+"\nFailed to delete the board "+
                CAP(board)+".\n\n"+RESET );
        seteuid(old);
        return do_prompt();
    }

    tell_object( TP, RED+"\nThe board "+CAP(board)+" has NOT been "
        "deleted.\n\n"+RESET );

    return do_prompt();

} /* delete_board3() */

private void list_boards() {
    tell_object( TP, "\n"+create_table( ({"Boards", "board"}),
        map( BOARD_H->query_boards(), (: CAP($1) :) ), 0 ) );
    return do_prompt();
} /* list_boards() */

private void get_command( string str ) {
    if( !str ) {
        display_menu();
        return do_prompt();
    }

    switch( str ) {
      case "1":
        if( !adminp(TP) ) {
            tell_object( TP, "You don't have the power to do that.\n");
            return do_prompt();
        }
        create_board();
      break;
      case "2":
        if( !adminp(TP) ) {
            tell_object( TP, "You don't have the power to do that.\n");
            return do_prompt();
        }
        delete_board();
      break;
      case "3":
        if( !adminp(TP) ) {
            tell_object( TP, "You don't have the power to do that.\n");
            return do_prompt();
        }
        list_boards();
      break;
      case "B": case "b":
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
int cmd( string str ) {
    if( file_name(PO) == "/secure/cmds/creator/admtools")
        return_mapping[TP] = PO;

    display_menu();
    do_prompt();
    return 1;

} /* cmd() */
