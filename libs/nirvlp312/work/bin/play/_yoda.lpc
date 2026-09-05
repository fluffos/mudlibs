string saved_punc;

string translate_to_formal_speech(string arg)
{
  int punc, punc_let;

  punc = strlen(arg)-1;
  punc_let=arg[punc];

  if(punc_let != '.' && punc_let != '!' && punc_let != '?' && !saved_punc)
    arg += ".";
  else if(saved_punc)
    arg += saved_punc;

  if(arg[strlen(arg)-1] == '!')
    arg += " Mmm? Mmm?";
  else if(!random(9))
    arg += " .. yes?";
  else if(!random(9))
    arg += " .. mm?";
  else if(!random(9))
    arg += " .. hmm?";
  else if(!random(9))
    arg += " .. eh!";

  return capitalize(arg);
}

int cmd_yoda(string arg)
{
  int chance;
  saved_punc=0;
  if(!arg)
    return (notify_fail("Yodinize what?\n"), 0);
  else
  {
    string  x, y, z;
    object  me;
    write("Yodinated.\n");

    me = this_player();
    if(sscanf(arg, "%s, %s %s", x, y, z) == 3)
    {
      y = lower_case(y);
      command("say " + translate_to_formal_speech(arg), me);
      return 1;
    }
    if(sscanf(arg, "%s %s %s", x, y, z) < 3)
    {
      command("say " + translate_to_formal_speech(arg), me);
      return 1;
    }
    else
    {
      string p;

      p = z[strlen(z)-1..strlen(z)-1];

      if(p == "." || p == "?" || p == "!")
        saved_punc=p;
      if((strlen(z) > 1) && saved_punc)
        z = z[0..strlen(z)-2];
      arg = z + ", " + lower_case(x) + " " + y;
      command("say " + translate_to_formal_speech(arg), me);
      return 1;
    }
  }
}
