#!/usr/bin/env python3
"""scripts/lpc_nitan_jap_name.py SLUG... -- the nitan-family task killer `d/city/task2/shashou.lpc` (copied from xkx100's
task2) calls `NAMES_D->jap_name()`, which the nitan `adm/daemons/namesd.lpc` does not have: one spawn in three gets 0, and
`name["name"]` on 0 fails the load (the escort quest's `new(ss_name)` errors).  It also wraps the id in `({ name["id"] })`,
xkx100's convention (a string id), where the nitan daemon already returns an id array.  This adds `jap_name()` to namesd,
with xkx100's Japanese name tables, returning the nitan shape `([ "name": ..., "id": ({ id }) ])`, and passes the id array
straight to set_name().  Binary-safe; idempotent."""
import sys

JAP = '''
// jap_name(): 日本名（d/city/task2/shashou 用；名表取自 xkx100 adm/daemons/named）
// nm1_jp 与 id_jp 一一对应
string *nm1_jp = ({
  "山本", "龟田", "姿三", "大岛", "松下", "横田", "东芝", "候本", "川野", "山口",
  "铃木", "岗仓", "小岛", "井上", "安奈", "浅田", "佐藤", "广末", "大竹", "大村",
  "伯佐", "富冈", "东乡",
});

string *id_jp = ({
  "shanben", "guitian", "zisan", "dadao", "songxia", "hengtian", "dongzhi", "houben", "chuanye", "shankou",
  "lingmu", "gangcang", "xiaodao", "jinshang", "annai", "qiantian", "zuoteng", "guangmo", "dazhu", "dacun",
  "bozuo", "fugang", "dongxiang",
});

string *nm2_jp = ({
  "太郎", "次郎", "三郎", "四郎", "五郎", "十一郎", "十四郎", "二十六", "俊树",
  "宁次", "英机", "冶字", "俊雄", "牧夫", "光夫", "敬一", "英世", "漱石", "渝吉",
  "一叶", "子规", "稻造", "伊冲", "松园", "深水", "大观", "丰国", "孝和", "茂",
  "川", "卫", "岛寿", "光云", "安治", "山乐", "梦二",
});

mapping jap_name() {
  int i = random(sizeof(nm1_jp));
  return ([ "name": nm1_jp[i] + nm2_jp[random(sizeof(nm2_jp))], "id": ({ id_jp[i] }) ]);
}
'''.encode()

for slug in sys.argv[1:]:
    base = f"libs/{slug}/work/"
    nd = base + "adm/daemons/namesd.lpc"
    d = open(nd, "rb").read()
    nl = b"\r\n" if b"\r\n" in d else b"\n"
    if b"jap_name" not in d:
        anchor = b"mapping woman_name() {"
        i = d.index(anchor)
        j = d.index(b"}", i) + 1
        d = d[:j] + nl + JAP.replace(b"\n", nl).rstrip(nl) + d[j:]
        open(nd, "wb").write(d)
        print(slug, "namesd: jap_name added")
    ss = base + "d/city/task2/shashou.lpc"
    s = open(ss, "rb").read()
    old = b'set_name(name["name"], ({ name["id"] }));'
    if old in s:
        open(ss, "wb").write(s.replace(old, b'set_name(name["name"], name["id"]);'))
        print(slug, "shashou: id array passed through")
