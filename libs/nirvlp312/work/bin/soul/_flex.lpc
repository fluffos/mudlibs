inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You flex your muscles, impressing those around you.$N$\n", "#MN# tries to impress you by flexing.$N$\n");
       target("You flex your muscles at #TN#, trying to impress #TO#.$N$\n", "#MN# flexes #MP# muscles at #TN#, trying to impress #TO#.$N$\n", "#MN# flexes #MP# muscles at you, trying to impress you.$N$\n");
       afar("You flex your muscles at #TN# from afar, trying to impress #TO#.$N$\n", "#MN# flexes #MP# muscles at you from afar, trying to impress you.$N$\n");
    }
}

int
cmd_flex(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
