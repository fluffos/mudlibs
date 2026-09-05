inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You chuckle politely.$N$\n", "#MN# chuckles politely.$N$\n");
       target("You chuckle at #TN#.$N$\n", "#MN# chuckles at #TN#.$N$\n", "#MN# chuckles at you.$N$\n");
       afar("You chuckle at #TN# from afar.$N$\n", "#MN# chuckles at you from afar.$N$\n");
    }
}

int
cmd_chuckle(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
