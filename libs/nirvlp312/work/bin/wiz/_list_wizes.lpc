#define SAVEDIR "/players/"

void process_list();
string *list;
int level;

void process_list()
{
  string *df;
  int s;
  string *wiz_names;
  
  list=({});
  df = get_dir(SAVEDIR);
  s = sizeof(df);
  
  while(s --)
  {
    if(df[s] && sscanf(df[s],"%s.o",df[s]))
    {
      list += ({ df[s] });
    }
  }
}

string * query_list()
{
  process_list();
  return list;
}

int cmd_list_wizes(string str)
{
  int x, y;
  string junk;
  
  process_list();
  
  y = sizeof(list);
  
  for(x = 0; x < y; x++)
  {
    restore_object("players/"+list[x]);
    write(list[x]+" "+level+"\n");
  }
  return 1;
}