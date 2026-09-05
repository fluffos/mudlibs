inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You leap into the air like Liu Kang.#RET#You kick like five point eight oh quadrillion times.#RET#You shout: \"HAZZAH WAZZAH WAZZAH WAH!\"$N$\n", "#MN# leaps into the air like Liu Kang.#RET##MN# kicks like five point eight oh quadrillion times.#RET##MN# shouts: \"HAZZAH WAZZAH WAZZAH WAH!\"$N$\n");
       target("You leap into the air in front of #TN# like Liu Kang.#RET#You kick #TN# like five point eight oh quadrillion times.#RET#You shout: \"HAZZAH WAZZAH WAZZAH WAH!\"$N$\n", "#MN# leaps into the air in front of #TN# like Liu Kang.#RET##MN# kicks #TN# like five point eight oh quadrillion times.#RET##MN# shouts: \"HAZZAH WAZZAH WAZZAH WAH!\"$N$\n", "#MN# leaps into the air in front of you like Liu Kang.#RET##MN# kicks you like five point eight oh quadrillion times.#RET##MN# shouts: \"HAZZAH WAZZAH WAZZAH WAH!\"$N$\n");
       afar("You make lame ass flailing motions at #TN# from afar.$N$\n", "#MN# makes lame ass flailing motions at you from afar.$N$\n");
    }
}

int
cmd_bicycle_kick(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
