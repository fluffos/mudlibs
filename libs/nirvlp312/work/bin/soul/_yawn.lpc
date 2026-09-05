inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You yawn tiredly.$N$\n", "#MN# yawns tiredly.$N$\n");
       target("You yawn tiredly at #TN#.$N$\n", "#MN# yawns tiredly at #TN#.$N$\n", "#MN# yawns tiredly at you.$N$\n");
       afar("You yawn tiredly at #TN# from afar.$N$\n", "#MN# yawns tiredly at you from afar.$N$\n");
    }
}

int
cmd_yawn(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
