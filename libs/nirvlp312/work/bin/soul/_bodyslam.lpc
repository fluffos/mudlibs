inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You get yourself in a bodyslam position, and then realize you must be retarded.\n", "#MN# is retarded.\n");
       target("You lift #TN# high above your head, and bodyslam #TO# to the ground.\n", "#MN# lifts #TN# above #MP# head and bodyslams #TO# to the ground.\n", "#MN# lifts you above #MP# head and bodyslams you to the ground.\n");
    }
}

int
cmd_bodyslam(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }
