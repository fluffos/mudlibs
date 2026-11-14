// SilberLand MUDlib
//
// /p/daemon/objectd.c -- object daemon
//
// $Date: 1997/03/16 02:32:44 $
/* $Revision: 1.3 $
 * $Log: objectd.c,v $
 * Revision 1.3  1997/03/16 02:32:44  Woody
 * prepared for revision control
 *
 * Revision 1.2  1995/04/03  14:47:02  Wargon
 * QueryObject() verwendet bei BluePrints jetzt auch AddItem.
 *
 * Revision 1.1  1995/03/31  13:30:33  Hate
 * Initial revision
 *
 */

#pragma strong_types

#include <rooms.h>
#include <properties.h>
#include <defines.h>
#include <daemon.h>

mapping objects = ([]);

#define CLASS   0
#define DATA    1

void create()
{
  if(IS_CLONE(ME)) destruct(ME);
  seteuid(getuid(ME));
  objects = ([]);
  restore_object(OBJECTD_SAVE);
}

mixed AddObject(object obj, string env)
{
  if(!obj || !env || !objectp(obj) || !stringp(env)) return 0;

  // save information
  if(!member(objects, env))
    objects[env] = ({ ({  object_name(obj), obj->QueryProp(P_AUTOLOAD) }) });
  else
    objects[env] += ({ ({ object_name(obj), obj->QueryProp(P_AUTOLOAD) }) });
  save_object(OBJECTD_SAVE);
  return env;
}

mixed RemoveObject(object obj, string env)
{
  if(!obj || !env || !objectp(obj) || !stringp(env)) return 0;

  // save information
  if(member(objects, env))
  { int i;
    i = sizeof(objects[env]);
                while(i && (objects[env][i-1][CLASS] != object_name(obj))) i--;
    if(i > 0) objects[env][i-1..i-1] = ({});
  }
  if(!sizeof(objects[env])) objects = m_delete(objects, env);
  save_object(OBJECTD_SAVE);
  return 1;
}

varargs void QueryObject(mixed env)
{
  mixed obj, oenv; int i;

  // take the caller as the questioning object
  if(!env || !stringp(env)) env = previous_object();
  else env = find_object(env);

  // target must be a blueprint
  if(IS_CLONE(env)) return 0;

  if(i = pointerp(obj = objects[env = object_name(oenv = env)])?sizeof(obj):0)
  {
    while(i--)
    {
       object o;
       string *n;

       n = explode(objects[env][i][CLASS], "#");
       if (sizeof(n) > 1)
         o = oenv->AddItem(n[0], REFRESH_DESTRUCT);
       else 
         o = oenv->AddItem(n[0], REFRESH_DESTRUCT, 1);
       o->SetProp(P_AUTOLOAD, objects[env][i][DATA]);
       objects[env][i][CLASS] = object_name(o);
    }
    save_object(OBJECTD_SAVE);
  }
}

mixed QueryObjects(mixed env)
{
  mixed obj;

  // take the caller as the questioning object
  if(!env || !stringp(env)) env = previous_object();
  else env = find_object(env);

  // target must be a blueprint
  if(IS_CLONE(env)) return 0;

  if(obj = objects[object_name(env)])
    obj = map(obj, #'[, 0);
  return obj;
}

int clean_up(int arg)
{
  if(arg>1) return 1;
  save_object(OBJECTD_SAVE);
  destruct(ME);
  return 0;
}
