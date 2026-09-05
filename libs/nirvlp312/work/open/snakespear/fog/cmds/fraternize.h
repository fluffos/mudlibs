do_fraternize() {
  fraternizing=!fraternizing;
  write(fraternizing?"You decide to fraternize with your brothers.\n":"You decide to stop fraternizing.\n");
  return 1;
}
