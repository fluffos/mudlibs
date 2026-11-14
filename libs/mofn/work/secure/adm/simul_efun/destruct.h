void destruct(object ob) {
  if(!ob)
    return;

  if(PO == ob)
    efun::destruct(ob);
  else
    ob -> dest_me();
}
