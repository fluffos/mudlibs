#include <object.h>
#include <item.h>
#include <desc.h>
#include <saveload.h>

mapping accounts;
mapping vault;
string *history;
string *banker;

NAME( "ledger" )
PLURAL( "ledgers" )
DISTANT( "a bank ledger" )
ICON( '\"', 9, LAYER_ITEMS )

int is_authorized( object who ) {
   return who->query_level() >= WIZLEVEL || member(banker, who->query_name()) != -1;
}

void create() {
   ::create();
   if( !pointerp(history) )
      history = ({});
   if( !stringp(banker) )
      banker = ({});
   if( !mappingp(accounts) )
      accounts = ([]);
   if( !mappingp(vault) )
      vault = ([]);
}

void init() {
   ::init();
   // all bank commands go here, ja?
   add_action( "do_balance", "balance" );
   add_action( "do_open_account", "oacct" );
   add_action( "do_close_account", "cacct" );
   add_action( "do_deposit", "depo" );
   add_action( "do_deposit", "with" );
}

string to_candles( int x ) {
   int candles, pence;
   pence = x % 10;
   candles = x / 10;

   if (pence) {
      return "C" + candles + ", " + pence + "p";
   } else if (candles) {
      return "C" + candles;
   } else {
      return pence + "p";
   }
}

string print_balance( string name ) {
   if( member(accounts, name) )
      return "Your current balance is "+to_candles( accounts[name] );
   else
      return "You do not have an account here.";
}

string print_help() {
   return "You can use the ledger to record deposits and withdrawals, and to perform any other basic bank function. Of course, it is not yet finished, but when it is, you will be able to get a list of commands by looking at the book.\n"+
         "  ~CCOMbalance <name>~CDEF    - check a player's balance\n"+
         "  ~CCOMbalance all~CDEF       - check the balance of all accounts\n"+
         "  ~CCOMdepo <name> <amt>~CDEF - add amt pence to player's balance\n"+
         "  ~CCOMwith <name> <amt>~CDEF - remove amt pence from player's balance\n"+
         "  ~CCOMcacct <name>~CDEF      - close 'name's account\n"+
         "  ~CCOMoacct <name>~CDEF      - open an account for 'name'";
}

string query_look() {
   if( !this_player() )
      return 0;
   if( !is_authorized(this_player()) ) {
      set_actor( this_player() );
      set_target( this_object() );
      this_player()->msg_local( "~CACT~Name ~verbcheck ~poss balance in ~targ.~CDEF" );
      return print_balance( this_player()->query_name() );
   } else {
      return print_help();
   }
}

string *query_bankers() {
   return banker;
}
void set_bankers( string *names ) {
   banker = names;
}

int query_balance( string name ) {
   return accounts[name];
}
void set_balance( string name, int x ) {
   accounts[name] = x;
}
void add_balance( string name, int x ) {
   set_balance( name, query_balance(name) + x );
}

int do_deposit(string arg) {
   string name;
   int amt;
   if( !is_authorized(this_player()) )
      return 0;
   if( !arg || sscanf(arg,"%s %d",name,amt) != 2 ) {
      msg( "Syntax: " + query_verb() + " name amt");
      return 1;
   }

   if( query_verb() == "with" )
      amt = -amt;
   debug ("Depositing " + amt );
   set_actor( this_player() );
   set_target( this_object() );
   this_player()->msg_local( "~CACT~Name ~verbmake a note in ~targ.~CDEF" );
   add_balance( name, amt );
   debug ("Balance " + accounts[name] );
   msg( capitalize(name)+"'s balance is now "+to_candles(accounts[name]) );
   return 1;
}

int do_balance(string arg) {
   if( !is_authorized(this_player()) )
      return 0;
   set_actor( this_player() );
   set_target( this_object() );
   this_player()->msg_local( "~CACT~Name ~verbconsult ~targ.~CDEF" );
   if( !arg )
      arg = this_player()->query_name();
   if( arg == "all" ) {
      string who;
      foreach( who : sort_array(m_indices(accounts), #'>) )
         msg( "~CBRT" + pad(who, 15, 0) + " ~CDEF: " + to_candles(accounts[who]) );
   } else {
      if( !member(accounts, arg) )
         msg( "There is no account by the name '"+arg+"' here.");
      else
         msg( capitalize(arg) + " has a balance of " + to_candles(accounts[arg]) );
   }
   return 1;
}

int do_open_account(string arg) {
   if( !is_authorized(this_player()) )
      return 0;
   if( !arg )
      return notify_fail("You must specify a name for the account.");
   arg = lower_case(arg);
   if( member(accounts, arg) )
      return notify_fail("There is already an account by that name here.");

   set_actor( this_player() );
   set_target( this_object() );
   this_player()->msg_local( "~CACT~Name ~verbmake an entry in ~targ.~CDEF" );

   msg("You have opened a new account under the name '"+arg+"'.");
   set_balance( arg, 0 );
   return 1;
}

int do_close_account(string arg) {
   if( !is_authorized(this_player()) )
      return 0;
   if( !arg )
      return notify_fail("You must specify a name for the account.");

   arg = lower_case(arg);
   if( !member(accounts, arg) )
      return notify_fail("There is not any account by that name here.");

   set_actor( this_player() );
   set_target( this_object() );
   this_player()->msg_local( "~CACT~Name ~verbmake an entry in ~targ.~CDEF" );

   msg("You closed the account '"+arg+"'.");
   msg("The balance was " + to_candles(accounts[arg]) + "." );
   accounts -= ([ arg ]);
   return 1;
}
