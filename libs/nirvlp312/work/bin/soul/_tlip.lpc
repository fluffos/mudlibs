inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You trace a finger down your cheek for a moment.#RET#You let it rest gently on your lips for a little while.$N$\n", "#MN# traces a finger down #MP# cheek for a moment.#RET##MN# lets #MP# finger rest gently on #MP# lips for a little while.$N$\n");
       target("You trace a finger down #TN#'s cheek for a moment.#RET#You let your finger rest gently on #TN#'s lips for a little while.$N$\n", "#MN# traces a finger down #TN#'s cheek for a moment.#RET##MN# lets #MP# finger rest gently on #TN#'s lips for a little while.$N$\n", "#MN# traces a finger down your cheek for a moment.#RET##MN# lets #MP# finger rest gently on your lips for a little while.$N$\n");
       afar("You trace a finger down #TN#'s cheek for a moment.#RET#You let your finger rest gently on #TN#'s lips for a little while.#RET#ALL OF THIS FROM AFAR.#RET#And to think Mother said you would never do anything productive.$N$\n", "#MN# traces a finger down your cheek for a moment.#RET##MN# lets #MP# finger rest gently on your lips for a little while.#RET#All of this from afar. Ain't that some trick?$N$\n");
    }
}

int
cmd_tlip(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
