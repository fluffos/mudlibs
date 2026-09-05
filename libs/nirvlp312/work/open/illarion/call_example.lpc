inherit "/room/room";

void reset(status arg) {
  if(arg) return;

  set_light(1);
  
  short_desc="An example room";
  long_desc="Type start to start the call_out chain.\n"+
      "Type stop at any time to interrupt the chain.\n";
}

void init() {
  ::init();
  add_action("cmd_start","start");
  add_action("cmd_stop","stop");
}

int cmd_start() {
  write("You start the call_out chain.\n");
  say(this_player()->query_name()+" starts the call_out chain.\n");
  call_out("chain_one",3,this_player());
  return 1;
}

/* in call_out, this_player() does not exist, so you cannot use write
   or say
   */
void chain_one(object starter) {
  tell_object(starter,"The first function in the call_out chain has been triggered.\n");
  tell_room(this_object(),starter->query_name()+"'s first function has been triggered.\n");
  call_out("chain_two",3,starter);
  call_out("chain_three",6,starter);
}

void chain_two(object starter) {
  tell_object(starter,"This is the first branch from chain_one.\n");
  call_out("chain_four",10,starter);
}

void chain_three(object starter) {
  tell_object(starter,"This is the second branch from chain_one.\n");
  remove_call_out("chain_four");
  tell_object(starter,"It just removed the call_out to chain_four.\n");
  call_out("chain_four",4,starter);
}

void chain_four(object starter) {
  tell_object(starter,"This is chain_four.  It was called out twice, but chain_three\n"+
      "removed one of those call_outs.\n"+
      "It's now going to start over again at chain_one.\n");
  call_out("chain_one",3,starter);
}

int cmd_stop() {
  remove_call_out("chain_one");
  remove_call_out("chain_two");
  remove_call_out("chain_three");
  remove_call_out("chain_four");
  write("All call_outs removed.\n");
  return 1;
}
  
