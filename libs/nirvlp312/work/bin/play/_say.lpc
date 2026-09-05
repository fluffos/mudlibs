/* 08/13/06 Earwax: Daemonized this */
/* 3-14-03 */

status cmd_say(string str)
{
 string me, how;
 int    index;
 if(!str || str=="")
 {
  write("Say what?\n");
  return 1;
 }
 if(str[(index=(strlen(str)-1))] == '?')
  how = "ask";
 else if(str[index]=='!')
  how = "exclaim";
 else how = "say";

 str = format(str, 60);
 me = ((int)this_player()->query_ghost()?(string)this_player()->short():(string)this_player()->query_name());

 say(me+" "+how+"s: "+str+"\n");
  write("You "+how+": "+str+"\n");

 return 1;
}
