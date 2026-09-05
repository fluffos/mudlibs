inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You grin mischeviously.\n", "#MN# grins mischeviously.\n");
       target("You grin mischeviously at #TN#.\n", "#MN# grins mischeviously at #TN#.\n", "#MN# grins mischeviously at you.\n");
       afar("You grin mischeviously at #TN# from afar.\n", "#MN# grins mischeviously at you from afar.\n");
    }
}

int
cmd_mgrin(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }
