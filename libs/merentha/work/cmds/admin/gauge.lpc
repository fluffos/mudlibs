// Petrarch
// Merentha Lib 1.0
// <gauge>

varargs int command(string str) {
mapping usage1, usage2;
int eval_cost;
  if (!str) return notify_fail("Syntax: gauge <command>\n");
  usage1=rusage();
  eval_cost=eval_cost();
  this_player()->force_me(str);
  eval_cost=eval_cost-eval_cost();
  usage2=rusage();
  message("command", 
"User Time    : "+(usage2["utime"]-usage1["utime"])+
"\nSystem Time  : "+(usage2["stime"]-usage1["stime"])+
"\nEval Cost    : "+eval_cost
, this_player());
  return 1;
}

string help() {
return "Syntax: gauge <command>\n\nRuns the command named and prints stats on user and system time needed to run it.";
}
