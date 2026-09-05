inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("Thwack who?\n", "#MN# looks confused.\n");
       target("You thwack #TN# on the back of #TP# head.\n", "#MN# thwacks #TN# on the back of #TP# head.\n", "#MN# thwacks you on the back of your head! (ouch)\n");
       afar("You thwack #TN# on the back of #TP# head from afar.\n", "#MN# thwacks you on the back of your head from afar! (ouch)\n");
    }
}

int
cmd_thwack(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }
