/* object.c

 Tacitus @ LPUniversity
 04-APR-05
 Base Object

*/

/* Last updated July 14th, 2006 by Tacitus */

#include <config.h>

inherit OB_E;

private string *ids, name, short, long;

void remove();
int move(mixed dest);
int moveAllowed(mixed dest);
void set_id(mixed str);
void set_ids(string *arg);
int id(string arg);
int set_name(string str);
string query_name();
string query_cap_name();
int set_short(string str);
int set_long(string str);
string query_short();
string query_long();
int receive_object(object ob);
int release_object(object ob);

void remove()
{
     load_object(VOID_OB);

     foreach(object ob in all_inventory())
     {
          if(interactive(ob))
          {
              tell_object(ob, "You watch as the environment around you disappears.\n");
              ob->move(VOID_OB);
          }
     }

     efun::destruct(this_object());
}

int move(mixed dest)
{
     object ob;
     if(stringp(dest)) ob = load_object(dest);
     if(objectp(dest)) ob = (object)dest;
     if(!objectp(ob)) return 0;
     if(!ob->receive_object(this_object())) return 0;
     if(environment(this_object())) if(!environment(this_object())->release_object(this_object())) return 0;
     move_object(dest);
     return 1;
}

int moveAllowed(mixed dest)
{
     object ob;
     if(stringp(dest)) ob = load_object(dest);
     if(objectp(dest)) ob = (object)dest;
     if(!objectp(ob)) return 0;
     if(!ob->receive_object(this_object())) return 0;
     if(environment(this_object())) if(!environment(this_object())->release_object(this_object())) return 0;
     return 1;
}

void set_id(mixed str)
{
     if(arrayp(str)) set_ids(str);
     else set_ids(({str}));
}

void set_ids(string *arg)
{
     if(stringp(arg)) arg = ({arg});
     ids = arg;
     set("ids", arg);
     if(member_array(query_name(), ids) == -1 && query_name())
     {
          ids += ({query_name()});
          set("ids", query_name());
     }
}

int id(string arg)
{
     if (!arg || !stringp(arg)) {
          return 0;
     }
     if(sizeof(ids) < 1) ids = ({query_name()});
     if(member_array(arg, ids) != -1) return 1;
     if(sizeof(query("ids")) > 0)
     {
          if(member_array(arg, query("ids")) != -1) return 1;
     }
     return 0;
}

int set_name(string str)
{
    if(interactive(this_object()) && !isMember(query_privs(previous_object()), "admin")
        && previous_object() != this_object()) return 0;
     else
     {
          name = str;
          set("name", str);
          return 1;
     }

}

string query_name()
{
     if(!name) return query("name");
     return name;
}

string query_cap_name()
{
    if(!name && !stringp(query("name"))) return "";
    else if(!name) return capitalize(query("name"));
    else return capitalize(name);
}

int set_short(string str)
{
     short = str;
     set("short", str);
}

string query_short()
{
     if(!short)
     {
          if(!query("short")) return name;
          return query("short");
     }
     return short;
}

int set_long(string str)
{
     long = str;
     set("long", str);
}

string query_long()
{
     if(!long) return query("long");
     return long;
}

int receive_object(object ob)
{
     return 1;
}

int release_object(object ob)
{
    return 1;
}