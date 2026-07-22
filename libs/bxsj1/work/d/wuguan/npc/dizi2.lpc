 //dizi2.c 周圻 by river

#include <ansi.h>
inherit NPC;
int ask_xuexi2();

void create()
{
	set_name("周圻", ({ "zhou qi","zhou","qi", "man" }));
	set("title", "襄阳武馆二弟子");
	set("gender", "男性");
	set("age", 32);         
	set("long", "他是万震山的二弟子，经常闯荡江湖，一张脸晒的黝黑。\n");
	set("combat_exp", 8000);
	set("shen_type", 1);         

	set_skill("force", 60);
	set_skill("strike", 60);
	set_skill("shenzhao-jing", 60);
	map_skill("force", "shenzhao-jing");          
         
	set("inquiry", ([
		"万震山" : "他老人家是我的恩师啊。",
		"扬州" : "在襄阳城的东面（help map yangzhou），人来人往可热闹呢，据说大\n"+
			"学士顾炎武就隐居在那里。",
		"苏州" : "在扬州城的南边，出扬州城渡过长江就到了。“沧浪亭”，“狮子林”\n"+
			"可都是名胜啊。风景介绍可全在（help map suzhou）里了。",
		"杭州" : "苏州往东南就到了杭州，“上有天堂，下有苏杭”西湖美景可真是美不\n"+
			"胜收啊，怕在杭州迷路的话，就看看（help map hangzhou）吧。", 
		"宁波" : "宁波哦，就在杭州城附近，阿育王庙是宁波最出名的地方了。（help map ningbo）",
		"福州" : "福州离这里可远着呢，地处闽南，现在居民相当少，当年路过，记得好\n"+
			"象有一个什么镖局在那里。看来俺也要看看（help map fuzhou）了，哈哈。",
		"少林派" : "天下第一大门派就是少林（help shaolin）了。位于河南境内，从襄\n"+
			"阳北上少室山就到了（help map shaolin）。别小看这些贼秃，少林“七十二绝\n"+
			"技”闻名江湖，但据说能学全的极少极少啊。",         
		"武当派" : "在湖北境内，过襄阳渡汉水就到武当山了（help map wudang），山\n"+
			"上的牛鼻子臭规矩不少，但武当派（help wudang）张三丰张真人可是俺一直景\n"+
			"仰的高人哦！",        
		"星宿派" : "在天山西边。想起来可真后怕，前年俺路过那里，由于不慎误入星宿\n"+
			"海（help map xingxiu），差点把命都丢在那了。星宿弟子个个浑身是毒，哎..，\n"+
			"最好别去轻易惹他们（help xingxiu）。",
		"明教" : "天下第一教, 就是人称魔教的明教（help mingjiao）了，魔不魔俺不\n"+
			"清楚，但很久前曾见过一明教高手与别人过招，武功可真透着诡异。光明顶在昆仑\n"+
			"山东边，从扬州往西过襄阳，渡黄河，穿越大沙漠就到了（help map_mingjiao）。\n"+
			"明教由于地处西域，弟子们已经多年未在中原武林出现了。",                  
		"姑苏慕容" : "在姑苏燕子坞，去苏州附近找找看吧。以“以彼之道，还彼之身”而\n"+
			"闻名天下的“南慕容”在江南可是最大的家族了（help murong）。去年有事前往\n"+
			"慕容家，凑巧拾到一张慕容的地图（help map murong），你拿去看看吧。",
		"桃花岛" : "这是东海上的一个小岛，从杭州往东南走（help map taohuadao），到\n"+
			"海边看看能不能雇到船吧。这地方俺还从没去过，据说黄老邪自从死了媳妇以后，\n"+
			"性情大变，整个桃花岛（help taohuadao）弄的象个迷宫似的，外人进去一般就\n"+
			"出不来了。",
		"归云庄" : "在太湖边上，从苏州往南走（help map guiyunzhuang）。 那里是黄\n"+
			"老邪的徒弟陆乘风的居所，这陆乘风什么不能学，也喜欢摆弄什么奇门八卦，上\n"+
			"次去归云庄（help taohuadao）差点叫俺迷路了，呵呵呵。",
		"丐帮" : "这，这....俺也说不清了，丐帮（help gaibang）是天下第一帮派，好\n"+
			"象到处都能见到他们的身影，丐帮老帮主洪七公他老人家不知改没改掉贪吃的习惯，\n"+
			"哈哈。",    
		"古墓" : "古墓派在终南山，从扬州向北再折向西南吧（help map gumu）。神雕\n"+
			"侠侣,相继消隐江湖, 不知古墓（help gumu）一派可有传人。",           
		"大理" : "在大宋的南边，从扬州往西到襄阳后折向南边（help map dali）就到\n"+
			"了大理城。大理段氏（help dali）一派是大理皇室。段氏原本出身中原武林世家，\n"+
			"虽贵为皇族，家传武功却从来不曾荒废，反而愈加勤奋。大理的一阳指，六脉神剑，\n"+
			"皆是江湖上赫赫有名的武功。 ",
		"华山派" : "华山在陕西境内，从扬州城西向北走可以到达（help map huashan）。\n"+
			"身为五岳剑派中最出色的门派，华山派（help huashan）在江湖上的名气也是响当\n"+
			"当的。",
		"铁掌帮" : "在川湘交界处，从扬州城向西再向南行就到了（help map tiezhang）。\n"+
			"想当年上官剑南为帮主的时候，铁掌帮（help tiezhang）在江湖上的声誉如日中天，\n"+
			"自从老帮主隐退后，就一天不如一天了。",
		"峨嵋派" : "峨嵋山在四川境内（help map emei），自从灭绝这老尼姑当了掌门后，\n"+
			"峨嵋（help emei）在武林的名气也越来越响了。哎，一群尼姑整天在江湖上逛来逛\n"+
			"去，成何体统，世道不古啊！ ",    
		"昆仑派" : "昆仑派自从“昆仑三圣”隐退以后，现在的昆仑派（help kunlun）门\n"+
			"人可是一代不如一代了，俺还没上过昆仑山，听说在西域一带（help map kunlun）。",
		"襄阳" : "哈哈，你现在不就在襄阳城（help map xiangyang）里么？",
		"丝绸之路" : "那是去西域的必经之路（help map sichou）",
		"京城" : "那是皇帝老子住的地方，可大着很呢！（help map jingcheng）", 
		"学习" : (: ask_xuexi2 :),        
	]));

	setup();
	carry_object(ARMOR_D("cloth"))->wear();
}

void init()
{
	object ob;
	::init();
	if (interactive(ob = this_player()) && !is_fighting()) {
		remove_call_out("greeting");
		call_out("greeting", 0, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	if ( ob->query_temp("jobask") == 2){
		command("admire zhou");
		command("say 这位" + RANK_D->query_respect(ob) +",你可以 "HIY HBCYN"ask zhou about 学习"CYN" 来向我了解地理情况。"NOR);
	}
}

int ask_xuexi2()
{      
	object ob = this_player();
	if(ob->query_temp("jobask") ==2 ) {      
	command("say 这位" + RANK_D->query_respect(ob) +"也是刚到江湖吧，俺在江湖上可混了好几年了，想知道各派\n"+
		"的情况么？先看看我到过的地方 "HIY HBCYN"look tu"CYN" ，然后向我打听吧 "HIY HBCYN"ask zhou about ***"CYN" 。"NOR);
		ob->delete_temp("jobask");
		if(ob->query_temp("jobover") != 2) {
			ob->set_temp("jobover", 2);
			command("say 听说狄云兄弟还有点事情找你，你最好去看一下。"NOR);
			if ( ob->query("combat_exp") < 200) {
				ob->add("potential", 20);
				ob->add("combat_exp",100);
				tell_object(ob,HIW"你听了周圻的讲解，增加了一百点实战经验和二十点潜能，对江湖又多了一分了解。\n"NOR);
			}
		}
		return 1;
	}
	if ( ob->query_temp("jobover") == 2) {
		command("say 我不是都和你说了么，狄云兄弟有事找你，快去看下吧。");
		return 1;
	}
}
