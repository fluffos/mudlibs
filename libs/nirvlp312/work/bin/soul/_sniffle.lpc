inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You sniffle.$N$\n", "#MN# sniffles.$N$\n");
       target("You sniffle at #TN#.$N$\n", "#MN# sniffles at #TN#.$N$\n", "#MN# sniffles at you.$N$\n");
       afar("You sniffle at #TN# from afar.$N$\n", "#MN# sniffles at you from afar.$N$\n");
    }
}

int
cmd_sniffle(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
