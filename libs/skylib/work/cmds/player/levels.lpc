
#include <rank.h>

inherit COMMAND_BASE;

int cmd() {
    object *users, user;
    string ret;
    string *players = ({ });
    string *creators = ({ });
    string *pleaders = ({ });
    string *lords = ({ });
    string *seniors = ({ });
    string *apps = ({ });
    string *admins = ({ });

    users = filter( users(), (: $1 && base_name($1) != LOGIN_OBJ &&
                                reference_allowed( $1, $(TP) ) :) );

    foreach( user in users ) {
        switch( rank(user) ) {
          case ADMIN:
            admins += ({ user->query_cap_name() });
          break;
          case LORD:
            lords += ({ user->query_cap_name() });
          break;
          case SENIOR:
            seniors += ({ user->query_cap_name() });
          break;
          case CREATOR:
            if( PROJECT_H->query_leader( user->query_name() ) ) {
                pleaders += ({ user->query_cap_name() });
                break;
            }
            creators += ({ user->query_cap_name() });
          break;
          case APPRENTICE:
            apps += ({ user->query_cap_name() });
          break;
          default:
            players += ({ user->query_cap_name() });
        }
    }

    ret = "%^BOLD%^"+mud_name()+" - "+ctime(time())+" %^RESET%^\n\n";
    if( sizeof(admins) ) {
        ret += "%^BLUE%^Admin ("+sizeof(admins)+"):%^RESET%^\n";
        ret += query_multiple_short( admins )+".\n\n";
    }
    if( sizeof(lords) ) {
        ret += "%^ORANGE%^Lords ("+sizeof(lords)+"):%^RESET%^\n";
        ret += query_multiple_short( lords )+".\n\n";
    }
    if( sizeof(seniors) ) {
        ret += "%^RED%^Senior Creators ("+sizeof(seniors)+"):%^RESET%^\n";
        ret += query_multiple_short( seniors )+".\n\n";
    }
    if( sizeof(pleaders) ) {
        ret += "%^GREEN%^Project Leaders ("+sizeof(pleaders)+"):%^RESET%^\n";
        ret += query_multiple_short( pleaders )+".\n\n";
    }
    if( sizeof(creators) ) {
        ret += "%^CYAN%^Creators ("+sizeof(creators)+"):%^RESET%^\n";
        ret += query_multiple_short( creators )+".\n\n";
    }
    if( sizeof(apps) ) {
        ret += "%^CYAN%^Apprentice Creators ("+sizeof(apps)+"):%^RESET%^\n";
        ret += query_multiple_short( apps )+".\n\n";
    }
    if( sizeof(players) ) {
        ret += "%^WHITE%^Players ("+sizeof(players)+"):%^RESET%^\n";
        ret += query_multiple_short( players )+".\n\n" ;
    }

    tell_object( TP, ret );
    return 1;

} /* cmd() */
