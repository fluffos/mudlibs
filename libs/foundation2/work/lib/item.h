#ifndef __ITEM_H__
#define __ITEM_H__

int CanGet(object ob);
int CanDrop(object ob);
int CanPut(object ob);

int SetMass(int x);
int GetMass();
mixed SetInvis(mixed val);
varargs int GetInvis(object ob);
mixed SetPreventGet(mixed val);
mixed GetPreventGet();
mixed SetPreventDrop(mixed val);
mixed GetPreventDrop();
mixed SetPreventPut(mixed val);
mixed GetPreventPut();

#endif /* __ITEM_H__ */
