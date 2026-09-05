inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You say: I don't usually do this, but I felt compelled to tell you something.#RET#You add: You have an absolutely ... breathtaking ... heinie.#RET#You finish: I mean, that thing's good. I wanna be friends with it.$N$\n", "#CMN# says: I don't usually do this, but I felt compelled to tell you something.#RET##CMN# adds: You have an absolutely ... breathtaking ... heinie.#RET##CMN# finishes: I mean, that thing's good. I wanna be friends with it.$N$\n");
       target("You say: I don't usually do this, but I felt compelled to tell you something, #CTN#.#RET#You add: You have an absolutely ... breathtaking ... heinie.#RET#You finish: I mean, that thing's good. I wanna be friends with it.$N$\n", "#CMN# says: I don't usually do this, but I felt compelled to tell you something, #CTN#.#RET##CMN# adds: #CTN#, have an absolutely ... breathtaking ... heinie.#RET##CMN# finishes: I mean, that thing's good. I wanna be friends with it.$N$\n", "#CMN# says: I don't usually do this, but I felt compelled to tell you something.#RET##CMN# adds: You have an absolutely ... breathtaking ... heinie.#RET##CMN# finishes: I mean, that thing's good. I wanna be friends with it.$N$\n");
       afar("$HW$[$HY$afar$HW$]$N$ You say: I don't usually do this, but I felt compelled to tell you something, #CTN#.#RET#$HW$[$HY$afar$HW$]$N$ You add: You have an absolutely ... breathtaking ... heinie.#RET#$HW$[$HY$afar$HW$]$N$ You finish: I mean, that thing's good. I wanna be friends with it.$N$\n", "$HW$[$HY$afar$HW$]$N$ #CMN# says: I don't usually do this, but I felt compelled to tell you something.#RET#$HW$[$HY$afar$HW$]$N$ #CMN# adds: You have an absolutely ... breathtaking ... heinie.#RET#$HW$[$HY$afar$HW$]$N$ #CMN# finishes: I mean, that thing's good. I wanna be friends with it.$N$\n");
    }
}

int
cmd_heinie(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "forbin"; }
