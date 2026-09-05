inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You go: 'B-O-R-I-N-G!'$N$\n", "#MN# goes: 'B-O-R-I-N-G!'$N$\n");
       target("You make mocking/chuckling noises at #TN#.#RET#You go: 'B-O-R-I-N-G!'$N$\n", "#MN# makes mocking/chuckling noises at #TN#.#RET##MN# goes: 'B-O-R-I-N-G!'$N$\n", "#MN# makes mocking/chuckling noises at you.#RET##MN# goes: 'B-O-R-I-N-G!'$N$\n");
       afar("You shout to #TN# from afar: 'B-O-R-I-N-G!'$N$\n", "#MN# shouts to you from afar: 'B-O-R-I-N-G!'$N$\n");
    }
}

int
cmd_boring(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
