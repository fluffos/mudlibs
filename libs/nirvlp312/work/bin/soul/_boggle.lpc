inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You boggle at the concept.$N$\n", "#MN# boggles at the concept.$N$\n");
       target("You boggle at #TN#.$N$\n", "#MN# boggles at #TN#.$N$\n", "#MN# boggles at you.$N$\n");
       afar("You boggle at #TN# from afar.$N$\n", "#MN# boggles at you from afar.$N$\n");
    }
}

int
cmd_boggle(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
