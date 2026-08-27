#include <standard.h>
#include <cmd.h>
inherit CMD_BASE;

void setup(){

position = 1;
}



/*
  Nanvaent Industries International

  LPC: Search and Replace

  Written by  : Weazel@Nanvaent Nov 92
  Modified by : Bill@Nanvaent Jan 93
  Modified by : Bill@Nanvaent+@Discworld Mar 93
*/

int cmd(string str, object me)
{
  // int i, j, num;
int i;
  
  string *files; //, *bit;
   string s1, s2, s3, s4;
  if(!str)
  {
    notify_fail("Uso: sar $<cadena_a_sustituir>$ $<cadena_que_sustituye>$ <ficheros>\n");
    return 0;
  }
  s4 = str[0..0];
  if(sscanf(str, s4+"%s"+s4+" "+s4+"%s"+s4+" %s", s1, s2, s3) != 3)
    if (sscanf(str, "%s %s %s", s1, s2, s3) != 3)
    {
       notify_fail("Uso: sar $<cadena_a_sustituir>$ $<cadena_que_sustituye>$ <ficheros>\n");
      return 0;
    }
   log_file("SAR",me->query_name()+" : "+str+"\n");
  files = (string *)this_player()->get_files(s3);
  if(!sizeof(files))
  {
    notify_fail("Fichero(s) " + s3 + " no encontrado(s).\n");
    return 0;
  }
  for (i=0;i<sizeof(files);i++)
   {
    if (file_size(files[i]) <= 0) continue;
    write("Buscando en "+files[i]+".\n");
    s4 = read_file(files[i]);
    if (s4)
    {
      s4 = replace(s4, s1, s2);
      rm(files[i]);
      write_file(files[i], s4);
    }
     else
      write("...fallo...no hay fichero\n");
  }
  return 1;
}

