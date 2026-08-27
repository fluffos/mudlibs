#include "mail.h"
inherit "/std/object";

#include "board.h"

nosave string *readonly = ({"playerinfo","quests","announcements"});

string board_name;

mapping being_written;
int action_pri;

void setup() {
  	set_name("tablon");
  	set_short("Tablon de Notas");
	add_alias("tablon");
  	set_main_plural("Tablones de Notas");
	add_plural("tablones");
  	reset_get();
  	board_name = "basura";
  	being_written = ([ ]);
  	action_pri = 0;
	} /* setup() */

string query_plural() {
  	mixed *stuff;

  	stuff = (mixed *)BOARD_HAND->get_subjects(board_name);
  	switch (sizeof(stuff)) {
    		case 0:  return pluralize(::short(0))+" [ Vacio ]";
    		case 1:  return pluralize(::short(0))+" [ 1 nota ]";
  	}
   	return pluralize(::short(0))+" [ "+sizeof(stuff)+" notas ]";
	} /* query_plural() */

string short(int dark) {
  	mixed *stuff;
	mapping recientes=TP->query_property(NEWS_RC);
	string buf;
	int noleidas=0;

  	stuff = (mixed *)BOARD_HAND->get_subjects(board_name);
	if(!sizeof(stuff)) return ::short(dark)+" [ %^CYAN%^0%^RESET%^ ]";
	if(!recientes) recientes = ([ ]);
	buf="";
	for (int i=0;i<sizeof(stuff);i++) if(recientes[board_name]<stuff[i][B_TIME]) noleidas++;
	if(!noleidas) return ::short(dark)+" [ %^CYAN%^"+sizeof(stuff)+"%^RESET%^ ]";
	return ::short(dark)+" [ %^ORANGE%^"+noleidas+"%^RESET%^/%^CYAN%^"+sizeof(stuff)+"%^RESET%^ ]";
	} /* short() */

string the_date(int i) { return ctime(i)[4..9]; } /* the_date() */

int subjects(string str, int dark) {
  	int i;
  	mixed *stuff;
  	string ret;
  	mapping news_rc;

  	stuff = (mixed *)BOARD_HAND->get_subjects(board_name);
  	if (!sizeof(stuff)) return notify_fail("El tablon esta completamente vacio.\n");

	news_rc = (mapping)this_player()->query_property(NEWS_RC);
  	if (!news_rc) news_rc = ([ ]);
  	ret = "";
  	for (i=0;i<sizeof(stuff);i++) if (news_rc[board_name] < stuff[i][B_TIME]) ret += sprintf("N %2d: %-=*s\n", i+1, (int)this_player()->query_cols()-6,stuff[i][B_SUBJECT]+" ("+capitalize(stuff[i][B_NAME])+" "+the_date(stuff[i][B_TIME])+")");
    	else ret += sprintf("  %2d: %-=*s\n", i+1, (int)this_player()->query_cols()-6,stuff[i][B_SUBJECT]+" ("+capitalize(stuff[i][B_NAME])+" "+the_date(stuff[i][B_TIME])+")");
  	this_player()->set_finish_func(0);
  	this_player()->more_string(ret);
  	return 1;
	} /* subjects() */

string long(string str, int dark) {
  	int i,newones;
  	mixed *stuff;
  	string ret;
  	mapping news_rc;

  	stuff = (mixed *)BOARD_HAND->get_subjects(board_name);
  	ret = "Un tablon de notas ("+CAP(board_name)+").\n";
  	ret += sprintf("%#-*s\n\n", this_player()->query_cols(),"leer [numero]\nescribir <asunto>\n"+"asuntos\ncomerse <nota>\n"+"responder <nota>\ncontinuar <nota>\n");

  	if (!sizeof(stuff))
    	return ret+"El tablon esta completamente vacio.\n";

  	news_rc = (mapping)this_player()->query_property(NEWS_RC);
  	if (!news_rc) news_rc = ([ ]);

  	newones = 0;
  	for (i=0;i<sizeof(stuff);i++) if (news_rc[board_name] < stuff[i][B_TIME]) {
      		ret += sprintf("N %2d: %-=*s\n", i+1, (int)this_player()->query_cols()-6,stuff[i][B_SUBJECT]+" ("+capitalize(stuff[i][B_NAME])+" "+the_date(stuff[i][B_TIME])+")");
      		newones +=1;
    		}
	else if (news_rc[board_name] < stuff[i][B_TIME]+(2*24*60*60))
      		ret += sprintf("  %2d: %-=*s\n", i+1, (int)this_player()->query_cols()-6,
             	stuff[i][B_SUBJECT]+" ("+capitalize(stuff[i][B_NAME])+" "+the_date(stuff[i][B_TIME])+")");

  	if (!newones) ret += "\nNo hay nuevos mensajes.\n";
  	return ret;
	} /* long() */

void init() {
  	add_action("read", "leer", action_pri);
  	add_action("post", "escribir", action_pri);
  	add_action("post", "nota", action_pri);
  	add_action("eat", "comerse", action_pri);
  	add_action("followup", "continuar", action_pri);
  	add_action("reply", "responder", action_pri);
  	add_action("subjects", "asuntos", action_pri);
	} /* init() */

void string_more(string arg, string prompt) {
  	this_player()->set_finish_func(0);
  	this_player()->more_string(arg, prompt);
	} /* string_more() */

int read(string str) {
  	int num, i;
  	mixed stuff;
  	mapping news_rc;

  	notify_fail("Uso: leer <numero de nota>\n");
  	stuff = (mixed *)BOARD_HAND->get_subjects(board_name);
  	news_rc = (mapping)this_player()->query_property(NEWS_RC);
  	if (!news_rc) news_rc = ([ ]);
  	if (!str) {
	 	i = sizeof(stuff)-1;
    		while (i >= 0 &&stuff[i][B_TIME] > news_rc[board_name] ) i--;
    		if (i == sizeof(stuff)-1) return notify_fail("No hay mensajes sin leer.\n");

    		num = i+2;
  		}
	else if (sscanf(str, "%d", num) != 1) return 0;
  	if (num < 1 || num > sizeof(stuff)) return notify_fail("No existe la nota con ese numero.\n");
	  num --;
  	if (news_rc[board_name] < stuff[num][B_TIME]) {
    		news_rc[board_name] = stuff[num][B_TIME];
    		this_player()->add_property(NEWS_RC, news_rc);
  		}
  	string_more(sprintf("Nota #%d de %s escrita en %s\nTitulo: '%s'\n\n", num+1, capitalize(stuff[num][B_NAME]), ctime(stuff[num][B_TIME]),stuff[num][B_SUBJECT][0..(int)this_player()->query_cols()-10])+BOARD_HAND->get_message(board_name, num),"[Nota "+(num+1)+"]");
  	return 1;
	} /* read() */

int post(string str) {
   	if( (member_array(board_name,readonly) != -1) && !this_player()->query_creator()) {
   		write("Solamente los inmortales pueden escribir en este tablon.\n");
    		return 1;
  		}
  	notify_fail("Sintaxis: escribir <asunto>\n");
  	if (!str)
    	return 0;
/* ok shove the editing stuff in here.  Lets make it function string_edit
 * sound froggy?
 */
/*
  string_edit("");
  body = string_edit_res;
*/
  	being_written[this_player()->query_name()] = str;
  	this_player()->do_edit(0,"end_of_thing");
  	return 1;
	} /* post() */

void end_of_thing(string body) {
  	if (body && body != "" && being_written[this_player()->query_name()]) {
    		if (!BOARD_HAND->add_message(board_name, this_player()->query_name(),being_written[this_player()->query_name()], body+TP->append_signature())) write("Error escribiendo el mensaje.\n");
    		else write("Mensaje escrito.\n");
		}
  	else write("Error.\n");
  	being_written = m_delete(being_written, this_player()->query_name());
  	return ;
	} /* end_of_thing() */

int eat(string str) {
  int num, i, eaten;

	if (!TP->query_creator()) {
  		notify_fail("Arrancas una nota del tablon y te la comes, pero al momento aparece por arte de magia alli donde estaba.\n");
		return 0;
	}
  notify_fail("Sintaxis: comerse [hasta] <num nota>\n");
  if (!str)
    return 0;
  if (sscanf(str, "hasta %d", num)) {
    for (i=0;i<num;i++)
      eaten += (int)BOARD_HAND->delete_message(board_name, i);
    if (!eaten) {
      notify_fail("No se ha comido ninguna nota.\n");
      return 0;
    }
    write("Degustas "+eaten+" notas, nyam nyam.\n");
    say(this_player()->query_cap_name()+" llora viciosamente a la vez que se come "+
        query_num(eaten, 0)+" notas.\n");
    if (eaten == 1)
      event(users(), "inform", this_player()->query_cap_name()+" se come una nota "+
            "de "+board_name, "message");
    else
      event(users(), "inform", this_player()->query_cap_name()+" se come "+
            query_num(eaten, 0)+" notas de "+board_name, "message");
    return 1;
  } else if (sscanf(str, "%d", num) != 1)
    return 0;
  if (!BOARD_HAND->delete_message(board_name, num-1))
    return 0;
  write("Lloras viciosamente y te comes la nota "+num+"\n");
  say(this_player()->query_cap_name()+" llora viciosamente y se come la nota "+
         num+".\n");
  event(users(), "inform", this_player()->query_cap_name()+" se come una nota "+
                           "de "+board_name, "message");
  return 1;
} /* eat() */

int followup(string str) {
  int num, i;
  mixed stuff;
  string s;

   if( (member_array(board_name,readonly) != -1) && !this_player()->query_creator())
   {
   write("Solamente los inmortales pueden escribir en este tablon.\n");
    return 1;
  }
  notify_fail("Sintaxis: continuar <num nota>\n");
  if (!str)
    return 0;
  if (sscanf(str, "%d", num) != 1)
    return 0;
  stuff = (mixed *)BOARD_HAND->get_subjects(board_name);
  if (num < 1 || num > sizeof(stuff)) {
    notify_fail("No existe ninguna nota con ese numero.\n");
    return 0;
  }
  if (sscanf(stuff[num-1][B_SUBJECT], "Re:#%d %s", i, s) != 2)
    being_written[this_player()->query_name()] = "Re:#1 "+stuff[num-1][B_SUBJECT];
  else
    being_written[this_player()->query_name()] = "Re:#"+i+" "+s;
  this_player()->do_edit(0,"end_of_thing");
  return 1;
} /* followup() */

int reply(string str) {
  int num;
  mixed stuff;

  if(board_name=="announcements" && !this_player()->query_creator() )
  {
  write("Solamente los inmortales pueden escribir en este tablon.\n");
  return 1;
  }
  notify_fail("Syntax: responder <num nota>\n");
  if (!str)
    return 0;
  if (sscanf(str, "%d", num) != 1)
    return 0;
  stuff = (mixed *)BOARD_HAND->get_subjects(board_name);
  if (num < 1 || num > sizeof(stuff)) {
    notify_fail("No existe ninguna nota con ese numero.\n");
    return 0;
  }
  MAIL_TRACK->mail(stuff[num-1][B_NAME], stuff[num-1][B_SUBJECT]);
  return 1;
} /* reply() */

void set_board_name(string str) {
  str = lower_case(str);
  board_name = str;
  BOARD_HAND->create_board(board_name, 0);
}

void set_datafile(string str) {
  set_board_name(str);
  /*board_name = str;*/
}

int query_new_messages() {
  mixed *notes;
  mapping news_rc;

  news_rc = (mapping)this_player()->query_property(NEWS_RC);
  if (!news_rc)
    news_rc = ([ ]);
  notes = (mixed *)BOARD_HAND->get_subjects(board_name);
  if (!sizeof(notes)) return 0;
  return (notes[sizeof(notes)-1][B_TIME] > news_rc[board_name]);
} /* query_new_messages() */
