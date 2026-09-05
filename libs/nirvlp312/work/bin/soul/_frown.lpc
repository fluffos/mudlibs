inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You frown.#RET#Is something wrong?$N$\n", "#MN# frowns.$N$\n");
       target("You frown at #TN#.$N$\n", "#MN# frowns at #TN#.$N$\n", "#MN# frowns at you.$N$\n");
       afar("You frown at #TN# from afar.$N$\n", "#MN# frowns at you from afar.$N$\n");
    }
}

int
cmd_frown(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
