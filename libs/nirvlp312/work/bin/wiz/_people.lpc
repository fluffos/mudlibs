/*
// /bin/_people.c
//
// Daemonized by Shadowhawk
*/

#include <security.h>

#pragma strict_types
#pragma save_types

int
cmd_people(string str) {
  object *list;
  int ll,hl,age_n,age_n2, i, z, x;
  int id_t,a,t;
  object snpob;
  string snpobn,option,gen;

  if ((int)this_player()->query_level() < EXPLORE)
    return 0;
  if (!str || str =="")
    str = "a";
  if (sscanf(str, "%s %d %d", option,ll,hl) == 3)
    str = option;
  if (hl < ll || !hl) {
    hl = 2147483647;
    ll = -2;
  }
  list=users();
  t = sizeof(list);
  for (i=0; i<sizeof(list); i++) {
    if (list[i]->query_invis() > 55 &&
        this_player()->query_level() < list[i]->query_level())
      t -=1;
  }
  if (hl != 2147483647)
    write(" Only those between level "+ll+" and level "+hl+" are listed\n");
/* Added the following so screenshots of the people command have a
 * a timestamp that's visible and nice - Rumplemintz */
  write(":::::::::: The current time is: "+ctime()+" ::::::::::\n");

  write("There are now " + t + " players");
  for (i=0, a=0; i < sizeof(list); i++)
    if (query_idle(list[i]) >= 5 * 60)
      a++;
    if (a)
      write(" (" + (sizeof(list) - a) + " active)");
  write(". " + query_load_average() + "\n");
  i = 0;
  if (str!="S" && str!="h" && str!="O" && str!="g" && str!="i" && str!="a")
    write("   Address        Name             Level      Location  \n");
  if (str == "a")
    write("   Address        Name       Age   Level      Location  \n");
  if (str == "i")
    write("   Address        Name      Idle   Level      Location  \n");
  if (str == "g")
    write("   Address        Name     gender  Level      Location  \n");
  if (str == "O")
    write("   Address        Name     object#  Level      Location  \n");
  if (str == "h")
    write("   Name           Address\n");
  if (str == "S")
    write("   Name        Snooped by\n");
  write("........................................................................\n");
  while(i < sizeof(list)) {
    string sn, ip, sd, sh;
    object obply, plob;
    if (list[i]->query_level() > ll && list[i]->query_level() < hl) {
    if (list[i]->query_invis() < 55 ||
        (list[i]->query_invis() > 55 &&
         this_player()->query_level() >= list[i]->query_level())) {
      sn = capitalize((string)list[i]->query_real_name());
      sn = capitalize(sn);
      if (!sn)
        sn = "Logon";
      if ((int)call_other(list[i], "query_ghost", 0) == 1)
        sn = "ghost of " + sn;
      plob = find_player(sn);
      if (in_editor(list[i]))
        sn = "*"+sn;
      ip = query_ip_number(list[i]);
      while(x < 13) {
        ip += " ";
        x += 1;
      }
      x = 0;
      if (str != "h" && str != "S")
        write(extract(ip, 0, 15));
   while(x < 15){
   sn += " ";
 x += 1;
   }
 if (call_other(list[i], "query_invis", 0) > 0)
      sn = "#" + sn;
 if((int)call_other(list[i], "query_ghost", 0) == 1) {
    sh = extract(sn, 9, 20);
    sh = "@"+ sh;
  } else
   sh = extract(sn, 0, 12);
   write(sh);
if (str == "i") {
    id_t = query_idle(list[i]);
    if (id_t/60 > 0) {
    if (id_t/60 < 10)
    write(" " + id_t/60 + "m ");
    if (id_t/60 > 9)
	    write(query_idle(list[i]) / 60 + "m ");
    }
   if (id_t < 10 && id_t && id_t != 0)
    write(" " + id_t + "s ");
   if (id_t > 9 && id_t < 60)
   write(id_t + "s ");
   if (id_t == 0 || !id_t)
   write ("    ");
 }
if (str == "h") {
    write(" "+query_ip_name(list[i])+" ");
}
if (str == "S") {
   snpob=query_snoop(list[i]);
   if(snpob)
/*
   if(snpob &&(string)snpob->query_real_name() != "boltar")
*/
   { snpobn=(string)snpob->query_real_name();
   write(" "+capitalize(snpobn)+" ");
   }
   else write(" ----------- ");
}
if (str == "g") {
    gen=(string)call_other(list[i], "query_gender",0);
    if (gen == "female")
      write ("  f  ");
    if (gen == "male")
       write ("  m  ");
    if (gen == "creature")
       write ("  c  ");
}
if (str == "a"){
   age_n = (int)list[i]->query_age();
   age_n2 = 0;
   if (age_n < 1800)
   {
      age_n = age_n/30;
     if (age_n > 9)
       write(age_n + "m ");
     if (age_n < 10)
       write(" " + age_n + "m ");
    }
   if (age_n > 1800)
   age_n2 = age_n/1800;
   if (age_n2 > 9 && age_n2 < 24)
     write(age_n2 +"h ");
   if (age_n2 < 10 && age_n2 > 0)
     write(" " + age_n2 + "h ");
    if (age_n2 >= 24)
   {
      age_n2 = age_n2/24;
    if(age_n2 > 9 && age_n2 < 100)
      write(age_n2 +"d ");
   if(age_n2 > 99)
      write(age_n2+"d");
    if (age_n2 < 10)
      write(" " + age_n2 + "d ");
    }
    }
if(str == "O") write(extract(object_name(list[i]), 10, 15));
if (str !="O" && str !="i" && str !="a" && str !="g")
  write("    ");
   z = (int)list[i]->query_level();
    if (z <99999) 
   write(" ");
    if(z < 10000 && z > 999) {
    write(" ");
}
   if(z < 1000 && z > 99) {
     write("  ");
   }
   if(z < 100 && z > 9) {
      write("   ");
   }
   if(z < 10) {
    write("    ");
   }
   if(str != "h" && str != "S")
   write(z);
   write("  ");
  obply = environment(list[i]);
   if (!obply) {
   if(str != "h" && str != "S")
     write("location unknown.\n");
   if(str == "S" || str == "h") write("\n");
     }
   if (obply) {
   if(str != "h" && str != "S")
   write(object_name(obply));
 write("\n");
  }
 }
}
       i += 1;
       x = 0;
     }
    return 1;
    }
