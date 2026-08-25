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

protected int cmd(string str, object me)
{
  int i, j, num;
  string *files, *bit;
   string s1, s2, s3, s4;
  if(!str)
  {
    notify_fail("Usage: sar search_string replace_string <files>\n");
    return 0;
  }
  s4 = str[0..0];
  if(sscanf(str, s4+"%s"+s4+" "+s4+"%s"+s4+" %s", s1, s2, s3) != 3)
    if (sscanf(str, "%s %s %s", s1, s2, s3) != 3)
    {
       notify_fail("Usage: sar search_string replace_string <files>\n");
      return 0;
    }
   log_file("SAR",me->query_name()+" : "+str+"\n");
  files = (string *)this_player()->get_files(s3);
  if(!sizeof(files))
  {
    notify_fail("File(s) " + s3 + " not found.\n");
    return 0;
  }
  for (i=0;i<sizeof(files);i++)
   {
    if (file_size(files[i]) <= 0) continue;
    write("Looking at "+files[i]+".\n");
    s4 = read_file(files[i]);
    if (s4)
    {
      s4 = replace(s4, s1, s2);
      rm(files[i]);
      write_file(files[i], s4);
    }
     else
      write("...failed...no file\n");
  }
  return 1;
}

