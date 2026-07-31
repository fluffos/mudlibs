inherit ROOM;

void create()
{
        set("short", "英雄七号街");
        set("long", @LONG
这里是一个很宽阔的广场，铺着青石地面。周围聚集着江湖上不少知名侠客，
很多江湖武林的人都喜欢来这里，因为这是通向各帮派的必进之路，武功低微
的人都敬而远之此处。这里有块牌子(sign)。
LONG );
        
        set("owner", "public");
        set("item_desc", ([
                "sign" : "各帮派的帮主可以在此处划出(help zaofang)一块地盘为己用。\n",
        ]));

        set("exits", ([
"southwest" : "/p/residence/tangjie1055962670",
"eastdown" : "/p/residence/ffb1055549443",
"southup" : "/p/residence/bwit1054288747",
"eastup" : "/p/residence/qiansui1052854286",
"northup" : "/p/residence/cccqc1051068242",
"west" : "/p/residence/tzz1051017055",
"westdown" : "/p/residence/mantis1044384012",
"east" : "/p/residence/pkusos1043760156",
"north" : "/p/residence/zzw1039318991",
"south" : "/p/residence/yingfei1038248088",
"down" : "/p/residence/wanga1037245672",
"up" : "/p/residence/coffer1030535926",   
"yxj9" : "/u/zjb/room/yingxiong9",
"yxj8" : "/u/zjb/room/yingxiong8",
"yxj6" : "/u/zjb/room/yingxiong6",
"yxj5" : "/u/zjb/room/yingxiong5",
"yxj4" : "/u/zjb/room/yingxiong4",
"yxj3" : "/u/zjb/room/yingxiong3",
"yxj2" : "/u/zjb/room/yingxiong2",
"yxj" : "/u/zjb/room/yingxiong",
                                ]));
        
        setup();
}


int get_object(object ob)
{
        if(userp(ob)&&ob->query_condition("killer"))
        return 1;
        return 0;
}

void init()
  {
object *obj;
     object ob=this_player();
   object *inv = deep_inventory(ob);    

    obj = filter_array(inv,(:get_object:));
    if(sizeof(obj)){
    write (HIB"你刚想偷偷的背个杀人犯到这里来干什么，快滚出去!。\n"NOR);
    ob->unconcious();
 ob->move("/d/city/guangchang");
return;
}
      if ( (int)ob->query_condition("killer")) {
      write (HIM"杀人犯也敢来英雄街，找死!\n"NOR);
     ob->unconcious();
     ob->move("/d/city/guangchang");
return;
      }
  } 

