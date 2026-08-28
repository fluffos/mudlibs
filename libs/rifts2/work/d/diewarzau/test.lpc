void test_me() {
  mapping ack = ([ "idx1" : "val1", "idx2" : "val2", "idx3" : "val3" ]);
  string val, idx;

  foreach(idx, val in ack) {
    if(val == "val3") val = "change";
  }
  write(sprintf("%O", ack));
  return;
}
