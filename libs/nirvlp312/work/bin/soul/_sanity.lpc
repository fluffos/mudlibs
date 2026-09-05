inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You're concerned about the sanity of the room.\n", "#MN# is concerned about the sanity of the room.\n");
       target("You seem concerned about #TN#'s sanity.\n", "#MN# seems concerned about #TN#'s sanity.\n", "#MN# seems concerned about your sanity.\n");
       afar("You seem concerned about #TN#'s sanity from afar.\n", "#MN# seems concerned about your sanity from afar.\n");
    }
}

int
cmd_sanity(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }
