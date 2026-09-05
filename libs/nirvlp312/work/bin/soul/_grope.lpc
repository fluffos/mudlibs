inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You grope yourself.$N$\n", "#MN# gropes #MO#self.$N$\n");
       target("You grope #TN#.#RET#<Well, what sort of noise do you expect here?!>$N$\n", "#MN# gropes #TN#.$N$\n", "#MN# gropes you.$N$\n");
       afar("You grope #TN# from afar.#RET#<Well, what sort of noise do you expect here?!>$N$\n", "#MN# gropes you from afar.$N$\n");
    }
}

int
cmd_grope(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
