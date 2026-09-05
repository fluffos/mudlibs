#include <ansi.h>
inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You go: \"" + BOLD + BLK + "GrooVy" + NORM + ".\"\n", "#MN# goes: \"" + BOLD + BLK + "GrooVy" + NORM + ".\"\n");
       target("You look at #TN# and go: \"" + BOLD + BLK + "GrooVy" + NORM + ".\"\n", "#MN# looks at #TN# and goes: \"" + BOLD + BLK + "GrooVy" + NORM + ".\"\n", "#MN# looks at you and goes: \"" + BOLD + BLK + "GrooVy" + NORM + ".\"\n");
       afar("To #TN# from afar, you go: \"" + BOLD + BLK + "GrooVy" + NORM + ".\"\n", "From afar, #MN# goes: \"" + BOLD + BLK + "GrooVy" + NORM + ".\"\n");
    }
}

int
cmd_groovy(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }
