#ifndef ZHUANSHI_H
#define ZHUANSHI_H
nosave int zs_getSpentExp(int zslvl) {
int i;
	int cost = 0;
	for (i=0;i<zslvl;i++) {
		cost += (i+1)*10000000;
	}
	return cost;
}
nosave int zs_getSpentDx(int zslvl) {
	return zs_getSpentExp(zslvl);
}
#endif

