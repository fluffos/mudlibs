/*---------------------------------------------------------------------------
** std/living/commands
**
** Commands and especially notify_fail-Handling.
**
** 01-Nov-1994  [Mateese]
**---------------------------------------------------------------------------
*/

#include <config.h>

#define PREV previous_object()
#define THIS this_object()
#define TP this_player()

private nosave mixed *command_stack;
private nosave mixed *last_fail;

public void AddHeart(mixed hook); // std/living/heart

//--------------------------------------------------------------------------

public int QueryCmdDataStackSize () { return sizeof(command_stack); }
public mixed QueryLastNotifyFail() { return last_fail; }

//---------------------------------------------------------------------------
public void ExecuteRegistered (mapping frame, int unwind)

// Execute any registered functions in the given stack <frame>.

{
  mixed *values, *entry;
  int i;

  if (!sizeof(frame = frame["RegisteredFuns"]))
    return;

  values = m_values(frame);
  for (i = sizeof(values); i--; )
  {
    entry = values[i];
    if (closurep(entry[0]))
    {
      if (to_object(entry[0]))
        funcall(entry[0], entry[1], unwind);
    }
    else if (entry[0])
      call_other(entry[0], entry[1], entry[2], unwind);
  }
}

//---------------------------------------------------------------------------
public void ResetCmdDataStack ()

// Reset the command data stack.

{
  command_stack = 0;
  last_fail = 0;
}

//---------------------------------------------------------------------------
public varargs void EmptyCmdDataStack (int unwind)

// Empty the command data stack, executing all registered functions.

{
  int i;

  //printf("Called EmptyCmdDataStack(%d)\n", unwind);
  for (i = 0; i < sizeof(command_stack); i++)
    ExecuteRegistered(command_stack[i], unwind);
  command_stack = 0;
}

//---------------------------------------------------------------------------
public void PushCmdData ()

// Push a new 'default' entry onto the command data stack.

{
  object prev_player;
  if (command_stack)
    prev_player = command_stack[0]["ThisPlayer"];
  command_stack = ({ ([ "NotifyFail":({ "What?\n", NOTIFY_DEFAULT }) 
                      , "PreviousPlayer": prev_player
                     ]) })
                  + (command_stack || ({}) );
  last_fail = ({ "What?\n", NOTIFY_DEFAULT });
  AddHeart("ResetCmdDataStack");
}

//---------------------------------------------------------------------------
public varargs mapping PopCmdData (int unwind)

// Pop the topmost entry from the command data stack, generating a default
// entry if the stack is empty.
// This will also execute functions registered with the popped frame.

{
  mapping rc;

  if (!command_stack)
    rc = ([ "NotifyFail":({ "What?\n", NOTIFY_DEFAULT }) ]);
  else
    rc = command_stack[0];
  last_fail = rc["NotifyFail"] + ({});
  if (sizeof(command_stack) > 1)
    command_stack = command_stack[1..];
  else
    command_stack = 0;
  ExecuteRegistered(rc, unwind);
  return rc;
}

//---------------------------------------------------------------------------
public mixed SetCmdData (string name, mixed data)

// Set an entry in the command data stack.

{
  if (!command_stack)
  {
    command_stack = ({ ([ "NotifyFail": ({ "What?\n", NOTIFY_DEFAULT }) ]) });
    last_fail = command_stack[0]["NotifyFail"]+({});
  }
  AddHeart("ResetCmdDataStack");
  return command_stack[0][name] = data;
}

//---------------------------------------------------------------------------
public mixed QueryCmdData (string name)

// Set an entry in the command data stack.

{
  if (!command_stack)
    return 0;
  return command_stack[0][name];
}

//---------------------------------------------------------------------------
public varargs void NotifyFail (mixed msg, int pri)

// Set a notify_fail message.

{
  if (!command_stack) {
    command_stack = ({ ([ "NotifyFail":({ msg, pri }) ]) });
  }
  else if (command_stack[0]["NotifyFail"][1] >= pri) {
    command_stack[0]["NotifyFail"][0] = msg;
    command_stack[0]["NotifyFail"][1] = pri;
  }
  last_fail = command_stack[0]["NotifyFail"]+({});
  AddHeart("ResetCmdDataStack");
}

//---------------------------------------------------------------------------
public varargs void RegisterCmdFun (mixed funarg, mixed args) 

// Register a function to be executed after this command.

{
  mixed entry;
  string key;
  mapping m;
  int i;

  if (closurep(funarg))
  {
    key = sprintf("%O", funarg);
    key[0..1] = "/";
    entry = ({ funarg, args });
  }
  else if (stringp(funarg))
  {
    if (-1 == (i = strstr(funarg, "->")))
    {
      key = to_string(PREV)+"->"+funarg;
      entry = ({ PREV, funarg, args });
    }
    else 
    {
      key = resolve_file(funarg[0..i-1], PREV);
      entry = ({ key, funarg[i+2..], args });
      key += funarg[i..];
    }
  }
  else if (pointerp(funarg))
  {
    entry = funarg+({ args });
    key = to_string(funarg[0])+"->"+funarg[1];
  }

  if (!command_stack) 
  {
    command_stack = ({ ([ "NotifyFail":({ "What?", NOTIFY_DEFAULT }) ]) });
    m = ([]);
  }
  else if (!(m = command_stack[0]["RegisteredFuns"]))
    m = ([]);

  m[key] = entry;
  command_stack[0]["RegisteredFuns"] = m;
  AddHeart("ResetCmdDataStack");
}

//--------------------------------------------------------------------------
public int command_me (string cmd)

// Let the living execute a command.
// The /secure/simul_efun and /secure/master will call the routines
// to handle the notify_fail stack.

{
  int oldsize, rc;

  oldsize = sizeof(command_stack);
  rc = command(cmd);
  // If this command_me() call was a successful force, we have to
  // clean up the stack manually. HASS!
  if (sizeof(command_stack))
    last_fail = command_stack[0]["NotifyFail"]+({});
  else
    last_fail = ({ "What?", NOTIFY_DEFAULT });
  while (sizeof(command_stack) > oldsize)
    PopCmdData();

  if (THIS)
  {
    THIS->FlushReceive();
    AddHeart("ResetCmdDataStack");
  }
  
  return rc;
}

/***************************************************************************/
