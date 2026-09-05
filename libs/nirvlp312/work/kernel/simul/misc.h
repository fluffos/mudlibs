#ifndef _kernel_simul_misc_h
#define _kernel_simul_misc_h

string version();
string query_host_name();
#ifdef __START_TIME__
string query_start_time();
#endif
mixed *order_objects(mixed *items);
nomask void remove_interactive(object o);
nomask varargs mixed set_prompt(string str, object obj);
nomask varargs mixed *call_out_info(int mode);
nomask void set_this_player();
#ifdef NOWRITE
void save_object(string file);
int write_files(string file,string str);
int write_bytes(string file,int start,string str);
int mkdir(string path);
int rm(string file);
int rename(string a,stringb);
int rmdir(string path);
#endif
#ifdef IMP_DISABLED
nomask status send_imp(string host,int port,string message);
nomask status send_udp(string host,int port,string message);
#endif
varargs void input_to(mixed fun, int onoff, varargs mixed *args);

#endif

