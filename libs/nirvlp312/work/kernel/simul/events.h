varargs void listen_event(string type, int prio, mixed callback);
varargs void set_global_listening_event(string type, status listening);
varargs void unlisten_event(string type, int prio, mixed callback);
varargs mixed *send_event(string type, mapping data, mixed dest, mixed trace);
varargs mixed *trace_event(string type, mixed dest);
varargs mapping send_query_event(string type, mapping data, mixed dest);
varargs void cancel_event(mixed info);

