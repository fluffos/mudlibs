//===========================================================================
//  Initialisation
//
// These functions are called after (re)loading the master to establish the
// most basic operation parameters.

#define BACKBONE_WIZINFO_SIZE 5
#define ATTRIBUTE_INDEX 2

//---------------------------------------------------------------------------
void inaugurate_master (int arg)

// Perform mudlib specific setup of the master.
//
// Argument:
//   arg: 0 if the mud just started.
//        1 if the master is reactivated destructed one.
//        2 if the master is a reactivated destructed one, which lost all
//             variables.
//        3 if the master was just reloaded.
//
// This function is called whenever the master becomes fully operational
// after (re)loading (it is now recognized as _the_ master).
// This doesn't imply that the game is up and running.
//
{
  if (!arg) {
    if (previous_object() && previous_object() != this_object())
      return;
    set_extra_wizinfo(0, allocate(BACKBONE_WIZINFO_SIZE));
    get_extra_wizinfo(0)[ATTRIBUTE_INDEX] = ([ ]);
  }

/*
  if (find_call_out("wiz_decay") < 0)
    call_out("wiz_decay", 3600);
*/

  set_driver_hook(
        H_MOVE_OBJECT0,
        unbound_lambda( ({'item, 'dest}),
        ({#'_move_hook_fun, 'item, 'dest })
                      )
                 );

#if __EFUN_DEFINED__(set_auto_include_string)
  set_auto_include_string(AUTO_INCLUDE_STRING);
#else
  set_driver_hook(H_AUTO_INCLUDE, AUTO_INCLUDE_STRING);
#endif

  set_driver_hook(H_LOAD_UIDS, #'creator_file);
  set_driver_hook(H_CLONE_UIDS, #'clone_uid);
  set_driver_hook(H_CREATE_SUPER, "reset");
  set_driver_hook(H_CREATE_OB,    "reset");
  set_driver_hook(H_CREATE_CLONE, "reset");
  set_driver_hook(H_RESET,        "reset");
  set_driver_hook(H_CLEAN_UP,     "clean_up");
  set_driver_hook(H_MODIFY_COMMAND,
    ([ "e":"east", "w":"west", "s":"south", "n":"north"
     , "d":"down", "u":"up", "nw":"northwest", "ne":"northeast"
     , "sw":"southwest", "se":"southeast" ]));
  set_driver_hook(H_MODIFY_COMMAND_FNAME, "modify_command");
  set_driver_hook(H_NOTIFY_FAIL, "What?\n");
  set_driver_hook(H_INCLUDE_DIRS, #'_include_dirs_hook);
  set_driver_hook(H_DEFAULT_PROMPT, "->> ");
}

//---------------------------------------------------------------------------

//int|string get_master_uid ()
int get_master_uid ()
// Return the string to be used as uid (and -euid) of a (re)loaded master.
// Under !native, the function may also return a non-zero number.
// In that case, the uid is set to 0, as is the euid.
{
    return 1;
}

//---------------------------------------------------------------------------
void flag (string arg)

// Evaluate an argument given as option '-f' to the driver.
//

{
  string obj, fun, rest;

  if (arg == "shutdown")
  {
    shutdown();
    return;
  }
  if (sscanf(arg, "call %s %s %s", obj, fun, rest) >= 2)
  {
    write(obj+"->"+fun+"(\""+rest+"\") = ");
    write(call_other(obj, fun, rest));
    write("\n");
    return;
  }
  write("master: Unknown flag "+arg+"\n");
}

//---------------------------------------------------------------------------
string *epilog (int eflag)
// Perform final actions before opening the game to players.
{
    if (eflag)
        return ({});

    debug_message(sprintf("Loading init file %s\n", INIT_FILE));
    current_time = rusage();
    current_time = current_time[0] + current_time[1];
    return explode(read_file(INIT_FILE), "\n");
}

//---------------------------------------------------------------------------
void preload (string file)
// Preload a given object.
{
  int last_time, eval_cost;
  float ff;

  if (strlen(file) && file[0] != '#') {
    debug_message(sprintf("Preloading: %-40'_'s", file + " "));
    last_time = current_time;
    eval_cost = get_eval_cost();
    load_object(file);
    eval_cost -= get_eval_cost();
    current_time = rusage();
    current_time = current_time[0] + current_time[1];
    debug_message(sprintf(" %.2f %6n\n",
                          (current_time - last_time)/1000.,
                           eval_cost));
    }
}

//---------------------------------------------------------------------------
//void external_master_reload ()

// Master was reloaded on external request by SIGUSR1.
//
// If the gamedriver destruct and reloads the master on external request
// via SIGUSR1, it does this by a call to this function.
// It will be called after inaugurate_master() of course.
// If you plan to do additional magic here, you're welcome.
//---------------------------------------------------------------------------
//void reactivate_destructed_master (int removed)

// Reactivate a formerly destructed master.
//
// Arguments:
//   removed: True if the master was already on the list of destructed
//            objects.
//
// This function is called in an formerly destructed master since a new master
// couldn't be loaded.
// This function has to reinitialize all variables at least to continue
// operation.

//---------------------------------------------------------------------------
//string|string* get_simul_efun ()
string get_simul_efun ()
// Load the simul_efun object(s) and return one or more paths of it.
{
  mixed error;
  object ob;

  error = catch(ob = load_object(SIMUL_EFUN));
  if (!error)
  {
  ob->start_simul_efun();
    return SIMUL_EFUN;
  }
  efun::write("Failed to load " + SIMUL_EFUN + ": "+error);
  efun::shutdown();
  return 0;
}


