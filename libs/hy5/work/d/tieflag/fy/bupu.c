 inherit ROOM;
void create()
{
        set("short", "风云布铺");
        set("long", @LONG
布铺里摆满了绫罗绸缎，这里专门订作，裁剪，改装各种鞋，帽，衫。老板娘
做的衣服不但款式新颖，而且经久耐穿。风云城里老老少少们穿的大部份都是来自
这儿。门口挂了一个大牌子（ｓｉｇｎ）．
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"ecloud2",
]));
        set("objects", ([
            __DIR__"npc/caifeng" : 1,
                        ]) );
        set("item_desc", ([
                "sign": @TEXT
这里是布铺，目前我们可订作（ｄｉｎｇ）： 
帽子（ｈａｔ），围巾（ｓｃａｒｆ），外衣（ｓｕｉｔ），
腰带（ｂｅｌｔ），布鞋（ｓｈｏｅｓ）． 
每件一两黄金． 
例子：
ｄｉｎｇ　ｓｕｉｔ　￥ＨＩＹ￥  团金黄龙袍  ｒｏｂｅ  ｂｕ 
布铺就会用你带来的布料帮你作一件黄色的 ｒｏｂｅ　叫＂团金黄龙袍＂  
$BLK$ - 黑色            $NOR$ - 恢复正常颜色
$RED$ - 红色            $HIR$ - 亮红色
$GRN$ - 绿色            $HIG$ - 亮绿色
$YEL$ - 土黄色          $HIY$ - 黄色
$BLU$ - 深蓝色          $HIB$ - 蓝色
$MAG$ - 浅紫色          $HIM$ - 粉红色
$CYN$ - 蓝绿色          $HIC$ - 天青色
$WHT$ - 浅灰色          $HIW$ - 白色 

另外这里也可以缝补破掉的防具，具体命令是bu id
TEXT
        ]) ); 
        set("coor/x",20);
        set("coor/y",10);
        set("coor/z",0);
        setup();
        replace_program(ROOM); 
}       
