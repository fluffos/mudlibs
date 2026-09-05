inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You are so manly.$N$\n", "#CMN# acts manly for your amusement.$N$\n");
       target("You run your hands through #CTN#'s thick chest hair and whisper huskily, \"You are so MANLY!\"$N$\n", "#CMN# runs #MP# hands through #CTN#'s thick chest hair and whispers huskily, \"You are so MANLY!\"$N$\n", "#CMN# runs #MP# hands through your thick chest hair and whispers huskily, \"You are so MANLY!\"$N$\n");
       afar("$HK$[afar]$N$ You run your hands through #CTN#'s thick chest hair and whisper huskily, \"You are so MANLY!\" - WTF?!$N$\n", "$HK$[afar]$N$ #CMN# runs #MP# hands through your thick chest hair and whispers huskily, \"You are so MANLY!\" - Whatta freak!$N$\n");
    }
}

int
cmd_manly(string arg)
{
  if(arg=="x" || arg =="vertebraker"){
   write("You suck.\n");
  return 1;
}
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "khrell"; }
