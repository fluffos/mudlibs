/**
 * deitytool.c
 * The Deity Control Tool
 * for the admtool
 * Sandoz, 22/09/2002
 */

#include <colors.h>

inherit COMMAND_BASE;

private mapping return_mapping = ([ ]);
private string main_menu_template = @END
-------------------------------------------------------------------------
%s
-------------------------------------------------------------------------
  %sCommand                                      Status%s

  [1]  Add Deity                               %s
  [2]  Remove Deity                            %s
  [3]  Modify Deity                            %s
  [4]  View Deity Data                         %s
  [5]  List Deities                            %s

END;

private string main_prompt = "Enter your command [1-4], or [Q] to quit: ";
private string main_prompt2 = "Enter your command [1-4], [B] to go back, or [Q] to quit: ";
private string tool_title = sprintf("%s%|72s%s", YELLOW, mud_name()+" Deity "
    "Control Tool v1.0", RESET );

private void add_deity( string str );
private void add_deity_title( string title, string deity, int flag );
private void add_deity_info( string info, string deity, string title,
                             int flag );
private void add_deity_gender( string str, string deity, string title,
                               string info, int flag );
private void add_deity_lower( string str, string deity, string title,
                              string info, int gender, int flag );
private void add_deity_upper( string str, string deity, string title,
                              string info, int gender, int low, int flag );
private void add_deity_recruit( string str, string deity, string title,
                                string info, int gender, int low, int high,
                                int flag );
private void add_deity_end( string str, string deity, string title, string info,
                            int gender, int low, int high, int recruit );

private void remove_deity( string str );
private void remove_deity_end( string str, string deity );

private void add_ritual( string ritual, string deity, int flag );
private void remove_ritual( string ritual, string deity, int flag );

private void add_command( string cmd, string deity, int flag );
private void remove_command( string cmd, string deity, int flag );

private void get_command( string str );
private void get_edit_command( string str, string deity );

int cmd( string str );

private void display_menu() {
    string s1, s2, s3, s4, s5;

    s1 = s2 = s3 = s4 = s5 = RED+"Unavailable"+RESET;

    if( creatorp(TP) )
        s4 = s5 = GREEN+"Available"+RESET;

    if( lordp(TP) )
        s1 = s2 = s3 = s4 = s5 = GREEN+"Available"+RESET;

    tell_object( TP, sprintf( main_menu_template, tool_title, BOLD, RESET,
        s1, s2, s3, s4, s5 ) );

} /* display_menu() */

private void do_prompt() {
    tell_object( TP, undefinedp(return_mapping[TP]) ? main_prompt :
                                                      main_prompt2 );
    input_to( (: get_command :) );
} /* do_prompt() */

private void add_deity( string str ) {
    if( !str || str == "")
        return do_prompt();

    if( DEITY_H->query_deity( str = CAP( lower_case(str) ) ) ) {
        tell_object( TP, RED+"\nA deity by that name already exists.\n\n"+
            RESET );
        return do_prompt();
    }

    tell_object( TP, "Enter the title for the new deity (eg. "
        "\"the God of Cash and Carry\"): ");

    input_to( (: add_deity_title( $1, $(str), 0 ) :) );

} /* add_deity() */

private void add_deity_title( string title, string deity, int flag ) {
    if( !title || title == "")
        return do_prompt();

    if( flag ) {
        DEITY_H->set_title( deity, title );
        tell_object( TP, GREEN+"\nThe title for "+deity+" set to '"+
            title+"'.\n\n"+RESET );
        return do_prompt();
    }

    tell_object( TP, "Enter the finger info for the new deity (this should "
        "be one line only): ");
    input_to( (: add_deity_info( $1, $(deity), $(title), 0 ) :) );

} /* add_deity_title() */

private void add_deity_info( string info, string deity, string title,
                             int flag ) {
    if( !info || info == "")
        return do_prompt();

    if( flag ) {
        DEITY_H->set_info( deity, info );
        tell_object( TP, GREEN+"\nThe info for "+deity+" set to '"+
            info+"'.\n\n"+RESET );
        return do_prompt();
    }

    tell_object( TP, "Enter the gender of the new deity (0|1|2): ");
    input_to( (: add_deity_gender( $1, $(deity), $(title), $(info), 0 ) :) );

} /* add_deity_info() */

private void add_deity_gender( string str, string deity, string title,
                               string info, int flag ) {
    int gender;

    if( !str || str == "")
        return do_prompt();

    if( sscanf( str, "%d", gender ) != 1 || gender < 0 || gender > 2 ) {
        tell_object( TP, "Invalid gender, please re-enter (0|1|2): ");
        input_to( (: add_deity_gender( $1, $(deity), $(title), $(info),
            $(flag) ) :) );
        return;
    }

    if( flag ) {
        DEITY_H->set_gender( deity, gender );
        tell_object( TP, GREEN+"\nThe gender of "+deity+" set to "+
            ( gender ? ( gender == 1 ? "male" : "female") : "neuter")+
            ".\n\n"+RESET );
        return do_prompt();
    }

    tell_object( TP, "Enter the lower alignment limit for the new deity "
        "(between -10000 (good) and 10000 (evil)): ");
    input_to( (: add_deity_lower( $1, $(deity), $(title), $(info),
        $(gender), 0 ) :) );

} /* add_deity_gender() */

private void add_deity_lower( string str, string deity, string title,
                              string info, int gender, int flag ) {
    int low;

    if( !str || str == "")
        return do_prompt();

    if( sscanf( str, "%d", low ) != 1 || low < -10000 || low > 10000 ) {
        tell_object( TP, "Invalid alignment limit, please re-enter "
            "(between -10000 (good) and 10000 (evil)): ");
        input_to( (: add_deity_lower( $1, $(deity), $(title), $(info),
            $(gender), $(flag) ) :) );
        return;
    }

    if( flag ) {
        if( DEITY_H->set_al_lower( deity, low ) )
            tell_object( TP, GREEN+"\nThe lower alignment limit for "+
                deity+" set to "+low+".\n\n"+RESET );
        else
            tell_object( TP, RED+"\nFailed to set the lower alignment limit "
                "for "+deity+" to "+low+".\n\n"+RESET );
        return do_prompt();
    }

    tell_object( TP, "Enter the upper alignment limit for the new deity "
        "(between "+low+" and 10000 (evil)): ");
    input_to( (: add_deity_upper( $1, $(deity), $(title), $(info), $(gender),
        $(low), 0 ) :) );

} /* add_deity_lower() */

private void add_deity_upper( string str, string deity, string title,
                              string info, int gender, int low, int flag ) {
    int high;

    if( !str || str == "")
        return do_prompt();

    if( sscanf( str, "%d", high ) != 1 || high < low || high > 10000 ) {
        tell_object( TP, "Invalid alignment limit, please re-enter "
            "(between "+low+" and 10000 (evil)): ");
        input_to( (: add_deity_upper( $1, $(deity), $(title), $(info),
            $(gender), $(low), $(flag) ) :) );
        return;
    }

    if( flag ) {
        if( DEITY_H->set_al_upper( deity, high ) )
            tell_object( TP, GREEN+"\nThe lower alignment limit for "+
                deity+" set to "+high+".\n\n"+RESET );
        else
            tell_object( TP, RED+"\nFailed to set the lower alignment limit "
                "for "+deity+" to "+high+".\n\n"+RESET );
        return do_prompt();
    }

    tell_object( TP, "Enter whether or not you want "+deity+" to accept "
        "worshippers [y|n]: ");

    input_to( (: add_deity_recruit( $1, $(deity), $(title), $(info),
        $(gender), $(low), $(high), 0 ) :) );

} /* add_deity_upper() */

private void add_deity_recruit( string str, string deity, string title,
                                string info, int gender, int low, int high,
                                int flag ) {
    int recruit;

    if( !str || str == "")
        return do_prompt();

    if( str == "y" || str == "yes") {
        recruit = 1;
    } else if( str == "n" || str == "no") {
        recruit = 0;
    } else {
        tell_object( TP, "Please enter yes or no [y|n]: ");
        input_to( (: add_deity_recruit( $1, $(deity), $(title), $(info),
            $(gender), $(low), $(high), $(flag) ) :) );
        return;
    }

    if( flag ) {
        DEITY_H->set_want_worshippers( deity, recruit );
        tell_object( TP, GREEN+"\n"+deity+" will"+( recruit ?
            "" : " not")+" accept worshippers now.\n\n"+RESET );
        return do_prompt();
    }

    str = sprintf("Name       : %s\nGender     : %s\nTitle      : %s\n"
                  "Info       : %s\nLower AL   : %i\nUpper AL   : %i\n"
                  "Recruiting : %s\n", deity,
                  ( gender ? ( gender == 1 ? "male" : "female") : "neuter"),
                  title, info, low, high, ( recruit ? "yes" : "no") );

    tell_object( TP, "Are you certain you wish to add a deity with the "
        "following stats:\n"+str+"[y|n]: ");

    input_to( (: add_deity_end( $1, $(deity), $(title), $(info),
        $(gender), $(low), $(high), $(recruit) ) :) );

} /* add_deity_recruit() */

private void add_deity_end( string str, string deity, string title,
                            string info, int gender, int low, int high,
                            int recruit ) {
    if( !str || ( str = lower_case(str) ) == "" || ( str != "y" &&
        str != "yes") ) {
        tell_object( TP, "Aborting...\n");
        return do_prompt();
    }

    if( DEITY_H->add_deity( deity, title, info, gender, low, high, recruit ) )
        tell_object( TP, GREEN+"\nSuccessfully added "+deity+" into the "
            "deity handler.\n\n"+RESET );
    else
        tell_object( TP, RED+"\nFailed to add "+deity+" into the deity "
            "handler for some reason.\n\n"+RESET );

    tell_object( TP, "To add commands or rituals specific to the deity, "
        "please use the Modify Deity option.\n\n");

    return do_prompt();

} /* add_deity_end() */

private void remove_deity( string deity ) {
    if( !deity || deity == "")
        return do_prompt();

    if( !DEITY_H->query_deity( deity = CAP(lower_case(deity)) ) ) {
        tell_object( TP, RED+"\nThere is no such deity: "+deity+".\n\n"+
            RESET );
        return do_prompt();
    }

    tell_object( TP, "Are you certain you wish to completely remove "+
        deity+" from the deity handler? [y|n]: ");
    input_to( (: remove_deity_end( $1, $(deity) ) :) );

} /* remove_deity() */

private void remove_deity_end( string str, string deity ) {
    if( !str || ( str = lower_case(str) ) == "" || ( str != "y" &&
        str != "yes") ) {
        tell_object( TP, "Aborting...\n");
        return do_prompt();
    }

    if( DEITY_H->remove_deity( deity ) )
        tell_object( TP, GREEN+"\nSuccessfully removed "+deity+" from the "
            "deity handler.\n\n"+RESET );
    else
        tell_object( TP, RED+"\nFailed to remove "+deity+" from the deity "
            "handler for some reason.\n\n"+RESET );

    return do_prompt();

} /* remove_deity_end() */

/**
 * @ignore yes
 * The following need checks for existance of ritual/command objects etc.
 * That is, after we've decided how to deal with deity specific stuff in
 * the first place.
 */
private void add_ritual( string ritual, string deity, int flag ) {
    tell_object( TP, "Sorry, this option hasn't been implemented yet.\n");
    return do_prompt();
} /* add_ritual() */

private void remove_ritual( string ritual, string deity, int flag ) {
    tell_object( TP, "Sorry, this option hasn't been implemented yet.\n");
    return do_prompt();
} /* remove_ritual() */

private void add_command( string cmd, string deity, int flag ) {
    tell_object( TP, "Sorry, this option hasn't been implemented yet.\n");
    return do_prompt();
} /* add_command() */

private void remove_command( string cmd, string deity, int flag ) {
    tell_object( TP, "Sorry, this option hasn't been implemented yet.\n");
    return do_prompt();
} /* remove_command() */

private void do_edit_prompt( string deity ) {
    string s1, s2, s3, s4, s5, s6, s7, s8, s9, s10;
    string str = @END
-------------------------------------------------------------------------
%s
-------------------------------------------------------------------------
  %sCommand                                      Status%s

  [1]  Modify Gender                           %s
  [2]  Modify Title                            %s
  [3]  Modify Info                             %s
  [4]  Modify Lower Alignment Limit            %s
  [5]  Modify Lower Alignment Limit            %s
  [6]  Modify Recruiting Flag                  %s
  [7]  Add Ritual                              %s
  [8]  Remove Ritual                           %s
  [9]  Add Command                             %s
  [10] Remove Command                          %s

Enter your command [1-8], [B] to go back, or [Q] to quit:
END;

    s1 = s2 = s3 = s4 = s5 = s6 = RED+"Unavailable"+RESET;

    if( lordp(TP) )
        s1 = s2 = s3 = s4 = s5 = s6 = s7 = s8 = s9 = s10 = GREEN+"Available"+RESET;

    s7 = s8 = s9 = s10 = RED+"Under Construction"+RESET;

    tell_object( TP, sprintf( str, tool_title, BOLD, RESET,
        s1, s2, s3, s4, s5, s6, s7, s8, s9, s10 ) );

    input_to( (: get_edit_command( $1, $(deity) ) :) );

} /* do_edit_prompt() */

private void get_edit_command( string str, string deity ) {
    mixed tmp;

    if( !str || !lordp(TP) ) {
        display_menu();
        return do_prompt();
    }

    switch( str ) {
      case "1":
        tmp = DEITY_H->query_gender(deity);
        tell_object( TP, "Enter the new gender for "+deity+" (currently '"+
            ( tmp ? ( tmp == 1 ? "male" : "female") : "neuter")+"') "
            "[0|1|2]: ");
        input_to( (: add_deity_gender( $1, $(deity), 0, 0, 1 ) :) );
      break;
      case "2":
        tmp = DEITY_H->query_title(deity);
        tell_object( TP, "Enter the new title for "+deity+" (currently '"+
            tmp+"'): ");
        input_to( (: add_deity_title( $1, $(deity), 1 ) :) );
      break;
      case "3":
        tell_object( TP, "Enter the new finger info for "+deity+", "
            "currently:\n"+tmp+": ");
        input_to( (: add_deity_info( $1, $(deity), 0, 1 ) :) );
      break;
      case "4":
        tmp = DEITY_H->query_al_lower(deity);
        tell_object( TP, "Enter the new lower alignment limit for "+
            deity+" (currently "+tmp+"): ");
        input_to( (: add_deity_lower( $1, $(deity), 0, 0, 0, 1 ) :) );
      break;
      case "5":
        tmp = DEITY_H->query_al_upper(deity);
        tell_object( TP, "Enter the new upper alignment limit for "+
            deity+" (currently "+tmp+"): ");
        input_to( (: add_deity_upper( $1, $(deity), 0, 0, 0,
            DEITY_H->query_al_lower($(deity)), 1 ) :) );
      break;
      case "6":
        tmp = DEITY_H->query_want_worshippers(deity);
        tell_object( TP, "Enter whether or not you want "+deity+" to accept "
            "new worshippers (currently "+( tmp ? "yes" : "no")+") [y|n]: ");
        input_to( (: add_deity_recruit( $1, $(deity), 0, 0, 0, 0, 0, 1 ) :) );
      break;
      case "7":
        tell_object( TP, "Enter the name of the ritual you want to add to "+
            deity+": ");
        input_to( (: add_ritual( $1, $(deity), 0 ) :) );
      break;
      case "8":
        tell_object( TP, "Enter the name of the ritual you want to remove "
            "from "+deity+": ");
        input_to( (: remove_ritual( $1, $(deity), 0 ) :) );
      break;
      case "9":
        tell_object( TP, "Enter the name of the command you want to add to "+
            deity+": ");
        input_to( (: add_command( $1, $(deity), 0 ) :) );
      break;
      case "10":
        tell_object( TP, "Enter the name of the command you want to remove "
            "from "+deity+": ");
        input_to( (: remove_command( $1, $(deity), 0 ) :) );
      break;
      case "B":
      case "b":
        return do_prompt();
      case "Q":
      case "q":
        map_delete( return_mapping, TP );
        return;
      default:
        return do_edit_prompt( deity );
    }

} /* get_edit_command() */

private void do_edit( string deity ) {
    if( !deity || deity == "")
        return do_prompt();

    if( !DEITY_H->query_deity( deity = CAP(lower_case(deity)) ) ) {
        tell_object( TP, RED+"\nThere is no such deity: "+deity+".\n\n"+
            RESET );
        return do_prompt();
    }

    input_to( (: get_edit_command( $1, $(deity) ) :) );

} /* do_edit() */

private void do_view( string deity ) {
    if( !deity || deity == "")
        return do_prompt();

    if( !DEITY_H->query_deity( deity = CAP(lower_case(deity)) ) ) {
        tell_object( TP, RED+"\nThere is no such deity: "+deity+".\n\n"+
            RESET );
        return do_prompt();
    }

    tell_object( TP, DEITY_H->query_deity_data( deity ) );
    do_prompt();

} /* do_view() */

private void do_list() {
    tell_object( TP, create_table( ({"Deities", "deity"}),
        DEITY_H->query_deities() ) );
    do_prompt();
} /* do_list() */

private void no_privs() {
    tell_object( TP, "You don't have the privileges to use this option.\n");
    cmd("");
} /* no_privs() */

private void get_command( string str ) {
    if( !str || !creatorp(TP) ) {
        display_menu();
        return do_prompt();
    }

    switch( str ) {
      case "1":
        if( lordp(TP) ) {
            tell_object( TP, "Enter the name of the new deity to add :");
            input_to( (: add_deity :) );
        } else {
            no_privs();
        }
      break;
      case "2":
        if( lordp(TP) ) {
            tell_object( TP, "Enter the name of the deity to remove :");
            input_to( (: remove_deity :) );
        } else {
            no_privs();
        }
      break;
      case "3":
        if( lordp(TP) ) {
            tell_object( TP, "Enter the name of the deity to modify : ");
            input_to( (: do_edit :) );
        } else {
            no_privs();
        }
      break;
      case "4":
        tell_object( TP, "Enter the name of the deity to view stats for : ");
        input_to( (: do_view :) );
      break;
      case "5":
        do_list();
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
        if( !undefinedp(return_mapping[TP]) )
            map_delete( return_mapping, TP );
        return;
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
