inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("All of a sudden, you black out!\n", "#MN# faints, falling to the ground!\n");
       target("All of a sudden, you black out!\n", "#MN# faints into #TN#'s arms!\n", "#MN# faints, falling into your arms!\n");
       afar("All of a sudden, you black out!\n", "#MN# faints into your arms from afar!\n");
    }
}

int
cmd_faint(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }
