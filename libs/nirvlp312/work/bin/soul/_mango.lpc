inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You menacingly wield a mango and eye the room...\n", "#MN# menacingly wields a mango and eyes the room...\n");
       target("You toss a sizable mango at #TN# and laf as it splats!\n", "#MN# tosses a sizable mango at you! It splatters all over your face!\n", "#TN# gets hit by a mango thrown by #MN#!\n");
       afar("You throw a mango really, really far.  It splatters all over #TN#.\n", "A mango from #MN# sails down from the heavens and splatters all over you.\n");
    }
}

int
cmd_mango(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }
