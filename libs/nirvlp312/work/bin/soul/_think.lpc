inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You think carefully.$N$\n", "#MN# thinks carefully.$N$\n");
       target("You think carefully at #TN#.$N$\n", "#MN# thinks carefully at #TN#.$N$\n", "#MN# thinks carefully at you.$N$\n");
       afar("You think carefully at #TN# from afar.$N$\n", "#MN# thinks carefully at you from afar.$N$\n");
    }
}

int
cmd_think(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
