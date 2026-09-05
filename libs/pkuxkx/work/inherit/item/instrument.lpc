// /adm/daemons/musicd.c
// base on the work of jjgod
// by shure@mudbuilder.net 2001-10-06

#include <ansi.h>
inherit ITEM;

mapping start_msg = ([
	"guitar" : ({ 
	        "$N拿出一柄$n，边弹边唱：\n",
    		"$N抱起$n，长发低垂，深情地唱道：\n",
   		"$N怀抱$n，一边伴奏，一边唱道：\n",}),
	"heptachord" : ({ 
		"琴弦上浊音一沉，$N奏起一曲，唱道：\n",
		"$N慢点泛音，神思徘徊，低声唱道：\n",
		"$N琴上轮指，口中吟唱：\n",
		"琴声跌宕，$N低声唱道：\n",
		"大撮声沉中，$N指上弦音回转，唱道：\n",
		"$N散挑数弦，琴声清越，朗声唱道：\n",
		"$N随指操缦，琴和短歌之行，唱道：\n",
		"$N转调商音，情入丝弦，曼声唱道：\n",
		"$N摆出一张$n，调轸停当，双手抚琴作一起式，随即吟声唱道：\n",}),
	"lute" : ({ 
	        "只见$N取出$n，斜抱入怀，轻拢慢捻低声唱道：\n",
    		"$N抱起$n，半遮面庞，手指轻颤处，清乐声起，宛如珠落玉盘。\n",
   		"$N仔细调好$n轸弦，微一沉吟，指落处曼声唱道：\n",})
]);

mapping end_msg = ([
	"guitar" : ({ 
	        "$N一曲弹毕，放下手中$n，对观众深鞠一躬，大声道：谢谢！谢谢！！：\n",
    		"$N歌声落下，长发一甩，满脸得意的颜色。\n",
   		"$N放下$n，大声问道：要不要再来一个？！\n",}),
	"heptachord" : ({ 
		"$N泛音慢点，琴声渐低，终于悄然而绝。\n",
		"$N指间泛音清泠，入尾而停。\n",
		"泛音清点，一曲弹罢，$N手抚琴弦，低声叹了口气，抬起头来。\n",}),
	"lute" : ({ 
	        "$N一曲弹罢，将怀中$n收入锦囊之中。\n",
    		"$N歌声悄落$n，弦上玲珑也停了下来。\n",
   		"$N一曲终了，收弦而止。\n",})
]);

string *halt_msg = ({
        "$N发现大家一脸痛苦的表情，尴尬地咳嗽了两声，停下了噪音。\n" ,
        "$N弹了一会儿，发现周围人慢慢都走光了，讪讪地收起了$n\n",
        "$N忽然停下来不弹了。\n",
        "$N一下子想不起后面的曲子，只好停了下来。\n",
});

string long();
void init();
int do_play(string arg);
int play_stage(string arg, object me, int s);
int do_halt();
void play_stop(object me);

string long()
{
        return query("long") + 
                "\nplay <词曲名>：开始弹奏（词曲名请用music -l 或 music -sl 查询）\n" +
                "stop：停止演奏\n";
}

void init()
{
        add_action("do_play", "play");
        add_action("do_halt", "stop");
}

int do_play(string arg)
{
        object  ob, me;
        mapping song;
        string  *msg;

        if (! arg) return notify_fail("你要弹奏什么曲子(help music)？\n");
        me = this_player();        
        if (me->is_busy())
                return notify_fail("你正忙着呢。\n");
        if (!me->query("songs") || undefinedp(song = me->query("songs")[arg]))
        	if(!mapp(song = MUSIC_D->query_song(arg)))
                	return notify_fail("乐曲库中没有这首曲子(help music)。\n");
        if (me->query_temp("playing"))
                return notify_fail("你不是正在演奏吗？\n");
	msg = start_msg[query("type")];
	ob  = this_object(); 
        message_vision(MAG + msg[random(sizeof(msg))] + NOR, me, ob);
	remove_call_out("play_stage");
	call_out( "play_stage" , 2, arg, me, 0);
        me->set_temp("playing", song);
        me->start_busy(1);
        return 1;
}

int play_stage(string arg, object me, int s)
{
	object ob;
	int all;
	string msg, *text;
	mapping song;
	
	ob  = this_object(); 
	msg = " ";

	if(environment(ob) != me)
	{
		remove_call_out("play_stop");
		call_out( "play_stop" , 0, me);
		return 1;
	}
				
	if (!me->query("songs") || undefinedp(song = me->query("songs")[arg]))
        	if(!mapp(song = MUSIC_D->query_song(arg)))
                	return notify_fail("乐曲库中没有这首曲子( help music )。\n");
        text = song["context"];
        all  = sizeof(text); 
	if ( s < all )
	{
		message_vision( BLK"\n.\t"NOR+msg+text[s]+"\n", me );
		remove_call_out("play_stage");
		call_out( "play_stage" , 2, arg, me, s+1);
	}
	else
	{
		remove_call_out("play_stop");
		call_out( "play_stop" , 1 , me);
	}
	return 1;
}

int do_halt()
{
        object me = this_player();
	if(!me->query_temp("playing"))
		return notify_fail("你没有在弹奏曲目。");
        me->delete_temp("playing");
        message_vision(YEL+halt_msg[random(sizeof(halt_msg))]+NOR, me, this_object());
        remove_call_out("play_stage");
        remove_call_out("play_stop");
        return 1;
}

void play_stop(object me)
{
	object ob;
	string *msg;
	
	ob = this_object();
	if(!objectp(ob) || !objectp(me))
		return;
	msg = end_msg[query("type")];
        message_vision(MAG + "\n"+msg[random(sizeof(msg))] + NOR, me, ob);
	me->delete_temp("playing");
	return;
}