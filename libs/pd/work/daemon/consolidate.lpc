/* Consolidate daemon commands can use to consolidate their input. Such as:
   get 2 oils  / drop 4 stones / get 3 knives from bag
  -- seeker 10/10/2001
 object *do_consolidate_cmd(string plurl, int cnt)
*/
#include <daemons.h>

inherit DAEMON;

string *plurl2itself = ({ "oil" });

string aplurl(string str) { return pluralize(str); }
string plurl_to_nonplurl_present(string plurl, object *env) {
int a, i;
string *ids;
   for(i=0; i<sizeof(env); i++)
    {
     ids = env[i]->query_id();
       for(a=0; a<sizeof(ids); a++)
          {
            if (pluralize(ids[a])==plurl)
              return ids[a];
            if (member_array(ids[a], plurl2itself)!=-1)
              if (ids[a] == plurl)
                 return ids[a];
          }
    }
 return "";
}
object *do_consolidate_cmd(object env, string plurl, int cnt)
{
 string name;
 int i;
 object *ob_ret, *all_inv;
if (!plurl || !cnt || !env ) return ({});
 env = environment(this_player());
 all_inv = all_inventory(env);
 name = plurl_to_nonplurl_present(plurl, all_inv);
/* 
*   processes when people do ex: get 1 oil.. makes sure its not plurl
*   so you cant do get 1 oils.. 
*/
 if ( cnt == 1 )
   {
    if (name == "" || member_array(plurl, plurl2itself)!=-1)
      if (present( plurl, env ))
        return ({ present( plurl, env ) });
      return ({});
   }
/*
*   now to process all other requests
*/
 if (name=="") return ({});
 i = 0;
 ob_ret = ({});
  while( present(name+" "+(++i), env) ) 
 {
   ob_ret += ({ present(name+" "+i, env) });
   if (i>=cnt) break;
 }
 
 return ob_ret;
}

int instance(string *ar, string str) {
 int a, b=0;
 if (ar==({}) || !ar || str == "" || !str) return 0;
 if (!(a = sizeof(ar))) return 0;
 while(a--)
   if (ar[a] == str) b++;
 return b;
 
}
