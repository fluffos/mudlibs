// Killers command by Ceres

#include <clubs.h>

inherit COMMAND_BASE;

string second_name( string str );

/** @ignore yes */
mixed cmd( string mode ) {
   object *killers;
   object player = this_player();
   string *names, *tmp, name;
   int i, brief, number;
   mixed *unique_names;

   if ( mode == "verbose" ) brief = 0;
   else brief = 1;


   // OK, OK.  This is awful, but it looks so cool...  :)    --Presto
   killers = filter_array( users(),
                         (: !(creatorp($1))  &&
                            !($1->query_login_ob())  &&
                            !($1->query_property("test character")) &&
                            $1->query_property("player_killer") :) );
   if (brief) {
      names = killers->query_cap_name();
   } else {
      names = killers->short();
   }

   if (!sizeof(names)) {
      write("There are no player killers logged in.\n");
   } else {
      if(sizeof(names) == 1)  {
         if ( names[0] == (brief? player->query_cap_name(): player->short()) ) {
            write( "You are the only player killer on "+ mud_name() +".\n");
         } else {
            write("The only player killer currently logged in is "+
                   names[0]+".\n");
         }
      } else {
         i = 0;
         if ( member_array(
              (brief? player->query_cap_name(): player->short()),
              names ) > -1 )  {
            names -= ({ (brief? player->query_cap_name(): player->short()) });
            i = 1;
         }
         names = sort_array( names,
                             (: strcmp( lower_case( $1 ),
                                        lower_case( $2 ) ) :) );
         if ( i ) {
             name = this_player()->query_cap_name();
             if (this_player()->query_family_name() &&
                 !brief) {
                name += " " + this_player()->query_family_name();
             }
             names += ({ name });
         }

         // This is a fairly silly thing, but quite cool, in its own little way :)
         if (!brief) {
           unique_names = unique_array( names, (: second_name($1) :) );
           names = ({ });
           foreach ( tmp in unique_names ) {
                names += tmp;
           }
         }

         number = sizeof(names);
         write("There are " + sizeof(names) + " player killers logged in:\n" +
               sprintf("%-#*s", player->query_cols(),
                      implode( names, "\n" ) ) + "\n");
      }
   }
   return 1;
} /* cmd() */

int cmd_here() {
   string *killers;

   killers = filter_array( all_inventory(environment(this_player())),
                         (: !(creatorp($1))  &&
                            !($1->query_property("test character")) &&
                            $1->query_property("player_killer") &&
                            $1->query_visible( this_player() ) &&
                            $1 != this_player() :) );
   if (!sizeof(killers)) {
      add_failed_mess("There are no killers here.\n");
      return 0;
   }
   if (sizeof(killers) > 1) {
      write("The killers here are " +
            query_multiple_short(killers) + ".\n");
   } else {
      write("The killer here is " +
            query_multiple_short(killers) + ".\n");
   }
   return 1;
} /* cmd_here() */

/** @ignore yes */
string second_name( string str ) {
  int pos;

  pos = strsrch( str, " " );
  if (pos == -1) {
     return "";
  }
  return str[pos+1..];
} /* second_name */

/** @ignore yes */
int cmd_club( string club ) {
    int number;
    string *names;

    if( CLUB_HANDLER->query_club_secret( club ) &&
        !CLUB_HANDLER->is_member_of( club, this_player()->query_name() ) ) {
        add_failed_mess( "That is a secret club! Killers information about "
            "secret clubs is only shown to club members.\n" );
        return -1;
    }
    names = map( filter( CLUB_HANDLER->query_members( club ),
       (: find_player( $1 ) && !creatorp( $1 ) &&
        pk_check( $1, this_player(), 1 ) != 1 :) ),
        (: capitalize( $1 ) :) );


    if ( number = sizeof( names ) ) {
        if ( number > 1 ) {
            write("There are " + number + " player killers logged on "
                "who are members of " + capitalize( club ) + ":\n" +
                sprintf("%-#*s", this_player()->query_cols(), implode( names,
                "\n" ) ) + "\n");
        }
        else {
            write("There is " + number + " player killer logged on "
                "who is a member of " + capitalize( club ) + ":\n" +
                sprintf("%-#*s", this_player()->query_cols(), implode( names,
                "\n" ) ) + "\n");
        }
    }
    else {
        add_failed_mess( "There are no player killers in that club.\n" );
        return -1;
    }

     return 1;
}

/** @ignore yes */
mixed *query_patterns() {
  return ({ "", (: cmd(0) :),
            "{verbose|brief}", (: cmd( $4[0] ) :),
            "here", (: cmd_here() :),
           "club <string'club name'>", (: cmd_club( $4[0] ) :) });
} /* query_patterns */
