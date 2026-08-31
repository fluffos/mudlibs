/* Do not remove the headers from this file! see /USAGE for more info. */

/* $Id: account_d.c,v 1.1 1998/01/27 23:20:44 monica Exp $
**
**  Expanded by Tsath 2020, 2021.
**  Now supports transaction logs and bank statements.
*/

inherit M_DAEMON_DATA;
inherit M_WIDGETS;

#define MAX_TRANSACTION_LOG 30
#define LOG_BANK 0
#define LOG_TEXT 1
#define LOG_MONEY 2
#define LOG_SALDO 3
#define LOG_TIME 4

private
mapping accounts = ([]);
mapping transactions = ([]);

private
string abbreviate(string s)
{
   return filter_array(s, ( : member_array($1, "eyuioa") == -1 :))[0..2];
}

private
int valid_currency(string currency)
{
   return member_array(currency, MONEY_D->query_currency_types()) != -1;
}

//: FUNCTION query_account
// This function returns the currencies stored in different accounts for
// the player (can either be a body object or a name of a player). If
// a currency is supplied then the saldo for that account is returned,
// no currency an a mapping with currencies as keys and saldos as
// values is returned.
//@ACCOUNT_D->query_account("Bean",.me)
//   ([ /* sizeof() == 2 */
//     "gold" : 75.520000,
//     "credit" : 11.746000,
//   ])
//
// Or:
//@ACCOUNT_D->query_account("Bean",.me,"gold")
//   75.520000
varargs mixed query_account(string bank, mixed player, string currency)
{
   string name;
   if (objectp(player))
      name = player->query_link()->query_userid();
   else
      name = player;

   if (!accounts[bank])
      return 0.0;
   if (!accounts[bank][name])
      accounts[bank][name] = ([]);

   if (accounts[bank][name][currency])
      return accounts[bank][name][currency];
   else
      return accounts[bank][name];
}

private
void transaction(mixed player, string bank, string what, string currency, float money)
{
   string name;
   float saldo;
   if (!valid_currency(currency))
      error("Unknown currency '" + currency + "'.");

   if (!to_int(money))
      return;
   if (objectp(player))
      name = player->query_link()->query_userid();
   else
      name = player;
   saldo = query_account(bank, name, currency);
   if (!transactions[currency])
      transactions[currency] = ([]);
   if (!transactions[currency][name])
      transactions[currency][name] = ({});
   if (sizeof(transactions[currency][name]) > MAX_TRANSACTION_LOG)
      transactions[currency][name] = transactions[currency][name][5..];

   transactions[currency][name] += ({({bank, what, money, saldo, time()})});
}

string fake_account_id(string bank, object body)
{
   string name = lower_case(body->query_name());
   return upper_case(bank[0..2]) + "-" + (bank[0] + name[0]) + "" + (bank[0] + name[1]) + "" + (bank[0] + name[2]);
}

string bank_statement(string bank, string currency, object body)
{
   string name = lower_case(body->query_name());
   string *out = ({upper_case(bank + " bank") + sprintf("%60s", "Account #: " + fake_account_id(bank, body)),
                   "Account in currency: " + capitalize(currency), "",
                   sprintf("%-35.35s  %-15s  %-15s  %-10s", "Description", "Withdrawals", "Deposits", "Balance"),
                   simple_divider()[0.. < 2]});
   if (!valid_currency(currency))
      error("Unknown currency '" + currency + "'.");

   if (!transactions[currency] || !transactions[currency][name])
      return "You have no '" + currency + "' account with " + bank + " Bank.\n";
   foreach (mixed *ar in transactions[currency][name])
   {
      if (ar[LOG_BANK] == bank && ar[LOG_MONEY])
         out += ({sprintf("%-35.35s  %-15s  %-15s  %-10s", ar[LOG_TEXT],
                          ar[LOG_MONEY] < 0 ? sprintf("%2.2f %s", ar[LOG_MONEY] * -1, abbreviate(currency)) : "",
                          ar[LOG_MONEY] >= 0 ? sprintf("%2.2f %s", ar[LOG_MONEY], abbreviate(currency)) + "" : "",
                          sprintf("%2.2f %s", ar[LOG_SALDO], abbreviate(currency)) + "", )});
   }
   out += ({simple_divider()[0.. < 2]});
   return implode(out, "\n");
}

mapping query_transactions()
{
   return transactions;
}

mapping query_account_data()
{
   return accounts;
}

void remove_bank(string bank)
{
   map_delete(accounts, bank);
   save_me();
}

mapping query_accounts(object player)
{
   mapping acm = ([]);
   foreach (string bank in keys(accounts))
   {
      mapping account = query_account(bank, player);
      foreach (string currency, float balance in account)
      {
         if (!acm[bank])
            acm[bank] = ([]);
         if (balance > 0.00)
            acm[bank][currency] = balance;
      }
   }
   return acm;
}

varargs void deposit(string bank, mixed player, float amount, string type, string what)
{
   string name;
   string currency;
   float factor;
   type = MONEY_D->singular_name(type);
   currency = MONEY_D->query_currency(type);
   factor = MONEY_D->query_factor(type);
   amount = amount * factor;

   if (!valid_currency(currency))
      error("Unknown currency '" + currency + "'.");

   if (objectp(player))
      name = player->query_link()->query_userid();
   else
      name = player;

   if (!accounts[bank])
      accounts[bank] = ([]);

   if (!accounts[bank][name])
      accounts[bank][name] = ([]);
   if (!accounts[bank][name][currency])
      accounts[bank][name][currency] = 0.0;
   accounts[bank][name][currency] = to_float(accounts[bank][name][currency]) + amount;
   transaction(player, bank, what ? what : (amount >= 0 ? "Deposit into" : "Withdrawal from") + " account", currency,
               amount);
   save_me();
}

int coverage(string bank, mixed player, float amount, string denom)
{
   return query_account(bank, player, denom) >= amount * MONEY_D->query_factor(denom);
}

varargs void withdraw(string bank, mixed player, float amount, string currency, string what)
{
   string name;
   if (!valid_currency(currency))
      error("Unknown currency '" + currency + "'.");

   if (objectp(player))
      name = player->query_link()->query_userid();
   else
      name = player;
   deposit(bank, player, -amount, currency, what);
}

void set_account(string bank, object player, string currency, float amount)
{
   string name = player->query_userid();
   if (!valid_currency(currency))
      error("Unknown currency '" + currency + "'.");

   if (!accounts[bank])
      accounts[bank] = ([]);
   if (!accounts[bank][name])
      accounts[bank][name] = ([]);
   accounts[bank][name][currency] = amount;
   save_me();
}

void stat_me()
{
   int people = 0;
   int account = 0;
   float amount = 0;
   string *currencies = ({});

   foreach (string bank, mapping peoples in accounts)
   {
      people++;
      foreach (string name, mapping acc in peoples)
      {
         foreach (string currency, float am in acc)
         {
            if (member_array(currency, currencies) == -1)
               currencies += ({currency});
            amount += am;
            account++;
         }
      }
   }

   write("ACCOUNT_D stats:\n----------------\n" + "Number of Banks: " + sizeof(accounts) + "\n" +
         "Number of People with accounts: " + people + "\n" + "Number of accounts: " + account + "\n" +
         "Number of currencies: " + sizeof(currencies) + " (" + format_list(currencies) + ")\n" +
         "Total amount: " + amount + "\n" + "Average/account: " + (amount / account) + "\n");
}

void clean_up()
{
   destruct(this_object());
}

void create()
{
   ::create();
   set_privilege("Mudlib:daemons");
   restore_me();
}
