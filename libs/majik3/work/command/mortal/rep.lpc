string Cmd;

int main (string arg) {
    Cmd = arg;

    if (!arg)
      {
        notify_fail ("usage: rep <command>\n");
        return 0;
      }

    write("Entering 'rep' mode -- type 'rep' again to end:\n");
    if (THIS->query("term") == 5)
      message ("prompt", "^c1"+arg+"^c0 > \n", THIS);
    else
      message ("prompt", "^c1"+arg+"^c0 > ", THIS);
    input_to("repeat_thing", 0, THIS);
    return 1;
}

repeat_thing(string str, object who) {
    if (str != "rep") {
	THIS->force_us(Cmd+" "+str);
        if (THIS->query("term") == 5)
	  message ("prompt", "^c1"+Cmd+"^c0 > \n", THIS);
        else
	  message ("prompt", "^c1"+Cmd+"^c0 > ", THIS);
	input_to("repeat_thing", 0, THIS);
    }
    else
      write("Exiting 'rep' mode.\n");
    return 1;
}

query_author()
{
  return "namhas";
}

query_help()
{
  return "Rep is short for 'repeat'. As the name indicates, you can repeat <string>"
  + " with this command. After starting rep <string> will be the prefix for"
  + " everything you type. To exit rep just type 'rep'.";
}

query_synopsis()
{
  return "rep <string>";
}

query_example()
{
  return"rep tell sinister\n"
  + "\n"
  + "        hello --> tell sinister hello\n"
  + "        foobar --> tell sinister foobar\n"
  + "        rep --> exits rep";
}

query_position ()
{
  return POS_STANDING;
}

