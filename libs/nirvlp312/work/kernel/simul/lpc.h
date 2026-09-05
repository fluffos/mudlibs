nosave mapping alloc_wl_entry(string name);
varargs void set_timed_flag(string flag,int delay,int mode);
int test_timed_flag(string flag);
int clear_timed_flag(string flag);
varargs mixed sort_args(closure original,int *order);
mixed simul_efun_call(string fun,varargs vargs);
mixed apply_function(mixed func, varargs mixed extra);
void check_arguments(mixed args,closure *tests,string func);
#if !__EFUN_DEFINED__(extract)
string extract(varargs mixed* args);
#endif
#if !__EFUN_DEFINED__(member_array)
int member_array(mixed item, mixed arr);
#endif

