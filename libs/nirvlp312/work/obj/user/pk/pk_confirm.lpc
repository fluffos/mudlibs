int setting_pk()
{
  write("\n");
  write("You have elected to set your Player Killing flag.\n");
  write("\n");
  write("If you do this, you may attack or be attacked by\n");
  write(" other players at any time.\n");
  write("\n");
  write("Are you sure you wish to set your PK flag?\n");
  write("<y/n> ");
  input_to("confirm_pk");
  return 1;
}

int confirm_pk(string str)
{
  int cpk;
  if(str != "y") {
    write("Wise choice.\n");
    destruct(this_object());
    return 1;
  }
  write("Then spill your enemies' blood thick, warrior.\n");
  this_player()->set_pl_k(1);
  destruct(this_object());
  return 1;
}
