// Petrarch
// Merentha Lib 1.0
// <callouts>

varargs int command(string obj) {
mixed *callouts;
int i;
        
  message("command",arrange_string("Object",35)+arrange_string("Function",35)+"Time",this_player());
  i=sizeof(callouts=call_out_info());
  while (i--) 
    callouts[i]=arrange_string(identify(callouts[i][0]),35)+arrange_string(identify(callouts[i][1]),35)+arrange_string(identify(callouts[i][2]),4);
  this_player()->more(callouts);
  return 1;
}

string help() {
return "Syntax: callouts\n\nDisplays information on all pending call_out() calls.\n\nSee also: mudstats";
}
