经过一天的努力，霹雳堂终于诞生了。在/u/下新建一个子目录/u/bombtang,
把这个zip文件解压到此目录。将/u/bombtang/下的 powderskill.c bombskill.c 移动到/daemon/skill/
下。
将/daemon/class/shaolin/duanhun-spear/ 下的 文件更名喂suomengduanhun.c（一个老bug）。
在mud中用你的pbc打命令：chinese bombskill==霹雳术    、  chinese powderskill==火药术

在/d/laowu/road5.c中加一个方向"eastup"  :  "/u/bombtang/road1",  。

你可以clone /u/bombtang/obj/bomb0;call bomb->set("level",N)   变一个霹雳弹试试，N>0
我试过  N=6 柳无眉重伤  ，N=7 柳无眉死，  N=12  黄麻子死（N为powderskill+bombskill再除以40）
想做出N=6的霹雳弹也要把两种功夫学到240，不易，学到两样480更难了，所以比较平衡。）

pbc兄，如果有什么意见和看法请e-mail : magnat@990.net。要做什么改动，请和我说一声，ok？

                magnat倾心奉上。

								1999.11.14 23:00