// che3.c 车厢内
// By River@SJ
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",HIY"车厢内"NOR);
        set("long", @LONG
干净舒服的车厢里，整洁的座位上铺着红色的锦缎。车前老车夫正在用力
地赶着马车，马行颠簸，但坐在车内，却并不感觉震荡。透过的车窗你能够欣
赏窗外优美的景色。
LONG
        );
        set("exits/out","/d/city/guangchang");

        set("no_fight",1);

        setup();
}

void init()
{
        object me=this_player();
        string arg,arg1;
        object place = me->query_temp("place");
        if (!place){
           tell_object(me,YEL"\n车夫拍了拍脑袋说道：你要去那里啊，我可忘了，算了送你到扬州城吧。\n\n");
           return;
        }
        switch(place){
            case "Dali":      arg="/d/dali/dalics";        arg1 ="西南大理国"; break;
            case "Gumu":      arg="/d/gumu/shengou";       arg1 ="终南山古墓"; break;
            case "Wudang":    arg="/d/wudang/xuanyue";	arg1 ="河北武当山脚"; break;
            case "Mingjiao":  arg="/d/mingjiao/shanjiao";  arg1 ="西域明教山脚"; break;
            case "Taohuadao": arg="/d/thd/guiyun/road4";   arg1 ="东海桃花岛门下归云庄前"; break;
            case "Shenlong":  arg="/d/sld/haitan";         arg1 ="神龙岛海滩"; break;
            case "Yangzhou":  arg="/d/city/guangchang";    arg1 ="江南扬州城"; break;
            case "Murong":    arg="/d/mr/testmatou1";      arg1 ="江南姑苏慕容"; break;
            case "Kunlun":    arg="/d/mingjiao/shanjiao";  arg1 ="昆仑山脚"; break;
            case "Tiezhang":  arg="/d/tiezhang/shanjiao";  arg1 ="湖南铁掌山"; break;
            case "Shaolin":   arg="/d/shaolin/shijie1";    arg1 ="嵩山少林少室山"; break;
            case "Huashan":   arg="/d/huashan/path1";      arg1 ="西岳华山山脚"; break;
            case "Xingxiu":   arg="/d/xingxiu/xxh";        arg1 ="西域星宿海"; break;
            case "Emei":      arg="/d/emei/qingshijie";    arg1 ="四川峨嵋山脚"; break;
            case "Dalunsi":   arg="/d/xueshan/mingxiamen"; arg1 ="西番雪山大轮寺"; break;
            case "Quanzhen":  arg="/d/gumu/lyy";           arg1 ="终南山全真教"; break;
            default: break;
        }
        set("exits/out",arg);
        message_vision(YEL "\n车夫把大车靠在路旁，对你说道："+arg1+"已经到了，快下车（out）吧。\n\n"NOR,me);
}
