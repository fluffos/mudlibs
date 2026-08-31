/******************************************************************************/
mixed *consolidate_search(object srch, string plurl, int x);
string plurl_present(string str, object ob);
/******************************************************************************/
mixed *consolidate_search(object srch, string plurl, int x)
{
 object *all, 
        *ob=({}), 
         tm;
 int     i;
 string  non_plurl;
 if (!x || !srch || !plurl || plurl=="") return ({});
 if (!(all = all_inventory( srch ))) return ({});
 if (!(non_plurl = plurl_present(plurl, srch))) return ({});
 while((tm = present(non_plurl+" "+(++i) , environment(this_player())))&&i<x+1)
   ob += ({ tm });
 return ob;
}

string plurl_present(string str, object ob)
{
 int i, a;
 object *obs;
 string *ids;
 if (!(i = sizeof( obs = all_inventory( ob ) ))) return 0;
 while(i--)
  {
   if (!(a = sizeof(ids = obs[i]->query_id()))) continue;
   while(a--)
    {
     if (pluralize(ids[a]) == str) return ids[a];
    }
  }
 return 0;
}
