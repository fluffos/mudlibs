int do_sense(string arg, string sense, string verb)
{
 string senseResult;
 if(!arg)
  arg = "main";
 senseResult = (string)call_other(environment(this_player()),
                                  "query_"+sense, arg);
 if((arg=="main"||arg=="default") && !senseResult)
 {
  if(sense == "taste" || sense == "feel")
   return (notify_fail(capitalize(sense)+" what ? \n"), 0);
  write("You don't "+verb+" anything here.\n");
 }
 else if(!senseResult)
  write("You don't "+verb+" any "+arg+" here.\n");
 else
  {
   int sl;
   status nl_flag;
   sl = strlen(senseResult) - 1;
   if(senseResult[sl] == '\n')
   {
    nl_flag = 1;
    senseResult = senseResult[0..sl-1];
   }
   else if(senseResult[sl] == ' ')
     senseResult = senseResult[0..sl-1];
   sl = strlen(senseResult) - 1;
   if(senseResult[sl] != '.' &&
      senseResult[sl] != '!' && senseResult[sl] != '?')
     senseResult = ((nl_flag?senseResult[0..sl-1]:senseResult[0..sl])+".");
    sl = strlen(senseResult)-1;
    write(senseResult + (senseResult[sl]=='\n'?"":"\n"));
  }

 return 1;
}

