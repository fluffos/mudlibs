#include <ansi.h>

mapping wiz_status;

void reset(status arg) {
  if(!wiz_status) wiz_status=([]);
}

void set_wiz_status(string name,string wstatus) {
	if(!name) return;
	wiz_status[name]=wstatus;
}

int cmd_wizes(string str)
{
  object *ob;
  int h, s;
  int hr, min, sec, tm; 
  string output;
  string wstatus;
  string time_string;
  ob = users();
  s  = sizeof(ob);
  output = "\n";
  output += BLU+"\
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+NORM+HIW+"\
  Lvl    Developer    Idle      Status\n"+NORM+BLU+"\
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+NORM;
  for(h=0;h<s;h++)
  {
    if((int)ob[h]->query_level() > 19 && !((int)ob[h]->query_invis()))
    {
      output += "  "+(int)ob[h]->query_level();
      if((int)ob[h]->query_level() < 100000)
        output += "\t";
      output += " "+pad((string)ob[h]->query_name(),13);
      tm = query_idle(ob[h]);
      time_string="";
      if(hr = (tm / 3600))
      {
        time_string += hr+"h ";
        tm -= (hr * 3600);
      }
      if(min = (tm / 60))
      {
        time_string += min+"m ";
        tm -= (min * 60);
      }
      output += pad(time_string,10);

      wstatus=wiz_status[ob[h]->query_real_name()];
      if(wstatus)
        output+=wstatus;
      else if (in_editor(ob[h]))
        output += "Editing";
      else if(query_idle(ob[h]) > 3000)
        output+="Idle";
      else output+="Available";
      output+="\n";
    }
  }
  output += BLU+"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+NORM;
  write(output+"\n");
  return 1;
}
