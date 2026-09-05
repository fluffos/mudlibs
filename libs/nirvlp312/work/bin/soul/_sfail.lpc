inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You say, \"OOOh, Shinshi FAIL!\"$N$\n", "#MN# says, \"OOOh, Shinshi FAIL!\"$N$\n");
       target("You look at #TN# and say, \"OOOh, Shinshi FAIL!\"$N$\n", "#MN# looks at #TN# and says, \"OOOh, Shinshi FAIL!\"$N$\n", "#MN# looks at you and says, \"OOOh, Shinshi FAIL!\"$N$\n");
       afar("[afar] You yell at #TN#, \"OOOh, Shinshi FAIL!\"$N$\n", "[afar] #MN# yells at you, \"OOOh, Shinshi FAIL!\"$N$\n");
    }
}

int
cmd_sfail(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "fred"; }
