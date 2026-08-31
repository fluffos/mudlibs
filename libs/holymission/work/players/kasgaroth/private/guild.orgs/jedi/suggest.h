suggest(str) {
  int i;
  int found;
  string what,who;
  if(!str) {
    write("Suggestions are :"+SUGGESTIONS+"\n");
    return 1;
  }
  sscanf(str,"%s %s",what,who);
  if(!who) what=str;
  i=sizeof(suggest_arr)-1;
  found=0;
  while(i>=0) {
   if (suggest_arr[i] ==what) found=1;
   i--;
  }
  if(!found) {
    write("You don't know how to do this.\n");
    return 1;
  }
  else
  {
    call_other(this_object(),what,who);
    return 1;
  }
}
  

 
