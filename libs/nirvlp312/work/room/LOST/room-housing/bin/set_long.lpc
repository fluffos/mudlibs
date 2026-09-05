#include "../defs.h"

/* Global Variables */
string Text;
status Parse;
object Room, Master;
int Wrap;
status Flag;

int *priv_cost() { return ({ 2, 0 }); }

int 
main(string arg, object room, object master)
{
  Text = "";
  write(HIK+"======================================================================================\n"+NORM+NORM);
  write(HIW+"Enter long description below.  Use '**' to finish, '~q' to abort.\n"+NORM+NORM);
  write("Note: descriptions will automatically line-wrap.\n");
  write(HIK+"======================================================================================\n"+NORM+NORM);
  Parse = ((status)master->query_upgrade(UPGRADE_ANSI) ? 1 : 0);
  Room = room; Master = master;
  Wrap = (int)Master->query_wrap_pref();
  input_to("input_text");
  Flag = 0;
  return 1;
}

void 
input_text(string arg) 
{

  if (arg == "~q")
  {
    write(HIW+"Aborting.\n"+NORM+NORM);
    return;
  }

  if (arg == "**")
  {
    write(HIK+"======================================================================================\n"+NORM+NORM);
    write(HIW+"New description has been set to: \n"+NORM+NORM);
    write(Text);
    Room->set_long(Text);
    write(HIW+"\nNote: changes aren't permanent until 'save_settings' has been used.\n"+NORM+NORM);
    return;
  } 

  if (arg == "")
    Text += "\n";
  else 
  {
    if (Parse)
      arg = (string)ANSI_PARSER->parse_pcodes(arg)+NORM+NORM;
  
    arg = (string)WAXFUNS->line_wrap(NORM+arg, Wrap);
    Text = Text + (Flag ? "\n" : "") + arg;
  }
  
  Flag = 1;
  write(arg+"\n");
  input_to("input_text");
}
