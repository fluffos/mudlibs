//---------------------------------------------------------------------------
// /p/daemons/vote_control.c
//
// A tool to check which wizards are active voters in OSB
// (c) Softbyte@OSB 8dec97
// V1.0:  Basic functions
//---------------------------------------------------------------------------

#include <properties.h>
#include <secure/config.h>
#include <secure/wizlevels.h>

inherit "/std/base";

#define SEC_PER_DAY  86400

#define VOTE_MAX_DAYS  40  // so many days are default absent time
                           // if no other argument is given


int pLastLogin,pIsNoVoter,pIsWizard;

string *GetWizards()
{
  string *w;

  w=get_dir("/players/*",1)-({})-({0})-({"."})-({".."});
  return w;
}

mixed *GetData(string wizard)
{
  int flag;
  object ob;

  if (ob=find_player(wizard)) // wizard is online
  {
    pIsNoVoter=({int})ob->QueryIsNoVoter();
    pLastLogin=time();  // now
    pIsWizard=IS_WIZARD(ob);
  }
  else
  {
    pIsNoVoter=0;
    pIsWizard=0;
    pLastLogin=0;
    catch(flag = restore_object("/" SAVEPATH+wizard[0..0]+"/"
                          + wizard));
    if (!flag) return 0;
  }
  // For future enhancement with arrays
  if (pIsNoVoter) flag=0;
  else flag=1;
  return ({wizard,pLastLogin,flag,pIsWizard});
}

mixed *GetWizardData(string *w)
{
  mixed data;
  if (!w) w=GetWizards();
  data=map(w,#'GetData /*'*/)-({})-({0});
  return data;

}

// checks whether 'w' is longer than maxdays offline or has the voting flag off
int is_voter(mixed *w,int maxdays,int t)
{
  int days;
  if (!w) return 0;
  if (w[2] == 0) return 0;   // vote flag off
  if (w[3] == 0) return 0;   // no wizard
  days=(t-w[1])/SEC_PER_DAY;
  if (days>maxdays) return 0;
  return 1;
}

mixed first_element(mixed *data)
{
  if (!data || !sizeof(data) ) return 0;
  return data[0];
}

// Called by the voteserver to determin the active voting wizards
varargs string *GetActiveWizards(string *w,int maxdays,int t)
{
  mixed data;
  data=GetWizardData(w);
  if (!t) t=time();
  if (!maxdays) maxdays=VOTE_MAX_DAYS;
  data=filter(data,#'is_voter,maxdays /*'*/,t);
  data=map(data,#'first_element /*'*/)-({})-({0});
  return data;
}

void create()
{
  ::create();
  if (is_clone()) return ;
  seteuid(getuid());
}
