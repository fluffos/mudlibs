inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("A deadpan expression washes over your face.#RET#You announce: The name's Dobbs. Fred C. Dobbs.$N$\n", "A deadpan expression washes over #MN#'s face.#RET##MN# announces: The name's Dobbs. Fred C. Dobbs.$N$\n");
       target("Deadpan, you look #TN# in the face.#RET#You announce: The name's Dobbs. Fred C. Dobbs.$N$\n", "Deadpan, #MN# looks #TN# in the face.#RET##MN# announces: The name's Dobbs. Fred C. Dobbs.$N$\n", "Deadpan, #MN# looks you in the face.#RET##MN# announces: The name's Dobbs. Fred C. Dobbs.$N$\n");
       afar("You announce to #TN# from afar: The name's Dobbs. Fred C. Dobbs.$N$\n", "#MN# announces to you from afar: The name's Dobbs. Fred C. Dobbs.$N$\n");
    }
}

int
cmd_algarcia6(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
