inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You clench your fists and throw your head back.#RET#At the top of your lungs, you scream, \"$HC$FRACK!$N$\"$N$\n", "#CMN# clenches #MP# fists and throws #MP# head back.#RET#At the top of #MP# lungs, #MS# screams, \"$HC$FRACK!$N$\"$N$\n");
       target("You clench your fists and throw your head back.#RET#At the top of your lungs, you look at #CTN# and scream, \"$HC$FRACK!$N$\"$N$\n", "#CMN# clenches #MP# fists and throws #MP# head back.#RET#At the top of #MP# lungs, #MS# looks at #CTN# and screams, \"$HC$FRACK!$N$\"$N$\n", "#CMN# clenches #MP# fists and throws #MP# head back.#RET#At the top of #MP# lungs, #MS# looks at you and screams, \"$HC$FRACK!$N$\"$N$\n");
       afar("$HW$[$HY$afar$HW$]$N$ You clench your fists and throw your head back.#RET#At the top of your lungs, you look at #CTN# and scream, \"$HC$FRACK!$N$\"$N$\n", "$HW$[$HY$afar$HW$]$N$ #CMN# clenches #MP# fists and throws #MP# head back.#RET#At the top of #MP# lungs, #MS# looks at you and screams, \"$HC$FRACK!$N$\"$N$\n");
    }
}

int
cmd_frack(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "forbin"; }
