/**
 * The standard inheritable object for player-run shop offices.
 * This is the main object for player-run shops.  The majority of
 * player-shop functionality is handled from within this object.
 * See the header file for a complete description of the shop's
 * workings.
 * @see /include/player_shop.h
 * @see /std/shops/player_shop/mgr_office.c
 * @see /std/shops/player_shop/counter.c
 * @see /std/shops/player_shop/storeroom.c
 * @see /std/shops/player_shop/shop_front.c
 * @see /std/shops/player_shop/shopkeeper.c
 * @author Ringo
 * @started 1st August 1999
 */
#include <player_shop.h>
#include <mail.h>
#include <board.h>
#include <money.h>
#include <move_failures.h>
#include <refresh.h>

inherit ROOM_OBJ;

int do_claim( string );
int do_clock( string );
int do_bank( mixed * );
int do_logs( mixed *, string );
int do_chart( mixed *, string );
int do_promote( string );
void demote( string, string );
void save_hist();
void save_times();
void add_policy( string );
void remove_policy( string );
int do_policy_vote( string, string, string );
private void adjust_profit( string emp, int amount );

private nosave string _proprietor = "???",
               _shop_name = "???",
               _very_short = "???",
               _place = "???",
               _channel = "???",
               _storeroom = "",
               _shop_front = "",
               _counter = "",
               _mgr_office = "",
               _store_dir = "",
               _counter_dir = "",
               _shop_dir = "",
               _shopkeeper = "",
               _log_file = "",
               _stock_policy = "",
               _save_dir = SAVE_DIR,
               _creator = CREATOR;

private nosave object _chart = 0,
                      _board = 0,
                      _notice = 0;

private nosave mapping _history = ([]),
                       _list = ([]),
                       _times = ([]),
                       _employees = ([]);

private nosave int _call_save = 0,
                   _call_hist = 0,
                   _call_times = 0,
                   _call_hire_list = 0,
                   _call_mail_hirees = 0,
                   _call_summon = 0,
                   _npc_time = 0,
                   _call_emps = 0;

private string *_retired = ({}),
               *_got_bonus = ({}),
               _last_month = "last month";

private mapping _applicants = ([]),
                _baddies = ([]),
                _declined = ([]),
                _accounts = (["profit":0,"bonus":0]),
                _new_policies = ([]),
                _policies = ([]);

private int _max_emp = MAX_EMP,
            _bonus_val = 0,
            _bonus = 0,
            _pay_val = 4,
            _num_cabinets = MIN_CABINETS,
            _net_takings = 0;

private mixed *_register;


/** @ignore yes */
void create() {
   string ob_file;
   object this_ob;

   this_ob = this_object();
   ob_file = file_name( this_ob );
#ifdef DEBUG
   debug_printf( "Filename: %s\n", ob_file );
#endif
   seteuid( (string)master()->creator_file( ob_file ) );
   do_setup++;
   ::create();
   do_setup--;
   if ( !do_setup ) {
      this_ob->setup();
      this_ob->reset();
   }
   add_property( "determinate", "" );
   _chart = clone_object( SHOP_CHART );
   _chart->set_office( ob_file );
   add_hidden_object( _chart );
   _notice = clone_object( SHOP_NOTICE );
   _notice->set_office( ob_file );
   add_hidden_object( _notice );
#ifndef DEBUG
   REFRESH->register_refresh( ob_file );
   REFRESH->register_delete( ob_file );
#endif
} /* create() */


/**
 * Set the creator of this shop.
 * This person will receive all applications, complaints, suggestions
 * etc in the absence of any managers.  Default is set by CREATOR in
 * <player_shop.h>
 * @param creator The person responsible for this shop.
 */
void set_creator( string creator ) { _creator = creator; }


/**
 * Query the maintainer of this shop's files.
 * @return The person responsible for this shop.
 */
void query_creator( string creator ) { return copy( _creator ); }


/**
 * Determine if this person is an employee of the shop.
 * @param player The player to query.
 * @return The employee's points, or FALSE if not an employee.
 */
int query_employee( string player )
{
   if ( _employees[player] )
   {
      return copy(_employees[player][EMP_POINTS]);
   }
   return FALSE;
}
/* query_employee() */


/**
 * Determine if this person is a supervisor of this shop.
 * @param player The player to query.
 * @return TRUE or FALSE
 */
int query_supervisor( string player )
{
   if ( _employees[player] )
   {
      return ( _employees[player][EMP_POINTS] & SUPERVISOR );
   }
   return FALSE;
}
/* query_supervisor() */


/**
 * Determine if this person is a manager of this shop.
 * @param player The player to query.
 * @return TRUE or FALSE
 */
int query_manager( string player )
{
   if ( _employees[player] )
   {
      return ( _employees[player][EMP_POINTS] & MANAGER );
   }
   return FALSE;
}
/* query_manager() */


/**
 * Determine if this person is a retired manager of this shop.
 * @param player The player to query.
 * @return TRUE or FALSE
 */
int query_retired( string player )
{
    return ( member_array( player, _retired ) == -1 )?FALSE:TRUE;
}
/* query_retired() */


/**
 * Determine if this person has applied for a job.
 * @param player The player to query.
 * @return APPLIED if applied, HIRED if voted in, AWAITING if awaiting
 * a vacancy.  Otherwise, will return FALSE.
 */
int query_applicant( string player )
{
    if ( !sizeof( _applicants ) )
    {
       return FALSE;
    }
    if ( _applicants[player] )
    {
       return copy(_applicants[player][APP_TYPE]);
    }
    return FALSE;
}
/* query_applicant() */


/**
 * Determine if this person is banned from the shop.
 * @param player The player to query.
 * @return The time of the ban if banned, FALSE if not banned.
 */
int query_baddie( string player )
{
   if ( !m_sizeof( _baddies ) )
   {
      return FALSE;
   }
   if ( _baddies[player] )
   {
      return copy(_baddies[player][BAD_TIME]);
   }
   return FALSE;
}
/* query_baddie() */


/** @ignore yes */
void init() {
   string word;
   object tp;

   ::init();
   tp = this_player();
   word = tp->query_name();

   /*
    * Only employees & creators should have access to shop commands.
    */
   if( !creatorp(tp) && !_employees[word] &&
       ( member_array( word, _retired ) == -1 ) ) {
       return;
   }

   add_command("claim", "{badge|handbook|bonus}", (: do_claim($4[0]) :) );
   add_command("resign", "");
   add_command("list", "");
   add_command("office", "");

   /*
    * If there is no board set up for this shop, all comms done by mail.
    */
   if( !_board )
       add_command( "memo", "" );

   /*
    * Retired managers have no need for following commands.
    */
   if( member_array( word, _retired ) != -1 )
       return;

   add_command("clock", "{in|out}", (: do_clock($4[0]) :) );
   add_command("bank", ({ "", "<number>" }), (: do_bank($4) :) );
   if( !tp->query_property( "no score" ) )
       add_command("promotion", "{on|off}", (: do_promote($4[0]) :) );

   /*
    * Only supervisors & managers have access to following commands.
    */
   if( !creatorp(tp) && !( _employees[word][EMP_POINTS] & SUPERVISOR ) )
       return;

   add_command("chart", ({ "add <string'item'>", "remove <string'item'>",
       "max <string'item'> <number>", "buy <string'item'> <number>",
       "sell <string'item'> <number>",
       "assign <string'item'> [to cabinet] <number>",
       "unassign <string'item'> [from cabinet] <number>" }),
       (: do_chart($4, $5) :) );
   add_command("check", "cabinets");

   if( !creatorp(tp) && !( _employees[word][EMP_POINTS] & MANAGER ) )
       add_command("logs", ({ "", "<number>", "[chart]" }),
           (: do_logs($4,$5) :) );
   else
       add_command("logs", ({ "", "<number>",
           "{personnel|accounts|chart}" }), (: do_logs($4,$5) :) );

} /* init() */


/**
 * @ignore yes
 * Saves the employee data.
 */
void do_save_emps() {
#ifdef DEBUG
   debug_printf( "Saving employee data to %s.\n",
     _save_dir + _very_short+ ".employees" );
#endif
   unguarded( (: write_file, _save_dir + _very_short+ ".employees",
     save_variable( _employees ), 1 :) );
}
/* do_save_emps() */

/**
 * Save the data file.
 * This method uses a call_out to help minimise the amount of disk activity
 * during normal operations of the shop.
 */
protected void save_emps() {
   if( _very_short == "???" )
       return;
   remove_call_out( _call_emps );
   _call_emps = call_out( "do_save_emps", SAVE_DELAY );
}
/* save_emps() */

/**
 * @ignore yes
 * Save this object immediately.
 */
void do_save() {
#ifdef DEBUG
   debug_printf( "Saving shop data to %s.\n",
     _save_dir + _very_short );
#endif
   unguarded( (: save_object, _save_dir + _very_short :) );
}
/* do_save() */

/**
 * Save the data file.
 * This method uses a call_out to help minimise the amount of disk activity
 * during normal operations of the shop.
 */
protected void save_me() {
   if( _very_short == "???" )
       return;
   remove_call_out( _call_save );
   _call_save = call_out( "do_save", SAVE_DELAY );
}
/* save_me() */


/**
 * @ignore yes
 * Saves the employment last-action times data.
 */
void save_list() {
   if ( _very_short == "???" )  {
      return;
   }
#ifdef DEBUG
   debug_printf( "Saving chart list data to %s.\n",
     _save_dir+ _very_short+ ".list" );
#endif
   unguarded( (: write_file, _save_dir + _very_short+ ".list",
     save_variable( _list ), 1 :) );
}
/* do_save_list() */


/**
 * @ignore yes
 * Make sure all data is saved before desting this object.
 */
void dest_me() {
   if( _very_short != "???" ) {
       remove_call_out( _call_save );
       remove_call_out( _call_hist );
       remove_call_out( _call_times );
       remove_call_out( _call_emps );
       save_hist();
       save_times();
       do_save_emps();
       do_save();
   }
   if( _chart )
       _chart->dest_me();
   if( _board )
       _board->dest_me();
   if( _notice )
       _notice->dest_me();

   ::dest_me();
} /* dest_me() */

/**
 * Query number of 'items' in stock.
 */
int query_stock( string items ) {
   return _storeroom->query_num_items( items, 0 );
} /* query_stock() */

/**
 * @ignore yes
 * Saves the employment last-action times data.
 */
void save_times() {
   if( _very_short == "???" )
       return;
#ifdef DEBUG
   debug_printf( "Saving times data to %s.\n",
     _save_dir + _very_short+ ".times" );
#endif
   unguarded( (: write_file, _save_dir + _very_short+ ".times",
     save_variable( _times ), 1 :) );
}
/* save_times() */

/**
 * @ignore yes
 * Sets the last action time of an employee.
 * This time is the last time an employee did something worth
 * recording and is used to determine if they are inactive.
 * @param employee The employee.
 */
private void set_emp_time( string employee )
{
   if ( !_employees[employee] )
   {
      return;
   }
   _employees[employee][EMP_TIME] = time();  // Set last-action time
   _employees[employee][EMP_INACTIVE] = 0;   // Reset inactivity flag
   if ( !sizeof( _times ) )
   {
      _times = ([ employee:0 ]);
   }
   else if ( !_times[employee] )
   {
      _times += ([ employee:0 ]);
   }
   _times[employee] = time();   // Update employee record
   remove_call_out( _call_times );
   _call_times = call_out( "save_times", PERS_DELAY );
   save_emps();
}
/* set_emp_time() */


/**
 * @ignore yes
 * This function adds an entry to the logs & pays employees.
 * Logs record a full day's (3 DW days) activity, apart from the
 * chart, accounts & personnel logs which use log_file.<br>
 * @param logtype The type of log entry - see <player_shop.h>
 * @param word The employee making the entry.
 * @param words The log entry text.
 */
void shop_log( int logtype, string word, string words ) {
   string date, file, month, colour, summary, item, sign;

   sscanf( mudtime(time()), "%*s %*s %*s %s", month );
   if ( file_size( _log_file +"general.log" ) > 0 ) {
      date = ctime( time() )[ 0 .. 9 ];

      /*
       * Are we on a new day yet?  If so, do the daily review.
       */
      if ( date != unguarded( (: read_file,
        _log_file +"general.log", 1, 1 :) )[ 0 .. 9 ] ) {
         _storeroom->force_load();
         call_out( "update_averages", 60 );
         file = _log_file +"general.log-"+ time();
         unguarded( (: rename, _log_file +"general.log", file :) );
         call_out( "review_employees", 5 );
         summary = sprintf( "%sFor the day ending %s:%s\n",
           "%^BOLD%^", mudtime(time()), "%^RESET%^" );
         foreach ( item in m_indices( _list ) ) {
            summary += sprintf( " %s - Bought %d, Sold %d\n", capitalize(item),
              _list[item][CHART_BOUGHT], _list[item][CHART_SOLD] );
           _list[item][CHART_AVESALE] = ( _list[item][CHART_AVESALE] +
             _list[item][CHART_SOLD] + random(2) ) / 2;
           _list[item][CHART_SOLD] = 0;
           _list[item][CHART_BOUGHT] = 0;
         }
         save_list();
         sign = "";
         if ( _net_takings < 0 )
         {
            _net_takings = -_net_takings;
            sign = "-";
         }
         summary += sprintf( "%sThe net takings of the shop were %s%s.%s\n\n",
           "%^BOLD%^", sign, MONEY_HAND->money_value_string( _net_takings,
           _place ), "%^RESET%^" );
         _net_takings = 0;
         save_me();
         unguarded( (: write_file, _log_file +"general.log",
           date +"\n" + summary :) );

         /*
          * Remove old logs.
          */
         foreach ( file in get_dir( _log_file +"general.log-*" ) )
         {
            sscanf( file, "%*s-%s", date );
            if ( time() - to_int( date ) > (60*60*24*LOG_DAYS) )
            {
               unguarded( (: rm, _log_file + "general.log-"+ date :) );
            }
         }
      }
   }

   /*
    * Are we in a new month yet?  If so do the monthly review.
    */
   if ( month != _last_month )
   {
      if ( member_array( month, ({ "Offle", "February", "March",
        "April", "May", "June", "Grune", "August", "Spune",
        "Sektober", "Ember", "December", "Ick" }) ) != -1 )
      {
         call_out( "monthly_review", 60, month);
      }
   }

   /*
    * Only pay employees if clocked in & this action is at least
    * 1 minute after the previous paid action.
    */
   if ( _employees[word] && !(_employees[word][EMP_POINTS] & NPC) )
   {
      if ( _employees[word][EMP_POINTS] & CLOCKED_IN &&
        _employees[word][EMP_TIME] < ( time() - 60 ) )
      {
         if ( _employees[word][EMP_POINTS] & MANAGER )
         {
            _employees[word][EMP_PAY] += ( _pay_val * 2 );
         }
         else if ( _employees[word][EMP_POINTS] & SUPERVISOR )
         {
            _employees[word][EMP_PAY] += to_int( _pay_val * 1.5 );
            _employees[word][EMP_POINTS] += 32;
         }
         else
         {
            _employees[word][EMP_PAY] += _pay_val;
            _employees[word][EMP_POINTS] += 32;
         }
         set_emp_time( word );
      }
   }

   /*
    * Write entry to the appropriate log.
    */
   switch ( logtype ) {
     case PURCHASE :
        colour = "%^GREEN%^";
        break;
     case SALE :
        colour = "%^RED%^";
        break;
     case GENERAL :
        colour = "%^CYAN%^";
        break;
     case PERSONNEL :
        log_file( _log_file+ "personnel.log", "%s: %s - %s\n",
          mudtime(time()), capitalize( word ), words );
        return;
        break;
     case ACCOUNTS :
        log_file( _log_file+ "accounts.log", "%s: %s - %s\n",
          mudtime(time()), capitalize( word ), words );
        return;
        break;
     case CHARTLOG :
        log_file( _log_file+ "chart.log", "%s: %s - %s\n",
          mudtime(time()), capitalize( word ), words );
        return;
        break;
     default :
        colour = "%^RESET%^";
        break;
   }
   unguarded( (: write_file, _log_file +"general.log", colour + mudtime(time())+
     ": "+ capitalize( word ) +"%^RESET%^ - "+ words +"\n" :) );
}
/* shop_log() */


/**
 * @ignore yes
 * Writes a message to the shop's board if it exists.  If not, will
 * send a mail to each employee.  This message is "written" by the shop's
 * proprietor.
 * @param subject Take a guess ;-)
 * @param post See subject...
 */
private void add_board_message( string subject, string post )
{
   string employee, *employees;

   if ( _board )
   {
#ifdef DEBUG
      debug_printf( "Posting message %s to board %s.\n", subject,
        _channel );
#endif
      BOARD_HAND->add_message( _channel, _proprietor,
        subject, post + "--\n"+ _proprietor+ " (proprietor)" );
   }
   else
   {
      employees = _retired;
      foreach( employee in m_indices( _employees ) )
      {
         if ( !( _employees[employee][EMP_POINTS] & NPC ) )
         {
            employees += ({ employee });
         }
      }
      if ( !sizeof( employees ) )
      {
#ifdef DEBUG
         debug_printf( "No employees to send mail to.\n" );
#endif
         return;
      }
      employees += ({ CREATOR });
#ifdef DEBUG
      debug_printf( "Sending mail %s to all employees.\n", subject );
#endif
      AUTO_MAILER->auto_mail( implode( employees, "," ), _proprietor,
           subject, "", post );
   }
}
/* add_board_message() */


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
   employees = _retired;
   if ( creatorp(TP) )
   {
      employees += ({ TP->query_name() });
   }
   foreach( string employee in m_indices( _employees ) )
   {
      if ( !( _employees[employee][EMP_POINTS] & NPC ) )
      {
         employees += ({ employee });
      }
   }
   tell_object( this_player(),
     "Do you want to keep a copy of the memo? " );
   input_to( "send_memo", 0, text, employees );
}
/* end_memo() */


/** @ignore yes */
void send_memo( string ans, string text, string *employees )
{
   ans = lower_case( ans );
   if ( strlen(ans) < 1 || ( ans[0] != 'y' && ans[0] != 'n' ) )
   {
      tell_object( TP,
        "Do you want to keep a copy of the memo? (Yes or No)? " );
      input_to( "send_memo", 0, text, employees );
      return;
   }
   if ( !sizeof( employees ) )
   {
#ifdef DEBUG
      debug_printf( "No employees to send mail to.\n" );
#endif
      tell_object( TP, "There is no-one to send a memo to!\n" );
      return;
   }
   if(ans[0] == 'n') employees -= ({ TP->query_name() });
#ifdef DEBUG
   debug_printf( "Sending employee memo to %s.\n",
     implode( employees, "," ) );
#endif
   tell_object( TP, "Sending your memo.\n" );
   AUTO_MAILER->auto_mail( implode( employees, "," ),
     TP->query_name(), _very_short+
     " employee memo", "", text, 0, 0 );
}
/* send_memo() */


/**
 * Return the employee data.
 * This includes only active employees - retired managers are not included.
 * The data is formatted as:<br>
 * ([ employee:({ points, time, bank, pay, inactive, nobonus, nopromote }) ])<br>
 * @return The employee mapping, formatted as above.
 */
mapping query_employees() { return copy(_employees + ([ ])); }


/**
 * @ignore yes
 * Displays the list of commands available to each employee.
 */
int do_office() {
   int employee;
   object tp;
   string tp_name, board_mess = "";

   if( !_board )
       board_mess = "   memo     - send a memo to the other employees\n";

   add_succeeded_mess( "" );
   tp = this_player();
   tp_name = tp->query_name();

   if( member_array( tp_name, _retired ) != -1 ) {
       tell_object( tp, "As a retired manager, you can use the following "
         "commands:\n"
         "   claim    - claim a badge or handbook\n"
         "   list     - list the other employees of the shop\n"
         "   logs     - review the shop's logs\n"
         "   resign   - terminate your association with Tarnach's\n"+
         board_mess+
         "You may also enter the managers' office for more commands.\n" );
       return 1;
   }

   employee = ( creatorp(tp) ? SUPERVISOR + MANAGER :
               _employees[tp_name][EMP_POINTS] );

   tell_object( tp, "As an employee, you can use the following commands:\n"
     "   clock    - start or finish your working day\n"+
     "   claim    - claim a badge, handbook, or this month's bonus\n"
     "   bank     - set to which bank account you are paid\n"
     "   list     - list the other employees of the shop\n"
     "   resign   - end your employment at the shop\n"+
     board_mess );

   if( employee & SUPERVISOR ) {
      tell_object( tp, "As a supervisor, you can also use:\n"
        "   chart  - change the information on the sales chart\n"
        "   check  - check cabinet assignments\n"
        "   logs   - review the shop's logs\n" );
   }

   if( employee & MANAGER ) {
      tell_object( tp, "As a manager you can enter the managers' "
        "office and\nuse the commands listed there.\n" );
   }

   return 1;

} /* do_office() */


/**
 * @ignore yes
 * Adds a new employee.
 * Also prevent the employee from receiving a bonus until they have
 * worked a full month by setting EMP_NOBONUS to 1.
 */
void add_employee( string player ) {
   if( !_employees[player] ) {
       _employees += ([ player: ({ 1, 0, 0, 0, 0, 1, 0 }) ]);
       set_emp_time( player );
       _got_bonus += ({ player });
       save_me();
   }
} /* add_employee() */

/**
 * @ignore yes
 * Remove this person from the retired managers array.
 * Used when a retired manager resigns.
 */
private void remove_retired( string retired ) {
   retired = lower_case( retired );
   if( member_array( retired, _retired ) == -1  )
       return;
   _retired -= ({ retired });
   save_me();
} /* remove_retired() */

/**
 * @ignore yes
 * Remove this person from the applicants mapping.
 * Used when an applicant is hired, declined, or cancels their
 * application.
 */
private void remove_applicant( string applicant ) {
   applicant = lower_case( applicant );
   if( query_applicant( applicant ) ) {
       map_delete( _applicants, applicant );
       save_me();
   }
} /* remove_applicant() */

/**
 * @ignore yes
 * Remove this person from the employees mapping.
 * Used when an employee is fired, resigns, or retires.
 */
private void remove_employee( string employee ) {
   employee = lower_case( employee );
   if( _employees[employee] ) {
       map_delete( _employees, employee );
       save_emps();
   }
   remove_applicant( employee );
   remove_retired( employee );

   /* Check to see if anyone should be hired */
   remove_call_out( _call_hire_list );
   _call_hire_list = call_out( "check_hire_list", 5 );
} /* remove_employee() */

/**
 * @ignore yes
 * Used to check access to the managers' office.
 */
int check_manager( string action ) {
   object tp = this_player();
   string tp_name = tp->query_name();

   if( creatorp(tp) || (_employees[tp_name][EMP_POINTS] & MANAGER) ||
       ( member_array( tp_name, _retired ) != -1 ) )
       return 1;

   return notify_fail( "You are not a manager here!\n" );

} /* check_manager() */

/**
 * Query the list of retired managers.
 * This method returns the list of retired managers, sorted
 * alphabetically.
 * @return The sorted array of retired managers.
 */
string *get_retired() {
   return copy( sort_array( _retired, 1 ) );
} /* get_retired() */

/**
 * Query the list of managers.
 * This method returns the list of managers, sorted alphabetically.
 * @return The sorted array of managers.
 */
string *get_managers() {
   return copy( sort_array( keys( filter( _employees,
          (: _employees[$1][EMP_POINTS] & MANAGER :) ) ), 1 ) );
} /* get_managers() */

/**
 * Query the list of supervisors.
 * This method returns the list of supervisors, sorted
 * alphabetically.
 * @return The sorted array of supervisors.
 */
string *get_supervisors() {
   string word, *supervisors;

   supervisors = keys( filter( _employees,
        (: _employees[$1][EMP_POINTS] & SUPERVISOR :) ) );

   /* Managers also have the supervisor bit set, so don't
    * include them in this list.
    */
   foreach( word in supervisors ) {
      if( _employees[word][EMP_POINTS] & MANAGER )
          supervisors -= ({ word });
   }

   return copy( sort_array( supervisors, 1 ) );

} /* get_supervisors() */

/**
 * Query the list of employees.
 * This method returns the list of employees, sorted alphabetically.
 * @return The sorted array of employees.
 */
string *get_employees() {
   string word, *employees;

   employees = keys( _employees );

   /* Don't include people with the supervisor bit set */
   foreach( word in employees ) {
      if( _employees[word][EMP_POINTS] & SUPERVISOR )
          employees -= ({ word });
   }

   return copy( sort_array( employees, 1 ) );
} /* get_employees() */

/**
 * @ignore yes
 * Used by the shop front to add this person to the applicants mapping.
 */
void add_applicant( string player ) {
   player = lower_case( player );
   if ( !query_applicant( player ) )
   {
      if ( !sizeof( _applicants ) )
      {
         _applicants = ([ player:({ APPLIED,0,({}),({}), ({}), }) ]);
      }
      else
      {
         _applicants += ([ player:({ APPLIED,0,({}),({}), ({}), }) ]);
         _applicants[player][APP_TIME] = time();
      }
      save_me();
   }
}
/* add_applicant() */


/**
 * Return the list of applicants.
 * This method returns the list of applicants as a mapping formatted
 * as follows:<br>
 * ([ "name": type, time, ({ for }), ({ against }), ({ abstain }), ])
 * @return The applicants mapping formatted as above.
 */
mapping get_applicants() { return copy(_applicants + ([ ])); }


/**
 * Determine if a player was declined for a job.
 * This method is used to determine if there is a declined
 * application registered for a player.
 * @param player The player to query.
 * @return FALSE, or the time at which the applicant was declined.
 */
int query_declined( string player )
{
   if ( !sizeof( _declined ) )
   {
      return FALSE;
   }
   if ( _declined[player] )
   {
      return copy(_declined[player]);
   }
   return FALSE;
}
/* query_declined() */


/**
 * @ignore yes
 * Add this person to the list of declined applicants.  Used by
 * the shop front to determine if this person can apply again
 * yet.
 */
private void add_declined( string applicant )
{
   applicant = lower_case( applicant );
   if ( !query_declined( applicant ) )
   {
      if ( !sizeof( _declined ) )
      {
         _declined = ([applicant:0]);
      }
      else
      {
         _declined += ([applicant:0]);
      }
      _declined[applicant] = time();
      save_me();
   }
}
/* add_declined() */


/**
 * @ignore yes
 * Remove this person from the list of declined applicants,
 * allowing them to re-apply.
 */
private void remove_declined( string declined )
{
   declined = lower_case( declined );
   if ( query_declined( declined ) )
   {
      map_delete( _declined, declined );
      save_me();
   }
}
/* remove_declined() */


/**
 * @ignore yes
 * Saves the employment history data.
 */
void save_hist()
{
   if ( _very_short == "???" )
   {
      return;
   }
#ifdef DEBUG
   debug_printf( "Saving history data to %s.\n",
     _save_dir + _very_short+ ".history" );
#endif
   unguarded( (: write_file, _save_dir + _very_short+ ".history",
     save_variable( _history ), 1 :) );
}
/* save_hist() */


/**
 * @ignore yes
 * Adds an entry to the employee's history.
 * This method is intended to log relevant personnel issues such as
 * applications, hirings, promotions etc.  The normal day-to-day
 * stuff is logged in the shop's logs themselves.
 * @param shop The shop very short name.
 * @param employee The employee.
 * @param note The note to log.
 */
void employee_log( string employee, string note )
{
   if ( !sizeof(_history) )
   {
      _history = ([ employee:({ ({}),({}), }) ]);
   }
   else if ( !_history[employee] )
   {
      _history += ([ employee:({ ({}),({}), }) ]);
   }
   _history[employee][0] += ({ time() });
   _history[employee][1] += ({ note });
   remove_call_out( _call_hist );
   _call_hist = call_out( "save_hist", PERS_DELAY );
   if ( !sizeof( _times ) )
   {
      _times = ([ employee:0 ]);
   }
   else if ( !_times[employee] )
   {
      _times += ([ employee:0 ]);
   }
   _times[employee] = time();   // Update employee record
   remove_call_out( _call_times );
   _call_times = call_out( "save_times", PERS_DELAY );
}
/* employee_log() */


/**
 * @ignore yes
 * Used when applicant has sufficient supporting votes to be
 * accepted.
 */
private void hire( string word )
{
   int gender;
   string obj, poss, subj;

   remove_applicant( word );

   /* Do not hire if not a user, already an employee, or banned */
   if ( !"/secure/login"->test_user( word ) || _employees[word] ||
     query_baddie( word ) )
   {
        return;
   }

   add_employee( word );
   employee_log( word, "Hired" );
   shop_log( PERSONNEL, _proprietor, "hired "+ capitalize( word ) );
   AUTO_MAILER->auto_mail( word, _proprietor, _shop_name, "",
     "Congratulations!  You've been hired to work at "+ _shop_name+
     ".  You'll find that you can now move through the counter "
     "to the back areas of the shop.  The first things you should "
     "do are \"claim\" a new badge and staff handbook.\n" );
   gender = "/secure/login"->test_gender(word);
   obj = ({ "it", "him", "her" })[gender];
   poss = ({ "its", "his", "her" })[gender];
   subj = ({ "it", "he", "she" })[gender];
   add_board_message( "New employee", capitalize( word )+
     " has today been employed to work for the shop.  Please make " +
     obj + " feel welcome, and assist " + obj + " while " + subj + " gets "
     "started in " + poss + " new position.\n" );

   /* Update the other accepted applicants */
   remove_call_out( _call_mail_hirees );
   _call_mail_hirees = call_out( "mail_hirees", 5 );
}
/* hire() */


/**
 * @ignore yes
 * Check to see if we should hire any more accepted applicants.
 */
void check_hire_list()
{
   int count, x;
   string word;
   string *hirees;
   hirees = ({});

   /* Applicant has not confirmed employment after being accepted
    * so remove them.
    */
   foreach ( word in m_indices( filter( _applicants,
     (: _applicants[$1][APP_TYPE] == HIRED :) ) ) )
   {
      if ( time() - _applicants[word][APP_TIME] > HIRE_TIMEOUT )
      {
         AUTO_MAILER->auto_mail( word, _proprietor,
           _shop_name, "", "Since you have not returned to confirm "
           "your employment with us, we have assumed that you are no "
           "longer interested, and removed your name from our files.  "
           "If you wish to re-apply at any time in the future, please "
           "return to the shop to do so.\n" );
         employee_log( word, "Lapsed their application" );
         remove_applicant( word );
      }
   }

   foreach ( word in m_indices( filter( _applicants,
     (: _applicants[$1][APP_TYPE] == APPLIED :) ) ) )
   {
      if ( time() - _applicants[word][APP_TIME] > HIRE_TIMEOUT )
      {
         if ( sizeof( _applicants[word][APP_FOR] ) <
           sizeof( _applicants[word][APP_AGAINST] ) )
         {
            /* Applicant has more 'no' votes than 'yes' votes so
             * decline them.
             */
            remove_applicant( word );
            AUTO_MAILER->auto_mail( word, _proprietor, _shop_name, "",
              "Thank you for your recent application for employment "
              "with us.  Unfortunately, I have to inform you that you "
              "have been unsuccessful at this time.  Please feel free "
              "to re-apply again in the future, when your application "
              "will be re-considered.\n" );
            employee_log( word, "Application was declined" );
            add_declined( word );
         }
         else
         {
            /* Applicant has at least as many 'yes' votes as 'no' votes
             * so accept them.
             */
            AUTO_MAILER->auto_mail( word, _proprietor, _shop_name, "",
              "Congratulations!  You've been accepted to work at "+
              _shop_name+ ".  Please return to the shop within the next "
              "seven days to \"confirm\" that you wish to accept "
              "the position.\n" );
            _applicants[word][APP_TYPE] = HIRED;
            _applicants[word][APP_TIME] = time();
            employee_log( word, "Application was accepted" );
         }
      }
   }

   /* Number of places available */
   count = _max_emp - sizeof( _employees );

   if ( count < 0 )
   {
      return;
   }
   TCRE("shiannar", count+"");
   hirees = sort_array( keys( filter( _applicants,
     (: _applicants[$1][APP_TYPE] == AWAITING :) ) ),
     (: _applicants[$1][APP_TIME] - _applicants[$2][APP_TIME] :) );

   /* See if we can hire all people awaiting a vacancy */
   if ( count > sizeof( hirees ) )
   {
      count = sizeof( hirees );
   }

   /* Hire as many people as we can */
   for ( x = 0; x < count; x++ )
   {
      hire( hirees[x] );
   }
   save_me();
}
/* check_hire_list() */

/**
 * @ignore yes
 * Send a mail to each applicant awaiting a vacancy to let them know
 * their position in the queue.
 */
void mail_hirees() {
   int x;
   string *hirees;

   /* Make sure we are mailing the correct person with the correct position
    * by sorting the list by time.
    */
   hirees = sort_array( keys( filter( _applicants,
     (: _applicants[$1][APP_TYPE] == AWAITING :) ) ),
     (: _applicants[$1][APP_TIME] - _applicants[$2][APP_TIME] :) );

   for( x = 0; x < sizeof( hirees ); x++ ) {
      AUTO_MAILER->auto_mail( hirees[x], _proprietor, _shop_name, "",
        "I am writing to inform you that you have now moved to position "+
        query_num( x + 1 )+ " in the employment waiting list.  If you "
        "are not near the top of the list, please be patient.\nThank you.\n");
   }

} /* mail_hirees() */

/**
 * @ignore yes
 * Employee bits are set upon promotion, or when clocking in.
 */
private void set_employee( string word, int bit ) {
   if( !_employees[word] )
       return;

   if( bit < EMPLOYEE || bit > CLOCKED_IN ) {
#ifdef DEBUG
       debug_printf("Trying to set an employee bit < %d || > %d\n",
                    EMPLOYEE, CLOCKED_IN );
#endif
       return;
   }

   _employees[word][EMP_POINTS] |= bit;
   save_emps();

} /* set_employee() */

/**
 * @ignore yes
 * Employee bits are reset on clocking out.
 */
void reset_employee( string word, int bit ) {
   if( !_employees[word] )
       return;

   if( bit < EMPLOYEE || bit > CLOCKED_IN ) {
#ifdef DEBUG
       debug_printf("Trying to reset an employee bit < %d || > %d\n",
                    EMPLOYEE, CLOCKED_IN );
#endif
      return;
   }

   _employees[word][EMP_POINTS] -= _employees[word][EMP_POINTS] & bit;
   save_emps();
} /* reset_employee() */


/**
 * Query the list of items sold by the shop.
 * @return The list of items, formatted nicely in a multiple_short string.
 */
string query_list_string() {
   if( !sizeof( _list ) )
       return "absolutely nothing at the moment";

   return query_multiple_short( keys( _list ) );
} /* query_list_string() */

/**
 * Query the list of items sold by the shop.
 * @return The list of items in array form.
 */
string *query_list_array() { return copy(m_indices( _list ) + ({ })); }

/**
 * Query the list of items sold by the shop.
 * @return The list of items in mapping form.
 */
mapping query_list_mapping() { return copy( _list ) + ([]); }

/**
 * @ignore yes
 * Used by the shop front when an applicant confirms their employment
 * after being accepted.
 */
private void confirm_employment( string applicant )
{
   applicant = lower_case( applicant );
   _applicants[applicant][APP_TYPE] = AWAITING;
   _applicants[applicant][APP_TIME] = time();
   tell_object( find_player( applicant ), "You have now been added to "
     "our waiting list.  You will be notified of your position in the "
     "list as it changes.  You may \"cancel\" your application at "
     "any time.  You are currently at position " +
     sizeof( m_indices( filter( _applicants,
     (: _applicants[$1][APP_TYPE] == AWAITING :) ) ) )+
     " in the waiting list.\n" );
   save_me();
}
/* confirm_employment() */


/**
 * @ignore yes
 * Used when employees are fired by managers, or automatically.
 */
private void fire_them( string word, string them, string reason )
{
   if ( !_employees[them] )
   {
      return;
   }
   BANK->adjust_account( them, BANKS[_employees[them][EMP_BANK]][1],
     _employees[them][EMP_PAY] );
   shop_log( ACCOUNTS, _proprietor, "paid "+
     MONEY_HAND->money_value_string( _employees[them][EMP_PAY], _place )+
     " to "+ capitalize( them ) );
   shop_log( PERSONNEL, word, "fired "+ capitalize( them ) +
     " for "+ reason );
   AUTO_MAILER->auto_mail( them, word, _shop_name, "",
      "Unfortunately, I have to inform you that you have today "
      "been fired for " + reason + ".  You have been paid the sum of "+
      MONEY_HAND->money_value_string( _employees[them][EMP_PAY], _place )+
      " for the work you have carried out to this date.\nIf you feel you "
      "have been unfairly dismissed, please refer to a manager.\n" );
   employee_log( them, "Fired by "+ capitalize( word )+
     " for "+ reason );
   remove_employee( them );
}
/* fire_them() */


/**
 * @ignore yes
 * Remove this person from the list of people banned from the shop.
 */
private void remove_baddie( string word )
{
   if ( !query_baddie( word ) )
   {
      return;
   }
   map_delete( _baddies, word );
   save_me();
}
/* remove_baddie() */


/**
 * @ignore yes
 * Called once a day to conduct the shop's daily review.
 * This method is the daily maintenance function for the shop.  It checks that
 * employees are still valid players, and not creators.  It conducts automatic
 * promotions, and handles demotions for inactive employees.  It also updates
 * the lists of declined applicants and banned people and removes that status
 * if applicable.  Finally, it calls the check_hire_list function to see if
 * we can hire any new employees.
 */
void review_employees()
{
   int prom, prom_number, managers, time;
   string word, *promos, promopost, *emps;

   emps = _retired;
   emps += m_indices( _employees );
   foreach ( word in emps )
   {
      if ( !"/secure/login"->test_user( word ) )
      {
         /* Make sure we are not firing the npc shopkeeper */
         if ( _employees[word][EMP_POINTS] & NPC )
         {
            continue;
         }
         fire_them( _proprietor, word, "not existing" );
      }
      if ( creatorp(word) )
      {
         fire_them( _proprietor, word, "being a creator" );
      }
   }

   promos = ({ });
   prom = FALSE;
   time = time();

   /* Check for inactive managers */
   foreach ( word in get_managers() )
   {
      if ( ( time - _employees[ word ][EMP_TIME] ) >
        (60*60*24*MGR_DEMOTE) )
      {
         demote( _proprietor, word );
      }
      else if ( time - _employees[word][EMP_TIME] > (60*60*24*MGR_WARN) &&
        !_employees[word][EMP_INACTIVE] )
      {
         AUTO_MAILER->auto_mail( word, _proprietor, "Poor attendance",
           "", "It has come to my attention that you have now been "
           "inactive for over " + MGR_WARN+ " days.  As you are a manager, "
           "you are required to meet certain levels of attendance.  "
           "You are now in serious danger of being demoted without "
           "further warning.\n---\n" + _proprietor+ " (proprietor)\n" );
         _employees[word][EMP_INACTIVE] = TRUE;
         employee_log( word, "Warned about inactivity" );
         shop_log( PERSONNEL, _proprietor, "warned "+
               capitalize( word ) + " about inactivity");
      }
   }

   /* Check supervisors for inactivity or promotion.  Sorted by points so
    * people promoted in order.
    */
   foreach( word in sort_array( get_supervisors(),
     (: _employees[$1][EMP_POINTS] - _employees[$2][EMP_POINTS] :) ) )
   {
      if ( time - _employees[word][EMP_TIME] > (60*60*24*SPR_DEMOTE) )
      {
         demote( _proprietor, word );
      }
      else if ( time - _employees[word][EMP_TIME] > (60*60*24*SPR_WARN) &&
        !_employees[word][EMP_INACTIVE] )
      {
         AUTO_MAILER->auto_mail( word, _proprietor, "Poor attendance",
           "", "It has come to my attention that you have now been "
           "inactive for over "+ SPR_WARN+ " days.  As you are a supervisor, "
           "you are required to meet certain levels of attendance.  "
           "You are now in serious danger of being demoted without "
           "further warning.\n---\n" + _proprietor+ " (proprietor)\n" );
         _employees[word][EMP_INACTIVE] = TRUE;
         employee_log( word, "Warned about inactivity" );
         shop_log( PERSONNEL, _proprietor, "warned "+
               capitalize( word ) + " about inactivity");
      }
      else
      {
         /* See if any managerial vacancies.  If so, and this person has
          * sufficient points & is not being ignored for promotion,
          * promote them.
          */
         prom_number = ( _max_emp * PERCENT_M ) / 100;
         if ( ( _employees[word][EMP_POINTS] > 32 * MANAGER_POINTS ) &&
           sizeof( get_managers() ) < prom_number &&
           !_employees[word][EMP_NOPROMOTE] )
         {
            set_employee( word, MANAGER );
            shop_log( PERSONNEL, _proprietor, "promoted "+
              capitalize( word )+ " to manager" );
            employee_log( word, "Promoted to manager" );
            AUTO_MAILER->auto_mail( word, _proprietor, "Promotion!",
              "", "Congratulations!  You've been promoted to manager "
              "of "+ _shop_name+ ".  You'll find that you can now enter "
              "the managers' office.  Please remember to use the \"memo\" "
              "facility from there to discuss any major admin points with "
              "other managers.  This includes hiring, firing, and so on.\n" );
            promos += ({ word });
            prom = TRUE;
         }
      }
   }

   /* Check employees for inactivity or promotion.  Sorted by points so
    * people promoted in order.
    */
   foreach( word in sort_array( get_employees(),
     (: _employees[$1][EMP_POINTS] - _employees[$2][EMP_POINTS] :) ) )
   {
      if ( _employees[word][EMP_POINTS] & NPC )
      {
         continue;
      }
      if ( time - _employees[word][EMP_TIME] > (60*60*24*EMP_FIRE) )
      {
         fire_them( _proprietor, word, "serious inactivity" );
         continue;
      }
      if ( time - _employees[word][EMP_TIME] > (60*60*24*EMP_WARN) )
      {
         if ( !_employees[word][EMP_INACTIVE] )
         {
            AUTO_MAILER->auto_mail( word, _proprietor, "Inactivity",
              "", "It has come to my attention that you have now been "
              "inactive for over "+ EMP_WARN+ " days.  Unless this "
              "situation is resolved, the management may have no option "
              "but to terminate your employment.\n---\n"+ _proprietor+
              " (proprietor)\n" );
            _employees[word][EMP_INACTIVE] = TRUE;
            shop_log( PERSONNEL, _proprietor, "warned "+
              capitalize( word )+ " about inactivity" );
            employee_log( word, "Warned about inactivity" );
         }
      }
      else
      {
         /* See if any supervisory vacancies.  If so, and this person has
          * sufficient points & is not being ignored for promotion,
          * promote them.
          */
         prom_number = ( _max_emp * PERCENT_S ) / 100;
         if ( ( _employees[word][EMP_POINTS] > 32 * SUPER_POINTS ) &&
           sizeof( get_supervisors() ) < prom_number &&
           !_employees[word][EMP_NOPROMOTE] )
         {
            if( _employees[word][EMP_POINTS] & CLOCKED_IN )
            {
               _employees[word][EMP_POINTS] = (SUPER_POINTS * 32) +
                 EMPLOYEE+ SUPERVISOR + CLOCKED_IN;
            }
            else
            {
               _employees[word][EMP_POINTS] = (SUPER_POINTS * 32) +
                 EMPLOYEE+ SUPERVISOR;
            }
            shop_log( PERSONNEL, _proprietor, "promoted "+
              capitalize( word )+ " to supervisor" );
            employee_log( word, "Promoted to supervisor" );
            AUTO_MAILER->auto_mail( word, _proprietor, "Promotion!", "",
              "Congratulations!  You've been promoted to supervisor "
              "of "+ _shop_name+ ".  You will now be able to use your "
              "newly acquired supervisor commands.\n" );
            promos += ({ word });
            prom = TRUE;
         }
      }
   }

   /* Post about promotions */
   if ( prom )
   {
      promopost = "The following employees have been promoted:\n\n";
      foreach ( word in promos )
      {
         promopost += sprintf( "     %s has been promoted to %s\n",
           capitalize( word ), (_employees[word][EMP_POINTS] & MANAGER)?
           "manager":"supervisor");
      }
      promopost += "\nCongratulations!\n";
      add_board_message( "Promotions", promopost );
   }

   /* Check the list of banned people */
   foreach ( word in m_indices( _baddies ) )
   {
      if ( time - _baddies[word][BAD_TIME] > (60*60*24*BAN_LENGTH) )
      {
         remove_baddie( word );
      }
   }

   /* Check the list of declined applicants */
   foreach ( word in m_indices( _declined ) )
   {
      if ( time - _declined[word] > (60*60*24*DECLINE_LENGTH) )
      {
         remove_declined( word );
      }
   }

   /* See if anyone can be hired */
   remove_call_out( _call_hire_list );
   _call_hire_list = call_out( "check_hire_list", 5 );
   save_emps();

   /* Update policies */
   managers = sizeof( get_managers() ) + sizeof( get_retired() );
   foreach ( word in m_indices( _new_policies ) )
   {
      if ( time - _new_policies[word][0] > (60*60*24*14) )
      {
         if ( sizeof( _new_policies[word][3] ) > managers / 2 )
         {
            add_policy( word );
         }
         else
         {
            remove_policy( word );
         }
      }
   }

   /* Update the player history data */
   foreach ( word in m_indices( _history ) )
   {
      if ( !"/secure/login"->test_user( word ) ||
        creatorp( word ) ||
        !_times[word] || _times[word] < (time - HIST_TIMEOUT) )
      {
         map_delete( _times, word );
         map_delete( _history, word );
      }
   }
   save_hist();
   save_times();
}
/* review_employees() */


/**
 * Calculate total employee wage packet for this month.
 * @return The current value of the months' wages.
 */
int calc_pay()
{
   string word, *emps;
   int amount = 0;

   emps = m_indices( _employees );
   foreach ( word in emps )
   {
      if ( _employees[word][EMP_POINTS] & NPC )
      {
         continue;
      }
      amount += _employees[word][EMP_PAY];
   }
   return amount;
}
/* calc_pay() */


/**
 * Calculate the months' projected bonuses.
 * These values are based upon the current staff levels, as well as
 * the amount of money in the bonus account.  The result is written
 * directly to this_player().
 */
void calc_bonus()
{
   int bonus_val, bonus_divisor = 0;
   string word;

   foreach ( word in m_indices( _employees ) )
   {
      if ( _employees[word][EMP_POINTS] & NPC ||
        _employees[word][EMP_NOBONUS] )
      {
         continue;
      }
      if ( _employees[word][EMP_POINTS] & MANAGER )
      {
         bonus_divisor += 4;
      }
      else if ( _employees[word][EMP_POINTS] & SUPERVISOR )
      {
         bonus_divisor += 3;
      }
      else
      {
         bonus_divisor += 2;
      }
   }
   if ( !bonus_divisor )
   {
      bonus_val = _accounts["bonus"];
   }
   else
   {
      bonus_val = ( _accounts["bonus"] * 2 ) / bonus_divisor;
   }
   word = "Based on the bonus fund of "+
     MONEY_HAND->money_value_string( _accounts["bonus"], _place )+
     ", the following bonuses are anticipated:\n"
     "\n     Managers    - "+
     MONEY_HAND->money_value_string( bonus_val * 2, _place )+
     "\n     Supervisors - "+
     MONEY_HAND->money_value_string( to_int( bonus_val * 1.5 ), _place )+
     "\n     Employees   - "+
     MONEY_HAND->money_value_string( bonus_val, _place )+ "\n";
   tell_object( this_player(), word );
}
/* calc_bonus() */


/**
 * @ignore yes
 * Called once a month to conduct the shop's monthly review.
 * This method is the monthly maintenance function for the shop.  This review
 * involves paying employees direct into their nominated bank account, and
 * awarding bonuses based on the current value of the bonus fund.  If there is
 * not enough money in the profit account to pay the correct amount, the employees
 * are paid on a pro-rata basis.
 */
void monthly_review(string month) {
   int amount, bonus_divisor, cabinet_cost, pay;
   float pay_multiplier;
   string *emps, post, word;

   // MONTH THINGIE IS BUGGERED HERE.

   amount = bonus_divisor = 0;
   pay_multiplier = 1.0;
   emps = keys( _employees );
   amount = calc_pay();

   cabinet_cost = ( _num_cabinets - MIN_CABINETS ) * CABINET_COST;
   adjust_profit( _proprietor, -cabinet_cost );
   shop_log( ACCOUNTS, _proprietor, "paid "+
       MONEY_H->money_value_string( cabinet_cost, _place )+" for the rent "
       "of " + ( _num_cabinets - MIN_CABINETS ) + " cabinets" );
   if( amount > _accounts["profit"] ) {
       pay_multiplier = _accounts["profit"] / amount;
   }
   foreach ( word in emps ) {
      if( _employees[word][EMP_POINTS] & NPC ) {
          continue;
      }
      if( !_employees[word][EMP_PAY] ) {
          continue;
      }
      pay = to_int(_employees[word][EMP_PAY] * pay_multiplier);
      BANK->adjust_account( word, BANKS[_employees[word][EMP_BANK]][1],
        pay );
      shop_log( ACCOUNTS, _proprietor, "paid "+ MONEY_HAND->
        money_value_string( pay, _place )+ " to "+ capitalize( word ) );
      AUTO_MAILER->auto_mail( word, _proprietor,
        "Pay advice for "+ _last_month, "", "For your work during "+
        _last_month+ ", you have been paid a total of "+
        MONEY_HAND->money_value_string( pay, _place )+
        ".  Keep up the good work.\n--\n"+ _proprietor+ " (proprietor)\n" );
      _employees[word][EMP_PAY] = 0;
      _accounts["profit"] -= pay;
   }
   _bonus += _accounts["bonus"];
   _accounts["bonus"] = 0;
   foreach ( word in m_indices( _employees ) )
   {
      if ( _employees[word][EMP_POINTS] & NPC ||
        _employees[word][EMP_NOBONUS] )
      {
         continue;
      }
      if ( _employees[word][EMP_POINTS] & MANAGER )
      {
         bonus_divisor += 4;
      }
      else if ( _employees[word][EMP_POINTS] & SUPERVISOR )
      {
         bonus_divisor += 3;
      }
      else
      {
         bonus_divisor += 2;
      }
   }
   if ( !bonus_divisor )
   {
      _bonus_val = _bonus;
   }
   else
   {
      _bonus_val = ( _bonus * 2 ) / bonus_divisor;
   }
   _got_bonus = ({ });
   foreach ( word in m_indices( _employees ) )
   {
      if ( _employees[word][EMP_POINTS] & NPC )
      {
         continue;
      }
      if ( _employees[word][EMP_NOBONUS] )
      {
         _employees[word][EMP_NOBONUS]--;
         _got_bonus += ({ word });
      }
   }
   post = "Based on the bonus fund of "+
     MONEY_HAND->money_value_string( _bonus, _place )+
     " for "+ month+ ", the following bonuses have been awarded:\n"
     "\n     Managers    - "+
     MONEY_HAND->money_value_string( _bonus_val * 2, _place )+
     "\n     Supervisors - "+
     MONEY_HAND->money_value_string( to_int( _bonus_val * 1.5 ), _place )+
     "\n     Employees   - "+
     MONEY_HAND->money_value_string( _bonus_val, _place )+
     "\n\nKeep up the good work.\n";
   add_board_message( "Bonuses for "+ month, post );
   shop_log( ACCOUNTS, _proprietor, "paid out "+
     MONEY_HAND->money_value_string( _bonus, _place )+
     " in bonuses for "+ month );
   _last_month = month;
   save_me();
   save_emps();
}
/* monthly_review() */


/**
 * Query the people banned from the shop.
 * This method returns a mapping of the people banned from this shop, along
 * with the time that they were banned, the person banning them, and the
 * reason they were banned.  The format for this mapping is:<br>
 * ([ person:({ reason, banner, time }) ])
 * @return The mapping, formatted above.
 */
mapping get_baddies() { return copy(_baddies + ([ ])); }


/**
 * @ignore yes
 * Ban this person from the shop.
 * This person will be banned for a specific period, and will not be allowed
 * back in the shop within this period.  People can be banned by managers, or
 * automatically for attacking employees.
 */
private void add_baddie( string word, string reason, string banner )
{
   object ob;

   word = lower_case( word );
   if ( query_baddie( word ) )
   {
      /*
       * Added this bit after discovering someone had been banned 75
       * times for killing Gretta @ Tarnach's- all at the same time.
       */
      if ( _baddies[word][BAD_TIME] == time() ||
         reason == _baddies[word][BAD_REASON] )
      {
         return;
      }
      remove_baddie( word );
   }
   if ( !sizeof( _baddies ) )
   {
      _baddies = ([ word:({ "", "", 0, }) ]);
   }
   else
   {
      _baddies += ([ word:({ "", "", 0, }) ]);
   }
   _baddies[word][BAD_REASON] = reason;
   _baddies[word][BAD_BANNER] = banner;
   _baddies[word][BAD_TIME] = time();
   save_me();
   shop_log( GENERAL, capitalize(banner), "banned "+ capitalize( word )+
     " for "+ reason );
   employee_log( word, sprintf( "Banned by %s for %s.", capitalize(banner),
     reason ) );
   fire_them( _proprietor, word, reason );
   remove_applicant( word );
   if ( !( ob = find_player( word ) ) )
   {
      return;
   }

   /* If this person is in the shop front, move them outside. */
   if ( environment( ob ) == find_object( _shop_front ) )
   {
      tell_room( _shop_front, ob->query_short()+ " drifts out of the door, "
        "seemingly against "+ ob->query_possessive()+ " will.\n", ({ ob }) );
      tell_object( ob , "You feel yourself pushed out of the shop "
        "by a mysterious force.\n" );
      tell_room( _shop_front->query_outside(), ob->query_short()+
        " drifts through the door of "+ _shop_name +
        ", seemingly against "+ ob->query_possessive()+ " will.\n", ({ ob }) );
      ob->move( _shop_front->query_outside() );
   }
}
/* add_baddie() */


/**
 * Query the number of employees currently clocked in.
 * This function will also clock out any employees that are no longer on DW.
 * @return The number of employees clocked in.
 */
int num_employees_in()
{
   int any = 0;
   string word;
   object ob;

   foreach ( word in m_indices( _employees ) )
   {
      if ( _employees[word][EMP_POINTS] & CLOCKED_IN )
      {
         if ( _employees[word][EMP_POINTS] & NPC )
         {
            continue;
         }
         if ( !( ob = find_player( word ) ) ||
           !interactive( ob ) )
         {
            reset_employee( word, CLOCKED_IN );
            shop_log( GENERAL, word, "was clocked out" );
         }
         else
         {
            any++;
         }
      }
   }
   return any;
}
/* num_employees_in() */


/**
 * @ignore yes
 * Called by the npc shopkeeper to limit loading patterns.
 */
void set_npc_time() { _npc_time = time(); }


/**
 * @ignore yes
 * Loads the npc shopkeeper and calls him/her/it to work.  Will only reload
 * the npc once every NPC_DELAY, unless clock_out is non-zero in which case the
 * npc will be loaded regardless - this parameter indicates that the npc is
 * being recalled due to an employee clocking out.
 */
void summon_shopkeeper( int clock_out )
{
   /* Already loaded */
   if ( find_object( _shopkeeper ) )
   {
      return;
   }

   /* Don't appear if any employees in */
   if ( num_employees_in() )
   {
      return;
   }

   /* Start shift */
   if ( ( time() - _npc_time > NPC_RELOAD ) || clock_out )
   {
      load_object(_shopkeeper)->start_shift();
   }
}
/* summon_shopkeeper() */


/**
 * @ignore yes
 * A nicely formatted employee list for the employee badge.
 */
string badge_list() {
   string word, temp_result, *results, tp_name;
   object ob, tp;

   results = ({});
   tp = this_player();
   tp_name = tp->query_name();

   foreach( word in sort_array( _retired, 1 ) ) {
      if ( ( ob = find_player( word ) ) && !ob->query_invis() ) {
         results += ({ "%^CYAN%^"+ ob->query_cap_name() +"%^RESET%^ (R)" });
      }
   }

   foreach ( word in get_managers() ) {
      temp_result = "";
      if ( ( ob = find_player( word ) ) && !ob->query_invis() ) {
         if( ( creatorp(tp) || ( _employees[tp_name][EMP_POINTS] & SUPERVISOR ) ) &&
             ( _employees[word][EMP_POINTS] & CLOCKED_IN ) ) {
             temp_result = "%^YELLOW%^";
         }
         results += ({ temp_result+ ob->query_cap_name()+ "%^RESET%^ (m)" });
      }
   }

   foreach( word in get_supervisors() ) {
      temp_result = "";
      if( ( ob = find_player( word ) ) && !ob->query_invis() ) {
         if( ( creatorp(tp) || ( _employees[tp_name][EMP_POINTS] & SUPERVISOR ) ) &&
             ( _employees[word][EMP_POINTS] & CLOCKED_IN ) ) {
             temp_result = "%^YELLOW%^";
         }
         results += ({ temp_result+ ob->query_cap_name()+ "%^RESET%^ (s)" });
      }
   }

   foreach( word in get_employees() ) {
      temp_result = "";
      if( ( ob = find_player( word ) ) && !ob->query_invis() ) {
         if( ( creatorp(tp) || ( _employees[tp_name][EMP_POINTS] & SUPERVISOR ) ) &&
             ( _employees[word][EMP_POINTS] & CLOCKED_IN ) ) {
             temp_result = "%^YELLOW%^";
         }
         results += ({ temp_result+ ob->query_cap_name()+ "%^RESET%^" });
      }
   }

   if( !sizeof( results ) ) {
      /* Will only occur if no employees logged on, and a creator is using
       * badge.
       */
      return "Just you, I'm afraid.\n";
   }

   return query_multiple_short( results ) + "\n";

} /* badge_list() */

/**
 * @ignore yes
 * The list of employees clocked in used by the extra_look in the shop front.
 */
string employees_clocked_in() {
   string word;
   object *words, ob;
   words = ({ });

   if( !num_employees_in() )
       return "No employees";

   foreach( word in keys( _employees ) ) {
      if( ( ob = find_player( word ) ) && !ob->query_invis() ) {
         if( _employees[word][EMP_POINTS] & CLOCKED_IN )
             words += ({ ob->query_cap_name() });
      }
   }

   return query_multiple_short( words );

} /* employees_clocked_in() */

/**
 * Checks to see if the specified employee is clocked in.
 * @param ob the object to check
 */
int employee_clocked_in(object ob) {
  if(!query_employee(ob->query_name())) return 0;
  return (_employees[ob->query_name()][EMP_POINTS] & CLOCKED_IN);
} /* employee_clocked_in() */

/**
 * @ignore yes
 * Used by the managers' office whenever a manager casts a vote
 * on an applicant.
 */
private void add_vote( string applicant, int vote ) {
   int managers;
   string voter;

   voter = this_player()->query_name();
   managers = sizeof( get_managers() );
   if ( vote == VABSTAIN )
   {
      _applicants[applicant][APP_ABSTAIN] += ({ voter });
   }
   else if ( vote == VFOR )
   {
      _applicants[applicant][APP_FOR] += ({ voter });
   }
   else
   {
       _applicants[applicant][APP_AGAINST] += ({ voter });
   }
   shop_log( GENERAL, voter, "voted on "+ capitalize( applicant ) );
   save_me();
   managers -= sizeof( _applicants[applicant][APP_ABSTAIN] );

   if ( sizeof( _applicants[applicant][APP_FOR] ) >= managers / 2 )
   {
      /* This applicant has the vote of at least 50%
       * of managers so hire them.
       */
      AUTO_MAILER->auto_mail( applicant, _proprietor, _shop_name, "",
        "Congratulations!  You've been accepted to work at "+
        _shop_name+ ".  Please return to the shop within the next "
        "seven days to \"confirm\" that you wish to accept "
        "the position.\n" );
      _applicants[applicant][APP_TYPE] = HIRED;
      _applicants[applicant][APP_TIME] = time();
      employee_log( applicant, "Application was accepted" );
   }
   else if ( sizeof( _applicants[applicant][APP_AGAINST] ) >
     managers / 2 )
   {
      /* This applicant has been voted against by over 50% of the
       * managers so decline them.
       */
      remove_applicant( applicant );
      AUTO_MAILER->auto_mail( applicant, _proprietor, _shop_name, "",
        "Thank you for your recent application for employment "
        "with us.  Unfortunately, I have to inform you that you "
        "have been unsuccessful at this time.  Please feel free "
        "to re-apply again in the future, when your application "
        "will be re-considered.\n" );
      employee_log( applicant, "Application was declined" );
      add_declined( applicant );
   }
}
/* add_vote() */


/**
 * @ignore yes
 * Used by the managers' office to determine whether a manager has
 * already voted on this applicant.
 */
int check_vote( string applicant, string voter )
{
   if ( member_array( voter, _applicants[applicant][APP_FOR] ) != -1 ||
     member_array( voter, _applicants[applicant][APP_AGAINST] ) != -1 ||
     member_array( voter, _applicants[applicant][APP_ABSTAIN] ) != -1 )
   {
      return TRUE;
   }
   return FALSE;
}
/* check_vote() */


/**
 * @ignore yes
 * Updates the chart with the average stock of an item.
 */
void update_averages()
{
   string words;

   foreach ( words in m_indices( _list ) )
   {
      _list[words][CHART_AVE] = ( _list[words][CHART_AVE] +
        query_stock( words ) + random(2) ) / 2;
   }
   save_list();
}
/* update_averages() */


/**
 * @ignore yes
 * Query if the shop sells this item.
 * @param item The item to query.
 * @return TRUE or FALSE
 */
int query_on_list( string item ) { return (!_list[item])?FALSE:TRUE; }


/**
 * @ignore yes
 * Add an item for the shop to deal in.
 */
private void put_on_list( string word )
{
   if ( !_list[word] )
   {
      _list[word] = ({ 5, 0, 20, 25, ({}), 0, 0, 0 });
      save_list();
   }
}
/* put_on_list() */


/**
 * @ignore yes
 * Stop the shop dealing in this item.
 */
private void take_off_list( string word )
{
   if ( !_list[word] )
   {
      return;
   }
   map_delete( _list, word );
   save_list();
}
/* take_off_list() */


/**
 * @ignore yes
 * Query the maximum number of this item allowed in stock.
 * @param item The item to query.
 * @return The maximum stock.
 */
int query_max( string item )
{
   return ( !_list[item] ) ? 0 : copy(_list[item][CHART_MAX]);
}
/* query_max() */


/**
 * @ignore yes
 * Set the maximum number of this item allowed in stock.
 */
private void set_max( string word, int number )
{
   if ( !_list[word] )
   {
      return;
   }
   _list[word][CHART_MAX] = number;
   save_list();
}
/* set_max() */


/**
 * @ignore yes
 * Query the average number of this item in stock.
 * @param item The item to query.
 * @return The average stock.
 */
int query_ave( string item )
{
   return ( !_list[item] ) ? 0 : copy(_list[item][CHART_AVE]);
}
/* query_ave() */


/**
 * @ignore yes
 * Query the buying price of this item.
 * This is the actual value, in the smallest unit of local currency
 * (eg. pence, farthings etc), rather than the absolute value.
 * @param item The item to query.
 * @return The buy price.
 */
int query_buy( string item )
{
   return ( !_list[item] ) ? 0 : copy(_list[item][CHART_BUY]);
}
/* query_buy() */


/**
 * @ignore yes
 * Set the buy price of this item.
 */
private void set_buy( string word, int number )
{
   if ( !_list[ word ] )
   {
      return;
   }
   _list[word][CHART_BUY] = number;
   save_list();
}
/* set_buy() */


/**
 * @ignore yes
 * Query the sell price of this item.
 * This is the actual value, in the smallest unit of local currency
 * (eg. pence, farthings etc), rather than the absolute value.
 * @param item The item to query.
 * @return The sell price.
 */
int query_sell( string item )
{
   return ( !_list[item] ) ? 0 : copy(_list[item][CHART_SELL]);
}
/* query_sell() */


/**
 * @ignore yes
 * Set the sell price of this item.
 */
private void set_sell( string word, int number )
{
   if ( !_list[word] )
   {
      return;
   }
   _list[word][CHART_SELL] = number;
   save_list();
}
/* set_sell() */


/**
 * @ignore yes
 * Query whether this cabinet is currently assigned to any items.
 * @param cabinet The cabinet number ( between 1 and number of cabinets )
 * @return TRUE or FALSE
 */
int query_cabinet_used( int cabinet )
{
   string word;

   foreach( word in m_indices(_list) )
   {
      if ( member_array( cabinet, _list[word][CHART_CAB] ) != -1 )
      {
         return TRUE;
      }
   }
   return FALSE;
}
/* query_cabinet_used() */


/**
 * @ignore yes
 * Query which cabinets are assigned to this item.
 * @param item The item to query.
 * @return An array of cabinet numbers assigned to the item.
 */
int *query_cabinet( string item )
{
   return ( !_list[item] ) ? ({}) : copy(_list[item][CHART_CAB]);
}
/* query_cabinet() */


/**
 * @ignore yes
 * Assign an item to use a cabinet.
 */
private void add_chart_cabinet( string word, int number )
{
   if ( !_list[word] )
   {
      return;
   }
   _list[word][CHART_CAB] += ({ number });
   _list[word][CHART_CAB] = sort_array( _list[word][CHART_CAB], 1 );
   save_list();
}
/* add_chart_cabinet() */


/**
 * @ignore yes
 * Stop an item using a cabinet.
 */
private void remove_chart_cabinet( string word, int number )
{
   if ( !_list[word] )
   {
      return;
   }
   _list[word][CHART_CAB] -= ({ number });
   save_list();
}
/* remove_chart_cabinet() */


/**
 * @ignore yes
 * Used by the employee list to show managers & creators the last
 * time an employee was active.  Employees will be highlighted yellow
 * if they are currently on an inactivity warning, and red if they are
 * within 7 days of being fired/demoted
 */
private string query_worked( string emp )
{
   string blurb;

   /* Clocked in */
   if ( _employees[emp][EMP_POINTS] & CLOCKED_IN )
   {
      return " is currently clocked in";
   }

   /* NPC */
   if ( _employees[emp][EMP_POINTS] & NPC )
   {
      return " has gone home for tea";
   }

   /* On leave */
   if ( _employees[emp][EMP_TIME] > time() )
   {
      return " - %^CYAN%^on leave until "+
        ctime( _employees[emp][EMP_TIME]  ) + "%^RESET%^";
   }

   blurb = " - last action ";

   if ( _employees[emp][EMP_POINTS] & MANAGER )
   {
      if ( ( time() - _employees[emp][EMP_TIME] ) > ((60*60*24*MGR_DEMOTE)-7) )
      {
         blurb += "%^RED%^";
      }
      else if ( ( time() - _employees[emp][EMP_TIME] ) > (60*60*24*MGR_WARN) )
      {
         blurb += "%^RED%^";
      }
   }
   else if ( _employees[emp][EMP_POINTS] & SUPERVISOR )
   {
      if ( ( time() - _employees[emp][EMP_TIME] ) > ((60*60*24*SPR_DEMOTE)-7) )
      {
         blurb += "%^RED%^";
      }
      else if ( ( time() - _employees[emp][EMP_TIME] ) > (60*60*24*SPR_WARN) )
      {
         blurb += "%^YELLOW%^";
      }
   }
   else if ( ( time() - _employees[emp][EMP_TIME] ) > ((60*60*24*EMP_FIRE)-7) )
   {
      blurb += "%^RED%^";
   }
   else if ( ( time() - _employees[emp][EMP_TIME] ) > (60*60*24*EMP_WARN) )
   {
      blurb += "%^YELLOW%^";
   }
   blurb += ctime( _employees[emp][EMP_TIME] ) + "%^RESET%^";
   return( blurb );
}
/* query_worked() */


/**
 * @ignore yes
 * This function is used by employees to clock in and out of work.
 * Clocking out may also summon the npc shopkeeper.
 */
int do_clock( string clock )
{
   string word;
   object tp;

   tp=this_player();

   if ( creatorp(tp) ) {
      tell_object( tp, "Creators cannot clock "+clock+"!\n" );
      return 1;
   }

   word = tp->query_name();
   switch( clock )
   {
     case "in" :
        if ( _employees[word][EMP_POINTS] & CLOCKED_IN )
        {
           tell_object( tp, "You are already clocked in!\n" );
           return 1;
        }

        /* Stop the shopkeeper appearing if on their way */
        remove_call_out( _call_summon );

        /* Is this person a cre alt? If so, prevent promotion. */
        if ( tp->query_property( "no score" ) )
        {
           _employees[word][EMP_NOPROMOTE] = TRUE;
        }
        set_employee( word, CLOCKED_IN );
        break;
     case "out" :
        if ( !_employees[word][EMP_POINTS] & CLOCKED_IN )
        {
           tell_object( tp, "You are already clocked out!\n" );
           return 1;
        }

        /* Call npc shopkeeper to work */
        remove_call_out( _call_summon );
        _call_summon = call_out( "summon_shopkeeper", 60, 1 );
        reset_employee( word, CLOCKED_IN );
        break;
   }
   add_succeeded_mess( "$N $V "+ clock+ ".\n" );
   shop_log( GENERAL, word, "clocked "+ clock );
   return 1;
}
/* do_clock() */


/**
 * @ignore yes
 * Displays an employee's percentage towards promotion, if applicable.
 * Displays all employees' scores to creators.
 * Displays last-action (leave) times to managers.
 */
string list_stuff( string word )
{
   string results = "", tp;

   /* Nothing to display for retired managers */
   if ( member_array( word, _retired ) != -1 )
   {
      return "\n";
   }

   tp = this_player()->query_name();

   /* Npc shopkeeper */
   if ( _employees[word][EMP_POINTS] & NPC )
   {
      return query_worked( word ) + "\n";
   }

   /* Creator viewing - display all scores */
   if ( creatorp(this_player()) )
   {
      results = " ["+ ( _employees[word][EMP_POINTS] / 32 ) +"]";
   }
   else if ( ( word == tp ) && !(_employees[word][EMP_POINTS] & MANAGER) )
   {
      if ( _employees[word][EMP_POINTS] & SUPERVISOR )
      {
         results = " ["+ ( ( 100 * ( _employees[word][EMP_POINTS] /
           32 - SUPER_POINTS )) /
           ( MANAGER_POINTS - SUPER_POINTS )) +"%]";
      }
      else
      {
         results = " ["+ ( ( 100 * ( _employees[word][EMP_POINTS] / 32 ) ) /
           SUPER_POINTS ) +"%]";
      }
   }

   /* Last-action times displayed to managers & creators */
   if ( creatorp(this_player()) || (_employees[tp][EMP_POINTS] & MANAGER) )
   {
      results += query_worked( word );
   }
   return results + "\n";
}
/* list_stuff() */


/**
 * @ignore yes
 * Employee wishes to terminate their employment with the shop.
 */
int do_resign()
{
   string word;

   word = this_player()->query_name();
   add_succeeded_mess( "$N $V.\n" );
   remove_employee( word );
   shop_log( PERSONNEL, word, "resigned" );
   employee_log( word, "Resigned" );
   return 1;
}
/* do_resign() */


/**
 * @ignore yes
 * The list of employees in the shop.
 * This list is displayed sorted primarily by status (Retired, manager,
 * supervisor, riff-raff) and then alphabetically within those groups.
 * It also highlights those employees currently logged on (as long as they
 * are visible).
 */
int do_list() {
   string word, results;
   int emps_in;
   object ob;

   results = "   Employees of "+ _shop_name + "\n"
     "     As at " + ctime( time() ) + "\n\n";

   /* Retired managers */
   foreach ( word in sort_array( _retired, 1 ) )
   {
      if ( (ob = find_player( word )) && !ob->query_invis() )
      {
         results += "%^GREEN%^";
      }
      results += "     "+ capitalize( word )+
      "%^RESET%^ (retired manager)\n";
   }

   /* Managers */
   foreach ( word in get_managers() )
   {
      if ( (ob = find_player( word )) && !ob->query_invis() )
      {
         emps_in ++;
         results += "%^GREEN%^";
      }
      results += "     "+ capitalize( word )+ "%^RESET%^ (manager)"+
        list_stuff( word );
   }

   /* Supervisors */
   foreach ( word in get_supervisors() )
   {
      if ( (ob = find_player( word )) && !ob->query_invis() )
      {
         emps_in ++;
         results += "%^GREEN%^";
      }
      results += "     "+ capitalize( word )+ "%^RESET%^ (supervisor)"+
        list_stuff( word );
   }

   /* Riff-raff */
   foreach ( word in get_employees() )
   {
      if ( (ob = find_player( word )) && !ob->query_invis() )
      {
         emps_in ++;
         results += "%^GREEN%^";
      }
      results += "     "+ capitalize( word )+ "%^RESET%^"+
        list_stuff( word );
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
        " on Discworld at the moment, with "+ query_num( num_employees_in(),
          0 ) + " currently clocked in.\n\n";
   }

   tell_object( this_player(), "$P$Employees$P$"+ results );
   add_succeeded_mess( "" );
   return 1;
}
/* do_list() */

/**
 * @ignore yes
 * Claim a badge, handbook, or bonus.
 */
int do_claim( string item ) {
   object thing, tp;
   int give_bonus;
   string tp_name;

   tp = this_player();
   switch( item ) {
     case "badge" :
        thing = clone_object( BADGE );
        thing->set_props( file_name( this_object() ),
          tp->query_name() );
        break;
     case "handbook" :
        thing = clone_object( STAFF_BOOK );
        thing->set_read_mess("\n   "+ _shop_name+ "\n\n"
          "   Staff Handbook\n\n   This handbook belongs to: "+
          tp->query_short()+ "\n\n", "common", 100 );
        thing->set_office( file_name( this_object() ) );
        break;
     case "bonus" :
        tp_name = tp->query_name();
        /* Already claimed, new employee, or had bonus suspended. */
        if ( member_array( tp_name, _got_bonus ) != -1 )
        {
           tell_object( tp, "You are not entitled to a "
             "bonus this month!\n" );
           return 1;
        }

        /* Value depends on status */
        if ( _employees[tp_name][EMP_POINTS] & MANAGER )
        {
           give_bonus = _bonus_val * 2;
        }
        if ( _employees[tp_name][EMP_POINTS] & SUPERVISOR )
        {
           give_bonus = to_int( _bonus_val * 1.5 );
        }
        else
        {
           give_bonus = _bonus_val;
        }
        /* Nothing to give */
        if ( !give_bonus )
        {
           tell_object( tp,  "There is no money in the bonus "
             "fund this month.\n" );
           return 1;
        }

        /* Prevent them from claiming again this month */
        _got_bonus += ({ tp_name });
        _bonus -= give_bonus;

        /* Update value of unclaimed bonus */
        if ( _bonus < 0 )
        {
           _bonus = 0;
        }

        thing = MONEY_HAND->make_new_amount( give_bonus, _place );
        shop_log( GENERAL, tp_name, "claimed "+
          MONEY_HAND->money_value_string( give_bonus, _place ) );
        if ( thing->move( tp ) != MOVE_OK )
        {
           thing->move( environment( tp ) );
           tell_object( tp, "You drop "+ thing->query_short()+
             " as you're carrying too much.\n" );
        }
        save_me();
        add_succeeded_mess( "$N $V "+ MONEY_HAND->
          money_value_string( give_bonus, _place )+ ".\n" );
        return 1;
        break;
   }
   if ( thing->move( tp ) != MOVE_OK )
   {
      thing->move( this_object() );
      tell_object( tp, "You drop your "+ item+
        " as you're carrying too much.\n" );
   }
   add_succeeded_mess( "$N $V a new "+ item+ ".\n" );
   return 1;
}
/* do_claim() */


/**
 * @ignore yes
 * This employee has requested to be passed over for promotion.
 */
int do_promote( string on )
{
   object tp;

   add_succeeded_mess( "" );
   tp = this_player();
   switch ( on )
   {
     case "on" :
        _employees[tp->query_name()][EMP_NOPROMOTE] = TRUE;
        tell_object( tp, "You have now requested to be "
          "passed over for promotion.\n" );
        break;
     case "off" :
        if ( tp->query_property( "no score" ) ) {
           tell_object( tp, "Creator alts cannot be promoted.\n" );
           return 1;
        }
        _employees[tp->query_name()][EMP_NOPROMOTE] = FALSE;
        tell_object( tp, "You have now requested to be "
          "considered for promotion.\n" );
        break;
   }
   save_emps();
   return 1;
}
/* do_promote() */


/**
 * @ignore yes
 * Display or update the employee's bank details.
 */
int do_bank( mixed *args )
{
   string word, message;
   int x;
   object tp;

   tp = this_player();
   if ( creatorp(tp) ) {
      tell_object( tp, "Why do you need to be paid?\n" );
      return 1;
   }
   word = tp->query_name();
   add_succeeded_mess( "" );

   if ( !sizeof( args ) )
   {
      message = "You are currently being paid into your account at "+
        BANKS[_employees[word][EMP_BANK]][0]+ ".  To change which bank "
        "you would like your pay to be deposited at, use the command "
        "\"bank <number>\" where <number> is one of the following:\n\n";
      for ( x = 0; x < sizeof(BANKS); x++ )
      {
         message += sprintf( "     %d: %s\n", x+1, BANKS[x][0] );
      }
      tell_object( tp, message + "\n" );
      return 1;
   }
   if ( args[0] < 1 || args[0] > sizeof(BANKS) )
   {
      tell_object( tp,  "There are "+ sizeof(BANKS)+
        " banks to choose from.\n" );
      return 1;
   }
   _employees[word][EMP_BANK] = args[0] - 1;
   save_emps();
   tell_object( tp, "You change your bank details.\n" );
   return 1;
}
/* do_bank() */


/**
 * @ignore yes
 * Maintain the list of stock dealt in by this shop.
 */
int do_chart( mixed *args, string pattern )
{
   int number;
   string word, item;

   word = this_player()->query_name();
   item = args[0];
   if ( sizeof(args) > 1 )
   {
      number = args[1];
   }

   if ( pattern == "add <string'item'>" )
   {
      if ( query_on_list( item ) )
      {
         tell_object( this_player(), item +
           " are already on the sales list.\n" );
         return 1;
      }
   }
   else if ( !query_on_list( item ) )
   {
      tell_object( this_player(), item +" are not on the sales list.\n" );
      return 1;
   }

   switch ( pattern )
   {
     case "add <string'item'>" :
        /* Start dealing in this item */
        add_succeeded_mess( "$N put$s "+ item +" on the sales list.\n" );
        put_on_list( item );
        shop_log( CHARTLOG, word, "put "+ item +" on the sales list" );
        break;
     case "remove <string'item'>" :
        /* Stop dealing in this item */
        add_succeeded_mess( "$N take$s "+item +" off the sales list.\n" );
        take_off_list( item );
        shop_log( CHARTLOG, word, "took "+item +" off the sales list" );
        break;
     case "max <string'item'> <number>" :
        /* Set maximum stock */
        add_succeeded_mess( "$N set$s the maximum stock of "+ item +" to "+
          number +".\n" );
        set_max( item, number );
        shop_log( CHARTLOG, word, "set max of "+ item +" to "+ number );
        break;
     case "buy <string'item'> <number>" :
        /* Set buy price */
        add_succeeded_mess( "$N set$s the buying price of "+ item +" to "+
          number +".\n" );
        set_buy( item, number );
        shop_log( CHARTLOG, word, "set buy of "+ item +" to "+ number );
        break;
     case "sell <string'item'> <number>" :
        /* Set sell price */
        add_succeeded_mess( "$N set$s the selling price of "+ item +" to "+
          number +".\n" );
        set_sell( item, number );
        shop_log( CHARTLOG, word, "set sell of "+ item +" to "+ number );
        break;
     case "assign <string'item'> [to cabinet] <number>" :
        /* Assign item to cabinets */
        if ( member_array( number, _list[item][CHART_CAB] ) != -1 )
        {
           tell_object( this_player(), item+
             " are already assigned to cabinet "+ number+ ".\n" );
           return 1;
        }
        if ( number < 1 || number > _num_cabinets )
        {
           tell_object( this_player(), "That cabinet does not exist.\n" );
           return 1;
        }
        add_chart_cabinet( item, number );
        add_succeeded_mess( "$N assign$s "+ item +" to use cabinet "+
          number +".\n" );
        shop_log( CHARTLOG, word, "assigned "+ item +
          " to cabinet "+ number );
        break;
     case "unassign <string'item'> [from cabinet] <number>" :
        /* Stop item using cabinets */
        if ( member_array( number, _list[item][CHART_CAB] ) == -1 )
        {
           tell_object( this_player(), item+
             " are not assigned to cabinet "+ number+ ".\n" );
           return 1;
        }
        remove_chart_cabinet( item, number );
        add_succeeded_mess( "$N stop$s "+ item +" using cabinet "+
          number +".\n" );
        shop_log( CHARTLOG, word, "unassigned "+ item +
          " from cabinet "+ number );
        break;
   }
   return 1;
}
/* do_chart() */


/**
 * @ignore yes
 * Check cabinet assignments
 */
int do_check()
{
   string result, item, word,*items;
   int x;

   result = "Current cabinet assignments are:\n";
   for( x = 0; x < _num_cabinets; x++ )
   {
      result += sprintf( "Cabinet %2d: ", x+1 );
      items = ({});
      foreach( item in m_indices(_list) )
      {
         if ( member_array( x+1, _list[item][CHART_CAB] ) != -1 )
         {
            word = sprintf( "%s (%d)", item, _list[item][CHART_MAX] );
            items += ({ word });
         }
      }
      if ( sizeof( items ) )
      {
         result += query_multiple_short( items );
      }
      result += "\n";
   }
   result += "\n";
   tell_object( this_player(), "$P$Cabinet assignments$P$"+ result );
   return 1;
}
/* do_check() */


/**
 * @ignore yes
 * Display the shop's logs.
 */
int do_logs( mixed *args, string pattern )
{
   int i;
   string start, end, file, *files, words;

   add_succeeded_mess("");
   switch ( pattern )
   {
     case "" :
        /* Display available logs */
        files = get_dir( _log_file +"general.log*" );
        words = "Available logs:\n\n";
        for ( i = 0; i < sizeof( files ); i++ )
        {
           if ( !i )
           {
              words += " 1: current log\n";
              continue;
           }
           sscanf( unguarded( (: read_file, _log_file + files[i], 2, 1 :) ),
             "%*s, %s: %*s", start );
           sscanf( unguarded( (: read_file, _log_file + files[i],
             file_length( _log_file + files[i] ), 1 :) ),
             "%*s, %s: %*s", end );
           if ( start == end )
           {
              words += sprintf( "%2d: %s\n", i + 1, start );
              continue;
           }
           words += sprintf( "%2d: %s to %s\n", i + 1, start, end );
        }
        words += "\nUse \"logs <number>\" to read one of them, or logs "
          "{personnel|accounts|chart} to view those logs.\n";
        tell_object( this_player(),"$P$Logs$P$"+ words );
        break;
     case "<number>" :
        /* Display specific log */
        files = get_dir( _log_file +"general.log*" );
        if ( ( args[0] < 1 ) || ( args[0] > sizeof( files ) ) )
        {
           tell_object( this_player(), "There are "+ sizeof( files ) +
             " logs.  Use \"logs\".\n" );
           return 1;
        }
        sscanf( unguarded( (: read_file, _log_file +
          files[args[0] - 1] :) ), "%*s\n%s", words );
        tell_object( this_player(),"$P$Log "+ args[0]+ "$P$"+ words );
        break;
     case "[chart]" :
        /* Display chart log */
        file = _log_file + "chart.log";
        if ( file_size( file ) > 0 )
        {
           sscanf( unguarded( (: read_file, file :) ), "%s", words );
           tell_object( this_player(),"$P$"+ capitalize(args[0])+
             " log$P$"+ words );
        }
        else
        {
           tell_object( this_player(), "The chart log is empty.\n" );
           return 1;
        }
        break;
     case "{personnel|accounts|chart}" :
        /* Display special log */
        file = _log_file + args[0] + ".log";
        if ( file_size( file ) > 0 )
        {
           sscanf( unguarded( (: read_file, file :) ), "%s", words );
           tell_object( this_player(),"$P$"+ capitalize(args[0])+
             " log$P$"+ words );
        }
        else
        {
           tell_object( this_player(), "The "+ args[0]+ " log is empty.\n" );
           return 1;
        }
        break;
   }
   return 1;
}
/* do_logs() */


/**
 * @ignore yes
 * Query the direction to another part of the shop.
 * This function is used by the npc shopkeeper to navigate
 * around the shop.
 */
string directions_to( string place )
{
   if ( place == _counter )
   {
      return copy(_counter_dir);
   }
   if ( place == _storeroom )
   {
      return copy(_store_dir);
   }
   if ( place == _shop_front )
   {
      return copy(_shop_dir);
   }
   return "here";
}
/* directions_to() */


/**
 * Set the location of the shop.
 * This is used by the money handling functions to determine which
 * currency to use and therefore should be one of the locations returned
 * by the query_all_places() function in /handlers/money_handler
 * @example set_place( "Ankh-Morpork" );
 * @param place The location of this shop.
 */
protected void set_place( string place ) { _place = place; }


/**
 * Set the npc shopkeeper object.
 * @example set_shopkeeper( CHARS + "gretta_shuffle" );
 * @param path The full path to the shopkeeper.
 */
protected void set_shopkeeper( string path ) {
   _shopkeeper = path;
}
/* set_shopkeeper() */


/**
 * Set the path to the customer area.
 * @example set_shop_front( PATH + "consumables" );
 * @param path The full path and filename to the customer area of the shop.
 */
protected void set_shop_front( string path ) { _shop_front = path; }


/**
 * Set the path to the counter.
 * @example set_counter( PATH + "counter" );
 * @param path The full path and filename to the shop's counter.
 */
protected void set_counter( string path ) { _counter = path; }


/**
 * Set the path to save the log files to.
 * @example set_log_files( PATH + "logs/" );
 * @param path The full path to the log files.
 */
protected void set_log_files( string path ) { _log_file = path; }

/**
 * Set the path to the storeroom.
 * @example set_storeroom( PATH + "tarnach's_storeroom" );
 * @param path The full path and filename to the storeroom of the shop.
 */
protected void set_storeroom( string path ) { _storeroom = path; }


/**
 * Query the name of the proprietor.
 */
string query_proprietor() { return copy(_proprietor); }

/**
 * Query the channel used by the shop.
 */
string query_channel() { return copy(_channel); }

/**
 * Query the value of the profit account.
 */
int query_profit() { return copy(_accounts["profit"]); }

/**
 * Query the value of the bonus account.
 */
int query_bonus() { return copy(_accounts["bonus"]); }

/**
 * Query the maximum number of employees.
 */
int query_maxemp() { return copy(_max_emp); }

/**
 * Query the base pay rate.
 */
int query_pay() { return copy(_pay_val); }

/**
 * Query the location of this shop.
 */
string query_place() { return copy(_place); }

/**
 * Query the path to the shop front.
 */
string query_shop_front() { return copy(_shop_front); }

/**
 * Query the path to the counter.
 */
string query_counter() { return copy(_counter); }

/**
 * Query the path to the managers' office.
 */
string query_mgr_office() { return copy(_mgr_office); }

/**
 * Query the path to the storeroom.
 */
string query_storeroom() { return copy(_storeroom); }

/**
 * Query the full name of the shop.
 */
string query_shop_name() { return copy(_shop_name); }

/**
 * Set the exit to the managers' office.
 * @example add_manager_exit( "east", PATH + "tarnach's_man_office" );
 * @param dir The direction of the exit.
 * @param path The full path and filename to the managers' office of the shop.
 */
protected void add_manager_exit( string dir, string path )
{
   add_exit( dir, path, "door" );
   modify_exit( dir, ({ "function", ({ this_object(),
     "check_manager" }), "door short", "office door", "door long",
     "There is a sign on the door which reads: \""+ _proprietor+
     "- Private\".\n" }) );
   _mgr_office = path;
}
/* set_mgr_office() */


/**
 * Set the full name of the shop.
 * This is used throughout the shop, and passed to the shop front as the
 * short description for the shop.
 * @example set_shop_name( "Tarnach Fendertwin's Quality Consumables" );
 * @param name The name of the shop.
 */
protected void set_shop_name( string name ) { _shop_name = name; }


/**
 * Set the very short name of the shop.
 * This is used in many places including save-file names, setting up
 * player-titles, and mail headers.  It should be no more than around
 * 4 or 5 chars in length.
 * @example set_very_short( "TFQC" );
 * @param name The short name.
 */
protected void set_very_short( string name )
{
   _very_short = name;
   if ( file_size( _save_dir + name + ".o" ) > 0 )
   {
      unguarded( (: restore_object, _save_dir + name :) );
   }
   if ( file_size( _save_dir + name+ ".employees" ) > 0 )
   {
      _employees = restore_variable( unguarded( (: read_file,
        _save_dir+ name+ ".employees" :) ) );
   }
   if ( file_size( _save_dir + name+ ".history" ) > 0 )
   {
      _history = restore_variable( unguarded( (: read_file,
        _save_dir+ name+ ".history" :) ) );
   }
   if ( file_size( _save_dir + name+ ".times" ) > 0 )
   {
      _times = restore_variable( unguarded( (: read_file,
        _save_dir+ name+ ".times" :) ) );
   }
   TCRE("shiannar", "PSHOP:"+file_name(TO)+": Restoring files.");
}
/* set_very_short() */


/**
 * Returns the very short name of the shop.
 */
string shop_very_short() { return copy(_very_short); }


/**
 * Set the name of the proprietor.
 * @example set_proprietor( "Tarnach Fendertwin" );
 * @param name The name of the proprietor.
 */
protected void set_proprietor( string name ) { _proprietor = name; }


/**
 * Set the channel used by the shop.
 * This sets the channel used by the employees' badges, and also the
 * name of the board.  If a board has been set-up for this shop, this
 * function will also add the board into the room.
 * @example set_channel( "Tarnach's", 1 );
 * @param name The name of the channel.
 * @param board Non-zero if a board exists for this shop.
 */
protected void set_channel( string name, int board )
{
   _channel = lower_case( name );
   if ( board )
   {
      _board = clone_object( "/obj/misc/board" );
      _board->set_datafile( name );
      _board->move( this_object() );
   }
}
/* set_channel() */


/**
 * @ignore yes
 * Adjust the value of the profit account.
 */
private void adjust_profit( string emp, int amount )
{
   string sign = "";

   _accounts["profit"] += amount;
   if ( _accounts["profit"] < 0 )
   {
      _accounts["profit"] = 0;
   }
   if ( amount < 0 )
   {
      sign = "-";
      amount = -amount;
   }
   shop_log( ACCOUNTS, emp, sprintf( "adjusted the profit account by %s%s",
     sign, MONEY_HAND->money_value_string( amount, _place ) ) );
   save_me();
}
/* adjust_profit() */


/**
 * @ignore yes
 * Adjust the value of the bonus account.
 */
private void adjust_bonus( string emp, int amount )
{
   string sign = "";

   _accounts["bonus"] += amount;
   if ( _accounts["bonus"] < 0 )
   {
      _accounts["bonus"] = 0;
   }
   if ( amount < 0 )
   {
      sign = "-";
      amount = -amount;
   }
   shop_log( ACCOUNTS, emp, sprintf( "adjusted the bonus account by %s%s",
     sign, MONEY_HAND->money_value_string( amount, _place ) ) );
   save_me();
}
/* adjust_profit() */


/**
 * Set the directions to other parts of the shop.
 * This function is used by the npc shopkeeper to navigate
 * around the shop, using the exits at the given directions.
 * These directions should be the standard "north", "southeast" etc.
 * @example set_directions( "southeast", "southeast", "southeast" );
 * @param store The direction to the storeroom.
 * @param counter The direction to the counter.
 * @param shop The direction to the shop front.
 */
protected void set_directions( string store, string counter, string shop  )
{
   _store_dir = store;
   _counter_dir = counter;
   _shop_dir = shop;
}
/* set_directions() */


/**
 * @ignore yes
 * Demote a manager or supervisor.
 */
private void demote( string demoter, string demotee )
{
   int points;

   points = _employees[demotee][EMP_POINTS] & CLOCKED_IN;
   if( _employees[demotee][EMP_POINTS] & MANAGER )
   {
      points += (SUPER_POINTS * 32) + EMPLOYEE + SUPERVISOR;
   }
   else
   {
      points += EMPLOYEE;
   }
   _employees[demotee][EMP_POINTS] = points;
   save_emps();
   AUTO_MAILER->auto_mail( demotee, _proprietor, "Demotion", "",
     "This is to advise you that you have today been demoted.\n"
     "This demotion will now stay on your employment record.\n" );
   employee_log( demotee, "Demoted by "+ demoter );
   shop_log( PERSONNEL, demoter, "demoted "+ capitalize( demotee ) );
}
/* demote() */


/**
 * @ignore yes
 * View an employee's history.
 * This method displays a formatted display of the employee's history
 * with a particular shop, and is viewable by managers of that shop.
 * @param employee The employee.
 */
void view_record( string employee )
{
   string text;
   int i;

   if ( !sizeof(_history) || !_history[employee] )
   {
      tell_object( this_player(), "There is no history for that person.\n" );
      return;
   }
   text = "Employment history of "+ capitalize( employee )+ ":\n\n";
   for( i = 0; i < sizeof( _history[employee][0] ); i++ )
   {
      text += ctime(_history[employee][0][i])+
        ": "+ _history[employee][1][i]+ "\n";
   }
   tell_object( this_player(), "$P$"+ capitalize(employee)+
     "'s history$P$"+ text );
}
/* view_record() */


/**
 * @ignore yes
 * Saving the contents of the shop's register.
 */
void save_register( mixed *money )
{
   _register = money;
   save_me();
}
/* save_register() */


/**
 * @ignore yes
 * Loading the contents of the shop's register.
 */
mixed *restore_register()
{
   return copy(({_register}));
}
/* restore_register() */


/**
 * Query the number of storeroom cabinets.
 * @return The number of cabinets in the storeroom.
 */
int query_num_cabinets() { return copy(_num_cabinets); }


/**
 * @ignore yes
 * Managers' office.
 * Retire from management.
 */
int do_retire()
{
   string manager;

   manager = this_player()->query_name();
   if ( !(_employees[manager][EMP_POINTS] & MANAGER) )
   {
      return 0;
   }
   remove_employee( manager );
   _retired += ({ manager });
   shop_log( PERSONNEL, manager, "retired from management" );
   employee_log( manager, "Retired from management" );
   save_me();
   add_succeeded_mess( "$N retire$s.\n" );
   return 1;
}
/* do_retire() */


/**
 * @ignore yes
 * Managers' office.
 * Transfer money between accounts.
 */
int do_transfer( mixed *args )
{
   int value, best;
   object money;
   string tp;

   if ( args[2] == args[3] || !args[0] )
   {
      tell_object( this_player(), "The point being?\n" );
      return 1;
   }
   tp = this_player()->query_name();
   money = clone_object( MONEY_OBJECT );
   money->set_money_array( MONEY_HAND->query_values_in( _place ) );
   if ( ( best = money->find_best_fit( args[1] ) ) == -1 )
   {
      tell_object( this_player(), "That currency is not used by "
        "the shop.\n" );
      return 1;
   }
   value = args[0] * ( money->query_money_array() )[ best + 1 ];
   money->dest_me();
   switch( args[2] ) {
   case "register" :
      if ( _counter->query_register() < value )
      {
         tell_object( this_player(), "There isn't that much available.\n" );
         return 1;
      }
      _counter->adjust_register( tp, value );
      if ( args[3] == "profit" )
      {
         adjust_profit( tp, value );
      }
      else
      {
         adjust_bonus( tp, value );
      }
      break;
   case "bonus" :
      if ( _accounts["bonus"] < value )
      {
         tell_object( this_player(), "There isn't that much available.\n" );
         return 1;
      }
      adjust_bonus( tp, -value );
      if ( args[3] == "profit" )
      {
         adjust_profit( tp, value );
      }
      else
      {
         money = MONEY_HAND->make_new_amount( value, _place );
         _counter->add_money_ob( money );
         shop_log( ACCOUNTS, tp, "adjusted the register by "+
           MONEY_HAND->money_value_string( value, _place ) );
      }
      break;
   case "profit" :
      if ( _accounts["profit"] < value )
      {
         tell_object( this_player(), "There isn't that much available.\n" );
         return 1;
      }
      adjust_profit( tp, -value );
      if ( args[3] == "bonus" )
      {
         adjust_bonus( tp, value );
      }
      else
      {
         money = MONEY_HAND->make_new_amount( value, _place );
         _counter->add_money_ob( money );
         shop_log( ACCOUNTS, tp, "adjusted the register by "+
           MONEY_HAND->money_value_string( value, _place ) );
      }
      break;
   }
   tell_object( this_player(), "Ok.\n" );
   return 1;
}
/* do_transfer() */


/**
 * @ignore yes
 * Make sure cabinet's dested before removing file.
 */
void rm_cab( string cab_name )
{
#ifdef DEBUG
   debug_printf( "Removing cabinet file %s.\n",
     _save_dir+ _very_short+ "_" + cab_name+ ".o" );
#endif
   unguarded( (: rm, _save_dir + _very_short+ "_"+ cab_name+ ".o" :) );
}
/* rm_cab() */


/**
 * @ignore yes
 * Managers' office.
 * Renting store cabinets.
 */
int do_rent()
{
   if ( !( _num_cabinets < MAX_CABINETS ) )
   {
      tell_object( this_player(), "The shop already contains the "
        "maximum number of cabinets.\n" );
      return 1;
   }
   if ( CABINET_COST > _accounts["profit"] )
   {
      tell_object( this_player(), "Cabinets currently cost "+
        MONEY_HAND->money_value_string( CABINET_COST, _place ) +
        ".  There is not enough money in the profit account.\n" );
      return 1;
   }
   tell_object( this_player(), "Are you sure you wish to rent a cabinet for "+
     MONEY_HAND->money_value_string( CABINET_COST, _place ) + " per month? " );
   input_to( "confirm_cabinet", 0, 1 );
   return 1;
}
/* do_rent() */


/**
 * @ignore yes
 * Managers' office.
 * Removing storeroom cabinets.
 */
int do_remove()
{
   int stock;

   if ( !( (stock = _num_cabinets ) > MIN_CABINETS ) )
   {
      tell_object( this_player(), "The shop already contains the "
        "minimum number of cabinets.\n" );
      return 1;
   }
   if ( sizeof( _storeroom->query_stock(stock) ) )
   {
      tell_object( this_player(), "Cabinet "+ stock+
        " still contains stock.\n" );
      return 1;
   }
   if ( query_cabinet_used(stock) )
   {
      tell_object( this_player(), "Cabinet "+ stock+
        " is still assigned to hold stock.\n" );
      return 1;
   }
   tell_object( this_player(), "Are you sure you wish to remove a cabinet? " );
   input_to( "confirm_cabinet", 0, 0 );
   return 1;
}
/* do_remove() */


/** @ignore yes */
void confirm_cabinet( string confirm, int rent )
{
   string cab_name;

   confirm = lower_case( confirm );
   if ( strlen( confirm ) < 1 ||
     ( confirm[0] != 'y' && confirm[0] != 'n' ) )
   {
       tell_object( this_player(), sprintf("Please enter 'yes' or 'no'.\n"
         "Are you sure you want to %s a cabinet? ", (rent)?"rent":"remove" ) );
       input_to( "confirm_cabinet", 0, rent );
       return ;
   }
   if ( confirm[0] == 'n' )
   {
      tell_object( this_player(), "Ok.\n" );
      return;
   }
   if ( rent )
   {
      if ( _storeroom->add_cabinet() )
      {
         _num_cabinets++;
         adjust_profit( this_player()->query_name(), -CABINET_COST );
         shop_log( ACCOUNTS, this_player()->query_name(),
           "rented cabinet for "+ MONEY_HAND->money_value_string( CABINET_COST,
           _place ) );
         save_me();
      }
   }
   else
   {
      if ( ( cab_name = _storeroom->remove_cabinet() ) != "" )
      {
         _num_cabinets--;
         shop_log( ACCOUNTS, this_player()->query_name(),
           "removed cabinet" );
         if ( file_size( _save_dir + _very_short+ "_"+ cab_name + ".o" ) > 0 )
         {
            call_out( "rm_cab", 5, cab_name );
         }
         save_me();
      }
   }
   tell_object( this_player(), "Cabinet "+ (rent)?"rent":"remove" + "ed.\n" );
}
/* confirm_cabinet() */


/**
 * @ignore yes
 * Managers' office.
 * Set maximum employees & base pay rate.
 */
int do_set( mixed *args, string pattern )
{
   int value, best;
   object money;

   switch( pattern )
   {
      case "maximum <number> [employees]" :
         if ( args[0] < MIN_EMP || args[0] > MAX_EMP )
         {
            tell_object( this_player(), "Must be between "+ MIN_EMP+
              " and "+ MAX_EMP+ ".\n" );
            return 1;
         }
         shop_log( PERSONNEL, this_player()->query_name(),
           "set maximum employees to "+ args[0] );
         _max_emp = args[0];
         break;
      case "pay <number'amount'> <string'type'>" :
         money = clone_object( MONEY_OBJECT );
         money->set_money_array( MONEY_HAND->query_values_in( _place ) );
         if ( ( best = money->find_best_fit( args[1] ) ) == -1 )
         {
            tell_object( this_player(),
              "That currency is not used by the shop.\n" );
            return 1;
         }
         value = args[0] * ( money->query_money_array() )[best + 1];
         money->dest_me();
         if ( value < 1 )
         {
            tell_object( this_player(),
              "You must pay your employees something.\n" );
            return 1;
         }
         shop_log( PERSONNEL, this_player()->query_name(), "set pay to "+
           MONEY_HAND->money_value_string( value, _place ) );
         _pay_val = value;
         add_board_message( "Pay", sprintf( "The base pay rate has today "
           "been set to:\n\n   Managers: %s\n   Supervisors: %s\n   "
           "Employees: %s\n", MONEY_HAND->money_value_string(value * 2, _place),
           MONEY_HAND->money_value_string(to_int(value * 1.5), _place),
           MONEY_HAND->money_value_string(value, _place) ) );
         break;
   }
   tell_object( this_player(), "Ok.\n" );
   save_me();
   return 1;
}
/* do_set() */


/**
 * @ignore yes
 * Managers' office.
 * Commend employees.  Adds 5% of their promotion target.
 */
int do_commend( string emp )
{
   string commender;

   if ( !_employees[emp] )
   {
      tell_object( this_player(), capitalize( emp )+
        " is not an active employee!\n" );
      return 1;
   }
   if ( _employees[emp][EMP_POINTS] & MANAGER )
   {
      tell_object( this_player(), "You can't commend a manager.\n" );
      return 1;
   }
   if ( _employees[emp][EMP_POINTS] & NPC )
   {
      tell_object( this_player(), "Don't be silly!  "
        "You can't commend $C$"+ emp +".\n" );
      return 1;
   }
   commender = this_player()->query_cap_name();
   AUTO_MAILER->auto_mail( emp, lower_case(commender), "Commendation",
     "", "This is to advise you that you have today received a "
     "commendation for outstanding service.\nThis will now stay on "
     "your employment record.\n" );
   employee_log( emp, "Received a commendation from "+ commender );
   shop_log( PERSONNEL, commender, "commended "+ capitalize( emp ) );
   _employees[emp][EMP_POINTS] += (_employees[emp][EMP_POINTS] & SUPERVISOR)?
     to_int(MANAGER_POINTS * 0.05 * 32) : to_int(SUPER_POINTS * 0.05 * 32);
   save_emps();
   tell_object( this_player(), "You commend "+ capitalize( emp )+ ".\n" );
   return 1;
}
/* do_commend() */


/**
 * @ignore yes
 * Managers' office.
 * Warn employees.  Removes 5% of their promotion target.
 */
int do_warn( mixed *args )
{
   string warner;
   object tp;
   int points;

   tp = this_player();
   args[0] = lower_case( args[0] );
   if ( !_employees[args[0]] )
   {
      tell_object( tp, capitalize( args[0] )+
        " is not an active employee!\n" );
      return 1;
   }
   if ( _employees[args[0]][EMP_POINTS] & MANAGER )
   {
      if ( !creatorp(tp) )
      {
         tell_object( tp, "You don't have the authority to "
           "warn $C$"+ args[0] +".\n" );
         return 1;
      }
   }
   if ( _employees[args[0]][EMP_POINTS] & NPC )
   {
      tell_object( tp, "Don't be silly!  You can't warn $C$"+
        args[0] +".\n" );
      return 1;
   }
   warner = tp->query_cap_name();
   AUTO_MAILER->auto_mail( args[0], _proprietor, "Official warning", "",
     "This is to advise you that you have today received a formal "
     "warning for " + args[1] + ".\nThis warning will now stay on "
     "your employment record.\n" );
   employee_log( args[0], "Received a warning from "+ warner+
     " for "+ args[1] );
   shop_log( PERSONNEL, warner, "warned "+
     capitalize( args[0] ) + " for "+ args[1] );
   points = _employees[args[0]][EMP_POINTS] & CLOCKED_IN;
   if ( _employees[args[0]][EMP_POINTS] & SUPERVISOR )
   {
      _employees[args[0]][EMP_POINTS] -= to_int(MANAGER_POINTS * 0.05 * 32);
   }
   else
   {
      _employees[args[0]][EMP_POINTS] -= to_int(SUPER_POINTS * 0.05 * 32) +
        EMPLOYEE;
      if ( _employees[args[0]][EMP_POINTS] < 1 )
      {
         _employees[args[0]][EMP_POINTS] = EMPLOYEE + points;
      }
   }
   save_emps();
   tell_object( tp, "You warn "+ capitalize( args[0] )+ " for "+
     args[1]+ ".\n" );
   return 1;
}
/* do_warn() */


/**
 * @ignore yes
 * Managers' office.
 * Demote supervisors or managers.
 */
int do_demote( string emp )
{
   object tp;

   tp = this_player();
   emp = lower_case( emp );
   if ( !_employees[emp] )
   {
      tell_object( tp, capitalize( emp )+
        " is not an active employee!\n" );
      return 1;
   }
   if ( _employees[emp][EMP_POINTS] & MANAGER )
   {
      if ( !creatorp(tp) )
      {
         tell_object( tp, "You don't have the authority to "
           "demote $C$"+ emp +".\n" );
         return 1;
      }
   }
   if ( !( _employees[emp][EMP_POINTS] & SUPERVISOR ) )
   {
      tell_object( tp, "Don't be silly!  You can't demote $C$"+
        emp +".\n" );
      return 1;
   }
   demote( tp->query_cap_name(), emp );
   tell_object( tp, "You demote "+ capitalize( emp )+ ".\n" );
   return 1;
}
/* do_demote() */


/**
 * @ignore yes
 * Managers' office.
 * Suspend employee's bonus for x months.
 */
int do_suspend( mixed *args )
{
   string suspender;
   object tp;

   args[0] = lower_case( args[0] );
   tp = this_player();
   if ( !_employees[args[0]] )
   {
      tell_object( tp, capitalize( args[0] )+
        " is not an active employee!\n" );
      return 1;
   }
   if ( (_employees[args[0]][EMP_POINTS] & MANAGER) &&
        ( !creatorp(tp) ) )
   {
      tell_object( tp, "You don't have the authority to "
        "suspend $C$"+ args[0] +"'s bonus.\n" );
      return 1;
   }
   if ( _employees[args[0]][EMP_POINTS] & NPC )
   {
      tell_object( tp, "Don't be silly!  "
        "You can't suspend $C$"+ args[0] +"'s bonus.\n" );
      return 1;
   }
   suspender = tp->query_cap_name();
   _employees[args[0]][EMP_NOBONUS] = args[1];
   save_emps();
   AUTO_MAILER->auto_mail( args[0], _proprietor, "Suspended bonus", "",
     sprintf( "This is to advise you that you have had your bonus "
       "entitlement suspended for %d month%s.\nThis suspension will "
       "now stay on your employment record.\n", args[1],
       (args[1] == 1)?"":"s" ) );
   employee_log( args[0], sprintf( "Bonus suspended for %d month%s by %s",
     args[1], (args[1] == 1)?"":"s", suspender ) );
   shop_log( PERSONNEL, suspender,
     sprintf( "suspended %s's bonus for %d month%s", args[0],
     args[1], (args[1] == 1)?"":"s" ) );
   tell_object( tp, "You suspend "+ capitalize( args[0] )+
     "'s bonus for "+ args[1]+ " months.\n" );
   return 1;
}
/* do_suspend() */


/**
 * @ignore yes
 * Managers' office.
 * Place an employee on leave.
 */
int do_leave( mixed *args )
{
   object tp;

   tp = this_player();
   args[0] = lower_case( args[0] );
   if ( !_employees[args[0]] )
   {
      tell_object( tp, capitalize( args[0] )+
        " is not an employee!\n" );
      return 1;
   }
   if ( args[1] > MAX_LEAVE )
   {
      tell_object( tp, "You cannot place an employee on leave "
        "for more than "+ MAX_LEAVE+ " days at a time.\n" );
      return 1;
   }
   _employees[args[0]][EMP_TIME] = time() + ( args[1] * 86400 );
   save_emps();
   add_succeeded_mess( capitalize( args[0] )+
     " is on leave until "+ ctime( time() + ( args[1] * 86400 ) )+
     ".\n" );
   shop_log( PERSONNEL, tp->query_name(), "placed "+
     capitalize( args[0] )+ " on leave for " + args[1]+ " days" );
   tell_object( tp, "You place "+ capitalize( args[0] )+
     " on leave for " + args[1]+ " days" );
   return 1;
}
/* do_leave() */


/**
 * @ignore yes
 * Managers' office.
 * Ban a person from the shop.
 */
int do_ban( mixed *args )
{
   if ( !"/secure/login"->test_user( lower_case( args[0] ) ) )
   {
      tell_object( this_player(), args[0]+ " is not a player.\n" );
      return 1;
   }
   add_baddie( args[0], args[1], this_player()->query_name() );
   tell_object( this_player(), "You ban "+ capitalize( args[0] )+
     " for "+ args[1]+ ".\n" );
   return 1;
}
/* do_ban() */


/**
 * @ignore yes
 * Managers' office.
 * Remove the ban on a person.
 */
int do_unban( string person )
{
   if ( !query_baddie( person ) )
   {
      tell_object( this_player(), person+ " is not currently banned.\n" );
      return 1;
   }
   remove_baddie( person );
   shop_log( GENERAL, this_player()->query_name(),
     "removed the ban on "+ capitalize( person ) );
   tell_object( this_player(), "You remove the ban on "+
     capitalize( person )+ ".\n" );
   return 1;
}
/* do_unban() */


/**
 * @ignore yes
 * Managers' office.
 * Fire an employee.
 */
int do_fire( mixed args ) {
   args[0] = lower_case( args[0] );

   if( !_employees[args[0]] )  {
       tell_object( TP, capitalize( args[0] )+" doesn't work at the shop!\n");
       return 1;
   }

   if( ( member_array( args[0], _retired ) != -1 ||
       query_manager( args[0] ) ) && !creatorp(TP) ) {
       tell_object( TP, "You don't have the authority to fire $C$"+
           args[0] +".\n");
       return 1;
   }

   if( _employees[args[0]][EMP_POINTS] & NPC ) {
       tell_object( TP, "Don't be silly!  You can't fire $C$"+
           args[0] +".\n");
       return 1;
   }

   fire_them( this_player()->query_name(), args[0], args[1] );
   tell_object( this_player(), "You fire "+ capitalize( args[0] )+
     " for "+ args[1]+ ".\n" );
   return 1;
}
/* do_fire() */


/**
 * @ignore yes
 * Managers' office.
 * Vote on an applicant.
 */
int do_vote( mixed *args, string pattern )
{
   string tp;
   int query_app;

   tp = this_player()->query_name();

   if ( pattern == "<word'applicant'> {y|n|a}" )
   {
      args[0] = lower_case( args[0] );
      if ( !( query_app = query_applicant(args[0]) ) )
      {
         tell_object( this_player(), capitalize( args[0] )+
           " hasn't applied!\n" );
         return 1;
      }
      if ( query_app != APPLIED )
      {
         tell_object( this_player(), capitalize( args[0] )+
           " has already been hired!\n" );
         return 1;
      }
      if ( check_vote( args[0], tp ) )
      {
         tell_object( this_player(),
           "You have already voted for this person!\n" );
         return 1;
      }
      if ( args[1] == "y" )
      {
         add_vote( args[0], VFOR );
         tell_object( this_player(), "You vote for " +
           capitalize( args[0] ) + " to work for the shop.\n" );
      }
      else if ( args[1] == "a" )
      {
         add_vote( args[0], VABSTAIN );
         tell_object( this_player(), "You abstain on " +
           capitalize( args[0] ) + ".\n" );
      }
      else
      {
         add_vote( args[0], VAGAINST );
         tell_object( this_player(), "You vote against " +
           capitalize( args[0] ) + " working for the shop.\n" );
      }
   }
   else
   {
      do_policy_vote( tp, args[0], args[1] );
   }
   return 1;
}
/* do_vote() */


/**
 * Someone has entered the room.
 * This function will automatically fire an employee if they have
 * teleported to this room.  To avoid this happening, or to modify,
 * mask this function.
 */
void event_enter( object ob, string message, object from )
{
   string room;

   if ( !from || creatorp(ob) || from == find_object( "/room/void") ||
     !ob->query_player() )
   {
      return;
   }
   room = file_name( from );
   if ( room == _counter || room == _shop_front || room == _storeroom ||
     room == _mgr_office || from == this_object() )
   {
      return;
   }
   else
   {
#ifdef DEBUG
      debug_printf( "%s arrived from %O.\n", ob->query_name(), from );
#endif
      fire_them( _proprietor, ob->query_name(), "for teleporting into the shop" );
   }
}
/* event_enter() */


/**
 * Someone has died.
 * This function will automatically fire an employee if they have
 * killed someone whilst on duty.  It will also make a note of anyone
 * who has killed an on-duty employee (including the npc shopkeeper).  To
 * avoid this happening, or to modify, mask this function.
 */
void event_death( object killed, object *others, object killer,
                  string rmess, string kmess ) {
   object baddie;

   /* Only look for players & the shopkeeper
    * We don't want to fire/ban people for killing a cabbage...
    */
   if( !killer || ( !interactive(killed) &&
       !( query_employee( killed->query_name() ) & NPC ) ) ) {
       return;
   }

   if( ( query_employee( killed->query_name() ) & NPC )  ||
       ( query_employee( killed->query_name() ) ) ) {
        add_baddie( killer->query_name(), "the vicious assault on "+
            killed->query_name(), _proprietor );
        foreach( baddie in others ) {
          if( interactive(baddie) ) {
              add_baddie( baddie->query_name(), "the vicious assault on "+
                  killed->query_name(), _proprietor );
          }
        }
        return;
   }

   if( query_employee( killer->query_name() ) & CLOCKED_IN ) {
       add_baddie( killer->query_name(), "the vicious assault on "+
           killed->query_name(), _proprietor );
   }

   if( sizeof( others ) ) {
       foreach( baddie in others ) {
         if( interactive(baddie) )
             return;
         if( query_employee( baddie->query_name() )& CLOCKED_IN ) {
             add_baddie( baddie->query_name(), "the vicious assault "
                 "on "+ killed->query_name(), _proprietor );
         }
      }
   }
}
/* event_death() */

/**
 * @ignore yes
 * Shop front.
 * Cancel application.
 */
int do_cancel() {
   object tp;

   tp = this_player();
   remove_applicant( tp->query_name() );
   employee_log( tp->query_name(),
     "Cancelled application" );
   tell_object( tp, "You cancel your application.\n" );
   return 1;
}
/* do_cancel() */


/**
 * @ignore yes
 * Shop front.
 * Confirm employment.
 */
int do_confirm()
{
   if(!query_applicant(TP->query_name()))
     return notify_fail("You are not currently an applicant here.\n");
   confirm_employment( TP->query_name() );
   employee_log( TP->query_name(),
     "Confirmed employment" );
   tell_object( TP, "You confirm your employment.\n" );
   return 1;
}
/* do_confirm() */


/**
 * @ignore yes
 * Keep track of net change in register.
 */
void adjust_takings( int amt )
{
   _net_takings += amt;
   save_me();
}
/* adjust_takings() */


/**
 * @ignore yes
 * Keep track of items bought.
 */
void adjust_bought( string item, int amt )
{
   _list[item][CHART_BOUGHT] += amt;
   save_list();
}
/* adjust_bought() */


/**
 * @ignore yes
 * Keep track of items sold.
 */
void adjust_sold( string item, int amt )
{
   _list[item][CHART_SOLD] += amt;
   save_list();
}
/* adjust_sold() */


/**
 * @ignore yes
 * Add standard stuff
 */
void set_long( string long_desc )
{
   long_desc += "Employees may \"clock\" in and out of work here "
     "and examine the items chart.  There is also a policy notice "
     "located next to the chart.\n";
   ::set_long( long_desc );
}
/* set_long() */


/**
 * @ignore yes
 * Update policies in force.
 */
private void add_policy( string policy )
{
   if ( !_policies[policy] )
   {
      _policies += ([ policy:"" ]);
      _policies[policy] = _new_policies[policy][2];
      AUTO_MAILER->auto_mail( _new_policies[policy][1], _proprietor,
        "Policy proposition - "+ policy, "",
        "Your proposition has been accepted by majority vote and is "
        "now shop policy.\n" );
      shop_log( GENERAL, "Shop", "accepted the "+ policy + " policy.\n" );
   }
   else
   {
      map_delete( _policies, policy );
      AUTO_MAILER->auto_mail( _new_policies[policy][1], _proprietor,
        "Policy proposition - "+ policy, "",
        "Your proposition to remove the above policy has been accepted "
        "by majority vote.\n" );
      shop_log( GENERAL, "Shop", "removed the "+ policy + " policy.\n" );
   }
   map_delete( _new_policies, policy );
   save_me();
}
/* add_policy() */


/**
 * @ignore yes
 * Policy update has been unsuccessful.
 */
private void remove_policy( string policy )
{
   AUTO_MAILER->auto_mail( _new_policies[policy][1], "Tarnach Fendertwin",
     "Policy proposition - "+ policy, "",
     "Your proposition has been rejected by majority vote.\n" );
   shop_log( GENERAL, "Shop", "rejected the "+ policy + " policy.\n" );
   map_delete( _new_policies, policy );
   save_me();
}
/* remove_policy() */


/**
 * @ignore yes
 * Add a vote
 */
private int do_policy_vote( string mgr, string policy, string decision )
{
   int managers;

   if ( !m_sizeof(_new_policies) || !_new_policies[policy] )
   {
      tell_object( this_player(), "There is no such policy pending!\n" );
      return 1;
   }
   if ( member_array( mgr, _new_policies[policy][3] ) != -1 ||
     member_array( mgr, _new_policies[policy][4] ) != -1 )
   {
      tell_object( this_player(), "You have already voted on this policy!\n" );
      return 1;
   }
   if ( decision == "y" )
   {
      _new_policies[policy][3] += ({ mgr });
      tell_object( this_player(), "You vote for the " + policy+ " policy.\n" );
   }
   else
   {
      _new_policies[policy][4] += ({ mgr });
      tell_object( this_player(), "You vote against the " + policy+ " policy.\n" );
   }
   shop_log( GENERAL, mgr, "voted on the "+ policy + " policy.\n" );
   save_me();
   managers = sizeof( get_managers() ) + sizeof( get_retired() );
   if ( sizeof( _new_policies[policy][3] ) > managers / 2 )
   {
      add_policy( policy );
   }
   else if ( sizeof( _new_policies[policy][4] ) >= managers / 2 )
   {
      remove_policy( policy );
   }
   return 1;
}
/* do_policy_vote() */


/**
 * Determine if a shop policy exists.
 * @param policy The name of the policy to query.
 * @return 2 if it is already policy, 1 if it is being voted upon, else 0
 */
int query_policy( string policy )
{
   if ( m_sizeof( _policies ) && _policies[policy] ) return 2;
   if ( m_sizeof( _new_policies ) && _new_policies[policy] ) return 1;
   return 0;
}
/* query_policy() */


/**
 * @ignore yes
 * Add a new policy suggestion.
 */
void add_policy_suggest( string name, string text, string mgr )
{
   if ( !sizeof( _new_policies ) )
   {
      _new_policies = ([ name:({0,"","",({}),({}) }) ]);
   }
   else
   {
      _new_policies += ([ name:({0,"","",({}),({}) }) ]);
   }
   if ( sizeof( _policies ) && _policies[name] )
   {
      text = _policies[name][2];
   }
   _new_policies[name][0] = time();
   _new_policies[name][1] = mgr;
   _new_policies[name][2] = text;
   do_policy_vote( mgr, name, "y" );
   save_me();
}
/* add_policy_suggest() */


/**
 * Query the policy suggestions.
 * @return A mapping of the suggested shop policies.
 */
mapping get_new_policies() { return copy( _new_policies ); }


/**
 * Query the policies.
 * @return A mapping of the shop policies.
 */
mapping get_policies() { return copy( _policies ); }


/**
 * Set the stock's main policy.
 * @param desc The main stock description, eg. "magical spell components"
 */
void set_stock_policy( string desc ) { _stock_policy = desc; }


/**
 * @ignore yes
 * Query the shop's main policy - used for the notice.
 */
string get_stock_policy() { return copy( _stock_policy ); }


/**
 * @ignore yes
 * Called when someone is refreshed or deleted
 * Will delete the employee in case of deletion or full refresh.  In case
 * of partial refresh, will reset employee to new employee status.
 */
void refresh_function( mixed employee, int flag )
{
   string emp_name;

   switch ( flag )
   {
      case PLAYER_DELETED :
        emp_name = employee;
        break;
      case TOTAL_REFRESH :
      case PARTIAL_REFRESH :
        emp_name = employee->query_name();
        break;
   }

   if ( query_applicant( emp_name ) )
   {
      remove_employee( emp_name );
      switch ( flag )
      {
         case PLAYER_DELETED :
           shop_log( PERSONNEL, capitalize(emp_name), "deleted character" );
           employee_log( emp_name, "deleted character" );
           break;
         case TOTAL_REFRESH :
         case PARTIAL_REFRESH :
           tell_object( employee, "Your application at "+ _shop_name+
             " has been removed.\n" );
           shop_log( PERSONNEL, capitalize(emp_name), "refreshed character" );
           employee_log( emp_name, "refreshed character" );
           break;
      }
   }

   if ( member_array( emp_name, _retired ) != -1 )
   {
      remove_employee( emp_name );
      switch ( flag )
      {
         case PLAYER_DELETED :
           shop_log( PERSONNEL, capitalize(emp_name), "deleted character" );
           employee_log( emp_name, "deleted character" );
           break;
         case TOTAL_REFRESH :
         case PARTIAL_REFRESH :
           tell_object( employee, "Your employment at "+ _shop_name+
             " has been terminated.\n" );
           shop_log( PERSONNEL, capitalize(emp_name), "refreshed character" );
           employee_log( emp_name, "refreshed character" );
           break;
      }
   }

   if ( !_employees[emp_name] )
   {
      return;
   }

   switch ( flag )
   {
      case PLAYER_DELETED :
        shop_log( PERSONNEL, capitalize(emp_name), "deleted character" );
        employee_log( emp_name, "deleted character" );
        remove_employee( emp_name );
        break;
      case TOTAL_REFRESH :
        tell_object( employee, "Your employment at "+ _shop_name+
          " has been terminated.\n" );
        shop_log( PERSONNEL, capitalize(emp_name), "refreshed totally" );
        employee_log( emp_name, "refreshed totally" );
        remove_employee( emp_name );
        break;
      case PARTIAL_REFRESH :
        tell_object( employee, "Your employment level at "+ _shop_name+
          " has been reset.\n" );
        shop_log( PERSONNEL, capitalize(emp_name), "refreshed character" );
        employee_log( emp_name, "refreshed character" );
        _employees[emp_name] = ({1,0,0,0,0,1,0,});
        set_emp_time( emp_name );
        _got_bonus += ({ emp_name });
        save_me();
        break;
   }
}
/* refresh_function() */

/**
 * Overrides the default save dir.
 * @param dir the new dir
 */
void set_save_dir(string dir) {
  _save_dir = dir;
} /* set_save_dir() */
