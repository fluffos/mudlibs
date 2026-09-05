inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You bow down before the one you serve.#RET#(You're going to get what you deserve.)$N$\n", "$MN$ bows down before the one #MS# serves.#RET#(#CMS#'s going to get what #MS# deserves.)$N$\n");
       target("You bow down before #TN#.$N$\n", "#MN# bows down before #TN#.$N$\n", "#MN# bows down before you.$N$\n");
       afar("From afar, you bow down before #TN#.$N$\n", "From afar, #MN# bows down before you.$N$\n");
    }
}

int
cmd_bow2(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "illarion"; }
