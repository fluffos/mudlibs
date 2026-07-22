一时心血来潮，尝试做了一个攻城的文件。
一个人可以对一座城攻击，防御，收税，驻兵，开发
每天税金会自动存到城主的户头。玩家必须带有士兵才能攻城
。士兵可去/d/city的jiuguan招募。
/cmds/usr/city.c 列出现在的城市占有表。
/obj/area1.c是一个过渡文件。用来支持上面的命令。
/std/city.c放的是城市的主体，继承它就可以做一座新城。
/d/city/jiuguan.c募兵处。
/d/city/hanyang.c一个城市的例子。
/adm/daemons/natured.c 定时发税金。
/adm/daemons/combatd.c放的是攻城的战斗描述。之所以这样来攻城
是因为它与一般的战斗相仿。所以就可以开发相当于perform的计谋、策略的使用。

我很喜欢mud这种特殊的编程。星月传奇提供了大量的学习素材，让我
受益良多。在这里我向星星表示感谢。希望星月传奇越办越好，我作为
热爱文字mud的一员，永远支持你。

                                              小米。7/2/2001
                                 address: hudiemiss@263.net
                                 oicq: 40900049

星月传奇提供下载
http://www.lywin.com
中国泥巴资源下载第一站