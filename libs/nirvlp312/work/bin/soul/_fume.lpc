inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You fume angrily.#RET#You'll get over it.$N$\n", "#MN# fumes angrily.$N$\n");
       target("You fume angrily at #TN#.$N$\n", "#MN# fumes angrily at #TN#.$N$\n", "#MN# fumes angrily at you.$N$\n");
       afar("You fume angrily at #TN# from afar.$N$\n", "#MN# fumes angrily at you from afar.$N$\n");
    }
}

int
cmd_fume(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
