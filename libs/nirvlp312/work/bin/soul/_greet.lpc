inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You greet everyone.$N$\n", "#MN# greets everyone.$N$\n");
       target("You greet #TN#.$N$\n", "#MN# greets #TN#.$N$\n", "#MN# greets you.$N$\n");
       afar("You greet #TN# from afar.$N$\n", "#MN# greets you from afar.$N$\n");
    }
}

int
cmd_greet(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
