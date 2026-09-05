inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You wrap your arms around yourself and start kissing yourself all over!$N$\n", "#MN# wraps #MP# arms around #MO#self and starts kissing #MO#self all over!\n");
       target("You wrap your arms around #TN# and start kissing #TO# all over!$N$\n", "#MN# wraps #MP# arms around #TN# and starts kissing #TO# all over!$N$\n", "#MN# wraps #MP# arms around you and starts kissing you all over!$N$\n");
       afar("You wrap your arms around #TN# and start kissing #TO# all over from afar.#RET#Damn you have long arms!$N$\n", "#MN# wraps #MP# arms around you and starts kissing you all over from afar!#RET#Damn #MS# has long arms!$N$\n");
    }
}

int
cmd_kwrap(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
