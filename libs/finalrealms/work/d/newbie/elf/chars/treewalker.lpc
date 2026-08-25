inherit "/obj/monster";

int ob;
mapping treewalking_quest;

void setup()
{
    treewalking_quest = ([ ]);

    set_name("treewalker");
    set_main_plural("treewalkers");
    set_race("elf");
    set_short("treewalker");
    set_long("An agile young elf, skilled at walking from tree "
      "branch to tree branch.\n");
    set_random_stats(10,18);
    set_level(15);
    set_wimpy(0);
    set_al(-200);
    // add_attack("spell", 0, 10, 210, 50, 0, "magic");
}

void init()
{
    ::init();
    add_action("train","train");
    if (!this_player()->query_property("treewalk") && interactive(this_player())
      && !sizeof(query_attacker_list()))
    {
        treewalking_quest[this_player()] = 1;
        call_out("start_quest", 0, this_player());
    }
}

void event_exit(object ob, string mess, object *avoid)
{
    if (treewalking_quest[ob])
        treewalking_quest = m_delete(treewalking_quest, ob);
}

void start_quest(object ob)
{
    do_command("say " + (string) ob->query_cap_name()+
      ", have you come here to study the elven art of treewalking?\n");
}

void event_person_say(object ob, string str, string mess)
{
    string s1, s2;
    string *list;

    mess = lower_case(mess);
    //tell_room(environment(this_object()),(string)ob->query_name()+"["+str+"]["+mess+"]\n");
    list = explode(mess," ");
    if(member_array("yes",list) >=0|| member_array("study",list) >= 0 || member_array("learn",list) >= 0)
        if (treewalking_quest[ob] == 1)
            call_out("second_question", 0, ob);
}

void second_question(object ob)
{
    if(ob->query_al() < 40)
    {
        tell_object(ob,(string)ob->query_cap_name()+
          ", you are a healthy young elf.  You should be able to "
          "learn this skill I can teach.  Please 'train' with me, "
          "and I'll instruct you in the art of crossing trees.\n");
        treewalking_quest[ob] = 2;
    }
    else
    {
        tell_object(ob,"I will teach nothing to unworthy people. If you ever "
          "learn to follow the path of goodness, you may come back to learn.\n");
        treewalking_quest = m_delete(treewalking_quest, ob);
    }
}
int train()
{
    if (!ob==2)
        return 0;
    else
    {
        write(this_player()->query_cap_name()+" studies the ancient elven skill.\n");
        say("You master the ancient elven skill.\n");
        call_out("give_treewalking",0,(this_player()));
        return 1;
    }
}

void give_treewalking(object ob)
{
    tell_room(environment(this_object()), "The Treewalker quickly "
      "teaches "+ob->query_cap_name()+" the art of walking on trees.\n", ({ ob }));
    tell_object(ob,
      "The treewalker proclaims proudly to you:"
      "You are taught a useful skill.  You now have the treewalking skill.\n");
    treewalking_quest = m_delete(treewalking_quest, ob);
    ob->add_property("treewalking", 1);
}
