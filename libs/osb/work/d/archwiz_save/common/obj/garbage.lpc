/*
** The ultimate garbage-collector
** Idea: Several HLPs
** Author: Thragor@Nightfall, 14oct96
** Update: Analena@Nightfall, 18feb97
*/

#include <search.h>
#include <config.h>
#include <properties.h>

#define ME this_object()
#define TP this_player()
#define STR "/obj/lib/string"
#define SF(x) #'x //'
#define SYM(x) 'x //'
#define CL_PROGN #', //'

inherit "/std/thing";

public void create()
{
  (::create());
  SetIds(({"dustbin","bin"}));
  SetAds(({"small"}));
  Set(P_AUTOOBJECT,1);
  SetShort("a small dustbin");
  SetLong("This is a very small dustbin. You hardly can guess what you "
	  "might put in such a small dustbin. You don't even know if your "
	  "small finger would fit into it. Well, perhaps all this is just "
	  "a bad joke, but there's a yellow label at one side of "
	  "the dustbin.\n"
	  "The dustbin is autoloading.\n");
  SetHelpMsg("Knock at dustbin!\n");
  AddSubDetail(({"label","yellow label"}),
	       "Black letters are painted on it, hard to read. Seems as "
	       "if someone who can hardly write wrote them:\n"
	       "  'KNoCk oT DUstbIn'\n");
  AddSubDetail(({"black letters","letters"}),
	       "They must have been written by someone, who can't write "
	       "very well.\n");
  AddSubReadMsg(({"label","yellow label","black letters","letters"}),
		"You read something like: 'KNoCk oT DUstbIn'. It seems to "
		"say that you should knock at the dustbin.\n");
  SetNoDrop("To get rid of the dustbin, toss the dustbin itself.\n");
  SetWeight(0);
  SetValue(1032);
  SetInfo("(c) by Nightfall-City Recycling Center\n");
  SetNoise("You hear some strange noises from inside.\n");
  SetSmell("Uuugh. Ever smelled at a rotten banana?\n");
}

public void init()
{
  (::init());
  add_action("cmd_knock","knock");
  add_action("cmd_toss","toss");
  add_action("cmd_stoss","stoss");
}

protected varargs int NotifyFail(mixed ownmsg,mixed envmsg)
{
  mixed ownfun,envfun;
  object pl;
  closure wrap_fun;
  
  if (!pl = TP) return 0;
  wrap_fun = symbol_function("wrap",STR);
  
  if (!ownmsg&&!envmsg) return 0;

  if (pointerp(ownmsg))
    ownfun = ({SF(see),quote(map(ownmsg,wrap_fun))});
  else
    if (stringp(ownmsg))
      ownfun = ({SF(write),STR->wrap(ownmsg)});
    else
      ownfun = 0;
  
  if (pointerp(envmsg))
    envfun = ({SF(show_room),environment(pl),
               quote(map(envmsg,wrap_fun)),SYM(({pl}))});
  else
    if (stringp(envmsg))
      envfun = ({SF(tell_room),environment(pl),STR->wrap(envmsg),
                 SYM(({pl,}))});
    else
      envfun = 0;
  
  return notify_fail(lambda(0,({CL_PROGN,ownfun,envfun})),
		     NOTIFY_NOT_VALID),0;
}

protected varargs int NotifySuccess(mixed ownmsg,mixed envmsg)
{
  mixed ownfun,envfun;
  object pl;
  closure wrap_fun;
  
  if (!pl = TP) return 1;
  wrap_fun = symbol_function("wrap",STR);

  if (!ownmsg&&!envmsg) return 0;

  if (pointerp(ownmsg))
    ownfun = ({SF(see),quote(map(ownmsg,wrap_fun))});
  else
    if (stringp(ownmsg))
      ownfun = ({SF(write),STR->wrap(ownmsg)});
    else
      ownfun = 0;
  
  if (pointerp(envmsg))
    envfun = ({SF(show_room),environment(pl),
               quote(map(envmsg,wrap_fun)),SYM(({pl}))});
  else
    if (stringp(envmsg))
      envfun = ({SF(tell_room),environment(pl),STR->wrap(envmsg),
                 SYM(({pl}))});
    else
      envfun = 0;
  
  return funcall(lambda(0,({CL_PROGN,ownfun,envfun}))),1;
}

protected varargs string Name(object ob,status cap)
{
  string res;
  if (!ob)
    res ="something";
  else if (!living(ob))
    res = ob->Short()||ob->QueryShort()||"something";
  else
    res = ob->QueryName()||ob->Short()||ob->QueryShort()||"someone";
  return cap?capitalize(res):res;
}

private void call_scene(int nr)
{
  closure wrap_fun;
  object env;
  int next;
  if (!TP||!environment(TP)) return;
  wrap_fun = symbol_function("wrap",STR);
  env = environment(TP);
  switch(nr)
    {
    case 1:
      NotifySuccess(({"The lid of the dustbin moves and suddenly is open. "
		      "A small green creature pops out of it.\n",
		      "Something moves in your inventory and makes some "
		      "metal noises.\n"}),
		    ({"The lid of "+add_gen(Name(TP))+" dustbin moves and "
		      "suddenly is open. A small green creature pops out "
		      "of it.\n",
		      "You hear some metal noises.\n"})
		    );
      next = 5;
      break;
    case 2:
      show_room(environment(TP),map(
		({"The creature says: Hi, "+Name(TP)+"! My name is Oscar "
		  "and I'm at your service. If you want me to take some "
		  "pieces of your rubbish lying around in your environment, "
		  "just type 'toss <item> into dustbin' and if you want me to "
		  "act quiet and fast use 'stoss <item>'. But please don't "
		  "ask me to give anything back. I always keep what is mine!\n",
		  "A small voice says: Hi, "+Name(TP)+"! My name is Oscar "
		  "and I'm at your service. If you want me to take some "
		  "pieces of your rubbish lying around in your environment, "
		  "just type 'toss <item> into dustbin'. and if you want me to "
		  "act quiet and fast use 'stoss <item>'. But please don't "
		  "ask me to give anything back. I always keep what is mine!\n"
		}),wrap_fun)
	       );
      next = 15;
      break;
    case 3:
      NotifySuccess(({"Oscar turns around and dives back into his domain. "
		      "The lid of the dustbin closes.\n",
		      "Something seems to move in your inventory and then "
		      "you hear those strange metal noises again.\n"
		    }),
		    ({"Oscar turns around and dives back into his domain. "
		      "The lid of the dustbin closes.\n",
		      "You hear those strange metal noises again.\n"
		    })
		   );
      return;
    }
  call_out(SF(call_scene),next,++nr);
}  

public int cmd_knock(string str)
{
  if (!TP||!sscanf(lower_case(str||""),"at %s",str))
    return notify_fail("Knock AT what? Knock at dustbin?\n",
		       NOTIFY_NOT_OBJ),0;
  if (search(TP,str,SEARCH_INV|SM_IGNLIGHT|SM_OBJECT)!=ME)
    {
      if (search(TP,str,SEARCH_ENV|SM_IGNLIGHT|SM_OBJECT)==ME)
	return notify_fail("You first have to take the dustbin.\n",
			   NOTIFY_NOT_VALID),0;
      return notify_fail("Knock at dustbin or what?\n",NOTIFY_NOT_OBJ),0;
    }
  call_out(SF(call_scene),5,1);
  return NotifySuccess("You knock at the dustbin. Immediatly you hear some "
		       "strange noises coming from inside.\n",
		       ({Name(TP,1)+" knocks at a small dustbin. Suddenly "
		         "you hear some strange noises comming from it.\n",
			 "You hear someone knocking on metal and immediately "
			   "afterwards you hear some strange noises.\n"})
		       );
}

public int toss_self()
{
  NotifySuccess(({"The dustbin explodes as it tries to toss itself. You hear "
		  "a last faint scream which seems to come from Oscar. Then it "
		  "is silent again...\n",
		  "You feel an explosion in your inventory and you hear a "
		  "last faint scream which seems to come from Oscar. Then it "
		  "is silent again.\n"
		}),
		({"The dustbin explodes as it tries to toss itself. You hear "
		  "a faint scream from somewhere and then it is silent again.\n",
		  "You hear an explosion and a faint scream afterwards. Then "
		  "it is silent again.\n"
		})
		);
  remove();
}

// Emergency fix : Softbyte 24.11.96
int correctobs(object ob,object pl)
{
  //if ( (environment(ob)!=pl) && (environment(ob)!=environment(pl))) return 1;
  if (environment(ob)&&living(environment(ob))&&environment(ob)!=pl) return 1;
  return 0;
}
public void get_objects(string what,object *obs,object *notget)
{
  mixed m;
  int i,error;

  m = searchm(TP, what, SEARCH_ENV_INV|SM_MULTI|SM_IGNLIGHT|SM_REALLY) || ({});
  obs = m[FOUND_SINGLE] || ({});
  if (sizeof(m[FOUND_CLASS]))
    {
      for (i = 0; i < sizeof(m[FOUND_CLASS]); i++)
	if (sizeof(m[FOUND_CLASS][i]))
	  {
	    obs -= m[FOUND_CLASS][i][0..0];
	    obs += m[FOUND_CLASS][i][0..0];
	  }
    }
  if (sizeof(m[FOUND_MULTI]))
    {
      for (i = 0; i < sizeof(m[FOUND_MULTI]); i++)
	{
	  if (sizeof(m[FOUND_MULTI][i]) < 2)
	    continue;
	  error = m[FOUND_MULTI][i][0];
	  if (!error)
	    error = sizeof(m[FOUND_MULTI][i])-1;
	  obs -= m[FOUND_MULTI][i][1..error];
	  obs += m[FOUND_MULTI][i][1..error];
	}
    }

  notget = filter_objects(obs,"QueryNoGet");
  m = filter(obs,SF(living));
  notget = notget-m+m;
  m = filter_objects(obs,"Query",P_AUTOOBJECT);
  notget = notget-m+m;
// Emergency fix : Softbyte 24.11.96
  m = filter(obs,#'correctobs,this_player());
  notget = notget-m+m;
}

public void complete_remove(object ob)
{
  object *inv;
  if (!ob) return;
  inv = deep_inventory(ob);
  if (sizeof(filter(inv,SF(query_once_interactive))))
    return;
  filter_objects(inv,"remove");
  filter(inv-({0}),SF(destruct));
  if (!ob) return;
  ob->remove();
  if (ob) destruct(ob);
}

public void item_remove(object *obs)
{
  filter(obs,SF(complete_remove));
}

public int toss_scene(int nr,mixed par)
{
  object *obs,*notget;
  string *pmsg,*emsg,msg;
  closure wrap_fun;
  
  if (!TP) return 0;
  wrap_fun = symbol_function("wrap",STR);
  switch(nr)
    {
    case 1:
      if (search(TP,par,SM_IGNLIGHT|SEARCH_INV|SM_OBJECT)==ME)
	return toss_self();
      get_objects(par,&obs,&notget);
      if (!sizeof(obs))
	return NotifySuccess(({"The lid of the dustbin moves and suddenly is "
			       "open. Oscar pops out of it and says: "
			       "Hey, "+Name(TP)+"! Are you crazy or what? "
			       "I just dreamed of a wonderful smelling heap of "
			       "shit and you call me because of nothing. I "
			       "don't see "+par+" here.\n",
			       "Something moves in your inventory and makes "
			       "some metal noises. Suddenly you hear a small "
			       "voice from your inventory saying: Hey, "+
			       Name(TP)+"! Are you crazy or what? I just "
			       "dreamed of a wonderful smelling heap of shit "
			       "and you call me because of nothing. I don't "
			       "see "+par+" here.\n"
			     }),
			     ({"The lid of "+add_gen(Name(TP))+" dustbin "
			       "moves and suddenly is open. A small green "
			       "creature pops out of it saying: Hey, "+Name(TP)+
			       "! Are you crazy or what? I just dreamed of a "
			       "wonderful smelling heap of shit and you call "
			       "me because of nothing. I don't see "+par+
			       "here.\n",
			       "You hear some metal noises and afterwards a "
			       "small voice saying: Hey, "+Name(TP)+
			       "! Are you crazy or what? I just dreamed of a "
			       "wonderful smelling heap of shit and you call "
			       "me because of nothing. I don't see "+par+
			       "here.\n"
			     })
			    );
      pmsg = ({"The lid of the dustbin moves and suddenly is "
	       "open. Oscar pops out of it and says: Hi, "+Name(TP)+"! ",
	       "Something moves in your inventory and makes "
	       "some metal noises. Suddenly you hear a small "
	       "voice from your inventory saying: Hi, "+Name(TP)+"! "
	     });
      emsg = ({"The lid of "+add_gen(Name(TP))+" dustbin "
	       "moves and suddenly is open. A small green "
	       "creature pops out of it saying: Hi, "+Name(TP)+"! ",
	       "You hear some metal noises and afterwards a "
	       "small voice saying: Hi, "+Name(TP)+"! "});
      if (!sizeof(obs-notget))
	return NotifySuccess(({pmsg[0]+"Hm. Very nice, indeed, but "
			       "I can't take "+par+".\n",
			       pmsg[1]+"Hm. Very nice, indeed, but I can't "
			       "take "+par+".\n"
			     }),
			     ({emsg[0]+"Hm. Very nice, indeed, but I can't "
			       "take "+par+".\n",
			       emsg[1]+"Hm. Very nice, indeed, but I can't "
			       "take "+par+".\n",
			     }));
      obs = obs-notget;
      if (sizeof(obs)>1)
	if (sizeof(notget))
	  msg = "These items are great! I'm sad that I can't take all "
	        "of them. One moment please.\n";
	else
	  msg = "These items are great! One moment please.\n";
      else
	if (sizeof(notget))
	  msg = "These items are great! I'm sad that I can only take one "
	        "of them. One moment please.\n";
	else
	  msg = "This item is great! One moment please.\n";
      pmsg[0]+=msg;
      pmsg[1]+=msg;
      emsg[0]+=msg;
      emsg[1]+=msg;
      pmsg[0]+="Oscar dives back into the dustbin.\n";
      pmsg[1]+="You feel something moving in your inventory.\n";
      emsg[0]+="The creatures dives back into the dustbin.\n";
      call_out(SF(toss_scene),5,2,obs);
      return NotifySuccess(pmsg,emsg);
    case 2:
      par-=({0});
      if (sizeof(par)>1)
	show_room(environment(TP),map(
		  ({"Suddenly the dustbin grows and a tongue comes out "
		    "of it, collecting all items. The tongue turns back "
		    "again, the dustbin closes and you hear a slight "
		    "'burp'.\n",
		    "You hear some strange noises, as if a dog is "
		    "drinking some water and then some metal noises and "
		    "a slight 'burp' afterwards.\n"
		  }),wrap_fun));
      else if(sizeof(par))
	show_room(environment(TP),map(
		  ({"Suddenly the dustbin grows slightly and a tongue comes "
		    "out of it, collecting "+par[0]->QueryShort()+". The "
		    "tongue turns back "
		    "again, the dustbin closes and you hear a slight "
		    "'burp'.\n",
		    "You hear some strange noises, as if a dog is "
		    "drinking some water and then some metal noises and "
		    "a slight 'burp' afterwards.\n"
		  }),wrap_fun));
      else
      {
        show_room(environment(TP),map(
                  ({"Suddenly the dustbin grows slightly and a tongue comes "
                    "out of it. It seems to be searching for something, "
                    "poking in the air, but can't find anything. Finally, it "
                    "turns back again, the dustbin closes and you hear "
                    "someone grumbling inside.\n",
                    "You hear some strange noises, as if a dog is "
		    "drinking some water and then some metal noises and "
		    "finally someone grumbling.\n"
		  }),wrap_fun));
        return 1;
      }
      call_out(SF(toss_scene),8,3);
      item_remove(par);
      return 1;
    case 3:
      return NotifySuccess("Your dustbin burps.\n",
			   add_gen(Name(TP,1))+" dustbin burps.\n");
    }
}

public int fast_toss(string objs)
{
  object *obs,*notget;
  string *descr;
  
  if (!TP) return 0;
  if (search(TP,objs,SM_IGNLIGHT|SEARCH_INV|SM_OBJECT)==ME)
    return toss_self(),1;
  get_objects(objs,&obs,&notget);
  if (!sizeof(obs))
    return notify_fail("Can't find "+objs+" to toss.\n",
		       NOTIFY_NOT_VALID),0;
  obs = obs-notget;
  if (!sizeof(obs))
    return notify_fail("Can't find 'tossable' "+objs+".\n",
		       NOTIFY_NOT_VALID),0;
  descr = map_objects(obs,"Short");
  item_remove(obs);
  obs-=({0});
  if (sizeof(obs))
    {
      notget+=obs;
      descr-=map_objects(obs,"Short");
    }
  write("Tossed: "+implode(descr,", ")+".\n");
  show(TP->QueryName()+" tosses "+implode(descr,", ")+".\n",TP);
  descr = map_objects(obs,"Short")-({0,""});
  if (sizeof(descr))
    write("Couldn't get: "+implode(descr,", ")+".\n");
  return 1;
}

public int cmd_toss(string str)
{
  string objs;
  if (!TP||sscanf(lower_case(str||""),"%s into %s",objs,str)!=2)
    return notify_fail("Toss what into what?\n",
		       NOTIFY_NOT_OBJ),0;
  if (search(TP,str,SEARCH_INV|SM_IGNLIGHT|SM_OBJECT)!=ME)
    {
      if (search(TP,str,SEARCH_ENV|SM_IGNLIGHT|SM_OBJECT)==ME)
	return notify_fail("You first have to take the dustbin.\n",
			   NOTIFY_NOT_VALID),0;
      return notify_fail("Toss something into dustbin or what?\n",
			 NOTIFY_NOT_OBJ),0;
    }
  call_out(SF(toss_scene),5,1,objs);
  return NotifySuccess("You knock at the dustbin and say: Oscar! I've some "
		       "food for you. Would you like to have "+objs+"?\n",
		       ({Name(TP,1)+" knocks at a small dustbin and says: "
			 "Oscar! I've some food for you. Would you like to "
			 "have "+objs+"?\n",
			 "You hear some noises as if someone is knocking on "
			 "metal and afterwards someone says: Oscar! I've some "
			 "food for you. Would you like to have "+objs+"?\n"
		       })
		       );
}

public int cmd_stoss(string str)
{
  string objs,intowhat;
  if (!TP||sscanf(lower_case(str||""),"%s into %s",objs,intowhat)!=2)
    objs = str;
  else if (search(TP,intowhat,SEARCH_INV|SM_IGNLIGHT|SM_OBJECT)!=ME)
    {
      if (search(TP,str,SEARCH_ENV|SM_IGNLIGHT|SM_OBJECT)==ME)
	return notify_fail("You first have to take the dustbin.\n",
			   NOTIFY_NOT_VALID),0;
      return notify_fail("Toss something into dustbin or what?\n",
			 NOTIFY_NOT_OBJ),0;
    }
  return fast_toss(objs);
}
