inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You shout: \"YOU'RE WELCOME!\"$N$\n", "#MN# shouts: \"YOU'RE WELCOME!\"$N$\n");
       target("You shout at #TN#: \"YOU'RE WELCOME!\"$N$\n", "#MN# shouts at #TN#: \"YOU'RE WELCOME!\"$N$\n", "#MN# shouts at you: \"YOU'RE WELCOME!\"$N$\n");
       afar("You shout at #TN# from afar: \"YOU'RE WELCOME!\"$N$\n", "#MN# shouts at you from afar: \"YOU'RE WELCOME!\"$N$\n");
    }
}

int
cmd_yw(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
