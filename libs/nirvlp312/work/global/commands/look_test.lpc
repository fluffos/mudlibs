inherit "basic/create";

#include <describe.h>
#include <grammar.h>
#include <prop/room.h>
#include <prop/item.h>
#include <prop/player.h>
#include <event.h>
#include <message.h>
#define MAX_ITEMS 40

void create() {
  listen_event("look");
  set_global_listening_event("look",1);
}

varargs string
look_at_room(object room,status brief,status combined,object who) {
  mixed *inv;
  string result, tmp;
  // test for test_dark() added by Ugh Jun-26-1995
  if (who ? who->test_dark(room) : query_light(room)<=0)
    return "It is too dark to see.\n";
  if (!brief)
    result = room->long();
  else {
    tmp = room->query_property(P_LOCAL_PREPOSITION);
    result = (describe(room,0,DESCRIBE_FULL+DESCRIBE_WITH_STATE) ||
              "somewhere");  // Alfe 96-Mar-18
    result = tmp? tmp+" "+result : result;
  }
  if (!(result && stringp(result)))
    result="";
  else if (brief)
    result=capitalize(result+".\n");
  if (brief && !room->query_property(P_NO_EXITS_IN_BRIEF) &&
      stringp(tmp=room->query_exit_long(1)) && strlen(tmp))
    result+=tmp+".\n";
  inv=all_inventory(room)-({ who });  // do not look at oneself, if given
  if (combined)
    inv=describe_list(inv,ARTICLE_A,DESCRIBE_FULL+DESCRIBE_WITH_STATE);
  else
    inv=(map(inv,#'describe,ARTICLE_A,DESCRIBE_FULL+DESCRIBE_WITH_STATE)-
         ({ 0 }));
  if (sizeof(inv)) {
    result+=implode(map(inv[0..MAX_ITEMS],#'capitalize),".\n")+".\n";
    if (sizeof(inv)>MAX_ITEMS)
      result+="*** TRUNCATED ***\n";
  }
  return result;
}

varargs string
look_at_environment(object whose,status brief) {
  return look_at_room(environment(whose),brief,
                      whose->query_property(P_COMBINED),whose);
}

string
look_at_thing (object who, object ob, string id)
{
    string result;
    mixed *inv;
    if (who->test_dark())
        return "It is too dark to see.\n";
#if 1
//  /bin/standard wants to know which was the last item the player looked
//  at to handle the look-failure properly. Carador, Jul-96

    if (ob == environment(who)) who->set_last_referenced("item", id);
#endif
    result = ob->long(id);
    if (!result || !stringp(result))
        result = "";
    inv = all_inventory (ob);
#if 0
    result += implode (map_objects (inv, "extra_look")+({""}), ".\n");
// changed by Carador, Dec-95 to allow objects to return messages
// as extra_looks.
#else
    result += implode (map (
      inv,
      lambda( ({ 'x, 'el }),
              ({ #'?,
                 ({ #'pointerp,
                    ({ #'=, 
                       'el, 
                       ({ #'call_other, 'x, "extra_look" })
                    }),
                 }),
 // added #'capitalize and #'[..-part below  Alfe 96-Feb-21
                 ({ #'capitalize,
                    ({ #'message2string,
                       ({ #'[.., 'el, 0 }),
                       who
                    })
                 }),
                 'el
              })
           )
      ) + ({""}), ".\n"
    );
#endif
    if (ob == environment(who) || 
        !first_inventory(ob) || 
        ob->hide_inventory (id) || 
        ob->query_fakeitem_id (id))
      return result;
    if (who->query_property (P_COMBINED))
        inv = describe_list(inv, ARTICLE_A, DESCRIBE_FULL+DESCRIBE_WITH_STATE);
    else
        inv = map (inv, #'describe, ARTICLE_A,
                         DESCRIBE_FULL+DESCRIBE_WITH_STATE) - ({0});
    if (!sizeof (inv))
        return result;
    if (living(ob))
        result += "  "+
            capitalize(message2string(({ M_PRONOUN, ob, 
                                         M_VERB, "are", ob }), who)) +
            " carrying";
    else if (ob->query_property(P_SURFACE))
        result += "  On "+(ob->query_objective()||"it")+   // Carador, May-96
                  " you can see";
    else
        result += "  "+capitalize(ob->query_pronoun()||"it")+
                  " contains";
    if (who->query_property(P_ADD_INVENTORY))
    {
      result += ":\n";
      result += implode (map (inv[0..MAX_ITEMS], #'capitalize), ".\n")+
		".\n";
      if (sizeof (inv) > MAX_ITEMS)
	  result += "*** TRUNCATED ***\n";
    }
    else
      result += " something.\n";
    return result;
}

int do_action(string action,mapping args)
{
    mixed *inv, h;
    int i, size;
    object ob;
    switch (action) {
    case "examine_all":
        args[G_INDIRECT,1] = args[G_ALL,1][0];
        size = args[G_ALL,1][1] || sizeof (args[G_ALL]);
        for (i = 0; i < size; i++)
        {
            args[G_INDIRECT] = args[G_ALL][i];
            do_action ("examine", args);
        }
        return 1;
    case "look":
    case "see":
        send_event("look", ([ E_AGENT: this_player(),
                              E_TARGET: environment(this_player()),
                              E_TYPE: action ]),environment(this_player()));
        return 1;
    case "show":
        send_event("look",([ E_AGENT: this_player(),
                             E_TARGET: args[G_LIVING],
                             E_OBJECT: args[G_IN_INVENTORY],
                             E_ID: args[G_IN_INVENTORY,1],
                             E_TYPE: action ]),environment(this_player()));
        return 1;
    case "examine_place":
        args = ([ G_INDIRECT: environment(this_player()); 0 ]);
        return do_action("examine", args);
    case "examine":
        send_event("look",([ E_AGENT: this_player(),
                             E_TARGET: args[G_INDIRECT],
                             E_ID: args[G_INDIRECT,1],
                             E_TYPE: action ]),environment(this_player()));
        return 1;
    case "weigh":  // Alfe 96-May-10
        send_event("look",([ E_AGENT: this_player(),
                             E_TARGET: args[G_IN_INVENTORY],
                             E_ID: args[G_IN_INVENTORY,1],
                             E_TYPE: action ]),environment(this_player()));
        return 1;
    case "inventory":
	if (args[G_ALL])
	  h = args[G_ALL][0..args[G_ALL,1][1]-1];
	else
	  h = ({this_player()});
        send_event("look",([ E_AGENT: this_player(),
			     E_TARGET: h,
                             E_TYPE: action ]),environment(this_player()));
        return 1;
    case "toggle_combined":
        if (this_player()->query_property (P_COMBINED))
        {
            this_player()->remove_property (P_COMBINED);
            write ("Combined short descriptions turned off.\n");
        }
        else
        {
            this_player()->set_property (P_COMBINED);
            write ("Combined short descriptions turned on.\n");
        }
        break;
    case "toggle_inventory":
        if (this_player()->query_property(P_ADD_INVENTORY))
        {
            this_player()->remove_property(P_ADD_INVENTORY);
            write ("Adding of inventory turned off.\n");
        }
        else
        {
            this_player()->set_property(P_ADD_INVENTORY);
            write ("Adding of inventory turned on.\n");
        }
        break;
    default:
        return 0;
    }
    return 1;
}

string
look_at_inventory(mixed ob)
{
  int i,j;
  string description, s;
  mixed h;
  if (this_player()->test_dark())
    return "It is too dark to see.\n";
  description = "";
  if (objectp(ob))
    ob = ({ ob });
  for (j = sizeof(ob); j; j--)
  {
    if (ob[<j]->hide_inventory())
      h = "You can't see it.\n";
    else
    {
      h = all_inventory(ob[<j]);
      if (this_player()->query_property(P_COMBINED))
	h = describe_list(h, ARTICLE_A, 
			  DESCRIBE_FULL+DESCRIBE_WITH_STATE+
			  DESCRIBE_WITH_INVENTORY);
				      // Ugh Jul-17-1996
      else
	h = map(h,#'describe,ARTICLE_A,
		      DESCRIBE_FULL+DESCRIBE_WITH_STATE)-({ 0 });
      for (i=sizeof(h); i--;)
	h[i] = capitalize(h[i]+".\n");
      if (sizeof(h))
	h = sprintf("%-78#s\n",implode(h,""));
    }
    if (h && sizeof(ob) > 1)
    {
      description += "\n";
      s = describe(ob[<j],ARTICLE_THE,DESCRIBE_SHORT,-1);
      if (s)
	description += capitalize(s)+":\n";
      description += h;
    }
    else if (sizeof(ob) < 2)
      description += "Nothing.\n";
  }
  return description;
}

void
receive_event(mapping e, string type, int prio)
{
  int i, j;
  mixed h;
  mixed agent;
  string description;
  if (e[E_HANDLED])
    return;
  e[E_HANDLED]=1;  // we will handle it now
  agent=e[E_AGENT];
  switch (type) {
  case "look":
    switch (e[E_TYPE]) {
    case "look":
    case "see":
      h=agent->query_property(P_DISPLAY_WIDTH) || 79;
      tell_object(agent,
                  break_string(look_at_room(e[E_TARGET],(e[E_TYPE]=="see"),
                                            agent->query_property(P_COMBINED),
                                            agent),h));
      break;
    case "inventory":
      description =
	with_player(agent,#'look_at_inventory,({e[E_TARGET],agent}));
      tell_object(agent,description);

#if 0
      if (agent->test_dark())
      {
        write("It is too dark to see.\n");
        return;
      }
      description = "";
      for (j = sizeof(e[E_TARGET]); j; j--)
      {
	if (!with_player(agent,#'call_other,({e[E_TARGET][<j],"short"}))) ||
	  continue;
	if (with_player(agent,#'call_other,
			({e[E_TARGET][<j],"hide_inventory"})))
	  h = "You can't see it.\n";
	else
	{
	  h = all_inventory (e[E_TARGET][<j]);
	  if (agent->query_property (P_COMBINED))
	      h = describe_list(h, ARTICLE_A, 
				DESCRIBE_FULL+DESCRIBE_WITH_STATE+
				DESCRIBE_WITH_INVENTORY);
					    // Ugh Jul-17-1996
	  else
	      h = map(h,#'describe,ARTICLE_A,
			    DESCRIBE_FULL+DESCRIBE_WITH_STATE)-({ 0 });
	  for (i=0; i<sizeof(h); i++)
	      h[i] = capitalize(h[i]+".\n");
	  if (sizeof(h))
	    h = sprintf("%-78#s\n",implode(h,""));
	}
	if (h && sizeof(e[E_TARGET]) > 1)
	{
	  description += "\n"+
	    capitalize(describe(e[E_TARGET][<j],ARTICLE_THE,
				  DESCRIBE_SHORT,-1))+":\n";
	  description += h;
	}
	else if (sizeof(e[E_TARGET]) < 2)
	  description += "Nothing.\n";
      }
#endif

      tell_object(agent,description);
      break;
    case "show":
      if (e[E_OBJECT]->query_fakeitem_id(e[E_ID]))
        send_message(({ M_PL,M_PL_VERB,"show",M_PL_POSSESSIVE," ",e[E_ID],
                        " to ",M_OBJECT,e[E_TARGET],"." }));
      else
        send_message(({ M_PL,M_PL_VERB,"show",M_PL_POSSESSIVE,M_OBJECT,M_NONE,
                        e[E_OBJECT]," to ",e[E_TARGET],"." }));
      h=e[E_TARGET]->query_property(P_DISPLAY_WIDTH) || 79;
      tell_object(e[E_TARGET],
                  break_string(with_player(e[E_TARGET],#'look_at_thing,
                                           ({ e[E_TARGET],e[E_OBJECT],
                                              e[E_ID] })) || "",h));
      break;
    case "examine":
      if (description=look_at_thing(agent,e[E_TARGET],e[E_ID])) {
        h=agent->query_property(P_DISPLAY_WIDTH) || 79;
        if (!call_resolved(&h,agent,"tell_more",break_string(description,h)))
          tell_object(agent,break_string(description,h));
      }
      break;
    case "weigh":  // Alfe 96-May-10
      send_message(({ M_PL,M_PL_VERB,"weigh",M_PL_POSSESSIVE,M_NONE,
                      e[E_TARGET],"." }));
      if (e[E_TARGET]->query_weight() || e[E_TARGET]->query_encumbrance())
        send_message(({ M_WRITE,"It seems to have weight, yes." }));
      else
        send_message(({ M_WRITE,"You cannot feel any weight." }));
      break;
    default:
      return;
    }
  default:
    return;
  }
}
