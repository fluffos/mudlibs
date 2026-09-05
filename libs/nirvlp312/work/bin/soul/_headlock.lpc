inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You put yourself in a headlock.$N$\n", "#MN# puts #MO# in a headlock.$N$\n");
       target("You put #TN# in a headlock.$N$\n", "#MN# puts #TN# in a headlock.$N$\n", "#MN# puts you in a headlock.$N$\n");
       afar("You put #TN# in a headlock from afar.#RET##CTS# is going down!\n", "#MN# puts you in a headlock from afar.#RET#You're going down!$N$\n");
    }
}

int
cmd_headlock(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "illarion"; }
