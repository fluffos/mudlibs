inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You sit down and wait patiently.$N$\n", "#MN# sits down and waits patiently.$N$\n");
       target("You sit down and wait patiently for #TN#.$N$\n", "#MN# sits down and waits patiently for #TN#.$N$\n", "#MN# sits down and waits patiently for you.$N$\n");
       afar("(afar) You sit down and wait patiently for #TN#.$N$\n", "(afar) #MN# sits down and waits patiently for you.$N$\n");
    }
}

int
cmd_sit(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "fred"; }
