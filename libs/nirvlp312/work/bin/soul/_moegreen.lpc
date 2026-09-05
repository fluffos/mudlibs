inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You fire a bullet through your glasses, into your eye.#RET#You gave yourself the Moe Green Special!$N$\n", "#MN# fires a bullet through #MP# glasses, into #MP# eye.#RET##MN# gave himself the Moe Green Special!$N$\n");
       target("You fire a bullet into #TN#'s glasses, through #TP# eye.#RET#You gave #TN# the Moe Green Special!$N$\n", "#MN# fires a bullet into #TN#'s glasses, through #TP# eye.#RET##MN# gave #TN# the Moe Green Special!$N$\n", "#MN# fires a bullet into your glasses, through your eye.#RET##MN# gave you the Moe Green Special!$N$\n");
       afar("You fire a bullet at #TN# from afar, but miss.$N$\n", "#MN# fires a bullet at you from afar, but misses.$N$\n");
    }
}

int
cmd_moegreen(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
