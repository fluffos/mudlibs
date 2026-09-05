inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You shout: '$G$Jump Around$N$' and begin to dance wildly!$N$\n", "#MN# shouts: '$G$Jump Around$N$' and begins to dance wildly!$N$\n");
       target("0$N$\n", "0$N$\n", "0$N$\n");
       afar("0$N$\n", "0$N$\n");
    }
}

int
cmd_jump(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "stardream"; }
