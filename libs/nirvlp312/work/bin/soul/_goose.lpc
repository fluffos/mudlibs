inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You goose yourself!$N$\n", "#MN# gooses #MO#self.$N$\n");
       target("You sneak up behind #TN# and goose #TO#!$N$\n", "#MN# sneaks up behind #TN# and gooses #TO#!$N$\n", "#MN# sneaks up behind you and gooses you!$N$\n");
       afar("You goose #TN# from afar.#RET# Ooh...it's squidgy!$N$\n", "#MN# gooses you from afar.#RET#Yeah baby!$N$\n");
    }
}

int
cmd_goose(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
