#include <event.h>

#include <server.h>
#define EVENTSERVER SE_EVENTS

varargs void listen_event(string type,int prio,mixed callback)
{
  if (!previous_object())
    return;
  if (!callback)
    callback="receive_event";
  if (stringp(callback))
    callback=funcall(bind_lambda(#'symbol_function,previous_object()),
                     callback,previous_object());
  if (!closurep(callback))
    return;
  funcall(bind_lambda(#'call_other,previous_object()),
    EVENTSERVER, "listen", type, prio, callback);
}

varargs void set_global_listening_event(string type,status listening)
{
  funcall(bind_lambda(#'call_other,previous_object()),
    EVENTSERVER, "set_global_listening", type, listening);
}

varargs void unlisten_event(string type,int prio,mixed callback)
{
// copied the handling of `callback' from above
  if (!previous_object())
    return;
  if (!callback)
    callback="receive_event";
  if (stringp(callback))
    callback=funcall(bind_lambda(#'symbol_function,previous_object()),
                     callback,previous_object());
  if (!closurep(callback))
    return;
  funcall(bind_lambda(#'call_other,previous_object()),
    EVENTSERVER, "unlisten", type, prio, callback);
}

varargs mixed *send_event(string type, mapping data, mixed dest, mixed trace) {
  if (objectp(dest))
    dest = ({ dest });
  if (!member(data,E_SENDER))
    data[E_SENDER] = previous_object();
  if (!member(data,E_RECEIVERS))
    data[E_RECEIVERS] = dest;
  if (!member(data,E_COMMAND) && this_player())
    data[E_COMMAND] = this_player()->query_commandline();
  data[E_HANDLED]    = 0;
  data[E_CANCELLED]  = 0;
  data[E_MODIFIERS]  = ([]);
  data[E_PREVENTERS] = ([]);
  data[E_HANDLERS]   = ([]);
  data[E_REACTORS]   = ([]);
  return funcall(bind_lambda(#'call_other,previous_object()),
                 EVENTSERVER, "send", type, data, dest, trace);
}

varargs mixed *trace_event(string type,mixed dest)
{
  return
    EVENTSERVER->trace(type,objectp(dest) ? ({ dest }) : dest);
}

varargs mapping send_query_event(string type,mapping data,mixed dest)
{
  return
    EVENTSERVER->send_query(type,data,objectp(dest) ? ({ dest }) : dest);
}

varargs void cancel_event(mixed info)
{
  EVENTSERVER->cancel(info);
}

