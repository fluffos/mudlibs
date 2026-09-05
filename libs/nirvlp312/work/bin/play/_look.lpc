/* 07/21/06 Earwax: Daemonized this */

#include <security.h>
#include <ansi.h>

#define MAX_LIST 20

varargs status cmd_look(string str, int remote) {
  object ob, ob_tmp, here;
  string item, cap_name, it;
  int max, player_killing, brief, level;
    
  if ((int)this_player()->test_dark())
  	return 1;
    	
  if(present("blindness_object", this_player()))
  {
    write("You can't see!\n");
    return 1;
  }
  
  cap_name = (string)this_player()->query_name();
  player_killing = (int)this_player()->query_pl_k();
  brief = (int)this_player()->query_brief();
  here = environment(this_player());
  level = (int)this_player()->query_level();
    
  if (!str) {
    if (remote) {
	    write((string)call_other(here, "short")); write("\n");
	  } else {
      if(brief == 2) {
        string sdec;
        string vsdec;
        string lkcol;
        int sdecl;
        sdec= (string)call_other(here, "short");
       if(!sdec) sdec="";
        sdecl = strlen(sdec);
        sdecl=40-(sdecl/2);
        if(lkcol=(string)this_player()->get_ansi_pref("roomtitle"))
          write(pad(" ",sdecl-1)+lkcol+sdec+NORM+"\n");
        else
          write(pad(" ",sdecl-1)+sdec+"\n");
      }
	    call_other(here, "long");
	  }
  	ob = first_inventory(here);
	  max = MAX_LIST;
	  while(ob && max > 0) {
	    if (ob != this_player()) {
		    string short_str;
		    short_str = (string)call_other(ob, "short");
		    if (short_str) {
		      max -= 1;
		      write(short_str + ".\n");
		      it = short_str;
		    }
	    }
	    ob = next_inventory(ob);
	  }
    if(player_killing && here
    && call_other("/obj/play/move_tracker","check_blood",object_name(here)))
      write("You detect the blood of a player killer.\n");
	    return 1;
    }
    if (sscanf(str, "at %s", item) || sscanf(str, "in %s", item) || (item = str)) {
	    item = lower_case(item);
	    ob = present(item, this_player());
      if(!ob) ob = present("_"+item+"_", this_player());
      /* security for player-made-to-order objects -Bp */
	    if (!ob && (status)call_other(here, "id", item))
	      ob = environment(this_player());
	    if (!ob)
	      ob = present(item, environment(this_player()));
	    if (!ob) {
	      write("There is no " + item + " here.\n");
	      return 1;
	    }
	    it = item;
	    call_other(ob, "long", item);
      if((status)ob->is_player() < 1  && living(ob)) 
        say(cap_name+" looks at "+(string)ob->query_name()+"\n");
      if((status)ob->is_player()) {
        if(environment(this_player())==environment(ob)){
          if(ob != this_player()) {
            tell_object(ob,cap_name+" looks at you.\n");
            say(cap_name + " looks at " + (string)ob->query_name() + "\n", ob);
          } else
            say(cap_name+" looks at "+(string)this_player()->query_objective()+"self in a reflection.\n");
        }
        if(level < EXPLORE && environment(this_player())!=environment(ob))
          tell_object(ob,cap_name+" looks at you from afar.\n");
      }
      if(present("look_block", ob)) {
        return 1;
      }
    	if ((int)call_other(ob, "can_put_and_get", item) < 1)
	      return 1;
      if (living(ob)) {
	      object special;
	      special = first_inventory(ob);
	      while (special) {
          object special2;
	        string extra_str;
          special2 = next_inventory(special);
		      extra_str = (string)call_other(special, "extra_look");
		      if (extra_str)
		        write(extra_str + ".\n");
          special = special2;
	      }
	    }
      ob_tmp = first_inventory(ob);
	    while (ob_tmp && (string)call_other(ob_tmp, "short") == 0)
	      ob_tmp = next_inventory(ob_tmp);
	    if (ob_tmp) {
	      if (living(ob)) {
          if(ob == this_player()) write("\tYou are carrying:\n");
        else
		      write("\t" + capitalize(item) + " is carrying:\n");
      }
	    else
		    write("\t" + capitalize(item) + " contains:\n");
	  }
	  max = MAX_LIST;
	  ob = first_inventory(ob);
	  while (ob && max > 0) {
	    string sh;
	    sh = (string)call_other(ob, "short");
	    if (sh)
		    write(sh + ".\n");
	    ob = next_inventory(ob);
	    max -= 1;
	  }
	  return 1;
  }
  write("Look AT something, or what?\n");
  return 1;
}
