inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You pant.\n", "#MN# pants.\n");
       target("You pant at #TN#.\n", "#MN# pants at #TN#.\n", "#MN# pants at you.\n");
       afar("You pant at #TN# from afar.\n", "#MN# pants at you from afar.\n");
    }
}

int
cmd_pant(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }
