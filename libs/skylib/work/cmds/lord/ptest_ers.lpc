/**
 * This is the ptesters command, to make dealing with all sorts
 * of PT stuff easier.  Such as adding/removing playtesters,
 * seniors and transit routes.
 * @author Sandoz
 */

#define LIST       1
#define ADD_TESTER 2
#define ADD_SENIOR 3
#define REM_TESTER 4
#define REM_SENIOR 5
#define ADD_ROUTE  6
#define REM_ROUTE  7
#define LIST_ROUTE 8
#define BADGE      9
#define LIST_APPS  10
#define SHOW_APP   11
#define ACCEPT_APP 12
#define REJECT_APP 13

inherit COMMAND_BASE;

/** @ignore yes */
private varargs int cmd( int action, string name, string reason ) {
    string str;

    switch( action ) {
      case LIST :
        str = PLAYTESTERS_H->query_show_list();
        TP->more_string( str, "Playtester");
        return 1;
      case ADD_TESTER :
        str = PLAYTESTERS_H->reason_invalid_playtester( lower_case(name) );
        if( str ) {
            add_failed_mess( CAP(name)+" cannot be made a playtester, "
                "because: "+str+".\n");
            return 0;
        }
        return PLAYTESTERS_H->add_playtester( lower_case(name) );
      case ADD_SENIOR :
        return PLAYTESTERS_H->add_senior_playtester( lower_case(name) );
      case REM_TESTER :
        if( !reason || reason == "" ) {
            add_failed_mess("You need to specify a reason when demoting "
                "someone.\n");
            return 0;
        }
        return PLAYTESTERS_H->remove_playtester( lower_case(name), reason );
      case REM_SENIOR :
        if( !reason || reason == "" ) {
            add_failed_mess("You need to supply a reason when demoting "
                "someone.\n");
            return 0;
        }
        return PLAYTESTERS_H->remove_senior_playtester( lower_case(name),
            reason );
      case ADD_ROUTE :
        return PLAYTESTERS_H->add_route( name, reason );
      case REM_ROUTE :
        return PLAYTESTERS_H->remove_route( name, reason );
      case LIST_ROUTE :
        return PLAYTESTERS_H->list_routes();
      case BADGE :
        return PLAYTESTERS_H->create_badge( name );
      case LIST_APPS :
        return PLAYTESTERS_H->do_list_apps();
      case SHOW_APP :
        return PLAYTESTERS_H->do_show_app( name );
      case ACCEPT_APP :
        return PLAYTESTERS_H->do_accept_app( name );
      case REJECT_APP :
        return PLAYTESTERS_H->do_reject_app( name );
      default:
        return TP->syntax_messages("ptesters");
    }

} /* cmd() */

/** @ignore yes */
mixed query_patterns() {
    return ({
        "list", (: cmd(LIST) :),
        "add <word'name'>", (: cmd( ADD_TESTER, $4[0] ) :),
        "add senior <word'name'>", (: cmd( ADD_SENIOR, $4[0] ) :),
        "remove <word'name'> <string'reason'>",
        (: cmd( REM_TESTER, $4[0], $4[1] ) :),
        "remove senior <word'name'> <string'reason'>",
        (: cmd( REM_SENIOR, $4[0], $4[1] ) :),
        "add route from <word'start'> to <word'destination'>",
        (: cmd( ADD_ROUTE, $4[0], $4[1] ) :),
        "remove route from <word'start'> to <word'destination'>",
        (: cmd( REM_ROUTE, $4[0], $4[1] ) :),
        "list routes", (: cmd( LIST_ROUTE ) :),
        "create badge for <word'player'>", (: cmd( BADGE, $4[0] ) :),
        "list applications", (: cmd( LIST_APPS ) :),
        "show <word'name'> application", (: cmd( SHOW_APP, $4[0] ) :),
        "accept <word'name'> application", (: cmd( ACCEPT_APP, $4[0] ) :),
        "reject <word'name'> application", (: cmd( REJECT_APP, $4[0] ) :),
        });
} /* query_patterns() */
