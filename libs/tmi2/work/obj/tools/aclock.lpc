
// aclock.c
// A basic alarm clock. You can set this to give you messages at some
// time in the future.
// Written by Mordact@TMI-2, date unknown.
// Mobydick put it into the mudlib, 9-13-93.

#include <mudlib.h>

inherit OBJECT;

void create() {
  set("short","an alarm clock");
  set("long","@@query_long");
  set("id", ({ "clock" }));
  set("mass",150);
  set("bulk",50);
  }

void init() {
  add_action("set_ac","set");
  add_action("cancel_ac","cancel");
  add_action("read_tab","read");
  }

int set_ac(string str) {
  string atime;
  string amsg;
  int itime;

  amsg="Ring! Ring! Ring!";

if (!str || str=="")
  return 0; // Avatar: let the SET command take care of it!
  if (sscanf(str,"alarm %s %s",atime,amsg)<1) {
    notify_fail("What do you want to set?");
    return 0;
    }
    sscanf(atime,"%d",itime);
  if (itime==0) {
    write("Why would you want to set it to 0?\n");
    return 1;
    }
  call_out("sound_alarm",itime,({ amsg, this_player() }));
  write("Alarm in "+itime+" seconds: "+amsg+"\n");
  say(this_player()->query("cap_name")+" fiddles with an alarm clock.\n");
  return 1;
  }
  
int cancel_ac(string str) {
  int timeleft;

  if (str!="alarm") {
    notify_fail("Cancel what?\n");
    return 0;
    }

  if ((timeleft=remove_call_out("sound_alarm"))==-1) {
    write("There are no alarms set!\n");
    return 1;
    }
  write(sprintf("Next alarm removed with %d seconds left.\n",timeleft));
  return 1;
  } 

int read_tab(string str) {
  if (str!="tag") {
    notify_fail("Read what?\n");
    return 0;
    }
  write("To set a new alarm, use 'alarm set <seconds> <msg>'.\n"+
	"To cancel the next alarm, use 'alarm cancel'.\n");
  return 1;
  }

string query_long() {
  string longdesc;
  mixed  *clock_outs;
  int i;

  longdesc="\nIt's a MordacAlarm clock with all the extras. You notice a little\n"+
    "tag with operating instructions on it. Maybe you should read it?\n\n"+
          "Current alarms:\n";
  clock_outs=filter_array(call_out_info(),"fil_clock_outs",this_object());
  if (!sizeof(clock_outs))
    return longdesc+"   None.\n\n";
  for (i=0;i<sizeof(clock_outs);i++)
    longdesc+=sprintf("\n%3d:%6d s >>> %s",i+1,clock_outs[i][2],clock_outs[i][3][0]);
  return longdesc+"\n\n";
  }

int fil_clock_outs(mixed *out_info) {
  if (out_info[0]==this_object())
    return 1;
  return 0;
  } 

void sound_alarm(mixed args) {
  tell_object(args[1],"The world echoes with the sound of a MordacAlarm clock:\n"+
	      "    ###  "+args[0]+"  ###\n\n\b");
  }
