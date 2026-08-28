inherit MONSTER;

int total_money;
mapping accounts;
string owner = "null";
int own_bkpng, own_bnkng, own_accng, own_curcy, own_bounus;


void
keeper (string str)
{
  "/command/mortal/say"->main(str);
}

void
t_keeper(string str)
{
  "/command/mortal/tell"->main(str);
}

do_withdraw (string str)
{
  int c;

  if (!str)
    {
      notify_fail ("Usage: withdraw <amount | all>\n");
      return 0; 
    }

  if (!accounts[THIS->query_true_name()])
    {
      write ("You have no account.\n");
      return 1;
    }

  if (!accounts[THIS->query_true_name()][0])
    {
      write ("You have no money on your account.\n");
      return 1;
    }

  if (str == "all")
    c = accounts[THIS->query_true_name()][0];
  else
    c = to_int(str);

  if (accounts[THIS->query_true_name()][0] < c)
    {
      write ("You don't have that much money on your account!\n");
      return 1;
    }     

  if (c > total_money)
    {
      write ("We are sorry, but the bank doesn't have that much money available right now.\n");
      return 1;
    }
if (THIS->query_true_name() != owner)
{
    if ((accounts[THIS->query_true_name()][0]-c) < 30)
      {
        if (THIS->query_money() < 30)
          {
            write ("You don't have enough money for transaction fee of 30 cps.\n");
            return 1;
          }

        THIS->add_money (-30);
      }
  else
    {accounts[THIS->query_true_name()][0] -= 30;}

  if(owner != "null")
          {
            own_bounus = ((own_bkpng+own_bnkng+own_accng+own_curcy)*0.05);
            accounts[owner][0] += own_bounus;
          }
}
  total_money -= c;
  total_money += 30;
  accounts[THIS->query_true_name()][0] -= c;
  THIS->add_money (c);

  write ("You receive money worth "+c+" copper pieces in total.\n");
  act (THIS, "$n withdraws some money.\n", 0, THIS);
  save_object (base_name(THOB));

  return 1;
}

do_deposit (string str)
{
  int c;

  if (!str)
    {
      notify_fail ("Usage: deposit <amount | all>\n");
      return 0;
    }

  if (str == "all")
    c = THIS->query_money();
  else
    c = to_int (str);

  if (!c || c < 1)
    {
      write ("Usage: deposit <amount | all>\n");
      return 1;
    }

  if (c > THIS->query_money())
    {
      write ("You don't have that much money.\n");
      return 1;
    }

  if (!accounts[THIS->query_true_name()])
    {
      accounts[THIS->query_true_name()] = ({ c, 0 });
      total_money += c;
      THIS->add_money (-c); 
      write ("You deposit money worth "+c+" copper pieces in total.\n");
      act (THIS, "$n deposits some money.", 0, THIS);
      save_object (base_name (THOB));
      return 1;
    }

  if (accounts[THIS->query_true_name()][1])
    {
      if (c >= accounts[THIS->query_true_name()][1])
        {
          total_money += c;
          THIS->add_money (-c);
          c = (c - accounts[THIS->query_true_name()][1]);
          accounts[THIS->query_true_name()][1] = ({ c, 0 });
          THIS->set ("loan", 0);

          write ("You pay your loan.\n");
          act (THIS, "$n deposits some money.", 0, THIS);
          save_object (base_name (THOB));

          return 1;
        }
      else
        {
          total_money += c;
          THIS->add_money (-c);

          accounts[THIS->query_true_name()][1] -= c;
          write ("You pay on your loan.\n");
          act (THIS, "$n deposits some money.", 0, THIS);
          save_object (base_name (THOB));

          return 1;
        }
    }

      accounts[THIS->query_true_name()][0] += c;
      total_money += c;
      THIS->add_money (-c);
         
      write ("You deposit money worth "+c+" copper pieces in total.\n");
      act (THIS, "$n deposits some money.", 0, THIS);
      save_object (base_name (THOB));
 
      return 1;
}

do_balance ()
{
  if (!accounts[THIS->query_true_name()])
    {
      write ("You have no account.\n");
      return 1;
    }

  write (sprintf (
    "You have money worth %.2f gold pieces stored in this bank.\n",
      to_float(accounts[THIS->query_true_name()][0]/100.0)));

  if (accounts[THIS->query_true_name()][1])
    write (sprintf (
      "You have taken loan worth %.2f gold pieces in total.\n",
        to_float(accounts[THIS->query_true_name()][1]/100.0)));
  else
    write ("You are free of loan.\n");

  return 1;
}

do_loan ()
{
  write ("We don't allow loans, yet!\n");
  return 1;
}

do_transfer (what)
{
  int amt;
  string who;
  if(!what) {
      write("Format: transfer <amount> <player>.\n"+
            "Example: transfer 100 namhas.\n");
      return 1;
  }

  if(sscanf(what,"%d %s",amt,who) != 2) {
      write("Format: transfer <amount> <player>.\n"+
            "Example: transfer 100 namhas.\n");
      return 1;
  }
  who = lower_case(who);
  if (!accounts[THIS->query_true_name()])
  {
      write ("You have no account.\n");
      return 1;
  }

  if(!accounts[who]) {
      write(capitalize(who)+" does not have an account at this bank.\n");
      return 1;
  }
  
  if((amt+30) >= accounts[THIS->query_true_name()][0]) {
      write("You don't have that much money in your account.\n");
      return 1;
  }
  else 
  {
    if (THIS->query_true_name() != owner)
     {
      if ((accounts[THIS->query_true_name()][0]-amt) < 30)
      {
        if (THIS->query_money() < 30)
          {
            write ("You don't have enough money for transaction fee of 30 cps.\n");
            return 1;
          }

        THIS->add_money (-30);
      }
    else
      {accounts[THIS->query_true_name()][0] -= 30;}

    if(owner != "null")
          {
            own_bounus = ((own_bkpng+own_bnkng+own_accng+own_curcy)*0.05);
            accounts[owner][0] += own_bounus;
          }
     }  
  total_money += 30;
      
      accounts[THIS->query_true_name()][0] -= amt;
      accounts[who][0] += amt; 
      if(find_player(who)) 
          THOB->force_us("tell "+who+" "+THIS->query_cap_name()+" transfered you "+amt);
      write("You transfer "+amt+" to "+capitalize(who)+".\n");
      return 1;
  }
      
  return 0;
}

create ()
{
  ::create();

  if (!restore_object (base_name (THOB)) || !accounts)
    accounts = ([ ]);

  THOB->create_bank();
  THOB->set_no_clean_up(1);
}

init_monster ()
{
  THOB->init_bank();
  add_action ("do_deposit", "deposit");
  add_action ("do_withdraw", "withdraw");
  add_action ("do_balance", "balance");
  add_action ("do_transfer", "transfer");
  add_action ("do_loan", "loan");
}

/*
 *  Contract code for merchants
 *    ++ Pook
 */


int forgetime;
int endtime;

init()
{
  ::init();
  add_action("do_propose","propose");
  add_action("do_forge","forge");
  add_action("do_check","check");
  
  restore_object (base_name (THOB));
  if (time() >= endtime)
    {owner = "null";}
}

do_propose(string what)
{
  if(what == "contract" && owner == "null")
    {
      keeper ("I will sign a contract with you, "+THIS->query_cap_name()+", for a price "
      + "of 15 gold florins.  Then, I will give you a considerable discount here for "
      + "the length of the contract. In return, I expect you to promote this shop and "
      + "bring in some business. It will last for a few weeks. If you agree to this, "
      + "type 'forge contract'.");
      return 1;
    }
  if(what == "contract" && owner != "null")
    {
     keeper ("I have already signed a contract with "+capitalize(owner)+".");
     return 1;
    }
}

do_forge(string what)
{
  if((THIS->query_skill_chance("banking") > 25) &&
       (THIS->query_skill_chance("bookkeeping") > 15) &&
       (THIS->query_skill_chance("accounting") > 15) &&
       (THIS->query_skill_chance("currency") > 15))
  {
  if(what == "contract" && owner != "null")
    {
      keeper ("No "+THIS->query_cap_name()+", I already have a "
       + "contract with "+capitalize(owner)+".");
      return 1;
    } 
  if(THIS->query_money() < 1500)
    {
     keeper ("A contract with me costs 15 gold florins "+THIS->query_cap_name()+", which "
     + "you do not have.");
     return 1;
    }
  if(what == "contract" && owner == "null" && THIS->query_money() >= 1500)
    {
      keeper("Great "+THIS->query_cap_name()+"! We have signed a contract which will "
       + "last for a few weeks.");
      owner = THIS->query_true_name();
      THIS->add_money(-1500);
      own_bkpng = (THIS->query_skill_chance("bookkeeping"));
      own_bnkng = (THIS->query_skill_chance("banking"));
      own_accng = (THIS->query_skill_chance("accounting"));
      own_curcy = (THIS->query_skill_chance("currency"));
      forgetime = time();
      endtime = (forgetime + 432000);
      save_object (base_name(THOB));
      return 1;
    }
  }
   else
   {
      keeper ("Sorry "+THIS->query_cap_name()+", I need someone who knows "
       + "a bit more about running a bank.");
      return 1;
    }
}

do_check(string what)
{ 
  restore_object (base_name(THOB));
  if(what == "contract" && owner != "null")
   {
    switch (432000-(time()-forgetime))
    {
      case 0..100000:
        keeper ("My contract with "+capitalize(owner)+" is almost up!.");
        break;
      case 100001..200000:
        keeper ("The contract I signed with "+capitalize(owner)+" will still be "
         + "valid for a little while.");
        break;
      case 200001..300000:
        keeper ("It will be quite a while before my contract "
         + "with "+capitalize(owner)+" is over.");
        break;
      case 300001..500000:
        keeper ("It has only been a short time since "+capitalize(owner)+" and "
         + "I forged the agreement.");
        break;
    }
    return 1;
   }
  if(what == "contract" && owner == "null")
   {
    keeper ("I do not have a contract with anyone at this "
     + "time "+THIS->query_cap_name()+".");
    return 1;
   }
  else
   {
    keeper ("You want to check what "+THIS->query_cap_name()+"?");
    return 1;
   }
}

