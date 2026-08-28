/*      
 *      /bin/user/_look.c
 *      from the Nightmare mudlib
 *      the command to look at stuff so that you might see!
 *      written by Descartes of Borg 16 january 1993
 *      based on the _look.c from the TMI mudlib
 *      modified by Bohemund 16 march 1994
 *        - some fixes for the sky
 */

#include <daemons.h>
#include <std.h>

inherit DAEMON;
 
int examine_object(string str);
void look_msg(object ob, string str);
 
int cmd_look(string str) {
  string tmp;
  
  if(stringp(str)) {
    if(sscanf(str, "in %s", tmp) == 1 || sscanf(str, "at %s", tmp) == 1)
      return examine_object(tmp);
    else return examine_object(str);
  }
  if(!((int)this_player()->query_invis()))
    say(this_player()->query_cap_name()+" looks at "+
	possessive(this_player())+" surroundings.");
  this_player()->describe_current_room(1);
  return 1;
}
 
int examine_object(string str) {
  object ob;
  object *obs, ob_list;
  int i;
 
  if(!str) return 0;
  ob = environment(this_player());
  if(effective_light(this_player()) < 1 && str != "sky") {
    write("It is too dark.");
    return 1;
  }
  if(total_light(this_player()) < 1) write("It is dark.");
  if(ob->id(str)) {
    look_msg(ob, str);
    write((string)ob->query_long(str));
    return 1;
  }
  ob = present(str, ob);
  if(ob) {
    look_msg(ob, str);
    write((string)ob->query_long(str));
    return 1;
  }
  ob = present(str, this_player());
  if(ob) {
    look_msg(ob, str);
    write((string)ob->query_long(str));
    return 1;
  }
  write("You do not notice that here.");
  return 1;
}
 
void look_msg(object ob, string str) {
  if((int)this_player()->query_invis()) return;
  if( ob != this_player() )
    if(living(ob)) {
      say(this_player()->query_cap_name()+" looks over "+
	  ob->query_cap_name()+"", ob);
      tell_object(ob, this_player()->query_cap_name() + " looks you over.");
    }
    else say(this_player()->query_cap_name()+" looks over the "+str+".");
}
 
void help() {
  write("Command: look\nSyntax: look [at object]\n"
        "If no object is specified this command makes you look "
        "around the room.  If an object is specified it lets you "
        "examine the object more closely.\n"
        "See also: describe, lines, ansi, autowrap, brief\n");
}
