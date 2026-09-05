inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You grin biggly, just like Mizan.$N$\n", "$MN$ grins biggly, just like Mizan.$N$\n");
       target("You grin biggly at $TN$.$N$\n", "#MN# grins biggly at #TN#.#RET#That's got to be unnerving.$N$\n", "#MN# grins biggly at you.#RET#That's really unnerving!$N$\n");
       afar("From afar, you grin biggly at #TN#, but you have a feeling it loses something with distance.$N$\n", "From afar, #MN# grins biggly at you.  Fortunately it's not as unnerving as the up close version.$N$\n");
    }
}

int
cmd_grinbig(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "illarion"; }
