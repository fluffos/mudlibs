//===========================================================================
//  Error Handling
//
//===========================================================================

//---------------------------------------------------------------------------
void dangling_lfun_closure ()

// Handle a dangling lfun-closure.
//
// This is called when the gamedriver executes a closure using a vanished
// lfun, with previous_object() showing the originating object. A proper
// handling is to raise a runtime error.
//
// Technical:
//   Upon replacing programs (see efun replace_program()), any existing
//   lambda closures of the object are adjusted to the new environment.
//   If a closure uses a lfun which vanished in the replacement process,
//   the reference to the lfun is replaced by an alien-lfun closure
//   referencing this function.  The error will then occur when the execution
//   of the adjusted lambda reaches the point of the lfun reference.
//   There are two reasons for the delayed handling. First is that the
//   program replacement and with it the closure adjustment happens at
//   the end of a backend cycle, outside of any execution thread: noone
//   would see the error at this time.
//   Second, smart closures might know/recognize the program replacement
//   and skip the call to the vanished lfun.

{
  raise_error("dangling lfun closure\n");
}


//---------------------------------------------------------------------------

void log_error(string file, string message, int warn)

// Announce a compiler-time error or warning.
//
// Arguments:
//   file: The name of file containing the error/warning (it needn't be
//         an object file!).
//   err : The error/warning message.
//   warn: non-zero if this is a warning, zero if it is an error.
//
// Whenever the LPC compiler detects an error or wants to issue a warning,
// this function is called.
// It should at least log the message in a file, and also announce it
// to the active player if it is an wizard.
{
  string name;

  name = get_wiz_name(file);
  if (name == 0)
    name = "log";
  if (!warn) write(message);
  write_file("/log/errors/" + name + ".log", message);
}


//---------------------------------------------------------------------------
int heart_beat_error(object heart_beat,
                     string error,
                     string program,
                     string current_object,
                     int line)
// Announce an error in the heart_beat() function.
//
// Arguments:
//   culprit: The object which lost the heart_beat.
//   err    : The error message.
//   prg    : The executed program (might be 0).
//   curobj : The object causing the error (might be 0).
//   line   : The line number where the error occured (might be 0).
//
// Result:
//   Return anything != 0 to restart the heart_beat in culprit.
//
// This function has to announce an error in the heart_beat() function
// of culprit.
// At time of call, the heart_beat has been turned off.
// A player should at least get a "You have no heartbeat!" message, a more
// advanced handling would destruct the offending object and allow the
// heartbeat to restart.
//
// Note that <prg> denotes the program actually executed (which might be
// inherited one) whereas <curobj> is just the offending object.
{
  if (query_ip_number(heart_beat)) {
    catch(tell_object(
	  heart_beat,
	  "Game driver tells you: You have no heart beat !\n"
    ));
    if (heart_beat && query_player_level("error messages")) {
    	catch(tell_object(heart_beat, error +"\n"));
    	catch(tell_object(heart_beat, ((current_object)
              ? "program: " + program +
                ", object: "+ current_object +
                " line " + line + "\n"
              : "")));
    }
  }
#ifdef LOG_HB_ERROR
  string wiz_name;
  if (environment(this_player())) {
    write_file(LOG_HB_ERROR,
               "Room: " + FILE_NAME(environment(this_player())) +
               "\nError: " + error +
               "Program: " + program +
               "\nObject: " + current_object +
               "\nLine: " + line + "\n\n");
    if (!(wiz_name = get_wiz_name(FILE_NAME(environment(this_player()))))) {
      if (!(wiz_name = get_wiz_name(current_object))) {
        return 0;
      }
    }
    write_file(WIZARD_DIR + wiz_name +"/HB_ERRORS",
               "Room: " + FILE_NAME(environment(this_player())) +
               "\nError: " + error +
               "Program: " + program +
               "\nObject: " + current_object +
               "\nLine: " + line + "\n\n");
  }
#endif
  return 0; /* Don't restart */
}

//---------------------------------------------------------------------------
void runtime_error (string error, string program, string current_object,
                    int line, mixed culprit)

// Announce a runtime error.
//
// Arguments:
//   err    : The error message.
//   prg    : The executed program.
//   curobj : The object causing the error.
//   line   : The line number where the error occured.
//   culprit: -1 for runtime errors; the object holding the heart_beat()
//            function for heartbeat errors.
//
// This function has to announce a runtime error to the active user,
// resp. handle a runtime error which occured during the execution of
// heart_beat() of <culprit>.
//
// For a normal runtime error, if the active user is a wizard, it might
// give him the full error message together with the source line; if the
// user is a is a player, it should issue a decent message ("Your sensitive
// mind notices a wrongness in the fabric of space") and could also announce
// the error to the wizards online.
//
// If the error is a heartbeat error, the heartbeat for the offending
// <culprit> has been turned off. The function itself shouldn't do much, since
// the lfun heart_beat_error() will be called right after this one.
//
// Note that <prg> denotes the program actually executed (which might be
// inherited) whereas <curobj> is just the offending object for which the
// program was executed.
{
  object ob;

  /* do not print self-created errors which log the time */
  if ((current_object != object_name(this_object()) || 
       (error[0..5] != "Time: "))) {
    if (!(ob = this_player()) || !interactive(this_player())) {
      ob = this_interactive();
    }
    if (ob && query_player_level("error messages")) {    
      if (current_object) {
        catch(tell_object(ob, error + "program: " + program + ", object: " + 
                          current_object + " line " + line + "\n"));
      }   
      else {
        catch(tell_object(ob, error));
      }
    }
    else {
      catch(ob && tell_object(ob, "Your sensitive mind notices a wrongness "
                              "in the fabric of space.\n"));
    }
    debug_message((stringp(error) 
                   ? error[0..<2] 
                   : to_string(error)) +
                     " in " + current_object + " (" + program + ":" + line +
                     ")\n");
    if (time_of_last_error < time() - 60) {
      time_of_last_error = time();
      debug_message("Time: " + ctime() + "\n");
    }
    debug_message("-------------------------------------------------\n");  
  }
}

