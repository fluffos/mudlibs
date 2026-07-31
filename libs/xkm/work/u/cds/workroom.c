inherit ROOM;

void create()
{
    set("short", "暴血的天堂");
        set("long", @LONG
这是一个从xiaofan那里偷来的房间，小心喽，苦海无涯，回头也无岸，哈哈哈哈。。。。。。
LONG
        );
    set("valid_startroom", 1);
    set("sleep_room", 1);
    set("no_sleep_room", 1);
    set("no_fight", 1);

        setup();
}
void init()
{
add_action("do_action", "");
}
int do_action(string arg)
{
           string action = query_verb();
switch (action) {
                    case "dazuo":
                    case "chat":
                    case "tell":
                    case "reply":
                    case "party":
                    case "quit":
                    case "exercise":
                    case "tuna":
                    case "chat*":
                    case "chat*":
                    case "abandon":
                    case "practice":
                    case "du":
                    case "fangqi":
                    case "study":
                    case "cha":
                    case "skills":
                    case "skill":
                    case "shout":
                    case "gwiz":
                    case "ajsx":
                    case "emote":
                    case "summon":
                                   case "blk":
                    case "dest":
                    case "destroy":
                    case "menpai":
                    case "ls":
                    case "cd":
                    case "update":
                    case "hp":
                    case "score":
                    case "respirate":
                    case "nick":
                    case "suicide":
                    case "say":
                    case "rumor":
                    case "nick":
                   case "wiz":
                    case "edit":
                    case "more":
                    case "cat":
//                  case "home":
//                  case "goto":
write("你死定了，你在这里慢慢发呆吧!哈哈哈哈。。。。。\n");
                             return 1;
                                  case "home":
                        if (this_player()->query("id") != "cds")
                        return 1;
                        else return 0;
                      case "goto":
                        if (this_player()->query("id") != "cds")
                        return 1;
                        else return 0;

              }
              return 0;
}
