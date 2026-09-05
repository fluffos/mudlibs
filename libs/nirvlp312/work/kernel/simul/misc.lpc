/*
 * kernel/simul/misc.c
 *
 * simul_efuns that are not contained in another /kernel/simul/*.c-file
 * Rumplemintz
 */

#include <call_out_info.h>
#include <closures.h>
#include <lpctypes.h>
#include <input_to.h>
#include <telnet.h>

#include "/kernel/simul/file.h"
#include "/kernel/simul/security.h"
#include "/kernel/simul/array.h"
#include "/kernel/simul/list.h"
#if !__EFUN_DEFINED__(member_array)
#include "/kernel/simul/lpc.h"
#endif

string version() {
  return __VERSION__;
}

string query_host_name() {
  return __HOST_NAME__;
}

#ifdef __START_TIME__
string query_start_time() {
  return __START_TIME__;
}
#endif

private object *sort_objects_in_env(object *items, object env) {
  if (env)
    return sort_map_array(items, #'member_array, #'>, ({ all_inventory(env) }));
  else
    return items;
}

mixed *order_objects(mixed *items) {
  mixed h;
  mapping groups;
  object *envs;

  if (!sizeof(items))
    return items;
  groups = factorize(items, #'typeof);
  h = factorize(groups[T_OBJECT], #'environment);
  m_delete(groups, T_OBJECT);
  envs = m_indices(h) - ({ 0 });
  envs = order_objects(envs);
  if (h[0])
    envs = ({ 0 }) + envs;
  h = map(envs, lambda(({ 'env }),
                          ({ (#'sort_objects_in_env),
                             ({ CL_INDEX, h, 'env }),
                             'env })));
  // h is now an array or arrays, each containing a list of objects which
  // are in the same environment
  return flatten_array(h) + flatten_array(m_values(groups));
}

nomask void remove_interactive(object o) {
  if (!o)
    raise_error("Bad argument 1 to remove_interactive()\n");
  if (!interactive(o))
    raise_error("remove_interactive() of non-interactive object\n");
  catch(o->prepare_remove_interactive()); // let the object prepare
  if (this_interactive() && this_interactive() !=o &&
      this_interactive()->query_vis_name() != o->query_vis_name())
    log_file("DESTRUCT", ctime() + ": " + o->query_vis_name() + " was " +
             "petrified by " + this_interactive()->query_vis_name() + ".\n");
  efun::remove_interactive(o);
}

nomask varargs mixed set_prompt(mixed prompt, object obj) {
  if (closurep(prompt) && to_object(prompt) != obj)
    raise_error("Illegal closure als prompt.\n");
  return efun::set_prompt(prompt, obj);
}

private mixed *call_out_info_helper(mixed *entry) {
  mixed h;
  string name;

  if (closurep(entry[1])) {
    name = sprintf("%O", entry[1]);
    entry[0] = to_object(entry[1]);
    if ((h = strstr(name, "->")) >= 0)  // lfun closure?
      entry[1] = name[h+2..];
  }
  return entry[0..2];
}

/*
 * This is a more detailed and thus more secure version of
 * efun::call_out_info() which returns not always all parameters of the
 * pending call_outs. The mode which returns simply the result of the efun
 * is restricted to calls with privilege 1.
 * #include <call_out_info.h> if you want to use others than the standard
 * parameters
 */
nomask varargs mixed *call_out_info(int mode) {
  switch (mode) {
  case COI_EFUN:
    if (check_previous_privilege(1))
      return efun::call_out_info();
    else
      raise_error("Illegal call of call_out_info()\n");
  case COI_NOARGS:
    return map(efun::call_out_info(), #'call_out_info_helper);
  case COI_ONLYMINE:
    return filter(efun::call_out_info(),
                        lambda(({ 'x }),
                               ({ (#'==),
                                  previous_object(),
                                  ({ (#'||),
                                     ({ CL_INDEX, 'x, 0 }),
                                     ({ (#'to_object),
                                        ({ CL_INDEX, 'x, 1 }) }) }) })));
  case COI_MAXIMAL:
  case COI_DEFAULT:
    return map(efun::call_out_info(),
                     lambda(({ 'x }),
                            ({ (#'?),
                               ({ (#'==),
                                  previous_object(),
                                  ({ CL_INDEX, 'x, 0 }) }),
                               'x,
                               ({ #'call_out_info_helper, 'x }) })));
  default:
    raise_error("Bad argument 1 to call_out_info()\n");
  }
  NO_WARN_MISSING_RETURN;
}

nomask void set_environment(mixed a, mixed b) {
  if (!b && objectp(a) && object_name(a)[0..4] == "room/" &&
      member(object_name(a), '#') < 0)
    efun::set_environment(a, 0);
}

nomask void set_this_player(mixed a) {}

#ifdef NOWRITE
/*
 * These are the efuns that write to the filesystem. They are overridden by
 * these simul_efuns in a NOWRITE-mud to prevent a lot of nasty errors.
 * It is not necessary to declare them 'nomask' because writing to the file
 * system is already impossible since valid_write() in the master will
 * always return false.
 */
void save_object(string file) {}
int write_file(string file, string str) { return 0; }
int write_bytes(string file, int start, string str) { return 0; }
int mkdir(string path) { return 0; }
int rm(string file) { return 0; }
int rename(string a, string b) { return 1; }  // an exception
int rmdir(string path) { return 0; }
#endif

#ifdef IMP_DISABLED
nomask status send_imp(string host, int port, string message) {
  debug_message("send_imp() is disabled due to switch IMP_DISABLED.\n");
  return 1;
}

nomask status send_udp(string host, int port, string message) {
  debug_message("send_udp() is disabled due to switch IMP_DISABLED.\n");
  return 1;
}
#endif

varargs void input_to(mixed fun, int onoff, varargs mixed *args) {
  mixed *arr;
  int i;
  object ob;

  if (!this_player() || !previous_object())
    return;

  arr = ({ fun, onoff }) + args;
  for (i=sizeof(arr) - 1; i>1; i--) {
    if (pointerp(arr[i]))
      arr[i] = quote(arr[i]);
  }

#if 0
  ob = query_input_pending(this_player());
#endif

  if (!(arr[1] & INPUT_CHARMODE) &&
      this_player()->query_send_telnet_eor()) {
    // send an IAC EOR after the prompt?
    // prompt via efun? then build a closure
    if (arr[1] & INPUT_PROMPT) {
      if (sizeof(arr) < 3)
        raise_error("Missing prompt argument to input_to().\n");
      if (stringp(arr[2])) {
        arr[2] = bind_lambda(unbound_lambda(0,
          ({ #',, ({ #'efun::binary_message, arr[2], 1 }),
                  ({ #'efun::binary_message,
                          ({ CL_ARRAY, IAC, EOR }), 3 }) })),
          this_player());
      } else if (closurep(arr[2])) {
        arr[2] = bind_lambda(unbound_lambda(0,
         ({ #',, ({ arr[2] }),
                 ({ #'efun::binary_message,
                         ({ CL_ARRAY, IAC, EOR }), 3 }) })),
         this_player());
      }
      else
        raise_error("Bad argument 3 to input_to()\n");
    }
    // otherwise: send an EOR (the text before is the prompt itself)
    else
      funcall(bind_lambda(#'efun::binary_message, this_player()),
                          ({ IAC, EOR }), 3);
  }
  funcall(bind_lambda(unbound_lambda(0,
          ({ #'efun::input_to }) + arr), previous_object()));
}

