inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You say: hmm...$N$\n", "#MN# says: hmm...$N$\n");
       target("You say: hmm... to #TN#$N$\n", "#MN# says: hmm... to #TN#.$N$\n", "#MN# says: hmm... to you.$N$\n");
       afar("You say: hmm... to #TN# from afar.$N$\n", "#MN# says: hmm... to you from afar.$N$\n");
    }
}

int
cmd_hmm(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
