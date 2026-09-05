inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You skillfully play a cowbell, impressing all around you.$N$\n", "#MN# skillfully plays a cowbell, impressing you greatly.$N$\n");
       target("You play your cowbell for #TN#.#RET#*$HW$DONK!$N$*#RET#*$HW$#DONK!$N$*#RET#*$HW$DONK!$N$*$N$\n", "#MN# plays a cowbell for #TN#.#RET#*$HW$DONK!$N$*#RET#*$HW$#DONK!$N$*#RET#*$HW$DONK!$N$*$N$\n", "#MN# plays a cowbell for you.#RET#*$HW$DONK!$N$*#RET#*$HW$#DONK!$N$*#RET#*$HW$DONK!$N$*$N$\n");
       afar("From afar, you play your cowbell for #TN#.#RET#*$HW$DONK!$N$*#RET#*$HW$#DONK!$N$*#RET#*$HW$DONK!$N$*$N$\n", "From afar, #MN# plays a cowbell for you.#RET#*$HW$DONK!$N$*#RET#*$HW$#DONK!$N$*#RET#*$HW$DONK!$N$*$N$\n");
    }
}

int
cmd_cowbell4(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "khrell"; }
