inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You get down on one knee and sing a ballad in your honor!$N$\n", "#MN# gets down on one knee and sings a ballad in #MP# honor.$N$\n");
       target("You get down on one knee and sing a ballad in #TN#'s honor.$N$\n", "#MN# gets down on one knee and sings a ballad in #TN#'s honor.$N$\n", "#MN# gets down on one knee and sings a ballad in your honor!$N$\n");
       afar("You get down on one knee and sing a ballad in #TN#'s honor from afar.#RET#Boy does your voice carry!$N$\n", "#MN# gets down on one knee and sings a ballad in your honor from afar.#RET# Boy does #MO# voice carry!$N$\n");
    }
}

int
cmd_ballad(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
