inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You grab a $HR$brick$N$ and glance around the room.\n", "#MN# grabs a $HR$brick$N$ and glances around the room.\n");
       target("You grab a $HR$brick$N$ and swing it at #TN#'s head.#RET#You fall down laughing as #TN# starts to drool and eat bugs.#RET#You bastard....you made #TN# SpEciAL!\n", "#MN# grabs a $HR$brick$N$ and swings it at #TN#'s head.#RET#You fall down laughing as #TN# starts to drool and eat bugs.#RET#That bastard #MN# made #TN# SpEciAL!\n", "#MN# grabs a $HR$brick$N$ and swings it at your head.#RET#You suddenly find yourself drooling and eating bugs.#RET#That bastard #MN# made you SpEciAL!\n");
       afar("You grab a $HR$brick$N$ and hurl it at #TN#'s head.#RET#You fall down laughing as #TN# starts to drool and eat bugs.#RET#You bastard....you made #TN# SpEciAL!\n", "#MN# grabs a $HR$brick$N$ and hurls it at your head.#RET#You suddenly find yourself drooling and eating bugs.#RET#That bastard #MN# made you SpEciAL!\n");
    }
}

int
cmd_special(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "fred"; }
