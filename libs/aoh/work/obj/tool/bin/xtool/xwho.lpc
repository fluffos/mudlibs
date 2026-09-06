#include <secure/wizlevels.h>
#include <properties.h>
#include <secure/userinfo.h>
#include "../bincmd.h"

inherit BASICXCMD;

#ifndef MASTER
#define MASTER __MASTER_OBJECT__
#endif

QueryAbrev() { return "xwh"; }

string PlayerIdle(object obj) {
  string str;
  int i, tmp;
  
  if(!obj) return 0;
  if(!interactive(obj))
    str="<dsc>";
  else if((i=query_idle(obj))>=60) {
    str = sprintf( "%2.2'0's", ""+(i/3600) );
    i-=(i/3600)*3600;
    str+="'"+ sprintf( "%2.2'0's", ""+(i/60) );
  } else str=".....";
  return str;
}

string PlayerAge(object obj) {
  string str;
  int i, tmp;
  
  if(!obj) return 0;
  i=(int)obj->QueryAge();
  str=" "+sprintf("%3.3'.'s",""+(i/43200) );
  i-=(i/43200)*43200;
  return str+":"+sprintf("%2.2'0's", ""+(i/1800) );
}

string PlayerJobs(object obj, int flag) {
  string str;
  mixed *data, *userinfo;
  int i;
  
  if(!obj) return 0;
  str=(flag) ? sprintf( "%-12.12'.'s", capitalize(getuid(obj)))+" " : "";
#if defined(MUD_OSB)
  if (IS_WIZARD( this_player() ))
    str+=sprintf( "%2.2s",""+query_user_level(obj) )+" ("+(query_user_tag(obj, 1)||"Player")+")";
#else
  if (IS_WIZARD( this_player() ))
    str+=sprintf( "%2.2s",""+query_user_level(obj) )+" ("+(query_user_tag(obj, 1)||"Player")+")";
#endif
  else
    str+=query_user_tag(obj, 1)||"Player";
  userinfo=MASTER->find_userinfo(getuid(obj));
  data=userinfo && userinfo[3];
  if (sizeof(data)) {
    for (i=0; i < sizeof(data); i++) {
      str+=", ";
      switch (data[i][0]) {
        case '*': str+=(obj->QueryGender() < 2?"Lord":"Lady")+" of "+capitalize(data[i][1..]); break;
        case '+': str+="Vice of "+capitalize(data[i][1..]); break;
        default : str+="Member of "+capitalize(data[i]); break;
      }
    }
  }
  return str;
}

string PlayerWho(object obj) {
  object tmp;
  string str, stmp;

#if defined(MUD_OSB)
  if (IS_WIZARD( this_player()))
    str=sprintf("%-4.4s",""+query_user_level(obj));
  else
    str=sprintf("%-4.4s",query_user_level(obj) ? "Wiz" : "" );
#else
  if (IS_WIZARD( this_player()))
    str=sprintf("%-4.4s",""+query_user_level(obj));
  else
    str=sprintf("%-4.4s",query_user_level(obj) ? "Wiz" : "" );
#endif
  str+=sprintf("%-12.12'.'s",capitalize(getuid(obj)));
  str+=PlayerAge(obj);
  str+=((int)obj->QueryGender()==1 ? " m " : " f ");
  str+=(obj->QueryFrog())    ? "f" : ".";
  str+=(obj->QueryGhost())   ? "g" : ".";
  str+=(obj->QueryInvis())   ? "i" : ".";
  str+=(query_editing(obj)||query_input_pending(obj) ? "e" : ".");
  str+=" "+PlayerIdle(obj)+" ";
  str+=(tmp=environment(obj)) ? ObjFile(tmp) : "- fabric of space -";
  return str;
}

string PlayerMail(object obj, int flag) {
  string pre;
  
  pre=(flag) ? sprintf( "%-12.12'.'s",capitalize(getuid(obj)) )+" " : "";
  return pre+"mail: "+obj->QueryMailaddr();
}

string PlayerIP(object obj, int flag) {
  string pre;
  
  pre=(flag) ? sprintf( "%-12.12'.'s",capitalize(getuid(obj)) )+" " : "";
  return pre+"host: "+query_ip_name(obj)+" ("+query_ip_number(obj)+")";
}

string PlayerRace(object obj, int flag) {
  string tmp, pre;

  pre=(flag) ? sprintf( "%-12.12'.'s",capitalize(getuid(obj)) )+" " : "";
  
#if defined(MUD_OSB)
  if ( IS_WIZARD( obj ) )
    pre=pre+"level: "+sprintf("%3.3s","w"+query_user_level(obj))+" ";
#else
  if ( IS_IMMORTAL( obj ) )
    pre=pre+"level: "+sprintf("%3.3s","w"+query_user_level(obj))+" ";
#endif
  else
    pre=pre+"level: "+sprintf("%3.3s",to_string(obj->QueryLevel()))+" ";

  pre=pre+"race: "+sprintf("%15.15'.'s", obj->QueryRace())+ " guild: ";
  tmp=(string)obj->QueryGuild();
  return tmp ? pre+tmp : pre+"- none -";
}

string PlayerDomain(object obj, int flag) {
  int i, s;
  mixed *uinfo;
  string *domains, pre, title;

  pre=(flag) ? sprintf( "%-12.12'.'s",capitalize(getuid(obj)) )+" " : "";
  pre+="domain: ";
  title=(int)obj->Query(P_GENDER)==1?"Lord":"Lady";
  uinfo=(mixed*)MASTER->find_userinfo(getuid(obj));
  if(uinfo&&(domains=uinfo[USER_DOMAIN])&&(s=sizeof(domains))) {
    for(i=0; i<s; i++) {
      switch(domains[i][0]) {
      case '*':
	pre=pre+title+" of "+capitalize(domains[i][1..]);
	break;
      case '+':
	pre=pre+"Vice "+title+" of "+capitalize(domains[i][1..]);
	break;
      default:
	pre+=capitalize(domains[i]);
	break;
      }
      if(i<s-1) pre+=", ";
    }
  }
  return pre;
}

string PlayerStats(object obj, int flag) {
  string pre;
  
  pre= (flag)? sprintf( "%-12.12'.'s", capitalize(getuid(obj)) )+" " : "";
  pre+="hp="+sprintf("%3.3'0's", ""+obj->QueryHP() );
  pre+="/"+sprintf("%3.3'0's", ""+obj->QueryMaxHP() );
  pre+=" sp="+sprintf("%3.3'0's", ""+obj->QuerySP() );
  pre+="/"+sprintf("%3.3'0's", ""+obj->QueryMaxSP() );
  pre+=" food="+sprintf("%3.3'0's", ""+obj->QueryFood() );
  pre+="/"+sprintf("%3.3'0's", ""+obj->QueryMaxFood() );
  pre+=" drink="+sprintf("%3.3'0's", ""+obj->QueryDrink() );
  pre+="/"+sprintf("%3.3'0's", ""+obj->QueryMaxDrink() );
  pre+=" exps="+obj->QueryXP();
  return pre;
}

string PlayerTTY( object obj, int flag ) {
  string pre;

  pre = (flag)? sprintf( "%-12.12'.'s", capitalize(getuid(obj)) )+" " : "";
  pre += obj->Query( P_TTY );

  return pre;
}

string PlayerSnoop(object obj, int flag) {
  string tmp, pre;
  object victim;
  
  pre=(flag) ? sprintf( "%-12.12'.'s",capitalize(getuid(obj)) )+" " : "";
  pre=pre+"is snooped by: ";
  if(victim=query_snoop(obj))
    pre+=sprintf( "%12.12'.'s",capitalize(getuid(victim)) );
  else
    pre+="............";
  return pre;
}

int main(string opt ) {
   string *strs, plname;
   object obj;
   
   notify_fail("xwh(o) [mail|ip|race|guild|domain|job|stats|snoop|level|tty|about <name>\n"), 0;
   if ( opt == "?" )
     return 0;

   if ( opt && ( sscanf( opt, "about %s", plname ) == 1 ) ) 
      opt = "about";
   
   if(!opt) strs=map(users(), SF(PlayerWho), this_object());
   else switch(opt) {
    case "mail":
      strs=map(users(), SF(PlayerMail), this_object(), 1);
      break;
    case "ip":
      strs=map(users(), SF(PlayerIP), this_object(), 1);
      break;
    case "level":
    case "race":
    case "guild":
      strs=map(users(), SF(PlayerRace), this_object(), 1);
      break;
    case "job":
    case "jobs":
      strs=map(users(), SF(PlayerJobs), this_object(), 1);
      break;
    case "domain":
      strs=map(users(), SF(PlayerDomain), this_object(), 1);
      break;
    case "stat":
    case "stats":
      strs=map(users(), SF(PlayerStats), this_object(), 1);
      break;
    case "snoop":
      strs=map(users(), SF(PlayerSnoop), this_object(), 1);
      break;
   case "tty":
     strs=map(users(), SF(PlayerTTY), this_object(), 1 );
     break;
    case "about":
      if ( ! plname ) return 0;
      if ( obj = XFindObj( plname ) ) {
	 if ( ! query_once_interactive( obj ) )
	   tell_object( cloner, "Sorry, this is not a player.\n" );
	 else {
	    tell_object( cloner, PlayerWho( obj )+"\n" );
	    tell_object( cloner, PlayerMail( obj,0 )+"\n" );
	    tell_object( cloner, PlayerIP( obj,0 )+"\n" );
	    tell_object( cloner, PlayerRace( obj,0 )+"\n" );
	    tell_object( cloner, PlayerDomain( obj,0 )+"\n" );
	    tell_object( cloner, PlayerStats( obj,0 )+"\n" );
	    tell_object( cloner, PlayerSnoop( obj,0 )+"\n" );
	    tell_object( cloner, PlayerTTY( obj, 0 )+"\n" );
	 }
      }
      return 1; /* this function is a bit different... */
    default:
      return 0;
   }
   strs=sort_array(strs, symbol_function("string_compare", "/lib/string" ), this_object() );
   
   tell_object( cloner, implode(strs,"\n") + "\n" );
   return 1;
}
