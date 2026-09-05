inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You point at yourself, as if saying, 'You talkin' 'bout me?'$N$\n", "#MN# points at #MO#self, as if saying 'You talkin' 'bout me?'$N$\n");
       target("You point at #TN#.$N$\n", "#MN# points at #TN#.$N$\n", "#MN# points at you.$N$\n");
       afar("You point at #TN# from afar.$N$\n", "#MN# points at you from afar.$N$\n");
    }
}

int
cmd_point(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
