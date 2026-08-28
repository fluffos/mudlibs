/* Majik 4 server
 * Copyright (C) 1998, 1999  Majik Development Team <majik@majik.netti.fi>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

inherit LIVING;

#define TRANSACTION_FEE 1

mapping accounts;

/*
 string owner = "null";
int own_bkpng, own_bnkng, own_accng, own_curcy, own_bounus;*/

void
keeper (string str)
{
   "/command/mortal/say"->main(str);
}

/*
 void
 t_keeper(string str)
{
  "/command/mortal/tell"->main(str);
}
 */

int
do_withdraw (string str)
{
   int c;
   
   if (!str)
	 {
		keeper (({ 
		   "How much do you want to withdraw?",
		   "Could you please specify how much do you want money?" 
		})[random(2)]);
		return 1; 
    }

   if (!accounts[THIS->query_true_name()])
	 {
		keeper (({
		   "You don't have an account here!",
		   "I don't know you, buzz off!",
		   "You should deposit some money before trying to withdraw."
		})[random(3)]);
		return 1;
	 }

  if (!accounts[THIS->query_true_name()][0])
    {
	   keeper (({
		  "Your account doesn't not contain any money.",
		  "You have no money on your account."
	   })[random (2)]);
	   return 1;
    }
   
   if (str == "all")
	 c = accounts[THIS->query_true_name()][0];
   else
	 c = to_int(str);
   
   if (accounts[THIS->query_true_name()][0] < c)
    {
	   keeper ("You don't have that much money on your account!");
	   return 1;
    }
   
   if (c > THOB->query_money())
	 {
		keeper ("We are sorry, but the bank doesn't have that much money available right now.");
		return 1;
    }
   
   if ((accounts[THIS->query_true_name()][0]-c) < TRANSACTION_FEE)
	 {
        if (THIS->query_money() < TRANSACTION_FEE)
          {
			 keeper ("You don't have enough money for transaction fee of "+TRANSACTION_FEE+" gps.");
			 return 1;
          }
		
        THIS->add_money (-TRANSACTION_FEE);
	 }
   else
	 {
		accounts[THIS->query_true_name()][0] -= TRANSACTION_FEE;
	 }
   
   THOB->add_money (-c + TRANSACTION_FEE);
   
   accounts[THIS->query_true_name()][0] -= c;

   keeper ("There you have it!");
   message (CMD_SEE, THOB->query_gridx(), THOB->query_gridy(), VISIBLE_RADIUS/2,
			"$N1 {hand} some money for $n2.", MAPENV(THOB), ({ THOB, THIS }));

  save_object (base_name(THOB));
  return 1;
}

int
do_deposit (string str)
{
   int c;
   
   if (!str)
	 {
		keeper (({
		   "Please specify how much do you want to deposit.",
		   "Be more specific! Deposit what?",
		   "How much do you want to deposit?"
		})[random (3)]);
		
		return 1;
	 }
   
   if (str == "all")
	 c = THIS->query_money();
   else
	 c = to_int (str);
   
   if (!c || c < 1)
	 {
		keeper (({
		   "Please specify how much do you want to deposit.",
		   "Be more specific! Deposit what?",
		   "How much do you want to deposit?"
		})[random (3)]);
		return 1;
	 }
   
   if (c > THIS->query_money())
	 {
		keeper ("You don't have that much money.");
		return 1;
	 }
   
   if (!accounts[THIS->query_true_name()])
	 {
		accounts[THIS->query_true_name()] = ({ c, 0 });
	    THOB->add_money (c);
		THIS->add_money (-c);
		keeper (({
		   "Ah, a new customer! Thank you.",
		   "Thank you. Use your account wisely!" 
		})[random(2)]);
		message (CMD_SEE, THIS->query_gridx(), THIS->query_gridy(), VISIBLE_RADIUS/2,
				 "$N1 hands some money for $n2.", MAPENV(THOB), ({ THIS, THOB }));
		save_object (base_name (THOB));
		return 1;
	 }
   
   if (accounts[THIS->query_true_name()][1])
	 {
      if (c >= accounts[THIS->query_true_name()][1])
		  {
		   THOB->add_money (c);
		   THIS->add_money (-c);
		   
		   c = (c - accounts[THIS->query_true_name()][1]);
		   accounts[THIS->query_true_name()][1] = ({ c, 0 });
		   
		   keeper ("Thank you. All of your loan is now paid.");
		   message (CMD_SEE, THIS->query_gridx(), THIS->query_gridy(), VISIBLE_RADIUS/2,
					"$N1 hands some money for $n2.", MAPENV(THIS), ({ THIS, THOB }));
		   
		   save_object (base_name (THOB));		   
		   return 1;
        }
      else
        {
		   THOB->add_money (c);
		   THIS->add_money (-c);
		   
		   accounts[THIS->query_true_name()][1] -= c;
		   
		   keeper ("You pay on your loan.");
		   message (CMD_SEE, THIS->query_gridx(), THIS->query_gridy(), VISIBLE_RADIUS/2,
					"$N1 hands some money for $n2.", MAPENV(THOB), ({ THIS, THOB }));
		   
		   save_object (base_name (THOB));
		   return 1;
        }
	 }
   
   accounts[THIS->query_true_name()][0] += c;
   THOB->add_money (c);
   THIS->add_money (-c);
   
   keeper ("Thank you. All of your "+c+" gold pieces are now on your account.");
   message (CMD_SEE, THIS->query_gridx(), THIS->query_gridy(), VISIBLE_RADIUS/2,
			"$N1 hands some money for $n2.", MAPENV(THIS), ({ THIS, THOB }));
   
   save_object (base_name (THOB));
   return 1;
}

int
do_balance ()
{
   if (!accounts[THIS->query_true_name()])
	 {
		keeper (({
		   "See balance on what? You don't have an account!",
		   "You don't seem to have an account.",
		   "You have no account.",
		   "Deposit some money first!" 
		})[random(4)]);
				
		return 1;
	 }
   
   message (CMD_MSG, 0,0,0, sprintf ("You have money worth %.2f gold pieces stored in this bank.",
									 to_float(accounts[THIS->query_true_name()][0]/1.0)), THIS);
   
   if (accounts[THIS->query_true_name()][1])
	 message (CMD_MSG, 0,0,0, sprintf ("You have taken loan worth %.2f gold pieces in total.",
									   to_float(accounts[THIS->query_true_name()][1]/1.0)), THIS);
   else
	 message (CMD_MSG, 0,0,0, "You are free of loan.", THIS);
   
   return 1;
}

int
do_loan ()
{
   keeper (({
	  "We don't allow loans, yet!",
	  "No loans allowed. Be back later!"
	  })[random(2)]);
   return 1;
}

int
do_transfer (string what)
{
   keeper (({
	  "We don't allow transfers, yet!",
	  "No transfers allowed. Be back later!"
   })[random(2)]);
   return 1;
   
   /*
   
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
	*/
}

void
create ()
{
   ::create();
   
   if (!restore_object (base_name (THOB)) || !accounts)
	 accounts = ([ ]);
   
   THOB->create_bank();
   THOB->set_no_clean_up(1);
   
   THOB->add_command ("deposit", file_name(THOB) + "->do_deposit");
   THOB->add_command ("withdraw", file_name(THOB) + "->do_withdraw");
   THOB->add_command ("balance", file_name(THOB) + "->do_balance");
   THOB->aad_command ("transfer", file_name(THOB) + "->do_transfer");
   THOB->add_command ("loan", file_name(THOB) + "->do_loan");
}

/*
 *  Contract code for merchants
 *    ++ Pook
 */


/*
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
*/
