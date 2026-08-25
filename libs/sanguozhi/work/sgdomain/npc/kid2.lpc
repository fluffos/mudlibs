// kid1.c "调皮的小男孩"
#include <mudlib.h>
inherit LIVING;
inherit M_ACTIONS;
inherit M_TRIGGERS;
string *query_channel_list() {
    return ({ "plyr_gossip" });
}
void setup()
{
    set_name("kid", "小男孩");
    set_gender(1);
    set_proper_name("调皮的小男孩");
    set_in_room_desc("一个调皮的小男孩(kid)");
    add_id("boy");
    set_long("浑身脏脏的，象是刚从泥坑里爬出来. . .");
    set_actions( 2, ({
        "say 你在等什么呢？",
            "say 想跟我玩吗？",
            "say 烈火就住在这个村里，不过他大部分时间都在这棵树上。",
            "say 苑璧是我们村里最漂亮的姑娘，你想见她吗？",
            "say 长街的家在村子东头。",
            "say 你是谁？",
            "say 你怎么长成这样？",
            "say 你在这儿干嘛呢？",
            "say 村后面的山洞里好象有财宝",
            "xixi",
            "jump",
            "kick",
                "escape"
            }) );
    add_pattern("%s一脚踢到你%s。",function(){ 
	respond("ah");
//	respond((: "say 打倒"+$1 :));
//	respond((: "say //调皮的小男孩一脚踢到"+$1+"的屁股上，踢得"+$1+"象皮球一样滚了三圈。":)); 
} );
    add_pattern("%s深深地叹了口气。","say 烈火最喜欢叹气，看来你和他一样呀
。");
    add_pattern("%s用尽全力向你头上砸去%s", function() {
        respond("pain");
        respond("say 为什么要打我，？");
          respond("cry");
    } );
}
