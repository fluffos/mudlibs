inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You declare: \"Fuck off..... doc!\"$N$\n", "#MN# declares: \"Fuck off..... doc!\"$N$\n");
       target("You declare to #TN#: \"Fuck off..... doc!\"$N$\n", "#MN# declares to #TN#: \"Fuck off..... doc!\"$N$\n", "#MN# declares to you: \"Fuck off..... doc!\"$N$\n");
       afar("You declare to #TN# from afar: \"Fuck off..... doc!\"$N$\n", "#MN# declares to you from afar: \"Fuck off..... doc!\"$N$\n");
    }
}

int
cmd_fdoc(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
