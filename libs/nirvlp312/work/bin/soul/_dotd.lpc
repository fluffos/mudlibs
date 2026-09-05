inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You announce: When there's no more room in hell... the DEAD will walk the Earth.$N$\n", "#MN# announces: When there's no more room in hell... the DEAD will walk the Earth.$N$\n");
       target("You announce to #TN#: When there's no more room in hell... the DEAD will walk the Earth.$N$\n", "#MN# announces to #TN#: When there's no more room in hell... the DEAD will walk the Earth.$N$\n", "#MN# announces to you: When there's no more room in hell... the DEAD will walk the Earth.$N$\n");
       afar("You announce to #TN# from afar: When there's no more room in hell... the DEAD will walk the Earth.$N$\n", "#MN# announces to you from afar: When there's no more room in hell... the DEAD will walk the Earth.$N$\n");
    }
}

int
cmd_dotd(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
