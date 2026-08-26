/*
   /obj/shells/term.c
   Creator:   Leto@Earth   (5/5/94)
   Related files: _term.c , _shell.c , _chsh.c /adm/etc/shells

   BETA BETA BETA BETA BETA BETA BETA BETA BETA BETA BETA BETA BETA

  If you want to use this, PLEASE mail me at Earth or Tmi-2
  This is a very limited inefficient hack, not even idented right ;)
  I don't like the use of environment(this_object()) instead of
  this_player(), if someone know how to fix it, let me know ;)

 Based a wee little on Watchers shsh.c, but rather simple now and almost
 ready to be added to user.c instead :)


 03/03/96 - Leto made the whole thing general, instead of hardcoded mesg_classes

*/

#include <mudlib.h>
#include <ansi.h>

#undef DEBUG

inherit OBJECT ;
 
create() {
 
	set("id", ({"term shell", "shell", "termshell" , "highlighter"}) );
	set("short", "a highlighter");  
	set("long", "This is Leto's ANSI/VT100 customizable highlighter" );
	set("prevent_drop", 1);
 
	seteuid(getuid(this_object()));  /** Set object permissions **/
 
}
 
mixed query_auto_load() {
   return 1;
}
 
 
int clean_up() {  return 1;  }		// Prevent inadvertant clean_up
 
void init() {
 
	//  If the environment isn't a user ... remove the shell.
	if(environment() && !interactive(environment())) {
	  remove();  return;  }
	//  Set the shell's euid to that of the user
	seteuid(getuid(this_player()));
}
 
 
/**
 **	Mudlib Message communication relay
 **	 - Called from receive_message() in user object
 **/
 
int receive_message(string Class, string msg) {

          string tmp,tmp1;
#ifdef DEBUG
    tell_object(environment(this_object()), 
   ( environment(this_object()->query("term/tell")+Class+":"+NOR+msg));
#endif

 tmp = environment(this_object())->query("term/"+Class);
 if (tmp) 
 {
  // This bit is here to avoid having a coloured blinking cursor :)
  if(msg[<1]=='\n') msg = tmp+msg[0..<2]+NOR+"\n";
  else msg = tmp + msg + NOR ;
 }
 tell_object(environment(this_object()),msg); 
}
