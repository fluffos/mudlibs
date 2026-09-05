inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You shout, \"I gotta have more Cowbell!\"$N$\n", "#MN# shouts, \"I gotta have more Cowbell!\"$N$\n");
       target("You shout at #TN#, \"I gotta have more Cowbell!\"$N$\n", "#MN# shouts at #TN#, \"I gotta have more Cowbell!\"$N$\n", "#MN# shouts at you, \"I gotta have more Cowbell!\"$N$\n");
       afar("[afar] You shout at #TN#, \"I gotta have more Cowbell!\"$N$\n", "[afar] #MN# shouts at you, \"I gotta have more Cowbell!\"$N$\n");
    }
}

int
cmd_cowbell2(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "fred"; }
