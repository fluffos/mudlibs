inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You look around for someone to pounce on.$N$\n", "#MN# looks around for someone to pounce on.$N$\n");
       target("You yell, \"RAWR!\", and pounce on #TN#.$N$\n", "#MN# yells, \"RAWR!\", and pounces on #TN#.$N$\n", "#MN# yells, \"RAWR!\", and pounces on you.$N$\n");
       afar("You yell, \"RAWR!\", and pounce on #TN# from afar.$N$\n", "#MN# yells, \"RAWR!\", and pounces on you from afar.$N$\n");
    }
}

int
cmd_pounce(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "fred"; }
