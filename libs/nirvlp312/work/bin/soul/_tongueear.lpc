inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("Your tongue leaps out and licks your own ear, then darts back inside your mouth\n", "#MN# licks #MP# own ear\n");
       target("You stick your tongue in #TN#'s ear\n", "#MN# sticks #MP# tongue in #TN#'s ear\n", "#MN# sticks #MP# tongue in your ear\n");
       afar("Your tongue extends quite a distance to stick in #TN#'s ear from afar\n", "#MN#'s tongue ends up in your ear from afar.  And you are confused\n");
    }
}

int
cmd_tongueear(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "illarion"; }
