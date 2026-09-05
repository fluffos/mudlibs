inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You pass out from boredom and go to sleep.$N$\n", "#MN# passes out from boredom and goes to sleep.$N$\n");
       target("You look at #TN# sleepily.#RET#You pass out from boredom and go to sleep.$N$\n", "#MN# looks at #TN# sleepily.#RET##MN# passes out from boredom and goes to sleep.$N$\n", "#MN# looks at you sleepily.#RET##MN# passes out from boredom and goes to sleep.$N$\n");
       afar("You look at #TN# sleepily from afar.#RET#You pass out from boredom and go to sleep.$N$\n", "#MN# looks at you sleepily from afar.#RET##MN# passes out from boredom and goes to sleep.$N$\n");
    }
}

int
cmd_sleep(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
