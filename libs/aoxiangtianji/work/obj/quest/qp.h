mapping pp = ([
  "/d/city/" : ({"/d/jjf/","/d/changan-s/", "/d/changan-e/","/d/qujing/",}),
  "/d/lanzhou/" : ({"/d/moon/","/d/qujing/",}),
  "/d/beiping/" : ({"/d/hengshan/","/d/wutaishan/",}),
  "/d/luoyang/" : ({"/d/huashan/"}),
  "/d/hangzhou/" : ({"/d/nanhai/",}),
  "/d/songshan/"  : ({"/d/kaifeng/",}),
]);
//w1 : knower  w2: quest
int can_know(string w1, string w2)
{
  string *kp;
  mixed rp;
  if (w1 == w2)
    return 1;
  if (w2 == w1[0..strlen(w2) - 1])
    return 1;
  kp = keys(pp);
  if( member_array( w1, kp) == -1 )
    return 0;
  rp = pp[w1];
  if (stringp(rp))
  {
    if (w2 == rp)
      return 1;
    else
      return 0;
  }

  if (arrayp(rp) && sizeof(rp) > 0)
  {
    if( member_array( w2, rp) == -1 )
      return 0;
    return 1;
  }

  return 0;
}

