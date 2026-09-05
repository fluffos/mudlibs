inherit "/obj/treasure";
#include "/players/anshar/closed/ansi.h";
short() { return "Teller"; }

long() { write("    A teller. 'wt <msg>' to use\n"); }

id(str) { return str == "teller"; }

init() {
        add_action("wiz_tell", "wt");
}

wiz_tell(str) {
object plyr;
string who;
string what;
string myname;
if(!str) { write("Tell what?\n"); return 1; }
  if(sscanf(str,"%s %s",who,what) != 2) {
    write("Tell <who> <what>.\n"); return 1; }
    plyr = find_living(who);
    myname = capitalize(this_player()->query_real_name());
  if(!plyr) { write(capitalize(who)+" is not online now.\n");
              return 1; }
  plyr->add_tellhistory(myname + " tells you: " + what);
  tell_object(plyr, myname+" whispers to you: "+GRN+what+NORM+"\n");
 write("You whisper to "+capitalize(who)+": "+GRN+what+NORM+"\n");
return 1;
}
