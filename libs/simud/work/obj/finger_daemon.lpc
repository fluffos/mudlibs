#include <const.h>
#include <titles.h>
#include <time.h>

/** An object used to generate descriptions for the finger verb.
 * This object is useful because root access is needed to read player
 * data, and the finger verb doesn't have root access (we don't want to
 * give it root access either, as there are some security issues).
 */

/// Dummy variable for reading in data from the player's file.
string email, hide_email, name, pretitle, title, job_title, *alignment, last_ip;
mapping vars, env_vars;
/// Dummy variable for reading in data from the player's file.
int last_login, last_logout, age, level, gender, warnings, deaths;
/// Another dummy variable for reading data from the player's mailbox.
int *flags;

/// \return " [testchar]" if the object \a who is a wizard test character, "" otherwise.
string typestr(object who) {
  if( !who ) {
    return (vars["type"]?" [testchar]":"");
  }
  if (who->query_testchar())
    return " [testchar]";
  else
    return "";
}

/// Converts a numeric (0,1,2) gender into a string one (M,F,N)
string genderchar(int x) {
  switch (x) {
    case 1:  return "M";
    case 2:  return "F";
    default: return "N";
  }
  return "N"; // for annoying warning
}

/// returns the string (possibly empty) for how many warnings
string warningstr(int warnings) {
  if (warnings == 0)
    return "";
  else if (warnings == 1)
    return " (" + warnings + " warning)";
  else
    return " (" + warnings + " warnings)";
}

string box_string(string str, int width) {
  string buf = "";
  string *lines = ({});
  int x;

  while (sizeof(str) > width - 15) {
    int cut = width - 15;
      for (x = width - 15; x > 1; x--) {
        if (str[x] == ' ') {
        cut = x;
        break;
      }
    }
    lines += ({ "       ~[070"+str[..cut] });
    str = str[cut+1..];
  }

  lines += ({ "       ~[070"+str });

  for (x = 0; x < sizeof(lines); x++)
    buf += "~[060| ~CDEF"+pad(lines[x],width,0)+"~[060|\n";

  return buf;
}

/** Does a complete 'finger' command for \a fname, which should be a player's name.
 * If \a fname is logged in, then they will be forced to save first.
 */
int finger_player(string fname) {
  object who;
  int x,width,on_line=0;
  int *mbox, mail, im;
  string buf;

  if (!fname || !legal_filename(fname)) {
    notify_fail("Whom do you want to finger?\n");
    return 0;
  }

  if (who = find_player(fname)) {
    who->save_self();
    on_line = 1;
  }

  /** Grab email header before doing anything else, this avoids a conflict
   * of variable names with the player object itself.
   */
  restore_object("/mail/"+fname);
  mbox = copy(flags);

  // Default all values to unset.
  email = name = last_login = last_logout = age = level = pretitle = title = job_title = gender = deaths = last_ip = 0;

  if (!restore_object(PLAYER_DIR+fname)) {
    write(capitalize(fname)+" does not exist.\n");
    return 1;
  }

  width = this_player()->query_term_width() - 1;
  if (pretitle == 0) pretitle = "";
  if (title == 0) title = "";
  if (job_title == 0) job_title = "none";
  if (email == 0) email = "unspecified";

  buf = "~[060/"+tab("-",width-4)+"\\\n";

  buf += "~[060| " + pad("~[080" + pretitle+" ~[150"+capitalize(name)+" ~[080"+title,width-7,2)+"~[070"+genderchar(gender)+" ~[060|\n";
  buf += "~[060|"+tab(" ",width-4)+"|\n";
  if (this_player()->query_level() >= WIZLEVEL)
    buf += "~[060| ~[080"+pad("Level: ~[070"+query_personal_title(who,name,level,job_title)+" ("+(string)level+")"+typestr(who)+" ("+"/obj/living"->query_alignment_string(alignment)+")" + warningstr(warnings),width-5,0)+"~[060|\n";
  else
    buf += "~[060| ~[080"+pad("Level: ~[070"+query_personal_title(who,name,level,job_title)+typestr(who)+" ("+"/obj/living"->query_alignment_string(alignment)+")",width-5,0)+"~[060|\n";

  if (!hide_email || this_player()->query_level() >= WIZLEVEL)
    buf += "~[060| ~[080"+pad("Email: ~[070"+email+(hide_email?" [hidden]":""),width-5,0)+"~[060|\n";

  if (on_line) {
    if( age != 0 )
       buf += "~[060| ~[080"+pad("Age:   ~[070"+int_to_time(age+time()-last_login),width-5,0)+"~[060|\n";
    if (query_idle(who) >= 10)
       buf += "~[060| ~[080"+pad("Idle:  ~[070"+int_to_time(query_idle(who)),width-5,0)+"~[060|\n";
    if (who->query_afk())
       buf += "~[060| ~[150"+"AFK~[080:   ~[070"+box_string(who->query_afk(),width-5)[24..];
    else if (query_idle(who) && who->query_env_var("idlemsg"))
       buf += box_string(who->query_env_var("idlemsg"),width-5);
    buf += "~[060| ~[080"+pad("On for: ~[070"+int_to_time(time()-last_login),width-5,0)+"~[060|\n";
    if (this_player()->query_level() >= WIZLEVEL)
      buf += "~[060| ~[080"+pad("Connected from: ~[070"+query_ip_name(who)+" ("+query_ip_number(who)+")",width-5,0)+"~[060|\n";
  } else {
    buf += "~[060| ~[080"+pad("Age:   ~[070"+int_to_time(age),width-5,0)+"~[060|\n";
    buf += "~[060| ~[080"+pad("Logged out: ~[070"+int_to_time(time()-last_logout)+" ago",width-5,0)+"~[060|\n";
    if (this_player()->query_level() >= WIZLEVEL)
      buf += "~[060| ~[080"+pad("Last connected from: ~[070"+last_ip,width-5,0)+"~[060|\n";
    if ( pointerp(env_vars["cryo_days"]) && member(env_vars["cryo_days"], localtime(time())[TM_WDAY]) != -1 )
      buf += "~[060| ~[060"+pad("Currently locked in cryo-stasis.",width-5,0)+"~[060|\n";
  }

  buf += "~[060| ~[080"+pad("Deaths: ~[070"+deaths,width-5,0)+"~[060|\n";

  // Check their mailbox
  if( pointerp(mbox) )
  for (x = 0; x < sizeof(mbox); x++) {
     if (mbox[x] & 0x01)  // READ_FLAG
        continue;
     if (mbox[x] & 0x02)  // IM_FLAG
        im++;
     else
        mail++;
  }
  if (im || mail)
     buf += "~[060| ~[080"+pad("Unread: ~[070"+(mail>0?(string)mail+" mudmail":"")+(mail>1?"s":"")+(im&&mail?" and ":"")+(im>0?(string)im+" instant message":"")+(im>1?"s":""),width-5,0)+"~[060|\n";

  buf += "~[060\\"+tab("-",width-4)+"/\n~CDEF";

  if( file_exists("/home/"+name+"/.plan") )
     buf += read_file( "/home/"+name+"/.plan" ) + "~CDEF";
  else if( file_exists("/players/"+name+".plan") )
     buf += read_file( "/players/"+name+".plan" ) + "~CDEF";

  msg(buf);
  return 1;
}
