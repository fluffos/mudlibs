inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You put a dramatic hand to your forehead and weep.\n", "#MN# puts a dramatic hand to #MP# forehead and weeps.\n");
       target("You put a dramatic hand to your forehead and weep for #TN#.\n", "#MN# puts a dramatic hand to #MP# forehead and weeps for #TN#.\n", "#MN# puts a dramatic hand to #MP# forehead and weeps for you.\n");
       afar("You put a dramatic hand to your forehead and weep for #TN# from afar.\n", "#MN# puts a dramatic hand to #MP# forehead and weeps for you from afar.\n");
    }
}

int
cmd_despair(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }
