inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You dream of better days.$N$\n", "#MN# daydreams.$N$\n");
       target("You daydream about #TN#.$N$\n", "#MN# daydreams about #TN#.$N$\n", "#MN# daydreams about you.$N$\n");
       afar("You daydream about #TN# from afar.#RET##CTS# is SO dreamy!$N$\n", "#MN# daydreams about you from afar.#RET##CMS# thinks you are SO dreamy!$N$\n");
    }
}

int
cmd_daydream(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
