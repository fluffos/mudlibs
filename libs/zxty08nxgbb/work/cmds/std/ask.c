// ask.c
// From ES2
// Modified by Xiang for XKX (12/15/95)

#include <ansi.h>
string query_inquiry(object ob);
inherit F_CLEAN_UP;

string *msg_dunno = ({
	"$n摇摇头，说道：没听说过。\n",
	"$n疑惑地看着$N，摇了摇头。\n",
	"$n睁大眼睛望着$N，显然不知道$P在说什么。\n",
	"$n耸了耸肩，很抱歉地说：无可奉告。\n",
	"$n说道：嗯....这我可不清楚，你最好问问别人吧。\n",
	"$n想了一会儿，说道：对不起，你问的事我实在没有印象。\n",
});

int main(object me, string arg)
{
	string dest, topic, msg;
	object ob;
	mapping inquiry;
        string str;


	seteuid(getuid());
			str=read_file("/log/NEWS");

        if( me->is_busy() )
                return notify_fail("您先歇口气再说话吧。\n");

	if( !arg || sscanf(arg, "%s about %s", dest, topic)!=2 )
		return notify_fail("你要问谁什么事？\n");

	if( !objectp(ob = present(dest, environment(me))) )
		return notify_fail("这里没有这个人。\n");

	if( !ob->is_character() ) {
		message_vision("$N对着$n自言自语....\n", me, ob);
		return 1;
	}

	if( !ob->query("can_speak") ) {
		message_vision("$N向$n打听有关『" + topic + "』的消息，但是$p显然听不懂人话。\n", me, ob);
		return 1;
	}

	if( !INQUIRY_D->parse_inquiry(me, ob, topic) )
		message_vision("$N向$n打听有关『" + topic + "』的消息。\n", me, ob);

	if( userp(ob) ) return 1;
	if( !living(ob) ) {
		message_vision("但是很显然的，$n现在的状况没有办法给$N任何答覆。\n",
			me, ob);
		return 1;
	}
        if(msg = ob->accept_ask(me, topic))
           { 
                  if (stringp(msg)) 
                  { 
                          message_vision(CYN "$N" CYN "说道：" + msg + "\n" NOR, ob); 
                          return 1; 
                  } 
          }
        if(! ob) return 1;
	if( msg = ob->query("inquiry/" + topic) ) {
		if( stringp(msg) ) {
			message_vision( CYN "$N说道：" + msg + "\n" NOR, ob);
			return 1;
		}
	} else {
  	        if(ob->query("race")=="野兽") {
			message_vision("但是很可惜，$N不会说话。\n", ob);
			return 1;
		}
		switch(topic) {
			case "name":
			message_vision( CYN "$N说道：我的名字就是$N," + RANK_D->query_respect(me)+ "有什么事?\n" NOR, ob);
				break;
			case "here":
				message_vision(CYN "$n对$N说道：这里是" + environment(ob)->query("short") + "，其它情况" + RANK_D->query_self(ob) + "也不太清楚。\n" NOR, me, ob);
				break;
			default:
		if(topic=="news")
			{
                        if (!str)
			{
			message_vision( CYN "$N对你说到,最近没什么新闻可说.." NOR, ob);
			}
else {
			message_vision( CYN "$N对你说到,最近听有人说过:"+str+"" NOR, ob);
}
			return 1;
		}	
		if(topic=="all")
			{
			message_vision( CYN "$N对你悄声说道:"+query_inquiry(ob)+"!\n" NOR, ob);
			return 1;
		}
				if (topic == ob->query("name") || ob->id(topic))
				message_vision(CYN "$n说道：那就是" + RANK_D->query_self_rude(ob) + "呀。\n" NOR, me, ob);
				else if (topic == me->query("name") || me->id(topic))
				message_vision(CYN "$n说道：那就是" + RANK_D->query_rude(me) + "你呀。\n" NOR, me, ob);
                                else if (topic == ob->query("name") || ob->id(topic))
				EMOTE_D->do_emote(ob, "name1");
else if (ob->query("combat_exp") < 500000)
{
                                if (strsrch(topic,"北京")>= 0 || strsrch(topic,"京城")>= 0)
                                message_vision(CYN "$n说道：那里是京城,听说那里的千金楼不错。\n" NOR, me, ob);
                                else if (strsrch(topic,"郭靖")>= 0 || strsrch(topic,"北侠")>= 0)
                                message_vision(CYN "$n说道：人称北侠的郭靖，既是蒙古成吉思汗的金刀驸马，又是
江南七怪、全真派马钰道长、「北丐」洪七公和「老顽童」周伯通等人的徒弟，身兼数门武功n" NOR, me, ob);
                                else if (strsrch(topic,"少林派")>= 0 || strsrch(topic,"少林")>= 0)
                                message_vision(CYN "$n说道：天下第一大门派就是少林。n" NOR, me, ob);
                                else if (strsrch(topic,"武当派")>= 0 || strsrch(topic,"武当")>= 0)
                                message_vision(CYN "$n说道：武当张真人是我的偶像。n" NOR, me, ob);
                                else if (strsrch(topic,"明 教")>= 0 || strsrch(topic,"明教")>= 0)
                                message_vision(CYN "$n说道：天下第一教，是人称魔教的明教。n" NOR, me, ob);
                                else if (strsrch(topic,"华山派")>= 0 || strsrch(topic,"华山")>= 0)
                                message_vision(CYN "$n说道：独孤九剑可是天下第一剑。n" NOR, me, ob);
                                else if (strsrch(topic,"姑苏慕容")>= 0 || strsrch(topic,"慕容")>= 0)
                                message_vision(CYN "$n说道：都什么朝代了, 还要什么大燕国。n" NOR, me, ob);
                                else if (strsrch(topic,"桃花岛")>= 0 || strsrch(topic,"桃花")>= 0)
                                message_vision(CYN "$n说道：桃花岛上奇门武功，怪东西可不少。n" NOR, me, ob);
                                else if (strsrch(topic,"大理段家")>= 0 || strsrch(topic,"天龙寺")>= 0)
                                message_vision(CYN "$n说道：六脉神剑、凌波微步我先学哪个更好呢？n" NOR, me, ob);
                                else if (strsrch(topic,"丐帮")>= 0 || strsrch(topic,"丐帮")>= 0)
                                message_vision(CYN "$n说道：天下第一帮么，自然是丐帮了。n" NOR, me, ob);
                                else if (strsrch(topic,"古墓")>= 0 || strsrch(topic,"古墓派")>= 0)
                                message_vision(CYN "$n说道：神雕侠侣，相继亡故，不知古墓一派可有传人？n" NOR, me, ob);
                                else if (strsrch(topic,"神龙教")>= 0 || strsrch(topic,"神龙")>= 0)
                                message_vision(CYN "$n说道：洪教主神通护佑，众弟子勇气百倍，以一当百.....n" NOR, me, ob);
                                else if (strsrch(topic,"大轮寺")>= 0 || strsrch(topic,"雪山寺")>= 0)
                                message_vision(CYN "$n说道：大雪山令人向往，我想去很久了？n" NOR, me, ob);
                                else if (strsrch(topic,"星宿派")>= 0 || strsrch(topic,"星宿")>= 0)
                                message_vision(CYN "$n说道：星宿派都是用毒高手!和无耻之徒n" NOR, me, ob);
                                else if (strsrch(topic,"铁掌帮")>= 0 || strsrch(topic,"铁掌")>= 0)
                                message_vision(CYN "$n说道：那猴爪山共有五个山峰,就像猴儿的手掌一般。n" NOR, me, ob);
                                else if (strsrch(topic,"嵩山派")>= 0 || strsrch(topic,"五岳剑派")>= 0)
                                message_vision(CYN "$n说道：据说五岳剑派就要合并了。n" NOR, me, ob);
                                else if (strsrch(topic,"峨嵋派")>= 0 || strsrch(topic,"峨嵋")>= 0)
                                message_vision(CYN "$n说道：峨嵋山的小师傅们可是漂亮的很啊，嘿嘿。n" NOR, me, ob);
                                else if (strsrch(topic,"灵鹫宫")>= 0 || strsrch(topic,"灵鹫")>= 0)
                                message_vision(CYN "$n说道：灵鹫宫上可都是大美女，一个个长的像仙女一样。n" NOR, me, ob);
                                else if (strsrch(topic,"白驼山庄")>= 0 || strsrch(topic,"白驼")>= 0)
                                message_vision(CYN "$n说道：听说白驼山上有很多蛇,好可怕啊。n" NOR, me, ob);
                                else if (strsrch(topic,"逍遥派")>= 0 || strsrch(topic,"逍遥")>= 0)
                                message_vision(CYN "$n说道：逍遥派好像和灵鹫宫的人常常来往。n" NOR, me, ob);
                                else if (strsrch(topic,"昆仑派")>= 0 || strsrch(topic,"昆仑")>= 0)
                                message_vision(CYN "$n说道：那里的人能文能武。琴剑双绝。n" NOR, me, ob);
                                else if (strsrch(topic,"日月神教 ")>= 0 || strsrch(topic,"日月")>= 0)
                                message_vision(CYN "$n说道：日出东方，唯我不败。n" NOR, me, ob);
                                else if (strsrch(topic,"昆仑派")>= 0 || strsrch(topic,"昆仑")>= 0)
                                message_vision(CYN "$n说道：那里的人能文能武。琴剑双绝。n" NOR, me, ob);
                                else if (strsrch(topic,"凌霄城")>= 0 || strsrch(topic,"凌霄")>= 0)
                                message_vision(CYN "$n说道：一走近凌霄城的人，就冷的浑身发抖。n" NOR, me, ob);
                                else if (strsrch(topic,"五毒教")>= 0 || strsrch(topic,"五毒")>= 0)
                                message_vision(CYN "$n说道：那里好可怕，什么怪物都有。n" NOR, me, ob);

}
				else
					message_vision(msg_dunno[random(sizeof(msg_dunno))], me, ob);
		}
	}
	return 1;
}

string query_inquiry(object ob)
{
	int i=0;
	mapping inq;
	string str="", *indexs;
	
	if(mapp(inq=ob->query("inquiry")))
		{
		indexs=keys(inq);
		for(i=0;i<sizeof(indexs);i++)
			{
				str=indexs[i]+" "+str;
				}
		str="有关于 "HIB+str+NOR CYN"的事情,我很高兴告诉你!";
		return str;
		}
	return "实在是对不起,我什么也不知道呀!";
	}

int help(object me)
{
   write( @HELP
指令格式: ask <someone> about <something>

这个指令在解谜时很重要, 通常必须藉由此一指令才能
获得进一步的资讯。
预设的询问主题:
	here
	name
	news
	all
HELP
   );
   return 1;
}
