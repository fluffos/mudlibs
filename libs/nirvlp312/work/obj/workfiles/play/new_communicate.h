/* 3-14-03 */

new_communicate(str)
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

#if 0 /* Rumplemintz - Grr.... */
 me = (ghost?short():cap_name);
#else
 me = (ghost ? short() : this_object()->query_name());
#endif

 say(me+" "+how+"s: "+str+"\n");
 if(brief)
  write("Ok.\n");
 else
  write("You "+how+": "+str+"\n");

 return 1;
}
