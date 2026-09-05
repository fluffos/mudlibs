inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You jokingly wink.$N$\n", "#MN# jokingly winks. $N$\n");
       target("You jokingly wink at #TN#.$N$\n", "#MN# jokingly winks at #TN#.$N$\n", "#MN# jokingly winks at you. $N$\n");
       afar("You jokingly wink at #TN# from afar.$N$\n", "#MN# jokingly winks at you from afar.$N$\n");
    }
}

int
cmd_wink2(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "fred"; }
