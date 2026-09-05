object asker_ob;
string asker;

drop() { return 1; }

init() {
  add_action("cmd_askobj","askobj");
}

set_ask(string ask, object ao){
  asker=ask;
  asker_ob=ao;
}


cmd_askobj(str)
{
  write(capitalize(asker)+" wants to add you to their friends list.\n");
  write("Is this ok? <y/n> ");
  input_to("confirm");
  return 1;
}

confirm(str)
{
  if(str=="y") {
    write("Ok!\n");
    tell_object(asker_ob, "Success!\n"+(string)this_player()->query_name()
    +" has been added to your friends list!\n");
    asker_ob->add_friend((string)this_player()->query_real_name());
  }
  else {
    write("Ok, declined.\n");
    tell_object(asker_ob, "Sorry, "+(string)this_player()->query_name()
    +" has declined.\n");
  }
  destruct(this_object());
  return 1;
}
