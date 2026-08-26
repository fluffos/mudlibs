/*
 * environment variables
 */

#include <uid.h>
private mapping env_var;

mixed query_env (string env);

int env_exists(string var) {
    if (!env_var) env_var = ([ ]);
    return (1 - undefinedp(env_var[var]));
}

/*
 * add_property adds a property to a list or modifies an existing prop
 * If the property is changed 1 is returned... Otherwise 0 is returned.
 * the function property_change() is called in the object for each call to
 * add_property. It is passed the property change. And the old value it had
 * if it is recently added it will be passed "ADDED" as the old value
 */

int setenv (string env, mixed value)
{
    int r;
    string s ;
   if( this_player() )
        s = getuid(this_player()) ;
    if (s!=getuid(this_object())) return 0 ;
    r = env_exists(env);
    if (!value) value = "";
    env_var[env] = value;
    return r;
}

int set_env (string env, mixed value) {
    string s ;

   if( this_player() )
       s = getuid(this_player()) ;
    if (s!=getuid(this_object())) return 0 ;
  return setenv(env, value);
}

mixed getenv(string env)
{
  if (!env_exists(env)) return 0;
  return env_var[env];
}

mixed query_env(string env) {
  return getenv(env);
}

int remove_env (string env)
{
    if (!env_exists(env)) return 0;
    map_delete(env_var, env);
    return 1;
}

string * regexp_query_env (string pattern)
{
   string *vars, *env;

   vars = keys(env_var);
   vars -= ({ 0 }); /* may as well skip all the "deleted" ones for now */
   env = regexp (vars, pattern);
   if (!env) 
     env = ({});
   return env;
}
