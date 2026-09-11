// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>

inherit LIVING;
inherit M_ACTIONS;
inherit M_TRIGGERS;

string *query_channel_list() {
    return ({ "plyr_gossip" });
}

void setup()
{
    set_name("Harry", "哈里");
    set_gender(1);
    set_proper_name("慈爱的哈里");
    set_in_room_desc("慈爱的哈里(harry)");
    add_id("dude");
    set_long("哈里长得还不赖...");
    set_actions( 10, ({
	"say 你在等什么呢？",
	    "say 各位有礼了！",
	    "say 我不喜欢冬天...",
	    "say 我不喜欢下雪。",
	    "say 我不喜欢雨季...",
	    "say 你是谁？",
	    "say 你怎么长成这样？",
	    "say 你在这儿干嘛呢？",
	    "say 今天天气就是好...就是好！",
	    "smile",
	    "lsfbog",
	    "ack",
//      "chan gossip Is this thing on?",
	    "rock"
	    }) );
    add_pattern("%s快乐地微笑着。", (: $1 != "慈爱的哈里" ? "smile" : 0 :));
    add_pattern("%s has left the game.", (: "say 为什么" + $1
					  + "离开了游戏？" :));
    add_pattern("%s拾起%s。", (: "say 为什么" + $1
				+ "要拣起" + $2 + "？" :));
    add_pattern("%s丢下%s。", (: "say " + $1
				 + "为什么把" + $2 + "丢在地上？" :));
    add_pattern("%s kicks you.", (: "kick " + $1 :));
    add_pattern("%s kisses you.", "blush");
    add_pattern("%s点了点头。", function() {
	respond("nod sol*");
	respond("say 我错过了什么重要的事吗？");
    } );
    add_pattern("%s开怀大笑。", "say 是有什么好笑的事吗？");
    add_pattern("%s chuckles.", "smirk");
    add_pattern("%s boggles.", "bog");
    add_pattern("%s走了过来。", (: "say " + $1 + "，你好！非常高兴见到你！" :) );
    add_pattern("%s朝%s离开了。", (: "go " + $2 :));

    // This subrule says that the right hand side will give us a string
    // we should sprintf() the name into, with the additional stipulation
    // that we ignore other Harry's
    add_pattern("%s说道：%s.", (: ($2 && $1 != "哈里")
				 ? sprintf($2, $1)
				 : 0 :),
		0, "say_rule");
    add_sub_pattern("say_rule", "yes", "say 我不同意。");
    add_sub_pattern("say_rule", "right", "no", "say 我不同意。");
    add_sub_pattern("say_rule", "shut up",
                    "say 你凭什么教我住嘴？");
    add_sub_pattern("say_rule", 
		    "%shello%s", "say 幸会、幸会！");
    add_sub_pattern("say_rule", 
		    "%sLPC%s", "turing %s");
    add_sub_pattern("say_rule", 
                    "%sstay here%s", "say 那好吧...");
    add_sub_pattern("say_rule", 
                    "%snot follow%s", "say 那好吧...");
    add_sub_pattern("say_rule", 
                    "%sget lost%s", "say 那好吧...");
    add_sub_pattern("say_rule", 
                    "%s", (: random(5) == 0 
			   ? "say 你为什么说'" + $1 + "'???" 
			   : 0 :));
}
