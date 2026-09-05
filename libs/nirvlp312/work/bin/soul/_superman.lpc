inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You put your fists to your sides, stick out your chest, and look up to the sky.\n", "#MN# puts #MP# fists to #MP# sides, sticks out #MP# chest, and looks up to the sky.\n");
       target("You put your fists to your sides, stick out your chest, and look down at #TN#.\n", "#MN# puts #MP# fists to #MP# sides, sticks out #MP# chest, and looks down at #TN#.\n", "#MN# puts #MP# fists to #MP# sides, sticks out #MP# chest, and looks down at you.\n");
       afar("You put your fists to your sides, stick out your chest, and look down at #TN# from afar.\n", "#MN# puts #MP# fists to #MP# sides, sticks out #MP# chest, and looks down at you from afar.\n");
    }
}

int
cmd_superman(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }
