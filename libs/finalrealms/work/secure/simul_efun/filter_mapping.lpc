varargs mapping filter_mapping(mapping map, string func, mixed ob, mixed extra) {
  mixed *bing;
  mapping ret;	
int i, bingsize;


  ret = ([ ]);
   bing = keys(map);
for (i=0; i < bingsize; i++) {
if(call_other(ob, func, map[bing[i]], extra ))
   ret[bing[i]] = map[bing[i]];
  }
  return ret;
} /* filter_mapping() */
