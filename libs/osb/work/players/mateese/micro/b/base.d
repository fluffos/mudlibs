#ifndef BASE_D
#define BASE_D 1

public nomask varargs int QueryMode (string name);
public nomask varargs int SetMode (string name, int new);
static nomask mixed set (string name, mixed value);
public nomask mixed query (string name);
public nomask mixed SetProps (mapping new);
public nomask mapping QueryProps ();
public mapping getProps ();
public void putProps (mapping p);
public mixed QueryAutodata ();
public mixed SetAutodata (mixed p);
public void save (string file);
public int restore (string file);
public int remove();
public int clean_up (int ref);
public varargs string replace_pgm (string *except);
public varargs mixed Set ( string name
                         , mixed arg1, mixed arg2, mixed arg3, mixed arg4
                         , mixed arg5, mixed arg6, mixed arg7, mixed arg8
                         );
public varargs mixed SetHook ( string name
                             , mixed arg1, mixed arg2, mixed arg3, mixed arg4
                             , mixed arg5, mixed arg6, mixed arg7, mixed arg8
                             );
public varargs mixed Query ( string name
                           , mixed arg1, mixed arg2, mixed arg3, mixed arg4
                           , mixed arg5, mixed arg6, mixed arg7, mixed arg8
                           );
public varargs mixed Get ( string name
                         , mixed arg1, mixed arg2, mixed arg3, mixed arg4
                         , mixed arg5, mixed arg6, mixed arg7, mixed arg8
                         );
public void create ();

#endif

