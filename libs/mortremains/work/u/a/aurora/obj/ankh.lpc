// ankh.c (and ankh2.c) were coded by Aurora
// on Circle 12/94
// code borrowed from Tarshen (rose.c)
//code borrowed from Corwin (rose.c)
 
#include <std.h>
inherit OBJECT;
 
mixed *query_auto_load(){
	return({"/wizards/aurora/obj/ankh", ({}) });
}
 
void init(){
   ::init();
	add_action("ankhup","ankhup");
	add_action("ankh", "ankh");
}
 
void create(){
   seteuid(getuid());
	set_name("brass ankh");
	set_id( ({"ankh", "brass ankh"}) );
       set_property("keep", "aurora");
	set_short("A gorgeous brass ankh (worn)");
   set_long(
" %^BOLD%^%^WHITE%^This is a gorgeous %^YELLOW%^brass ankh%^WHITE%^, an Egyption symbol for life.\n"+
"%^BOLD%^%^WHITE%^It shimmers and slightly glows as you gaze at it's beauty.\n"+
"%^BOLD%^%^WHITE%^Type \"%^GREEN%^ankh help%^WHITE%^\" for more information."
	   );
   set_weight(100);
   set_value(0);
	}
 
int ankh(string str){
   string command, name, me;
   object who;
   if(!str){
	notify_fail("What did you want to do with the ankh?\n");
      return 0;
   }
   if(sscanf(str, "%s %s", command, name)==2){
      if(find_player(name)) who = find_player(name);
      else {
         notify_fail("That player isn't logged on.  Sorry.\n");
         return 0;
      }
   }
   else {
      command = str;
      name = "NIL";
   }
   me = (string)this_player()->query_cap_name();
   if(command=="help"){
      write(
@TEXT
 
%^RED%^============================%^GREEN%^ Commands %^RED%^============================

%^BOLD%^%^WHITE%^The following commands should be issued in the syntax %^CYAN%^ankh <command> <player>

%^BOLD%^%^YELLOW%^hug    grin    drool    ribbit    wink    smile    ack    blush
%^BOLD%^%^YELLOW%^	dis    kiss    smack    massage    lick    nibble    bop

%^BOLD%^%^WHITE%^The following commands should be issued in the syntax %^CYAN%^ankh <command>

%^BOLD%^%^GREEN%^    who %^BLUE%^[Lists users online who have a ankh]
%^BOLD%^%^GREEN%^    update %^BLUE%^[Updates your ankh to the latest version]

%^RED%^======================================================================
%^%^BOLD%^%^BLUE%^This is a magical ankh coded by Aurora.  If you would like to see more funtions
added, ask Aurora very nicely, and perhaps she will add them. *grin*
 
TEXT
	  );
     if(wizardp(this_player())){
       write(
@TEXT
Wizard commands:
	Sorry, this isn't working right now.  =)
TEXT
	   );
      }
      return 1;
   }
   if(command=="smack"){
      if(name=="NIL"){
         notify_fail("You must give a player name with that command.\n");
         return 0;
      }
	tell_player(who, me+" appears from the mist and smacks you across the face!\n");
      write("You smack "+who->query_cap_name()+" across the face!  Better run!");
      return 1;
   }
   if(command=="kiss"){
      if(name=="NIL"){
         notify_fail("You must give a player name with that command.\n");
         return 0;
      }
	tell_player(who, me+" appears from the mist and softly kisses you on the cheek.\n");
      write("You kiss "+who->query_cap_name()+" softly on the cheek from afar.");
      return 1;
   }
   if(command=="grin"){
      if(name=="NIL"){
         notify_fail("You must give a player name with that command.\n");
         return 0;
      }
      tell_player(who, me+" appears in front you and gives you a really cheezy grin.\n");
      write("You give "+who->query_cap_name()+" a really cheezy grin from afar.");
      return 1;
   }
   if(command=="ack"){
      if(name=="NIL"){
         notify_fail("You must give a player name with that command.\n");
         return 0;
      }
      tell_player(who, me+" acks at you from afar.\n");
      write("You ack at "+who->query_cap_name()+" from afar.");
      return 1;
   }
   if(command=="blush"){
      if(name=="NIL"){
         notify_fail("You must give a player name with that command.\n");
         return 0;
      }
      tell_player(who, me+" blushs at you from afar.\n");
      write("You blush at "+who->query_cap_name()+" from afar.");
      return 1;
   }
   if(command=="smile"){
      if(name=="NIL"){
         notify_fail("You must give a player name with that command.\n");
         return 0;
      }
      tell_player(who, me+" appears from the mist and smiles in your direction.\n");
      write("You smile at "+who->query_cap_name()+" from afar.");
      return 1;
   }
   if(command=="drool"){
      if(name=="NIL"){
         notify_fail("You must give a player name with that command.\n");
         return 0;
      }
	tell_player(who, me+" appears from the mist and drools all over yer hot bod!\n");
      write("You drool all over "+who->query_cap_name()+"'s hot bod!");
      return 1;
   }
   if(command=="dis"){
      if(name=="NIL"){
         notify_fail("You must give a player name with that command.\n");
         return 0;
      }
      tell_player(who, me+" appears in front you, stares at you and then blatantly disses you and then vanishes!\n");
      write("You blatantly dis "+who->query_cap_name()+"!  How rude!");
      return 1;
   }
   if(command=="massage"){
      if(name=="NIL"){
         notify_fail("You must give a player name with that command.\n");
         return 0;
      }
	tell_player(who, me+" appears from the mist behind you, massages the tension from your shoulders and kisses you softly on the cheek.\n");
      write("You massage the tension from "+who->query_cap_name()+"'s shoulders.");
      return 1;
   }
   if(command=="wink"){
      if(name=="NIL"){
         notify_fail("You must give a player name with that command.\n");
         return 0;
      }
	tell_player(who, me+" winks at you with a sparkle from afar.\n");
      write("You wink at "+who->query_cap_name()+" from afar.");
      return 1;
   }
   if(command=="ribbit"){
      if(name=="NIL"){
         notify_fail("You must give a player name with that command.\n");
         return 0;
      }
      tell_player(who, me+" steps from the shadows dressed in a frog suit and\nsays to you 'RIBBIT!'.\n");
      write( "You ribbit like a frog at "+who->query_cap_name()+".");
      return 1;
   }
	if(command=="lick"){
	    if(name=="NIL"){
		notify_fail("You must give a player name with that command.\n");
		return 0;
	    }
	    tell_player(who, me+" appears from the shadows and licks you all over.\n");
	    write( "You lick " +who->query_cap_name()+ " all over from afar.");
	    return 1;
	}
	if(command=="nibble"){
	    if(name=="NIL"){
	    notify_fail("You must give a player name with that command.\n");
		return 0;
	    }
	    tell_player(who, me+" appears from the shadows and nibbles gently on your ear.\n");
	    write( "You nibble on " +who->query_cap_name()+ " from a far.\n");
	    return 1;
	}
   if(command=="hug"){
      if(name=="NIL"){
         notify_fail("You must give a player name with that command.\n");
         return 0;
      }
      tell_player(who, me+" appears from the shadows and gives you a tender hug.\n");
      write( "You send a tender hug to " +who->query_cap_name()+ ".");
      return 1;
   }
if(command=="bop"){
   if(name=="NIL"){
      notify_fail("You must give a player name with that command.\n");
      return 0;
   }
   tell_player(who, me+" appears from the mist and bops you over the head!\n");
   write( "You bop " +who->query_cap_name()+ " over the head!");
   return 1;
}
   if(command=="update"){
      write("You get the latest copy of the ankh.");
	new("/wizards/aurora/obj/ankh")->move(this_player());
      this_object()->remove();
      return 1;
   }
   if(command=="who"){
      int x;
      object group;
 
	write("These people have ankhs: (names in the () are toggled)");
      for(x=0;x<sizeof(users());x++){
         group = users()[x];
         if((string)group->query_cap_name()!="Someone"){
		if(present("ankh", group) && !present("oankh", group)){
               write(" "+group->query_cap_name());
            }
		if(present("ankh", group) && present("oankh", group)){
               write("("+group->query_cap_name()+")");
            }
         }
      }
      return 1;
   }
   notify_fail(
"Sorry...the magical ankh doesn't support that command at the moment.\n"+
"Send mail to Aurora and maybe she'll add it for you.\n"
              );
   return 0;
}
 
int drop(){
	write("You can't drop your ankh!");
   return 1;
}
 
int give(){
	write("you can't give your ankh away!");
   return 1;
}
 
int agive(string str){
   if(!wizardp(this_player())){
      notify_fail("This can only be done by wizards.\n");
      return 0;
   }
   if(!str || !find_living(str)){
	    notify_fail("Who did you want to give an ankh to?\n");
      return 0;
   }
	  if(present("ankh", find_living(str))){
	    notify_fail("That player already has an ankh.\n");
      return 0;
   }
	write("You give "+find_player(str)->query_cap_name()+" a beautiful brass ankh.");
	say(this_player()->query_cap_name()+ "sends a beautiful brass ankh to "+find_player(str)->query_cap_name());
	tell_player(find_player(str), "A brass ankh forms from a glowing mist and ties itself around your neck with a black cord.");
	new("/wizards/aurora/obj/ankh")->move(find_player(str));
   return 1;
}
 
