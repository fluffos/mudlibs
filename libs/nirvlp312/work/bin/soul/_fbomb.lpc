inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You go: $HR$FBOMB$N$!\n", "#MN# goes: $HR$FBOMB$N$!\n");
       target("You drop the $HR$FBOMB$N$ on #TN#!\n", "#MN# drops the $HR$FBOMB$N$ on #TN#!\n", "#MN# drops the $HR$FBOMB$N$ on you!\n");
       afar("You drop the $HR$FBOMB$N$ on #TN# from afar!\n", "#MN# drops the $HR$FBOMB$N$ on you from afar!\n");
    }
}

int
cmd_fbomb(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "quicksilver"; }
