/********************************************************************
 * /bin/_ip.c: Sort users() array by ip # and print some user info  *
 * Created on: 6/10/96                                              *
 * Created by: Wizardchild (Dan Conti)                              *
 *             With thanks to Mythos for his assistance             *
 * Last revised: 6/14/96                                            *
 ********************************************************************/
#define SWAP(a,b) { int agf; agf = a; a = b; b = agf; }
#pragma strict_types
#pragma save_types
 
object *do_sort(object *in);
status find_member(int i, int *a);
 
int cmd_ip(int not_used) {
  object *ob,*can_see;
  int i, so,lev,idled;
  string *ip_arr, *hosts_arr;
  string flags;
  
  lev = (int) this_player()->query_level();
  ob = users();
  can_see = ({ });
  ip_arr = ({ });
  hosts_arr = ({ });
  for(i = 0, so = sizeof(ob); i < so; i++) {
    if(ob[i]->query_invis() < lev) {
      can_see += ({ ob[i] });
      if(ob[i]->query_idle() >= 300) 
        idled++;
    }
  }
  so = sizeof(can_see);
  write("There are now "+so+" players ("+(so-idled)+" active). "+
        query_load_average()+"\n");
  write("  Name         Idle  Address          Hostname\n");
  write("........................................................................\n");
  can_see = do_sort(can_see);
  so = sizeof(can_see);
  for(i = 0; i < so; i++) {
    flags = "";
    if(can_see[i]->query_invis()) flags += "#";
    if(in_editor(can_see[i]))     flags += "*";
    if(can_see[i]->query_ghost()) flags += "@";
    flags += capitalize((string) can_see[i]->query_real_name());
    write(pad(flags,15));
    flags = 0;
    lev = query_idle(can_see[i]);
    if(lev < 2) flags = pad("",4);
    else if(lev < 60) flags = pad(lev+"s",-4);
    else flags = pad((lev/60)+"m",-4);
    write(flags+"  ");
    flags = pad(query_ip_number(can_see[i]),17)+
            query_ip_name(can_see[i]);
    write(flags+"\n");
  }
  return 1;
}
status find_member(int i, int *a) {
  int x,so;
  for(x = 0, so = sizeof(a); x < so; x++)
    if(a[x] == i) return 1;
  return 0;
}
/* ip format is aaa.bbb.ccc.ddd */
/* this sorts aaa bbb and ccc...give full credit to Mythos for this */
object *do_sort(object *in) {
  string foo;
  object *out;
  int i, so,x,y,z;
  int *ip,*new_order,*used;
  ip = ({ });
  used = ({ });
  new_order = ({ });
  out = ({ });
  for(i = 0, so = sizeof(in); i < so; i++) {
    sscanf(query_ip_number(in[i]),"%d.%d.%d%s",x,y,z,foo);
    ip += ({ (x*1000000)+(y*1000)+z });
  }
  z = 666;
  for(i = 0, so = sizeof(ip); i < so; i++) {
    for(x = 0; x < so; x++) 
      if((z == 666|| ip[x] < ip[z]) && !find_member(x,used))
        z = x;
    new_order += ({ z });
    used += ({ z });
    z = 666;
  }    
  for(i = 0, so = sizeof(new_order); i < so; i++) 
    out += ({ (in[ (new_order[i]) ]) });
  return out;
}
