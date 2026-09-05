inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You shout: SEEYA!$N$\n", "#MN# shouts: SEEYA!$N$\n");
       target("You shout: SEEYA! to #TN#.$N$\n", "#MN# shouts: SEEYA! to #TN#.$N$\n", "#MN# shouts: SEEYA! to you.$N$\n");
       afar("You shout: SEEYA! to #TN# from afar.$N$\n", "#MN# shouts: SEEYA! to you from afar.$N$\n");
    }
}

int
cmd_seeya(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
