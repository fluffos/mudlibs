// room: xing0.c
//by lnwm 97-09-12


inherit ROOM;

void create()
{
        set("short", "黄河沿岸");
        set("long", @LONG
告别西北重镇兰州, 你向北沿黄河北上. 这里虽是山区, 但因傍依黄河, 两
侧还是颇为平坦的黄土路. 到了这里已是人烟渐稀. 路边常常是杂草丛生, 几乎
不可辨清道路. 前面不远就是天都山高高的主峰.
LONG
        );
    set("exits", ([ 
                "southwest"     :       "/d/xibei/jincheng_guan",
                "northeast"     :       __DIR__ "xing1",
        ]));
        set("outdoors","xingqing");
        setup();
}                       


