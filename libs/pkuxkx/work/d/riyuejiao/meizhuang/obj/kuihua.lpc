// kuihua.c 葵花宝典
// Jay 4/5/96
#include <ansi.h>
inherit ITEM;
void setup()
{}

void init()
{
        add_action("do_du", "du");
        add_action("do_du", "zuanyan");
        add_action("do_du", "study");
	add_action("do_read","read");
        add_action("do_join", "join");
}

void create()
{
        set_name("葵花宝典", ({ "kuihua baodian", "baodian", "book"}));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long", "这就是武林第一秘籍《葵花宝典》，相传是一位宫中太监所作。
传到日月教主手中已经是残缺不全。但历代教主潜心钻研，
其中又有新的突破，但也出现了不少重大问题。\n");
                set("value", 50000);
                set("material", "paper");
                set("no_drop", "这样东西不能离开你。\n");
                set("no_get", "这样东西不能离开那儿。\n");

        }
}

int do_du(string arg)
{
        object me = this_player();
        object where = environment(me);
        object ob;
        mapping skill;
        int pxlevel; 
	int neili_lost;

	if (!(arg=="kuihua baodian" || arg == "baodian" || arg == "book"))
	return 0;

	if ((string)me->query("family/master_id")!="dongfang bubai"){
		write("你不是东方不败的弟子，不能学习日月神教的神功！\n");
		return 1;
	}
        if (where->query("pigging")){
                write("你还是专心拱猪吧！\n");
                return 1;
        }
        if (me->is_busy()) {
                write("你现在正忙着呢。\n");
                return 1;
        }

        if( me->is_fighting() ) {
                write("你无法在战斗中专心下来研读新知！\n");
                return 1;
        }

        if (!id(arg)) {	
                write("你要读什么？\n");
                return 1;
        }
        if ((string)me->query("gender") == "女性" ){
                write("自古没有女人可以读《葵花宝典》的。\n");
                return 1;
        }
        if ((string)me->query("gender") == "男性" ) {
               write("《葵花宝典》的第一页写着：欲练神功，必先自宫。\n");
               return 1;
        }
        if( !me->query_skill("literate", 1) ){
                write("你是个文盲，先学点文化(literate)吧。\n");
                return 1;
        }

        switch(random(3)) {
          case 0:
        message("vision", me->name() + "偷偷摸摸翻出一本书在读。\n", environment(me), me);
              break;
          case 1:
        message("vision", me->name() + "边读书边骚首弄姿，好象在模仿女人。\n", environment(me), me);
              break;
          case 2:
        message("vision", me->name() + "边读书边把腰身扭来扭去。\n", environment(me), me);
              break;
        }
        if( (int)me->query("jing") < 15 ) {
                write("你现在过于疲倦，无法专心下来研读新知。\n");
                return 1;
        }
	if ( me->query_skill("pixie-jian",1)>149) neili_lost =30;
	else
	if ( me->query_skill("pixie-jian",1)>99) neili_lost =20;
	else
	if ( me->query_skill("pixie-jian", 1) > 79) neili_lost = 15;
	else
	if ( me->query_skill("pixie-jian", 1) > 49) neili_lost = 10;
	else neili_lost = 5;


        if( (int)me->query("neili") < neili_lost) {
		write("你内力不够，无法钻研这么高深的武功。\n");
                return 1;
        }

	if( (int)me->query_skill("kuihua-shengong",1) < pxlevel )
	{
		write("你的葵花神功功力不够，不能继续学习辟邪剑法。\n");
		return 1;
	}

        pxlevel = me->query_skill("pixie-jian", 1);
        if( (int)me->query("combat_exp") < (int)pxlevel*pxlevel*pxlevel/10 ) {
                write("你的实战经验不足，再怎么读也没用。\n");
                return 1;
        }

        if( me->query_skill("pixie-jian", 1) > 9)
            if ((!objectp(ob = present("golden ring", me)) ) ||
               (!ob->query("equipped") )) {
                write("你没戴戒指，感到很难理解阴柔的指法。\n");
                return 1;
        }
        if( me->query_skill("pixie-jian", 1) > 19)
            if ((!objectp(ob = present("flower shoes", me)) ) ||
               (!ob->query("equipped") )) {
                write("你没穿绣花鞋，感到很难理解阴柔的步法。\n");
                return 1;
        }
        if( me->query_skill("pixie-jian", 1) > 29)
            if ((!objectp(ob = present("xiuhua zhen", me)) ) ||
               (!ob->query("equipped") )) {
                write("你没用绣花针，感到无法理解这种阴柔灵活的武功。\n");
                return 1;
        }
        if( me->query_skill("pixie-jian", 1) > 39)
            if ((!objectp(ob = present("pink cloth", me)) ) ||
               (!ob->query("equipped") )) {
                write("你没穿女人的衣衫，感到很难理解阴柔的身法。\n");
                return 1;
        }
        if( me->query_skill("pixie-jian", 1) > 49)
            if ((!objectp(ob = present("golden necklace", me)) ) ||
               (!ob->query("equipped") )) {
                write("你没戴项链，觉得练这种阴柔的功夫缺乏自信。\n");
                return 1;
        }

        if( me->query_skill("pixie-jian", 1) > 59)
            if( me->query("rank_info/respect") != "公公") {
		write("你现在需要正式加入(join)东厂才能继续深造辟邪剑法。\n");
		write("键入join你便成为东厂的一位太监。这将不影响你的师承，\n");
		write("而且大家都将尊称你为公公。\n");
		me->set_temp("pending/join",1);
                return 1;
        }


     if( me->query_skill("pixie-jian", 1) > 200){
                write("你研读了一会儿，但是发现上面所说的对你而言都太浅了，没有学到任何东西。\n");
                return 1;
        }

        me->receive_damage("jing", 15);
	me->set("neili",(int)me->query("neili")-neili_lost);
        if( !me->query_skill("pixie-jian", 1) ) {
                me->set_skill("pixie-jian", 0);
write("                   《葵花宝典》阅读指南\n"
"\n    恭喜你开始研习武林第一功夫－－－－辟邪剑法！\n"
"注意事项：\n"
"一．研习辟邪剑法必先自宫，如你不想让别人发现这个天大的秘密，你必须\n"
"    找一无人所在之处阅读，且当有别的玩家在场时不要使用辟邪剑法战斗，\n"
"    因为当你阅读或使用辟邪剑法时会出现一些阴柔的举动，使别人产生怀\n"
"    疑。切记不可收徒或拜别的玩家为师，以免被人检查你的技能。\n\n"
"二．辟邪剑法功力极强，既可作剑法，又可作腾挪之法。\n\n"
"         祝你早日成为武林第一高手，称霸天下！\n");
        }
        me->improve_skill("pixie-jian", (int)me->query_skill("literate", 1)/3+1);
        write("你研读《葵花宝典》，颇有心得。\n");
        return 1;
}

int do_read(string arg)
{
        object me = this_player();
        object where = environment(me);
        object ob;
        mapping skill;
        int pxlevel; 
	      int neili_lost;
        int flag=0; //身上是否持有心法
	if (!(arg=="kuihua baodian" || arg == "baodian" || arg == "book"))
	return 0;

	if ((string)me->query("family/master_id")!="dongfang bubai"){
		write("你不是东方不败的弟子，不能学习日月神教的神功！\n");
		return 1;
	}
        if (where->query("pigging")){
                write("你还是专心拱猪吧！\n");
                return 1;
        }
        if (me->is_busy()) {
                write("你现在正忙着呢。\n");
                return 1;
        }

        if( me->is_fighting() ) {
                write("你无法在战斗中专心下来研读新知！\n");
                return 1;
        }

        if (!id(arg)) {	
                write("你要读什么？\n");
                return 1;
        }
        if ((string)me->query("gender") == "女性" ){
                write("自古没有女人可以读《葵花宝典》的。\n");
                return 1;
        }
        if ((string)me->query("gender") == "男性" ) {
               write("《葵花宝典》的第一页写着：欲练神功，必先自宫。\n");
               return 1;
        }
        if( !me->query_skill("literate", 1) ){
                write("你是个文盲，先学点文化(literate)吧。\n");
                return 1;
        }

        switch(random(3)) {
          case 0:
        message("vision", me->name() + "偷偷摸摸翻出一本书在读。\n", environment(me), me);
              break;
          case 1:
        message("vision", me->name() + "边读书边骚首弄姿，好象在模仿女人。\n", environment(me), me);
              break;
          case 2:
        message("vision", me->name() + "边读书边把腰身扭来扭去。\n", environment(me), me);
              break;
        }
        if( (int)me->query("jing") < 25 ) {
                write("你现在过于疲倦，无法专心下来研读新知。\n");
                return 1;
        }
	if ( me->query_skill("kuihua-shengong",1)>199) neili_lost =40;
	else
	if ( me->query_skill("kuihua-shengong",1)>149) neili_lost =30;
	else
	if ( me->query_skill("kuihua-shengong",1)>99) neili_lost =20;
	else
	if ( me->query_skill("kuihua-shengong", 1) > 79) neili_lost = 15;
	else
	if ( me->query_skill("kuihua-shengong", 1) > 49) neili_lost = 10;
	else neili_lost = 5;


        if( (int)me->query("neili") < neili_lost) {
		write("你内力不够，无法钻研这么高深的武功。\n");
                return 1;
        }

        pxlevel = me->query_skill("kuihua-shengong", 1);
        if( (int)me->query("combat_exp") < (int)pxlevel*pxlevel*pxlevel/10 ) {
                write("你的实战经验不足，再怎么读也没用。\n");
                return 1;
        }

        if( me->query_skill("kuihua-shengong", 1) > 9)
            if ((!objectp(ob = present("golden ring", me)) ) ||
               (!ob->query("equipped") )) {
                write("你没戴戒指，感到很难理解阴柔的指法。\n");
                return 1;
        }
        if( me->query_skill("kuihua-shengong", 1) > 19)
            if ((!objectp(ob = present("flower shoes", me)) ) ||
               (!ob->query("equipped") )) {
                write("你没穿绣花鞋，感到很难理解阴柔的步法。\n");
                return 1;
        }
        if( me->query_skill("kuihua-shengong", 1) > 29)
            if ((!objectp(ob = present("xiuhua zhen", me)) ) ||
               (!ob->query("equipped") )) {
                write("你没用绣花针，感到无法理解这种阴柔灵活的武功。\n");
                return 1;
        }
        if( me->query_skill("kuihua-shengong", 1) > 39)
            if ((!objectp(ob = present("pink cloth", me)) ) ||
               (!ob->query("equipped") )) {
                write("你没穿女人的衣衫，感到很难理解阴柔的身法。\n");
                return 1;
        }
        if( me->query_skill("kuihua-shengong", 1) > 49)
            if ((!objectp(ob = present("golden necklace", me)) ) ||
               (!ob->query("equipped") )) {
                write("你没戴项链，觉得练这种阴柔的功夫缺乏自信。\n");
                return 1;
        }

        if( me->query_skill("kuihua-shengong", 1) > 59)
            if( me->query("rank_info/respect") != "公公") {
		write("你现在需要正式加入(join)东厂才能继续深造葵花神功。\n");
		write("键入join你便成为东厂的一位太监。这将不影响你的师承，\n");
		write("而且大家都将尊称你为公公。\n");
		me->set_temp("pending/join",1);
                return 1;
        }
//////////////////////////////////////////////////        
      if (present("kuihua xinfa",me))
      	flag=1;
//////////////////////////////////////////////////      	
      //whuan修改，如果身上有心法则不走火，无需读	
      if ( me->query_skill("kuihua-shengong",1) > 160 && !flag)
                  if ( random(pxlevel*pxlevel/100) > (135 + me->query("kar") + me->query("int")))
		{
			tell_object(me,"你按照宝典里所说的调理内息，突然感觉有些不对。\n");
			me->add_temp("crazy",1);
//modified by advent 060729
//修改理由：基本上没人可以读上去，就算一次一次的读也不行
            if( (int)me->query_temp("crazy") > (random(20)+3) )
//            if( (int)me->query_temp("crazy") > random(20) )
			{
				tell_object(me,HIR "由于你按照宝典上错误的方法练功，你走火入魔了！\n" NOR);
				me->set_skill("kuihua-shengong",pxlevel-10);
				me->set("attitude","aggressive");
				me->delete_temp("crazy");
				me->unconcious();
			}
			return 1;
		}
     if( me->query_skill("kuihua-shengong", 1) > 250){
                write("你研读了一会儿，但是发现上面所说的对你而言都太浅了，没有学到任何东西。\n");
                return 1;
        }

        me->receive_damage("jing", 25);
	      me->set("neili",(int)me->query("neili")-neili_lost);
        if( !me->query_skill("kuihua-shengong", 1) ) {
                me->set_skill("kuihua-shengong", 0);
write("                   《葵花宝典》阅读指南\n"
"\n    恭喜你开始研习武林第一内功－－－－葵花神功！\n"
"注意事项：\n"
"一．研习辟邪神功必先自宫，否则会欲火焚身而死。如你不想让别人发现这个\n"
"    天大的秘密，你必须找一无人所在之处阅读，因为当你阅读或\n"
"    使用辟邪剑法时会出现一些阴柔的举动，使别人产生怀\n"
"    疑。切记不可收徒或拜别的玩家为师，以免被人检查你的技能。\n\n"
"二．辟邪内功功力极强，可以读到250级，但从190级开始是以前各日月教主自创，\n"
"    并不完善，需注意不要走火入魔。祝你早日成为武林第一高手，称霸天下！\n");
        }
        me->improve_skill("kuihua-shengong", (int)me->query_skill("literate", 1)/3+1);
        write("你研读《葵花宝典》，颇有心得。\n");
        return 1;
}        
int do_join()
{
        if( this_player()->query("rank_info/respect") == "公公") {
     		write("你已经加入东厂了，不需要重新加入。\n");
		return 1;
	}

        if( !this_player()->query_temp("pending/join"))
			return 0;
 
	this_player()->set("rank_info/respect", "公公");
	this_player()->set("rank_info/rude","阉贼");
        write("恭喜你成为朝廷最重要的机关东厂的一员！\n");
	this_player()->delete_temp("pending/join");
	return 1;
}

