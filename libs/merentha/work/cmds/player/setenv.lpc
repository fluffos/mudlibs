// Petrarch
// Merentha Lib 1.0
// <setenv>

string help() {
return "Syntax: setenv <variable> <value>\n\n\
This command allows you to customize your environment.  Valid \
variables are:\n\
   BRIEF       sets brief movement mode (either 'on' or 'off')\n\
   SCREEN      sets the column width of your screen\n\
   LINES       sets the height of your screen\n\
   TERMINAL    (either 'ansi' or 'unknown')\n\
\n\
Examples: setenv SCREEN 75
          setenv LINES 20
          setenv terminal ansi\n\n\
See also: ansi";
}

int command(string str) {
mixed var, val;
  if(!str) return notify_fail(help()+"\n");
  if(sscanf(str, "%s %s", var, val)!=2) return notify_fail(help()+"\n");
  if(member_array(var, ({"BRIEF","SCREEN","LINES","TERMINAL"}))==-1) return notify_fail("Invalid setenv variable.\n");
  switch (var) {
   case "SCREEN": val=to_int(val); if(val>132) val=132; break;
   case "LINES": val=to_int(val); if(val>200) val=200; break;
   case "TERMINAL": var="terminal"; break;
   case "BRIEF": if(val=="1" || val=="on") val=1; else val=0; break;
  }
  this_player()->setenv(var, val);
  message("command", "Variable "+var+" set to "+val+".", this_player());
  return 1;
}


