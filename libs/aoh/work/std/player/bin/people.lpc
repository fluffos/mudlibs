/*--------------------------------------------------------------------------
 * /std/player/bin/people.c  --  The wizard's people command.
 *
 * Copyright (C) 1997 by One Step Beyond.
 * All Rights Reserved.
 * Permission granted for non-commercial use.
 *--------------------------------------------------------------------------
 */

#include <ansi.h>
#include <properties.h>

#define MAXIDLE 300
#undef PEOPLE_ANSI

public varargs string prettyfile(string str,status short)
  // Used by cmd_people and parse_prompt
  // When 'short' is given only the current dir is returned
{
  string res,name;
  if (!str) return 0;
  if (str[0..2] == DPATH) res = "+"+str[3..<1];
  else if (str[0..2] == PPATH) res = "&"+str[3..<1];
  else if (str[0..8] == WPATH)
    {
      res = "~"+str[9..<1];
      name = getuid();
      if (res[1..sizeof(name)]==name)
	res = "~"+res[sizeof(name)+1..];
    }
  else res = str;
  if (short)
    res = explode(res,"/")[<1];
  
  return res;
}

private int people_sort( object a, object b ) {
  return ( ( ({string})a->Query(P_REALNAME)||"" ) > ( ({string})b->Query(P_REALNAME)||"" ) );
}

public int main( string arg ) {
  object *list;
  int i, a, short;
  string nm;

  if ( arg && ( arg == "long" ) )
    short = 0;
  else
    short = 1;

#ifdef PEOPLE_ANSI
  string a_age,a_ipnum,a_name,a_level,a_idle,a_room,a_end, a_title,res;

  switch ( ({string})this_player()->Query(P_TTY) ) {
  case "vt100":
    a_ipnum = ""; a_name = ANSI_BOLD; a_level = ANSI_NORMAL;
    a_idle = ANSI_BLINK; a_room = ANSI_NORMAL; a_end = ANSI_NORMAL;
    a_title = ANSI_INVERS; a_age = ANSI_NORMAL;
    break;
  case "ansi":
    a_ipnum = ANSI_GREEN; a_name = ANSI_YELLOW; a_level = ANSI_RED;
    a_idle = ANSI_WHITE; a_room = ANSI_CYAN; a_end = ANSI_NORMAL;
    a_title = ANSI_INVERS; a_age = ANSI_PURPLE;
    break;
  default:
    a_title = a_ipnum = a_name = a_level = a_idle = a_room = a_end = "";
    a_age = "";
  }
#endif  

  list = sort_array( users(), #'people_sort /*'*/ );
  
  for (i=0, a=0; i < sizeof(list); i++)
    if (query_idle(list[i]) >= MAXIDLE ) a++;
  
  nm = sprintf(
#ifdef PEOPLE_ANSI
                a_title+
#endif
                "There are now %d players (%d idle). %s"
#ifdef PEOPLE_ANSI
                +a_end
#endif
                ,
	        sizeof(list),a,query_load_average());
  
  nm = sprintf( "%|78s\n%78'-'s\n",nm,"" );

  for (i=0; i<sizeof(list); i++) {
    string tag, name, age, room;
    
    name = capitalize(({string})list[i]->Query(P_REALNAME) || 
		      ({string})list[i]->Query(P_NAME) || "<logon>");
    if (({int})list[i]->Query(P_INVIS) || !({string})list[i]->Query(P_SHORT)) 
      name = "(" + name + ")";

    if ( ! ( a = query_user_level(list[i]) ) )
      tag = ({int})list[i]->Query(P_LEVEL)+"/"+({int})list[i]->Query(P_REAL_LEVEL);
    else
      tag = query_user_tag(this_object());

    a = ({int})list[i]->QueryAge();
    if      (a / 43200 > 9) age = a / 43200 + "D";
    else if (a / 43200 > 0) age = a / 43200 + "D";
    else if (a /  1800 > 9) age = a / 1800 + "h";
    else if (a /  1800 > 0) age = a / 1800 + "h";
    else if (a /    30 > 9) age = a / 30 + "m";
    else                    age = a / 30 + "m";

    if (environment(list[i]))
      room = prettyfile(object_name(environment(list[i])));
    else
      room = "<no environment>";

    if ( short && ( sizeof( room ) > 33 ) )
      room = "..."+room[(sizeof(room)-33)..];

#ifdef PEOPLE_ANSI
    nm += sprintf( a_ipnum+"%-15s "+a_name+"%-15s "+a_level+"%-5s "+a_age+"%-5s"+a_idle+"%c "+a_room+"%s"+a_end+"\n",
#else
    nm += sprintf( "%-15s %-12s %-5s %4s %c %s\n",
#endif
		   query_ip_number(list[i]),
		   name,
		   tag,
		   age,
		   ( (query_idle(list[i]) > MAXIDLE ) ? 'I' : ' ' ),
		   room );

  }

  nm += sprintf( "%78'-'s\n", "" );

  "/lib/string"->smore( nm, ({int})this_player()->Query(P_PAGESIZE) );
  return 1;
}
