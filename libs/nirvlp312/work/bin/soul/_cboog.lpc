inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You shove your finger up your nose and dig around...#RET#You pull out a dry $Y$booger$N$ and roll it into a ball...#RET#You flick it to see how far it goes.$N$\n", "#MN# shoves #MP# finger up #MP# nose and digs around...#RET##MN# pulls out a dry $Y$booger$N$ and roll it into a ball...#RET##MN# flicks it to see how far it goes.$N$\n");
       target("You shoves your finger up you nose and dig around...#RET#You pull out a dry $Y$booger$N$ and roll it into a ball...#RET#You flick it at #TN#.$N$\n", "#MN# shoves #MP# finger up #MP# nose and digs around...#RET##MN# pulls out a dry $Y$booger$N$ and roll it into a ball...#RET##MN# flicks it at #TN#.$N$\n", "#MN# shoves #MP# finger up #MP# nose and digs around...#RET##MN# pulls out a dry $Y$booger$N$ and roll it into a ball...#RET##MN# flicks it at You.$N$\n");
       afar("You shove your finger up your nose and dig around...#RET#You pull out a dry $Y$booger$N$ and roll it into a ball...#RET#You flick it at #TN#.#RET#WOW! Amazing aim!$N$\n", "#MN# shoves #MP# finger up #MP# nose and digs around...#RET##MN# pulls out a dry $Y$booger$N$ and roll it into a ball...#RET##MN# flicks it at You.#RET#WOW! Amazing aim!$N$\n");
    }
}

int
cmd_cboog(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "wicket"; }
