inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You yell, \"Lock and load boys, we're goin' in!\"\n", "#MN# yells, \"Lock and load boys, we're goin' in!\"\n");
       target("You yell, \"Lock and load #TN#, we're goin' in!\"\n", "#MN# yells, \"Lock and load #TN#, we're goin' in!\"\n", "#MN# yells at you, \"Lock and load, we're goin' in!\"\n");
    }
}

int
cmd_locknload(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }
