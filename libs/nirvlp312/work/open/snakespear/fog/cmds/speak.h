int fraternizing;
do_speak(str) {
  notify_fail("Speak what?\n");
  if(!str) { return 0; }
  if(str=="fogese") {
    fraternizing=1;
    write("You decide to fraternize with your brothers.\n");
    return 1;
  }
  if(str=="common") {
    fraternizing=0;
    write("You decide to speak the common language.\n");
    return 1;
  }
}
query_language() {
  return "fogese";
}
