#define MASTER "/secure/master"
#define PEOPLER "/obj/handlers/peopler"
#define traceprefix(x)
#define trace(x)

#define C_NAME 0
#define C_DATA 1
#define C_OBJ 2
#define C_FUNC 3

varargs object *wiz_present(string str, object onobj, int nogoout);
string desc_object(mixed o);
string desc_f_object(object o);

protected void wiz_commands() {
  /* Adds for new commandsystem.. */
  //add_action("comm_info","cominfo");
} /* wiz_commands() */
     
/*
** commands in the app_commands will go to all players with
** level >= 20. This includes players who have opted to
** remain players rather than advancing to wizard. As such
** we must be careful in what we place here
*/
 
protected void app_commands() {
  add_action("do_snoop", "snoop");
  add_action("grim_snoop", "qsnoop");  /* Added on 16 March by Grimbrand */
} /* app_commands() */
 
/* These commands go to ALL players. Note that master.c
** gives only limited read/write access to dirs anyway,
** so the apparent security problems are NOT a problem
*/
 
protected void all_commands() {
} /* all_commands() */

int check_snoop(object ob) {
  if((object)ob->query_snoopee())
    return 1;
  else
    return 0;
} /* check_snoop() */

/*  Added on 16 March 93 by Grimbrand */

protected int grim_snoop(string str) {
   object targ;

  if( this_player(1)->query_lord() )
     {
      if(!str)
        {
         snoop(this_object(),0);
         write("Ok, quiet snoop cancelled.\n");
         return 1;
        }
      str = (string)this_player()->expand_nickname(str);
      if(!(targ = find_player(str)))
        {
         notify_fail("Cannot find "+str+" to quiet snoop.\n");
         return 0;
        }
      if(targ->query_god())
        {
         tell_object(targ,"A demonic voice echo's within your head saying:\n"+
                     " \n"+
                     this_player()->query_cap_name()+" has attempted to "+
                     "silently snoop you m'lord.\n");
         return 1;
        }
      if(!snoop(this_object(), targ))
        {
         notify_fail("You fail to silently snoop "+capitalize(str)+".\n");
         return 0;
        }
      write("Ok, quiet snooping "+str+".\n");
      return 1;
     }
   write("A demons voice echo's inside your skull:\n"+" \n"+
         "You have not the power nor the ability for such a feat!\n");
   return 1;
}

protected int do_snoop(string str) {
  object targ;

  if (!str) {
    snoop(this_object());
    write("Ok, snoop cancelled.\n");
    return 1;
  }
  str = (string)this_player()->expand_nickname(str);
  if(!(targ = find_player(str))) {
    notify_fail("Cannot find "+str+".\n");
    return 0;
  }
 /* fixed object 24.2 93 Baldrick */
if(!this_player()->query_god() && targ->query_lord()) {
 tell_object(targ, "A cute Duck appears before you.\n"+
                 "The Duck says: "+this_player()->query_cap_name()+
                 " is trying to snoop you m'lord.\n");
  this_object()->set_trivial_action();
 return 1;
}

  if(!snoop(this_object(), targ)) {
    notify_fail("You fail to snoop " + capitalize(str) + ".\n");
    return 0;
  }
  write("Ok, snooping "+str+".\n");
  return 1;
} /* do_snoop() */   

int review() {
  PEOPLER->review();
  this_object()->set_trivial_action();
  return 1;
} /* review() */

nosave mapping blue;

int stats_sort_array(string str, string str2) {
  if (blue[str]["moves"] > blue[str2]["moves"])
    return 1;
  if (blue[str]["moves"] < blue[str2]["moves"])
    return -1;
  return 0;
} /* stats_sort_array() */

int stats_filter_array(string ind) {
  return blue[ind]["moves"]+blue[ind]["heart_beats"]+blue[ind]["worth"]+
         blue[ind]["array_size"]+blue[ind]["errors"]+blue[ind]["objects"];
} /* stats_filter_array() */

string string_stats(mapping map) {
  string *inds, str;
  int i;

  str = sprintf("%20-s %7|s %7|s %7|s %7|s %7|s %7|s\n",
           "name", "moves", "hbs", "worth", "arr", "errors", "objects");
  inds = keys(map);
  blue = map;
  inds = sort_array(filter_array(inds, "stats_filter_array", this_object()),
                    "stats_sort_array", this_object());
  blue = ([ ]);
  for (i=0;i<sizeof(inds);i++) {
    str += sprintf("%20-s %7|d %7|d %7|d %7|d %7|d %7|d\n", inds[i],
                   map[inds[i]]["moves"],
                   map[inds[i]]["heart_beats"], map[inds[i]]["worth"],
                   map[inds[i]]["array_size"], map[inds[i]]["errors"],
                   map[inds[i]]["objects"]);
  }
  return str;
} /* print_stats() */

/*
 * I wonder if anything else than cominfo uses this.
 * I'll keep it rem'ed out for now. 
 * cominfo uses it's own in the external command
 * Baldrick. dec '97.
protected string do_find_comm(string func, object ob) {
  string s, ping;
  object fish;
  s = "";
  if(ping = function_exists(func, ob))
      s += " found in " + ping;
    else
      s += " not found";
  fish = ob;
  while(fish = shadow(fish, 0))
    if(function_exists(func, fish))
      s += " shadowed by " + file_name(fish);
  s += ".\n";
  return s;
} */ /* do_find_comm() */

