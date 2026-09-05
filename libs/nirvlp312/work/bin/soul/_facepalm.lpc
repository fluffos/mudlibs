inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You smack your hand against your forehead.$N$\n", "#MN# smacks #MP# hand against #MP# forehead.$N$\n");
       target("You look at #TN#, and smack your hand against your forehead.$N$\n", "#MN# smacks #MP# hand against #MP# forehead while looking at #TN#.$N$\n", "#MN# looks at you, thn smacks #MP# hand against #MP# forehead.\n");
       afar("From afar, you look at #TN#, and smack your hand against your forehead.$N$\n", "From far, #MN# looks at you, thn smacks #MP# hand against #MP# forehead.\n");
    }
}

int
cmd_facepalm(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "illarion"; }
