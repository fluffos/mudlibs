// support for shells
object _sh;

void set_this_shell(object ob) {
  _sh = ob;
}

object this_shell() {
  if(_sh && objectp(_sh))
    return _sh;
  return 0;
}
