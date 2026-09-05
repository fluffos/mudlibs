inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You announce: \"O'DOYLE RULES!\"$N$\n", "#MN# announces: \"O'DOYLE RULES!\"$N$\n");
       target("You announce to #TN#: \"O'DOYLE RULES!\"$N$\n", "#MN# announces to #TN#: \"O'DOYLE RULES!\"$N$\n", "#MN# announces to you: \"O'DOYLE RULES!\"$N$\n");
       afar("You announce to #TN# from afar: \"O'DOYLE RULES!\"$N$\n", "#MN# announces to you from afar: \"O'DOYLE RULES!\"$N$\n");
    }
}

int
cmd_odoyle(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
