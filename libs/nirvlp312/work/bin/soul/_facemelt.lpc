inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("Your face $HR$MELTS$N$ off!$N$\n", "You watch in horror as #MN#'s face $HR$MELTS$N$ off!$N$\n");
       target("You stare at #TN# until your face $HR$MELTS$N$ off!$N$\n", "#MN# stares at #TN# until #MP# face $HR$MELTS$N$ off!$N$\n", "#MN# stares at YOU until #MP# face $HR$MELTS$N$ off!$N$\n");
       afar("You stare at #TN# from afar until your face $HR$MELTS$N$ off!$N$\n", "You seem to make out #MN#'s face melting away.#RET#But it's quite far away.$N$\n");
    }
}

int
cmd_facemelt(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
