// New mudlist command for I3 system
// Added some enhancements, Avatar of Eodon, 09/19/95
// Added some enhancements, Slc/Brainstorm May 96

#include <net/i3.h>

inherit DAEMON;
 
#define        SYNTAX        "Syntax: mudlist [-a] [mudname]\n"

string *format_info(string name,mixed vls,string option)
{
  string flags="";
  mapping services = ([]);

  if(vls[10] && mapp(vls[10])) services = vls[10];
  else if(vls[11] && mapp(vls[11])) services = vls[11];
    
  flags += (sizeof(services) && services["tell"])  ? "* ":"  ";
  flags += (sizeof(services) && services["who"])  ? "* ":"  ";
  flags += (sizeof(services) && services["finger"]) ? "* ":"  ";
  flags += (sizeof(services) && services["locate"]) ? "* ":"  ";
  flags += (sizeof(services) && services["channel"]) ?  "* ":"  ";
  flags += (sizeof(services) && services["news"]) ? "* ":"  ";
  flags += (sizeof(services) && services["mail"]) ? "* ":"  ";

  return ((vls[0]==-1) || (option=="-a")) ?
    ({sprintf("%-15s%-17s%5d%c %-15s %s",
            name[0..14], (vls[0]!=-1) ? "(" + vls[1] : " " + vls[1] ,vls[2],
            (vls[0]!=-1) ? ')' : ' ',
            ((vls[5] && stringp(vls[5])) ? vls[5][0..14] : ""), flags)}):
    ({});
}
 
int cmd_mudlist(string args)
{
  string *mud,flags;
  mixed *vls;
  int i,j;
  mapping list,newlist;
  string option="";
  string *result=({});
  string *sorted=({});

  list = I3_DAEMON->query_mudlist();
  if (!sizeof(list))
  { 
    message("error","No muds on I3 Network!\n", this_player() ); 
    return 1;
  }

  mud = keys(list);
  vls = values(list);
  
  result = ({"There are currently "+sizeof(mud)+" muds on the I3 Network!\n",
             sprintf("%-15s %-17s %-5s %-15s %s","Name","IP","Port",
                     "MudLib","T W F L C N M L"),
             sprintf("%-15s %-17s %-5s %-15s %s","----","--","----",
                     "------","- - - - - - - -")});

  j = -1;

  if (args && args!="")
  {
    string name=args;

    if (sscanf(args,"%s %s",option,name)==2 &&
        option!="-a")
    {
      write(SYNTAX);
      return 1;
    }
    else
      if (args=="-a")
      {
        option = "-a";
        name = "";
      } else
	option = "-a";  /* test by SLC */ 

    args = name;

/*    if (name!="" && (j=member_array(name,mud))==-1)
    {
      write("Sorry, the mud "+args+" is not in the list right now. Try again "+
            "later.\n");
      return 1;
    } */
 
  } 

  if (j != -1)
    sorted += format_info(mud[j][0..14],vls[j],option);
  else
    for (i=0; i<sizeof(mud); i++){
      sorted += format_info(mud[i][0..14],vls[i],option);
    }

  if( args ) sorted=regexp( sorted, args );
  if( !sizeof(sorted) ) {
      write (wrap ("Sorry, the expression `"+args+"' did not match anything on the list right now. "+
            "Try again later."));    
      return 1;
  }
  result += sort_array(sorted,"compare_names",this_object());
  this_player()->more(result);

  return 1;
}

int compare_names(string a,string b)
{
  return strcmp(a,b);
}
 
string help()
{

  return(SYNTAX+"\n"+
	"This command gives a full list of all MUDs and their addresses that\n"+
	"are connected to the Intermud 3 network.\n\n"+
        "Additionally a regular expression can be given in order to narrow\n"+
	"the selection.\n\n"+
	"For more info see: http://www.imagianry.com/~beek/intermud.\n\n"+
	"Flags are: Tell, Who, Finger, Locate, Channel, News, Mail\n"+
	"\nSee also: tell, who, finger\n");
}
