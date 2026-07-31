// qingke.c

#include <login.h>
inherit ROOM;

void create()
{
        set("short", "青柯坪");
        set("long", @LONG
走过崎岖的十八盘，穿过云门，就到了青柯坪。青柯坪是一山间盆地
，地势略为平坦。从这里开始，上山的路都是由原地凿出的石阶。北壁下
大石当路，此石叫做回心石，再上去山道奇险，游客至此，就该回头了。
远远望见一个小小石亭，便是赌棋亭了。相传宋太祖与华夷先生曾弈棋于
此，将华山作为赌注，宋太祖输了，从此华山上的土地就不须缴纳钱粮。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  		"northdown" : __DIR__"shaluo",
  		"eastup" : __DIR__"qianchi",
	]));

        set("objects", ([
                CLASS_D("huashan") + "/shi" : 1
        ]));

        set("no_clean_up", 0);
        set("outdoors", "xx" );

        setup();
        replace_program(ROOM);
}

int valid_leave(object me, string dir)
{

    if (!::valid_leave(me, dir))
        return 0;

        if ( (string)me->query("family/family_name") =="华山派" )
        {
                if (!me->query("K_record1"))
                {
                        me->set("K_record1", me->query("PKS") + me->query("MKS"));
                        me->set("shen_record1", me->query("shen"));
                        me->set("bad", 0);
                }
                if (((int)me->query("bad") == 0) && ((int)me->query("K_record1") ==((int)me->query("PKS") + (int)me->query("MKS"))))
                {
     			return 1;
                }
                else
                {
                        if((int)me->query("bad") == 0) {
                        if((int)me->query("shen_record1") > (int)me->query("shen"))
                        {
                                me->set("bad", me->query("bad") + 1);
                                if (me->query("bad")<3) write("一名华山弟子走过来说：师傅让我告诉你，你这次下山做的坏事我们都知道。再犯就决不饶你。\n");
                        }
                        if((int)me->query("shen_record1") < (int)me->query("shen") && me->query("bad") > 0)
                        {
                                me->set("bad", me->query("bad") -1 );
                                write("一名华山弟子对你说，师傅听说你做了好事很高兴，可以抵消一次坏事。\n");
                        }
                        me->set("K_record1", me->query("PKS") + me->query("MKS"));
                        me->set("shen_record1", me->query("shen"));
                }
                if ((int)me->query("shen") <= -100) me->set("bad", 3);
                if ((int)me->query("bad") == 3)
                {
                        write("路上冲出很多华山弟子，对你说：你此次下山，有去杀人，该当何罪！我华山无法留你，这就去见你的师傅。\n");
                        if((string)me->query("family/master_id")=="yue buqun" || (string)me->query("family/master_id")=="ning zhongze")
	   			me->move("/d/huashan/shufang");
                        if ((string)me->query("family/master_id")=="lu dayou" || (string)me->query("family/master_id")=="yue lingshan")
                                me->move("/d/huashan/buwei1");
                        if ((string)me->query("family/master_id")=="gao genming")
                                me->move("/d/huashan/xiaolu1");

                }
        else
        {
                me->set("bad", 0);
                me->set("K_record1", 0);
        }
        return 1;
}
