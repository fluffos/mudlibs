inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You shout: $HR$NO$N$!$N$\n", "#MN# shouts: $HR$NO$N$!$N$\n");
       target("You shout at #TN#: $HR$NO$N$!$N$\n", "#MN# shouts at #TN#: $HR$NO$N$!$N$\n", "#MN# shouts at you: $HR$NO$N$!$N$\n");
       afar("You shout at #TN# from afar: $HR$NO$N$!$N$\n", "#MN# shouts at you from afar: $HR$NO$N$!$N$\n");
    }
}

int
cmd_no(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
