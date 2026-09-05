varargs void dump_array(mixed a, string tab, int dw);
varargs void debug(string player_name, mixed m, string s);
mixed get_variable(string variable_name, object o);
status set_variable(string variable_name, mixed value, object o);
mixed call_function(string function_name, object o, varargs mixed args);
void save_other_object(object o, string file);
int restore_other_object(object o, string file);

string *query_call_trace();
void reset_call_trace();
void add_call_trace_enter(object caller, mixed called, string func,
                          mixed *args);
void add_call_trace_leave(mixed *args);
void set_call_other_trace(status enable);
mixed call_other(mixed called, string func, varargs mixed *args);
mixed call_other_2ref(mixed called, string func, mixed ref1, mixed ref2,
                      varargs mixed *args);

