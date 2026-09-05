inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You give yourself a long, tender massage.$N$\n", "#MN# gives #MO#self a long, tender massage.#RET#WHY!?!?!?$N$\n");
       target("You give #TN# a long, tender massage.$N$\n", "#MN# gives #TN# a long, tender massage.$N$\n", "#MN# gives you a long, tender massage. You feel completely relaxed!$N$\n");
       afar("You give #TN# a long, tender massage from afar.#RET#Work those fingers!$N$\n", "#MN# gives you a long, tender massage from afar.#RET##CMS# lets #MP# fingers do the talking!$N$\n");
    }
}

int
cmd_massage(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
