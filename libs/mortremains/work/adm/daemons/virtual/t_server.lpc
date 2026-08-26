// Virtual treasure compiler

#include <mudlib.h>

inherit DAEMON;

#define DEBUG 1


#ifdef DEBUG
#define BUG(x) log_file("t_server", x)
#else
#define BUG(x)
#endif

object newobj;
int current;
string *lines;

string extension();
void evaluate(string word, string line);
void initialize_new();

object compile_object(string s)
{
  string word;
  int max;

  s+=extension();
  if (file_size(s)==-1)
    return 0;
  newobj=new(OBJECT);
  lines=explode(read_file(s),"\n");
  max=sizeof(lines);
  for (current=0; current<max; current++) {
    if (word=lines[current])
      sscanf(lines[current],"%s %*s",word);
    evaluate(word, lines[current]);
  }
  return newobj;
}

string extension() { return ".t"; }

void evaluate(string word, string line)
{
  string rest, newid;
  int amount;
  string *ids;

  switch(word) {
    case "id:":
      sscanf(line,"id: %s",rest);
      rest+=" end";
      ids=({ });
      while(sscanf(rest,"%s %s",newid,rest))
        ids+=({ newid });
      newobj->set("id", ids);
      break;
    case "short:":
      sscanf(line,"short: %s",newid);
      newobj->set("short", newid);
      break;
    case "value:":
      sscanf(line,"value: %d",amount);
      newobj->set_("value", amount);
      break;
    case "weight:":
      sscanf(line,"weight: %d",amount);
      newobj->set("weight", amount);
      break;
    case "long:":
      current++;
      for (newid = ""; lines[current] != "**"; current++)
        newid += lines[current]+"\n";
      newobj->set("long", newid);
      break;
  }
}

