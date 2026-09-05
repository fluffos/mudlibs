#include <security.h>

int cmd_statall(string str)
{
 object *list;
 int ll, hl, count, i, z, x, id_t, a, t, ept, plt, act,
     wct, mct, hpt, spt, mspt, mhpt;

 if(str && sscanf(str, "%d %d", ll, hl))
 {
  write("Usage: 'statall', or 'statall <lownum> <highnum>'\n");
  return 1;
 }

 list = users();
 if(!hl || hl < 11)
 {
  hl = 2000000;
  ll = 0;
 }
 t = sizeof(list);
 if(hl != 2000000)
  write("Those between levels "+ll+" and "+hl+" are displayed.\n");
 write("   Name      Money      AC     WC    HP     MHP    SP    MSP      Exp\n");
 write("-----------------------------------------------------------------------------\n");
 write("\n");
 while(i < sizeof(list))
 {
  int ql, qi;
  string sn, ip, sd, sh;
  object obply, plob;
  if((ql = (int)list[i]->query_level()) > ll && ql < hl)
  {
   if((qi = (int)list[i]->query_invis()) < 55 || (qi > 55 && 
    (int)this_player()->query_level() >= ql))
   {
    if(ql < EXPLORE)
     plt += 1;
    sn = capitalize((string)list[i]->query_real_name());
    
    if(list[i]->query_ghost())
     sn = "ghost of "+sn;
    plob = find_player(sn);
    if(in_editor(list[i]))
     sn = "*"+sn;
    x = 0;
    while(x < 15)
    {
     sn += " ";
     x += 1;
    }
    if(list[i]->query_ghost())
     sh = "@"+sn[9..20];
    else
     sh = sn[0..12];
    write(sh);
    count = 1;
    while (count < 9)
    {
     if(count == 1)
     {
      z = (int)list[i]->query_money();
      if(ql < EXPLORE) mct += z;
     }
     if(count == 2)
     {
      z = (int)list[i]->query_ac();
      if(ql < EXPLORE) act += z;
     }
     if(count == 3)
     {
      z = (int)list[i]->query_wc();
      if(ql < EXPLORE) wct += z; 
     }
     if(count == 4)
     {
      z = (int)list[i]->query_hp();
      if(ql < EXPLORE) hpt += z;
     }
     if (count == 5)
     {
      z = (int)list[i]->query_mhp();
      if(ql < EXPLORE) mhpt += z;
     }
     if (count == 6)
     {
      z = (int)list[i]->query_sp();
      if(ql < EXPLORE) spt += z;
     }
     if (count == 7)
     {
      z = (int)list[i]->query_msp();
      if(ql < EXPLORE) mspt += z;
     }
     if (count == 8)
     {
      z = (int)list[i]->query_exp();
      if(ql < EXPLORE) ept = ept+z;
     }
     if(count == 8 && z < 10000000)
      write(" ");
     if(count == 8 && z < 1000000)
      write(" ");
     if (z < 99999)
      write(" ");
     if(z < 10000 && z > 999)
      write(" ");
     if(z < 1000 && z > 99)
      write("  ");
     if(z < 100 && z > 9)
      write("   ");
     if(z < 10)
      write("    ");
     write(z);
     write(" ");
     count += 1;
    }
   }
   write("\n");
  }
  i += 1;
  x = 0;
 }
 write("AVERAGES (pl)");
 count = 1;
 while (count < 9)
 {
  if(!plt) plt=1;
  if(count==1) z=mct/plt;
  if(count==2) z=act/plt;
  if(count==3) z=wct/plt;
  if(count==4) z=hpt/plt;
  if(count==5) z=mhpt/plt;
  if(count==6) z=spt/plt;
  if(count==7) z=mspt/plt;
  if(count==8) z=ept/plt;
  if ( z < 99999)
   write(" ");
  if(z < 10000 && z > 999)
   write(" ");
  if(z < 1000 && z > 99)
   write("  ");
  if(z < 100 && z > 9)
   write("   ");
  if(z < 10)
    write("    ");
  write(z);
  write(" ");
  count += 1;
 }
 write("\n");
 return 1;
}
