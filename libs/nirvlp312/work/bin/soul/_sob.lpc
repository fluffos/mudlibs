inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You sob inconsolably.\n", "#MN# sobs inconsolably.\n");
       target("You sob inconsolably at #TN#.\n", "#MN# sobs inconsolably at #TN#.\n", "#MN# sobs inconsolably at you.\n");
       afar("You sob inconsolably at #TN# from afar.\n", "#MN# sobs inconsolably at you from afar.\n");
    }
}

int
cmd_sob(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }
