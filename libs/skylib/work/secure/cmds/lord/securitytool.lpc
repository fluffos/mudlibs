/**
 * securitytool.c
 * The Security Control Tool
 * for the admtool
 * Shaydz 2 Apr '00
 */

#include <colors.h>
inherit COMMAND_BASE;

#define MAIL_FILE "/doc/creator/concepts/creator_doc.txt"
#define IDLE_APP  "/d/admin/text/idle_app.txt"
#define PRIVILEGE(XXX) PRIVILEGE_H->query_privilege(XXX,TP->query_name())

private mapping return_mapping = ([ ]);
private string main_menu_template = @END
-------------------------------------------------------------------------
%s
-------------------------------------------------------------------------
  %sCommand                                      Status%s

  [1]  Promote new creator                     %s
  [2]  Demote creator                          %s
  [3]  Suspend player                          %s
  [4]  Unsuspend player                        %s
  [5]  Banish Player                           %s
  [6]  Grant Privilege                         %s
  [7]  Revoke Privilege                        %s
  [8]  List creators privileges                %s
  [9]  List all privileges in system           %s

END;

private string main_prompt = "Enter your command [1-9], or [Q] to quit: ";
private string main_prompt2 = "Enter your command [1-9], [B] to go back, or [Q] to quit: ";

// Function prototypes
mixed cmd(string args);
private void get_command( string str );
private void promote_creator();
private void promote_creator2( string str );
private void promote_creator3( string str, string domain );
private void demote_creator();
private void demote_creator2( string str);
private void demote_creator3( string reason, string str );
private void demote_creator4( string str, string crea, string reason );
private void suspend_player();
private void suspend_player2( string str );
private void suspend_player3( string str, string str2 );
private void unsuspend_player();
private void unsuspend_player2( string str );
private void unsuspend_player3( string str, string str2 );
private void banish_player();
private void banish_player2( string str );
private void banish_player3( string str, string pname );
private void banish_player4( string str, string pname );
private void banish_player5( string str, string pname, string reason );
private void grant_privilege();
private void grant_privilege2( string str );
private void grant_privilege3( string str, string str2 );
private void revoke_privilege();
private void revoke_privilege2( string str );
private void revoke_privilege3( string str, string str2 );
private void list_cre_privileges();
private void list_cre_privileges2( string str );
private void list_cre_privileges3( string args );
private void list_all_privileges();
private void list_all_privileges2( string str );

private void display_menu() {
    string title, s1, s2, s3, s4, s5, s6, s7, s8, s9;

    title = sprintf("%s%|72s%s", YELLOW,
        mud_name()+" Security Control Tool v1.5", RESET );

    s1 = s2 = s3 = s4 = s5 =  s6 = s7 = s8 = s9 = RED+"Unavailable"+RESET;

    if( PRIVILEGE("creator.add") )
        s1 = GREEN+"Available"+RESET;

    if( PRIVILEGE("creator.remove") )
        s2 = GREEN+"Available"+RESET;

    if( PRIVILEGE("player.suspend") )
        s3 = GREEN+"Available"+RESET;

    if( PRIVILEGE("player.unsuspend") )
        s4 = GREEN+"Available"+RESET;

    if( PRIVILEGE("player.banish") )
        s5 = GREEN+"Available"+RESET;

    if( PRIVILEGE("privilege.add") )
        s6 = GREEN+"Available"+RESET;

    if( PRIVILEGE("privilege.remove") )
        s7 = GREEN+"Available"+RESET;

    if( adminp(TP) )
        s8 = GREEN+"Available"+RESET;

    if( adminp(TP) )
        s9 = GREEN+"Available"+RESET;

    tell_object( TP, sprintf( main_menu_template, title, BOLD, RESET,
                 s1, s2, s3, s4, s5, s6, s7, s8, s9 ) );

} /* display_menu() */

private void do_prompt() {
    tell_object( TP, undefinedp(return_mapping[TP]) ? main_prompt :
                                                      main_prompt2 );
    input_to( (: get_command :) );
} /* do_prompt() */

private void promote_creator() {
    if( !PRIVILEGE("creator.add") ) {
        tell_object( TP, RED+"\nYou don't have the power to do that.\n"+
            RESET );
        return do_prompt();
    }

    tell_object( TP, "Enter the name of the player to promote: ");
    input_to( (: promote_creator2 :) );

} /* promote_creator() */

private void promote_creator2( string str ) {
    if( !str || str == "")
        return do_prompt();

    if( !LOGIN_OBJ->test_user(str) ) {
        tell_object( TP, RED+"\n"+CAP(str)+" isn't a player here.\n"+RESET );
        return do_prompt();
    }

    tell_object( TP, "What domain should "+CAP(str)+" start in? "
        "[press enter for learning] : ");
    input_to( (: promote_creator3( $1, $(str) ) :) );

} /* promote_creator2() */

private void promote_creator3( string str, string crea ) {
    string err, old;

    if( !str || str == "" )
        str = "learning";

    if( !DOMAIN_H->query_domain(str) ) {
        tell_object( TP, RED+"\n"+CAP(str)+" isn't a valid domain, putting "
            "them in Learning.\n"+RESET );
        str = "learning";
    }

    old = geteuid(TO);
    seteuid(geteuid(TP));

    if( !err = DOMAIN_H->add_creator(crea) ) {
        DOMAIN_H->add_member( str, crea );

        if( file_exists(MAIL_FILE) ) {
            string body = read_file(MAIL_FILE);
            MAIL_H->do_mail_message( crea, TP->query_name(),
                "How to get started.", "", body, 0, 0 );
        }

        tell_object( TP, GREEN+"\n"+CAP(crea)+" has been promoted.\n"+RESET );
        event( users(), "inform", TP->query_cap_name()+" has promoted "+
            CAP(crea)+".", "admin");
    } else {
        tell_object( TP, RED+"\nUnable to promote "+CAP(crea)+" because: "+
            err+"\n"+RESET );
    }

    seteuid(old);

    return do_prompt();

} /* promote_creator3() */

private void demote_creator() {
    if( !PRIVILEGE("creator.remove") ) {
        tell_object( TP, RED+"\nYou don't have the power to do that.\n"+
            RESET );
        return do_prompt();
    }

    tell_object( TP, "Enter the name of the creator to demote: ");
    input_to( (: demote_creator2 :) );

} /* demote_creator() */

private void demote_creator2( string str ) {
    if( !str || str == "")
        return do_prompt();

    if( !creatorp(str) ) {
        tell_object( TP, RED+"\n"+CAP(str)+" isn't a creator here.\n"+RESET );
        return do_prompt();
    }

    tell_object( TP, "Please enter a reason for demoting "+CAP(str)+".\n"
        "\"idle app\" for idle apprentices: ");
    input_to( (: demote_creator3( $1, $(str) ) :) );

} /* demote_creator2() */

private void demote_creator3( string reason, string str ) {
    if( !reason || reason == "")
        return do_prompt();

    tell_object( TP, "Are you sure you wish to demote "+CAP(str)+": ");
    input_to( (: demote_creator4( $1, $(str), $(reason) ) :) );

} /* demote_creator2() */

private void demote_creator4( string str, string crea, string reason ) {
    string err, old;

    if( !str || str == "")
        return do_prompt();

    str = lower_case(str);

    if( str != "y" && str != "yes")
        return do_prompt();

    old = geteuid(TO);
    seteuid(geteuid(TP));

    if( !err = DOMAIN_H->remove_creator( crea+" "+reason ) ) {
        tell_object( TP, GREEN+"\n"+CAP(crea)+" has been demoted.\n"+RESET );
        event( users(), "inform", TP->query_cap_name()+" has demoted "+
            CAP(crea)+" for "+reason+".", "admin");
        if( reason == "idle app" && file_exists(IDLE_APP) ) {
            string body = read_file(IDLE_APP);
            body = replace( body, "$cre$", TP->query_cap_name() );
            MAIL_H->do_mail_message( crea, TP->query_name(),
                "Your demotion.", "", body, 0, 0 );
        }
    } else {
        tell_object( TP, RED+"\nUnable to demote "+CAP(crea)+" because: "+
            err+"\n"+RESET );
    }

    seteuid(old);

    return do_prompt();

} /* demote_creator3() */

private void suspend_player() {
    if( !PRIVILEGE("player.suspend") ) {
        tell_object( TP, RED+"\nYou don't have the power to do that.\n"+
            RESET );
        return do_prompt();
    }

    tell_object( TP, "Enter the name of the player to suspend: ");
    input_to( (: suspend_player2 :) );

} /* suspend_creator() */

private void suspend_player2( string str ) {
    if( !str || str == "")
        return do_prompt();

    if( !LOGIN_OBJ->test_user(str) ) {
        tell_object( TP, RED+"\n"+CAP(str)+" isn't a player here.\n"+RESET );
        return do_prompt();
    }

    tell_object( TP, "How many hours do you wish to suspend "+
        CAP(str)+" for? : ");
    input_to( (: suspend_player3( $1, $(str) ) :) );

} /* suspend_player2() */

private void suspend_player3( string str, string str2 ) {
    int tim;

    if( !str || str == "")
        return do_prompt();

    tim = to_int(str);

    if( !BASTARDS_H -> suspend_person( str2, tim*60*60 ) ) {
        tell_object( TP, RED+"\nSuspension not accepted.\n"+RESET );
        return do_prompt();
    }

    tell_object( TP, CAP(str2)+" suspended until "+
        ctime(time()+tim*60*60)+"\n");

    return do_prompt();

} /* suspend_player3() */

private void unsuspend_player() {
    if( !PRIVILEGE("player.unsuspend") ) {
        tell_object( TP, RED+"\nYou don't have the power to do that.\n"+
            RESET );
        return do_prompt();
    }

    tell_object( TP, "Enter the name of the player to unsuspend: ");
    input_to( (: unsuspend_player2 :) );

} /* unsuspend_player() */

private void unsuspend_player2( string str ) {
    if( !str || str == "")
        return do_prompt();

    if( !PLAYER_H->test_user(str) ) {
        tell_object( TP, RED+"\n"+CAP(str)+" isn't a player here.\n"+RESET );
        return do_prompt();
    }

    tell_object( TP, "Are you sure you wish to unsuspend "+CAP(str)+"? : ");
    input_to( (: unsuspend_player3( $1, $(str) ) :) );

} /* unsuspend_player2() */

private void unsuspend_player3( string str, string str2 ) {
    str = lower_case(str);

    if( !str || str == "")
        return do_prompt();

    if( str != "y" && str != "yes")
        return do_prompt();

    if( !BASTARDS_H->unsuspend_person(str2) ) {
        tell_object( TP, RED+"\nYou don't have access to do that.\n"+RESET );
        return do_prompt();
    }

    tell_object( TP,GREEN+"\n"+CAP(str2) +" unsuspended.\n"+RESET );
    return do_prompt();

} /* unsuspend_player3() */

private void banish_player() {
    if( !PRIVILEGE("player.banish") ) {
        tell_object( TP, RED+"\nYou don't have the power to do that.\n"+RESET );
        return do_prompt();
    }

    tell_object( TP, "Enter the name of the player to banish: ");
    input_to( (: banish_player2 :) );

} /* banish_player() */

private void banish_player2( string str ) {
    if( !str || str == "")
        return do_prompt();

    str = lower_case( str ) ;

    if( creatorp(str) ) {
        tell_object( TP, RED+"\nYou cannot banish creators, please demote "
            "them first.\n"+RESET );
        return do_prompt();
    }

    if( file_exists("/banish/"+str[0..0]+"/"+str+".o") ) {
        tell_object( TP, RED+"\nThe name ["+str+"] has already been "
            "banished.\n"+RESET );
        return do_prompt();
    }

    if( file_exists("/save/banish/"+str+".o") ) {
        tell_object( TP, "The name ["+str+"] has already been backed up.  "
            "Please remove the file first from /save/banish/.\n"+RESET );
        return do_prompt();
    }

    if( file_exists("/save/players/"+str[0..0]+"/"+str+".o") ) {
        tell_object( TP, "Are you sure you wish to banish "+CAP(str)+": ");
        input_to( (: banish_player3( $1, $(str) ) :) );
        return;
    }

    tell_object( TP, "The player file does not exist, continue ? [Y/N] : ");
    input_to( (: banish_player3( $1, $(str) ) :) );
    return;

} /* banish_player2() */

private void banish_player3( string str, string pname ) {
    str = lower_case(str);

    if( !str || str == "")
        return do_prompt();

    if( str == "y") {
        tell_object( TP, "Please enter a reason: ");
        input_to( (: banish_player4( $1, $(pname) ) :) );
        return;
    }

    tell_object( TP, RED+"\nAborting banish process.\n"+RESET );
    return do_prompt();

} /* banish_player3() */

private void banish_player4( string str, string pname ) {
    if( !str || str == "") {
        tell_object( TP, RED+"\nAborting banish process.\n"+RESET );
        return do_prompt();
    }

    if( file_exists("/save/players/"+pname[0..0]+"/"+pname+".o") ) {
        tell_object( TP, "Do you want to remove the old player file? [Y/N] : ");
        input_to( (: banish_player5( $1, $(pname), $(str) ) :) );
        return;
    }

    tell_object( TP, GREEN+ "\nOkay, "+CAP(pname)+" banished.\n"+RESET );
    return do_prompt();

} /* banish_player4() */

private void banish_player5( string str, string pname, string reason ) {
    string old;

    str = lower_case(str);

    if( !str || str == "")
        return do_prompt();

    reason = "Banished by : "+TP->query_cap_name()+"\n"
             "Banished on : "+ctime( time() )+"\n"
             "Reason      : "+reason+"\n";

    old = geteuid(TO);
    seteuid(geteuid(TP));

    if( str == "y") {
        unguarded( (: rm, "/save/players/"+pname[0..0]+"/"+pname+".o" :) );

        BULK_DELETE_H->delete_related_files( pname, 1 );

        write_file("/banish/"+pname[0..0]+"/"+pname+".o", reason );

        seteuid(old);

        tell_object( TP, "Okay, player banished and save file removed.\n"+
            RESET );

        return do_prompt();
    }

    if( !dir_exists("/save/banish/") )
        unguarded( (: mkdir, "/save/banish" :) );

    unguarded( (: rename, "/save/players/"+pname[0..0]+"/"+pname+".o",
        "/save/banish/"+pname+".o" :) );

    write_file("/banish/"+pname[0..0]+"/"+pname+".o", reason );

    seteuid(old);

    tell_object( TP, "Okay, player banished and playerfile backed up.\n");

    return do_prompt();

} /* banish_player5() */

private void grant_privilege() {
    if( !PRIVILEGE("privilege.add") ) {
        tell_object( TP,RED+"\nYou don't have the power to do that.\n"+RESET );
        return do_prompt();
    }

    tell_object( TP, "Enter the name of the privilege to grant "
        "(eg. creator.add) : ");
    input_to( (: grant_privilege2 :) );

} /* grant_privilege() */

private void grant_privilege2( string str ) {
    if( !str || str == "")
        return do_prompt();

    // Need something here to check whether this privilege is valid at all.
    tell_object( TP, "What player do you want to add the privilege "+
        str+" to: ");
    input_to( (: grant_privilege3( $1, $(str) ) :) );

} /* grant_privilege2() */

private void grant_privilege3( string str, string str2 ) {
    string err, old;

    if( !str || str == "")
        return do_prompt();

    old = geteuid(TO);
    seteuid(geteuid(TP));

    if( !err = PRIVILEGE_H->add_privilege( str2, str ) ) {
        tell_object( TP, GREEN+"\nAdded privilege "+str2+" to "+
            CAP(str)+".\n\n"+RESET );
        seteuid(old);
        return do_prompt();
    }

    tell_object( TP, RED+"\nFailed to add privilege "+str2+" to "+
        CAP(str)+" because: "+err+"\n"+RESET );

    seteuid(old);

    return do_prompt();

} /* grant_privilege3() */

private void revoke_privilege() {
    if( !PRIVILEGE("privilege.remove") ) {
        tell_object( TP, RED+"\nYou don't have the power to do that.\n"+RESET );
        return do_prompt();
    }

    tell_object( TP, "Enter the name of the privilege to revoke "
        "(eg. creator.add) : ");
    input_to( (: revoke_privilege2 :) );

} /* revoke_privilege() */

private void revoke_privilege2( string str ) {
    if( !str || str == "")
        return do_prompt();

    tell_object( TP, "What player do you want to remove the privilege "+
        str+" from: ");
    input_to( (: revoke_privilege3($1, $(str)) :) );

} /* revoke_privilege2() */

private void revoke_privilege3( string str, string str2 ) {
    string err, old;

    if( !str || str == "")
        return do_prompt();

    old = geteuid(TO);
    seteuid(geteuid(TP));

    if( !err = PRIVILEGE_H->remove_privilege( str2, str ) ) {
        tell_object( TP, GREEN+"\nRemoved privilege "+str2+" from "+
            CAP(str)+".\n\n"+RESET );
    } else {
        tell_object( TP, RED+"\nFailed to remove privilege "+str2+" from "+
            CAP(str)+" because: "+err+"\n"+RESET );
    }

    seteuid(old);

    return do_prompt();

} /* revoke_privilege3() */

private void list_cre_privileges() {
    if( !adminp(TP) ) {
        tell_object( TP, RED+"\nYou don't have the power to do that.\n"+
            RESET );
        return do_prompt();
    }

    tell_object( TP, "Enter the name of the creator to view.  Press 'enter' "
        "to view all creators or type 'nosages' to exclude sages from the "
        "list: ");
    input_to( (: list_cre_privileges2 :) );

} /* list_cre_privileges() */

private void list_cre_privileges2( string str ) {
    string *ret;

    if( !str || str == "") {
        list_cre_privileges3("all");
        return;
    }

    if( str == "nosages") {
        list_cre_privileges3("nosages");
        return;
    }

    if( adminp(str) ) {
        if( str == TP->query_name() ) {
            tell_object( TP, GREEN+"\nYou are an admin, and have all "
                "privileges.\n"+RESET );
        } else {
            tell_object( TP, GREEN+"\n"+CAP(str)+" is an admin, and has all "
                "privileges.\n"+RESET );
        }
        return do_prompt();
    }

    if( !creatorp(str) ) {
        tell_object( TP, RED+"\n"+CAP(str)+" is not a creator.\n"+RESET );
        return do_prompt();
    }

    ret = PRIVILEGE_H->query_privileges(str);

    if( !sizeof(ret) ) {
        tell_object( TP, GREEN+"\n"+CAP(str)+" does not have any "
            "privileges.\n"+RESET );
        return do_prompt();
    }

    tell_object( TP, sprintf("%s\n%s has the following privileges:%s%s\n"
        "%-*#s%s\n\n", GREEN, CAP(str), RESET, YELLOW, 79,
        implode( sort_array( ret, 1 ), "\n"), RESET ) );

    return do_prompt();

} /* list_cre_privileges2() */

private void list_cre_privileges3( string args ) {
    string *ret, *creas, str;

    creas = DOMAIN_H->query_creators();

    if( args == "nosages")
        creas -= DOMAIN_H->query_members("sage");

    creas = asort(creas);

    if( !creas ) {
        tell_object( TP, RED+"\nThere don't appear to be any creators!!!\n"+
            RESET );
        return do_prompt();
    }

    args = "";

    foreach( str in creas ) {
        ret = PRIVILEGE_H->query_privileges(str);

        if( !sizeof(ret) && !adminp(str) )
            continue;

        args += GREEN+"\n"+CAP(str)+":\n"+YELLOW;

        if( adminp(str) ) {
            if( str == TP->query_name() ) {
                args += "You are an admin, and have all privileges.\n";
            } else {
                args += CAP(str)+" is an admin, and has all privileges.\n";
            }
            args += RESET;
            continue;
        }

        if( !creatorp(str) ) {
            args += RED+"\n"+CAP(str)+" is not a creator.\n"+RESET;
            continue;
        }

        args += sprintf("%-*#s%s\n", 79,
            implode( sort_array( ret, 1 ), "\n"), RESET );

    }

    tell_object( TP, args+"\n");
    return do_prompt();

} /* list_cre_privileges3() */

private void list_all_privileges() {
    string *ret;

    if( !adminp(TP) ) {
        tell_object( TP, RED+"\nYou don't have the power to use this "
            "option.\n"+RESET );
        return do_prompt();
    }

    ret = PRIVILEGE_H->query_privilege_types();

    if( !ret ) {
        tell_object( TP, GREEN+"\nThere have been no privileges "
            "assigned.\n"+RESET );
        return do_prompt();
    }

    tell_object( TP, sprintf("%s\nThe following privileges have been entered "
        "into the system:\n%s%s%-*#s\n", GREEN, RESET, YELLOW, 79,
        implode( sort_array( ret, 1 ), "\n") )+"\n"+RESET );

    return do_prompt();

} /* list_all_privileges() */

private void get_command( string str ) {
    if( !str ) {
        display_menu();
        return do_prompt();
    }

    switch( str ) {
      case "1":
        promote_creator();
      break;
      case "2":
        demote_creator();
      break;
      case "3":
        suspend_player();
      break;
      case "4":
        unsuspend_player();
      break;
      case "5":
        banish_player();
      break;
      case "6":
        grant_privilege();
      break;
      case "7":
        revoke_privilege();
      break;
      case "8":
        list_cre_privileges();
      break;
      case "9":
        list_all_privileges();
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

int cmd( string arg ) {
    if( PO && file_name(PO) == "/secure/cmds/creator/admtools")
        return_mapping[TP] = PO;

    if( !lordp(TP) ) {
        log_file("SECURITY_VIOLATION", TP->query_name()+" attempted to "
            "illegally use the SecurityTool on "+ctime(time())+"\n");
        return notify_fail("%^RED%^Security Violation!\n%^RESET%^");;
    }

    display_menu();
    do_prompt();

    return 1;

} /* cmd() */
