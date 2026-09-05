inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You peer at everyone in the room quizzically.$N$\n", "#MN# peers at everyone in the room quizzically.$N$\n");
       target("You peer at #TN# quizzically.$N$\n", "#MN# peers at #TN# quizzically.$N$\n", "#MN# peers at you quizzically.$N$\n");
       afar("From afar, You peer at #TN# quizzically.$N$\n", "From afar, #MN# peers at you quizzically.$N$\n");
    }
}

int
cmd_peer(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
