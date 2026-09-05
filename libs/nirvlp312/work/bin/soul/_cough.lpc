inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You cough noisily.#RET# Cover your mouth when you do that!$N$\n", "#MN# coughs noisily.$N$\n");
       target("You cough noisily at #TN#.$N$\n", "#MN# coughs noisily at #TN#.$N$\n", "#MN# coughs noisily at you.$N$\n");
       afar("You cough noisily at #TN# from afar.$N$\n", "#MN# coughs noisily at you from afar.$N$\n");
    }
}

int
cmd_cough(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
