inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You assmack yourself. Mmmmm.$N$\n", "#MN# assmacks #MO#self. Mmmmm.$N$\n");
       target("You assmack #TN# thoroughly.$N$\n", "#MN# assmacks #TN# thoroughly.$N$\n", "#MN# assmacks you thoroughly.$N$\n");
       afar("You assmack #TN# thoroughly from afar.$N$\n", "#MN# assmacks you thoroughly from afar.$N$\n");
    }
}

int
cmd_assmack(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
