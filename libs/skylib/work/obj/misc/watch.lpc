inherit OBJECT_OBJ;

int our_offset,
    their_offset,
    last_time,
    cur_alarm,
    offset_alarm,
    alarm;
mixed *alarms; 
string *alarm_write,
       alarm_name;
object our_player;

string get_time();
varargs int get_text(string line);

void setup() {
  set_name("watch");
  add_adjective("demonic");
  add_alias("watch");
  set_main_plural("demonic watches");
  set_short("demonic watch");
  set_long("A small wrist attachable living quarters for a demon.  "+
           "The demon looks pretty harried about giving out the "+
           "time all the time, and the pay is lousy.  PS: try \"use\" "+
           "watch.\n");
  set_value(20000);
  our_offset = 0;
  their_offset = 8;
  last_time = time();
  call_out("check_alarm",60);
  alarms = ({ });
}

string long( string word, int dark ) {
  if (our_offset == their_offset)
    return ::long()+".\n"+get_time()+".\n";
  else
    return ::long()+"\n"+get_time()+"\nMud time: "+ctime(time())+".\n";
}

string query_read() {
  if (our_offset == their_offset)
    return get_time()+".\n";
  else
    return get_time()+"\nMud time: "+ctime(time())+".\n";
}

void init() {
  add_command("time", "");
  add_command("gmt", "<word'offset'>", (:this_object()->set_gmt($4[0]):));
  add_command("use", "<direct:object>", (:this_object()->use():));
  this_player()->add_command("read", this_object());
}

int use(string arg) {
  if (!alarms)
    alarms = ({ });
  printf("%-=80s","You look into the watch and fiddle with several buttons, "+
                  "Finally a light lights up in the top corner say you have "+
                  "the security clearance to modify the settings.\n"+
                  "You can \"set\" an alarm \"remove\" an alarm \"list\" the "+
                  "set alarms. You can \"quit\" also.\n");
  write("What do you wish to do ? ");
  input_to("the_command");
  return 1;
}

int the_command(string arg) {
  string s1;
  int i;

  if (arg == "quit") {
    write("Thank you for using this wonderful watch.\n");
    return 1;
  }
  if (sscanf(arg,"set%s",s1)) {
    int hour, min;
    string name;
    if (sscanf(s1," %s %d:%d%s",name,hour,min,s1)!=4)
      write("Usage: set <name> <hour>:<min> [+]\n");
    else {
      if ((i=member_array(name,alarms))<0)
        alarms += ({ name, hour, min, 0 });
      else
        if (i%4)
          write("Oooooopps, you cannot use that name as an alarm\n");
        else {
          alarms[i+1] = hour;
          alarms[i+2] = min;
        }
      if (s1 == " +") {
        if (i==-1)
          i = sizeof(alarms)-4;
        cur_alarm = i;
        get_text();
        return 1;
      }
    }
  }
  if (sscanf(arg,"remove%s",s1)) {
    string frog;
    if (sscanf(s1," %s",frog)!=1)
      write("Usage: remove <name>\n");
    else
      if ((i=member_array(frog,alarms))<0)
        write("You must remove an existing alarm\n");
      else
        if (i%4)
          write("Ohhh dear.\n");
        else {
          alarms = delete(alarms,i);
          alarms = delete(alarms,i);
          alarms = delete(alarms,i);
          alarms = delete(alarms,i);
        }
  }
  if (sscanf(arg,"list%s",s1)) {
    string chicken;
    if (sscanf(s1," %s",chicken)!=1) {
      for (i=0;i<sizeof(alarms);i+=4) {
        write("Alarm "+alarms[i]+" is set for "+alarms[i+1]+":"+alarms[i+2]+"\n");
      }
    } else {
      if ((i=member_array(chicken,alarms))<0)
        write("That alarm does not exist.\n");
      else
        if (i%4)
          write("Bing basicly");
        else
          write("You have set alarm "+chicken+" to go off at "+alarms[i+1]+":"+
                 alarms[i+2]+"\n");
    }
  }
  if (sscanf(arg,"time%s",s1)==1) {
    write(get_time()+"\n");
  }
// removed as it doesn't do anything
//  if (sscanf(arg,"gmt%s",s1)==2) {
//  }
  write("What do you wish to do ? ");
  input_to("the_command");
  return 1;
}

int do_read() {
  if (query_read_mess() /* && !::do_read() */ )
    return 0;
  write(get_time()+"\n");
  return 1;
}

int set_gmt(string arg) {
  if (!arg) {
    notify_fail("You must give a GMT to set to.\n");
    return 0;
  }
  if (arg[0] == '+')
    sscanf(arg,"+%d",their_offset);
  else
    sscanf(arg,"%d",their_offset);
  write("Ok your GMT offset is now set to ");
  if (their_offset>=0)
    write("+"+their_offset+".\n");
  else
    write(their_offset+".\n");
  return 1;
}

int do_time() {
  write(get_time()+"\n");
  write("Mud time: "+ctime(time())+".\n");
  return 1;
}

string get_time() {
  string the_time;

  the_time = "";

  the_time = ctime(time()-(our_offset-their_offset)*3600);  
  return the_time;
}

varargs int get_text(string line) {
   string text;
  if (!line) {
    text = "";
    write(sprintf("%-=80s","Please enter the text you wish to be displayed "+
          "when the alarm goes off (. to finish)"));
  } else if (line==".") {
    alarms[cur_alarm+3] = text+"\n";
    write("What do you wish to do ? ");
    input_to("the_command");
    return 1;
  } else
    text += line+"\n";
  write("] ");
  input_to("get_text");
  return 1;
}

mixed query_auto_load() {
  mixed ret;

  if (!alarms)
    alarms = ({ });
  ret = ({ their_offset, alarms });
  return ret;
}

void init_arg(mixed *arg) {

  their_offset = arg[0];
  alarms = arg[1];
  if (!alarms)
    alarms = ({ });
}

void check_alarm() {
   int the_time, offset, i;
   int tmp;
   
   the_time = time();
   offset = (the_time/(3600*24))*3600*24 - our_offset*3600;
   for (i=0;i<sizeof(alarms);i+=4) {

      tmp = offset + (alarms[i+1]-our_offset+their_offset)*3600 + alarms[i+2]*60;
      if (the_time>tmp && tmp>last_time) {
         /* we go off. bounce */
         alarm = 6;
         alarm_name = alarms[i];
         if (alarms[i+3])
         alarm_write = explode(alarms[i+3],"\n");
      else
         alarm_write = ({
            "Beep Beep Beep, Your "+alarms[i]+" alarm has gone off.\n",
            "Beep Beep Beep, Your "+alarms[i]+" alarm has gone off.\n",
            "Beep Beep Beep, Your "+alarms[i]+" alarm has gone off.\n",
            "Beep Beep Beep, Your "+alarms[i]+" alarm has gone off.\n",
            "Beep Beep Beep, Your "+alarms[i]+" alarm has gone off.\n",
            "Beep Beep Beep, Your "+alarms[i]+" alarm has gone off.\n",
         });
         offset_alarm = 0;
         set_heart_beat(1);
      }
   }
   last_time = the_time;
   call_out("check_alarm",60);
}

void heart_beat() {
   if (our_player)
     our_player->event_say(this_object(), "The watch goes: "+
                           alarm_write[offset_alarm++]+"\n");
   if (offset_alarm>sizeof(alarm_write))
     set_heart_beat(0);
}

int move(object ob) {
  int i;

  i = ::move(ob);
  our_player = environment();
  return i;
}
