inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You proclaim to the world that: You are in the mood!$N$\n", "#MN# appears to be in the mood for romance!$N$\n");
       target("You proclaim to #TN# that you're in the mood for romance!$N$\n", "#MN# proclaims to #TN# that #MS#'s in the mood for romance!$N$\n", "#MN# proclaims to you that #MS#'s in the mood for romance!$N$\n");
       afar("From afar, you proclaim to #TN# that you're in the mood for romance!$N$\n", "From afar, #MN# proclaims to you that #MS#'s in the mood for romance!$N$\n");
    }
}

int
cmd_mood(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "stardream"; }
