inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You tickle yourself fiendishly.$N$\n", "#MN# tickles #MO#self fiendishly.$N$\n");
       target("You tickle #TN# fiendishly.$N$\n", "#MN# tickles #TN# fiendishly.$N$\n", "#MN# tickles you fiendishly.$N$\n");
       afar("You tickle #TN# fiendishly from afar.$N$\n", "#MN# tickles you fiendishly from afar.$N$\n");
    }
}

int
cmd_tickle(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
