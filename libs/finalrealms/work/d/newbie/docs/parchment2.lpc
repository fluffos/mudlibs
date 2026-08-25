inherit "/std/object";

void setup()
{
    set_name("parchment");
    set_short("Parchment");
    set_long("This scruffy-looking piece of parchment looks to have been "
      "kept scrumpled up in someone's pocket for weeks at a time. "
      "It is covered in tiny scrawling writing which is difficult to "
      "read. "
      "\nLooking closely you can make out what looks like 'rules' "
      "'ask', 'ask1', and 'ask2'. "
      "\n\n");
}

void init()
{
    ::init();
    add_action("rules","rules");
    add_action("do_questions","ask");
    add_action("do_questions1","ask1");
    add_action("do_questions2","ask2");
}
int rules()
{
    write("\n1. All answers are to be mailed to Riddler no later than "
      "midday, 30 September, Mud Time. (As seen at the top of the \"Who\" list). "
      "\n2. The judges decision will be final, no correspondence will "
      "be entered into. "  
      "\n3. The winner will be the being with the most correct answers."
      "In the event of a tie, the winner will be chosen by random selection "
      "\n4. There may or may not be other random prizes awarded at the whim "
      "of the judge. (In this case, Raisa)"
      "\n5. Please try to answer the questions in the order they are asked. "
      "\n6. Players who also have immortal chars will have a 10 point "
      "penalty, on the assumption they SHOULD know more about their own "
      "domain than an ordinary player. "
      "\n");

    return 1;
}
int do_questions()
{
    write("\n"
      "1. What river feeds into the Sword Sea?\n"
      "2. How many different faces appear on FR coins?\n"
      "3. What kind of prayer does Taniwha refuse?\n"
      "4. What kind of prayer does Timion refuse?\n"
      "5. Who is the friendly neighborhood lumberjack?\n"
      "6. Which guilds cost 2 times the level in plat when you advance?\n"
      "7. If you sought divine inspiration, who would you go to?\n"
      "8. What color potion would you drink to boost your wisdom?\n"
      "9. How do you cure a dwarf of homesickness?\n"
      "10. What was \"The Footman's Charge\"?\n"
      "11. What does a bamboo wand do?\n"
      "12. How many arrow spells are there?\n"
      "13. What do Frodo and Orfod want?\n"
      "14. What is the Pirates SIG on?\n"
      "15. Where is Balnazzi kept?\n");
    return 1;
}
int do_questions1()
{
    write("\n"
      "16. How many sunken ships are there?\n"
      "17. You are lost and alone in a part of the Realms you have "
      "never explored before. Somehow you have lost most of your "
      "equipment and you have only 10 hit points left. Which "
      "other player would you least like to see enter the room?\n"
      "18. What is the most fearsome monster in the Realms (opinion)?\n"
      "19. Which of the Daggerford mini-omiqs is the most fun (opinion)?\n"
      "20. What falls from the sky at the entrance to Caldera?\n"
      "21. Name the assassin who accidentally collected the bounty on Ducky?\n"
      "22. How much does the Pirates SIG charge for safe passage for a sloop?\n"
      "23. Where are the skavens found?\n"
      "24. What is Armas' title?\n"
      "25. In what domain can you find the scroll of darkness?\n"
      "26. What race first used Power Word Genocide?\n"
      "27. When casting Detect Magic, what does the color grey signify?\n"
      "28. What is the name of the ruined city in Oceanfall?\n"
      "29. When was Daggerford founded, and by whom?\n"
    );
    return 1;
}
int do_questions2()
{
    write("\n"
      "30. Which NPC is the \"Hand of the Dark\"?\n"
      "31. According to the tablet in the Spider Tunnels, when should "
      "plaid pants be worn?\n"
      "32. What is Rakmar's last name?\n"
      "33. What floats in the center of the feral gardens?\n"
      "34. Who was the first kender in the Realms?\n"
      "35. Name the first vampire player.\n"
      "36. What is the most valuable card in Spades?\n"
      "37. How big is the stage in the orc village throne room?\n"
      "38. Who do you doubt would be visiting the orc shaman any "
      "time soon?\n"  
      "39. Name as many barkeepers as you can. (1/4 point for each "
      "correct one)\n" 
      "40. Name as many dragons in the Realms as you can. (1/4  point each)\n"
      "\nThats all folks, 40 questions in all :)\n "
    );
    return 1;
}

