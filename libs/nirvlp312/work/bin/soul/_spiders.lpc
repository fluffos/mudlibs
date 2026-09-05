inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You dump a bucket of spiders on the ground.\n", "#MN# dumps a bucket of spiders on the ground.\n");
       target("You dump a bucket of spiders on #TN#.\n", "#MN# dumps a bucket of spiders on #TN#.\n", "#MN# dumps a bucket of spiders on you.\n");
       afar("You somehow manage to dump a bucket of spiders on #TN# from afar.\n", "#MN# somehow manages to dump a bucket of spiders on you from afar.\n");
    }
}

int
cmd_spiders(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }
