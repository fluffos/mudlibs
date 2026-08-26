/**
 * The standard inheritable object for player-run shop manager offices.
 * This object defines the managers' office, allowing access to managers'
 * commands.  The majority of player-shop functionality is handled from
 * within the main office.  See the header file for a complete description
 * of the shop's workings.
 * @see /include/player_shop.h
 * @see /std/shops/player_shop/office.c
 * @see /std/shops/player_shop/counter.c
 * @see /std/shops/player_shop/storeroom.c
 * @see /std/shops/player_shop/shop_front.c
 * @see /std/shops/player_shop/shopkeeper.c
 * @author Ringo
 * @started 1st August 1999
 */
#include <player_shop.h>
#include <mail.h>
#include <move_failures.h>
#include <money.h>

inherit ROOM_OBJ;

int do_list( mixed * );
int do_logs( mixed *, string );
int do_mail( mixed * );
int do_query( string );
int do_view( string );
int do_project( string );
int do_vote( mixed *, string );
int do_commend( string );
int do_fire( mixed * );
int do_warn( mixed * );
int do_demote( string );
int do_suspend( mixed * );
int do_leave( mixed * );
int do_ban( mixed * );
int do_unban( string );
int do_set( mixed *, string );
int do_transfer( mixed * );
int do_policy(mixed *);

private string _office = "",
               _place = "",
               _shop_front = "",
               _counter = "",
               _storeroom = "";

private mapping _applicants = ([]);

/** @ignore yes */
void create()
{
   do_setup++;
   ::create();
   do_setup--;
   add_property( "determinate", "" );
   if ( !do_setup )
   {
      this_object()->setup();
      this_object()->reset();
   }
}
/* create() */


/** @ignore yes */
void init()
{
   ::init();
   if ( !_office || _office == "" )
   {
      return;
   }
   if ( !_office->query_manager( this_player()->query_name() ) &&
     !_office->query_retired( this_player()->query_name() ) &&
     !creatorp(this_player()) )
   {
      return;
   }
   add_command( "list", ({ "", "{employees|applicants|baddies}" }),
     (: do_list($4) :) );
   add_command( "memo", "" );
   add_command( "office", "" );
   add_command( "claim", "" );
   add_command( "accounts", "" );
   add_command( "logs", ({ "", "<number>", "{personnel|accounts|chart}" }),
     (: do_logs($4,$5) :) );
   add_command( "query", "{pay|employees}", (: do_query($4[0]) :) );
   add_command( "view", "<string'employee'>", (: do_view($4[0]) :)  );
   add_command( "project", "{pay|bonus}", (: do_project($4[0]) :) );
   add_command( "vote", "policy <word'name'> {y|n}", (: do_vote($4,$5) :) );
   add_command( "policy", "{suggest|remove} <word'policy'>",
     (: do_policy($4) :) );
   add_command( "policies", "" );

   if ( _office->query_retired( this_player()->query_name() ) )
   {
      return;
   }
   add_command( "rent", "cabinet" );
   add_command( "remove", "cabinet" );
   add_command( "retire", "" );
   add_command( "vote", "<word'applicant'> {y|n|a}", (: do_vote($4,$5) :) );
   add_command( "check", "votes" );
   add_command( "commend", "<word'employee'>", (: do_commend($4[0]) :) );
   add_command( "fire", "<word'employee'> [for] <string'reason'>",
     (: do_fire($4) :) );
   add_command( "warn", "<word'employee'> [for] <string'reason'>",
     (: do_warn($4) :) );
   add_command( "demote", "<word'employee'>", (: do_demote($4[0]) :) );
   add_command( "suspend", "<word'employee'> [for] <number> [months]",
     (: do_suspend($4) :) );
   add_command( "leave", "<word'employee'> [for] <number> [days]",
     (: do_leave($4) :) );
   add_command( "ban", "<word'person'> for <string'reason'>",
     (: do_ban($4) :) );
   add_command( "unban", "<word'person'>", (: do_unban($4[0]) :) );
   add_command( "set", ({ "maximum <number> [employees]",
     "pay <number'amount'> <string'type'>" }), (: do_set($4,$5) :) );
   add_command( "transfer", "<number'amount'> <string'type'> [from] "
     "{register|bonus|profit} [to] {register|bonus|profit}",
     (: do_transfer($4) :) );
}
/* init() */


/**
 * Set the path of the main office.
 * @param path The full path & filename.
 */
void set_office(string path) {
  _office = path;
}

int do_list(mixed *stuff) {
   string word, results;
   int emps_in;
   object ob;
   mapping _employees = ([ ]);
   
   _employees = _office->query_employees();
   results = "   Employees of "+ _office->query_shop_name() + "\n"
     "     As at " + ctime( time() ) + "\n\n";

   /* Retired managers */
   foreach ( word in _office->get_retired() )
   {
      if ( (ob = find_player( word )) && !ob->query_invis() )
      {
         results += "%^GREEN%^";
      }
      results += "     "+ capitalize( word )+
      "%^RESET%^ (retired manager)\n";
   }

   /* Managers */
   foreach ( word in _office->get_managers() )
   {
      if ( (ob = find_player( word )) && !ob->query_invis() )
      {
         emps_in ++;
         results += "%^GREEN%^";
      }
      results += "     "+ capitalize( word )+ "%^RESET%^ (manager)"+
        _office->list_stuff( word );
   }

   /* Supervisors */
   foreach ( word in _office->get_supervisors() )
   {
      if ( (ob = find_player( word )) && !ob->query_invis() )
      {
         emps_in ++;
         results += "%^GREEN%^";
      }
      results += "     "+ capitalize( word )+ "%^RESET%^ (supervisor)"+
        _office->list_stuff( word );
   }

   /* Riff-raff */
   foreach ( word in keys(_employees))
   {
      if ( (ob = find_player( word )) && !ob->query_invis() )
      {
         emps_in ++;
         results += "%^GREEN%^";
      }
      results += "     "+ capitalize( word )+ "%^RESET%^"+
        _office->list_stuff( word );
   }

   /* Applicants */
   foreach ( word in keys(_office->get_applicants()) )
   {
      if ( (ob = find_player( word )) && !ob->query_invis() )
      {
         results += "%^YELLOW%^";
      }
      results += "     "+ capitalize( word )+
      " %^YELLOW%^(applicant)%^RESET%^\n";
   }

   /* Baddies */
   foreach ( word in keys(_office->get_baddies()) )
   {
      if ( (ob = find_player (word ) ) && !ob->query_invis() )
      {
         results += "%^RED%^";
      }
      results += "     "+ capitalize( word )+
      " %^RED%^(baddie)%^RESET%^\n";
   }

   results += "\n";

   /* If viewed by manager or creator, display number of employees logged
    * on and number clocked in.
    */
   if( creatorp(TP) || _employees[TP->query_name()][EMP_POINTS] & MANAGER ) {
      if ( emps_in == 1 ) {
         results += "   There is one employee ";
      } else {
         results += "   There are "+ query_num(emps_in,0)+ " employees ";
      }
      results += "out of "+ query_num( sizeof( _employees ) )+
        " on "+mud_name()+" at the moment, with "+
        query_num( _office->num_employees_in(), 0 ) +
        " currently clocked in.\n\n";
   }

   tell_object( this_player(), "$P$Employees$P$"+ results );
   add_succeeded_mess( "" );
   return 1;
}
/* do_list() */

/**
 * @ignore yes
 * Send a memo to each employee.  Only used if there is no board.
 */
int do_memo()
{
   this_player()->do_edit( 0, "end_memo" );
   add_succeeded_mess( "" );
   return 1;
}
/* do_memo() */


/** @ignore yes */
void end_memo( string text )
{
   string *employees;
   if ( !text )
   {
      tell_object( this_player(), "Aborted.\n" );
#ifdef DEBUG
      debug_printf( "No message text.  Aborting.\n" );
#endif
      return;
   }
   employees = _office->get_managers() -
      ( creatorp(TP) ? ({ }) : ({ TP->query_name() }));
   tell_object( this_player(),
     "Do you want to keep a copy of the memo? " );
   input_to( "send_memo", 0, text, employees );
}
/* end_memo() */


/** @ignore yes */
void send_memo( string ans, string text, string *employees )
{
   if ( strlen(ans) < 1 || ( ans[0] != 'y' && ans[0] != 'n' ) )
   {
      tell_object( TP,
        "Do you want to keep a copy of the memo? (Yes or No)? " );
      input_to( "send_memo", 0, text );
      return;
   }
   _office->send_memo(ans, text, employees);
}
/* send_memo() */

int do_office() {
}

int do_claim() {
  object thing;
  thing = clone_object(MGR_BOOK);
  thing->set_read_mess("\n  "+_office->query_shop_name()+"\n\n"
              "  Staff Handbook\n\n  This handbook belongs to "+
              TP->query_short()+"\n\n", "common", 100);
  thing->set_office(_office);
  thing->move(TP);
  TP->add_succeeded_mess(TO, "$N $V $I.\n", ({ thing }));
  return 1; 
}

int do_accounts() {
}

int do_logs(string stuff, int num) {
}

int do_query(string stuff) {
}

int do_view(string stuff) {
}

int do_project(string stuff) {
}

int do_vote(mixed *stuff, string pat) {
  return _office->do_vote(stuff, pat);
}

int do_policy(string *stuff) {
}

int do_policies() {
}

int do_rent() {
}

int do_remove() {
}

int do_retire() {
}

int do_check() {
}

int do_commend(string stuff) {
}

int do_fire(string *stuff) {
}

int do_warn(string *stuff) {
}

int do_demote(string stuff) {
}

int do_suspend(string *stuff) {
}

int do_leave(string *stuff) {
}

int do_ban(string *stuff) {
}

int do_unban(string stuff) {
}

int do_set(string *stuff, string pat) {
}

int do_transfer(string *stuff) {
}
