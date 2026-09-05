inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You shout: 'In Your Face' to the entire room!$N$\n", "#MN# shouts: 'In Your Face' to the entire room!$N$\n");
       target("You shout: In Your Face' to #TN#!$N$\n", "#MN# shouts: 'In Your Face' to #TN#!$N$\n", "#MN# shouts: 'In Your Face' to you!$N$\n");
       afar("You shout at #TN# from afar: 'In Your Face!'$N$\n", "#MN# shouts at you from afar: 'In Your Face!'$N$\n");
    }
}

int
cmd_face(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "stardream"; }
