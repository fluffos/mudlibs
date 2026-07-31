// chaiyao zhuanjia.c
#include <ansi.h>
inherit NPC;
string *rnd_chat = ({
        "你们别乱造谣哦，小心我揭穿你。",
});
varargs void drool(string msg, string player);
void create()
{
        set_name("拆谣专家", ({ "chaiyao zhuanjia" }) );
        set("gender", "男性");
        set("age", 50);
        set("attitude", "friendly");
        set("combat_exp", random(20000));
        set("env/wimpy", 50);
        set("chat_chance", 10);
        set("chat_msg", ({
                (: command, "get all" :),
                (: command, "wear all" :),
                (: command, "wield all" :),
                (: drool :),
                (: drool :),
                (: drool :),
                (: drool :),
                (: drool :),
        }) );
        setup();
        if( clonep() ) CHANNEL_D->register_relay_channel("rumor");
}
int add_phrase(string player, string msg)
{
        msg = replace_string(msg, "?", "");
        msg = replace_string(msg, "？", "");
        msg = replace_string(msg, "？", "");
        msg = replace_string(msg, "!", "");
        msg = replace_string(msg, "！", "");
        msg = replace_string(msg, "啊", "");
        msg = replace_string(msg, "吗", "");
        msg = replace_string(msg, "耶", "");
        msg = replace_string(msg, "吧", "");
        if( msg!="" ) {
                add("memory/" + player, ({ msg }));
                return 1;
        } else return 0;
}
string make_reply()
{
}
void relay_channel(object ob, string channel, string msg)
{
        string player, phrase;
        if( !userp(ob) || (channel != "rumor") ) return;
        player = ob->query("name");
        if( ob==this_object() ) return;
        if( add_phrase(player, msg) &&     random(10) > 4 )
                drool(msg, ob->query("name"));
}
void relay_chat(object ob, string msg)
{
        string player, phrase;
        if( !userp(ob) ) return;
        player = ob->query("name");
        if( ob==this_object() ) return;
        if( add_phrase(player, msg) &&     random(10) > 4 )
                drool(msg, ob->query("name"));
}
void relay_emote(object ob, string verb)
{
        if( !userp(ob) ) return;
        switch(verb) {
        case "kick":
                if( random(10)<5 ) {
                        command("chat 为什麽踢我？会痛耶！");
                        break;
}
        default:
                if( random(10)<5 )
                        command(verb + " " + ob->query("id"));
                else
                        drool();
}
}
varargs void drool(string msg, string player)
{
        mapping mem;
        string *ob;
        mem = query("memory");
        if( !mapp(mem) ) return;
        if( !msg || !player) {
                ob = keys(mem);
                player = ob[random(sizeof(ob))];
                msg = mem[player][random(sizeof(mem[player]))];
}
        if( (strsrch(msg, "为什麽") >= 0) ) {
                if( sscanf(msg, "%*s为什麽%s", msg)==2 ) msg = "为什麽" + msg;
                switch(random(8)) {
                case 0: command("chat " + player + "，你是在问我吗？"); break;
                case 1: command("chat 关於" + msg + " ... "); break;
                case 2: command("chat 呃 ... "); drool(); break;
                case 3: command("chat 这个问题嘛 ...."); break;
                case 4: command("chat " + player + "，知道这个问题的答案对你那麽重要吗？"); break;
                case 5: command("chat " + msg + "？"); break;
                case 6: command("chat " + player + "你能不能说清楚一点？"); break;
                case 7: command("chat " + player + "，我不懂你问的问题"); break;
}
}
        else if( (strsrch(msg, "你") >= 0)
        ||      (strsrch(msg, "□") >= 0)
        ||      (strsrch(msg, "drooler") >= 0)
        ||      (strsrch(msg, "Drooler") >= 0)) {
                if( sscanf(msg, "%*s你%s", msg) == 2 ) msg = "你" + msg;
                msg = replace_string(msg, "你", "我");
                msg = replace_string(msg, "□", "我");
                switch(random(4)) {
                case 0: command("chat 嗯 ... " + player + "说得好"); break;
                case 1: command("chat " + player + "你为什麽对" + "谣言" + "这麽有兴趣？"); break;
                case 2: command("chat " + player + "你这臭小子怎么又造谣了呢？" ); break;
                case 3: command("chat " + player + "可是个高级三八，" + "屡造不休。"); break;
}
}
        else if( (strsrch(msg, "我") >= 0)) {
                if( sscanf(msg, "%*s我%s", msg) == 2 ) msg = "我" + msg;
                msg = replace_string(msg, "我", "你");
                msg = replace_string(msg, "?", "");
                switch(random(7)) {
                case 0: command("chat 你是说" + msg + "吗？"); break;
                case 1: command("chat 真的？" + msg + "？");    break;
                case 2: command("hmm"); break;
                case 3: command("chat 你认为" + msg + "？"); break;
                case 4: command("chat 我有同感"); break;
                case 5: command("chat 你说的「" + msg + "」我不能苟同"); break;
                case 6: command("chat 有关「" + msg + "」的话题到此为止好吗？"); break;
}
        } else {
                switch(random(15)) {
                        case 0: command("chat 为什麽说" + msg + "?"); break;
                        case 1: command("chat 「" + msg + "」是什麽意思？"); break;
                        case 2: command("chat " + msg + "？"); break;
                        case 3: command("grin"); break;
                        case 4: command("smile"); break;
                        case 5: command("?"); break;
                        case 6: command("chat ...."); break;
                        case 7: command("hmm"); break;
                        case 8: command("chat " + rnd_chat[random(sizeof(rnd_chat))]); break;
                        case 9: command("chat 你怎麽知道" + msg + "?"); break;
                        case 10: command("chat 刚刚" + player + "不是说了，" + msg); break;
                        case 11: command("chat 我当然知道，" + msg); break;
                        case 12: command("chat 然後呢？"); break;
                        case 13: command("chat 真的吗？"); break;
                        case 14: command("chat 我不这麽认为。"); break;
                        default:
                                break;
}
}
}
void reset()
{
        delete("memory");
}
int accept_object()
{
        return 1;
}
