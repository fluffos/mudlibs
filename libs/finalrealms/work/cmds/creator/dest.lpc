/* 
 * Externalize by Baldrick june '97.
 */

#include <standard.h>
#include <cmd.h>
inherit CMD_BASE;
inherit WIZ_CMD_BASE;

void setup(){

position = 1;
}

/* This is for querying about objects who don't want to be destructed */
nosave object discard_obj;

nosave object *dest_obj; 
nosave int objn, majd;

void ask_dest(object me) {
    if (!pointerp(dest_obj) || objn >= sizeof(dest_obj)) {
	write("No more things to dest.\n");
	dest_obj = 0;    /* wipe array to free memory */
	return;
    }
    write("Dest object " + desc_object(dest_obj[objn]) + " ? ");
    input_to("dest_answer", me);
    return;
} /* ask_dest() */

void dest_answer(string s, object me)
{
    string err, shrt;

    if (affirmative(s)) {
	if (majd) {
	    shrt = (string)dest_obj[objn]->short();
	    err = catch(dest_obj[objn]->dwep());
	    handle_error(err, "DWEP");
	    if (dest_obj[objn]) {
		write("It REALLY doesn't want to be dested.\n");
		err = catch(destruct(dest_obj[objn]));
		handle_error(err, "destruct()");
	    }
	    majd = 0;
	    if (dest_obj[objn]) write("It didn't dest.\n");
	    else {
		say((string)me->query_cap_name()+" disintegrates "+
		  (shrt ? shrt : "something") +".\n"); 
		write("Ok.\n");
	    }
	    objn++;
	    ask_dest( me );
	    return;
	} else {
	    err = catch(dest_obj[objn]->dest_me());
	    handle_error(err, "dest_me");
	    if (dest_obj[objn]) {
		write("This object does NOT want to be dested.  Are you sure? ");
		majd = 1;
		input_to("dest_answer", me );
		return;
	    } 
	    write("Ok.\n");
	    objn++;
	    ask_dest( me );
	    return;
	}
    } else if (s == "q" || s == "quit") {
	write("Ok.  No more objects will be destd.\n");
	dest_obj = 0;
	return;
    }
    write("Ok.  Not destd.\n");
    objn++;
    ask_dest( me );
    return;
} /* dest_answer() */

protected int cmd(string str, object me) {
    object *ob;
    int i;
    string qstr, err, shrt, dobj;

    dest_obj = ({ });

    if (!str) 
      {
      write("Who did you ask me to dest?\n");
      return 1;
      }
 
    notify_fail("Can't find " + str + " to dest.\n");

    if (sscanf(str, "query %s", qstr) == 1) {
	dest_obj = wiz_present(qstr, me);
	if (!sizeof(dest_obj)) return 0;
	objn = 0;
	majd = 0;	/* MAJOR dest needed */
	ask_dest( me );
	return 1;
    }

    ob = wiz_present(str, me);
    if (!sizeof(ob)) return 0;

    for (i = 0; i < sizeof(ob); i++) 
    {
	if(interactive(ob[i]) && (sizeof(ob) !=1 || "/secure/master"->high_programmer(geteuid(ob[i]))))
	{
	    write("You DON'T destruct " + ob[i]->query_cap_name() + ".\n");
	    continue;
	}
	catch(shrt = (string)ob[i]->short());
	dobj = desc_object(ob[i]);

	if( ob[i]->query_cap_name() && environment(ob[i]) )
          {
	  log_file("MISC",(string)me->query_cap_name() + 
              " dests "+ob[i]->query_cap_name()+
	      " from "+environment(ob[i])->query_name()+" file " +
              file_name(environment(ob[i]))+"\n");
	  event(users(), "inform", (string)me->query_cap_name() + 
               " dests "+ob[i]->query_cap_name()+ " from " + 
               environment(ob[i])->query_name()+" file " + 
               file_name(environment(ob[i])), "dest");  
          }

	err = catch(ob[i] -> dest_me());
	handle_error(err, "dest_me");
	if (ob[i]) 
	    dest_obj += ({ ob[i] });
	else 
	{
	    write("You destruct " + dobj + ".\n");
	    say((string)me->query_cap_name()+" disintegrates "+
	      (shrt ? shrt : "something") + ".\n"); 
	}
    }
    if (sizeof(dest_obj) > 0) {
	objn = 0;
	majd = 0;
	ask_dest( me );
	return 1;
    }
    me->set_trivial_action();
    return 1;
} /* dest() */


