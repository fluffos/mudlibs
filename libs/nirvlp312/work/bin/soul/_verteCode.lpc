inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You crash the MUD with verteCode[tm].#RET#Armageddon shouts: I'M OUTTA HERE!#RET##RET#Connection closed from foreign host.$N$\n", "#MN# crashes the MUD with verteCode[tm].#RET#Armageddon shouts: I'M OUTTA HERE!#RET##RET#Connection closed from foreign host.$N$\n");
       target("You crash #TN#'s computer with verteCode[tm].$N$\n", "#MN# crashes #TN#'s computer with verteCode[tm].$N$\n", "#MN# crashes your computer with verteCode[tm].#RET##RET#Connection closed from foreign host.$N$\n");
       afar("You attempt to jack into #TN#'s computer with verteCode[tm].#RET#BUT IT CRASHES YOUR OWN COMPUTER INSTEAD.#RET##RET#Connection closed from foreign host.$N$\n", "#MN# attempts to jack into your computer with verteCode[tm].#RET##MN# fails, and in the process, the verteCode eats #MP# soul.$N$\n");
    }
}

int
cmd_verteCode(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
