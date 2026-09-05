inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You close your eyes and smile, thinking of a better place.$N$\n", "#MN# closes #MP# eyes and smiles, thinking of a better place.$N$\n");
       target("You think #TN# is dreamy.$N$\n", "#MN# thinks #TN# is dreamy.$N$\n", "#MN# thinks you are dreamy.$N$\n");
       afar("You think #TN# is dreamy... from afar.$N$\n", "#MN# thinks you are dreamy... from afar.$N$\n");
    }
}

int
cmd_dream(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "stardream"; }
