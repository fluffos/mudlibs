inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You do a little jig.$N$\n", "#MN# does a little jig.$N$\n");
       target("You do a little jig for #TN#.$N$\n", "#MN# does a little jig for #TN#.$N$\n", "#MN# does a little jig for you.$N$\n");
       afar("You do a little jig for #TN# from afar.$N$\n", "#MN# does a little jig for you from afar.$N$\n");
    }
}

int
cmd_jig(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
