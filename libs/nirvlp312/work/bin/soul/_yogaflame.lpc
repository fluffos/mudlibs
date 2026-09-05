inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You shoot a large $HR$ball of flame$N$ from your mouth.#RET#You announce: YOGA $HR$FLAME$N$!$N$\n", "#MN# shoots a large $HR$ball of flame$N$ from #MP# mouth.#RET##MN# announces: YOGA $HR$FLAME$N$!$N$\n");
       target("You shoot a large $HR$ball of flame$N$ from your mouth at #TN#.#RET#You announce: YOGA $HR$FLAME$N$!$N$\n", "#MN# shoots a large $HR$ball of flame$N$ from #MP# mouth at #TN#.#RET##MN# announces: YOGA $HR$FLAME$N$!$N$\n", "#MN# shoots a large $HR$ball of flame$N$ from #MP# mouth at you.#RET##MN# announces: YOGA $HR$FLAME$N$!$N$\n");
       afar("You shoot a large $HR$ball of flame$N$ from your mouth at #TN# from afar.#RET#Unfortunately, it doesn't reach quite that far.#RET#You announce: YOGA $HR$FLAME$N$!$N$\n", "#MN# shoots a large $HR$ball of flame$N$ from #MP# mouth at you from afar.#RET#Fortunately, it doesn't reach quite that far.#RET##MN# announces: YOGA $HR$FLAME$N$!$N$\n");
    }
}

int
cmd_yogaflame(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
