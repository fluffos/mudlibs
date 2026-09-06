//---------------------------------------------------------------------------
// /p/skills/throwing.c
//
// The throw skill handling of OSB
// (c) Softbyte@OSB 10nov97
// [Softbyte] 10nov97:    Basic skill handling and functions
//---------------------------------------------------------------------------

#include <config.h>
#include <properties.h>
#include <moving.h>
#include <daemons.h>
#include <msgclass.h>
#include <skills.h>
#include <math.h>
#include <combat.h>



#define TO this_object()
#define TP this_player()


// ========================= Special skill functions ========================
// ************************    Throwing     *********************************
mixed OnSucceedThrowing(object who, int skill, string arg, string extra,mixed p)
{
string dir,whom;
object ob,dest,we;
int modus;
mixed exit;
int dist,maxdist;
mixed dam;

  seteuid(getuid());
  //printf("OnSucceedThrowing:: id=%s extra=%s\n",arg||"NULL",extra||"NULL");
  if (!extra) return 0;  // wrong usage
  we=S_PO;
  modus=0;
  if (2==sscanf(extra,"%s at %s",dir,whom))
  {
    modus=2;
  }
  else if (1==sscanf(extra,"to %s",whom))
  {
    dir=0;
    modus=1;
  }
  else if (1==sscanf(extra,"at %s",whom))
  {
    dir=0;
    modus=2;
  }
  else 
  {
    dir=extra;
	whom=0;
    modus=0;
  }
  if (whom)
  {
    ob=who->CanSeeLiving(whom,-1);
  }
  else ob=0;

  // How far can we throw (-1: infinitely far, 0: this room only)
  if (p) maxdist=p[P_SK_THROW_DISTANCE];
  else maxdist=0;

  // The exit where we plan to throw
  if (dir) exit=environment(who)->QueryExit(dir);
  else exit=0;

  if (modus==0) // Throw in neighboring room
  {
    if (maxdist==0) 
	  return "You cannot throw to other rooms.\n";

    if (!exit)
	  return "You can't throw to the "+dir+".\n"; 
    else if (stringp(exit[0]))
	{
	  exit=load_object(exit[0]);
	  dist=call_other(L_DISTANCE,"dist",environment(who),exit);
	  if (dist>maxdist && maxdist>=0)
	    return "You can't throw that far.\n";
	  else 
	  {
	    // TODO
	    if (p && p[P_SK_THROW_MSG])
		{
		  // The user wants to create the output
		  funcall(p[P_SK_THROW_MSG],who,ob,arg,modus);
		}
		else
		{
	      msg_write(CMSG_GENERIC,
		     "You throw "+arg+" "+dist+"m to the "+dir+".\n"); 
	      msg_room(exit,CMSG_GENERIC,
		     capitalize(arg)+" arg is thrown in.\n",({this_player()}) );
		}
	    we->move(exit,M_GO);
      }
	}
	else 
      write("TODO: The item would be moved to the room "+dir+".\n");
  }
  else if (modus==1)
  {
    if (!ob)
	  return
	  "You don't see "+whom+" and therefore can't throw there.\n"; 
    else
	{
	  // maxdist==0 means we cannot thro to neighboring rooms
      if (maxdist==0 && environment(who)!=environment(ob))
	    return "You cannot throw to other rooms.\n";

      // distance calulation not necessary if the room is equal
      if (maxdist!=0)
	    dist=call_other(L_DISTANCE,"dist",environment(who),environment(ob));
      else
	    dist=0;

	  if (dist>maxdist && maxdist>=0)
	    msg_write(CMSG_GENERIC, "You can't throw that far.\n");
	  else
	  {
	    if (p && p[P_SK_THROW_MSG])
		{
		  // The user wants to create the output
		  funcall(p[P_SK_THROW_MSG],who,ob,arg,modus);
		}
		else
		{
	      msg_write(CMSG_GENERIC,
	        "You throw "+we->QueryShort()+" to "+whom+
			". It flies "+dist+"m.\n"); 
	      msg_object(ob,CMSG_GENERIC,
	        capitalize(we->QueryShort())+" is thrown to you.\n");
          msg_room(environment(ob),CMSG_GENERIC,
           capitalize(we->QueryShort())+" is thrown to "+ob->QueryName()+".\n",
		   ({ob,who}));
	      msg_room(environment(who),CMSG_GENERIC,
	       capitalize(we->QueryShort())+" is thrown from "+who->QueryName()+
		   ".\n",({ob,who}));
		}
        we->move(ob,M_SILENT);
		if (who==ob) 
	      msg_object(ob,CMSG_GENERIC,
		    "Throwing to yourself must be COOOOOOL...\n");
	  }
	}
  }
  else if (modus==2)
  {
    // TODO
	if (dir || environment(ob)!=environment(who) )
       return "Throwing at someone from afar is not yet implemented.\n";
    if (p) dam=p[P_SK_THROW_HITHP];
	else dam=0;
	// The user wants to calculate the damage
	if (closurep(dam)) dam=funcall(dam,arg,who,ob);

	if (p && p[P_SK_THROW_MSG])
	{
	  // The user wants to create the output
	  funcall(p[P_SK_THROW_MSG],who,ob,arg,modus);
	}
	else
	{
	  msg_write(CMSG_GENERIC,
		"You throw "+we->QueryShort()+" hard at "+whom+ ".\n"); 
	  msg_object(ob,CMSG_GENERIC,
		capitalize(we->QueryShort())+" is thrown hard at you.\n");
	  msg_room(environment(ob),CMSG_GENERIC,
	   capitalize(who->QueryName())+" throws "+we->QueryShort()+
	   " hard at "+ob->QueryName()+".\n", ({ob,who}));
	}
	we->move(environment(ob),M_SILENT);
	if (dam>0)
	{
	  // Do NOT hurt players
	  if (!ob->QueryIsPlayer())
	    ob->Defend(dam,DT_BLUDGEON,this_object());
	}
	if (who==ob) 
	  msg_object(ob,CMSG_GENERIC,
		"Hurting yourself must be a nice game...\n");
  }
  return 1;
}
mixed OnFailThrowing(object who, int skill, string arg, string extra,mixed p)
{
object ob;
int chance;
closure fun;
  if (!arg) return 0;
  seteuid(getuid());
  msg_write(CMSG_GENERIC,
  "You throw the "+arg+" but stumble and drop it.\n");
  S_PO->move(environment(who),M_DROP);
  // Check whether we shall break
  if (p)
  {
    chance=p[P_SK_THROW_BREAK_CHANCE];
	fun=p[P_SK_THROW_BREAK_FUN];
	if (fun && closurep(fun) && chance>0 && random(1000)<chance) 
	{
	  // Call the break function, where the user can do some action
	  funcall(fun,arg,who);
	}
  }
  return 1;
}

// Check whether it is possible to throw this thing
string CannotThrowing(object who,int diff,string id_str,string extra ,mixed p)
{
  if (S_PO->Query(P_NODROP))
    return "This can't be thrown.\n";
}




