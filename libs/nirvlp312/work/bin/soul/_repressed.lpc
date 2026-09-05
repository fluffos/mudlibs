inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You shout, \"Come and see the violence inherent in the system! Help! Help! I'm being repressed!\"\n", "$MN$ shouts, \"Come and see the violence inherent in the system! Help! Help! I'm being repressed!\n");
       target("You yell, \"Oh, what a give-away. Did you hear that? Did you hear that, eh? That's what I'm on about. Did you see $TN$ repressing me? You saw it, didn't you?\"\n", "$MN$ yells, \"Oh, what a give-away. Did you hear that? Did you hear that, eh? That's what I'm on about. Did you see $TN$ repressing me? You saw it, didn't you?\"\n", "$MN$ yells, \"Oh, what a give-away. Did you hear that? Did you hear that, eh? That's what I'm on about. Did you see $TN$ repressing me? You saw it, didn't you?\"\n");
       afar("From afar, you cry to $TN$, \"Help! Help! I'm being repressed!\"$N$\n", "From afar, $MN$ cries to you, \"Help! Help! I'm being repressed!\"$N$\n");
    }
}

int
cmd_repressed(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "illarion"; }
