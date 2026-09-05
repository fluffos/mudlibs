inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You twiddle your thumbs.$N$\n", "#MN# twiddles #MP# thumbs.$N$\n");
       target("You twiddle your thumbs at #TN#.$N$\n", "#MN# twiddles #MP# thumbs at #TN#.$N$\n", "#MN# twiddles #MP# thumbs at you.$N$\n");
       afar("You twiddle your thumbs at #TN# from afar.$N$\n", "#MN# twiddles #MP# thumbs at you from afar.$N$\n");
    }
}

int
cmd_twiddle(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
