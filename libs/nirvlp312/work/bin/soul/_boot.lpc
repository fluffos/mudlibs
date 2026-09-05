inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You boot yourself in the head.... IT HURTS!$N$\n", "#MN# boots #MO#self in the head.... Dumbass.$N$\n");
       target("You boot #TN# in #TP# head... hahahaha$N$\n", "#MN# boots #TN# in #TP# head.... OW!$N$\n", "#MN# boots you in your head.... IT HURTS!$N$\n");
       afar("You kick up your heels at #TN# from afar.#RET#Ha Ha!$N$\n", "#MN# kicks up #MP# heels at you from afar.#RET#Ha Ha!$N$\n");
    }
}

int
cmd_boot(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
