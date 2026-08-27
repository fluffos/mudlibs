/* Events.c
 * Changed a bit, added Begosh new channel system..
 * And some more basic stuff.. 
 * Baldrick, may '94.
 */
// Added block command - Radix 1996

inherit "/global/play_parse_com";
inherit "/global/communicate";
#include "player.h"
#include "term.h"

int earmuffs, cols, rows;
nosave mapping colour_map;
nosave string block;

string term_name = "ansi";
nosave string new_line = "";
nosave string away;

nosave string *past;
nosave string *gritos;

void create() {
    languages = ({ "comun" });
    cur_lang = "comun";
	past = gritos = ({ });
	away = 0;
    ::create();
} /* create() */

int set_away(string str)
{
	if (!str) {
		away = 0;
		tell_object(TP, "Mensaje de away borrado.\n");
	}
	else {
		away = "%^BOLD%^RED%^"+str+"%^RESET%^";
		tell_object(TP, "Mensaje de away activado.\n");
	}
	return 1;
}

string query_away()
{
	return away;
}

// tengo que hacer fns para cada uno argh!
void add_past(string msg) {
	if (sizeof(past) > 19)
		past = past[1..];
	past += ({ msg });
}

void add_grito(string msg) {
	if (sizeof(gritos) > 19)
		gritos = gritos[1..];
	gritos += ({ msg });
}

string get_past() {
//	int i, x;
//	string msg = "";
	if (!sizeof(past))
		return "No te han dicho nada.\n";
//	for (x=0;x < i;i++) {
//		msg += (x+1)+": "+past[x];
//	}
//	return msg;
	return implode(past, "\n") + "\n";
}

string get_gritos() {
	if (!sizeof(gritos))
		return "No has oido ningun grito.\n";
	return implode(gritos, "\n") + "\n";
}

int do_past(string str)
{
	if (str == "gritos") {
		tell_object(TP, "----- Past de Gritos -----\n\n"+get_gritos()+"\n--------------------------\n");
		return 1;
	}
	tell_object(TP, "---------- Past ----------\n\n"+get_past()+"\n--------------------------\n");
	return 1;
}

string query_term_name() { return term_name; }
int query_earmuffs() { return earmuffs; }
string query_blocking() { return block; }

int query_see_magic()
{
    string guild;

    if(!(guild = (string)this_object()->query_guild_ob())) return 0;
    return (int)guild->query_see_magic();
} /* query_see_octarine() */

string read_message(string str, string type, string lang) {
    mixed bing;

    if (member_array(lang, languages) == -1)
	if ((bing = (mixed)LANGUAGE_HAND->query_garble_object(lang)))
	    if ((bing = (mixed)bing->garble_text(str, previous_object())))
		return "No comprendes los signos "+bing+
		(type?" escritos en "+type:"")+"\n";
	    else
		return "Jurarias que aqui habia algo escrito...\n"; /* Invisible text... */
	else
	    return "No comprendes los signos "+(type?" escritos en "+type:"")+"\n";
    if (LANGUAGE_HAND->query_language_magic(lang))
	if ((bing = (mixed)LANGUAGE_HAND->query_garble_object(lang)))
	    return (string)bing->magical_text(str, previous_object());
	else {
	    return "El mud se tambalea cuando encuentra una escritura magica que puedes leer "+
	    "pero que no encuentra su interprete.\n";
	}
    if (!type)
	return str+"\n";
    return "'"+str+"' escrito en "+type+"\n";
} /* read_message() */

varargs string fix_string(string ret,int n) 
{
    string *st;
    int i;
    
    if(!n) n=0;

    if (!colour_map)
	colour_map = (mapping)TERM_HANDLER->set_term_type(term_name);
    if (!stringp(ret) || ret == "")
	return ret;
    st = explode(ret, "%^");
    ret = "";
    for (i=0;i<sizeof(st);i++) {
	if(st[i][0..8] == "OCTARINE:")
	    if(query_see_magic()) st[i] = extract(st[i], 9);
	    else continue;
	if (colour_map[st[i]])
	    ret += colour_map[st[i]];
	else
	    ret += st[i];
    }
    return ret+colour_map["RESET"];
} /* fix_string() */

int set_term_type(string str)
{
    if (!str) {
	notify_fail(sprintf("%-=*s", cols,
	    "Sintaxis: "+query_verb()+" <tipo_de_terminal>\n"+
	    "Donde tipo de terminal es uno de los siguientes: "+
	    implode((string *)TERM_HANDLER->query_term_types(), ", ")+
	    ".\n"));
	return 0;
    }
    if(str != term_name) {
	if(member_array(str, (string *)TERM_HANDLER->query_term_types()) != -1) {
	    colour_map = (mapping)TERM_HANDLER->set_term_type(str);
	    term_name = str;
	    write("Ok, tipo de terminal establecido a "+str+".\n");
	    return 1;
	} else {
	    notify_fail("No existe un tipo de terminal " + str  + ".\n");
	    return 0;
	}
    } else {
	notify_fail("Tipo de terminal no cambiado, esta en " + str + ".\n");
	return 0;
    }
} /* set_term_type() */

void event_commands(){
    add_action("earmuffs", "earmuffs");
    add_action("earmuffs", "tapones");
    add_action("inform", "informar");
    add_action("inform", "inform");
    add_action("set_our_rows", "rows");
    add_action("set_our_cols", "cols");
    add_action("set_term_type", "term");
    add_action("do_past", "past"); // Tyrael - Jun '02
    add_action("set_away", "away"); // Tyrael - Jun '02
    if(!this_object()->query_creator()) {
       add_action("do_block","block");
       add_action("do_block","bloquear");
    }
    add_action("do_new_line","new_line");
    add_action("do_new_line","nueva_linea");
    if(this_object()->query_property(NO_LINE_PROP))
	new_line = "";
    else
	new_line = "\n";
} /* event_commands() */

int do_block(string name)
{
   if(!name || name == "")
   {
      if(block)
        notify_fail("Estas bloqueando a: "+
          capitalize(block)+".\n");
      else
         notify_fail("Sintaxis: bloquear <jugador>\n");
      return 0;
   }
   if(!user_exists(lower_case(name)) && !find_player(name))
   {
      notify_fail("Ese jugador nunca ha existido en " + mud_name() + ".\n");
      return 0;
   }
   block = name;
   write("Ok, bloqueando mensajes de "+capitalize(block)+".\n");
   log_file("BLOCK",TO->query_cap_name()+" ha bloqueado a "+capitalize(block)+
      " : "+ctime(time())+"\n");
   return 1;
}

int earmuffs(string frog)
{
    string *bits, *types, *on;
    int i;

    types = ({ "shout" });
    if (this_object()->query_creator())
	types += ({ "creator-tell", "multiple-soul", "remote-soul",
	"inter-creator-tell" });
    if (!frog)
    {
	if (earmuffs)
	    write("Tus tapones auditivos estan activados.\n");
	else
	    write("Tus tapones auditivos estan desactivados.\n");
	on = (string *)this_object()->query_property("earmuffs");
	if (!on) on = ({ });
	if (!sizeof(on))
	{
	    write("You have nothing set to be earmuffed.\n");
	}
	else
	{
	    for (i=0;i<sizeof(on);i++)
		write("You have "+on[i]+" earmuffed.\n");
	    on = types - on;
	    for (i=0;i<sizeof(on);i++)
		write(on[i]+" events are not currently being earmuffed.\n");
	}
	return 1;
    }
    bits = explode(lower_case(frog), " ");
    bits = bits - ({ "" });
    on = (string *)this_object()->query_property("earmuffs");
    if (!on) on = ({ });
    if (sizeof(bits) == 1)
	switch (bits[0])
    {
    case "on" :
	earmuffs = 1;
	write("Tapones auditivos activados.\n");
	return 1;

    case "off" :
	earmuffs = 0;
	on=({ });
	write("Tapones auditivos desactivados.\n");
	return 1;

    case "all" :
	bits = types;
	break;
    case "none" :
	on = ({ });
	write("Nothing will be ear muffed any more.  (no news is good news?)\n");
	return 1;
    }
    for (i=0;i<sizeof(bits);i++)
	if (member_array(bits[i], types) == -1)
	{
	    write("I cannot earmuff "+bits[i]+" events.\n");
	}
	else
	{
	    if (sizeof(bits) > i+1)
	    {
		switch (bits[i+1])
		{
		case "on" :
		    if (member_array(bits[i], on) == -1)
			on += ({ bits[i] });
		    write("Your "+bits[i]+" events will now be earmuffed.\n");
		    i++;
		    break;

		case "off" :
		    on = on - ({ bits[i] });
		    write("Your "+bits[i]+" events will not be earmuffed.\n");
		    i++;
		    break;

		default :
		    if (member_array(bits[i], on) == -1)
		    {
			write("Your "+bits[i]+" events will be earmuffed.\n");
			on += ({ bits[i] });
		    }
		    else
		    {
			write("Your "+bits[i]+" events will not be earmuffed.\n");
			on = on - ({ bits[i] });
		    }
		    break;
		} /* switch */
	    }
	    else
	    {
		if (member_array(bits[i], on) == -1)
		{
		    write("Your "+bits[i]+" events will be earmuffed.\n");
		    on += ({ bits[i] });
		}
		else
		{
		    write("Your "+bits[i]+" events will not be earmuffed.\n");
		    on = on - ({ bits[i] });
		}
	    }
	}
    this_player()->add_property("earmuffs", on);
    return 1;
} /* earmuffs() */

int check_earmuffs(string type)
{
    string *on;

    on = (string *)this_object()->query_property("earmuffs");
    if (!on) return 0;
    if (member_array(type, on) == -1)
	return 0;
    return 1;
} /* check_earmuffs() */

/* This should go away!!! Baldrick...
 */
int inform(string str)
{
    string *types, *on, *frog;
    int i;

    if (this_object()->query_creator())
	types = ({ "logon", "link-death", "message", "call", "death", "immort_logon" });
    else
	types = ({ "logon" });
    on = (string *)this_object()->query_property("inform");
    if (!on)
	on = ({ });
    if (!str) str = "";
    frog = explode(str, " ");
    if (!frog)
	frog = ({ });
    else
	frog = frog - ({ "", 0 });
    if (!sizeof(frog)) {
	/* show status */
	if (this_object()->query_property("inform repressed"))
	    write("La informacion esta siendo reprimida.\n");
	for (i=0;i<sizeof(on);i++)
	    write("Seras informado de eventos de "+on[i]+".\n");
	types = types - on;
	for (i=0;i<sizeof(types);i++)
	    write("No seras informado de eventos de "+types[i]+".\n");
	return 1;
    }
    if (sizeof(frog) == 1) {
	switch (frog[0]) {
	case "on" :
	    this_object()->remove_property("no_inform");
	    write("You can be informed about the following events:\n");
	    for (i=0;i<sizeof(types);i++)
		write("   "+types[i]+".\n");
	    write("\n'inform <event>' to be informed of the event of your choice."+
	      "\nOr 'inform all' to be informed of all the above events.\n");
	    return 1;
	case "off":
	    this_object()->add_property("no_inform", 1);
	    write("Inform is now repressed.\n");
	    return 1;
	case "all":
	    on = types;
	    frog = frog[1..100];
	    for (i=0;i<sizeof(on);i++)
		write("You will be informed of "+on[i]+" events.\n");
	    break;
	case "none" :
	    on = ({ });
	    write("You will not be informed of anything.\n");
	    frog = frog[1..100];
	    break;
	}
    }
    for (i=0;i<sizeof(frog);i++)
	if (member_array(frog[i], types) == -1) {
	    write("I don't know about "+frog[i]+" events.\n");
	} else {
	    if (sizeof(frog) > i+1) {
		switch (frog[i+1]) {
		case "on" :
		    if (member_array(frog[i], on) == -1)
			on += ({ frog[i] });
		    write("Seras informado de eventos de "+frog[i]+".\n");
		    i++;
		    break;
		case "off" :
		    on = on - ({ frog[i] });
		    write("No seras informado de eventos de "+frog[i]+".\n");
		    i++;
		    break;
		default :
		    if (member_array(frog[i], on) == -1)
		    {
			write("No seras informado de eventos de "+frog[i]+".\n");
			on += ({ frog[i] });
		    }
		    else
		    {
			write("No seras informado de eventos de "+frog[i]+".\n");
			on = on - ({ frog[i] });
		    }
		    break;
		}
	    } else {
		if (member_array(frog[i], on) == -1) {
		    write("Seras informado de eventos de "+frog[i]+".\n");
		    on += ({ frog[i] });
		} else {
		    write("No seras informado de eventos de "+frog[i]+".\n");
		    on = on - ({ frog[i] });
		}
	    }
	}
    this_object()->add_property("inform", on);
    return 1;
} /* inform() */

void set_rows(int i) { rows = i; }
int query_rows() { return rows; }

int set_our_rows(string str)
{
    int val;

    if(!str) {
	notify_fail("Lineas actualmente en " + rows + ".\nrows <numero> para especificarlas.\n");
	return 0;
    }
    if(!sscanf(str, "%d", val) || val <= 10) {
	notify_fail("Numero de columnas invalido.\n");
	return 0;
    }
    write("Rows configuradas en " + val + ".\n");
    rows = val;
    return 1;
} /* set_our_rows() */

int query_cols() { return cols; }
void set_cols(int i) { cols = i; }

int set_our_cols(string str)
{
    int val;

    if(!str) {
	notify_fail("Columnas actualmente " + cols +
	  ".\ncols <numero> para especificarlas.\n");
	return 0;
    }
    if(!sscanf(str, "%d", val) || val <= 35) {
	notify_fail("Numero de columnas invalido.\n");
	return 0;
    }
    write("Columnas configuradas en " + val + ".\n");
    cols = val;
    return 1;
} /* set_our_cols() */

/* Added flag to next func so it can be called in code when
   needed.  -- Hamlet
*/
varargs int do_new_line(string str, int hush)
{
    switch(str) {
    case 0:
	if (new_line == "")
	    new_line = "\n";
	else
	    new_line = "";
	break;
    case "off":
	new_line = "";
	break;
    case "on":
	new_line = "\n";
	break;
    default:
	notify_fail("Sintaxis: new_line <on|off>\n");
	return 0;
    }
    if (new_line == "") {
	this_object()->add_property(NO_LINE_PROP, 1);
	if(!hush)
	    write("Nuevas lineas despues de todo desactivadas.\n");
    } else {
	this_object()->remove_property(NO_LINE_PROP);
	if(!hush)
	    write("Nuevas lineas despues de todo activadas.\n");
    }
    return 1;
} /* do_new_line() */

void event_inform(string mess, string type, object ob)
{
    string *on;

    if (type == "person_cheat")
	efun::tell_object(this_object(), new_line + "[" +
	  fix_string(sprintf("%-=*s", cols-2, mess)) + "]\n");
    on = (string *)this_object()->query_property("inform");
    if (!on) on = ({ });
    if (this_object()->query_property("no_inform")||!sizeof(on)) return ;
    if (member_array(type, on) == -1) return ;
    efun::tell_object(this_object(), new_line + "[" +fix_string(sprintf("%-=*s", cols-2, mess)) + "]\n");
} /* event_inform() */

void event_enter(object ob, string mess, object *ignore)
{
    if (pointerp(ignore) && member_array(this_object(), ignore) != -1)
	return ;
    if (stringp(mess))
	efun::tell_object(this_object(), new_line + fix_string(sprintf("%-=*s",cols, mess ) ));
} /* event_enter() */

/* Testing a new version... please don't touch.  Ducky
 *
void event_exit(object ob, string mess, object from)
  {
  ::event_exit(ob, mess, from);
  if (mess)
    efun::tell_object(this_object(), new_line + fix_string(sprintf("%-=*s",
		     cols, process_string(mess))));
}  event_exit() */

void event_exit(object ob, string mess, object to, object *ignore)
{
    ::event_exit(ob, mess, to, ignore);
    if (pointerp(ignore) && member_array(this_object(), ignore) != -1)
	return ;
    if (mess)
	efun::tell_object(this_object(), new_line + fix_string(sprintf("%-=*s",
	      cols, mess)));
} /* event_exit() */

void event_say(string str, mixed avoid,object caller)
{
    if (pointerp(avoid)) {
	if (member_array(this_object(), avoid) != -1)
	    return ;
    } else if (avoid == this_object())
	return ;
    efun::tell_object(this_object(), new_line + fix_string(sprintf("%-=*s",
	  cols, str)));
} /* event_say() */

void event_write(object caller, string str)
{
    efun::tell_object(this_object(), fix_string(str));
} /* event_write() */

void do_efun_write(string str)
{
    efun::tell_object(this_object(), fix_string(/*sprintf("%-=*s",cols,*/ str))/*)*/;
} /* do_efun_write() */

void event_soul(object ob, string str, mixed avoid)
{
    if (ob != this_object())
	event_say(str, avoid,ob);
    else
	do_efun_write(str);
} /* event_soul() */

void event_person_say(object ob, string start, string mess, string lang, int speaker)
{
    if (member_array(lang, languages) == -1) {
	mixed str;

	if ((str = (mixed)LANGUAGE_HAND->query_garble_object(lang)))
	    if ((str = (mixed)str->garble_say(start, mess))) {
		start = str[0];
		mess = str[1];
	    } else
		return ;
	else
	    return ;
    } else if (lang != "common" && lang != "comun")
	start = start[0..strlen(start)-3]+" en "+lang+": ";
    if (ob == this_object()) return;
//  if(!this_object()->query_creator())
       mess = "/std/language"->scramble_sentence(mess,speaker, this_object()->query_int());
    efun::tell_object(this_object(), new_line + fix_string(sprintf("%s%-=*s\n",
	  start, cols-strlen(start), mess)));
} /* event_person_say() */

void event_person_tell(object ob, string start, string mess, string lang)
{
    string finalmsg;
    int id;
    mixed str;

      if(TP && !TP->query_creator() && TP->query_name() == block)
       {
          write("Esa persona esta bloqueando tus mensajes.\n");
          return;
       }

    if (member_array(lang, languages) == -1) {

	if (str = (mixed)LANGUAGE_HAND->query_garble_object(lang))
	    if (str = (mixed)str->garble_say(start, mess)) {
		start = str[0];
		mess = str[1];
	    } else
		return ;
	else
	    return ;
    } else if (lang != "common" && lang != "comun")
	start = start[0..strlen(start)-3]+" en "+lang+": ";

    /* The following block of code was added to tell players that the target
       is idle and may not reply for a period of time.
       Firestorm 9/3/93
    */

    if (interactive(this_object()) && (id=query_idle(this_object()))
      > TELL_WARN_TIME)
/* tell warn time is defined in player.h in case you wondered -- FS */
    {
	str = ({  });
/* Need to use some neato formulas to convert to standard time -- FS */
   // This needs cleaned up, a simul_efun does this... have to come back
   // Radix

	if(id/(60*60))
	    str += ({   (id/(60*60))+ " horas"  });
	if((id/60)%60)
	    str += ({   ((id/60)%60) + " minutos"   });
	if(id%60)
	    str += ({   (id%60) + " segundos"   });
	write(this_object()->query_cap_name() + " ha estado inactivo durante "+
	  query_multiple_short(str) + ".\n");
    }

    if(this_object()->query_in_editor())
    {
	write(this_object()->query_cap_name() + " esta ocupado editando un fichero y"+
	  " puede tardar un rato en responder.\n");
    }

	// un NPC tiene away? :)
    if (interactive(this_object()) && (finalmsg = TO->query_away())) {
	write(TO->QCN + " esta away: "+finalmsg+".\n");
    }
	finalmsg = fix_string(sprintf("%s%-=*s", start, cols-strlen(start), mess));
	add_past(finalmsg);
    efun::tell_object(this_object(), new_line + finalmsg+"\n");
} /* event_person_tell() */

void event_whisper(object ob, string start, string mess, object *obs,
  string lang)
{
    string blue;
    mixed str;

    blue = "";
    if (member_array(lang, languages) == -1)
    {
	if (str = (mixed)LANGUAGE_HAND->query_garble_object(lang))
	    if (str = (mixed)str->garble_whisper(start, mess))
	    {
		start = str[0];
		mess = str[1];
		blue = ": ";
	    }
	    else
		return ;
	else
	    return ;
    } else if (lang != "common" && lang != "comun")
	blue = " en "+lang+": ";
    else
    if (!stringp(blue)) blue = "";
    if (member_array(this_object(), obs) == -1)
	efun::tell_object(this_object(), new_line + fix_string(sprintf("%s.\n",
	      start + query_multiple_short(obs) +
	      blue[0..strlen(blue)-3])));
    else if (sizeof(obs) == 1)
	efun::tell_object(this_object(), new_line + fix_string(sprintf("%s%-=*s\n",
              start + "you: " + blue, rows - strlen(start) - 10,
	      mess)));
    else
	efun::tell_object(this_object(), new_line + fix_string(sprintf("%s%-=*s\n",
              start + "you and ", rows - strlen(start) - 10,
              query_multiple_short(obs - ({this_object()})) + ": "+blue+mess)));
} /* event_whisper() */

void event_person_shout(object ob, string start, string mess, string lang) 
{
	string finalmsg;

    if (ob == this_object()) {
	add_grito(start+mess);
	return ;
    }
    if(earmuffs == 1 && (string)ob->query_verb() != "cre!" &&
      (string)ob->query_verb() != "shout!"){ return; }
    if (member_array(lang, languages) == -1) {
	mixed str;

	if (str = (mixed)LANGUAGE_HAND->query_garble_object(lang))
	    if (str = (mixed)str->garble_say(start, mess)) {
		start = str[0];
		mess = str[1];
	    } else
		return ;
	else
	    return ;
    } else if (lang != "common" && lang != "comun")
	start = start[0..strlen(start)-3]+" en "+lang+": ";

	finalmsg = fix_string(sprintf("%s%-=*s", start, cols-strlen(start), mess));
	add_grito(finalmsg);	// New by Tyrael - Jun '02
    efun::tell_object(this_object(), new_line + finalmsg + "\n");
} /* event_person_shout() */

void event_creator_tell(object ob, string start, string mess) 
{
    if (ob == this_object() || (earmuffs == 1 && query_verb() != "cre!") ||
      !this_object()->query_creator())
	return;
    efun::tell_object(this_object(), new_line + fix_string(sprintf("%s%-=*s\n",
	  start, cols - strlen(start), mess)));
} /* event_creator_tell() */

nomask void event_god_inform(object ob, string start, string mess)
{
    if(!previous_object()->query_lord())
	return;
    efun::tell_object(this_object(), new_line + fix_string(sprintf("%s%-=*s\n",
	  start, cols - strlen(start), mess)));
}

void event_inter_creator_tell(object ob, string mname, string pname, 
  string mess, object ig, int emote) {
    if (!this_object()->query_creator() 
      || check_earmuffs("inter-creator-tell")
      || earmuffs
      || this_object() == ig)
	return ;
    efun::tell_object(this_object(), new_line +
      fix_string(sprintf("%s@%s%s%-=*s\n", pname, mname,(emote?" ":": "),
	  cols-strlen(mname)-strlen(pname)-3, mess)));
} /* event_inter_creator_tell() */

void event_player_echo_to(object ob, string mess) {
    if (this_object()->query_lord())
	efun::tell_object(this_object(), ob->query_cap_name()+" echo to's:\n");
    efun::tell_object(this_object(), new_line + fix_string(sprintf("%-=*s\n",
	  cols, mess)));
} /* event_player_echo_to() */

void event_player_emote_all(object ob, string mess) 
{
    if (ob == this_object())
	return;
    if (this_object()->query_lord())
	efun::tell_object(this_object(), ob->query_cap_name()+" emote all's:\n");
    efun::tell_object(this_object(), new_line + fix_string(sprintf("%-=*s\n",
	  cols, mess)));
} /* event_player_emoteall() */

void event_player_echo_all(object ob, string mess) 
{
    if (ob == this_object())
	return;
    if (this_object()->query_lord())
	efun::tell_object(this_object(), ob->query_cap_name()+" echo all's:\n");
    efun::tell_object(this_object(), new_line + fix_string(sprintf("%-=*s\n",
	  cols, mess)));
} /* event_player_echoall() */


void event_player_echo(object ob, string mess) 
{
    if (ob == this_object())
	return;
    if (this_object()->query_lord())
	efun::tell_object(this_object(), ob->query_cap_name()+" echo's:\n");
    efun::tell_object(this_object(), new_line + fix_string(sprintf("%-=*s\n",
	  cols, mess)));
} /* event_player_echo() */
