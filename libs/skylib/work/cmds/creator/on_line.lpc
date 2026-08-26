/*  -*- LPC -*-  */

/*   Online   *
 *   Gototh   *
 *  08/12/97  */

inherit COMMAND_BASE;

string idle_time(object person) {
  int hours, mins, secs;
  string s, m, h;

  secs = query_idle(person);
  mins = secs / 60;
  secs %= 60;
  hours = mins / 60;
  mins %= 60;
  s = ("0"+secs)[<2..<1];
  m = ("0"+mins)[<2..<1];
  if ( !hours )  {
    return " (idle: "+m+":"+s+")";
  }
  h = ("0"+hours)[<2..<1];
  return " (idle: "+h+":"+m+":"+s+")";
} /* idle_time() */

mixed cmd() {
  object *people, person;
  string *cre, *invis, *lord, *high, bing;

  cre = ({ });
  invis = ({ });
  lord = ({ });
  high = ({ });

  people = filter_array( users(), (: creatorp($1) :) );
  people = people - this_player()->query_ignoring( people );
  people = sort_array( people,
    (: strcmp( $1->query_name(), $2->query_name() ) :) );

  foreach( person in people )  {
    bing = person->query_cap_name();
    if ( query_idle( person ) > 120 )  {
      bing += idle_time( person );
    }
    switch( person->query_invis()  )  {
      case 0:
        cre += ({ bing });
        break;
      case 1:
        invis += ({ bing });
        break;
      case 2:
        lord += ({bing});
        break;
      default:
        high += ({bing});
        break;
    }
  }

  if(sizeof(cre)) {
    tell_object(this_player(), 
      "/global/player/events"->convert_message("$I$2=%^GREEN%^"
      "Visible%^RESET%^: "+query_multiple_short(cre)+".\n"));
  }
  if(sizeof(invis)) {
    tell_object(this_player(), 
      "/global/player/events"->convert_message("$I$2=%^CYAN%^"
      "Invisible%^RESET%^: "+query_multiple_short(invis)+".\n"));
  }
  if(sizeof(lord)) {
    tell_object(this_player(), 
      "/global/player/events"->convert_message("$I$2=%^YELLOW%^Lord "
      "Invisible%^RESET%^: "+query_multiple_short(lord)+".\n"));
  }
  if(sizeof(high)) {
    tell_object(this_player(), 
      "/global/player/events"->convert_message("$I$2=%^RED%^ADMIN "
      "Invisible%^RESET%^: "+query_multiple_short(high)+".\n"));
  }
  return 1;
} /* cmd() */
