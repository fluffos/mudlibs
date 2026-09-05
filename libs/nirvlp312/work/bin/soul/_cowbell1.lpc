inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You say, \"I'm telling you, fellas...#RET#you're going to want that cowbell on the track!\"$N$\n", "#MN# says, \"I'm telling you, fellas...#RET#you're going to want that cowbell on the track!\"$N$\n");
       target("You say, \"I'm telling you, #TN#...#RET#you're going to want that cowbell on the track!\"$N$\n", "#MN# says, \"I'm telling you, #TN#...#RET#you're going to want that cowbell on the track!\"$N$\n", "#MN# says, \"I'm tell you...#RET#you're going to want that cowbell on the track!\"$N$\n");
       afar("[afar] You yell, \"I'm telling you, #TN#...#RET#you're going to want that cowbell on the track!\"$N$\n", "#MN# yells, \"I'm telling you...#RET#you're going to want that cowbell on the track!\"$N$\n");
    }
}

int
cmd_cowbell1(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "fred"; }
