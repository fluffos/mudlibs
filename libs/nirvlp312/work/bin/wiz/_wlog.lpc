#include "/obj/user/dt_stamp.h"

int cmd_wlog(string str)
{
  string entry;
  string action, reason;
  if(!str)
  {
    write("================================================================================\n");
    command("tail /log/WR/"+(string)this_player()->query_real_name()+"_workreport", this_player());
    write("--------------------------------------------------------------------------------\n");
    command("tail /log/WR/WORK_REPORT", this_player());
    write("================================================================================\n");
    return 1;
  }
  if(str && sscanf(str,"%s %s",action,reason)== 0 && file_size("/players/"+str) == -2)
  {
    write("================================================================================\n");
    command("tail /log/WR/"+str+"_workreport", this_player());
    write("================================================================================\n");
    return 1;  
  }
  action=reason=0;
  if(sscanf(str,"%s#%s",action,reason) != 2)
  action=str;
   
  entry = (reason?("\n  A: "+action+"\n  R: "+reason+"\n"):"A: "+action+"\n");
  write_file("/log/WR/"+(string)this_player()->query_real_name()+"_workreport","["+DT+"] "+entry);
  write_file("/log/WR/WORK_REPORT","["+DT+"] "+capitalize((string)this_player()->query_real_name())+": "+ entry);
   
  write("Noted in workreport.\n");
  return 1;
}
