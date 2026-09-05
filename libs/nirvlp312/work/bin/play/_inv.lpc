#include <ansi.h>

varargs mixed * process_list(object *arr, object ob, string fun, int a);
void print_con(string x, object *arr);

object *treasure_obj;

/* 08/19/06 Earwax: Moved this from player.c */

int old_inv()
{  
  object ob;
  string str;
  
  if ((int)this_player()->test_dark()) 
  { 
    write("You can't see anything.\n"); 
    return 1; 
  }
  
  ob = first_inventory(this_player());
  
  while (ob) {
  str = (string)ob->short();
  if (str) {
    write(str); write(".\n");
  }
  ob = next_inventory(ob);
  }
  
  write("Carrying ");
  write((int)this_player()->query_pct_weight());
  write("% of maximum capacity.\n");
  return 1;
}

string * get_switches(string str) {
  if(str) {
    if(text_contains(str, "-")) {
      string *sws, *tws;
      int s;
      tws = ({ });
      sws = explode(str, "-"),
      s = sizeof(sws);
      while(s--) {
        if(stringp(sws[s])) {
          tws += ({ delete_spaces(sws[s]) });
        }
      }
      if(sizeof(tws)) return tws;
    }
  }
  return 0;  /* Rump */
}

int cmd_inv(string str)
{
    object *inv;
    int    y;
    
    
    this_player()->transfer_extra_eq();
    if(str == "-old") {
      object c;
      c = this_player();
      return old_inv();
  }
    if(!(y = sizeof(inv = all_inventory(this_player()))) || (y==1 && present("soul", this_player())))
    {
      write("You are not carrying anything.\n");
    }
    
    else 
    {
      object *armors, *heals, *containers, *special, *weps, wep, o_wep;
      mapping weaps;
      int  *p, s, mf; string sh, *sws;
      int x;
      string el; object fg, ff;
      mixed *pl;

      armors = heals = containers = special = p = weps = treasure_obj = ({ });
      treasure_obj = (object *) this_player()->query_treasure_obj();
      if( !treasure_obj )
        treasure_obj = ({ });
      
      ff = first_inventory(this_player());
      while(ff) {
        fg = next_inventory(ff);
        if(el=(string)ff->extra_look()) write(el+".\n");
        ff = fg;
      }
      for(x = 0; x < y; x ++)
      {
        mf = 0;
        if((pl = process_list(armors,inv[x],"query_worn"))[1])
        {
          armors = pl[0]; mf = 1;
        }
        if((pl = process_list(heals,inv[x],"is_heal"))[1])
        {
          heals = pl[0]; mf = 1;
        }
/*
        if((pl = process_list(containers,inv[x],"can_put_and_get"))[1])
        {
          containers = pl[0]; mf = 1;
        }
 */
        if(!inv[x]->id("mask_autoload"))
          if((pl = process_list(special,inv[x],"drop",1))[1])
          {
           if(!inv[x]->is_weapon())
          {
            special = pl[0]; mf = 1;
          }
          }
        if(mf) p += ({ x });
      }
      
      s = sizeof(p);
      while(s --) {
        inv -= ({ inv[p[s]] });
      }
      
      sws = get_switches(str);
      
      if(!sws || member_array("autoloads", sws) == -1) {
        print_con("Autoloads:\n", special);
      }
      
      /** For registered weapons **/
      weaps = (mapping) this_player()->QueryWeapons();
      weps = keys( weaps );
      
      /** For weapons using shadows **/
      wep = (object)this_player()->query_weapon();
      o_wep = (object)this_player()->query_second_weapon();
      
      if(!sws || member_array("weapons", sws) == -1) 
      {
        if(wep && wep->short() && !wep->id("mask_weapon"))
        {
          if( member( weps, wep ) < 0 )
           weps += ({ wep });
        }
        if(o_wep && o_wep->short() && !o_wep->id("mask_weapon"))
        {
          if( member( weps, o_wep ) < 0 )
           weps += ({ o_wep });
        }
        for( x=0; x < sizeof(weps); x++ ) {
          if( weps[x]->short() && !weps[x]->id("mask_weapon") && !weps[x]->id("GI") ) 
            inv -= ({ weps[x] });
          else
            weps -= ({ weps[x] });
        }
        
        print_con("Wielded:\n", weps);
      }
      
      if(!sws || member_array("armors", sws) == -1) {
        print_con("You are wearing:\n", armors);
      }
      if(!sws || member_array("heals", sws) == -1) {
        print_con("Heals:\n", heals);
      }
/*
      if(!sws || member_array("containers", sws) == -1) {
        print_con("Containers:\n", containers);
      }
*/
      if(!sws || member_array("other", sws) == -1) {
        print_con("Other:\n", inv);
      }
      write("\n");
      write("You are carrying "+
        (int)this_player()->query_pct_weight()+"% of maximum capacity.\n");
    }
  return 1;
}
string get_short( object obj ) {
  int kept;
  string flag;
  flag = "";

  if( !obj->short() )
    return 0;

  if( obj->queryKept() )
    kept = 1;

  if( member( treasure_obj, obj ) >= 0 )
    flag = kept ? "" : " [S]";

  return BOLD+ pad( flag, kept ? 1 : 5 ) + NORM  + obj->short();
}

void print_con(string msg, object *arr)
{
  int s, x, i;
  string sh;
  string stuff;
  string *m; int *a;
  m = ({ }); a = ({ });
  stuff = "";
  s = sizeof(arr);
  for(x = 0; x < s; x ++) {
    if(sh = get_short( arr[x] ) ) {
    /*if(sh = (string)arr[x]->short()) {*/
      sh = implode(explode(sh, "\n"), ".\n    ");
      if((i = member_array(sh, m)) == -1) {
        m += ({ sh });
        a += ({ 1 });
      }
      else {
        a[i] ++;
      }
    }
  }
  
  s = sizeof(m);
  for(x = 0; x < s; x ++) {
    stuff += pad( (a[x] != 1) ? "["+a[x]+"x]" : "", 6);
    stuff += m[x] + ".\n";
  }
    
  if(strlen(stuff)) {
      write("\n"+msg);
      write(stuff);
  }
}

varargs
mixed * process_list(object *arr, object ob, string fun, int a) {
  if((!a && call_other(ob, fun)) || 
     (a && (ob->query_auto_load() || ob->id("GI")))){
    return ({ arr + ({ ob }), 1 });
  }
  return ({ arr, 0 });
}
