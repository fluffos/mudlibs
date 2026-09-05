/*
 * /basic/event_listener.c
 *
 * Implementing standard event listener behavious for all of the four
 * phases of event-listening:
 *   - modification
 *   - prevention (cancelling)
 *   - handling 
 *   - noticing (reaction)
 */

#include <event.h>

status modify_event(mapping m,string t,int p) {
  string name;

  name = object_name()+"##"+__FILE__+"##"+p;
  if (member(m[E_MODIFIERS],name))
    return m[E_MODIFIERS][name];
  else
    m[E_MODIFIERS][name] = 0;
  return
    m[E_MODIFIERS][name] =
      call_other(this_object(),"modify_"+t+"_event",m,t,p);
}

status prevent_event(mapping m,string t,int p) {
  string name;

  name = object_name()+"##"+__FILE__+"##"+p;
  if (!member(m[E_PREVENTERS],name)) {
    m[E_PREVENTERS][name] = 0;
    m[E_PREVENTERS][name] = 
      call_other(this_object(),"prevent_"+t+"_event",m,t,p);
  }
  return m[E_PREVENTERS][name];
}

status handle_event(mapping m,string t,int p) {
  string name;

  if (m[E_HANDLED]) // already handled
    return m[E_HANDLED];

  name = object_name()+"##"+__FILE__+"##"+p;
  if (!member(m[E_HANDLERS],name)) {
    m[E_HANDLERS][name] = 0;
    m[E_HANDLERS][name] =
      call_other(this_object(),"handle_"+t+"_event",m,t,p);
  }
  return m[E_HANDLERS][name];
}

status notice_event(mapping m,string t,int p) {
  string name;

  name = object_name()+"##"+__FILE__+"##"+p;
  if (!member(m[E_REACTORS],name)) {
    m[E_REACTORS][name] = 0;
    m[E_REACTORS][name] =
      call_other(this_object(),"notice_"+t+"_event",m,t,p);
  }
  return m[E_REACTORS][name];
}

public status catch_event(mapping m,string t,int p) {
  mixed h;

  if (p >= EPRIO_MODIFY)
    return modify_event(m,t,p);
  if (p >= EPRIO_CANCEL) {
    if (h = prevent_event(m,t,p))
      return cancel_event(h), h;
  }
  else if (p >= EPRIO_HANDLE) {
    if (h = handle_event(m,t,p)) {
      m[E_HANDLED] = h;
      if (widthof(m) > 1)
        m[E_HANDLER] = this_object();
      return h;
    }
  } else {
    return notice_event(m,t,p);
  }
  return 0;
}


