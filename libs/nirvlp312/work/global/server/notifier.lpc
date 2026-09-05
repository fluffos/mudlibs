#pragma strong_types

#include <kernel.h>

inherit ACCESS;
inherit "basic/create";

private mapping notifies;

void create() {
  notifies = allocate_shared_mem("notify_reset", ([ ]));
}

private string normalize_program_name(mixed ob) {
#if 1  // Coogan, 07-May-2002
  return load_name(ob);
#else
  if (objectp(ob))
    return load_name(ob);
  else 
    return implode(explode(ob,"/")-({""}),"/");
#endif
}

private void call_notify(object which, string what, string where, int arg) {
  string error;
  if (!which) 
    return;
  if (error = catch(call_other(which, what, where, arg)))
    log_file("NOTIFIES", ctime(time())+" Notify failed in "+
             object_name(which)+"->"+what+"("+where+","+arg+") with error: "+
             error);
}

public void notify_reset(mixed ob, int arg) {
  mixed *n;
  ob = normalize_program_name(ob);
  if (!(n = notifies[ob]))
    return;
  walk_mapping(n, #'call_notify, ob, arg);
}

// changed function type from string to void, Coogan, 24-Mar-2011
public varargs void add_notify(mixed where, string what) {
  object which;
  if (!what)
    what = "notify_reset";
  else if (!stringp(what))
    raise_error("third argument is no function name");
  which = previous_object();
  where = normalize_program_name(where);
  if (!notifies)
    notifies = ([ ]);
  if (!notifies[where])
    notifies[where]  = ([ which : what ]);
  else
    notifies[where] += ([ which : what ]);
  if (find_object(where))
    notify_reset(where, 1);
}

public varargs string remove_notify(mixed where, mixed which) {
  int i;
  object w;

  if (!which)
    which = previous_object();
  else if (!objectp(which)) {
    if (!(w = find_object(which)))
      return "object " + which + " not found";
    which = w;
  }
  where = normalize_program_name(where);
  if (!member(notifies, where) || !member(notifies[where], which))
    return "no such notify added for " + where;
#if 0  // Coogan && Alfe, 07-May-2002
  if (!(check_previous_privilege(SECURITY->query_protection(which, 1)) || 
        check_previous_privilege(SECURITY->query_protection(where, 1)))) {
    raise_error("not privileged to do that");
    return 0;
  }
#endif
  m_delete(notifies[where], which);
  return 0;  // Coogan, 24-Mar-2011
}

public mapping query_notifies(mixed where) {
  mixed result;
  result = notifies && notifies[normalize_program_name(where)];
  if (result) 
    return copy(result);
}

