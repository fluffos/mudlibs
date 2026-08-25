inherit "/std/room";

mapping nummem, maxmem;
mapping spells, memspells;
void create()
{
 spells=([ ]);
 memspells=([ ]);
 nummem=([ ]);
 maxmem=([ ]);
 ::create();
}

int query_num_mem(int level) { return nummem[level]; }

int query_max_mem(int level) { return maxmem[level]; }

int adjust_num_mem(int level, int i)
{
 nummem[level]+=i;
 return i;
}

int add_mem_spell(string name, int level)
{
 int i;
 mapping tmp;
 if(pointerp(memspells))
 {
  tmp=([ ]);
  for (i=0;i<sizeof(memspells);i+=2)
   tmp[memspells[i]]=memspells[i+1];
  memspells=tmp;
 }
 if(!mappingp(memspells))
  memspells=([ ]);
 memspells[name]=level;
 return 1;
}
int set_max_routine(int level)
{
 int spelllvl;
 int a;
 int i;
 spelllvl=level/2+1;
 a=level % 2;
 if(a=0)
 {
  maxmem[1]=level/2;
  maxmem[2]=level/2;
  for(i=3;i<=spelllvl;i++)
   maxmem[i]=maxmem[i-1]-1;
 }
 else
 {
  maxmem[1]=level/2+1;
  for(i=2;i<=spelllvl;i++)
   maxmem[i]=maxmem[i-1]-1;
 }
return 1;
}
