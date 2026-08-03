void init()
{
     add_action("do_action", ({"dazuo", "tuna", "lian", "learn", "du", "steal", "hit",
                             "kill", "fight", "study", "practice","exercise", "exert",
                             "emote", "ask"}));
}
int do_action(string arg)
{
   write("你正要有所动作，突然身旁有人将你一拍：好好看比武，再乱动当心老子揍你！\n");
   return 1;
}
