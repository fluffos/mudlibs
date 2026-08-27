string number_as_string(int n);

string query_num(int n, int limit) {
  string ret;
  int i;

  if (limit && n>limit) return "muchos"; /* this is a little pointless ... */
  if (n < 0) return "muchos"; /* fo wraps... */
  if (n > 99999) return "muchos"; /* sorry 'bout the hard limit */
  ret = 0;
  if ((i = n/1000)) {
    n = n%1000;
    if (!n)
      return number_as_string(i) + " mil";
    ret = number_as_string(i) + " mil";
  }
  if ((i = n/100)) {
    n = n%100;
    if (ret) {
      if (!n)
        return ret + " y " + number_as_string(i) + " cientos";
      ret += ", " + number_as_string(i) + " cientos";
    } else {
      if (!n)
        return number_as_string(i) + " cientos";
      ret = number_as_string(i) + " cientos";
    }
  }
  if (ret)
    return ret + " y " + number_as_string(n);
  return number_as_string(n);
} /* query_num() */

string number_as_string(int n) {
  string ret;

  if (!n) return "cero";
  if (n<20 && n>9) return ({ "diez", "once", "doce", "trece", "catorce",
                             "quince", "dieciseis", "diecisiete",
                             "dieciocho", "diecinueve" })[n-10];
  ret = ({ "", "", "veinte", "treinta", "cuarenta", "cincuenta", "sesenta",
           "setenta", "ochenta", "noventa"})[n/10];
  if ((n = n%10)&&(ret!="")) ret += " ";
  return ret + ({ "", "un", "dos", "tres", "cuatro", "cinco", "seis",
                  "siete", "ocho", "nueve"})[n];
} /* number_as_string() */
