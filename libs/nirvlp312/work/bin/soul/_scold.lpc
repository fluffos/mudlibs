inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You scold everyone. What a prick!$N$\n", "#MN# scolds everyone! What a prick!$N$\n");
       target("You scold #TN#. You are such a prick!$N$\n", "#MN# scolds #TN#. What a prick!$N$\n", "#MN# scolds you! What a prick!$N$\n");
       afar("You scold #TN# from afar.#RET#You are the biggest prick!$N$\n", "#MN# scolds you from afar!$N$\n");
    }
}

int
cmd_scold(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
