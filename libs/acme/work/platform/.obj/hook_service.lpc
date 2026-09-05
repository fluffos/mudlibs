/**
 * The service providing driver hooks.
 *
 * @author devo@eotl
 * @alias HookService
 */
#pragma no_clone
#include <sys/driver_hook.h>
#include <object.h>
#include <sql.h>

private inherit ObjectLib;

public void setup();
public void telnet_neg_hook(int action, int option, int *opts);
public string auto_include_hook(string base_file, string current_file, 
                                int sys);
public varargs mixed uids_hook(string objectname, object blueprint);
public int command_hook(string command, object command_giver);
public void move_object_hook(object item, object dest);  
protected void track_object(object ob);
public int create_hook(object ob);  
public int reset_hook(object ob);
public int clean_up_hook(int ref, object ob);
private void register_hooks();

/**
 * Setup the HookService.
 */
public void setup() {
  register_hooks();
}

/**
 * Telnet negotiation hook. Defer to ConnectionTracker for processing.
 * 
 * @param  action        negotation action (DO/DONT/WILL/WONT)
 * @param  option        negotation option
 * @param  opts          extra args to the negotation
 */
public void telnet_neg_hook(int action, int option, int *opts) {
  return ConnectionTracker->telnet_negotiation(THISP, action, option, opts);
}

/**
 * Auto-include string hook. This is simply '#include <auto.h>' in everything
 * but another auto.h.
 * 
 * @param  base_file     filename of compiled object
 * @param  current_file  the file doing the include
 * @param  sys           1 if sys include, otherwise 0
 * @return the auto include string
 */
public string auto_include_hook(string base_file, string current_file, 
                                int sys) {
  if (current_file && (current_file[<7..] == "/" AutoInclude)) {
    return "";
  } else {
    return "#include <" AutoInclude ">\n";
  }
}

/**
 * UIDs hook. Currently a stub returning "root" for all objects.
 * 
 * @param  objectname    the object name of the compiled object
 * @param  blueprint     the program name of the blue print, if a clone
 * @return a string to use for both uid and euid
 */
public varargs mixed uids_hook(string objectname, object blueprint) {
  // FUTURE implement uids
  return "root";
}

/**
 * Command hook. Runs whenever a user command is executed. Defers to 
 * do_command() in the command giver.
 * 
 * @param  command       the command being executed
 * @param  command_giver the command giver
 * @return 1 if command was found and executed, otherwise 0
 */
public int command_hook(string command, object command_giver) {
  if (command_giver->is_command_giver()) {
    return command_giver->do_command(command);
  }
  return 0;
}

/**
 * Move object hook. Handles the try/catch and signal function sequence, as 
 * well as init() with the appropriate command giver and actually moving the
 * object.
 * 
 * @param  item          the item being moved
 * @param  dest          the environment being moved into
 */
public void move_object_hook(object item, object dest) {  
  object origin = ENV(item);
  if (origin && origin->prevent_leave(item, dest)) { return; }
  if (!(item && dest)) { return; }
  if (item->prevent_move(dest)) { return; }
  if (!(item && dest)) { return; }
  if (dest->prevent_enter(item)) { return; }

  set_environment(item, dest);

  if (origin && origin->leave_signal(item, dest)) { return; }
  item->move_signal(origin);
  if (!(item && dest)) { return; }
  dest->enter_signal(item, origin);
  if (!(item && dest)) { return; }
  if (ENV(item) != dest) { return; }

  object oldp = this_player();

  if (living(item)) {
    set_this_player(item);
    dest->init();
    if (ENV(item) != dest) {
      return;
    }
  }

  object *others = all_inventory(dest);

  others[member(others, item)] = 0;
  filter(others, (: 
    if ($2 && living($1)) {
      set_this_player($1);
      $2->init();
    }
    return;
  :), item);

  if (living(item)) {
    set_this_player(item);
    filter_objects(others, "init");
  }

  if (item && living(dest)) {
    set_this_player(dest);
    item->init();
  }

  set_this_player(oldp);
  return;
}

/**
 * Used by the create hook to notify appropriate tracker objects of the 
 * creation of a new object.
 * 
 * @param  ob            the object being created
 */
protected void track_object(object ob) {
  mixed path_info = get_path_info(ob);
  string zone_id = path_info[PATH_INFO_ZONE];

  if (FINDO(ZoneTracker)) {
    ZoneTracker->new_zone(zone_id);
  }

  if (FINDO(ProgramTracker)) {
    if (!clonep(ob)) {
      ProgramTracker->new_program(ob);
    } else {
      ProgramTracker->program_cloned(ob);
    }
  }

  if (FINDO(ObjectTracker)) {
    ObjectTracker->new_object(ob);
  }

  return;
}

/**
 * Create hook, for initializing newly compiled objects. Informs ZoneTracker
 * and ObjectTracker there is a new object being created, and finishes by 
 * invoking create() in the new object.
 * 
 * @param  ob            the object being created
 * @return 0, to indicate the object's current time to reset should be 
 *         preserved
 */
public int create_hook(object ob) {  
  if (load_name(ob) == SQLiteClient) {
    call_out(#'track_object, 0, ob);
  } else {
    track_object(ob);
  }

  ob->create();
  return 0;
}

/**
 * Reset hook. Defer to reset() lfun in object being reset.
 * 
 * @param  ob            the object being reset
 * @return time until next reset, in seconds
 */
public int reset_hook(object ob) {
  return ob->reset();
}

/**
 * Clean up hook. Defer to clean_up() lfun in object being cleaned up.
 * 
 * @param  ref           the object's ref count
 * @param  ob            the object being cleaned up
 * @return time until next clean up attempt, in seconds
 */
public int clean_up_hook(int ref, object ob) {
  return ob->clean_up(ref);
}

/**
 * Register all of HookService's hooks with the driver.
 */
private void register_hooks() {
  set_driver_hook(H_TELNET_NEG, unbound_lambda(
    ({ 'action, 'option, 'opts }),
    ({ #'call_other, HookService, "telnet_neg_hook", 'action, 'option, 'opts })
  )); //'

  set_driver_hook(H_AUTO_INCLUDE, unbound_lambda(
    ({ 'base_file, 'current_file, 'sys }),
    ({ #'call_other, HookService, "auto_include_hook", 'base_file, 
                                                       'current_file, 'sys })
  )); //'

  set_driver_hook(H_LOAD_UIDS, unbound_lambda(
    ({ 'objectname }),
    ({ #'call_other, HookService, "uids_hook", 'objectname })
  ));
  set_driver_hook(H_CLONE_UIDS, unbound_lambda(
    ({ 'blueprint, 'objectname }),
    ({ #'call_other, HookService, "uids_hook", 'objectname, 'blueprint })
  )); //'

  set_driver_hook(H_COMMAND, unbound_lambda(
    ({ 'command, 'command_giver }),
    ({ #'call_other, HookService, "command_hook", 'command, 'command_giver })
  )); //'

  set_driver_hook(H_MOVE_OBJECT0, unbound_lambda(
    ({ 'item, 'dest }),
    ({ #'call_other, HookService, "move_object_hook", 'item, 'dest })
  ));

  set_driver_hook(H_CREATE_OB, unbound_lambda(
    ({ 'obj }),
    ({ #'call_other, HookService, "create_hook", 'obj })
  )); //'
  set_driver_hook(H_CREATE_CLONE, unbound_lambda(
    ({ 'obj }),
    ({ #'call_other, HookService, "create_hook", 'obj })
  )); //'
  set_driver_hook(H_CREATE_SUPER, unbound_lambda(
    ({ 'obj }),
    ({ #'call_other, HookService, "create_hook", 'obj })
  )); //'

  set_driver_hook(H_RESET, unbound_lambda(
    0,
    ({ #'call_other, HookService, "reset_hook", ({ #'this_object }) })
  ));

  set_driver_hook(H_CLEAN_UP, unbound_lambda(
    ({ 'ref, 'obj }),
    ({ #'call_other, HookService, "clean_up_hook", 'ref, 'obj })
  ));
}

/**
 * Constructor. Register hooks.
 */
public void create() {
  setup();
}
