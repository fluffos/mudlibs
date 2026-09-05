inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You lust for yourself.$N$\n", "#MN# lusts for #MO#self.#RET#Uh...what is wrong with this picture??$N$\n");
       target("You lust for #TN#.$N$\n", "#MN# lusts for #TN#.$N$\n", "#MN# lusts for you.$N$\n");
       afar("You lust for #TN# from afar.$N$\n", "#MN# lusts for you from afar.$N$\n");
    }
}

int
cmd_lust(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
