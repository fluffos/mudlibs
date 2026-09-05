inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You say, \"Whoa.\"$N$\n", "#MN# says, \"Whoa.\"$N$\n");
       target("You point at #TN# and say, \"Whoa.\"$N$\n", "#MN# points at #TN# and says, \"Whoa.\"$N$\n", "#MN# points at you and says, \"Whoa.\"$N$\n");
       afar("You point at #TN# from afar and say, \"Whoa.\"$N$\n", "#MN# points at you from afar and says, \"Whoa.\"$N$\n");
    }
}

int
cmd_whoa(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
