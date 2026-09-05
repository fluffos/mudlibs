inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You beg like a dog. Arf!$N$\n", "#MN# begs like a dog!$N$\n");
       target("You beg #TN# like a dog!$N$\n", "#MN# begs #TN# like a dog!$N$\n", "#MN# begs you like a dog!$N$\n");
       afar("You beg #TN# like a dog from afar!#RET#Have SOME pride!$N$\n", "#MN# begs you like a dog from afar!#RET##CMS# ain't too proud to beg!$N$\n");
    }
}

int
cmd_beg(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
