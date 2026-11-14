/* DO not copy this file!!! There should be enought #defines so you can make
   the line work the way you want, and if you should need another define
   ask Rohan for it. */
/* Do NOT change this file if you find any bug.
   If the bug is not so serious that it must be fixed right away mail Rohan,
   and if it is serious change /players/rohan/line/line.c and make sure it
   works before you copy that file to /obj/line/line.c
   Changes only made in /obj/line/line.c will dissapear when it is replaced
   with /players/rohan/line/line.c next time.
*/

#define OWNER (environment()?environment():find_object("/room/void"))
#define SEND(x) tell_room(load_object(OWNER?SENDROOM:"/room/void"),x+"\n")
#define NAME  (OWNER?capitalize((string)OWNER->query_real_name()):"")

static object SP;

init_line() {
  if(this_player()!=environment()) return;
  add_action("print_list", LINEMEMBERS);
  add_action("line_send", LINECOMMAND);
  add_action("send_on", LINEON);
  add_action("send_off", LINEOFF);
#ifdef LINETOCOMMAND
  add_action("line_to", LINETOCOMMAND);
#endif
  send_reset();
}

send_off() {
  if (!SP) { send_reset(); }
    if(SP->query_online()==0) {
#ifdef ARE_OFFLINE
	write(LINENAME+ARE_OFFLINE+"\n");
	return 1;
#endif
	write(LINENAME+"You are already offline!\n");
	return 1;
    }
    else {
#ifdef GOES_OFFLINE
	write(LINENAME+GOES_OFFLINE+"\n");
#else
	write(LINENAME+"You are now offline.\n");
#endif
        SP->go_offline();
    }
    return 1;
}

send_on() {
  if (!SP) { send_reset(); }
  if(SP->query_online()==1) {
#ifdef ARE_ONLINE
    write(LINENAME+ARE_ONLINE+"\n");
    return 1;
#endif
    write(LINENAME+"You are already online!\n");
    return 1;
  }
  else {
#ifdef GOES_ONLINE
    write(LINENAME+GOES_ONLINE+"\n");
#else
    write(LINENAME+"You are now online.\n");
#endif
    SP->go_online();
  }
  return 1;
}

send_reset() {
int new_statue_was_cloned;
  new_statue_was_cloned=0;
  SP=present(this_player()->query_real_name(),load_object(SENDROOM));  
  if(!SP) { 
    SP=clone_object(SENDPLAYER);
    move_object(SP, SENDROOM);
    new_statue_was_cloned=1; /* We cloned a new statue. */
  }
#ifdef EXTRA_SEND_PLAYER_INFO
  SP->init_statue(this_player(),LINENAME,EXTRA_SEND_PLAYER_INFO);
#else
  SP->init_statue(this_player(),LINENAME);
#endif
  return new_statue_was_cloned; /* We already had a statue */
}

line_to(string what)
{
  string target,text,intext,away;
  object target_obj;
  target="";
  text="";
  if (!what) {
    write(LINENAME+"You must specify a name to tell something.\n");
    return 1;
  }
  sscanf(what,"%s %s",target,intext);
  if (!intext) {
    write(LINENAME+"You must specify what to tell.\n");
    return 1;
  }
  text=capitalize(this_player()->query_real_name())+" tells you: "+intext+"\n";
  if (target=="") target=what;
  target_obj=present(target,load_object(SENDROOM));
  if (!target_obj) {
    write(LINENAME+"There is no "+target+" connected to this line right now.\n");
    return 1;
  }
#ifdef OWN_SENDTOCOST_FUNCTION
  if (!own_sendtocost_function(target,intext)) return 1;
#endif

#ifdef SENDTOCOST
  if (SENDTOCOST!=0) {
    if (this_player()->query_spell_points() < SENDTOCOST) {
      write(LINENAME+"You're too weak to use the line!\n");
      return 1;
    }
    this_player()->restore_spell_points(-SENDTOCOST);
  }
#endif
  if (!interactive(target_obj->query_who())) {
    write(LINENAME+target+" is currently linkdead and can't hear you.\n");
    return 0;
  }
  if ((target_obj->query_who())->is_hard_invis()) {
    write(LINENAME+"There is no "+target+" connected to this line right now.\n");
    return 1;
  }
#ifdef CHECK_AWAYSTRING
  away = (string) (target_obj->query_who())->query_away(SET_REPLY_TO);
  if (away) {
    write(LINENAME+target_obj->query_name()+" is away: "+away+"\n");
    text=text[0..strlen(text)-2]+" <"+ctime(time())[11..15] +">\n";
  }
#endif
#ifdef PASS_LINETO_WHEN_OFFLINE
  target_obj->catch_tell_line_to(text,1);
#else
  target_obj->catch_tell_line_to(text,0);
#endif
#ifdef QUERY_ECHO_LINETO
  if (previous_object()->query_echo_lineto()) {
    write(LINENAME+"You told "+target_obj->query_name()+": "+intext+"\n");
    return 1;
  }
  write(LINENAME+"Ok.\n");
  return 1;
#endif
  write(LINENAME+"You told "+target_obj->query_name()+": "+intext+"\n");
  return 1;
}

line_send(string what)
{
  object e;
  string ts;
#ifdef LINECOMMAND_WITHOUT_ARG_EQUALS_MEMBERCOMMAND
  if(what==0) {
      return print_list();
  }
#endif
  if(what==0) {
      write(LINENAME+"Say what?\n");
      return 1;
  }
#ifdef OWN_SENDCOST_FUNCTION
  if (!own_sendcost_function(what)) return 1;
#endif

#ifdef SENDCOST
  if (SENDCOST!=0) {
    if (this_player()->query_spell_points()<SENDCOST) {
      write(LINENAME+"You're too weak to use the line!\n");
      return 1;
    }
    this_player()->restore_spell_points(-SENDCOST);
  }
#endif
  if (!SP) { send_reset(); }
  SP->go_online();
  if(what)
    switch(what[0])
    {
      case 33:
/* Specialy requested for Druids-line. */
#ifdef NO_FEELINGS
  write(LINENAME+"Sorry, no feelings allowed over this line.\n");
  return 1;
#endif
        ts=what[1..1000];
        if (!command(ts,SP)) write(LINENAME+"Feeling does not exist!\n");
        return 1;
      case 35:
        /* emote */
#ifdef NO_EMOTE
  write(LINENAME+"Sorry, no emote allowed over this line.\n");
  return 1;
#endif
        tell_room(SENDROOM,capitalize(this_player()->query_real_name())+" "+what[1..1000]+"\n");
        return 1;
      default:
        tell_room(SENDROOM,capitalize(this_player()->query_real_name())+": "+what+"\n");
        return 1;
    }  
}

print_list() {
  int i;
  object *alla;
  string levstr;
  if (!SP) { send_reset(); }
#ifdef SORT_OBJECT
  SORT_OBJECT->line_print_list(all_inventory(environment(SP)));
  return 1;
#endif
  write("These are the members currently logged on:\n");
  alla=all_inventory(environment(SP));
  alla = m_values(mkmapping(map_array(alla, "scale_fun", this_object()), alla));
  for(i=0;i<sizeof(alla);i++) {
    switch(alla[i]->query_level()) {
/*	      case 1..9  : levstr=" "+alla[i]->query_level(); break;
	      case 10..19: levstr=""+alla[i]->query_level(); break;
	      case 20..21: levstr="Wz"; break;
	      case 22    : levstr="Sk"; break;
	      case 23    : levstr="Hi"; break;
              case 25    : levstr="Ar"; break;
              case 30    : levstr="El"; break;
              case 50    : levstr="Gd"; break;
 */
      case 1..19 : levstr="Mortal"; break;
      default    : levstr="Wizard"; break;
    }
    if (/* !(alla[i]->query_npc()) && */
	alla[i]->short() &&
	alla[i]->query_name())
    {
      write("["+levstr+"] "+alla[i]->short());
      if (!alla[i]->query_online()) { write(" (offline)"); }
      write("\n");
    }
  }
  return 1;
}

scale_fun(o)
{
/* Sort wizards first by name, then sort mortals by name */
  string a;
  a=o->query_name()+"\n\n\n";
  if (o->query_level()<20) return a[0]*0x10000+a[1]*0x100+a[2];
  return -2*0x1000000+a[0]*0x10000+a[1]*0x100+a[2];
} /* scale_fun */












