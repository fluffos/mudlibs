inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You wiggle sexily around the room!$N$\n", "#MN# wiggles sexily around the room!$N$\n");
       target("You wiggle sexily all over #TN#'s body!$N$\n", "#MN# wiggles sexily all over #TN#'s body!$N$\n", "#MN# wiggles sexily all over your body!$N$\n");
       afar("0$N$\n", "0$N$\n");
    }
}

int
cmd_swiggle(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "stardream"; }
