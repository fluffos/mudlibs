inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You strike a heroic pose, and speak the most terrifying battlecry you know:  $H$SPOON!$N$$N$\n", "#MN# strikes a heroic pose, and emits the silliest battlecry in the world:  $H$SPOON!$N$$N$\n");
       target("You fix #TN# with a stern glare, and yell:  $H$SPOON!$N$$N$\n", "#MN# fixes #TN# with a stern glare, and yells:  $H$SPOON!$N$$N$\n", "#MN# fixes you with a stern glare, and yells:  $H$SPOON!$N$$N$\n");
       afar("Confident that the evildoer will hear you and tremble no matter, the distance, you think of #TN# and yell $H$SPOON!$N$$N$\n", "From impossibly far away, you hear #MN# yell: $H$SPOON!$N$$N$\n");
    }
}

int
cmd_spoon(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "illarion"; }
