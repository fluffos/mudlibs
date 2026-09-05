inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You sniff yourself. PeeYew!$N$\n", "#MN# sniffs #MO#self.#RET#Anyone have any deodorant?$N$\n");
       target("You sniff #TN#.$N$\n", "#MN# sniffs #TN#.$N$\n", "#MN# sniffs you.$N$\n");
       afar("You sniff #TN# from afar.$N$\n", "#MN# sniffs you from afar.$N$\n");
    }
}

int
cmd_sniff(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
