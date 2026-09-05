inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You burp tremendously!#RET#Excuse yourself piggy!$N$\n", "#MN# burps tremendously!$N$\n");
       target("You burp tremendously at #TN#.$N$\n", "#MN# burps tremendously at #TN#.$N$\n", "#MN# burps tremendously at you.$N$\n");
       afar("You burp tremendously at #TN# from afar.#RET#What a piggy!$N$\n", "#MN# burps tremendously at you from afar.#RET#What a piggy!$N$\n");
    }
}

int
cmd_burp(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
