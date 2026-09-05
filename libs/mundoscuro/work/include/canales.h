    
#ifndef CANALES_H
#define CANALES_H

/* No cambiar estos defines! */

#define CLOSE	  0
#define OPEN	  1

#define READWRITE 0
#define READONLY  1
#define BANNED    1

class canal {
    int cid;
    object * users;
    int tipo;
}

#endif /* CANALES_H */
