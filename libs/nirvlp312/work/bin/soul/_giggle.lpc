inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You giggle inanely.$N$\n", "#MN# giggles inanely.$N$\n");
       target("You giggle at #TN#.$N$\n", "#MN# giggles at #TN#.$N$\n", "#MN# giggles at you.$N$\n");
       afar("You giggle at #TN# from afar.$N$\n", "#MN# giggles at you from afar.$N$\n");
    }
}

int
cmd_giggle(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
