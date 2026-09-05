inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You feel hungry.\n", "#MN# looks hungry.\n");
       target("You look at #TN# hungrily.\n", "#MN# looks at #TN# hungrily.\n", "#MN# looks at you hungrily.\n");
       afar("You look at #TN# hungrily from afar.\n", "#MN# looks at you hungrily from afar.\n");
    }
}

int
cmd_hungry(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }
