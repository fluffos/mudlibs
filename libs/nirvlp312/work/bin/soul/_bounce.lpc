inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("B O I N G!$N$\n", "#MN# bounces around the room.$N$\n");
       target("You bounce around #TN#.$N$\n", "#MN# bounces around #TN#.$N$\n", "#MN# bounces around you.$N$\n");
       afar("You bounce around #TN# from afar.$N$\n", "#MN# bounces around you from afar.$N$\n");
    }
}

int
cmd_bounce(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
