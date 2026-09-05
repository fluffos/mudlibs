inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You huggle yourself warmly, cuddling up with yourself.$N$\n", "#MN# huggles #MO#self warmly, cuddling up with #MO#self.$N$\n");
       target("You huggle #TN# warmly, making #TO# cuddle up with you.$N$\n", "#MN# huggles #TN# warmly, making #TO# cuddle up with #MO#.$N$\n", "#MN# huggles you warmly, making you cuddle up with #MO#.$N$\n");
       afar("You huggle #TN# warmly, making #TO# cuddle up with you from afar.#RET#Awww.$N$\n", "#MN# huggles you warmly, making you cuddle up with #MO# from afar.#RET#Awww.$N$\n");
    }
}

int
cmd_huggle(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
