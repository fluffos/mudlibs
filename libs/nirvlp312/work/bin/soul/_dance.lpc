inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You do the disco duck.#RET#Feels silly, doesn't it?$N$\n", "#MN# does the disco duck.$N$\n");
       target("You sweep #TN# across the dance floor.\n", "#MN# sweeps #TN# across the dance floor.\n", "#MN# sweeps you across the dance floor.\n");
       afar("You sweep #TN# across the dance floor from afar.\n", "#MN# sweeps you across the dance floor from afar.\n");
    }
}

int
cmd_dance(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
