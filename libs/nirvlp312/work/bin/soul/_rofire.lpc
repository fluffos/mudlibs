inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You cooly look around the room.#RET#You shout: \"I hope you like $HK$Johnny Cash$N$.\"#RET#You add: \"Cause you just stepped into $HR$The Ring of Fire$N$!\"$N$\n", "#CMN# cooly looks around the room.#RET##CMN# shouts: \"I hope you like $HK$Johnny Cash$N$.\"#RET##CMN# adds: \"Cause you just stepped into $HR$The Ring of Fire$N$!\"$N$\n");
       target("You cooly look at #CTN#.#RET#You shout: \"I hope you like $HK$Johnny Cash$N$, #CTN#.\"#RET#You add: \"Cause you just stepped into $HR$The Ring of Fire$N$!\"$N$\n", "#CMN# cooly looks at #CTN#.#RET##CMN# shouts: \"I hope you like $HK$Johnny Cash$N$, #CTN#.\"#RET##CMN# adds: \"Cause you just stepped into $HR$The Ring of Fire$N$!\"$N$\n", "#CMN# cooly looks at you.#RET##CMN# shouts: \"I hope you like $HK$Johnny Cash$N$, #CTN#.\"#RET##CMN# adds: \"Cause you just stepped into $HR$The Ring of Fire$N$!\"$N$\n");
       afar("$HY$[$HW$afar$HY$]$N$ You cooly look at #CTN#.#RET#$HY$[$HW$afar$HY$]$N$ You shout: \"I hope you like $HK$Johnny Cash$N$, #CTN#.\"#RET#$HY$[$HW$afar$HY$]$N$ You add: \"Cause you just stepped into $HR$The Ring of Fire$N$!\"$N$\n", "$HY$[$HW$afar$HY$]$N$ #CMN# cooly looks at you.#RET#$HY$[$HW$afar$HY$]$N$ #CMN# shouts: \"I hope you like $HK$Johnny Cash$N$, #CTN#.\"#RET#$HY$[$HW$afar$HY$]$N$ #CMN# adds: \"Cause you just stepped into $HR$The Ring of Fire$N$!\"$N$\n");
    }
}

int
cmd_rofire(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "forbin"; }
