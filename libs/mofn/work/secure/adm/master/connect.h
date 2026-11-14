object connect() {
  object ob;
  string err;

  if(err = catch(ob = new(LOGIN_OBJ))) {
    receive("Unable to login.  Please try again later.\n");
    receive(err);
    destruct(ob);
  }

  return ob;
}
