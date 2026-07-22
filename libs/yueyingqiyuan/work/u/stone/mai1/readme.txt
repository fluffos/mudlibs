加入系统方法如下
1,把paimaishi.c cp到/d/pingan/npc/
2,把bid.c cp到/cmds.std/
3,修改/d/pingan/guangchang.c
在setup();前面写上以下几行
set("objects", ([
  __DIR__"npc/paimaishi" : 1,
]));
4,把paimaishi cp到/doc/help/
这个程序在单机hy2里测试成功


                     by lywin
                                         