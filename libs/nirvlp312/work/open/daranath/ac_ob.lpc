#define tp this_player()
#define ep environment(this_object())
int ac;

id(str) { return str == "ac_ob"; }

drop() { return 1; }
get() { return 0; }

extra_look() {
write(environment()->query_name()+" is currently in wraithform.\n");
}

set_ac(arg) { ac = arg; }

init() {
  if(ep)
  if(tp == ep) {
    tp->set_ac(ac);
	call_out("wipe",1000);
  return 1;
  } 
}

wipe() {
  if(!ep) return 1; 
tell_object(ep,"\nWraithform runs its course and you return to your solid form.\n\n");
  ep->set_ac(0);
  destruct(this_object());
return 1; }

