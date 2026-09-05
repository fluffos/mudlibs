inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You sneak your hands into the back pockets of your jeans and try to kiss yourself. Fool!$N$\n", "#MN# sneaks #MP# hands into the back pockets of #MP# jeans and tries like a fool to kiss #MO#self.$N$\n");
       target("You sneak your hands into the back pockets of #TN#'s jeans, pull #TO# very close and give #TO# a deep, lingering kiss.$N$\n", "#MN# sneaks #MP# hands into the back pockets of #TN#'s jeans, pulls #TO# very close and gives #TO# a deep, lingering kiss.$N$\n", "#MN# sneaks #MP# hands into the back pockets of your jeans, pulls you very close and gives you a deep, lingering kiss.$N$\n");
       afar("You sneak your hands into the back pockets of #TN#'s jeans, pull #TO# very close and give #TO# a deep, lingering kiss from afar.#RET#Wowsa!$N$\n", "#MN# sneaks #MP# hands into the back pockets of your jeans, pulls you very close and gives you a deep, lingering kiss from afar.#RET#Wowsa!$N$\n");
    }
}

int
cmd_jeans(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
