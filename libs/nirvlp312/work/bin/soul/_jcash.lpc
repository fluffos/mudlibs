inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You shake your head like Johnny Cash.\n", "#MN# shakes #MP# head like Johnny Cash.\n");
       target("You shake your head at #TN# like Johnny Cash.\n", "#MN# shakes #MP# head at #TN# like Johnny Cash.\n", "#MN# shakes #MP# head at you like Johnny Cash.\n");
       afar("You shake your head at #TN# like Johnny Cash from afar.\n", "#MN# shakes #MP# head at you like Johnny Cash from afar.\n");
    }
}

int
cmd_jcash(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "x"; }
