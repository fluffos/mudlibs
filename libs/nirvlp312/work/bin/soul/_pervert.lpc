inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You feel this room is full of perverts.\n", "#MN# thinks the room is a bunch of perverts.\n");
       target("You point at #TN# and shout, \"$HR$YOU PERVERT!$N$\"\n", "#MN# points at #TN# and shouts, \"$HR$YOU PERVERT!$N$\"\n", "#MN# points at you and shouts, \"$HR$YOU PERVERT!$N$\"\n");
       afar("You point at #TN# from afar and shout, \"$HR$YOU PERVERT!$N$\"\n", "#MN# points at you from afar and shouts, \"$HR$YOU PERVERT!$N$\"\n");
    }
}

int
cmd_pervert(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
