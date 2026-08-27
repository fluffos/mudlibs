/* Comando para anyadir a la lista de IP's las ip's que estan en multi
   y pertenecen a un cyber para que no salgan en el who */
// Yvendur Enero 00

#include <standard.h>
#include <cmd.h>
inherit CMD_BASE;
#define PEOPLER "/obj/handlers/peopler"

string lista;
string multi; 
void setup()
{
position = 1;
}

string dame_lista();
int anyade_ip(string ip);

int cmd(string str, object me) {
  string comando;
  string ip;
  string *param,*param1;
  string *param2;

  multi=PEOPLER->do_multi();
  if(!str)
     { notify_fail("ip <comando> [<numero IP>]. Comandos: listar, borrar y anyadir.\n");  
       return 0;
     }

  
  param=explode(str," ");
  if(sizeof(param)==2)
    {
     comando=param[0];
     ip=param[1];
    }
  
  if(sizeof(param)==1)
     comando=param[0];
  
  if(sizeof(param)!=1&&sizeof(param)!=2)
     { notify_fail("Parametros incorrectos.\n"); return 0;  }
 
  if(comando=="listar")
    {  lista=dame_lista();
      write(lista+"\n"); 
      return 1;
    }
  if(comando=="anyadir")
    {
      if(!ip)
        { notify_fail("usa: ip anyadir <numero ip>\n");  return 0;  }
      if(multi=="No hay jugadores en multiplaying.")
         { notify_fail("No hay IP's en multiplay.\n");
           return 0;
         }

      lista=dame_lista();
      param1=explode(lista,"\n");
      if(member_array(ip,param1)!=-1)
        {  notify_fail("Esta IP ya esta anyadida a la lista.\n");  return 0;  }
      param=explode(ip,".");
      if(sizeof(param)!=4||ip=="127.0.0.1")
        {  notify_fail("IP ilegal o erronea.\n");  return 0;  }
     
      param2=explode(multi," ");
      if(member_array(ip,param2)!=-1)
        { notify_fail("Esta IP no esta en Multiplay.\n");
          return 0;
        }
      anyade_ip(ip);
      write("Ok, IP :"+ip+" anyadida a la lista de cybercafes-IP fijas.\n");
      return 1;
    } 
 
   notify_fail("Comando de IP erroneo.\n");
   return 0;
} 



string dame_lista()
{
 if(file_size("/cmds/creator/ip.cyber")>0)
   return read_file("/cmds/creator/ip.cyber");
 else
  return "Ninguna IP registrada.\n";
}

int anyade_ip(string ip)
{
  write_file("/cmds/creator/ip.cyber",ip+"\n");
  return 1;
}
