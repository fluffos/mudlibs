//  The donation daemon for guild halls.
 
#include <std.h>
 
inherit DAEMON;
 
private mapping __Accounts;
private string __Current_Leader;
 
void create()
{
  ::create();
  __Accounts = ([]);
  __Current_Leader = "";
}
 
void adjust_leader();
 
int add_to_account(string name, int val)
{
  if(!__Accounts || (val < 0))
    return 0;
  
  if(!__Accounts[name])
    __Accounts[name] = 0;
  
  __Accounts[name] += val;
  adjust_leader();
  return 1;
}
 
int sub_from_account(string name, int val)
{
  if(!__Accounts || (val < 0))
    return 0;
  
  if(!__Accounts[name])
    __Accounts[name] = 0;
  
  __Accounts[name] -= val;
  adjust_leader();
  return 1;
}
 
void adjust_leader()
{
  string *accs;
  string new_lead;
  int max, i, asz;
 
  max = 0;
  accs = keys(__Accounts);
  for(i = 0, asz = sizeof(accs); i < asz; i++)
    {
      if(((int)__Accounts[accs[i]]) > max)
        {
          max = (int)__Accounts[accs[i]];
          new_lead = accs[i];
        }
    }
  if(new_lead != __Current_Leader)
    {
      // announce
      __Current_Leader = new_lead;
      message("shout", "The " + __Current_Leader + 
              " now have the most donations.\n", users());
    }
}
