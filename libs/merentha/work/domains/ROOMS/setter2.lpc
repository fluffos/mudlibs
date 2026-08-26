// Petrarch
// Merentha Lib 1.0
// setter.c

#include <daemons.h>
#include <rooms.h>
#include <std.h>
inherit ROOM;

void create() {
    ::create();
    set_property("no linkdead", START_ROOM);
    set_property("no start", 1);
    set_short("This is the character creation room.");
    set_long("Large swirling disks of colours appear on all the walls around you.  In fact there appear to be no walls at all as the swirls fly by you.");
    set_items(([
        "disk":"The disks swirl by at grat speeds.  Each disk has a question in it.",
      ]));
}

void reset() {
    object ob;
    ::reset();
    if(!present("sign")) {
        ob=new(SIGN);
        ob->set_name("sign");
        ob->set_short("a swirling sign");
        ob->set_long("The sign is made up of swirling colours.");
        ob->set_id(({"sign", "newbie sign", "oak sign", "race sign"}));
        ob->set_message(copy(border("%^RED%^Answering the following questions will help customize your character for the world.\n\nType <begin> to answer the first question."
              , "Character Customization")));
        ob->move(this_object());
    }
}

void init() {
    ::init();
    add_action("cmd_begin", "begin");
}

string *questions=({
  "What was the profession of your mother?\n  a) Mage\n  b) Monk\n  c) Healer\n  d) Fighter",
  "What was the profession of your father?\n  a) Mage\n  b) Monk\n  c) Healer\n  d) Fighter",
  "What did you always want to be growing up?\n  a) A magician\n  b) A healer\n  c) A monk\n  d) A fighter",
  "As a child you:\n  a) Played mostly by youself\n  b) Played with your brothers and sisters\n  c) Played mostly with a small group of friends\n  d) Played with everyone who looked at you",
  "Where would you go on vacation?\n  a) A nice lake side cottage\n  b) Off in the middle of the woods\n  c) In your house with your family and friends\n  d) In another town or village",
});

void alter_skills(object tp, int question, string answer) {
    question--;
    switch (question) {
    case 0:
        switch (answer) {
        case "a":
            tp->set_skill("attack magic", tp->query_base_skill("attack magic")+5);
            tp->set_skill("defense magic", tp->query_base_skill("defense magic")+10); 
            tp->set_skill("conjuring", tp->query_base_skill("conjuring")+15);
            tp->set_skill_adjustment("attack magic", tp->query_skill_adjustment("attack magic")-5);
            tp->set_skill_adjustment("defense magic", tp->query_skill_adjustment("defense magic")-10);
            tp->set_skill_adjustment("conjuring", tp->query_skill_adjustment("conjuring")-15);
            tp->set_stat("intelligence",tp->query_base_stat("intelligence")+1);
            break;
        case "b":
            tp->set_skill("faith", tp->query_base_skill("faith")+15); 
            tp->set_skill("melee", tp->query_base_skill("melee")+10); 
            tp->set_skill("climbing", tp->query_base_skill("climbing")+5); 
            tp->set_skill_adjustment("faith",tp->query_skill_adjustment("faith")-15);
            tp->set_skill_adjustment("melee",tp->query_skill_adjustment("melee")-10);
            tp->set_skill_adjustment("climbing",tp->query_skill_adjustment("climbing")-5);
            tp->set_stat("dexterity",tp->query_base_stat("dexterity")+1);
            break;
        case "c":
            tp->set_skill("healing", tp->query_base_skill("healing")+10); 
            tp->set_skill("medicine", tp->query_base_skill("medicine")+15); 
            tp->set_skill("faith", tp->query_base_skill("faith")+5); 
            tp->set_skill_adjustment("healing",tp->query_skill_adjustment("healing")-10);
            tp->set_skill_adjustment("medicine",tp->query_skill_adjustment("medicine")-15);
            tp->set_skill_adjustment("faith",tp->query_skill_adjustment("faith")-5);
            tp->set_stat("intelligence",tp->query_base_stat("intelligence")+1);
            break;
        case "d":
            tp->set_skill("attack", tp->query_base_skill("attack")+5); 
            tp->set_skill("defense", tp->query_base_skill("defense")+5); 
            tp->set_skill("knife", tp->query_base_skill("knife")+5); 
            tp->set_skill("bow", tp->query_base_skill("bow")+5); 
            tp->set_skill("whip", tp->query_base_skill("whip")+5); 
            tp->set_skill("riding", tp->query_base_skill("riding")+5); 
            tp->set_skill_adjustment("attack",tp->query_skill_adjustment("attack")-5);
            tp->set_skill_adjustment("defense",tp->query_skill_adjustment("defense")-5);
            tp->set_skill_adjustment("knife",tp->query_skill_adjustment("knife")-5);
            tp->set_skill_adjustment("bow",tp->query_skill_adjustment("bow")-5);
            tp->set_skill_adjustment("whip",tp->query_skill_adjustment("whip")-5);
            tp->set_skill_adjustment("riding",tp->query_skill_adjustment("riding")-5);
            tp->set_stat("constitution",tp->query_base_stat("constitution")+1);
            break;
        }
        break;
    case 1:
        switch (answer) {
        case "a":
            tp->set_skill("attack magic", tp->query_base_skill("attack magic")+15);
            tp->set_skill("defense magic", tp->query_base_skill("defense magic")+10); 
            tp->set_skill("conjuring", tp->query_base_skill("conjuring")+5);
            tp->set_skill_adjustment("attack magic",tp->query_skill_adjustment("attack magic")-15);
            tp->set_skill_adjustment("defense magic",tp->query_skill_adjustment("defense magic")-10);
            tp->set_skill_adjustment("conjuring",tp->query_skill_adjustment("conjuring")-5);
            tp->set_stat("wisdom",tp->query_base_stat("wisdom")+1);
            break;
        case "b":
            tp->set_skill("faith", tp->query_base_skill("faith")+10); 
            tp->set_skill("melee", tp->query_base_skill("melee")+15); 
            tp->set_skill("climbing", tp->query_base_skill("climbing")+5); 
            tp->set_skill_adjustment("faith",tp->query_skill_adjustment("faith")-10);
            tp->set_skill_adjustment("melee",tp->query_skill_adjustment("melee")-15);
            tp->set_skill_adjustment("climbing",tp->query_skill_adjustment("climbing")-5);
            tp->set_stat("constitution",tp->query_base_stat("constitution")+1);
            break;
        case "c":
            tp->set_skill("healing", tp->query_base_skill("healing")+10); 
            tp->set_skill("medicine", tp->query_base_skill("medicine")+10); 
            tp->set_skill("faith", tp->query_base_skill("faith")+10); 
            tp->set_skill_adjustment("healing",tp->query_skill_adjustment("healing")-10);
            tp->set_skill_adjustment("medicine",tp->query_skill_adjustment("medicine")-10);
            tp->set_skill_adjustment("faith",tp->query_skill_adjustment("faith")-10);
            tp->set_stat("intelligence",tp->query_base_stat("intelligence")+1);
            break;
        case "d":
            tp->set_skill("attack", tp->query_base_skill("attack")+5); 
            tp->set_skill("defense", tp->query_base_skill("defense")+5); 
            tp->set_skill("sword", tp->query_base_skill("sword")+5); 
            tp->set_skill("club", tp->query_base_skill("club")+5); 
            tp->set_skill("axe", tp->query_base_skill("axe")+5); 
            tp->set_skill("melee", tp->query_base_skill("melee")+5); 
            tp->set_skill_adjustment("attack",tp->query_skill_adjustment("attack")-5);
            tp->set_skill_adjustment("defense",tp->query_skill_adjustment("defense")-5);
            tp->set_skill_adjustment("sword",tp->query_skill_adjustment("sword")-5);
            tp->set_skill_adjustment("club",tp->query_skill_adjustment("club")-5);
            tp->set_skill_adjustment("axe",tp->query_skill_adjustment("axe")-5);
            tp->set_skill_adjustment("melee",tp->query_skill_adjustment("melee")-5);
            tp->set_stat("strength",tp->query_base_stat("strength")+1);
            break;
        }
        break;
    case 2:
        switch (answer) {
        case "a":
            tp->set_skill("attack magic", tp->query_base_skill("attack magic")+10);
            tp->set_skill("defense magic", tp->query_base_skill("defense magic")+10); 
            tp->set_skill("conjuring", tp->query_base_skill("conjuring")+10);
            tp->set_skill_adjustment("attack magic",tp->query_skill_adjustment("attack magic")-10);
            tp->set_skill_adjustment("defense magic",tp->query_skill_adjustment("defense magic")-10);
            tp->set_skill_adjustment("conjuring",tp->query_skill_adjustment("conjuring")-10);
            tp->set_stat("wisdom",tp->query_base_stat("wisdom")+1);
            break;
        case "b":
            tp->set_skill("faith", tp->query_base_skill("faith")+10); 
            tp->set_skill("melee", tp->query_base_skill("melee")+10); 
            tp->set_skill("climbing", tp->query_base_skill("climbing")+10); 
            tp->set_skill_adjustment("faith",tp->query_skill_adjustment("faith")-10);
            tp->set_skill_adjustment("melee",tp->query_skill_adjustment("melee")-10);
            tp->set_skill_adjustment("climbing",tp->query_skill_adjustment("climbing")-10);
            tp->set_stat("charisma",tp->query_base_stat("charisma")+1);
            break;
        case "c":
            tp->set_skill("healing", tp->query_base_skill("healing")+10); 
            tp->set_skill("medicine", tp->query_base_skill("medicine")+10); 
            tp->set_skill("faith", tp->query_base_skill("faith")+10); 
            tp->set_skill_adjustment("healing",tp->query_skill_adjustment("healing")-10);
            tp->set_skill_adjustment("medicine",tp->query_skill_adjustment("medicine")-10);
            tp->set_skill_adjustment("faith",tp->query_skill_adjustment("faith")-10);
            tp->set_stat("dexterity",tp->query_base_stat("dexterity")+1);
            break;
        case "d":
            tp->set_skill("attack", tp->query_base_skill("attack")+5); 
            tp->set_skill("defense", tp->query_base_skill("defense")+5); 
            tp->set_skill("sword", tp->query_base_skill("sword")+5); 
            tp->set_skill("club", tp->query_base_skill("club")+5); 
            tp->set_skill("axe", tp->query_base_skill("axe")+5); 
            tp->set_skill("melee", tp->query_base_skill("melee")+5); 
            tp->set_skill_adjustment("attack",tp->query_skill_adjustment("attack")-5);
            tp->set_skill_adjustment("defense",tp->query_skill_adjustment("defense")-5);
            tp->set_skill_adjustment("sword",tp->query_skill_adjustment("sword")-5);
            tp->set_skill_adjustment("club",tp->query_skill_adjustment("club")-5);
            tp->set_skill_adjustment("axe",tp->query_skill_adjustment("axe")-5);
            tp->set_skill_adjustment("melee",tp->query_skill_adjustment("melee")-5);
            tp->set_stat("constitution",tp->query_base_stat("constitution")+1);
            break;
        }
        break;
    case 3:
        switch (answer) {
        case "a":
            tp->set_skill("faith", tp->query_base_skill("faith")+5); 
            tp->set_skill("conjuring", tp->query_base_skill("conjuring")+5); 
            tp->set_skill("stealth", tp->query_base_skill("stealth")+10); 
            tp->set_skill_adjustment("faith",tp->query_skill_adjustment("faith")-5);
            tp->set_skill_adjustment("conjuring",tp->query_skill_adjustment("conjuring")-5);
            tp->set_skill_adjustment("stealth",tp->query_skill_adjustment("stealth")-10);
            break;
        case "b":
            tp->set_skill("bargaining", tp->query_base_skill("bargaining")+5); 
            tp->set_skill("stealth", tp->query_base_skill("stealth")+5); 
            tp->set_skill("stealing", tp->query_base_skill("stealing")+10); 
            tp->set_skill_adjustment("bargaining",tp->query_skill_adjustment("bargaining")-5);
            tp->set_skill_adjustment("stealth",tp->query_skill_adjustment("stealth")-5);
            tp->set_skill_adjustment("stealing",tp->query_skill_adjustment("stealing")-10);
            break;
        case "c":
            tp->set_skill("bargaining", tp->query_base_skill("bargaining")+10); 
            tp->set_skill("healing", tp->query_base_skill("healing")+5); 
            tp->set_skill("medicine", tp->query_base_skill("medicine")+5); 
            tp->set_skill_adjustment("bargaining",tp->query_skill_adjustment("bargaining")-10);
            tp->set_skill_adjustment("healing",tp->query_skill_adjustment("healing")-5);
            tp->set_skill_adjustment("medicine",tp->query_skill_adjustment("medicine")-5);
            break;
        case "d":
            tp->set_skill("bargaining", tp->query_base_skill("bargaining")+15); 
            tp->set_skill("swimming", tp->query_base_skill("swimming")+5); 
            tp->set_skill("riding", tp->query_base_skill("riding")+5); 
            tp->set_skill_adjustment("bargaining",tp->query_skill_adjustment("bargaining")-15);
            tp->set_skill_adjustment("swimming",tp->query_skill_adjustment("swimming")-5);
            tp->set_skill_adjustment("riding",tp->query_skill_adjustment("riding")-5);
            break;
        }
        break;
    case 4:
        switch (answer) {
        case "a":
            tp->set_skill("survival", tp->query_base_skill("swimming")+10);
            tp->set_skill("swimming", tp->query_base_skill("swimming")+10);
            tp->set_skill("fishing", tp->query_base_skill("fishing")+15);
            tp->set_skill_adjustment("swimming",tp->query_skill_adjustment("swimming")-10);
            tp->set_skill_adjustment("fishing",tp->query_skill_adjustment("fishing")-10);
            break;
        case "b":
            tp->set_skill("survival", tp->query_base_skill("swimming")+15);
            tp->set_skill("hunting", tp->query_base_skill("hunting")+10);
            tp->set_skill("riding", tp->query_base_skill("riding")+10);
            tp->set_skill_adjustment("hunting",tp->query_skill_adjustment("hunting")-10);
            tp->set_skill_adjustment("riding",tp->query_skill_adjustment("riding")-10);
            break;
        case "c":
            tp->set_skill("bargaining", tp->query_base_skill("bargaining")+20);
            tp->set_skill("faith", tp->query_base_skill("faith")+15);
            tp->set_skill_adjustment("bargaining",tp->query_skill_adjustment("bargaining")-10);
            tp->set_skill_adjustment("faith",tp->query_skill_adjustment("faith")-10);
            break;
        case "d":
            tp->set_skill("bargaining", tp->query_base_skill("bargaining")+25);
            tp->set_skill("riding", tp->query_base_skill("riding")+10);
            tp->set_skill_adjustment("bargaining",tp->query_skill_adjustment("bargaining")-10);
            tp->set_skill_adjustment("riding",tp->query_skill_adjustment("riding")-10);
            break;
        }
        break;
    }
}

int cmd_begin(string answer, int question) {
    if(answer && member_array(answer,({"a","b","c","d"}))==-1) {
        question--;
        message("customize", "Please answer only 'a', 'b', 'c' or 'd'\n"+questions[question], this_player());
        message("prompt", "Answer: ", this_player());
        question++;
        input_to("cmd_begin", 2, question);
        return 1;
    }
    if(question) alter_skills(this_player(), question, answer);
    if(question==5) {
        this_player()->move_player(START_ROOM);
        return 1;
    }
    message("customize", "Question "+(question+1)+" of 5\n"+questions[question], this_player());
    message("prompt", "Answer: ", this_player());
    question++;
    input_to("cmd_begin", 2, question);
    return 1;
}


