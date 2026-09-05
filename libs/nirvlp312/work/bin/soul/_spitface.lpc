inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("Spit in whose face?\n", "0\n");
       target("You spit in #TN#'s face!\n", "#MN# spits in #TN#'s face!\n", "#MN# spits in your face!\nYou wipe your face off in $HR$anger$N$.\n");
       afar("As you try to spit afar, the wind pushes it back into your face!\n\(Don't spit into the wind)\n", "0\n");
    }
}

int
cmd_spitface(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }
