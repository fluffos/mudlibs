inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You announce: I came here to kick ass and chew $HM$bubblegum$N$. And I'm aaaalll out of $HM$bubblegum$N$.$N$\n", "#MN# announces: I came here to kick ass and chew $HM$bubblegum$N$. And I'm aaaaalll out of $HM$bubblegum$N$.$N$\n");
       target("You stare directly at #TN#.#RET#You announce: I came here to kick ass and chew $HM$bubblegum$N$. And I'm aaaalll out of $HM$bubblegum$N$.$N$\n", "#MN# stares directly at #TN#.#RET##MN# announces: I came here to kick ass and chew $HM$bubblegum$N$. And I'm aaaaalll out of $HM$bubblegum$N$.$N$\n", "#MN# stares directly at you.#RET##MN# announces: I came here to kick ass and chew $HM$bubblegum$N$. And I'm aaaaalll out of $HM$bubblegum$N$.$N$\n");
       afar("You attempt to stare at #TN# from afar.#RET#You announce: I came here to kick ass and chew $HM$bubblegum$N$. And I'm aaaaalll out of $HM$bubblegum$N$.$N$\n", "#MN# attempts to stare directly at you from afar.#RET##MN# announces: I came here to kick ass and chew $HM$bubblegum$N$. And I'm aaaaalll out of $HM$bubblegum$N$.$N$\n");
    }
}

int
cmd_kickchew(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
