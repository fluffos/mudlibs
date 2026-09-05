string look_jia() {
    string mesg;
    mesg = "可以拿的兵器有剑(sword)，刀(blade)，杖(staff)，鞭(whip)，镖(dart)，针(needle)。\n还有铁甲(armor)。\n\n";
    return mesg;
}


int do_get(string arg) {
    object weapon, me=this_player(), *temp, env;
    string type;
    int i;

    if(!arg) return 0;
    if(me->is_busy()) return 0;
    if (sscanf(arg, "%s from jia", type) != 1) return 0;

    switch (type) {
    case "sword":   if(this_player()->query("gender") == "无性")
                        weapon = new("/d/quanzhou/npc/obj/xiuhua");
                    else
                        weapon = new("/d/taishan/npc/obj/gangjian");
                    break;
    case "blade":   weapon = new("/clone/weapon/gangdao");
                    break;
    case "dart":   weapon = new("/clone/weapon/dart");
                    break;
    case "needle":   weapon = new("/clone/weapon/wuyingzhen");
                    break;
    case "staff":   weapon = new("/clone/weapon/gangzhang");
                    break;
    case "whip" :   weapon = new("/clone/weapon/changbian");
                    break;
    case "armor":   weapon = new("/clone/armor/tiejia");

                    break;
    case "walkie-talkie" : 
                    temp = all_inventory(me);
                    for (i = 0; i < sizeof(temp); i++) {
                        if (temp[i]->query("id") == "walkie-talkie") {
                            write("你已经拿了对讲机了。\n");
                            return 1;
                        }
                    }
                    weapon = new(__DIR__"obj/walkie-talkie");
                    env = environment(me);
                    if ( env->query("short") == "东厢房" )
                        weapon->set("channel", 1);
                    else if (env->query("short") == "西厢房" )
                        weapon->set("channel", 2);
                    break;
    default:        write("找不到"+type+"。\n");
                    return 1;
    }

    if(weapon->move(me)) {
        message_vision("$N从兵器架上取下一"+weapon->query("unit")+weapon->name()+"。\n", me);
    } else {
        destruct(weapon);
    }
    return 1;
}

void create_xiangfang() {
    set("item_desc", ([
        "jia" : (: look_jia :),
    ]));
}

void init_xiangfang() {
    add_action("do_get", "get");
    add_action("do_open", "open");
}

