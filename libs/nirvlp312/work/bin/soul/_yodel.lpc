inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You yodel. YO DE' LAY HOO HOO!$N$\n", "#MN# yodels. YO DE' LAY HOO HOO!$N$\n");
       target("You yodel for #TN#. YO DE' LAY HOO HOO!$N$\n", "#MN# yodels for #TN#. YO DE' LAY HOO HOO!$N$\n", "#MN# yodels for you. YO DE' LAY HOO HOO!$N$\n");
       afar("You yodel for #TN# from afar. YO DE' LAY HOO HOO!$N$\n", "You can hear the annoying voice of #MN# yodeling from afar.#RET#YO DE' LAY HOO HOO!$N$\n");
    }
}

int
cmd_yodel(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
