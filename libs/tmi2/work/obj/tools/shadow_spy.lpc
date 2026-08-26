// The shadow spy. It tells you what objects are being shadowed by what
// other objects and gives you some leeway to alter that.
// Rather old. I believe it was originally written by Tarod, although the
// comment that made me think that is gone now. It survived until November
// 1992 without a header, when Mobydick@TMI-2 added this one.

#include <mudlib.h>

inherit OBJECT ;
 
int show (string str, object u_obj) ;
int dest_shadows (string str) ;
object find_shadowed_player (string str) ;
void create() {
	set ("short", "Shadow Spy") ;
	set ("id", ({"show","spy"}) ) ;
	set ("long", "This item shows who is using shadows.\n");
	set ("mass", 50) ;
	set ("bulk", 20) ;
}

void init() {
 add_action("view","sview");
 add_action("show_shadows","sv");
 add_action("dest_shadows","Sdest");
 add_action("alert_sdest","sdest");
 add_action("dest_spec_shadow","rms");
 add_action("help","help");
}
 
int help (string str) {
 if (str!="show" && str!="spy" && str!="shadow") return 0 ;
 
write("Shadow Spy (TM) - v1.0\n");
write("sv             :  Show all shadows on all users logged in.\n");
write("sview <user>   :  See shadows on a specific user.\n");
write("sdest <user>   :  Destruct all shadows on a specific user.\n");
write("Sdest <user>   :  Silent sdest.\n");
write("rms <user> <#> :  Remove shadow <#> from specified user.\n");
return 1;
}
 
int show_shadows() {
  object *u;
  string name;
int i;
write("Shadow Spy (TM)  - by Tarod (To keep you guys in line.) :-)\n");
    u=users();
    i=0;
        while(i<sizeof(u)){
	  name=u[i]->query("cap_name") ;
          if(!name)name="logon";
          show(name,u[i]);
	     i+=1;
	     }
	write("\n");
    return 1;
	}
 
int get () { return 1; }
 
int show (string str, object u_obj) {
object obj;
 
string fn;
write(capitalize(str)+":    \t");
 obj=shadow(u_obj,0);
  if (!obj) {write("Not Shadowed\n"); return 1;}
  fn = file_name(obj);
  write("Shadowed by:  "+fn+"\n");
   obj=shadow(obj,0);
  while (obj) {
	write("Muliple Shadows:   **  \t"+file_name(obj)+"\n");
	obj=shadow(obj,0);
    }
 return 1;
}
 
int view (string str) {
object obj;
string fn;
if (find_shadowed_player(str)) {
write(capitalize(str)+":     \t");
  obj=shadow(find_shadowed_player(str),0);
  if (!obj) {write("Not Shadowed\n"); return 1;}
  fn = file_name(obj);
  write("Shadowed by:  "+fn+"\n");
 obj=shadow(obj,0);
  while (obj) {
	write("Multiple Shadows:   **  \t"+file_name(obj)+"\n");
	obj=shadow(obj,0);
    }
	return 1;
}
write("Find shadows on who?\n");
return 1;
}
 
int alert_sdest (string str) {
object target;
 
    target=find_shadowed_player(str);
    if (!target) { write("sdest:  target not found\n"); return 1; }
    if (environment(target)==environment(this_player())) {
        write("You tear the shadows from "+
            capitalize((string)target->query("cap_name"))+".\n");
        say(capitalize((string)this_player()->query("cap_name"))+
            " tears the shadows from "+
            capitalize((string)target->query("cap_name"))+".\n");
        }
     else {
        write("You tear the shadows from "+
		capitalize((string)target->query("cap_name"))+".\n");
        tell_object(target,capitalize((string)this_player()->query("cap_name"))+
              " tears your shadows from you.\n");
        }
     dest_shadows(str);
return 1;
}
 
int dest_shadows (string str) {
object obj, n_obj;
string fn;
if (find_shadowed_player(str)) {
write(capitalize(str)+":\t");
  obj=shadow(find_shadowed_player(str),0);
  if (!obj) {write("Not Shadowed\n"); return 1;}
  fn = file_name(obj);
  write("Shadowed by:  "+fn);
  n_obj=obj;
  obj=shadow(obj,0);
  destruct(n_obj);
  write(" <- Destructed!\n");
  while (obj) {
    write("Multiple Shadows:   **  \t"+file_name(obj));
      n_obj=obj;
      obj=shadow(obj,0);
    destruct(n_obj);
write(" <- Destructed!\n");
}
	return 1;
}
write("Dest shadows on who?\n");
return 1;
}
 
object find_shadowed_player (string str) {
object *u;
int i;
string name;
    if (!str || str == "") return 0;
    u=users();
    i=0;
        while(i<sizeof(u)){
	  name=u[i]->query("cap_name") ;
          if(!name)name="logon";
          if (capitalize(name)==capitalize(str)) return u[i];
	     i+=1;
	     }
 return 0;
}
 
/* This function seems not to be doing anything... It's commented out.

dest_guild_shadows() {
object *u;
int i;
string name;
u=users();
    i=0;
        while(i<sizeof(u)){
          name=u[i]->query("cap_name");
          if(!name)name="logon";
          clean_shadows(u[i]);
	     i+=1;
	     }
 return 1;
}

*/
 
int dest_spec_shadow (string str) {
object obj, n_obj;
string fn, who;
int snum, count;
if (sscanf(str,"%s %d",who,snum)!=2) {
        write("Shadow Spy:  Invalid Paramaters\n");
        return 1;
    }
if (find_shadowed_player(who)) {
write(capitalize(str)+":\t");
  obj=shadow(find_shadowed_player(who),0);
  if (!obj) { write("Not Shadowed\n"); return 1; }
  fn = file_name(obj);
  count=1;
  write("Shadowed by:  "+fn);
  n_obj=obj;
  obj=shadow(obj,0);
  if (count==snum) {
    destruct(n_obj);
    write(" <- Destructed!\n");
    }
  else write(" <- Ignored.\n");
  while (obj) {
    write("Multiple Shadows:   **  \t"+file_name(obj));
      n_obj=obj;
      obj=shadow(obj,0);
      count++;
      if (count==snum) {
            destruct(n_obj);
            write(" <- Destructed!\n");
        }
       else write(" <- Ignored.\n");
}
	return 1;
}
write("Dest shadow on who?\n");
return 1;
}
 
