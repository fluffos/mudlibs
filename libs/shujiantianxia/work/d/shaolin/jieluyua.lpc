//jieluyuan.c

inherit ROOM;
#include <ansi.h>
#include <login.h>
void create()
{
	set("short", HIB"戒律院"NOR);
	set("long", @LONG
整个大殿门户紧闭，密不透风。即便是在白昼，也犹如黑夜一般，每隔几
步的墙上，点燃着几枝牛油巨烛。殿上供奉着降魔韦陀下方摆着一排排水牛皮
鞭、穿孔竹板及狼牙棒等执法刑杖。四周站满了怀抱戒刀的执法僧兵。他们正
用威严的眼神打量着你，令你不禁心生惧意。
LONG
	);

	set("exits", ([
		"west" : __DIR__ "songshu4",
	]));
	set("objects",([
		CLASS_D("shaolin") + "/xuan-ji" : 1,
		__DIR__"npc/zjseng" : 1,
                __DIR__"npc/slseng" : 1,
		__DIR__"npc/xiao-tong" : 1
	]));
        
	set("no_fight", "1");
	set("valid_startroom",1);

	setup();
}

void init()
{	
	object ob;

	if (interactive(ob = this_player())) {
		if (wizardp(ob)) return;
		if (!ob->query("guilty") && ob->query("family/family_name") == "少林派") return;
		message_vision(HIY "$N一进戒律院，...只听几声大喝，如同炸雷般在大殿里回响。"
		"$N不禁浑身发抖，再也站立不住，腿一软，扑通一声跪了下来。\n\n" NOR, ob);

		ob->set("startroom", "/d/shaolin/jieluyua");

		if (!ob->query_condition("killer"))
			call_out("processing", 3, ob);
	}
}

void processing(object ob)
{
	if (!ob) return;
	tell_object(ob, HIW "\n你定了定神，抬头细看，只见数十名持刀僧人将你团团围起来，\n"
		"一片雪亮的刀光逼得你眼都睁不开。正前方的高台上放着一把\n"
		"太师椅，居中高坐着位白须白眉的老僧，脸色铁青，目射精光，\n"
		"狠狠地瞪着你。\n\n\n" NOR);

	if (ob->query("family/family_name") != "少林派"){
		message_vision(HIY "玄寂一声大喝：尔等大胆狂徒，擅闯本寺，意在不轨，该当何罪！"
		"堂堂少林寺，岂能容你等宵小如此胡作非为！执法僧兵何在！\n\n" NOR, ob);
		call_out("responsing", 3, ob, 3);
		return;
	}
	if (ob->query("guilty") == 1)
		message_vision(HIY "玄寂一声大喝："+ob->query("name")+"！你离寺仅有数日，却在外杀人越货，胡作非为，"
		"累犯大戒，败坏本寺千载清誉！ 你该当何罪？！执法僧兵何在！\n\n" NOR, ob);

	if (ob->query("guilty") == 3)
		message_vision(HIY "玄寂一声大喝："+ob->query("name")+"！本寺护法松林历代向来不许门人弟子擅入，"
		"你擅闯此地，意在不轨，该当何罪！执法僧兵何在！\n\n" NOR, ob); 

	if (ob->query("guilty") == 2){
		message_vision(HIY "玄寂盯着$N看了半饷，说道："+ob->query("name")+"，你惩恶扬善，锄暴安良，当得表彰，\n"
		"但出家人首戒杀生，你伤害人命，乃是僧家的重罪！ "
		"你去罢，下次定不轻饶！\n\n" NOR, ob);
		ob->delete("guilty");
		return;
	}
	call_out("responsing1", 3, ob, 3);
}

void responsing(object ob, int i)
{
	int j;

	if (!ob) return;
	message_vision(HIR "僧兵大声应道：弟子在！\n" NOR, ob);

	i--;
	j = random(3);

	if (i == 0) {	
		call_out("beating", 3, ob);
		return;
	}

	call_out("responsing", j, ob, i);
}

void responsing1(object ob, int i)
{
	int j;

	if (!ob) return;
	message_vision(HIR "僧兵大声应道：弟子在！\n" NOR, ob);

	i--;
	j = random(3);

	if (i == 0) {
		call_out("beating1", 3, ob);
		return;
	}

	call_out("responsing1", j, ob, i);
}

void beating(object ob)
{

	if (!ob) return;
	message_vision(HIY "\n\n玄寂喝道：杖责三百，将"+ob->query("name")+"打入僧监拘押三月，非洗心悔改，"
	"不得释放！意图越狱者罪加一等！\n\n" NOR, ob);

	message_vision(HIR "僧兵们一涌而上，乱棒齐下，$N痛得昏了过去......\n" NOR, ob);

	ob->delete("guilty");
	
	ob->move(__DIR__"jianyu");
	ob->unconcious();
}

void beating1(object ob)
{
	int i;

	if (!ob) return;
	i = 20 + ob->query("combat_exp") / 100000 * 10;
	if (i > 50) i = 50;

	ob->set("carry_count", i);
	message_vision(HIY "\n\n玄寂喝道：杖责三百，将"+ob->query("name")+"罚去后殿挑水"
		+ chinese_number(i) + "桶，非洗心悔改，"
	"不得释放！意图偷懒者罪加一等！\n\n" NOR, ob);

	message_vision(HIR "僧兵们一涌而上，乱棒齐下，$N痛得昏了过去......\n" NOR, ob);

	ob->delete("guilty");
	
	new(__DIR__"obj/liao_kao")->move(ob);
        ob->unconcious();
	ob->move(__DIR__"houdian");
	ob->set("startroom", "/d/shaolin/houyuan");
}

int valid_leave(object me, string dir)
{
	mapping fam;

        if (userp(me) && dir == "west" && !wizardp(me)) {
		if (mapp(fam = me->query("family"))
		&& fam["family_name"] == "少林派" 
		&& !me->query("guilty")) ;
		else
			return notify_fail("玄寂说道: 大胆，你还敢逃跑！执法僧兵何在！\n");
	}
	return ::valid_leave(me, dir);
}
