// standard pet object
// Modified by iszt@pkuxkx, 2007-03-15, added meat in die()

#define NICK_CMD        "/cmds/usr/nick"

#include <ansi.h>

inherit NPC;
inherit F_SAVE;

void create()
{
        ::create();
        seteuid(0);
        set_name("pet_name", ({ "pet_id" }) );
        set("attitude", "peaceful");
        set("no_arrest", 1);
        set_max_encumbrance(100);
}

void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 4, ob);
        }
        add_action("do_modify", "modify");
//        add_action("do_rang", "rang");
}

void greeting(object ob)
{
        object owner = find_player(query("owner_id"));
        if( owner ) set_leader(owner);
        
        if( !owner ) {
                message_vision(query("msg_lost"), this_object());
                return;
        }
        if( !present(owner, environment()) ) {
                random_move();
                return;
        }
        if( ob == query_leader() ) {
                message_vision(query("msg_meet"), this_object());
                return;
        }
}

int do_modify(string arg)
{
        object ob;
        string option, content;

        if( !(ob = this_player()) || (ob != query_leader()) )
                return notify_fail("这不是你的宠物，别指手划脚了好吗？\n");
                
        if( !arg || sscanf(arg, "%s %s", option, content) != 2 )
                return notify_fail("指令格式 : modify <选项> <内容>\n" +
                        "目前可以修改的选项有：long, nick, msg_lost, msg_meet, msg_come, msg_leave.\n");
                
        if( member_array(option, ({ "long", "nick", "msg_lost", "msg_meet", "msg_come", "msg_leave" })) == -1 )
                return notify_fail("指令格式 : modify <选项> <内容>\n" +
                        "目前可以修改的选项有：long, nick, msg_lost, msg_meet, msg_come, msg_leave.\n");

        if( sizeof(content) > 80 )
                return notify_fail("对不起，你的描述太长了。\n");
        
        if( sscanf(content, "%*s\\%*s") || sscanf(content, "%*s\"%*s") )
                return notify_fail("描述里不可以含有 \" 和 \\ 字符。\n");

        if( option == "nick" )
                NICK_CMD->main(this_object(), content);
        else
                set(option, content + "\n");
        save();
        write("描述修改完毕。\n");
        return 1;
}

int do_rang(string arg)
{
        string id, cmd;
        if( !arg || sscanf(arg, "%s to %s", id, cmd) != 2 )
                return notify_fail("你想让谁做什么？\n");
        
        if( id != query("id") )
                return notify_fail("你想让谁做什么？\n");
        
        command(cmd);
        write("Ok.\n");
        return 1;
}

void setup_pet(string id)
{
        object ob = this_object();
        
        ob->set_leader(find_player(id));
        ob->set("owner_id", id);
}

string query_save_file()
{
        return PRIVATE_DIR + query("owner_id")[0..0] + "/" + query("owner_id");
}

void die()
{
        object ob, killer;

        if( ob = query_leader() ) {
                ob->set("pet_died", 1);
                ob->delete_temp("created_pet");
                ob->save();
        }
        set("died", 1);
        set("eff_qi", query("max_qi"));
        set("eff_jing", query("max_jing"));
        set("qi", query("max_qi"));
        set("jing", query("max_jing"));
        save();
        if( killer = get_damage_origin_object() )
        {
                CHANNEL_D->do_channel(this_object(), "rumor", name() + "被" + killer->name() + "杀死了。");
                killer->add("PetKills", 1);               //add by boost, kill-pet count
        }
        else
                CHANNEL_D->do_channel(this_object(), "rumor", name() + "莫名其妙地死了。");
		seteuid(ROOT_UID);
        ob = new("/clone/food/pet");
	ob->set_name(replace_string(this_object()->name(), NOR, "肉"NOR), ({this_object()->query("id")+" rou", "rou",}));
        ob->move(this_object());
        ::die();
}

int heal_up()
{
        return ::heal_up()+1;
}
