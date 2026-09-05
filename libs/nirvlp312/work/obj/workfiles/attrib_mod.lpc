string attrib;
int    amt;
int    time;
int    num;
string dest_msg;

id(str){
  return str=="attrib_mod";
}

reset(arg)
{
  if(arg) return;
  dest_msg = "You feel your attributes returning to normal.\n";
}

start_it(a, am, t)
{
  int qa;
  
  attrib = a;
  amt = am;
  time = t;
  num = 0;
  
  qa = environment()->query_attrib(attrib);
  
  environment()->set_attrib(attrib, qa + amt);
  command("save", environment());
 
  call_out("tick", 1);
}

tick()
{
  if(++num == time)
  {
    int qa;
    qa = environment()->query_attrib(attrib);
    environment()->set_attrib(attrib, qa - amt);
    tell_object(environment(), dest_msg);
    destruct(this_object());
  }
  call_out("tick", 1);
}
  
drop() { return 1; }

query_auto_load(){
  string al;
  al = ":"+attrib+"@"+amt+"@"+time+"@"+num;
  return basename(this_object())+al;
}

init_arg(x){
  sscanf(x, "%s@%d@%d@%d", attrib, amt, time, num);
  call_out("tick", 1);
}

set_dest_msg(d) { dest_msg = d; }
