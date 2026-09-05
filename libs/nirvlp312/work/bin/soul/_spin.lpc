inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("Spin who?\n", "#MN# looks confused.\n");
       target("You spin #TN# around in tight circles.\n", "#MN# spins #TN# around in tight circles.\n", "#MN# grabs your hand and spins you around in tight circles.\n");
       afar("You spin #TN# in tight circles from afar.\n", "#MN# grabs your hand and spins you around in tight circles from afar.\n");
    }
}

int
cmd_spin(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }
