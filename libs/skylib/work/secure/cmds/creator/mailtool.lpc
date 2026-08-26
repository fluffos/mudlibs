/**
 * mailtool.c
 * The Mail Control Tool
 * for the Admtool
 * Shaydz 02 Apr '00
 */

#include <colors.h>
#include <mail.h>

inherit COMMAND_BASE;

private mapping return_mapping = ([ ]);
private string main_menu_template = @END
-------------------------------------------------------------------------
%s
-------------------------------------------------------------------------
  %sCommand                                      Status%s

  [1]  Add Player(s) to a Mailing List         %s
  [2]  Remove Player(s) from a Mailing List    %s
  [3]  Add Controller to a Mailing List        %s
  [4]  Remove Controller from a Mailing List   %s
  [5]  Create a NEW Mailing List               %s
  [6]  Delete a Mailing List                   %s
  [7]  Display Current Mailing Lists           %s

END;

private string main_prompt = "Enter your command [1-7], or [Q] to quit: ";
private string main_prompt2 = "Enter your command [1-7], [B] to go back, or [Q] to quit: ";

// Function prototypes.
int cmd( string str );
private void get_command( string str );
private void add_player();
private void add_player2( string str );
private void add_player3( string str, string list );
private void del_player();
private void del_player2( string str );
private void del_player3( string str, string list );
private void add_controller();
private void add_controller2( string str );
private void add_controller3( string str, string list );
private void del_controller();
private void del_controller2( string str );
private void del_controller3( string str, string list );
private void new_list();
private void new_list2( string str );
private void new_list3( string str, string list );
private void del_list();
private void del_list2( string str );
private void del_list3( string str, string list );
private void list_lists();
private void list_lists2( string str );

private void display_menu() {
    string title, s1, s2, s3, s4, s5, s6, s7;

    title = sprintf("%s%|72s%s", YELLOW, mud_name()+" Mailer Control "
        "Tool v1.5", RESET );

    s1 = s2 = s3 = s4 = s5 = s6 = s7 = RED+"Unavailable"+RESET;

    if( creatorp(TP) )
        s7 = GREEN+"Available"+RESET;

    if( lordp(TP) )
        s1 = s2 = s5 = GREEN+"Available"+RESET;

    if( adminp(TP) )
        s3 = s4 = s6 = GREEN+"Available"+RESET;

    tell_object( TP, sprintf( main_menu_template, title, BOLD, RESET,
        s1, s2, s3, s4, s5, s6, s7 ) );

} /* display_menu() */

private void do_prompt() {
    tell_object( TP, undefinedp(return_mapping[TP]) ? main_prompt :
                                                      main_prompt2 );
    input_to( (: get_command :) );
} /* do_prompt() */

private void add_player() {
    if( !lordp(TP) ) {
        tell_object( TP, RED+"\nYou don't have the power to do that.\n"+
            RESET );
        return do_prompt();
    }

    tell_object( TP, "Enter the name of the mailing list to add a player to: ");
    input_to( (: add_player2 :) );

} /* add_player()*/

private void add_player2( string str ) {
    if( !str || str == "")
        return do_prompt();

    str = lower_case(str);

    if( !MAIL_TRACK->query_list(str) ) {
        tell_object( TP, RED+"The mailing list "+CAP(str)+" does NOT "
            "exist!\n\n"+RESET);
        return do_prompt();
    }

    if( !MAIL_TRACK->query_controlled_list(str) ) {
        tell_object( TP, RED+"You can't add members to "+
            CAP(str)+" because it isn't a controlled list.\n\n"+RESET );
        return do_prompt();
    }

    tell_object( TP, "Enter the player's name or a comma separated list if "
        "more than one: ");

    input_to( (: add_player3( $1, $(str) ) :) );

} /* add_player2() */

private void add_player3( string str, string list ) {
    string *names, name;

    if( !str || str == "")
        return do_prompt();

    if( !MAIL_TRACK->query_controller( list, TP->query_name() ) && !adminp(TP) ) {
        tell_object( TP, RED+"You must be the controller of the list to add "
            "members to it!\n\n"+RESET );
        return do_prompt();
    }

    names = explode( replace( lower_case(str), " ", ","), ",") - ({""});

    if( !sizeof(names) ) {
        tell_object( TP, RED+"You need to specify the name(s) to "
            "add.\n\n"+RESET);
        return do_prompt();
    }

    foreach( name in names ) {
        name = lower_case( TP->expand_nickname(name) );

        if( !PLAYER_H->test_user(name) && !MAIL_TRACK->query_list(name) )
            write(RED+"The player "+CAP(name)+" does not exist.\n"+RESET);
        else if( MAIL_TRACK->query_member( list, name ) )
            write(RED+CAP(name)+" is already a member of "+CAP(list)+".\n"+
                RESET);
        else if( MAIL_TRACK->add_member( list, name ) )
            write(GREEN+"Added "+CAP(name)+" to "+CAP(list)+".\n"+RESET);
        else
            write(RED+"Failed to add "+CAP(name)+" to "+CAP(list)+".\n"+
                RESET);
    }

    return do_prompt();

} /* add_player3() */

private void del_player() {
    if( !lordp(TP) ) {
        tell_object( TP, RED+"\nYou don't have the power to do that.\n"+
            RESET );
        return do_prompt();
    }

    tell_object( TP, "Enter the name of the mailing list to remove a member "
        "from: ");
    input_to( (: del_player2 :) );

} /* del_player() */

private void del_player2( string str ) {
    if( !str || str == "")
        return do_prompt();

    str = lower_case(str);

    if( !MAIL_TRACK->query_list(str) ) {
        tell_object( TP, RED+"The mailing list "+CAP(str)+" does NOT "
            "exist!\n\n"+RESET);
        return do_prompt();
    }

    if( !MAIL_TRACK->query_controlled_list(str) ) {
        tell_object( TP, RED+"You can't remove members from "+
            CAP(str)+" because it isn't a controlled list.\n\n"+RESET );
        return do_prompt();
    }

    tell_object( TP, "Enter the player's name or a comma separated list if "
        "more than one: ");
    input_to( (: del_player3( $1, $(str) ) :) );

} /* del_player2() */

private void del_player3( string str, string list ) {
    string *names, name;

    if( !str || str == "")
        return do_prompt();

    if( !MAIL_TRACK->query_controller( list, TP->query_name() ) && !adminp(TP) ) {
        tell_object( TP, RED+"You must be the controller of the list to "
            "remove members from it!\n\n"+RESET );
        return do_prompt();
    }

    names = explode( replace( lower_case(str), " ", ","), ",") - ({""});

    if( !sizeof(names) ) {
        tell_object( TP, RED+"You need to specify the name(s) to "
            "remove.\n\n"+RESET);
        return do_prompt();
    }

    foreach( name in names ) {
        name = lower_case( TP->expand_nickname(name) );

        if( MAIL_TRACK->query_controller( list, name ) )
            write(RED+CAP(name)+" is a controller of "+CAP(list)+", please "
                "remove them as a controller first.\n"+RESET);
        else if( MAIL_TRACK->remove_member( list, name ) )
            write(GREEN+"Removed "+CAP(name)+" from "+CAP(list)+".\n"+RESET);
        else
            write("Failed to remove "+CAP(name)+" from "+
                CAP(list)+".\n"+RESET);
    }

    return do_prompt();

} /* del_player3() */

private void add_controller() {
    if( !adminp(TP) ) {
        tell_object( TP, RED+"\nYou don't have the power to do that.\n"+
            RESET );
        return do_prompt();
    }

    tell_object( TP, "Enter the name of the mailing list to add a controller "
        "to: ");
    input_to( (: add_controller2 :) );

} /* add_controller()*/

private void add_controller2( string str ) {
    if( !str || str == "")
        return do_prompt();

    str = lower_case(str);

    if( !MAIL_TRACK->query_list(str) ) {
        tell_object( TP, RED+"The mailing list "+CAP(str)+" does NOT "
            "exist!\n\n"+RESET);
        return do_prompt();
    }

    if( !MAIL_TRACK->query_controlled_list(str) ) {
        tell_object( TP, RED+"You can't add controllers to "+
            CAP(str)+" because it isn't a controlled list.\n\n"+RESET );
        return do_prompt();
    }

    tell_object( TP, "Enter the player's name to add as a controller: ");

    input_to( (: add_controller3( $1, $(str) ) :) );

} /* add_controller2() */

private void add_controller3( string name, string list ) {
    if( !name || name == "")
        return do_prompt();

    if( !adminp(TP) ) {
        tell_object( TP, RED+"You must be an admin to add controllers to "
            "mailing lists!\n\n"+RESET );
        return do_prompt();
    }

    name = lower_case( TP->expand_nickname(name) );

    if( MAIL_TRACK->query_controller( list, name ) )
        write(RED+CAP(name)+" is already a controller of "+
            CAP(list)+".\n\n"+RESET);
    else if( !PLAYER_H->test_user(name) )
        write(RED+"The player "+CAP(name)+" does not exist.\n\n"+RESET);
    else if( MAIL_TRACK->add_controller( list, name ) )
        write(GREEN+"Added "+CAP(name)+" as a controller to "+
            CAP(list)+".\n\n"+RESET);
    else
        write(RED+"Failed to add "+CAP(name)+" as a controller to "+
            CAP(list)+".\n\n"+RESET);

    return do_prompt();

} /* add_controller3() */

private void del_controller() {
    if( !adminp(TP) ) {
        tell_object( TP, RED+"\nYou don't have the power to do that.\n"+
            RESET );
        return do_prompt();
    }

    tell_object( TP, "Enter the name of the mailing list to remove a "
        "controller from: ");
    input_to( (: del_controller2 :) );

} /* del_controller() */

private void del_controller2( string str ) {
    if( !str || str == "")
        return do_prompt();

    str = lower_case(str);

    if( !MAIL_TRACK->query_list(str) ) {
        tell_object( TP, RED+"The mailing list "+CAP(str)+" does NOT "
            "exist!\n\n"+RESET);
        return do_prompt();
    }

    if( !MAIL_TRACK->query_controlled_list(str) ) {
        tell_object( TP, RED+"You can't remove controllers from "+
            CAP(str)+" because it isn't a controlled list.\n\n"+RESET );
        return do_prompt();
    }

    tell_object( TP, "Enter the player's name to remove as a controller: ");
    input_to( (: del_controller3( $1, $(str) ) :) );

} /* del_controller2() */

private void del_controller3( string name, string list ) {
    if( !name || name == "")
        return do_prompt();

    if( !adminp(TP) ) {
        tell_object( TP, RED+"You must be an admin to remove controllers "
            "from mailing lists!\n\n"+RESET );
        return do_prompt();
    }

    name = lower_case( TP->expand_nickname(name) );

    if( !MAIL_TRACK->query_controller( list, name ) )
        write(RED+CAP(name)+" is not a controller of "+
            CAP(list)+".\n\n"+RESET);
    else if( MAIL_TRACK->remove_controller( list, name ) )
        write(GREEN+"Removed "+CAP(name)+" as a controller from "+
            CAP(list)+".\n"+RESET);
    else
        write("Failed to remove "+CAP(name)+" as a controller from "+
            CAP(list)+".\n"+RESET);

    return do_prompt();

} /* del_controller3() */

private int check_valid_name( string str ) {
    int i;

    for( i = 0; i < strlen(str); i++ )
        if( str[i] < 'a' || str[i] > 'z')
            return i;

    return -1;

} /* check_valid_name() */

private void new_list() {
    if( !lordp(TP) ) {
        tell_object( TP, RED+"\nYou don't have the power to do that.\n"+
            RESET );
        return do_prompt();
    }

    tell_object( TP, "Enter the name of the new mailing list: ");
    input_to( (: new_list2 :) );

} /* new_list() */

private void new_list2( string str ) {
    int i;

    if( !str || str == "")
        return do_prompt();

    str = lower_case(str);

    if( MAIL_TRACK->query_list(str) ) {
        tell_object( TP, RED+"The mailing list "+CAP(str)+" already "
            "exists!\n\n"+RESET);
        return do_prompt();
    }

    if( ( i = check_valid_name(str) ) != -1 ) {
        tell_object( TP, RED+"Invalid character '"+str[i..i]+"' in the "
            "proposed list name ("+str+").\n\n"+RESET);
        return do_prompt();
    }

    tell_object( TP, "Are you sure you want to create a new mailing list "
        "called '"+CAP(str)+"'? [Y|N] :");

    input_to( (: new_list3( $1, $(str) ) :) );

} /* new_list2() */

private void new_list3( string str, string list ) {
    if( !str || str == "" || lower_case(str) != "y")
        return do_prompt();

    if( !MAIL_TRACK->create_list( list, TP->query_name() ) ) {
        tell_object( TP, RED+"Failed to create the list "+
            CAP(list)+"!\n\n"+RESET);
        return do_prompt();
    }

    tell_object( TP, GREEN+"Successfully created the mailing list.\n\n"+
        RESET);

    return do_prompt();

} /* new_list3() */

private void del_list() {
    if( !adminp(TP) ) {
        tell_object( TP, RED+"\nYou don't have the power to do that.\n"+
            RESET );
        return do_prompt();
    }

    tell_object( TP, "Enter the name of the mailing list to delete: ");
    input_to( (: del_list2 :) );

} /* del_list() */

private void del_list2( string str ) {
    if( !str || str == "")
        return do_prompt();

    str = lower_case(str);

    if( !MAIL_TRACK->query_list(str) ) {
        tell_object( TP, RED+"The mailing list "+CAP(str)+" doesn't "
            "exist!\n\n"+RESET);
        return do_prompt();
    }

    if( !MAIL_TRACK->query_controlled_list(str) ) {
        tell_object( TP, RED+"The mailing list "+CAP(str)+" isn't a "
            "controlled list and cannot be deleted!\n\n"+RESET);
        return do_prompt();
    }

    tell_object( TP, "Are you sure you want to delete the mailing "
        "list '"+CAP(str)+"'? [Y|N] :");

    input_to( (: del_list3( $1, $(str) ) :) );

} /* del_list2() */

private void del_list3( string str, string list ) {
    if( !str || str == "" || lower_case(str) != "y")
        return do_prompt();

    if( !MAIL_TRACK->delete_list( list ) ) {
        tell_object( TP, RED+"Failed to delete the list "+
            CAP(list)+"!\n\n"+RESET);
        return do_prompt();
    }

    tell_object( TP, GREEN+"Successfully deleted the mailing list.\n\n"+
        RESET);

    return do_prompt();

} /* del_list3() */

private void list_lists() {
    tell_object( TP, "Enter the name of a mailing list for info or return "
        "for a list of lists: ");
    input_to( (: list_lists2 :) );
} /* list_lists() */

private void list_lists2( string str ) {
    string *members, *controllers;

    if( !str || str == "") {
        tell_object( TP, "\n"+create_table( ({"Mailing Lists",
            "mailing list"}), map( MAIL_TRACK->query_mailing_lists(),
            (: CAP($1)+( MAIL_TRACK->query_controlled_list($1) ?
            "(*)" : "") :) ), 0 ) );
        return do_prompt();
    }

    if( !MAIL_TRACK->query_list(str) ) {
        tell_object( TP, RED+"The mailing list "+CAP(str)+" does "
            "not exist!\n\n"+RESET);
        return do_prompt();
    }

    controllers = MAIL_TRACK->query_controllers(str);
    members = map( MAIL_TRACK->query_members(str) -  controllers,
        (: CAP($1) :) );
    controllers = map( controllers, (: CAP($1)+"(*)" :) );

    tell_object( TP, "\n"+create_table( ({"Members of "+
        CAP(str)+" mailing list", "member" }),
        controllers + members, 0 ) );

    return do_prompt();

} /* list_lists2() */

private void get_command( string str ) {
    if( !str ) {
        display_menu();
        return do_prompt();
    }

    switch( str ) {
      case "1":
        if( !lordp(TP) ) {
            tell_object( TP, RED+"\nYou are not authorised to use this "
                "option.\n"+RESET);
            return do_prompt();
        }
        add_player();
      break;
      case "2":
        if( !lordp(TP) ) {
            tell_object( TP, RED+"\nYou are not authorised to use this "
                "option.\n"+RESET);
            return do_prompt();
        }
        del_player();
      break;
      case "3":
        if( !adminp(TP) ) {
            tell_object( TP, RED+"\nYou are not authorised to use this "
                "option.\n"+RESET);
            return do_prompt();
        }
        add_controller();
      break;
      case "4":
        if( !adminp(TP) ) {
            tell_object( TP, RED+"\nYou are not authorised to use this "
                "option.\n"+RESET);
            return do_prompt();
        }
        del_controller();
      break;
      case "5":
        if( !lordp(TP) ) {
            tell_object( TP, RED+"\nYou are not authorised to use this "
                "option.\n"+RESET);
            return do_prompt();
        }
        new_list();
      break;
      case "6":
        if( !adminp(TP) ) {
            tell_object( TP, RED+"\nYou are not authorised to use this "
                "option.\n"+RESET);
            return do_prompt();
        }
        del_list();
      break;
      case "7":
        list_lists();
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
