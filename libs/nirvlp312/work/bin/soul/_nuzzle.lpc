inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You attempt to nuzzle yourself...seriously dude...get some help!$N$\n", "#MN# attempts to nuzzle #MP#self...#CMS# has issues.\n");
       target("You bury your face in #TN#'s neck and purr happily.$N$\n", "#MN# buries #MP# face in #TN#'s neck and purrs happily.$N$\n", "#MN# buries #MP# face in your neck and purrs happily.$N$\n");
       afar("From afar, You bury your face in #TN#'s neck and purr happily.$N$\n", "From afar, #MN# buries #MP# face in your neck and purrs happily.$N$\n");
    }
}

int
cmd_nuzzle(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
