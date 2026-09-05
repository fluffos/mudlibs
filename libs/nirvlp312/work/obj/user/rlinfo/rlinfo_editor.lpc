#include <ansi.h>
#define DAEMON "/obj/user/rlinfo/rlinfo_daemon"

mapping info;

void receive_info();
void loadMain();

void reset(int x)
{
  if(x) return;
  info = ([ "character" : 0,
            "age" : 0,
            "gender" : 0,
            "name" : 0,
            "location" : 0,
            "email": 0,
            "favorite": 0,
            "quote" : 0,
            "www" : 0,
            "im" : 0,
            "misc" : 0,
            "occupation" : 0 ]);
}

int start_edit()
{
  info["character"]=(string)this_player()->query_real_name();
  receive_info();
  
  loadMain();
  return 1;
}

void send_info()
{
  int x, y;
  string *ks;
  string nm;
  
  nm = info["character"];
  ks = m_indices(info);
  y  = sizeof(ks);
  
  for(x = 0; x < y; x ++)
  {
    if(ks[x]=="character") continue;
    if(info[ks[x]] == 0 || info[ks[x]]=="")
    {
      call_other(DAEMON, "delete_"+ks[x], nm);
    }
    else
    {
      call_other(DAEMON, "add_"+ks[x], nm, info[ks[x]]);
    }
  }
}

void receive_info()
{
  int x, y;
  string *ks;
  string nm;
  
  nm = info["character"];
  ks = m_indices(info);
  y  = sizeof(ks);
  
  for(x = 0; x < y; x ++)
  {
    if(ks[x]=="character") continue;
    
    info[ks[x]] = (string)call_other(DAEMON, "query_"+ks[x], nm);
  }
}

#define mainprompt "[1-"+(sizeof(info)-1)+", 'q'uit, e'x'it, 'h'elp]: "

int editing;

int loadMain()
{
  int x, y;
  string *ks;
  
  editing = 0;
  
  write("\n");
  
  ks = m_indices(info);
  y = sizeof(ks);
  
  for(x = 0; x < y; x ++)
  {
    if(ks[x]=="character") continue;
    
    write(x+": "+ks[x]+":\n");
    write("    "+(info[ks[x]]?info[ks[x]]:"")+"\n");
  }
  write("\n");
  
  write(mainprompt);
  input_to("main_choice");
  return 1;
}

void display_help()
{
  write("\nChoose a number to edit its value.\n"+
        "'q' quits without saving.\n"+
        "'x' exits WITH saving.\n");
}

int main_choice(string str)
{
  int num;
  if(str=="q")
  {
    /* do not save */
  }
  else if(str=="x")
  {
    send_info();
  }
  else if(str=="h")
  {
    display_help();
    write(mainprompt);
    input_to("main_choice");
  }
  else if(!sscanf(str,"%d",num) || num < 1 || num > sizeof(info) - 1)
  {
    write("Invalid choice.\n");
    write(mainprompt);
    input_to("main_choice");
  }
  else
  {
    editing = num;
    write("Ok, changing \""+m_indices(info)[num]+"\".\n");
    write("Enter information, or 'd' to delete: ");
    input_to("enter_information");
  }
  return 1;
}

int enter_information(string str)
{
  if(str == "d")
    str = 0;
  info[m_indices(info)[editing]]=str;
  return loadMain();
}