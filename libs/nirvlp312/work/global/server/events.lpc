#include <event.h>
#include <rtlimits.h>

#define MEMORY "etc/shared"
#define DEFAULT_HANDLERS "/save/event_handlers"

inherit "basic/create";
inherit "basic/copy";


private mapping events;
private mapping default_handler;
private mapping global_listeners;
mixed *event_queue;
private int event_queue_index;
private mixed cancelled;
private closure assign; // this is to save time 

void read_default_handlers() {
  object ob;
  mixed data;
  string type,handler,error;
  int i;

  data = read_file(DEFAULT_HANDLERS);
  if (data)
    data = regexp(explode(data,"\n"),"^[^#]")-({""});
  default_handler = ([]);
  for (i=sizeof(data); i--; ) {
    if (sscanf(data[i],"%s /%s",type,handler)==2) {
      if (member(m_values(default_handler),"/"+handler) < 0)
        if (ob=find_object(handler))
          destruct(ob);
      if (error=catch(load_object(handler)))
        log_file("EVENTS",ctime(time())+error+": "+handler+"\n");
      else
        default_handler += ([ type : make_shared_string("/"+handler) ]);
    }
  }
  MEMORY->set_global("events_dflt", default_handler);
}

void create() {
  if (events)
    return;
  if (!(events = MEMORY->query_global("events")))
    MEMORY->set_global("events", events = ([ ]));
  if (!(global_listeners = MEMORY->query_global("events_global")))
    MEMORY->set_global("events_global", global_listeners = ([]));
  default_handler = MEMORY->query_global("events_dflt");
  if (!default_handler || get_type_info(default_handler,1) != 1)
    read_default_handlers();
  assign = lambda(({'x,'y}),({#'=,'x,'y}));
}

void delete_destructed_keys(string type, mapping map) {
#if 0  // Coogan, 02-Mar-2003
  // copy the mapping to remove destructed objects
  map = ([]) + map;
#else  // this does the same, but is less expensive
  sizeof(map);
#endif
}

// Ugh Jan-6-98
void refresh() {
  string event_type_key;
  event_queue = 0;
#if 0  // Coogan, 03-Mar-03
  walk_mapping(events,#'delete_destructed_keys);
#else
  foreach (event_type_key : events)
    sizeof(events[event_type_key]);
#endif
}

varargs void set_default_handler(string type, string handler) {
  int pos;

  if (!stringp(type) || (handler && !stringp(handler)))
    return;
  if (handler)
    load_object(handler);
  pos = member(type, ':');
  if (pos<0) {
    if (!check_previous_privilege(1))
      return;
  }
  else {
    // Ugh Jun-14-1995 the ':' is taken into account in the check
    // so that objects can call this function as well
    if (!check_previous_privilege(type[0..pos]))
      return;
  }

  if (handler)
    default_handler += ([type : handler]);
  else
    m_delete(default_handler,type);
  MEMORY->set_global("events_dflt",default_handler);
}

mapping query_default_handlers() {
  return copy(default_handler);
}

void listen(string type,int prio,mixed callback) {
  mapping list;
  int *prios;
  closure *callbacks;
  mixed *temp;

  if (!stringp(type) || !intp(prio) || !closurep(callback))
    return;
  if (!m_contains(&list,events,type)) {
    events[type] = ([ previous_object() : ({ prio }); ({ callback }) ]);
    MEMORY->set_global("events",events);
    return;
  }
  if (!m_contains(&prios,&callbacks,list,previous_object())) {
    list += ([ previous_object() : ({ prio }); ({ callback }) ]);
    MEMORY->set_global("events",events);
    return;
  }
  temp = order_alist(prios + ({ prio }),callbacks + ({ callback }) );
  list += ([ previous_object() : temp[0]; temp[1] ]);
  MEMORY->set_global("events",events);
}

void set_global_listening(string type,status listening) {
  if (listening && member(type, ':')<0)
    if (!check_previous_privilege(1))
      log_file("events_global_listening",
               ctime()+" "+type+" "+listening+" "+
               object_name(previous_object())+"\n");
  if (listening)
    if (global_listeners[type] && 
        member(global_listeners[type],previous_object()) >= 0)
      return;
    else
      global_listeners[type] =
        (global_listeners[type]||({}))-({0}) + ({previous_object()});
  else
    if (global_listeners[type])
      global_listeners[type] -= ({previous_object(),0});
    else
      return;
  MEMORY->set_global("events_global",global_listeners);
}

mixed query_global_listeners(string type) {
  return global_listeners && global_listeners[type] &&
          global_listeners[type][0..];
}

void unlisten(string type,int prio,mixed callback) {
  mapping list;
  int *prios;
  closure *callbacks;
  int pos;

  if (!(list = events[type]))
    return;
  if (!m_contains(&prios,&callbacks,list,previous_object()))
    return;
  if ((pos = member(prios,prio)) < 0)
    return;
  while (pos < sizeof(prios) && prios[pos]==prio)
#if 0  // only until comparison of lfun-closures works  Alfe 95-Jun-26
    if (callbacks[pos]==callback)
#else
    if (sprintf("%O",callbacks[pos])==sprintf("%O",callback))
#endif
    {
      prios[pos..pos]=({ });
      callbacks[pos..pos]=({ });
      if (!sizeof(prios))
        m_delete(list,previous_object());
      else
        list += ([ previous_object() : prios; callbacks ]);
      MEMORY->set_global("events",events);
      return;
    }
    else
      pos++;
}

void cancel(mixed cancel_info) {  // cancel_info added by Ugh Feb-10-98
  cancelled = cancel_info || 1;
}

nomask varargs mixed query_events(string t) {  // Alfe 95/3/10
  if (!check_previous_privilege(1))
    raise_error("Illegal call of query_events()\n");
  if (t)
    return events && events[t];
  else
    return limited(#'copy, ({ LIMIT_UNLIMITED }), events);
}

private mixed *trace_buffer;
private mixed trace_mode;

public void set_trace(mixed tm) {
  trace_mode = tm;
  trace_buffer = ({});
}

public varargs mixed *query_trace(status mode) {
  return mode? trace_mode : trace_buffer;
}

private void add_trace(mixed mode,mixed *buffer,
                       closure call,mapping data,string type,int prio) {
  if (closurep(mode))
    funcall(mode,call,data,type,prio);
  else if (intp(mode))
    switch (mode) {
    case 1:  // use copy() to copy the data
      buffer += ({ ({ call,copy(data),type,prio }) });
      break;
    case 2:  // use copy() to copy the data
      buffer += ({ ({ call,copy(data),type,prio }) });
      break;
    }
}

#if 0  // Alfe 2002-Sep-6
#  define REPEAT(what, times) map(allocate(times), assign, what)
#else
#  define REPEAT(what, times) allocate(times, what)
#endif

varargs mixed *send(string ev_type,mapping ev_data,object *ev_dest,
                    mixed local_trace_mode) {
  mixed *ev_prios;
  closure *ev_calls;
  mapping ev_filter;
  object *ev_obs;
  int i,j,n;
  mixed old_cancelled; // changed from 'c' by Ugh Feb-10-98
  status delay;
  mixed *prios;
  mixed *callbacks;
  mixed *local_trace_buffer;
  if (local_trace_mode)
    local_trace_mode = ({});
  if (pointerp(ev_dest)) // Ugh Mar-27-1996
    ev_dest = m_indices(mkmapping(ev_dest));
  // this should make the default-handler a global listener
  if (member(default_handler,ev_type))
    load_object(default_handler[ev_type]);
  // Is there anything we should do?
  if (!(ev_filter = events[ev_type]))
    return local_trace_buffer;
  i = caller_stack_depth();
  while (i-- && !delay)
    if (previous_object(i)==this_object())
      delay = 1;
  // Ugh Jun-20-1995 -- if no destinations are given, 
  // all listeners get the event
  if (!ev_dest)
    ev_obs = m_indices(ev_filter);
  else {
    ev_obs = global_listeners[ev_type] || ({ });
    for (i=sizeof(ev_dest); i--; )
      if (objectp(ev_dest[i])) {
        if (ev_filter[ev_dest[i]])
          ev_obs += ({ ev_dest[i] });
        ev_obs += filter(deep_inventory(ev_dest[i]), ev_filter);
      }
  }
  prios = allocate(sizeof(ev_obs));
  callbacks = allocate(sizeof(ev_obs));
  for (i=sizeof(ev_obs); i--; ) {
    m_contains(&(prios[i]),&(callbacks[i]),ev_filter,ev_obs[i]);
    n += sizeof(prios[i]);
  }
  ev_prios = allocate(n);
  ev_calls = allocate(n);
  for (i=j=0; i<sizeof(prios); i++) {
    n = sizeof(prios[i]);
    ev_prios[j..j+n-1] = prios[i];
    ev_calls[j..j+n-1] = callbacks[i];
    j += n;
  }
  ev_prios = order_alist(ev_prios,ev_calls);
  ev_calls = ev_prios[1];
  ev_prios = ev_prios[0];
  i = sizeof(ev_calls);
  old_cancelled = cancelled;
  cancelled = 0;
  if (!delay) {
    event_queue =  ({ ({}),({}),({}) });
    event_queue_index = 0;
  }
  while (i--) {
    // only call positive priorities
    if (ev_prios[i] < 0)
      break;
    if (local_trace_mode)
      add_trace(local_trace_mode,&local_trace_buffer,ev_calls[i],ev_data,
                ev_type,ev_prios[i]);
    if (trace_mode)
      add_trace(trace_mode,&trace_buffer,ev_calls[i],ev_data,
                ev_type,ev_prios[i]);
    if (to_object(ev_calls[i])) {
#if 0  // Alfe 2002-Sep-6
      funcall(ev_calls[i], ev_data, ev_type, ev_prios[i]);
#else
      with_player(ev_data[E_AGENT], #'funcall,
                  ({ ev_calls[i], ev_data, ev_type, ev_prios[i] }));
#endif
    }
    if (cancelled) {
      ev_data[E_CANCELLED] = cancelled; // Ugh Feb-10-98
      break;
    }
  }
  cancelled = old_cancelled;
  // negative priorities are enqueued, or rather, accumulated
  // if not all priorities were called and the next one is negative
  if (i >= 0 && ev_prios[i] < 0) {
    prios = ev_prios[0..i];
    callbacks = ev_calls[0..i];
    if (event_queue_index < sizeof(event_queue[0])) {
      // the reaction is already in progress, therefor, add the time
      // that has already passed to this later reaction
      n = event_queue[0][event_queue_index];
      ev_prios = map(prios,#'+,n);
      event_queue = 
        order_alist(event_queue[0]+ev_prios,
                    event_queue[1]+transpose_array(({prios,callbacks})),
                    event_queue[2]+REPEAT(({copy(ev_data),ev_type}),
                                          sizeof(prios)));
      event_queue_index = sizeof(event_queue[0]);  // Alfe 96-Mar-23
    }
    else {  // the initial event is still in the positive priorities
      event_queue = 
        order_alist(event_queue[0]+prios,
                    event_queue[1]+transpose_array(({prios,callbacks})),
                    event_queue[2]+REPEAT(({copy(ev_data),ev_type}),
                                          sizeof(prios)));
      event_queue_index = sizeof(event_queue[0]);
    }
  }
  // this loop is only called if we're the initial event
  if (!delay && event_queue_index) {
    mixed *data, call;
    prios = event_queue[0];
    callbacks = event_queue[1];
    data = event_queue[2];
    while (event_queue_index--) {
      call = callbacks[event_queue_index];
      if (!(call && to_object(call[1])))
        continue;
      ev_data = data[event_queue_index][0];
      ev_type = data[event_queue_index][1];
      // don't call it twice
      callbacks[event_queue_index] = data[event_queue_index] = 0;
      if (local_trace_mode)
        add_trace(local_trace_mode,&local_trace_buffer,call[1],ev_data,
                  ev_type,call[0]);
      if (trace_mode)
        add_trace(trace_mode,&trace_buffer,call[1],ev_data,ev_type,call[0]);
      if (to_object(call[1])) {  // check for destructed objects
#if 0  // Alfe 2002-Sep-6
        funcall(call[1], ev_data, ev_type, call[0]);
#else
        with_player(ev_data[E_AGENT], #'funcall,
                    ({ call[1], ev_data, ev_type, call[0] }));
#endif
      }
      // This has to be done in case the call sent a new event
      prios = event_queue[0];
      callbacks = event_queue[1];
      data = event_queue[2];
    }
  }
  return local_trace_buffer;
}

mixed *trace(string ev_type, object *ev_dest) {
  mixed *ev_prios;
  closure *ev_calls;
  mapping ev_filter;
  object *ev_obs;
  int i,j,n;
  mixed *prios;
  mixed *callbacks;

  // this should make the default-handler a global listener
  if (member(default_handler,ev_type))
    load_object(default_handler[ev_type]);
  // Is there anything we should do?
  if (!(ev_filter = events[ev_type]))
    return ({});
  // Ugh Jun-20-1995 -- if no destinations are given, 
  // all listeners get the event
  if (!ev_dest)
    ev_obs = m_indices(ev_filter);
  else {
    ev_obs = global_listeners[ev_type] || ({ });
    for (i=sizeof(ev_dest); i--; )
      if (objectp(ev_dest[i])) {
        if (ev_filter[ev_dest[i]])
          ev_obs += ({ ev_dest[i] });
        ev_obs += filter(deep_inventory(ev_dest[i]), ev_filter);
      }
  }
  prios = allocate(sizeof(ev_obs));
  callbacks = allocate(sizeof(ev_obs));
  for (i=sizeof(ev_obs); i--; ) {
    m_contains(&(prios[i]),&(callbacks[i]),ev_filter,ev_obs[i]);
    n += sizeof(prios[i]);
  }
  ev_prios = allocate(n);
  ev_calls = allocate(n);
  for (i=j=0; i<sizeof(prios); i++) {
    n = sizeof(prios[i]);
    ev_prios[j..j+n-1] = prios[i];
    ev_calls[j..j+n-1] = callbacks[i];
    j += n;
  }
  return turn_array(transpose_array(order_alist(ev_prios,ev_calls)));
}

