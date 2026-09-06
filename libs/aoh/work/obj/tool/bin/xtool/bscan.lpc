/*
** Tool to implement the security checks of the xtool in heartbeats
** Softbyte 21sep1998
*/

#include "../bincmd.h"
#include <properties.h>
#include <msgclass.h>

inherit BASICXCMD;

#define PO previous_object()

private object *mInv,*mEnv,*mInvis,*mVars,*mSnoop;

string QueryAbrev() { return "bscan"; }
string QueryAuthor() {return "Softbyte, Sep1998";}
string QueryVersion() {return "V1.0";}

Query( string arg ) { if ( arg == "IsTool" ) return 1; else return 0; }

/* Enable use of heartbeat */
int QueryHeartbeat() {return 1;} 



int write_newobj(object obj,object who,string s) 
{
  if(obj && who && s)
    tell_object(who,"*** "+s+" "+ObjFile(obj)+"\n");
}

int write_newstr(string str,object who,string s) 
{
  object ob;
  
  if(str && who && s)
  {
    ob=VarToObj(s);
    if (ob) str=ObjFile(ob);
    else str="[$"+str+"]";
    tell_object(who,"*** "+s+" "+str+"\n");
  }
}

int write_snoop(object obj,object who,string s) 
{
  object snoop;
  string s1,s2;

  if(obj && who && s)
  {
    snoop=query_snoop(obj);
    if (snoop) s1=" by "+capitalize(getuid(snoop)||"Null");
    else s1="";
    s2=capitalize(getuid(obj)||"Null");
     
    tell_object(who,
      sprintf("*** %s%s on %s\n",s,s1,s2));
  }
}

/* Snoop check */
int is_snoopee(object who)
{
  return who&&objectp(query_snoop(who));
}



/* periodic heartbeat..return 1 to keep it running */
int HeartBeat(object owner)
{
  object *inv,*env,*invis,*vars,*snoop,*diff,*diff2;

  if (!owner) return 1;
  if (!PO) return 1;

  // In the heartbeat the variables are not set..why?
  if (!cloner) cloner=owner;
  if (!dispatcher) dispatcher=PO;

  if (PO->QueryPermData("BSCANinv") )
  {
    inv=all_inventory(owner);
    if (!mInv) mInv=inv;
    diff=inv-mInv;
    diff2=mInv-inv;
    if (sizeof(diff))
    {
      filter(diff, #'write_newobj,owner,"New object in inventory");
      mInv=inv;
    }
    if (sizeof(diff2))
    {
      filter(diff2, #'write_newobj,owner,"Object leaves inventory");
      mInv=inv;
    }
  }

  if (PO->QueryPermData("BSCANenv") )
  {
    env=all_inventory(environment(owner));
    if (!mEnv) mEnv=env;
    diff=env-mEnv;
    diff2=mEnv-env;
    if (sizeof(diff))
    {
      filter(diff, #'write_newobj,owner,"New object in environment");
      mEnv=env;
    }
    if (sizeof(diff2))
    {
      filter(diff2, #'write_newobj,owner,"Object leaves environment");
      mEnv=env;
    }
  }
    
  if (PO->QueryPermData("BSCANinvis") )
  {
    invis=filter_objects(all_inventory(environment(owner)), "QueryInvis");
    if (!mInvis) mInvis=({});

    diff=invis-mInvis;
    diff2=mInvis-invis;
    if (sizeof(diff))
    {
      filter(diff, #'write_newobj,owner,"New Invisible in environment");
      mInvis=invis;
    }
    if (sizeof(diff2))
    {
      filter(diff2, #'write_newobj,owner,"Invisible leaves environment");
      mInvis=invis;
    }
  }

  if (PO->QueryPermData("BSCANsnoop") )
  {
    snoop=filter(users(), "is_snoopee");

    if (!mSnoop) mSnoop=({});

    diff=snoop-mSnoop;
    diff2=mSnoop-snoop;
  
    if (sizeof(diff))
    {
      filter(diff, #'write_snoop,owner,"Snooping started");
      mSnoop=snoop;
    }
    if (sizeof(diff2))
    {
      filter(diff2, #'write_snoop,owner,"Snooping ended");
      mSnoop=snoop;
    }
 
  }

  if (PO->QueryPermData("BSCANvars") )
  {
    xvariables = PO->QueryTempData( "xvariables" )||([]);
    // tell_object(owner,sprintf("%O\n",xvariables));
    CheckXVariables(0,0); // for the removel of the 0 objects
    vars=m_indices(xvariables);

    if (!mVars) mVars=vars;
    diff2=mVars-vars;
    if (sizeof(diff2))
    {
      filter(diff2, #'write_newstr,owner,"Variable got destructed");
    }
    mVars=vars;
  }

  
  return 1;
}

private int IsScanmode(string str)
{
  if (!str) return 0;
  str=lower_case(str);
  if (-1==member( ({"vars","inv","env","invis","snoop"}),str ) )
    return 0;
  return 1;
}

int main(string str )
{
  string what;
  int inv,env,invis,xxx,vars,snoop;
  int onoff;

  if (CheckHelp(str)) return 1;

  onoff=-1;
  if (str && (1==sscanf(str,"%s on",what)) )
  {
    if (!IsScanmode(what)) 
      return notify_fail( "Unkown mode '"+what+"'\n" ), 0;
    onoff=1;
  }
  else if (str && (1==sscanf(str,"%s off",what)) )
  {
    if (!IsScanmode(what)) 
      return notify_fail( "Unkown mode '"+what+"'\n" ), 0;
    onoff=0;
  }
  else if (!str)
  {
    what="Scanning:\n";
    inv=QueryDispatcher()->QueryPermData("BSCANinv");
    env=QueryDispatcher()->QueryPermData("BSCANenv");
    invis=QueryDispatcher()->QueryPermData("BSCANinvis");
    vars=QueryDispatcher()->QueryPermData("BSCANvars");
    snoop=QueryDispatcher()->QueryPermData("BSCANsnoop");
    what+="  - Inventory:    "+(inv?"on":"off")+"\n";
    what+="  - Environment:  "+(env?"on":"off")+"\n";
    what+="  - Invisible:    "+(invis?"on":"off")+"\n";
    what+="  - Variables:    "+(vars?"on":"off")+"\n";
    what+="  - Snoopcheck:   "+(snoop?"on":"off")+"\n";
    "/lib/string"->SMore(what);
  }
  else
  {
    return notify_fail( 
     "bscan <vars|inv|env|invis|snoop> [on|off] or bscan\n" ), 0;
  }

  if (onoff==0 || onoff==1)
  {
    xxx=QueryDispatcher()->QueryPermData("BSCAN"+what);
    if (xxx==onoff)
    {
      write("Mode '"+capitalize(what)+"' is already "+(onoff?"on":"off")
        +".\n");
    }
    else
    {
      QueryDispatcher()->SetPermData("BSCAN"+what,onoff);
      write("Mode '"+capitalize(what)+"' is now "+(onoff?"on":"off")
        +".\n");
    }
    
  }
  return 1;
}


