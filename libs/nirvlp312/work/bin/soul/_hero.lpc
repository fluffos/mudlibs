inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You look over everyone in the room, trying to find a hero.\n", "#MN# looks over the room, searching for a hero.\n");
       target("You jump into #TN#'s arms and proclaim, \"My Hero!\"\n", "#MN# jumps into #TN#'s arms and proclaims, \"My Hero!\"\n", "#MN# jumps into your arms and proclaims, \"My Hero!\"\n");
       afar("You search far and wide for your hero.\n", "#MN# searches in your direction for a hero.\n");
    }
}

int
cmd_hero(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }
