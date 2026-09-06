#ifndef _SCRIPTCONST_H_
#define _SCRIPTCONST_H_

#ifdef IS_AI_MODULE
#define Myself environment()
#else
#define Myself this_object()
#endif

// You may only have one ScriptBegin per .c file. If you wish
// to parse the scripts in the parent as well, you should include
// a call to "InheritScripts" as the first line after ScriptBegin.
#define ScriptBegin void setup_script() { block_stack += ({ -1 });
#define InheritScripts ::setup_script();

// Something like a function declaration. This gives
// the name of the script you will be executing.
#define Script(s) addscript(s, __LINE__ ); block_stack += ({ -1 }); {

// Prints the string defined by 'x'. Mostly useful for debugging.
#define Print(x) addcom( #'do_print, (: x :), __LINE__ );

// Delays for x or more seconds, roughly. Execution resumes after the
// delay.
#define Delay(x) addcom( #'do_delay, (: x :), __LINE__ );

// Jumps to the label given by the string "x". 'x' must
// be a string, and the label must be defined.
#define Goto(x) addcom( #'do_goto, (: x :), __LINE__ );

// Execute the script given by x. When it's finished, resume
// the current script at its current position. If the script
// given by x doesn't exist, it will quietly do nothing. Note
// that any variables currently available will be available
// to the subroutine script, and any variables set by the
// subroutine script will be set in the calling script as well.
// For debugging purposes, you may Query("_callstack") for
// the current list of scripts being executed.
#define Gosub(x) addcom( #'do_gosub, (: x :), __LINE__ );

// Adds a label to the code. Good for control logic.
#define Label(x) addlabel( x, __LINE__ );

// Executes a snippet of LPC. You may use global variables
// and functions, as well as script variables and functions,
// in the LPC but there are no local variables in scripts.
#define Lpc(x) addcom( #'do_lpc, (: x :), __LINE__ );

// Executes a command as if it had been typed into the command
// line. Does not wait for the command to complete.
#define Com(x) addcom( #'do_lpc, (: command( x, Myself ) :), __LINE__ );
// Same as above, but waits for completion.
#define ComWait(x) addcom( #'do_lpc, (: command( x, Myself ) :), __LINE__ ); addcom( #'do_com_wait, (: Myself :), __LINE__ );

// Used for control logic. The parameter is a statement that
// evaluates to true or false (like Target != Actor). The
// general forms are:
// If( x ) <one statement>
// If( x ) Do ... End
// If( x ) Do ... Else ... End
#define If(x) addcom( #'do_if, (: x :), __LINE__ );

// Say something using the say command.
#define Say(x) addcom( #'do_lpc, (: command("say " + x, Myself) :), __LINE__ );
#define SayTo(dest, text) addcom( #'do_lpc, (: command("say " + (stringp(dest)?dest:dest->query_name()) + ": " + text, Myself) :), __LINE__ );

// Sets a variable with name "x" (which must be a string) to
// value "y".
#define Set(x, y) { string key=x; if( !stringp(key) ) raise_error( "Script error: Var name must be a string in Set on line " + __LINE__ ); addcom( #'do_lpc, (: set_script_var(key, y); return 0; :), __LINE__ ); }

// Retrieves value with name "x", which must be a string. Only
// useful embedded inside of other script code (and will have funny
// effects if you try and leave it standing alone).
#define Query(x) query_script_var( x )

// Emote something using the emote command.
#define Emote(x) addcom( #'do_lpc, (: command("emote " + x, Myself) :), __LINE__ );

// Echo something; the default color is ~CACT, and the restoration to ~CDEF
// is included.
#define Echo(x) addcom( #'do_lpc, (: Myself->msg_local( "~CACT" + x + "~CDEF" ); return 0; :), __LINE__ );

// Echo something to a particular person.
#define EchoTo(x,y) addcom( #'do_lpc, (: set_target(x); Myself->msg_local( "~CACT" + y + "~CDEF" ) :), __LINE__ );

// Marks the beginning of a block. Appropriate for use with If().
#define Do addcom( #'do_do, 0, __LINE__ ); block_stack += ({ curr_block }); addcom( #'do_goto, "__block" + (curr_block++), __LINE__ ); {

// Marks an alternate clause on a block. See If().
#define Else if( sizeof(block_stack) == 0 ) raise_error("Script error: Unbalanced Else on line " + __LINE__); addcom( #'do_goto, "__block" + curr_block, __LINE__ ); addlabel( "__block" + block_stack[<1], __LINE__ ); block_stack[<1] = curr_block++;

// Immediately exit this script.
#define Abort addcom( #'do_abort, 0, __LINE__ );

// Immediately exit all scripts, including any that called this script (not necessarily all the scripts running on this object, though).
#define AbortAll addcom( #'do_abort, (: set_script_var("_callstack",0); return 0; :), __LINE__ );

// Pause on this line until the command queue is empty.
#define Catchup addcom( #'do_com_wait, (: Myself :), __LINE__ );

// Walk to the object given by x, which can be a string or an object.
// Does not return until the object is reached, although usually returns
// immediately if walking to that object isn't valid.
#define WalkTo(x) addcom( #'do_lpc, (: mixed ob=x; if(stringp(ob)) ob=present(ob, environment(Myself)); if(!objectp(ob))return 0; "/daemon/walk"->init_walk_action(ob->query_border()?ob->query_border():"/daemon/walk"->shape_adjacent(),ob->query_coord(),({0,"/bin/walk",ob,ST_STANDING,0}),0,0,Myself); return 0; :), __LINE__ ); addcom( #'do_com_wait, (: Myself :), __LINE__ );

// Used to perform sscanf's, which are pretty much impossible otherwise.
// The script vars match1-match9 will be set with whatever the values returned
// by sscanf are; use Set( "whatever", Get("match3") ) to reassign them.
// If you just want to know if the sscanf succeeded, use match0, which
// contains the return value of sscanf.
#define Parse(str,fmt) addcom( #'do_sscanf, (: ({ str, fmt }) :), __LINE__ );

// Gets the object(s) specified in the parameter, which may be
// an array or a single object. Uses the get bin verb.
// Waits for get to complete. The Drop command is the inverse.
#define Get(x) addcom( #'do_lpc, (: mixed oblist=x; if(objectp(oblist))oblist=({oblist}); oblist-=({0}); if(!pointerp(oblist)||sizeof(oblist)<1)return 0; oblist-=({0}); object container="/bin/get"->container_of(oblist[0],Myself); "/daemon/walk"->init_walk_action(container->query_border()?container->query_border():"/daemon/walk"->shape_adjacent(),container->query_coord(),({800,"/bin/get",container,ST_STANDING,oblist}),0,0,Myself); return 0; :), __LINE__ ); addcom( #'do_com_wait, (: Myself :), __LINE__ );
#define Drop(x) addcom( #'do_lpc, (: mixed oblist=x; if(objectp(oblist))oblist=({oblist}); oblist-=({0}); if(!pointerp(oblist)||sizeof(oblist)<1)return 0; oblist-=({0}); Myself->push_action( ({500,"/bin/drop",oblist[0],ST_STANDING,oblist}) ); return 0; :), __LINE__ ); addcom( #'do_com_wait, (: Myself :), __LINE__ );
#define Put(x,y) addcom( #'do_lpc, (: mixed oblist=x, ins=y; if(objectp(oblist))oblist=({oblist}); oblist-=({0}); if( !objectp(ins) ) raise_error( "Invalid 'put' location (" + as_lpc(ins) + ") on script line " + __LINE__ ); if(!pointerp(oblist)||sizeof(oblist)<1)return 0; oblist-=({0}); Myself->push_action( ({500,"/bin/put",y,ST_STANDING,oblist}) ); return 0; :), __LINE__ ); addcom( #'do_com_wait, (: Myself :), __LINE__ );

// Moves the scripted object to a certain place. The second
// parameter is a message to print when you get there, and the
// third parameter is how many heart beats the movement should
// take (no difference between 0 and 1, it always takes at least
// a heart beat).
#define MoveTo(dest) addcom( #'do_lpc, (: if(!dest) return 0; if( environment(Myself) == dest) return 0; Myself->msg_local("~CACT~Name ~verbleave.~CDEF"); object ob = clone_object("/obj/portbubble"); ob->move(dest); Myself->move(ob); return 0; :), __LINE__ ); addcom( #'do_move_wait, (: Myself :), __LINE__ );
#define MoveToCustom(dest, leave_message, arrive_message, delay) addcom( #'do_lpc, (: if(!dest) return 0; if( environment(Myself) == dest) return 0; Myself->msg_local(leave_message); object ob = clone_object("/obj/portbubble"); ob->set_duration(delay); ob->set_arrive_message(arrive_message); ob->move(dest); Myself->move(ob); return 0; :), __LINE__ );

// Returns a value, not usable directly as a command. Returns
// whether a given message contains a keyword. The key may
// have spaces in it.
#define HasKeyword(message, key) (strstr(message,key) >= 0)

// Some script functions will have valid values in these variables.
// If a variable doesn't apply, the value will usually be 0.
#define Actor query_script_var( "actor" )
#define Target query_script_var( "target" )
#define Item query_script_var( "item" )
#define Items query_script_var( "items" )
#define Message query_script_var( "message" )
#define Type query_script_var( "type" )
#define Amount query_script_var( "amount" )

// Marks the end of a script or the end of a block.
#define End if( sizeof(block_stack) == 0 ) raise_error("Script error: Too many 'End' statements on line " + __LINE__ ); if( block_stack[<1] != -1 ) addlabel( "__block" + block_stack[<1], __LINE__ ); block_stack = block_stack[..<2]; }

#endif
