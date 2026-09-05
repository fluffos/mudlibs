inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You are totally disgusted and make a Mr. Yuck face. '$G$YUCK$N$!'$N$\n", "#MN# is totally disgusted and makes a Mr. Yuck face. '$G$YUCK$N$!'$N$\n");
       target("You are totally disgusted with #TN# and make a Mr. Yuck face. '$G$YUCK$N$!'$N$\n", "#MN# is totally disgusted with #TN# and makes a Mr. Yuck face. '$G$YUCK$N$!'$N$\n", "#MN# is totally disgusted with you and makes a Mr. Yuck face. '$G$YUCK$N$!'$N$\n");
       afar("You make a Mr. Yuck face at #TN# from afar. '$G$YUCK$N$!'$N$\n", "#MN# makes a Mr. Yuck face at you from afar. '$G$YUCK$N$!'$N$\n");
    }
}

int
cmd_yuck(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
