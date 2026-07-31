// Room: /d/sandboy/pomiao 
inherit ROOM;
int i=1;
string str="这座破庙空荡荡的,正中的观音像残破不全,蓬头垢脸地托着早已没了
杨柳枝的净瓶。从北面的窗户可以看到外面的小路.地上生着一堆火。火
堆的木架子上";
void do_set_long();

void create ()
{
	set("short","破观音庙");
  set ("long", @LONG
这座破庙空荡荡的,正中的观音像残破不全,蓬头垢脸地托着早已没了 
杨柳枝的净瓶。从北面的窗户可以看到外面的小路.地上生着一堆火。火 
堆的木架子上空空的,什么都没有!满地都是鸡毛和鸡血.
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"shandao1",
]));
  set("item_desc", ([ /* sizeof() == 8 */
  "小路" : "小路上静悄悄的，没人走过!
",
  "净瓶" : "观音菩萨手中拿的瓶子，不过这个是泥作的
",
  "窗户" : "窗扇早已给人拆去，只剩下一个框框!
",
  "烧鸡" : "看清楚了，那有烧鸡？饿昏了吧!
",
  "火堆" : "燃烧的火堆!
",
  "观音" : "一个穿着破旧衣衫的神像!
",
  "木架子" : "这是个用三根树枝搭起来的木头架子!
",
  "破庙" : "你仔细看了看周围,没发现什么特别的东西!
",
]));

  setup();
}
void init()
{
  do_set_long();
  add_action("do_get","get");
}
int do_get(string arg)
{
   object ob;
   string str;
   if (!arg||(arg!="烧鸡")) return notify_fail("你要拿什么?\n");
   if (i==0) return notify_fail("哪来的烧鸡?\n");
   message_vision("$N从木架子上取下一只冒着热气的烧鸡,揣入怀中!\n",this_player());
   ob=new(__DIR__"obj/kaoji");
   ob->move(this_player());
   i=0;
   do_set_long();
    return 1;
}
void do_set_item(string str1,string str2)
{   
  set ("item_desc",([
  "破庙":"你仔细看了看周围,没发现什么特别的东西!\n",
  "木架子":str1,
    "观音":"一个穿着破旧衣衫的神像!\n",
    "火堆":"燃烧的火堆!\n",
    "烧鸡":str2,
    "窗户":"窗扇早已给人拆去，只剩下一个框框!\n",
    "净瓶":"观音菩萨手中拿的瓶子，不过这个是泥作的\n",
    "小路":"小路上静悄悄的，没人走过!\n",
]));
  return;
}
void do_set_long()
{
   string str1,str2,str3;
   if (i==1)
       {
      str1="这是个用三根树枝搭起来的木头架子,上面烤着一只烧鸡，发出扑鼻香味!\n";
      str2="这只烧鸡快烤熟了，油脂不断滴到下面的火堆上!\n";
           str3="烤着一只烧鸡,";
    }
       else
                {
                      str1="这是个用三根树枝搭起来的木头架子!\n";
            str2="看清楚了，那有烧鸡？饿昏了吧!\n";
                      str3="空空的,什么都没有!";
         }
 set("long",str+str3+"满地都是鸡毛和鸡血.\n");
 do_set_item(str1,str2);
  return;
}
