inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You noggle enthusiastically.\n", "#MN# noggles enthusiastically.\n");
       target("You noggle enthusiastically at #TN#.\n", "#MN# noggles enthusiastically at #TN#.\n", "#MN# noggles enthusiastically at you.\n");
       afar("You noggle enthusiastically at #TN# from afar.\n", "#MN# noggles enthusiastically at you from afar.\n");
    }
}

int
cmd_noggle(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
