//didao.c 地道
//Design By Ymh 飞影 email:stcoolman@163.net

#include <ansi.h>

inherit ROOM;
void create()
{
	set("short","地道");
	set("long",@LONG
这是一条阴暗潮湿的地道，地道中却没有一个出口，显得十分神秘。
旁边有一块牌子，上面好象写着什么(sign)。

LONG
);

	set("item_desc",([
		"sign":@TEXT

 这里是蝴蝶哥哥给江湖侠客提供的地道，用来快速逃避仇家的追杀！
 如果你有想到中央广场去的话，请输入: run gc，以此类推！
 
中央广场:       gc      逍遥派:         xy      法元寺:         fy
北京:           bj      桃花岛:         th      峨嵋山:         em
泉州:           qz      白驼山庄:       bt      侠客岛:	       xkd
新疆:           xj      黑木崖:         hm      明教:           mj
华山派:         hs      武当山:         wd      少林:           sl
泰山:           ts      星宿海:         xx      古墓:           gm
雪山寺:         xs      天龙寺:         tl      神龙岛:        sld
衡山派:         hengs   燕子坞:        yzw      全真教:        qzj

TEXT
]));
 
	setup();
}


void init()
{
	add_action("do_run","run");
}
int do_run(string arg)
{
        string obj, msg,where;

        if( !arg )  return notify_fail("你想到哪里 ？\n");
        
        switch(arg) {
         case "gc":
          obj="/d/city/guangchang";
         where="广场";
        break;
        case "xj":
        obj="/d/xingxiu/shanjiao";
        where="新疆";
          break;
         case "bj":
          obj="/d/city2/tian_anm";
         where="北京";
         break;
         case "qz":
          obj="/d/quanzhou/zhongxin";
         where="泉州";
         break;
         case "xx":
          obj="/d/xingxiu/beijiang";
         where="星宿";
         break;
         case "mj":
         obj="/d/mingjiao/shanmen";
         where="明教";
         break;
         case "sl":
         obj="/d/shaolin/guangchang1";
         where="少林寺";
         break;
         case "hz":
         obj="/d/hangzhou/suti1";
         where="杭州";
         break;
         case "cyg":
         obj="/d/quanzhen/damen";
         where="重阳宫";
         break;
          case "xs":
         obj="/d/xueshan/dadian";
         where="雪山";
          break;
         case "ts":
          obj="/d/taishan/doumo";
         where="泰山";
          break;
         case "hs":
          obj="/d/huashan/buwei1";
         where="华山";
          break;
         case "ca":     
         obj="/d/city4/center";
         where="长安";
         break;
         case "xy":
           obj="/d/xiaoyao/qingcaop";
         where="逍遥";
         break;
         case "gm":
         obj="/d/gumu/zhengting";
         where="古墓";   
         break;
         case "hm":
           obj="/d/heimuya/up1";
         where="黑木崖";
         break;
         case "wd":
         obj="/d/wudang/sanqingdian";
         where="武当";
        break;
         case "th":
          obj="/d/taohua/dating";
         where="桃花岛";
         break;
         case "tl":
         obj="/d/tianlongsi/damen";
         where="天龙寺";
         break;
        case "bt":
          obj="/d/baituo/dating";
         where="白驼";
         break;
        case "sld":
          obj="/d/shenlong/road";
         where="神龙岛";
         break;
        case "xkd":
          obj="/d/xiakedao/dating";
         where="侠客岛";
 	 break;
 	case "em":
          obj="/d/emei/fhs";
         where="峨嵋山";
 	 break;
 	case "fy":
 	  obj="/d/xuedao/shanmen";
 	 where="法元寺";
 	 break;
 	case "hengs":
 	  obj="/d/henshan/zhurongdian";
 	 where="衡山派";
 	 break;
 	case "yzw":
 	  obj="/d/yanziwu/bozhou";
 	 where="燕子坞";
 	 break;
 	case "qzj":
 	  obj="/d/quanzhen/damen";
 	  where="全真教";
 	  break;
        default:
                 return notify_fail("你不能到那里 !\n");
                 return 1;
        }
        if( stringp(msg = this_player()->query("env/msg_mout")) )
        message_vision(msg+"\n", this_player());
        else
         { message_vision("$N的身影突然消失得无影无踪。\n"NOR, this_player());

        this_player()->move(obj);}

        if( stringp(msg = this_player()->query("env/msg_min")) )
{
                message_vision(msg+"\n", this_player());
         CHANNEL_D->do_channel(this_object(),"rumor",this_player()->name()+"从地道中逃脱了。");
}
        else
{ 
        message_vision(HIW"$N满脸灰土的从地面上钻了出来。贼头贼脑的四周张望。\n"NOR, this_player());

          
}

        return 1;
}



