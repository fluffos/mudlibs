/*--------------------------------------------------------------------------
 * /p/daemons/bank_d.c  --  The main bank account manager
 *
 * Copyright (C) 1997 by One Step Beyond.
 * All Rights Reserved.
 * Permission granted for non-commercial use.
 *--------------------------------------------------------------------------
 */

inherit "/lib/number";

#include <secure/wizlevels.h>
#include <config.h>
#include <money.h>

#define BANK_DATA "/save/daemons/bank"
#define BANKLOG "finance/BANK"
#define BANK_CHECK 20 // bank-accounts to check during 1 reset
#define A_DATA 4      // how many data are hold in the accounts-mapping

public mapping accounts;
// ([name:amount;created;last_deposit;last_withdraw])

private nosave string curr_account; // the current player to check
                                    // if the account might be deleted

public varargs void LoadAccounts(int force)
{
//  if (sizeof(accounts)&&!force) return;
  restore_object(BANK_DATA);
}

public void SaveAccounts()
{
  save_object(BANK_DATA);
}

public void create()
{
  if (clonep())
  {
    destruct(this_object());
    return;
  }
  seteuid(getuid());
  accounts = m_allocate(0, A_DATA);
  LoadAccounts();
  if (accounts&&sizeof(m_indices(accounts))&&!curr_account)
    curr_account = m_indices(accounts)[0];
}

private int player_exists(string player)
{
  return stringp(find_savefile(player))||objectp(find_player(player));
}

private void log_action(string what)
{
  string po,tp,ti;
  if (this_player())
    tp = capitalize(getuid(this_player()));
  else
    tp = "(none)";
  if (this_interactive())
    ti = capitalize(getuid(this_interactive()));
  else
    ti = "(none)";
  if (previous_object())
    po = object_name(previous_object());
  else
    po = "(none)";
  log_file(BANKLOG,"\n"+ctime()+" "+what+"\n [TP: "+tp+", TI: "+ti+
           ", PO: "+po+"]\n");
}

private void create_accounts()
{
  if (sizeof(accounts)) return;
  accounts = m_allocate(0,A_DATA);
}

public int HasAccount(string player)
{
  if (!accounts)
    return 0;
  return member(accounts,player);
}

public int has_account(string player) // comp.
{
  return HasAccount(player);
}

public mapping QueryAccounts()
{
  return accounts;
}

public int SetAccount(string player,int amount)
{
  int dif;

  if (amount<0) return 0;
  if (!player_exists(player)) return 0;
  create_accounts();
  if (!HasAccount(player))
  {
    accounts[player,A_CREATED] = time();
    log_action("account of "+capitalize(player)+" created ("+
               to_string(amount)+" CU)");
  }
  else
    if (dif = amount-accounts[player,A_AMOUNT])
      if (  (this_player()&&getuid(this_player())!=player)
          ||(this_interactive()&&getuid(this_interactive())!=player)
          ||this_player()!=this_interactive())
        log_action("balance of "+capitalize(player)+" changed ("+
                   to_string(accounts[player,A_AMOUNT])+
                   ((sign(dif)==-1)?" - ":" + ")+
                   to_string(abs(dif))+" = "+
                   to_string(amount)+" CU)");
  accounts[player,A_AMOUNT] = amount;
  accounts[player,dif>0?A_DEPOSIT:A_WITHDRAW] = time();
  SaveAccounts();
  return 1;
}

public int set_account(string player,int amount) // comp.
{
  return SetAccount(player,amount);
}

public int QueryAccount(string player)
{
  if (!HasAccount(player)) return -1;
  return accounts[player,A_AMOUNT];
}

public int query_account(string player) // comp.
{
  return QueryAccount(player);
}

public int AddAccount(string player,int amount)
{
  if (!player_exists(player)) return 0;
  create_accounts();
  if (!HasAccount(player))
    return SetAccount(player,amount);
  else
    return SetAccount(player,accounts[player,A_AMOUNT]+amount);
}

public int add_account(string player,int amount) // comp.
{
  return AddAccount(player,amount);
}

public mapping QueryFullAccount(string player)
{
  mapping result;

  if (!HasAccount(player)) return 0;
  result = m_allocate(0,A_DATA);
  result[player,A_AMOUNT] = accounts[player,A_AMOUNT];
  result[player,A_CREATED] = accounts[player,A_CREATED];
  result[player,A_DEPOSIT] = accounts[player,A_DEPOSIT];
  result[player,A_WITHDRAW] = accounts[player,A_WITHDRAW];
  return result;
}

public mixed *query_full_account(string player) // comp.
{
  mapping result;

  if (!result = QueryFullAccount(player)) return 0;
  return ({result[player,A_AMOUNT],
           ctime(result[player,A_DEPOSIT]),
           ctime(result[player,A_WITHDRAW])});
}

public int create_account(string player) // comp.
{
  return AddAccount(player,0);
}

public int CloseAccount(string player)
{
  int amount;
  if (!HasAccount(player)) return -1;
  amount = accounts[player,A_AMOUNT];
  accounts = m_delete(accounts,player);
  log_action("account of "+capitalize(player)+" closed ("+
             to_string(amount)+" CU)");
  SaveAccounts();
  return amount;
}

public int close_account(string player) // comp.
{
  return CloseAccount(player);
}

public void reset()
{
  string *idx,*delet;
  int i,curpos,lastpos,size;

  if (!accounts) return;
  if (!size = sizeof(idx = m_indices(accounts))) return;
  if (!HasAccount(curr_account))
    curr_account = idx[0];
  curpos = member(idx,curr_account);
  if ((lastpos = curpos+BANK_CHECK)>size) lastpos = size;
  delet = ({});
  for (i=curpos;i<lastpos;i++)
    if (!player_exists(idx[i]) || IS_IMMORTAL(idx[i]))
      delet+=({idx[i]});
  for (i=0;i<sizeof(delet);i++)
    CloseAccount(delet[i]);
  if (lastpos == sizeof(idx))
    curr_account = 0;
  else
    curr_account = idx[lastpos];
  SaveAccounts();
}
