}
init() {
  ::init();
  add_action("open", "open");
}

open(str) {
  if(str != "coffin") return;
    if (ob && !ob->query_quest("quest_name")) {
        tell_object(ob, "You have completed the quest.\n");
        ob->set_quests("quest_name");
    }
}
