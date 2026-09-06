// 2003-12-16 - commented out all the 'unknowns' junk, to be removed if no one complains
#include <titles.h>

#define NOLIFE	"/daemon/nolife"
#define IRCD	"/secure/sockets/ircd"

void wholist_dump() {
   call_out( "do_wholist_dump", 0 );
}

string level_string( object victim );

void do_wholist_dump() {
   object ob;
   string curr;
   string buf;

   buf="";
   foreach( ob: users() ) {
      if ( !ob->query_is_player() )
         continue;

      buf += "" + ob->query_invis() + "~~";

      curr = ob->query_pretitle();
      if( curr ) buf += curr + "~~"; else buf += "~~";

      curr = ob->query_cap_name();
      if( curr ) buf += curr + "~~"; else buf += "~~";

      curr = ob->query_title();
      if( curr ) buf += curr + "~~"; else buf += "~~";

      curr = ob->query_alignment_string();
      if( curr ) buf += curr + "~~"; else buf += "~~";

      curr = ob->query_level();
      if( curr ) buf += curr + "~~"; else buf += "~~";

      curr = trim(level_string(ob));
      if( curr ) buf += curr + "~~"; else buf += "~~";

      buf += query_idle( ob ) + "~~";
      buf += get_location( ob ) + "~~";
      buf += this_object()->status_string(ob)[5..] + "~~";
      buf += query_idle(ob) + "~~";
      curr = ob->query_afk(); if( !curr ) curr = "";
      buf += curr + "~";
      curr = ob->query_env_var("idlemsg"); if( !curr ) curr = "";
      buf += curr;
      buf += "\n";
   }
   rm( "/text/wholist.txt" );
   write_file( "/text/wholist.txt", buf );
}

string boink(string bonk) {
  if (bonk == "")
    return "";
  else
    return bonk+" ";
}

string level_string(object victim) {
  return pad("["+query_personal_title(victim)+"]",14,2)+" ";
}

string status_string(object victim) {
  int idle = query_idle(victim);
  string buf = "";
  if (victim->query_testchar())
    buf += "~[100[testchar] ";
  if (idle > 60*5)
    buf += "~[130[idle] ";
  if (victim->query_in_combat())
    buf += "~[110[fighting] ";
  if (victim->query_action() && victim->query_action()[1] == find_object("/bin/meditate") )
    buf += "~[120[meditating] ";
  if (victim->query_afk())
    buf += "~[070[afk] ";
  if (victim->query_dead())
    buf += "~[090[DEAD] ";
  if (victim->query_editing())
    buf += "~[060[editing] ";
  if (victim->query_mailing())
    buf += "~[060[mailing] ";
  if (victim->query_creating())
    buf += "~[140[NEW] ";
  }
/*
  else if (!this_player() || (this_player() != victim &&
      !this_player()->query_recognize(victim->query_name())))
    buf += "~[030[unknown] ";
*/
  if (victim->query_invis() == 1)
    buf += "~CDRK[invis] ";
  return buf;
}

// Function used for sorting list of players by name
int name_sort (object a, object b) {
  string astr = a->query_name();
  string bstr = b->query_name();
  if (!stringp(astr))
    astr = "";
  if (!stringp(bstr))
    bstr = "";
  return astr > bstr;
}

int case_insensitive_sort( string a, string b ) {
  return lower_case( a ) > lower_case( b );
}

void plain_wholist() {
   object ob;
   write("\nOnline Users:\n\n");
   foreach( ob : sort_array(users(), "name_sort")) {
      if (!ob->query_is_player() || ob->query_invis())
         continue;

      write(level_string(ob) +
            boink(ob->query_pretitle()) +
            boink(ob->query_cap_name()) +
            boink(ob->query_title()) +
            "("+ob->query_alignment_string() + ") " +
            status_string(ob)[4..] +
            "\n");
   }
   write("\n");
}

string wholine( object ob ) {
	if( !ob || !ob->query_is_player() )
		return "";
	return  level_string(ob) +
            boink(ob->query_pretitle()) +
            boink(ob->query_cap_name()) +
            boink(ob->query_title()) +
            "("+ob->query_alignment_string() + ") " +
            status_string(ob)[4..];
}

main(string str) {
  object plyrs;
  //int i, wiz = 0, unknown = 0, login = 0, invis = 0;
  int i, wiz = 0, login = 0, invis = 0, irc = 0;
  string buf, buf2;

  plyrs = sort_array(users(),"name_sort");

  msg("~CBRT"+pad("-----== PLAYERS ==-----",this_player()->query_term_width()-1,2));
  for (i = 0; i < sizeof(plyrs); i++) {
    if (plyrs[i]->query_level() >= WIZLEVEL)
      wiz++;
    if( plyrs[i]->query_invis() == 1) {
       invis++;
       if (this_player()->query_level() < WIZLEVEL)
          continue;
    }
    if (!plyrs[i]->query_is_player() ) {
        login++;
        continue;
    }
/*
    if (this_player()->query_recognize(plyrs[i]->query_name()) ||
        this_player()->query_level() >= WIZLEVEL ||
        this_player() == plyrs[i])
*/
      msg("~CTIT"+level_string(plyrs[i])+
               "~CDEF"+boink(plyrs[i]->query_pretitle())+
               "~CLAB"+plyrs[i]->query_cap_name()+
               " ~CDEF"+boink(plyrs[i]->query_title())+
               "~CLAB("+plyrs[i]->query_alignment_string()+") "+
               status_string(plyrs[i]), 16);
/*
    else {
      if (plyrs[i]->query_level() >= WIZLEVEL)
        msg("~CTIT"+level_string(plyrs[i])+
            "~CDEF"+boink(plyrs[i]->query_pretitle())+
            "~CLAB"+plyrs[i]->query_cap_name()+
            " ~CDEF"+boink(plyrs[i]->query_title())+
            "~[030(unknown)", 16);
      unknown++;
    }
*/

  }

  buf = "~CDEFPlayers: ~CREF"+(sizeof(plyrs)-wiz-login);
  if (wiz & this_player()->query_level() >= WIZLEVEL) {
    buf += "~CDEF, Wizards: ~CREF"+wiz;
  } else if ( (wiz-invis) ) {
    buf += "~CDEF, Wizards: ~CREF"+(wiz-invis);
  }
/*
  if (unknown) {
    buf += "~CDEF, Unknown: ~CREF"+unknown;
    i += 10;
  }
*/
  if (login) {
    buf += "~CDEF, Logging in: ~CREF"+login;
  }
  if( invis && this_player()->query_level() >= WIZLEVEL ) {
    buf += "~CDEF, Invis: ~CREF"+ invis;
  }
  if( irc ) {
    buf += "~CDEF, IRC: ~CREF"+irc;
  }
  buf = "~CBRT--== "+buf+" ~CBRT==--";

  msg("\n"+pad(buf+"~CDEF",this_player()->query_term_width()-1,2)[..<3]);

/** Wait for NoLife to get fixed first, ne? :)
 *
  buf = "~CDEFBiggest login today: ~CREF"+NOLIFE->query_biggest_login();
  buf += "~CDEF, Total players today: ~CREF"+NOLIFE->query_players_today();
  buf = "~CBRT--== "+buf+" ~CBRT==--";
  msg(pad(buf,this_player()->query_term_width()-1,2)[..<3]+"~CDEF");
*/

  return 1;
}
