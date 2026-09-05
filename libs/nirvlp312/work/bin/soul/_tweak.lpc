inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You look around for a cheek to tweak.$N$\n", "#MN# looks around in a way that reminds you of your dear old Great-Aunt Gertrude, even if you never had one.$N$\n");
       target("You tweak #TN#'s cheek.#RET#Isn't #TS# just so cute?$N$\n", "#MN# tweaks #TN#'c cheek.#RET#Awww... isn't that adorable?$N$\n", "#MN# tweaks your cheek.#RET#That might seem cute if it didn't hurt so much!$N$\n");
       afar("$HM$[afar]$N$You tweak #TN#'s cheek.#RET#Isn't #TS# just so cute?$N$\n", "$HM$[afar]$N$#MN# tweaks your cheek.#RET#That might seem cute if it didn't hurt so much!$N$\n");
    }
}

int
cmd_tweak(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "illarion"; }
