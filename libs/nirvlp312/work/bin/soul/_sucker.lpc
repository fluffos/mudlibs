inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You try foolishly to sucker punch yourself!$N$\n", "#MN# tries foolishly to sucker punch #MO#self!$N$\n");
       target("Pointing to the sky, you get #TN# to look up and you sucker punch 'em in the stomach!$N$\n", "#MN# points to the sky, causing #TN# to look up. #MN# just sucker punched #TN# in the stomach!$N$\n", "#MN# points to the sky, causing you to look up...#MN# just sucker punched you!$N$\n");
       afar("From afar, You point to the sky, causing #TN# to look up and you sucker punch 'em in the stomach!$N$\n", "From afar, #MN# points to the sky, causing you to look up...#RET##CMN# just sucker punched you in the stomach!$N$\n");
    }
}

int
cmd_sucker(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
