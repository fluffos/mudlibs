 
//	File	:  /adm/simul_efun/unique_mapping.c
//	Creator	:  Buddha@TMI-2   (01/31/93)
//
//	Returns a mapping containing
//
 
mapping unique_mapping(mixed *arr, string func, string var) {
mapping tmp;
mixed res;
int i;

 seteuid(0);
if(!arr || !pointerp(arr))  return 0;

for (i=0, tmp = ([]); i<sizeof(arr);i++) {
if (!objectp(arr[i])) continue; /* ignore things that aren't objects. */
res = (mixed)call_other(arr[i], func, var);
if (!tmp[res]) tmp[res] = ({ arr[i] });
else tmp[res] += ({ arr[i] });
}
 
return tmp;
}
 
