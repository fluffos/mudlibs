// a test

void start_test() {
  call_out("finish_test", 30, this_player(), "help me!");
  write(sprintf("%O", call_out_info()));
  return;
}

void int_test() {
  remove_call_out("finish_test");
  write(sprintf("%O", call_out_info()));
  return;
}

void finish_test(object who, string str) {
  message("info", "TEST FINISHED!", who);
  message("info", "Test str: "+str, who);
  return;
}

