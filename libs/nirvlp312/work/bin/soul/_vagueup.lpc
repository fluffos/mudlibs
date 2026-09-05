inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("Shaking your head, you ask, \"Could you vague that up for me?\"$N$\n", "Shaking #MP# head, #CMN# asks, \"Could you vague that up for me?\"$N$\n");
       target("Shaking your head, you ask, \"Could you vague that up for me, #TN#?\"$N$\n", "Shaking #MP# head, #CMN# asks, \"Could you vague that up for me, #CTN#?\"$N$\n", "Shaking #MP# head, #CMN# asks, \"Could you vague that up for me, #CTN#?\"$N$\n");
       afar("[afar] Shaking your head, you ask, \"Could you vague that up for me, #TN#?\"$N$\n", "[afar] Shaking #MP# head, #CMN# asks, \"Could you vague that up for me, #CTN#?\"$N$\n");
    }
}

int
cmd_vagueup(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "forbin"; }
