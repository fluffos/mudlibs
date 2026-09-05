/* call_out.c: example of heart_beat like call_out loops */
short() { return "An example of call out"; }
id(str) { return str == "example"; }
get() { return 1; }
long() { write("Type \"start_example\" or \"stop_now\".\n"); }
init() { 
  if(this_player()->query_level() < 20) destruct(this_object());
  add_action("start", "start_example");
  add_action("stop", "stop_now");
}
set_fake_hb(arg) {
  while(remove_call_out("fake_hb") != -1) ;
  if(arg) call_out("fake_hb", 3);
}
start() {
  set_fake_hb(1);
  write("On.\n");
  return 1;
}
stop()  {
  set_fake_hb(0);
  write("Off.\n");
  return 1;
}
/* placing the set_fake_hb(0) and fake_hb(1) in their positions prevents */
/* mass running on error */
fake_hb() {
  object ob;
  set_fake_hb(0); /* remove overlapping */
  ob = environment(this_object());
  if(!living(ob)) set_fake_hb(0);
  tell_object(ob, "Fake HB called.\n");
  set_fake_hb(1);   
}
