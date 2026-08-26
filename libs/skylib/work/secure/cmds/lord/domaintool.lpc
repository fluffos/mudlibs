/* domaintool.c
 * The Domain Control Tool
 * for the admtool
 *Shaydz 3 Apr '00
 */

#include <colors.h>
inherit COMMAND_BASE;

private mapping return_mapping = ([ ]);
private string main_menu_template = @END
-------------------------------------------------------------------------
%s
-------------------------------------------------------------------------
  %sCommand                                      Status%s

  [1]  Create new Domain                      %s
  [2]  Delete Domain                          %s
  [3]  List Domains                           %s
  [4]  Add Leader to Domain                   %s
  [5]  Add Senior to Domain                   %s
  [6]  Add Member to Domain                   %s
  [7]  Remove Leader from Domain              %s
  [8]  Remove Senior from Domain              %s
  [9]  Remove Member from Domain              %s

END;

private string main_prompt = "Enter your command [1-9], or [Q] to quit: ";
private string main_prompt2 = "Enter your command [1-9], [B] to go back, or [Q] to quit: ";

// Function prototypes
mixed cmd(string arg);
private void get_command(string str);
private void create_domain();
private void create_domain2(string str);
private void create_domain3(string str, string domain);
private void delete_domain();
private void delete_domain2(string str);
private void delete_domain3(string str, string domain);
private void list_domains();
private void add_leader();
private void add_leader2(string str);
private void add_leader3(string str, string domain);
private void add_member();
private void add_member2(string str);
private void add_member3(string str, string domain);
private void remove_leader();
private void remove_leader2(string str);
private void remove_leader3(string str, string domain);
private void remove_member();
private void remove_member2(string str);
private void remove_member3(string str, string domain);
private void add_senior();
private void add_senior2(string str);
private void add_senior3(string str, string domain);
private void remove_senior();
private void remove_senior2(string str);
private void remove_senior3(string str, string domain);

private void display_menu() {
    string title, s1, s2, s3, s4, s5, s6, s7, s8, s9;

    title = sprintf("%s%|72s%s", YELLOW,
        mud_name()+" Domains Control Tool v1.5", RESET );

    s1 = s2 = s3 = s4 = s5 = s6 = s7 = s8 = s9 = RED+"Unavailable"+RESET;

    if( DOMAIN_H->query_leader( TP->query_name() ) ) {
        s5 = s6 = s8 = s9 = MAGENTA+"Limited"+RESET;
        s3 = GREEN+"Available"+RESET;
    }

    if( adminp(TP) )
        s1 = s2 = s3 = s4 = s5 = s6 = s7 = s8 = s9 = GREEN+"Available"+RESET;

    tell_object( TP, sprintf( main_menu_template, title, BOLD, RESET,
        s1, s2, s3, s4, s5, s6, s7, s8, s9 ) );

} /* display_menu() */

private void do_prompt() {
    tell_object( TP, undefinedp(return_mapping[TP]) ? main_prompt :
                                                      main_prompt2 );
    input_to( (: get_command :) );
} /* do_prompt() */

private void create_domain() {
    if( !adminp(TP) ) {
        tell_object( TP, RED+"\nYou are not authorised to use this option.\n"+
            RESET );
        return do_prompt();
    }

    tell_object( TP, "Enter the name of the NEW Domain ('q' to abort): ");
    input_to( (: create_domain2 :) );

} /* create_domain() */

private void create_domain2( string str ) {
    if( !str || str == "")
        return do_prompt();

    if( DOMAIN_H->query_domain( str ) ) {
        tell_object( TP, "The "+CAP(str)+" domain already exists.\n");
        return do_prompt();
    }

    if( ( str = lower_case(str) ) == "q")
        return do_prompt();

    tell_object( TP, "Enter the name of the Domain leader or press return "
        "to use yourself ('q' to abort): ");
    input_to( (: create_domain3( $1, $(str)) :) );

} /* create_domain2() */

private void create_domain3( string str, string domain ) {
    string err, old;

    if( !str || str == "")
        str = TP->query_name();

    if( ( str = lower_case(str) ) == "q")
        return do_prompt();

    old = geteuid(TO);
    seteuid(geteuid(TP));

    if( err = DOMAIN_H->add_domain(domain) ) {
        tell_object( TP, RED+"\n"+err+"\n"+RESET );
        seteuid(old);
        return do_prompt();
    }

    if( err = DOMAIN_H->add_member( domain, str ) ) {
        tell_object( TP, RED+"\n"+err+"\n"+RESET );
        seteuid(old);
        return do_prompt();
    }

    if( err = DOMAIN_H->add_leader( domain, str ) ) {
        tell_object( TP, RED+"\n"+err+"\n"+RESET );
        seteuid(old);
        return do_prompt();
    }

    seteuid(old);

    log_file("PROMOTIONS", "%s - %s created a new domain %s with %s as "
        "lord.\n", ctime(time()), CAP(TP->query_name()), CAP(domain),
        CAP(str) );

    tell_object( TP, GREEN+"\nCreated domain "+CAP(domain)+" with "+
        CAP(str)+" as its leader.\n\n"+RESET );

    do_prompt();

} /* create_domain3() */

private void delete_domain() {
    if( !adminp(TP) ) {
        tell_object( TP, RED+"\nYou are not authorised to use this option.\n"+
            RESET );
        return do_prompt();
    }

    tell_object( TP, "Enter the name of the domain to DELETE: ");
    input_to( (: delete_domain2 :) );

} /* delete_domain() */

private void delete_domain2( string str ) {
    if( !str || str == "")
        return do_prompt();

    if( !DOMAIN_H->query_domain( str = lower_case(str) ) ) {
        tell_object( TP, RED+"The "+CAP(str)+" domain doesn't exist.\n"+
            RESET );
        return do_prompt();
    }

    tell_object( TP, "Are you sure you wish to delete the "+
        CAP(str)+" domain? : ");
    input_to( (: delete_domain3( $1, $(str)) :) );

} /* delete_domain2() */

private void delete_domain3( string str, string domain ) {
    string err, old;

    if( !str || str == "")
        return do_prompt();

    str = lower_case(str);

    if( str != "y" && str != "yes" ) {
        tell_object( TP, "\nThe "+CAP(domain)+" domain has NOT been "
            "deleted.\n");
        return do_prompt();
    }

    old = geteuid(TO);
    seteuid(geteuid(TP));

    if( err = DOMAIN_H->remove_domain(domain) ) {
        tell_object( TP, RED+"\n"+err+"\n"+RESET );
        seteuid(old);
        return do_prompt();
    }

    seteuid(old);

    log_file("PROMOTIONS", "%s - %s removed domain %s.\n", ctime(time()),
        CAP(TP->query_name()), CAP(domain) );

    tell_object( TP, GREEN+"\nRemoved domain "+CAP(domain)+".\n"+RESET );

    do_prompt();

} /* delete_domain3() */

private void list_domains() {
    tell_object( TP, create_table( ({"Domains", "domain"}),
        DOMAIN_H->query_domains(), 1 ) );
    do_prompt();
} /* list_domains() */

private void add_leader() {
    if( !adminp(TP) ) {
        tell_object( TP, RED+"\nYou are not authorised to use this option.\n"+
            RESET );
        return do_prompt();
    }

    tell_object( TP, "Enter the name of the Domain to add a leader to: ");
    input_to( (: add_leader2 :) );

} /* add_leader() */

private void add_leader2( string str ) {
    if( !str || str == "")
        return do_prompt();

    if( !DOMAIN_H->query_domain( str = lower_case(str) ) ) {
        tell_object( TP, RED+"The "+CAP(str)+" domain doesn't exist.\n"+
            RESET );
        return do_prompt();
    }

    tell_object( TP, "Enter the name of the Domain leader to add or press "
        "return to use yourself: ");
    input_to( (: add_leader3( $1, $(str)) :) );

} /* add_leader2() */

private void add_leader3( string str, string domain ) {
    string err, old;

    if( !str || str == "")
        str = TP->query_name();

    if( DOMAIN_H->query_leader( domain, str = lower_case(str) ) ) {
        tell_object( TP, RED+CAP(str)+" is already a leader of "+
            CAP(domain)+".\n"+RESET );
        return do_prompt();
    }

    if( !DOMAIN_H->query_member( domain, str ) ) {
        if( err = DOMAIN_H->add_member( domain, str ) ) {
            tell_object( TP, RED+"\n"+err+"\n"+RESET );
            return do_prompt();
        }
    }

    old = geteuid(TO);
    seteuid(geteuid(TP));

    if( err = DOMAIN_H->add_leader( domain, str ) ) {
        tell_object( TP, RED+"\n"+err+"\n"+RESET );
        seteuid(old);
        return do_prompt();
    }

    if( DOMAIN_H->query_senior( domain, str ) )
        DOMAIN_H->remove_senior( domain, str );

    seteuid(old);

    log_file("PROMOTIONS", "%s - %s added %s as a lord of %s.\n",
        ctime(time()), CAP(TP->query_name()), CAP(str), CAP(domain) );

    tell_object( TP, GREEN+"\nAdded "+CAP(str)+" as a leader of the "+
        CAP(domain)+" domain.\n\n"+RESET );

    do_prompt();

} /* add_leader3() */

private void add_senior() {
    tell_object( TP, "Enter the name of the Domain to add a senior to: ");
    input_to( (: add_senior2 :) );
} /* add_senior() */

private void add_senior2( string str ) {
    if( !str || str == "")
        return do_prompt();

    if( !DOMAIN_H->query_domain( str = lower_case(str) ) ) {
        tell_object( TP, RED+"The "+CAP(str)+" domain doesn't exist.\n"+
            RESET );
        return do_prompt();
    }

    if( !adminp(TP) && !DOMAIN_H->query_leader( str, TP->query_name() ) ) {
        tell_object( TP, RED+"\nYou are not authorised to do that.\n"+RESET );
        return do_prompt();
    }

    tell_object( TP, "Enter the name of the senior to add or press return to "
        "use yourself: ");
    input_to( (: add_senior3( $1, $(str)) :) );

} /* add_member2() */

private void add_senior3( string str, string domain ) {
    string err, old;

    if( !str || str == "")
        str = TP->query_name();

    if( DOMAIN_H->query_senior( domain, str = lower_case(str) ) ) {
        tell_object( TP, RED+CAP(str)+" is already a senior of "+
            CAP(domain)+".\n"+RESET );
        return do_prompt();
    }

    if( DOMAIN_H->query_leader( domain, str ) ) {
        tell_object( TP, RED+CAP(str)+" is already a leader of "+
            CAP(domain)+".\n"+RESET );
        return do_prompt();
    }

    old = geteuid(TO);
    seteuid(geteuid(TP));

    if( err = DOMAIN_H->add_senior( domain, str ) ) {
        tell_object( TP, RED+"\n"+err+"\n"+RESET );
        seteuid(old);
        return do_prompt();
    }

    seteuid(old);

    log_file("PROMOTIONS", "%s - %s added %s as a senior of %s.\n",
        ctime(time()), CAP(TP->query_name()), CAP(str),CAP(domain) );

    tell_object( TP, GREEN+"\nAdded "+CAP(str)+" as a senior of "+
        CAP(domain)+".\n\n"+RESET );

    do_prompt();

} /* add_senior3() */

private void add_member() {
    tell_object( TP, "Enter the name of the Domain to add a member to: ");
    input_to( (: add_member2 :) );
} /* add_member() */

private void add_member2( string str ) {
    if( !str || str == "")
        return do_prompt();

    if( !DOMAIN_H->query_domain( str = lower_case(str) ) ) {
        tell_object( TP, RED+"The "+CAP(str)+" domain doesn't exist.\n"+
            RESET );
        return do_prompt();
    }

    if( !adminp(TP) && !DOMAIN_H->query_leader( str, TP->query_name() ) ) {
        tell_object( TP, RED+"\nYou are not authorised to do that.\n"+
            RESET );
        return do_prompt();
    }

    tell_object( TP, "Enter the name of the member to add or press return to "
        "use yourself: ");
    input_to( (: add_member3( $1, $(str)) :) );

} /* add_member2() */

private void add_member3( string str, string domain ) {
    string err, old;

    if( !str || str == "")
        str = TP->query_name();

    if( DOMAIN_H->query_member( domain, str = lower_case(str) ) ) {
        tell_object( TP, RED+CAP(str)+" is already a member of "+
            CAP(domain)+".\n"+RESET );
        return do_prompt();
    }

    old = geteuid(TO);
    seteuid(geteuid(TP));

    if( err = DOMAIN_H->add_member( domain, str ) ) {
        tell_object( TP, RED+"\n"+err+"\n"+RESET );
        seteuid(old);
        return do_prompt();
    }

    seteuid(old);

    tell_object( TP, GREEN+"\nAdded "+CAP(str)+" as a member of "+
        CAP(domain)+".\n\n"+RESET );

    do_prompt();

} /* add_member3() */

private void remove_leader() {
    if( !adminp(TP) ) {
        tell_object( TP, RED+"\nYou are not authorised to use this option.\n"+
            RESET );
        return do_prompt();
    }

    tell_object( TP, "Enter the name of the Domain to remove a Leader "
        "from: ");
    input_to( (: remove_leader2 :) );

} /* remove_leader() */

private void remove_leader2( string str ) {
    if( !str || str == "")
        return do_prompt();

    if( !DOMAIN_H->query_domain( str = lower_case(str) ) ) {
        tell_object( TP, RED+"The "+CAP(str)+" domain doesn't exist.\n"+
            RESET );
        return do_prompt();
    }

    tell_object( TP, "Enter the name of the Domain leader to remove or press "
        "return to use yourself: ");
    input_to( (: remove_leader3( $1, $(str)) :) );

} /* remove_leader2() */

private void remove_leader3( string str, string domain ) {
    string err, old;

    if( !str || str == "")
        str = TP->query_name();

    if( !DOMAIN_H->query_leader( domain, str = lower_case(str) ) ) {
        tell_object( TP, RED+CAP(str)+" isn't a Leader of "+
            CAP(domain)+".\n"+RESET );
        return do_prompt();
    }

    old = geteuid(TO);
    seteuid(geteuid(TP));

    if( err = DOMAIN_H->remove_leader( domain, str ) ) {
        tell_object( TP, RED+"\n"+err+"\n"+RESET );
        seteuid(old);
        return do_prompt();
    }

    seteuid(old);

    log_file("PROMOTIONS", "%s - %s removed %s as a lord of %s.\n",
        ctime(time()), CAP(TP->query_name()), CAP(str), CAP(domain) );

    tell_object( TP, GREEN+"\nRemoved "+CAP(str)+" as a leader from "+
        CAP(domain)+".\n"+RESET );

    do_prompt();

} /* remove_leader3() */

private void remove_senior() {
    tell_object( TP, "Enter the name of the Domain to remove senior from: ");
    input_to( (: remove_senior2 :) );
} /* remove_member() */

private void remove_senior2( string str ) {
    if( !str || str == "")
        return do_prompt();

    if( !DOMAIN_H->query_domain( str = lower_case(str) ) ) {
        tell_object( TP, RED+"The domain "+CAP(str)+" doesn't exist.\n"+
            RESET );
        return do_prompt();
    }

    if( !adminp(TP) && !DOMAIN_H->query_leader( str, TP->query_name() ) ) {
        tell_object( TP, RED+"\nYou are not authorised to do that.\n"+
            RESET );
        return do_prompt();
    }

    tell_object( TP, "Enter the name of the Domain senior to remove or press "
        "return to use yourself: ");
    input_to( (: remove_senior3( $1, $(str)) :) );

} /* remove_senior2() */

private void remove_senior3( string str, string domain ) {
    string err, old;

    if( !str || str == "")
        str = TP->query_name();

    if( !DOMAIN_H->query_senior( domain, str = lower_case(str) ) ) {
        tell_object( TP, RED+CAP(str)+" isn't a senior of "+CAP(domain)+".\n"+
            RESET );
        return do_prompt();
    }

    if( DOMAIN_H->query_leader( domain, str ) ) {
        tell_object( TP, RED+CAP(str)+" is a Leader of "+
            CAP(domain)+", use the remove leader option.\n"+RESET );
        return do_prompt();
    }

    old = geteuid(TO);
    seteuid(geteuid(TP));

    if( err = DOMAIN_H->remove_senior( domain, str ) ) {
        tell_object( TP, RED+"\n"+err+"\n"+RESET );
        seteuid(old);
        return do_prompt();
    }

    seteuid(old);

    log_file("PROMOTIONS", "%s - %s removed %s as a senior of %s.\n",
        ctime(time()), CAP(TP->query_name()), CAP(str),CAP(domain) );

    tell_object( TP, GREEN+"\nRemoved "+CAP(str)+" as senior of "+
        CAP(domain)+".\n\n"+RESET );

    do_prompt();

} /* remove_senior3() */

private void remove_member() {
    tell_object( TP, "Enter the name of the Domain to remove member from: ");
    input_to( (: remove_member2 :) );
} /* remove_member() */

private void remove_member2( string str ) {
    if( !str || str == "")
        return do_prompt();

    if( !DOMAIN_H->query_domain( str = lower_case(str) ) ) {
        tell_object( TP, RED+"The domain "+CAP(str)+" doesn't exist.\n"+
            RESET );
        return do_prompt();
    }

    if( !adminp(TP) && !DOMAIN_H->query_leader( str, TP->query_name() ) ) {
        tell_object( TP, RED+"\nYou are not authorised to do that.\n"+
            RESET );
        return do_prompt();
    }

    tell_object( TP, "Enter the name of the Domain member to remove or press "
        "return to use yourself: ");
    input_to( (: remove_member3( $1, $(str)) :) );

} /* remove_member2() */

private void remove_member3( string str, string domain ) {
    string err, old;

    if( !str || str == "")
        str = TP->query_name();

    if( DOMAIN_H->query_leader( domain, str = lower_case(str) ) ) {
        tell_object( TP, RED+CAP(str)+" is a Leader of "+CAP(domain)+", use "
            "the remove leader option first.\n"+RESET );
        return do_prompt();
    }

    if( !DOMAIN_H->query_member( domain, str ) ) {
        tell_object( TP, RED+CAP(str)+" isn't a member of "+
            CAP(domain)+".\n"+RESET );
        return do_prompt();
    }

    old = geteuid(TO);
    seteuid(geteuid(TP));

    if( err = DOMAIN_H->remove_member( domain, str ) ) {
        tell_object( TP, RED+"\n"+err+"\n"+RESET );
        seteuid(old);
        return do_prompt();
    }

    seteuid(old);

    tell_object( TP, GREEN+"\nRemoved " + CAP(str) + " as member of "+
        CAP(domain)+".\n\n"+RESET );

    do_prompt();

} /* remove_member3() */

private void get_command( string str ) {
    if( !str ) {
        display_menu();
        return do_prompt();
    }

    switch( str ) {
      case "1":
        create_domain();
      break;
      case "2":
        delete_domain();
      break;
      case "3":
        list_domains();
      break;
      case "4":
        add_leader();
      break;
      case "5":
        add_senior();
      break;
      case "6":
        add_member();
      break;
      case "7":
        remove_leader();
      break;
      case "8":
        remove_senior();
      break;
      case "9":
        remove_member();
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
    if( file_name(PO) == "/secure/cmds/creator/admtools")
        return_mapping[TP] = PO;

    display_menu();
    do_prompt();
    return 1;

} /* cmd() */
