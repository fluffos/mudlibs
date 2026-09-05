inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You flash yourself to the room.#RET#You are proud of the resulting amazement.$N$\n", "#CMN# flashes #MO#self to the room.#RET#You realize the rumors must be true...#RET#Everything IS Bigger in Texas!$N$\n");
       target("You flash #MO#self to #CTN#.#RET#You are proud of the resulting amazement.$N$\n", "#CMN# flashes #MO#self to #CTN#.#RET#You realize the rumors must be true...#RET#Everything IS Bigger in Texas!$N$\n", "#CMN# flashes #MO#self to you.#RET#You realize the rumors must be true...#RET#Everything IS Bigger in Texas!$N$\n");
       afar("$Y$[$N$afar$Y$]$N$ You flash yourself to #CTN#.#RET#$Y$[$N$afar$Y$]$N$ You are proud of the resulting amazement.$N$\n", "$Y$[$N$afar$Y$]$N$ #CMN# flashes #TO#self to you.#RET#$Y$[$N$afar$Y$]$N$ You realize the rumors must be true...#RET#$Y$[$N$afar$Y$]$N$ Everything IS Bigger in Texas!$N$\n");
    }
}

int
cmd_texflash(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "forbin"; }
