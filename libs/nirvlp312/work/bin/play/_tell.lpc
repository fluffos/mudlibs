#include <ansi.h>
#include <security.h>
cmd_tell(str) {
    object ob;
    string TellColor;
    string who;
    string msg;
    string afk_str;
    if (this_player()->query_ghost()) {
  	  write("Because you are a ghost, you fail.\n");
	    return 1;
    }
    if((string)this_player()->query_real_name()=="guest"){
      write("Guest cannot send tells.\n");
      return 1;
    }
    if ((int)this_player()->query_sp() < 0) {
    	write("You are low on power.\n");
	    return 1;
    }
    if(query_verb()=="reply")
      str = (string)this_player()->Replyer() + " " + str;
    if (!str || sscanf(str, "%s %s", who, msg) != 2)
    {
	    write("Usage: 'tell <who> <msg>'\n");
	    return 1;
    }
    this_player()->set_it(who);
  
    ob=find_player(who);
    
    who=capitalize(who);
    if(!ob)ob=find_living(lower_case(who));
    if (!ob) {
	write("No player with that name.\n");
	return 1;
    }
    if (interactive(ob)) {
	if (this_player()->query_level() < ob->query_level() && ob->query_invis() >= 39) {
	    write("No player with that name.\n");
	    return 1;
	}
        if (this_player()->query_level() < GOD && in_editor(ob)) {
	    write("That person is editing. Please try again later.\n");
	    return 1;
	}
        if (this_player()->query_level() < 21 && ob->query_tellblock()) {
          write("That person is blocking tells. Please try again later.\n");
           return 1;
        }
        if((int)this_player()->query_tellblock_index(0)=="on" && ob->query_level() < 21 && (int)this_player()->query_level() < 21){
           write("You cannot use tell when tellblock is on.\n");
           return 1;
        }
      if(query_idle(ob) > 120) tell_object(this_player(), 
      capitalize(who)+
      " is idle at the moment. You may not get a response right away.\n");
      if((afk_str=ob->query_afk_message()))
        tell_object(this_player(), who+" is afk: "+afk_str+"\n");
    }
    if(!ob->query_npc() && !interactive(ob))
      write(who+" is disconnected.\n");
if(call_other(this_object(),"query_invis",0) > 20 && (int)this_player()->query_level() < 199)
  {
  write( "Don't be annoying.  Become visible before you talk to someone!\n" );
  return 1;
  }
    ob->Replyer((string)this_player()->query_real_name());
    ob->add_tellhistory((string)this_player()->query_name() + " tells you: " + msg);
msg = format(msg, 60);
    if(ob->query_level() > (int)this_player()->query_level() && (string)this_player()->query_name()=="Someone") tell_object(ob, "< "+(string)this_player()->query_real_name()+" > ");
    TellColor=ob->get_ansi_pref("tell");
    if(TellColor) tell_object(ob, TellColor + (string)this_player()->query_name() + " tells you: " + msg + "\n" + NORM);
    else tell_object(ob, (string)this_player()->query_name() + " tells you: " + msg + "\n");
    write("Ok.\n");
    write("You tell "+ob->query_name()+" "+msg+"\n");
    return 1;
}
