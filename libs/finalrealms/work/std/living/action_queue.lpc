/*
 * Originally..
 * 'the bit of the soul that all players should have ;)'
 * By Pinkfish, presumably
 *
 * This is the action queue, now, however.  Soul stuff removed.
 * This file has no soul.  It also uses private stuff.  Imagine that!
 *
 * By Wonderflug, 1996.
 * And Baldrick hacked some on it to make it worse dec '97.
 */

#include "action_queue.h"
#include "cmd.h"

/*
 * These must be saved in permanent storage; in fact, these should be
 * permanent stats of a character and handled as such.
 */

private int max_time;          /* Maximum 'spare' time this object can have  */
private int default_time;      /* Used for non-trivial actions w/o times set */


/* the actionq can contain function pointers or strings ;
 * function pointers are evaluated, strings are passed to
 * command() when the action is due to be done.
 * The actionq is allocate()'d, since commands will constantly be added
 * and deleted from it, and growing and shrinking it would be needless
 * waste.  Admittedly this means the majority of the queue slots are empty
 * most of the time.
 *
 * Actually it's not; we let it grow and shrink dynamically, to save heaps
 * and heaps of memory.  I do have the old implementation lying around
 * ready to be plugged in though, should we be able to spare the memory,
 * and not the cpu. (the other version isn't particularly faster though)
 */
private nosave mixed* actionq;

/*
 * Security array; this is an array of flags, each corresponding to
 * an action in the action queue, indicating if the action was forced by
 * some other object or not.
 */
private nosave int* action_forcedq;

/* If the current command was forced or not; 
 * -1 means no command is in progress (and thus, to most checks, has the
 * conservative view that the action WAS forced)
 */
private nosave int curr_forced;

private nosave int time_left;  /* Time left for this round. */

/* Allows prompts to be disabled after a given command completes */
private nosave int show_prompt;

/* for bookkeeping purposes */
private nosave string command_in_progress; /* copy of a command in progress */
private nosave int time_adjusted;          /* flag if time's been adjusted  */
private nosave int trivial_actions_performed;  /* number performed this hb  */
private nosave int trivial_action_in_progress;  /* flag if command trivial  */
private nosave int notified;
private nosave int hb_command_done; 

private nosave string temp_verb; 


/* interruptable action stuff */
private nosave int ia_in_progress; /* flag indicating in the middle of an ia */
private nosave mixed ia_abort;     /* function/message on abort              */
private nosave mixed ia_complete;  /* function/message on complete           */
private nosave string ia_message;  /* message on any command not an abort    */

mixed* debug_actionq() { return actionq; }
void debug_resetq() {  actionq = ({ }); }

/* debug of course */
int query_bits_per_beat() { return 10; }

string query_verb() {
  log_file ("balddeb", "temp_verb: " + temp_verb + "\n");
  if ( sizeof(temp_verb) > 0)
    return temp_verb;
  else
    return efun::query_verb();
}

void create() 
{
  time_left = this_object()->query_bits_per_beat();

  actionq = ({ });
  action_forcedq = ({ });
  curr_forced = -1;

  if ( undefinedp(max_time) )
    max_time = this_object()->query_bits_per_beat();
  if ( undefinedp(default_time) )
    default_time = max_time;

  command_in_progress = "";
  time_adjusted = 0;
  trivial_actions_performed = 0;
  ia_in_progress = 0;
  ia_abort = 0;
  ia_complete = 0;
  ia_message = "";

  show_prompt = 1;
} /* create() */

int query_time_left() { return time_left; }
int adjust_time_left(int i) 
{ 
  time_adjusted = 1;
  return time_left += i; 
}

int query_max_time() { return max_time; }
int set_max_time(int i)
{
  if ( i < 0 )
    return max_time = 0;
  else
    return max_time = i;
}

int query_default_action_time() { return default_time; }
int set_default_action_time(int i) { return default_time = i; }

void set_notified(int fi)
  {
  notified = fi;
  return;
}

/* Maybe not needed anyway, Baldrick
 *
void set_hb_command_done(int fi)
  {
  hb_command_done = fi;
  return;
}
*/

void set_trivial_action() 
{ 
  trivial_action_in_progress = 1; 
  trivial_actions_performed++;
}

int set_interruptable_action(
  int time,
  string message,
  mixed abort,
  mixed complete )
{
  if ( ia_in_progress )
    return AQ_ERROR;

  if ( !stringp(abort) && !functionp(abort) )
    return AQ_ERROR;

  ia_in_progress = 1;
  this_object()->adjust_time_left( -time );

  /* Hmm, is this one nessesary? 
   * give looks ugly with it at least.
   * Baldrick.
  ia_message = "Command queued since "+message+"Type 'abort' to attempt to "
    "end prematurely.\n";
    */

  ia_abort = abort;
  ia_complete = complete;

  return AQ_OK;
}

/*
 * Attempts to abort any interruptable action in progress
 * Returns AQ_OK if, after returning, there is no interruptable action 
 * in progress, or AQ_ERROR otherwise.
 */
int abort_interruptable_action()
{
  if ( !ia_in_progress )
    return AQ_OK;

  if ( functionp( ia_abort ) && !evaluate(ia_abort) )
    return AQ_ERROR;
  else if ( stringp( ia_abort ) )
    tell_object( this_object(), ia_abort );

  ia_in_progress = 0;
  ia_abort = 0;
  ia_complete = 0;
  ia_message = 0;
  time_left = 0;
  
  return AQ_OK;
}
    
/*
 * Small interface functions used in the prompting system
 */
int query_busy()
{
  if ( time_left < 0 )
  {
    if ( ia_in_progress )
      return INTERRUPTABLE_BUSY;
    else
      return NON_INTERRUPTABLE_BUSY;
  }
  else if ( trivial_actions_performed > MAXIMUM_COMMANDS_PER_HB )
    return NON_INTERRUPTABLE_BUSY;
  return NOT_BUSY;
}

void set_no_prompt() { show_prompt = 0; }

/****
 * Queue maintenance routines
 ****/

/*
 * Determines who originated the current thread of execution. (action)
 * Returns 0 if this_object(); 1 if another object or it cannot
 * be determined for sure that it was this_object()
 * See queue_security (in some doc dir) to see the argument for
 * correctness of this.
 */
nomask private int aq_determine_forced()
{
  /* this_player(1) determines it for sure, if set */
  if ( this_player(1) )
  {
    if ( this_player(1) == this_object() )
      return 0;
    else
      return 1;
  }

  /* if this_player is set, and not this_object, we know it IS forced */
  if ( this_player() && this_player() != this_object() )
    return 1;

  /* if this_player is this_object, or this_player isn't set, use
   * the current forced status; note if it's -1 then of course we are
   * being forced.
   */
  if ( curr_forced == 0 )
    return 0;
  else
    return 1;
}


/*
 * Tries to insert an action at the head of the queue.
 */
nomask private int aq_insert( mixed val )
{
  if ( !stringp( val ) && !functionp( val ) )
    return AQ_ERROR;

  if ( sizeof( actionq ) >= AQ_MAX_ACTIONS )
    return AQ_FULL;

  actionq = ({ val }) + actionq;

  action_forcedq = ({ aq_determine_forced() }) + action_forcedq;

  return AQ_OK;
}

/*
 * Tries to add an action to the end of queue
 */
nomask private int aq_add( mixed val )
{
  string t, verb;

  if ( !stringp( val ) && !functionp( val ) )
    return AQ_ERROR;

  if ( sizeof( actionq ) >= AQ_MAX_ACTIONS )
    return AQ_FULL;

  if (sizeof(actionq) == 0 && !hb_command_done)
    {
    if ( functionp( val ) )
      {
      evaluate( val );
      }
    notify_fail ("");
    notified = 0;
    temp_verb = val;
    if (!command( val ))
      {
      sscanf(val, "%s %s", verb, t);
      if(!verb)
        verb = val;
      //if (!environment(this_object())->do_move_command(verb, t))
      if (!environment(this_object())->do_move_command(val))
        if (!CMD_HANDLER->cmd(verb, t, this_object()))
          if (!this_object()->parse_comm(verb, t ))
            hb_command_done = 2;
      }
    temp_verb = "";
    if (hb_command_done == 2 && !notified)
      hb_command_done = 1;
     else
      {
      hb_command_done = 1;
      return AQ_OK;
      }
    }  

  actionq += ({ val });

  action_forcedq += ({ aq_determine_forced() });

  return AQ_OK;
}

/*
 * Removes the head of the queue, of course, and returns it
 * -1 if there are no entries in the queue.
 */
nomask private mixed aq_decapitate()
{
  mixed ret;

  if ( !sizeof(actionq) )
    return AQ_EMPTY;

  ret = actionq[0];

  /* [1..n] means 2nd element (1) to the last element (<0) ;
   * see the man pages under lpc/types/substructures for shortcuts
   * in indexing
   */
  actionq = actionq[1..<0];

  return ret;
}

/*
 * Deletes user actions from the queue.  Any command string is a user
 * action.  (supposedly)
 */
nomask private int aq_delete_user_actions()
{
  int i;
  mixed* newq; 
  int* new_fq;

  newq = ({ });
  new_fq = ({ });
  for( i=0; i<sizeof(actionq); i++ )
    if ( functionp(actionq[i]) )
    {
      newq += ({ actionq[i] });
      new_fq += ({ action_forcedq[i] });
    }

  actionq = newq;
  action_forcedq = new_fq;
      
  return AQ_OK;
}

/* The do_cmd is a part of the external command handling system.
 * Made by Chrisy and gotten from RD. oct '95.
 * Moved here by Baldrick so that the whole living-tree can use the 
 * commands in that system.
 */   
int do_cmd(string tail)
{
  string verb, t;

  sscanf(tail, "%s %s", verb, t);
  if(!verb)
    verb = tail;

  return (int)CMD_HANDLER->cmd(verb, t, this_object());
} /* do_cmd() */

/*
 * This looks for an action to perform and does it if there's one waiting
 * and time left.  Otherwise it returns.  If it does perform an action it'll
 * return 1, otherwise 0.
 */

nomask private int perform_next_action()
{
  mixed curr_act;
  int verb,t;

  show_prompt = 1;
  if ( ia_in_progress && time_left >= 0 )
  {
    /* this means the interruptable action is complete. */
    
    evaluate(ia_complete);
    ia_in_progress = 0;
    ia_complete = 0;
    ia_abort = 0;
    ia_message = "";
    curr_forced = -1;

    /* now we go ahead and try to perform the next action as usual */
  }

  if (time_left < 0 || trivial_actions_performed > MAXIMUM_COMMANDS_PER_HB )
    return 0;

  if ( sizeof(actionq) == 0 ) 
  {
    if ( this_object()->query_in_combat() )
    {
      mixed act = this_object()->determine_action() ;

      if ( !(stringp(act) || functionp(act)) 
           || aq_insert( act ) != AQ_OK )
      {
        write("perform_next_action: determine_action buggered up\n");
        return 0;
      }
    }
    else
      return 0;
  }

  curr_act = aq_decapitate();

  if ( intp(curr_act) )  /* it can't be good */
    return 0;

  curr_forced = action_forcedq[0];
  action_forcedq = action_forcedq[1..<0];

  trivial_action_in_progress = 0;
  if ( functionp( curr_act ) )
  {
    evaluate( curr_act );
  }
  else if ( stringp( curr_act ) )
  {
    command_in_progress = curr_act;
    time_adjusted = 0;
    /* testing something.. 
     * the right order of this may have to be tweaked
     * Baldrick */
    notify_fail ("");
    notified = 0;
    temp_verb = curr_act;
    if (!command( curr_act ))
      {
      sscanf(curr_act, "%s %s", verb, t);
      if(!verb)
        verb = curr_act;
      if (!environment(this_object())->do_move_command(curr_act))
       if (!this_object()->do_gr_command(verb, t))
        if (!CMD_HANDLER->cmd(verb, t, this_object()))
          if (!this_object()->parse_comm(verb, t ))
            if (!CMD_HANDLER->soul_com ( curr_act, this_object() ))
              if (!notified)
                write("The attempt to %^RED%^" + curr_act 
                      + "%^RESET%^ didn't really work out.\n");
      }
    command_in_progress = "";
  }
  else
  {
    temp_verb = "";
    return 0;
  }

  /* if the action didn't flag itself as trivial, and it didn't adjust
   * time left, then adjust time by a default
   *
   * Have to check for this_object(), alas, since 'quit' will destroy it.
   * Particularly stupid, I must say, makes no sense.
   */
  if ( !trivial_action_in_progress && !time_adjusted && this_object() )
    adjust_time_left( -this_object()->query_default_action_time() );

  if ( !ia_in_progress )
    curr_forced = -1;

  temp_verb = "";
  return 1;
} /* perform_next_action() */

/****
 * The real routines
 ****/

/*
 * The outside interface for inserting actions to the head of the queue.
 */
nomask int insert_action( mixed val ) { return aq_insert( val ); }
nomask int queue_action( mixed val ) { return aq_add( val ); }
int action_queue_empty() { return sizeof(actionq) == 0; }

nomask int query_current_action_forced() { return curr_forced; }

/*
 * This should be called each heart beat..
 * This loops on perform_next_action until time is done or the max eval is
 * is hit, probably.  For security we might want to ENSURE this is only
 * called once per heartbeat.
 */
void act() 
{
  trivial_actions_performed = 0;
  if ( time_left < max_time )
  {
    time_left += this_object()->query_bits_per_beat();
    time_left = ( time_left > max_time ) ? max_time : time_left;
  }

  while( perform_next_action() )
  {
    if ( show_prompt && this_object() )
    {
      this_object()->show_prompt();
      /* show busy status; mudos wont in this case */
      this_object()->write_prompt();  
    }
  }
  hb_command_done = 0;
} /* act() */


/*
 * The great command enqueuer.  Fwheee.
 * If this_object has no heartbeat, it won't do anything.  Actions
 * can go right on through, then.
 * Otherwise, it sticks it on the queue and tells everyone its been done.
 * Well it's worse than that.  If we're the one trying to do the
 * action, then we let it through.
 */
nomask int action_check(string str) 
{
  int i;


  /* this is ridiculous.  MudOS will not show these strings as equal. */
  if ( str ==  command_in_progress )
    return 0;

  /* check for some special queue-affecting commands */
  switch( str )
  {
    case "restart":
      if ( query_heart_beat(this_object()) )
        write("You don't need your heartbeat restarted.\n");
      else
      {
        write("Attempting to restart heartbeat..\n");
        actionq = ({ });  /* will get cascading failure without this */
        set_heart_beat(1);
        catch(this_object()->flush_spell_effects());
      }
      return 1;

    case "stop":
      if ( sizeof(actionq) != 0 )
        aq_delete_user_actions();
      write("Removed queue.\n");
      return 1;

    case "abort":
      if ( !ia_in_progress )
      {
        write("You are not in the middle of an action which may be "
          "aborted.\n");
        return 1;
      }
      abort_interruptable_action();
      return 1;
    case "flee":
      environment(this_object())->do_random_move_command();
      return 1;
  }
      
  if ( query_heart_beat(this_object()) == 0  )
  {
    write("WARNING: You have no heartbeat; try 'restart' to try to "
      "restart it.  Nothing will get performed without your heartbeat.\n");
  }

  if ( sizeof(actionq) >= AQ_MAX_ACTIONS )
  {
    tell_object(this_object(), "Too many commands queued already; "
      "ignoring '"+str+"'.\n");
    return 1;
  }

  if(this_object()->action_blocked())
  {
    /* Wonderflug, Dec 95, making this more flexible --
     * can specify the string that the block puts out.
     * A year later, adding ability to make it a function pointer too.
     */
    mixed pop = this_object()->action_blocked();

    if ( stringp(pop) )
    {
      write(pop);
      if(!this_object()->query_lord())
        return 1;
    }
    else if ( functionp( pop) )
      return evaluate( pop );
    else
    {
      write("You have passed out, you cant do anything.\n");
      if(!this_object()->query_lord())
        return 1;
    }
  }

  /* not sure why this is necessary.. */
  str=replace_string(str,"@@","");

  this_object()->add_history(str);

  /* The latency is too much, so we've added a check to see
   * if it's ok to execute the command right away.
   */
  if ( (i=aq_add( str )) != AQ_OK )
    write("Error queuing '"+str+"', "+i+"\n");
  else if ( ia_in_progress )
    write( ia_message );
  else 
  {
    /* added the while below to remove latency in history/alias commands 
     * as well; to get prompting correct, I've also unrolled the first
     * iteration of the loop into an if.
     */
    if ( sizeof(actionq) >= 1 && time_left > 0 
            && trivial_actions_performed < MAXIMUM_COMMANDS_PER_HB )
      perform_next_action();

    while ( sizeof(actionq) >= 1 && time_left > 0 
            && trivial_actions_performed < MAXIMUM_COMMANDS_PER_HB )
    {
      this_object()->show_prompt();
      this_object()->write_prompt();
      perform_next_action();
    }
  }
    
  if ( show_prompt && this_object() )
    this_object()->show_prompt();

  return 1;
} /* action_check() */


/* Always return 0 to get the driver's notify_fail;
 * however getting here, we can be pretty sure that no 'real' action
 * was done, so we know a trivial command was done.  Anything using a
 * notify_fail shouldn't be a real action anyway, or can adjust time itself.
 */
nomask int lower_check(string str) 
{
  if ( command_in_progress )
  {
    trivial_action_in_progress = 1;
    trivial_actions_performed++;
  }

  return 0;
} /* lower_check() */
