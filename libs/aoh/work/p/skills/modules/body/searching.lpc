//---------------------------------------------------------------------------
// /p/skills/searching.c
//
// The searching skill handling of OSB
// (c) Softbyte@OSB 3oct97 
// V1.0:  Basic skill handling and functions
//---------------------------------------------------------------------------

#include <config.h>
#include <properties.h>
#include <moving.h>
#include <daemons.h>
#include <msgclass.h>
#include <skills.h>


#define TO this_object()
#define TP this_player()

private string ResolveVItem(string vitem,object ob)
{
mixed mx;

  if (ob || !vitem) return "";
  mx=ob->VQuery(vitem,P_SHORT);
  if (!mx) mx=ob->VQuery(vitem,P_IDS);
  if (!mx) return vitem;
  if (pointerp(mx)) mx=mx[0];
  if (!stringp(mx)) return "";
  return mx;

}

// ========================= Special skill functions ========================
// ************************    Searching     ********************************
// TODO: Searching reduced 'physical endurance'
mixed OnSucceedSearching(object who, int skill, string arg, mixed extra,mixed p)
{
int i,cnt;
mapping s_map;
mapping props;
object ob;
string err;
string *idx;
mixed mx;

// printf("On succeed serching arg=%O\n",arg);
  if (!p) // No argument given  standard handling
   return 0;

  seteuid(getuid());

  s_map=p;
  idx=m_indices(s_map);
  cnt=random(1000);
  for (i=0;i<sizeof(idx);i++)
  {
    cnt-=s_map[idx[i],2];     // propability 0..1000 to find this
    if (cnt<=0)
    {
      if (s_map[idx[i],1]>0)  // not yet empty
      {
        s_map[idx[i],1]--;
	err=catch(ob=clone_object(s_map[idx[i],0]));   // clone it
        if (err)
	{
	  msg_write(CMSG_GENERIC,"Error...please report to a wizard:\n");
	  msg_write(CMSG_ERROR,err+".\n");
	}
	else
	{
	  props=s_map[idx[i],3]; // properies
          if (props && mappingp(props)) ob->SetProperties(props);	
	  ob->move(environment(who),M_SILENT);
	  msg_write(CMSG_GENERIC,
             "You search ... and find "+(ob->QueryShort()||"something")+".\n");
	}
        return 1;                // break loop to speed up
      }
    }
  }
  mx=ResolveVItem(arg,S_PO);
  if (mx!="") mx=mx+" ";
  msg_write(CMSG_GENERIC,
     "You search "+mx+"but cannot find anything more.\n");
  return 1;
}
mixed OnFailSearching(object who, int skill, string arg, mixed extra,mixed p)
{
string mx;

  seteuid(getuid());

  mx=ResolveVItem(arg,S_PO);
  if (mx!="") mx=mx+" ";
  msg_write(CMSG_GENERIC,
     "You search "+mx+"but find nothing.\n");
  return 1;
}




