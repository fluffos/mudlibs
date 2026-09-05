inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You attempt to nibble your own ear...need I say more??$N$\n", "#MN# attempts to nibble #MP# own ear...WTF?$N$\n");
       target("You nibble #TN#'s ear.$N$\n", "#MN# nibbles #TN#'s ear.$N$\n", "#MN# nibbles your ear.$N$\n");
       afar("You nibble #TN#'s ear from afar.$N$\n", "#MN# nibbles your ear from afar.$N$\n");
    }
}

int
cmd_nibble(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
