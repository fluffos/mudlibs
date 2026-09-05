inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You look around for somebody to teabag.\n", "#MN# looks around the room for somebody to teabag.\n");
       target("You knock #TN# out, drop your pants, and begin to dip your balls on and off of #TN#'s face.\n", "#MN# knocks #TN# out, drops their pants, and begins to dip their balls on and off of #TN#'s face.\n", "#MN# knocks you out, drops their pants, and begins to dip their balls on and off of your face.\n");
       afar("You run into the room, knock #TN# out, and begin to dip your balls on and off of #TN#'s face.\n", "#MN# runs into the room, knocks you out, and begins to dip their balls on and off of your face.\n");
    }
}

int
cmd_tbag(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "shinshi"; }
