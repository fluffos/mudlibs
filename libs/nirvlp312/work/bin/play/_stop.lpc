int cmd_stop(string arg) {
  object hunted;
  if(arg != "hunting" && arg != "hunt"){
    notify_fail("Stop what?\nType 'stop hunting' to stop hunting.\n");
    return 0;
  }
  if (!(hunted=(object)this_player()->query_hunted())) {
    write("You are not hunting anyone.\n");
  	return 1;
  }
  hunted->stop_hunter();
  this_player()->set_hunted(0);
  write("Ok.\n");
  return 1;
}
