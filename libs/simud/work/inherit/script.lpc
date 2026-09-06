/** The script object was a quick and entertaining hack which is gradually
 * turning into a useful system. For this reason, it seems wise to explain how
 * it works, as the code is much less than clear.
 *
 * One of the important tricks of scripting is /include/const/scriptconst.h.
 * This file contains a series of macros that look like rather simple commands,
 * but which expand out to some fairly hard-to-read stuff. The main trick is that
 * the arguments themselves are wrapped in (: :), which build closures. These
 * are then added to an array of commands (with addcom). All of the addcom
 * stuff is called when the object is created, so the command mappings are built
 * when the object loads. Actually executing the scripts happens later.
 *
 * The commands are generally executed in order, but there are a few tricks that
 * are used. One trick is "labels." Labels are a mapping of label-name to
 * array index. Many of the commands, especially conditional ones, rely heavily
 * on labels to control the flow of the script. Labels are also used to handle
 * blocks.
 *
 * There are some commands which simply do something, and these are generally
 * pretty simple. Such are Print, Lpc, Com, Say, Emote, Emit, and EmitTo.
 * These use "do_lpc" as their closure handler, which does nothing more than
 * evaluate the parameter and return. They don't affect flow much. There
 * are some more complex commands, however:
 *
 * Delay -- This command uses do_delay, which is a special behavior. This
 * command sets the "program counter" to an invalid value, and creates a
 * call_out to the run() function, passing the entire script state as parameters
 * to the call_out. Script states aren't very heavy, so that's not a big
 * deal. Once the call_out triggers, the delay is considered finished,
 * and the program resumes. Setting the program counter to an invalid value
 * is how you terminate the script. Note also that the run() function has
 * an otherwise unused 'start position' value, which is how it is able to
 * resume where it left off.
 *
 * Goto -- The handler simply sets the program counter to the given label.
 *
 * Label -- The user gets to choose the label. When the script is compiled,
 * the current position is stored as the label to be retrieved later.
 *
 * If -- The evaluated closure is passed as a parameter to do_if, so the
 * parameter will either be true or false. If true, the condition succeeded,
 * if false, then it didn't. If the condition is true, the if statement
 * proceeds onto the next line of code; if the condition is false, then the
 * next line of code is skipped. This interacts with "Do" in a subtle
 * but important way.
 *
 * Do -- The do statement adds TWO commands to the command list. The
 * first is an unconditional "skip the next command", which uses the
 * function "do_do" and doesn't use any parameters. The SECOND command
 * is "jump to the end of this block". It generates a label for the
 * end of the block at this point, and then pushes that label onto
 * the "block_stack", a variable only used at compile time. The End
 * label will pop a value off the block_stack, and use it as a label,
 * which is how the end of the block is found.
 *
 * When you hit the "Do" statement, the 'jump to end of block' command
 * is skipped, and the block is executed. If you skip the Do statement,
 * such as occurs when an If fails, the 'jump to end of block' command
 * is triggered, and the block is missed.
 *
 * An "Else" statement looks almost exactly like a Do, except that it
 * inverts the behavior. Else's first command is to skip to the end
 * of the block; whatever follows is marked as the end of the previous
 * block (so Else must come at the end of a block), and a new block is
 * added to the block stack (so you must put an End at the end of the
 * Else). So if a Do statement drops to the end of its block, and it
 * was followed by an Else, then the Else block will be executed.
 * If the Do reaches the end of its block uneventfully, it will execute
 * the 'skip' statement, and the Else block will not be executed.
 * Honestly, if you're not already familiar with what If/Do/Else/End
 * ought to do, then you're going to find this confusing.
 *
 * The End statement terminates the previous block, marking it with
 * an end-of-block marker; the only exception is the End that is
 * used to end the scripts entirely, which actually turns out to
 * be a no-op in the final command list. Actually, all Ends are
 * no-ops, they just add labels.
 *
 * This is not the most current list of operations; for a complete list,
 * read the comments in /include/scriptconst.h (where the operations
 * are actually defined).
 */

struct Command {
   closure com;
   closure param;
   int line;
};

nosave mapping scripts = ([ ]);
nosave struct Command *curr_script;
nosave string curr_script_name;
nosave mapping labels = ([ ]);
nosave int pc;
nosave int curr_block, *block_stack;

nosave mapping script_vars;

void set_script_vars( mapping m ) { script_vars = m; }
mapping query_script_vars() { return script_vars; }

void set_script_var( string var, mixed val ) {
   if( !mappingp(script_vars) )
      script_vars = ([ ]);
   script_vars[var] = val;
}

mixed query_script_var( string var ) {
   if( !mappingp(script_vars) )
      return 0;
   return script_vars[var];
}

mapping query_scripts() {
   return scripts;
}

void end_run() {
   script_vars = 0;
   pc = -1;
}

void do_print( int line, string val ) {
   if( !stringp(val) ) raise_error( "Error on script line " + line + ": Print requires a string as input." );
   msg( to_string(val) );
}

void do_delay( int line, int val ) {
   if( !intp(val) ) raise_error( "Error on script line " + line + ": Delay requires an integer as input." );
   call_out( "run", val, curr_script_name, query_script_vars(), pc );
   end_run();
}

void do_com_wait( int line, object who ) {
   if( sizeof(who->query_actions()) ) {
      // Repeat the current line if commands are waiting.
      call_out( "run", 4, curr_script_name, query_script_vars(), pc - 1 );
      end_run();
   }
   // Otherwise do nothing, wait's over.
}

void do_move_wait( int line, object who ) {
   if( environment(who)->query_is_port_bubble() ) {
      // Repeat the current line if we haven't finished the move yet.
      call_out( "run", 4, curr_script_name, query_script_vars(), pc - 1 );
      end_run();
   }
   // Otherwise do nothing, wait's over.
}

void do_abort( int line ) {
   // Don't use end_run(), we might want to just return to the
   // previous script up.
   pc = -1;
}

void do_lpc( int line, mixed val ) {}

void do_goto( int line, string target ) {
   if( !member(labels, target) ) raise_error( "No such label \"" + target + "\" on line " + line );
   pc = labels[target];
}

void do_if( int line, mixed condition ) {
   if( !condition ) pc++;
}

void do_do( int line ) {
   pc++;
}

void do_set( int line, mixed *param ) {
   set_script_var( param[0], param[1] );
}

void do_sscanf( int line, string str, string fmt ) {
   if( !stringp(str) || !stringp(fmt) ) {
      set_script_var( "match0", 0 );
      return;
   }

   int i;
   string *matches=allocate(9);
   int match_count = sscanf(str,fmt,matches[0],matches[1],matches[2],matches[3],matches[4],matches[5],matches[6],matches[7],matches[8]);
   set_script_var( "match0", match_count );
   for( i = 0; i < sizeof(matches); ++i )
      set_script_var( "match"+(i+1), matches[i] );
}

void do_gosub( int line, string subroutine ) {
   if( !member(scripts, subroutine) )
      return;
   mixed *stack = query_script_var("_callstack");
   if( !pointerp(stack) ) stack = ({ });
   if( sizeof(stack) > 24 ) {
      debug( "Overly deep callstack: " + implode(explode(as_string(map(stack,(:$1[0]:))),"\n")," "), "script" );
      raise_error( "Improbably deep call stack on line " + line + "; call stack dumped to debug:script." );
   }
   stack += ({ ({ curr_script_name, pc }) });
   set_script_var( "_callstack", stack );
   pc = 0;
   curr_script = scripts[subroutine];
   curr_script_name = subroutine;
   // Note that we leave the vars alone for subroutine calls; this gives
   // a rudimentary passing mechanism, if you need one.
}

void addlabel( string name, int line ) {
   if( !stringp(name) ) raise_error( "Label must be a string, on line " + line );
   if( member(labels, name) ) raise_error( "Duplicate label " + name + " on line " + line );
   labels[name] = sizeof(scripts[curr_script_name]);
}

void addcom( closure com, mixed param, int line ) {
   struct Command c = (<Command>);
   c->com = com;
   c->param = param;
   c->line = line;
   scripts[curr_script_name] += ({ c });
}

void addscript( string s, int line ) {
   if( member(scripts, s) ) raise_error( "Script " + s + " defined for a second time on line " + line );
   scripts[s] = ({ });
   curr_script_name = s;
}

varargs int run( string script_name, mapping vars, int start_pc ) {
   if( mappingp(vars) )
      set_script_vars( vars );
   curr_script_name = script_name;
   curr_script = scripts[script_name];
   if( !curr_script )
      return 0;
      //raise_error( "No such script: " + script_name );
   pc = start_pc;
   int need_return;
   do {
      need_return = 0;
      while( pc >= 0 && pc < sizeof(curr_script) ) {
         string err;
         int curr_line;
         pc++;
         curr_line = curr_script[pc-1]->line;
         err = catch( apply(curr_script[pc-1]->com, curr_line, apply(curr_script[pc-1]->param)) );
         if( err ) raise_error( "Script line " + curr_line + ": " + err );
      }
      // Ended the script, but if there's a callstack, we need to return.
      mixed *stack = query_script_var( "_callstack" );
      if( pointerp(stack) && sizeof(stack) ) {
         need_return = 1;
         mixed settings = stack[<1];
         curr_script_name = settings[0];
         curr_script = scripts[curr_script_name];
         pc = settings[1];
         set_script_var( "_callstack", stack[..<2] );
      }
   } while( need_return );
   return 1;
}

void _create_script() {
   curr_block = 0;
   block_stack = ({ });
   if( function_exists("setup_script") )
      this_object()->setup_script();
   if( sizeof(block_stack) != 0 ) raise_error( "Script error: Not enough End statements." );
}
