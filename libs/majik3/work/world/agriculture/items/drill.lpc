inherit ITEM;
int pay_time;
int drilled = 0;
create_item()
{
  set_name(({"water drill","drill"}));
  set_short("a long metalic water drill");
  set_long(wrap("This is a long metalic water drill for tapping into "+
  "deep water sources.  You can check the drill to see how much "+
  "life is left in this drill.\n"));
  set_material ("steel");
  set_dimensions (50, 5, 5);
}
init()
{
  add_action("do_irrigate","irrigate");
  add_action("do_check","check");
  add_action("do_drill","drill");
}
do_drill()
{
  if(!drilled){
  message("standard","You drive the water drill into the ground.\n",THIS);
  message("standard",THIS->query_cap_name()+" drives the water drill "+
  "into the ground.\n",ENV(THIS),THIS);
  drilled = 1;
  pay_time = time() + 604800;
  THIS->force_us("drop drill");
  THOB->set_no_get(1);
  return 1;
  }
  else
  {
   write("You can't drill\n");
   return 1;
  }
}
do_check()
{
  if(drilled)
  {
    write("You check the pay meter on the drill.\n");
    write("It reads: ");
    write("There are approximately "+(pay_time-time())/3600+"h until this "+
    "drill is useless.\n");
    return 1;
  }
  else
  {
    write("You can't check the drill.\n");
    return 1;
  }
}
do_irrigate()
{
  if(drilled){
  if(time() >= pay_time) {
    write(wrap("You turn the nozzel on the drill and it explodes into a "+
    "thousand pieces.\n"));
    message("0",THIS->query_cap_name()+" turns the nozzel on the water "+
    "drill and it explodes into a thousand pieces.\n",ENV(THIS),THIS);
    destruct(THOB);
    return 1;
  }
  write("You open the nozzel on the drill.\n");
  message("0",THIS->query_cap_name()+" turns a nozzel on the water drill.\n"
  ,ENV(THIS),THIS);
  ENV(THIS)->do_irrigate();
  return 1;
 }
 else
 {
   write("You can't irrigate.\n");
   return 1;
 }
}  
