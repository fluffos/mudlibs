inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You reach over and start scratching your own back lovingly.$N$\n", "#MN# reaches over and starts scratching #MP# own back lovingly.$N$\n");
       target("You reach over and start scratching #TN#'s back lovingly.$N$\n", "#MN# reaches over and starts scratching #TN#'s back lovingly.$N$\n", "#MN# reaches over and starts scratching your back lovingly.#RET#It feels soooo good you just curl up and smile.$N$\n");
       afar("You reach over and start scratching #TN#'s back lovingly from afar.$N$\n", "#MN# reaches over and starts scratching your back lovingly from afar.$N$\n");
    }
}

int
cmd_lscratch(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
