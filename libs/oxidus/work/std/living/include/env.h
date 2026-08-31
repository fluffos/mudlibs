#ifndef __ENV_H__
#define __ENV_H__

protected void init_env();
public int set_env(string var_name, string var_value);
public varargs mixed query_env(string var_name, mixed def);
public mapping list_env();
public int set_pref(string pref_name, string pref_value);
public varargs string query_pref(string pref_name, string def);
public mapping list_pref();

#endif // __ENV_H__
