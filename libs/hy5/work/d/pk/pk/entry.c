// Room: "/d/pk/entry",

#include <ansi.h>

inherit ROOM;

string *map1=({
"/d/pk/pk/turen1",
"/d/pk/pk/turen10",
"/d/pk/pk/turen11",
"/d/pk/pk/turen12",
"/d/pk/pk/turen2",
"/d/pk/pk/turen3",
"/d/pk/pk/turen4",
"/d/pk/pk/turen5",
"/d/pk/pk/turen6",
"/d/pk/pk/turen7",
"/d/pk/pk/turen8",
"/d/pk/pk/turen9",
"/d/pk/bwdh/caodi1",
"/d/pk/bwdh/caodi10",
"/d/pk/bwdh/caodi2",
"/d/pk/bwdh/caodi3",
"/d/pk/bwdh/caodi4",
"/d/pk/bwdh/caodi5",
"/d/pk/bwdh/caodi6",
"/d/pk/bwdh/caodi7",
"/d/pk/bwdh/caodi8",
"/d/pk/bwdh/caodi9",
"/d/pk/bwdh/houting",
"/d/pk/bwdh/huilang1",
"/d/pk/bwdh/huilang2",
"/d/pk/bwdh/huilang3",
"/d/pk/bwdh/huilang4",
"/d/pk/bwdh/huilang5",
"/d/pk/bwdh/huilang6",
"/d/pk/bwdh/jiashan",
"/d/pk/bwdh/qianting",
"/d/pk/bwdh/quqiao1",
"/d/pk/bwdh/quqiao2",
"/d/pk/bwdh/quqiao3",
"/d/pk/bwdh/quqiao4",
"/d/pk/bwdh/shulin1",
"/d/pk/bwdh/shulin10",
"/d/pk/bwdh/shulin11",
"/d/pk/bwdh/shulin12",
"/d/pk/bwdh/shulin13",
"/d/pk/bwdh/shulin14",
"/d/pk/bwdh/shulin2",
"/d/pk/bwdh/shulin3",
"/d/pk/bwdh/shulin4",
"/d/pk/bwdh/shulin5",
"/d/pk/bwdh/shulin6",
"/d/pk/bwdh/shulin7",
"/d/pk/bwdh/shulin8",
"/d/pk/bwdh/shulin9",
"/d/pk/bwdh/zhongting",
"/d/pk/bwdh/zoulang1",
"/d/pk/bwdh/zoulang2",
"/d/pk/sjsz/egarden",
"/d/pk/sjsz/etower1",
"/d/pk/sjsz/etower2",
"/d/pk/sjsz/etower3",
"/d/pk/sjsz/etower4",
"/d/pk/sjsz/etower5",
"/d/pk/sjsz/etower6",
"/d/pk/sjsz/etower7",
"/d/pk/sjsz/ezoulan",
"/d/pk/sjsz/room_01",
"/d/pk/sjsz/room_02",
"/d/pk/sjsz/room_03",
"/d/pk/sjsz/room_04",
"/d/pk/sjsz/room_05",
"/d/pk/sjsz/room_06",
"/d/pk/sjsz/room_07",
"/d/pk/sjsz/room_08",
"/d/pk/sjsz/room_09",
"/d/pk/sjsz/room_10",
"/d/pk/sjsz/room_11",
"/d/pk/sjsz/room_12",
"/d/pk/sjsz/room_13",
"/d/pk/sjsz/room_14",
"/d/pk/sjsz/room_15",
"/d/pk/sjsz/room_16",
"/d/pk/sjsz/room_17",
"/d/pk/sjsz/room_18",
"/d/pk/sjsz/room_19",
"/d/pk/sjsz/room_20",
"/d/pk/sjsz/room_21",
"/d/pk/sjsz/room_22",
"/d/pk/sjsz/room_23",
"/d/pk/sjsz/room_24",
"/d/pk/sjsz/room_25",
"/d/pk/sjsz/room_26",
"/d/pk/sjsz/room_27",
"/d/pk/sjsz/wgarden",
"/d/pk/sjsz/wtower1",
"/d/pk/sjsz/wtower2",
"/d/pk/sjsz/wtower3",
"/d/pk/sjsz/wtower5",
"/d/pk/sjsz/wtower6",
"/d/pk/sjsz/wtower7",
"/d/pk/sjsz/wzoulan",
});

/*string *map2=({
"/d/pk/pk/entry",
});*/
string *map2=({
"/d/pk/pk/turen1",
"/d/pk/pk/turen10",
"/d/pk/pk/turen11",
"/d/pk/pk/turen12",
"/d/pk/pk/turen2",
"/d/pk/pk/turen3",
"/d/pk/pk/turen4",
"/d/pk/pk/turen5",
"/d/pk/pk/turen6",
"/d/pk/pk/turen7",
"/d/pk/pk/turen8",
"/d/pk/pk/turen9",
"/d/pk/sjsz/egarden",
"/d/pk/sjsz/etower1",
"/d/pk/sjsz/etower2",
"/d/pk/sjsz/etower3",
"/d/pk/sjsz/etower4",
"/d/pk/sjsz/etower5",
"/d/pk/sjsz/etower6",
"/d/pk/sjsz/etower7",
"/d/pk/sjsz/ezoulan",
"/d/pk/sjsz/room_01",
"/d/pk/sjsz/room_02",
"/d/pk/sjsz/room_03",
"/d/pk/sjsz/room_04",
"/d/pk/sjsz/room_05",
"/d/pk/sjsz/room_06",
"/d/pk/sjsz/room_07",
"/d/pk/sjsz/room_08",
"/d/pk/sjsz/room_09",
"/d/pk/sjsz/room_10",
"/d/pk/sjsz/room_11",
"/d/pk/sjsz/room_12",
"/d/pk/sjsz/room_13",
"/d/pk/sjsz/room_14",
"/d/pk/sjsz/room_15",
"/d/pk/sjsz/room_16",
"/d/pk/sjsz/room_17",
"/d/pk/sjsz/room_18",
"/d/pk/sjsz/room_19",
"/d/pk/sjsz/room_20",
"/d/pk/sjsz/room_21",
"/d/pk/sjsz/room_22",
"/d/pk/sjsz/room_23",
"/d/pk/sjsz/room_24",
"/d/pk/sjsz/room_25",
"/d/pk/sjsz/room_26",
"/d/pk/sjsz/room_27",
"/d/pk/sjsz/wgarden",
"/d/pk/sjsz/wtower1",
"/d/pk/sjsz/wtower2",
"/d/pk/sjsz/wtower3",
"/d/pk/sjsz/wtower5",
"/d/pk/sjsz/wtower6",
"/d/pk/sjsz/wtower7",
"/d/pk/sjsz/wzoulan",
});

string *npc1 = ({
	 "/d/biwu/ouyangfeng",
	 "/quest/menpaijob/emei/miejue",
	 "/kungfu/class/emei/zhou",
	 "/kungfu/class/gaibang/hong",
	 "/kungfu/class/huashan/feng",
	 "/kungfu/class/huashan/yue-buqun",
	 "/kungfu/class/shaolin/du-jie",
	 "/kungfu/class/shaolin/du-nan",
	 "/kungfu/class/shaolin/da-mo",
	 "/kungfu/class/wudang/zhang",
	 "/kungfu/class/xingxiu/ding",
	 "/kungfu/class/xueshan/fawang",
	 "/kungfu/class/xueshan/jiumozhi",
	 "/quest/menpaijob/shenlong/hong",
	 "/d/biwu/dongfang",
	 "/d/shenlong/npc/dushe",
	 "/d/shenlong/npc/fushe",
	 "/d/wudujiao/npc/baidu5",
	 "/d/wudujiao/npc/chanchu5",
	 "/d/wudujiao/npc/laohu2",
	 "/d/wudujiao/npc/qiandu5",
	 "/d/wudujiao/npc/wandu5",
	 "/d/wudujiao/npc/wolf2",
	 "/d/wudujiao/npc/wugong3",
	 "/d/wudujiao/npc/xiezi3",
	 "/d/wudujiao/npc/zhangao",
	 "/d/wudujiao/npc/zhanglang",
	 "/d/wudujiao/npc/zhizhu3",
	 "/kungfu/class/btshan/ouyangke",
	 "/kungfu/class/emei/jingxuan",
	 "/kungfu/class/gaibang/jian",
	 "/kungfu/class/shaolin/xuan-ci",
	 "/kungfu/class/shaolin/xuan-bei",
	 "/kungfu/class/shaolin/xuan-nan",
	 "/kungfu/class/shaolin/xuan-ku",
	 "/kungfu/class/wudang/mo",
	 "/kungfu/class/wudang/yu",
	 "/kungfu/class/wudang/yin",
	 "/kungfu/class/wudang/song",
	 "/kungfu/class/wudang/zhang",
	 "/kungfu/class/xingxiu/zhaixing",
	 "/kungfu/class/xuedao/shengdi",
	 "/kungfu/class/xueshan/lingzhi",
	 "/d/quanzhen/npc/hao",
	 "/d/quanzhen/npc/ma",
	 "/d/quanzhen/npc/tan",
	 "/d/quanzhen/npc/liu",
	 "/d/taishan/npc/tianmen",
	 "/kungfu/class/emei/fang",
	 "/kungfu/class/gaibang/kongkong",
	 "/kungfu/class/shaolin/hui-kong",
	 "/kungfu/class/xingxiu/azi",
	 "/kungfu/class/wudang/daotong",
	 "/kungfu/class/emei/li",
	 "/kungfu/class/emei/bei",
	 "/kungfu/class/emei/fang",
	 "/d/songshan/npc/zuo",
	 "/d/henshan/npc/moda",
	 "/d/hengshan/npc/xian",
	 "/d/qingcheng/npc/hai",
	 "/kungfu/class/shenlong/su",
	 "/kungfu/class/shenlong/wugen",
	 "/d/xingxiu/npc/gushou",
	 "/d/xingxiu/npc/boshou",
	 "/d/xingxiu/npc/haoshou",
	 "/d/xingxiu/npc/caihua",
});
void create()
{
	set("short", "ÍÀÈË³¡Èë¿Ú");
	set("long", @LONG
ÕâÀïÊÇÒ»¼ä²»Ëã´óµÄĞ¡Îİ£¬µ±ÖĞ°ÚÁËÒ»¸ö×À×Ó£¬ºóÃæ×ö×ÅÒ»¸öÈË£¬
ÕıĞ¦Ò÷Ò÷µÄ¿´×ÅÄã¡£ËûÉíºóÓĞÒ»ÉÈÃÅ£¬ĞéÑÚ×Å£¬ÀïÃæºÚºõºõµÄ£¬Ò²²»Öª
µÀÍ¨ÍùÄÄÀï¡£Î÷ÃæÍû³öÈ¥ÊÇ¿íÀ«³¨ÁÁµÄ´ó½Ö£¬ÈÃÈËÎŞÏŞÏòÍù¡£
[1;31mÍæ¼Ò: Èç¹ûÌìÉñĞû²¼±ÈÈü¿ªÊ¼£¬¿ÉÒÔÓÃstartÀ´½øÈë±ÈÎä³¡¡£
[1;33mÌìÉñ:
Èç¹ûÄãÊÇÌìÉñ£¬ÄÜÏÈÓÃan anniuÀ´¿ªÊ¼±ÈÈüºÍ½áÊø±ÈÈü¡£
Èç¹ûÄãÊÇÌìÉñ£¬ÄÜÓÃchuchangÀ´ÈÃÍæ¼Ò³ö³¡¡£
³ö³¡ºóÓÃupdatedir /d/pk/ À´Çå±ÈÈü³¡
LONG
	);
	set("exits", ([
//		"west" : __DIR__"kantaiw",
//		"east" : __DIR__"kantaie",
                "out"  : "/d/city/wumiao",
	]));
        set("no_fight", 1);
	setup();
}

void init()
{
        add_action("do_push", "an");
        add_action("do_start", "start");
        add_action("do_refresh", "chuchang");
}

void check_trigger()
{
       object room,npc,room2;
       int a,b,i;
       object thisroom = this_object();
       if(!(room = find_object(__DIR__"entry")))
             room = load_object(__DIR__"entry");
       if( room = find_object(__DIR__"entry")){
         if( room->query("exits/out")){
                 room->delete("exits/out");
                 room->set("startpk",1); 
for (i=0;i<30;i++)
{
           a=random(sizeof(npc1));
           npc=new(npc1[a]);
           b=random(sizeof(map2));
           room2=load_object(map2[b]);
if (npc && room2)
{
           npc->move(room2);
//                 message("vision", HIR" "+npc->query("name")+"·Ö²¼µ½"+room2->query("short")+"ÁË¡£\n"NOR, thisroom);
}
}
for (i=0;i<4;i++)
{
           a=random(sizeof(npc1));
           npc=new(__DIR__"obj/hongmao");
           b=random(sizeof(map1));
           room2=load_object(map1[b]);
if (npc && room2)
{
           npc->move(room2);
//                 message("vision", HIY" "+npc->query("name")+"·Ö²¼µ½"+room2->query("short")+"ÁË¡£\n"NOR, thisroom);
}
}
message("channel:chat", HIC"¡¾ÊÔ½£É½×¯¡¿"HIR + "ÍÀÈË´ó»á¿ªÊ¼ÁË£¡\n"NOR,users() );
                 message("vision", HIG"Ö»Ìı¼ûºäÈ»Ò»Éù£¬±ÈÎäÂíÉÏ¿ªÊ¼£¬NPCÈë³¡,ÊÔ½£É½×¯µÄ´óÃÅ¹ØÉÏÁË¡£\n"NOR, thisroom);
                 }
                else
{
room->set("startpk", 0); 
room->delete("startpk");
                 room->set("exits/out", "/d/city/wumiao"); 
message("channel:chat", HIC"¡¾ÊÔ½£É½×¯¡¿"HIR + "ÍÀÈË´ó»á½áÊøÁË£¡\n"NOR,users() );
                 message("vision", HIW"ÊÔ½£É½×¯µÄ³ö¿Ú´óÃÅ±»´ò¿ªÁË¡£\n"NOR, thisroom);
}
           } 
          else message("vision", "ERROR: Room 2 not found\n", thisroom);          
}

void check_trigger1()
{
       object room1;
       object thisroom = this_object();
       if(!(room1 = find_object("/d/city/wumiao")))
             room1 = load_object("/d/city/wumiao");
       if( room1 = find_object("/d/city/wumiao")){
         if( room1->query("exits/enter")){                 
                 room1->delete("exits/enter");
                 message("vision", HIR"Ö»Ìı¼ûºäÈ»Ò»Éù£¬±ÈÎäÂíÉÏ¿ªÊ¼£¬ÊÔ½£É½×¯µÄÈë¿Ú¹ØÉÏÁË¡£\n"NOR, thisroom);                 }
                else 
{
room1->set("exits/enter", "/d/pk/pk/entry"); 
                message("vision", HIW"ÊÔ½£É½×¯µÄÈë¿Ú±»´ò¿ªÁË¡£\n"NOR, thisroom);
}
           } 
          else message("vision", "ERROR: Room 1 not found\n", thisroom);          
}

int do_push(string arg)
{
       object me;
       me = this_player();       
       if (userp(me) && !wiz_level(me))
          return notify_fail("Äã²»ÊÇÎ×Ê¦£¬²»ÒªËæ±ãÂÒ¶¯£¬»µÁËÄã¿ÉÅâ²»ÆğÅ¶£¡\n");
       if( wiz_level(me) < 3)
                return notify_fail("ÕâÃ´¹óÖØµÄ¶«Î÷£¬Äã»¹ÊÇ±ğÅöÎªºÃ¡£\n"); 

       if (!arg || arg !="anniu")
          return notify_fail("ÄãÒª°´Ê²Ã´£¿\n");
       if (arg == "anniu"){
           message_vision(HIR"$NÇáÇáĞêÁË¿ÚÆø£¬ÌáÆğÊ³Ö¸ÂıÂıµØ°´¶¯ÁË°´Å¥¡£\n"NOR, me);
           check_trigger();
           check_trigger1();
           return 1;
           } 
          return notify_fail("ÄãÒª°´Ê²Ã´£¿\n");
}


int do_start()
{
       object me;
       object room,npc,room2;
int a;
       me = this_player();       
       if (!userp(me))
          return notify_fail("·ÇÍæ¼Ò²»µÃ½øÈë£¡\n");
       if (!environment(me)->query("startpk"))
          return notify_fail("»¹Ã»ÓĞ¿ªÊ¼£¡\n");
if (me->query_condition("killer"))
return notify_fail("Í¨¼­·¸²»ÄÜ½øÈë£¡\n");
if (me->query("combat_exp") <100000)
return notify_fail("Ö»ÓĞ¾­Ñé´óÓÚ100000²ÅÄÜ½øÈë£¡\n");
    if (present("mian ju", me) )
return notify_fail("²»ÄÜ´øÃæ¾ßÈëÄÚ£¡\n");
    if (present("helan huoqiang", me) )
return notify_fail("²»ÄÜ´ø»ğÇ¹ÈëÄÚ£¡\n");
           message_vision(HIR"Ò»Õó¹â°üÎ§ÁË$N,$NÏûÊ§²»¼ûÁË¡£\n"NOR, me);
           a=random(sizeof(map1));
           room2=load_object(map1[a]);
if (room2)
           me->move(room2);

           return 1;
 
}


int do_refresh(object me,string file) 
{ 
        object *list,*ob;
        int i;
        string msg;
me=this_player();
       if (userp(me) && !wiz_level(me))
          return notify_fail("Äã²»ÊÇÎ×Ê¦£¬²»ÒªËæ±ãÂÒ¶¯£¬»µÁËÄã¿ÉÅâ²»ÆğÅ¶£¡\n");
       if( wiz_level(me) < 3)
                return notify_fail("ÕâÃ´¹óÖØµÄ¶«Î÷£¬Äã»¹ÊÇ±ğÅöÎªºÃ¡£\n"); 

        ob = filter_array(children(USER_OB),(: userp($1) && !wizardp($1) :));
list = sort_array(ob,"sort_user");
       for (i = 0 ;i < sizeof(list); i++) {
       if( environment(list[i])->query("bwdhpk"))
{
list[i]->remove_all_killer();
list[i]->move(__DIR__"ready");
}
}
           message_vision(HIW"³ö³¡Íê³É£¬ËùÓĞ±ÈÈü³¡ÖĞÍæ¼ÒÒÆÖÁĞİÏ¢ÊÒ¡£\n"NOR, me);
        return 1;       
} 

int sort_user(object ob1, object ob2)
{
        string name1, name2;
        if( wiz_level(ob1) != wiz_level(ob2) )
                return wiz_level(ob2) - wiz_level(ob1);
        name1 = ob1->query("family/family_name");
        name2 = ob2->query("family/family_name");
        if (intp(name1)) name1 = "";
        if (intp(name2)) name2 = "";
        if (name1 > name2) return -1;
        if (name1 < name2) return 1;
                return (int)ob2->query("family/generation") - (int)ob1->query("family/generation");

}
