// marry_yahuan.c "丫环"
#include <mudlib.h>
#include <ansi.h>
inherit LIVING;
inherit M_ACTIONS;
inherit M_TRIGGERS;
inherit M_WANDER;
void receive_outside_msg(string str){
    receive_outside_msga(str);
}
void receive_private_msg(string str) {
    receive_outside_msga(str);
}
string *query_channel_list() {
    return ({ "plyr_gossip" });
}
object jia;
void setup() 
{
    add_id("shu tong","书童","tong");
    set_gender(1);
    set_proper_name("书童");
    set_in_room_desc("牧童家的 书童(shu tong)");
    set_long("一个书童，正在喃喃自语。\n");
    jia=new("/sgdomain/obj/cloth/torso/buyi.c");
    jia->move(this_object());
    jia->do_wear();
    set_sg_rongmao(25);
 add_pattern("%s走了%s",function(string left, string right){
                 
                respond("say :书中自有黄金屋，书中自有颜如玉...口水下来了...oops,K书K书");
});

}

