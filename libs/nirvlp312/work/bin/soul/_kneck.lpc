inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You kiss your neck passionately!$N$\n", "#MN# kisses #MP# neck passionately!$N$\n");
       target("You kiss #TN#'s neck passionately!$N$\n", "#MN# kisses #TN#'s neck passionately!$N$\n", "#MN# kisses your neck passionately!$N$\n");
       afar("You kiss #TN#'s neck passionately from afar.#RET#How good are you?$N$\n", "#MN# kisses your neck passionately from afar.#RET#How good is #MS#?$N$\n");
    }
}

int
cmd_kneck(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
