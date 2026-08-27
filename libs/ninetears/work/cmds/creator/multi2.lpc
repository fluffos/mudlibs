/* Creador Gestur
   Modificado seriamente por Spp (para arreglar un poquito el desastre).
   Mostrar paths en la info Feb'2000 Goku
   Recodificaion para eliminar multiples peticiones a users() Feb'2000 Goku
   Mostrar Idle sobre usuarios coincidentes Feb'2000 Goku
   Inclusion de coincidencias en environments Feb'2000 Goku
*/
 
#include <standard.h>
#include <cmd.h>
inherit CMD_BASE;
#define BLANK "   "
 
string get_ipmsg(object);
string get_file_name(object);
string get_filemsg(object);
 
void setup()
{
position = 1;
}
 
int cmd()
{
  object *usuarios = users();
  object *ips, *users_ok, env;
  int i = 0, j=0;
  string ip;
  users_ok = ({ });
  for(i=0;i<sizeof(usuarios);i++) {
    users_ok += ({ usuarios[i] });
  }
  if (!TP->query_creator()) return 0;
  {
	  write("\n%^BOLD%^YELLOW%^-- %^MAGENTA%^Control de Players %^YELLOW%^ -------------------------------%^RESET%^\n");
	  write("%^BOLD%^WHITE%^Gente con el mismo ip:%^RESET%^\n");
  }
  i=0;
  while(i < sizeof(usuarios))
  {
    ip   = usuarios[i]->query_my_ip();
    ips  = ({ });
    j = i+1;
   while (j < sizeof(usuarios))
    {
      if (ip && (ip == usuarios[j]->query_my_ip()))
      {
       ips += ({ usuarios[j] });
        usuarios -= ({ usuarios[j] });
      }
      j++;
    }
    if(sizeof(ips))
    {
      write("* "+ip+" ->\n");
      write(get_ipmsg(usuarios[i]));
      for (j=0;j<sizeof(ips);j++) {
        write(get_ipmsg(ips[j]));
      }
    }
    i++;
 }
   write("\n%^BOLD%^WHITE%^Gente con el mismo environment%^RESET%^:\n");
  usuarios = ({ });
  for(i=0;i<sizeof(users_ok);i++) {
    usuarios += ({ users_ok[i] });
  }
  i=0;
  while(i < sizeof(usuarios))
  {
    env   = environment(usuarios[i]);
    ips  = ({ });
    j = i+1;
   while (j < sizeof(usuarios))
    {
     if (env && (env == environment(usuarios[j])) )
      {
       ips += ({ usuarios[j] });
        usuarios -= ({ usuarios[j] });
      }
      j++;
    }
    if(sizeof(ips))
    {
      write("%^BOLD%^WHITE%^*%^RED%^ "+get_file_name(usuarios[i])+"%^YELLOW%^ ->\n");
      write(get_filemsg(usuarios[i]));
      for (j=0;j<sizeof(ips);j++) 
     	 write(get_filemsg(ips[j]));
    }
    i++;
 }
  write("\n%^BOLD%^WHITE%^Gente con el mismo login:%^RESET%^\n");
  usuarios = ({ });
  for(i=0;i<sizeof(users_ok);i++) {
    usuarios += ({ users_ok[i] });
  }
 for (i=0; i<sizeof(usuarios)-1; i++)
 {
   ip = usuarios[i]->query_ident();
   for(j=i+1; j<sizeof(usuarios); j++)
     if (ip && (ip == usuarios[j]->query_ident()))
       write(ip+"\t--- "+usuarios[i]->query_short()+" y "+
                         usuarios[j]->query_short()+".\n");
 }
   return 1;
}
 
string get_ipmsg(object obj)
{
   string back;
   if( query_idle(obj) > 120 ) {
     back = sprintf("  %sIdle: %d%s %10-s%s%s\n",
            "",query_idle(obj)/60,""," "+obj->query_short()+"",
             BLANK,get_file_name(obj));
   } else {
     back = sprintf("          %10-s%s%s\n"," "+obj->query_short()+"",
             BLANK,get_file_name(obj));
   }
   return(back);
}
 
string get_file_name(object obj)
{
   return (environment(obj)? virtual_file_name(environment(obj))
                      :"Esta en el limbo");
}
 
string get_filemsg(object obj)
{
   string back;
   if( query_idle(obj) > 120 ) {
     back = sprintf("  %sIdle: %d%s %10-s%s%s\n",
            "",query_idle(obj)/60,""," "+obj->query_short()+"",
             BLANK,obj->query_my_ip());
   } else {
     back = sprintf("          %10-s%s%s\n"," "+obj->query_short()+"",
             BLANK,obj->query_my_ip());
   }
   return(back);
}
